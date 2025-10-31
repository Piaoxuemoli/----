#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "tac.h"

/* global var */
int scope, next_tmp, next_label;
SYM *sym_tab_global, *sym_tab_local;
TAC *tac_first, *tac_last;
STRUCT_TYPE *current_struct_decl=NULL;

static STRUCT_TYPE *struct_types=NULL;

typedef struct cse_entry
{
	int op;
	SYM *lhs;
	SYM *rhs;
	SYM *result;
	struct cse_entry *next;
} CSE_ENTRY;

static CSE_ENTRY *cse_entries=NULL;

static int cse_is_commutative(int op)
{
	return op==TAC_ADD || op==TAC_MUL;
}

static void const_invalidate_sym(SYM *sym);
static void const_invalidate_all(void);
static void const_record_assignment(SYM *var, EXP *exp);

static SYM *cse_lookup(int op, SYM *lhs, SYM *rhs)
{
	if(lhs==NULL || rhs==NULL) return NULL;
	for(CSE_ENTRY *iter=cse_entries; iter!=NULL; iter=iter->next)
	{
		if(iter->op!=op) continue;
		if(iter->lhs==lhs && iter->rhs==rhs)
		{
			return iter->result;
		}
		if(cse_is_commutative(op) && iter->lhs==rhs && iter->rhs==lhs)
		{
			return iter->result;
		}
	}
	return NULL;
}

static void cse_insert(int op, SYM *lhs, SYM *rhs, SYM *result)
{
	if(lhs==NULL || rhs==NULL || result==NULL) return;
	CSE_ENTRY *entry=(CSE_ENTRY *)malloc(sizeof(CSE_ENTRY));
	entry->op=op;
	entry->lhs=lhs;
	entry->rhs=rhs;
	entry->result=result;
	entry->next=cse_entries;
	cse_entries=entry;
}

static void cse_kill_sym(SYM *sym)
{
	if(sym==NULL) return;
	const_invalidate_sym(sym);
	CSE_ENTRY **pp=&cse_entries;
	while(*pp!=NULL)
	{
		CSE_ENTRY *node=*pp;
		if(node->lhs==sym || node->rhs==sym || node->result==sym)
		{
			*pp=node->next;
			free(node);
		}
		else
		{
			pp=&node->next;
		}
	}
}

static void cse_clear(void)
{
	while(cse_entries!=NULL)
	{
		CSE_ENTRY *node=cse_entries;
		cse_entries=node->next;
		free(node);
	}
}

static void dim_list_free(DIM_LIST *dims)
{
	while(dims!=NULL)
	{
		DIM_LIST *next=dims->next;
		free(dims);
		dims=next;
	}
}

static ARRAY_INFO *array_info_new(int length, int base_type, int base_size, STRUCT_TYPE *base_struct, ARRAY_INFO *child)
{
	ARRAY_INFO *info=(ARRAY_INFO *)malloc(sizeof(ARRAY_INFO));
	info->length=length;
	info->elem_type=base_type;
	info->elem_size=base_size;
	info->elem_struct=base_struct;
	info->child=child;
	info->stride=(child!=NULL) ? child->total_size : base_size;
	info->total_size=info->length * info->stride;
	return info;
}

static ARRAY_INFO *array_info_clone(const ARRAY_INFO *info)
{
	if(info==NULL) return NULL;
	ARRAY_INFO *child_copy=array_info_clone(info->child);
	return array_info_new(info->length, info->elem_type, info->elem_size, info->elem_struct, child_copy);
}

static void array_info_free(ARRAY_INFO *info)
{
	if(info==NULL) return;
	array_info_free(info->child);
	free(info);
}

static ARRAY_INFO *array_info_build_recursive(DIM_LIST *dims, int base_type, int base_size, STRUCT_TYPE *base_struct)
{
	if(dims==NULL) return NULL;
	ARRAY_INFO *child=array_info_build_recursive(dims->next, base_type, base_size, base_struct);
	return array_info_new(dims->length, base_type, base_size, base_struct, child);
}

static ARRAY_INFO *array_info_build(int base_type, STRUCT_TYPE *base_struct, DIM_LIST *dims)
{
	if(dims==NULL)
	{
		error("array requires at least one dimension");
		return NULL;
	}
	int base_size;
	if(base_type==TYPE_STRUCT)
	{
		if(base_struct==NULL)
		{
			error("struct type not specified for array");
			base_size=type_size(TYPE_INT);
		}
		else
		{
			base_size=base_struct->size;
		}
	}
	else
	{
		base_size=type_size(base_type);
	}
	return array_info_build_recursive(dims, base_type, base_size, base_struct);
}

typedef struct loop_ctx
{
	SYM *continue_label;
	SYM *break_label;
	struct loop_ctx *prev;
} LOOP_CTX;

static LOOP_CTX *loop_stack = NULL;

void loop_push(SYM *continue_label, SYM *break_label)
{
	LOOP_CTX *ctx=(LOOP_CTX *)malloc(sizeof(LOOP_CTX));
	ctx->continue_label=continue_label;
	ctx->break_label=break_label;
	ctx->prev=loop_stack;
	loop_stack=ctx;
}

void loop_pop(void)
{
	if(loop_stack==NULL)
	{
		error("loop stack underflow");
		return;
	}
	LOOP_CTX *ctx=loop_stack;
	loop_stack=ctx->prev;
	free(ctx);
}

SYM *loop_current_continue(void)
{
	LOOP_CTX *ctx=loop_stack;
	while(ctx!=NULL && ctx->continue_label==NULL)
	{
		ctx=ctx->prev;
	}
	if(ctx==NULL)
	{
		error("continue statement not within loop");
		return NULL;
	}
	return ctx->continue_label;
}

SYM *loop_current_break(void)
{
	if(loop_stack==NULL)
	{
		error("break statement not within loop");
		return NULL;
	}
	return loop_stack->break_label;
}

int is_pointer_type(int data_type)
{
	return data_type==TYPE_PTR_INT || data_type==TYPE_PTR_CHAR;
}

int pointer_type_from_base(int base_type)
{
	switch(base_type)
	{
		case TYPE_INT:
		return TYPE_PTR_INT;
		case TYPE_CHAR:
		return TYPE_PTR_CHAR;
		case TYPE_ARRAY_INT:
		return TYPE_PTR_INT;
		case TYPE_ARRAY_CHAR:
		return TYPE_PTR_CHAR;
		case TYPE_ARRAY_STRUCT:
		return TYPE_PTR_CHAR;
		case TYPE_STRUCT:
		return TYPE_PTR_CHAR;
		default:
		error("unsupported base type for pointer");
		return TYPE_PTR_INT;
	}
}

int pointer_base_type(int pointer_type)
{
	switch(pointer_type)
	{
		case TYPE_PTR_INT:
		return TYPE_INT;
		case TYPE_PTR_CHAR:
		return TYPE_CHAR;
		default:
		error("dereference of non-pointer type");
		return TYPE_INT;
	}
}

int is_array_type(int data_type)
{
	return data_type==TYPE_ARRAY_INT || data_type==TYPE_ARRAY_CHAR || data_type==TYPE_ARRAY_STRUCT;
}

int array_base_type(int array_type)
{
	switch(array_type)
	{
		case TYPE_ARRAY_INT:
		return TYPE_INT;
		case TYPE_ARRAY_CHAR:
		return TYPE_CHAR;
		case TYPE_ARRAY_STRUCT:
		return TYPE_STRUCT;
		default:
		error("subscript on non-array type");
		return TYPE_INT;
	}
}

int type_size(int data_type)
{
	switch(data_type)
	{
		case TYPE_CHAR:
		case TYPE_INT:
		case TYPE_PTR_INT:
		case TYPE_PTR_CHAR:
		return 4;
		default:
		return 4;
	}
}

static int sym_is_numeric_const(SYM *sym)
{
	return sym!=NULL && sym->type==SYM_INT;
}

static int sym_const_value(SYM *sym)
{
	return sym->value;
}

static int exp_is_const_int(EXP *exp, long long *value)
{
	if(exp==NULL)
	{
		return 0;
	}
	if(exp->tac!=NULL)
	{
		return 0;
	}
	if(!sym_is_numeric_const(exp->ret))
	{
		return 0;
	}
	if(value!=NULL)
	{
		*value=sym_const_value(exp->ret);
	}
	return 1;
}

static void const_invalidate_sym(SYM *sym)
{
	if(sym==NULL)
	{
		return;
	}
	if(sym->type==SYM_VAR)
	{
		sym->is_const=0;
	}
}

static void const_invalidate_all(void)
{
	for(SYM *iter=sym_tab_local; iter!=NULL; iter=iter->next)
	{
		if(iter->type==SYM_VAR)
		{
			iter->is_const=0;
		}
	}
	for(SYM *iter=sym_tab_global; iter!=NULL; iter=iter->next)
	{
		if(iter->type==SYM_VAR)
		{
			iter->is_const=0;
		}
	}
}

static void const_record_assignment(SYM *var, EXP *exp)
{
	if(var==NULL || var->type!=SYM_VAR)
	{
		return;
	}
	if(!(var->data_type==TYPE_INT || var->data_type==TYPE_CHAR))
	{
		var->is_const=0;
		return;
	}
	long long value=0;
	if(exp_is_const_int(exp, &value))
	{
		var->is_const=1;
		var->const_value=(int)value;
	}
	else
	{
		var->is_const=0;
	}
}

STRUCT_FIELD *struct_field_create(char *name, int base_type, DIM_LIST *dims, STRUCT_TYPE *elem_struct)
{
	STRUCT_FIELD *field=(STRUCT_FIELD *)malloc(sizeof(STRUCT_FIELD));
	field->name=name;
	field->elem_type=base_type;
	field->elem_struct=elem_struct;
	field->array_info=NULL;
	if(base_type==TYPE_STRUCT && elem_struct==NULL)
	{
		error("struct field missing type");
	}
	if(dims!=NULL)
	{
		ARRAY_INFO *info=array_info_build(base_type, elem_struct, dims);
		dim_list_free(dims);
		field->array_info=info;
		if(base_type==TYPE_INT)
			field->type=TYPE_ARRAY_INT;
		else if(base_type==TYPE_CHAR)
			field->type=TYPE_ARRAY_CHAR;
		else
			field->type=TYPE_ARRAY_STRUCT;
		if(info!=NULL)
		{
			field->elem_size=info->stride;
			field->size=info->total_size;
		}
		else
		{
			field->elem_size=type_size(base_type);
			field->size=field->elem_size;
		}
	}
	else
	{
		field->array_info=NULL;
		field->type=base_type;
		if(base_type==TYPE_STRUCT && elem_struct!=NULL)
		{
			field->elem_size=elem_struct->size;
			field->size=elem_struct->size;
		}
		else
		{
			field->elem_size=type_size(base_type);
			field->size=field->elem_size;
		}
	}
	field->offset=0;
	field->next=NULL;
	return field;
}

STRUCT_FIELD *struct_field_list_append(STRUCT_FIELD *list, STRUCT_FIELD *field)
{
	if(list==NULL) return field;
	STRUCT_FIELD *iter=list;
	while(iter->next!=NULL) iter=iter->next;
	iter->next=field;
	return list;
}

STRUCT_FIELD *struct_field_lookup(STRUCT_TYPE *type, char *name)
{
	if(type==NULL) return NULL;
	for(STRUCT_FIELD *iter=type->fields; iter!=NULL; iter=iter->next)
	{
		if(strcmp(iter->name, name)==0)
		{
			return iter;
		}
	}
	return NULL;
}

static void struct_validate_fields(STRUCT_FIELD *fields)
{
	for(STRUCT_FIELD *a=fields; a!=NULL; a=a->next)
	{
		int base_type = a->elem_type;
		if(!(base_type==TYPE_INT || base_type==TYPE_CHAR || base_type==TYPE_STRUCT))
		{
			error("unsupported field type in struct");
		}
		if(base_type==TYPE_STRUCT && a->elem_struct==NULL)
		{
			error("struct field missing type");
		}
		for(STRUCT_FIELD *b=a->next; b!=NULL; b=b->next)
		{
			if(strcmp(a->name, b->name)==0)
			{
				error("duplicate field name in struct");
			}
		}
	}
}

STRUCT_TYPE *struct_lookup(char *name)
{
	for(STRUCT_TYPE *iter=struct_types; iter!=NULL; iter=iter->next)
	{
		if(strcmp(iter->name, name)==0)
		{
			return iter;
		}
	}
	return NULL;
}

STRUCT_TYPE *struct_define(char *name, STRUCT_FIELD *fields)
{
	if(fields==NULL)
	{
		error("struct must have at least one field");
	}
	if(struct_lookup(name)!=NULL)
	{
		error("struct already defined");
		return struct_lookup(name);
	}
	struct_validate_fields(fields);
	STRUCT_TYPE *stype=(STRUCT_TYPE *)malloc(sizeof(STRUCT_TYPE));
	stype->name=name;
	stype->fields=fields;
	stype->size=0;
	int offset=0;
	for(STRUCT_FIELD *iter=fields; iter!=NULL; iter=iter->next)
	{
		iter->offset=offset;
		offset += iter->size;
	}
	stype->size=offset;
	stype->next=struct_types;
	struct_types=stype;
	return stype;
}

void tac_init(void)
{
	scope=0;
	sym_tab_global=NULL;
	sym_tab_local=NULL;	
	next_tmp=0;
	next_label=1;
 	current_struct_decl=NULL;
	cse_clear();
}

void tac_complete(void)
{
	TAC *cur=NULL; 		/* Current TAC */
	TAC *prev=tac_last; 	/* Previous TAC */

	while(prev !=NULL)
	{
		prev->next=cur;
		cur=prev;
		prev=prev->prev;
	}

	tac_first = cur;
}

SYM *lookup_sym(SYM *symtab, char *name)
{
	SYM *t=symtab;

	while(t !=NULL)
	{
		if(strcmp(t->name, name)==0) break; 
		else t=t->next;
	}
	
	return t; /* NULL if not found */
}

void insert_sym(SYM **symtab, SYM *sym)
{
	sym->next=*symtab; /* Insert at head */
	*symtab=sym;
}

SYM *mk_sym(void)
{
	SYM *t;
	t=(SYM *)malloc(sizeof(SYM));
	t->name=NULL;
	t->type=SYM_UNDEF;
	t->scope=0;
	t->offset=0;
	t->data_type=TYPE_INT;
	t->value=0;
	t->label=0;
	t->address=NULL;
	t->etc=NULL;
	t->is_const=0;
	t->const_value=0;
	t->next=NULL;
	return t;
}

SYM *mk_var(char *name, int data_type)
{
	SYM *sym=NULL;

	if(scope)
		sym=lookup_sym(sym_tab_local,name);
	else
		sym=lookup_sym(sym_tab_global,name);

	/* var already declared */
	if(sym!=NULL)
	{
		error("variable already declared");
		return NULL;
	}

	/* var unseen before, set up a new symbol table node, insert_sym it into the symbol table. */
	sym=mk_sym();
	sym->type=SYM_VAR;
	sym->name=name;
	sym->offset=-1; /* Unset address */
	sym->data_type=data_type;
	sym->scope = scope ? 1 : 0;
	if(data_type==TYPE_STRUCT)
	{
		if(current_struct_decl==NULL)
		{
			error("struct type not specified");
		}
		sym->etc=current_struct_decl;
	}

	if(scope)
		insert_sym(&sym_tab_local,sym);
	else
		insert_sym(&sym_tab_global,sym);

	return sym;
}

TAC *join_tac(TAC *c1, TAC *c2)
{
	TAC *t;

	if(c1==NULL) return c2;
	if(c2==NULL) return c1;

	/* Run down c2, until we get to the beginning and then add c1 */
	t=c2;
	while(t->prev !=NULL) 
		t=t->prev;

	t->prev=c1;
	return c2;
}

TAC *declare_var(char *name, int data_type)
{
	return mk_tac(TAC_VAR,mk_var(name, data_type),NULL,NULL);
}

static SYM *mk_array(char *name, int base_type, DIM_LIST *dims)
{
	SYM *sym=NULL;

	STRUCT_TYPE *stype=NULL;
	if(base_type==TYPE_STRUCT)
	{
		stype=current_struct_decl;
		if(stype==NULL)
		{
			error("struct type not specified for array");
			base_type=TYPE_INT;
		}
	}
	else if(!(base_type==TYPE_INT || base_type==TYPE_CHAR))
	{
		error("unsupported array element type");
		base_type=TYPE_INT;
	}

	if(dims==NULL)
	{
		error("array requires at least one dimension");
		DIM_LIST *node=(DIM_LIST *)malloc(sizeof(DIM_LIST));
		node->length=1;
		node->next=NULL;
		dims=node;
	}

	for(DIM_LIST *iter=dims; iter!=NULL; iter=iter->next)
	{
		if(iter->length<=0)
		{
			error("array length must be positive");
			iter->length=1;
		}
	}

	if(scope)
		sym=lookup_sym(sym_tab_local,name);
	else
		sym=lookup_sym(sym_tab_global,name);

	if(sym!=NULL)
	{
		error("variable already declared");
		dim_list_free(dims);
		return NULL;
	}

	sym=mk_sym();
	sym->type=SYM_VAR;
	sym->name=name;
	sym->offset=-1;
	sym->scope = scope ? 1 : 0;
	if(base_type==TYPE_INT)
		sym->data_type=TYPE_ARRAY_INT;
	else if(base_type==TYPE_CHAR)
		sym->data_type=TYPE_ARRAY_CHAR;
	else
		sym->data_type=TYPE_ARRAY_STRUCT;
	STRUCT_TYPE *array_struct=(base_type==TYPE_STRUCT) ? stype : NULL;
	ARRAY_INFO *info=array_info_build(base_type, array_struct, dims);
	dim_list_free(dims);
	sym->etc=info;

	if(scope)
		insert_sym(&sym_tab_local,sym);
	else
		insert_sym(&sym_tab_global,sym);

	return sym;
}

TAC *declare_array(char *name, int base_type, DIM_LIST *dims)
{
	SYM *sym=mk_array(name, base_type, dims);
	if(sym==NULL) return NULL;
	return mk_tac(TAC_VAR, sym, NULL, NULL);
}

TAC *mk_tac(int op, SYM *a, SYM *b, SYM *c)
{
	TAC *t=(TAC *)malloc(sizeof(TAC));

	t->next=NULL; /* Set these for safety */
	t->prev=NULL;
	t->op=op;
	t->a=a;
	t->b=b;
	t->c=c;

	return t;
}  

SYM *mk_label(char *name)
{
	SYM *t=mk_sym();

	t->type=SYM_LABEL;
	t->name=strdup(name);

	return t;
}  

TAC *do_func(SYM *func, TAC *args, TAC *code)
{
	TAC *tlist; /* The backpatch list */

	TAC *tlab; /* Label at start of function */
	TAC *tbegin; /* BEGINFUNC marker */
	TAC *tend; /* ENDFUNC marker */
	cse_clear();

	tlab=mk_tac(TAC_LABEL, mk_label(func->name), NULL, NULL);
	tbegin=mk_tac(TAC_BEGINFUNC, NULL, NULL, NULL);
	tend=mk_tac(TAC_ENDFUNC,   NULL, NULL, NULL);

	tbegin->prev=tlab;
	code=join_tac(args, code);
	tend->prev=join_tac(tbegin, code);

	return tend;
}

SYM *mk_tmp_type(int data_type)
{
	SYM *sym;
	char *name;

	name=malloc(12);
	sprintf(name, "t%d", next_tmp++);
	return mk_var(name, data_type);
}

SYM *mk_tmp(void)
{
	return mk_tmp_type(TYPE_INT);
}

TAC *declare_para(char *name, int data_type)
{
	return mk_tac(TAC_FORMAL,mk_var(name, data_type),NULL,NULL);
}

SYM *declare_func(char *name)
{
	SYM *sym=NULL;

	sym=lookup_sym(sym_tab_global,name);

	/* name used before declared */
	if(sym!=NULL)
	{
		if(sym->type==SYM_FUNC)
		{
			error("func already declared");
			return NULL;
		}

		if(sym->type !=SYM_UNDEF)
		{
			error("func name already used");
			return NULL;
		}

		return sym;
	}
	
	
	sym=mk_sym();
	sym->type=SYM_FUNC;
	sym->name=name;
	sym->address=NULL;

	insert_sym(&sym_tab_global,sym);
	return sym;
}

TAC *do_assign(SYM *var, EXP *exp)
{
	TAC *code;

	if(var->type !=SYM_VAR) error("assignment to non-variable");
	cse_kill_sym(var);
	if(exp->tac==NULL && exp->ret!=NULL && exp->ret->type==SYM_VAR)
	{
		SYM *src=exp->ret;
		if(src->type==SYM_VAR && (src->data_type==TYPE_INT || src->data_type==TYPE_CHAR) && src->scope==0 && src->is_const)
		{
			SYM *const_sym = (src->data_type==TYPE_CHAR) ? mk_char_const(src->const_value) : mk_const(src->const_value);
			exp->ret=const_sym;
		}
	}

	code=mk_tac(TAC_COPY, var, exp->ret, NULL);
	code->prev=exp->tac;
	const_record_assignment(var, exp);

	return code;
}

TAC *do_input(SYM *var)
{
	TAC *code;

	if(var->type !=SYM_VAR) error("input to non-variable");
	cse_kill_sym(var);

	code=mk_tac(TAC_INPUT, var, NULL, NULL);

	return code;
}

TAC *do_output(SYM *s)
{
	TAC *code;

	code=mk_tac(TAC_OUTPUT, s, NULL, NULL);

	return code;
}

EXP *do_addr(SYM *var)
{
	if(var==NULL)
	{
		error("address-of null symbol");
		return mk_exp(NULL, NULL, NULL);
	}
	if(var->type!=SYM_VAR)
	{
		error("address-of non-variable");
		return mk_exp(NULL, NULL, NULL);
	}
	int base_type;
	if(is_array_type(var->data_type))
	{
		base_type=array_base_type(var->data_type);
	}
	else if(var->data_type==TYPE_STRUCT)
	{
		base_type=TYPE_CHAR;
	}
	else if(var->data_type==TYPE_INT || var->data_type==TYPE_CHAR)
	{
		base_type=var->data_type;
	}
	else
	{
		error("address-of unsupported type");
		return mk_exp(NULL, NULL, NULL);
	}
	SYM *tmp=mk_tmp_type(pointer_type_from_base(base_type));
	TAC *decl=mk_tac(TAC_VAR, tmp, NULL, NULL);
	TAC *addr=mk_tac(TAC_ADDR, tmp, var, NULL);
	addr->prev=decl;
	EXP *exp=mk_exp(NULL, tmp, addr);
	exp->etc = (var->data_type==TYPE_STRUCT) ? var->etc : NULL;
	return exp;
}

EXP *do_deref(EXP *ptr)
{
	if(ptr==NULL || ptr->ret==NULL)
	{
		error("dereference of invalid expression");
		return mk_exp(NULL, NULL, NULL);
	}
	SYM *pointer_sym=ptr->ret;
	if(!is_pointer_type(pointer_sym->data_type))
	{
		error("dereference of non-pointer");
		return mk_exp(NULL, NULL, NULL);
	}
	SYM *tmp=mk_tmp_type(pointer_base_type(pointer_sym->data_type));
	TAC *decl=mk_tac(TAC_VAR, tmp, NULL, NULL);
	TAC *code=join_tac(ptr->tac, decl);
	TAC *load=mk_tac(TAC_LOAD, tmp, pointer_sym, NULL);
	load->prev=code;
	ptr->ret=tmp;
	ptr->tac=load;
	return ptr;
}

TAC *do_store(EXP *ptr, EXP *value)
{
	if(ptr==NULL || ptr->ret==NULL)
	{
		error("store through invalid pointer");
		return NULL;
	}
	if(!is_pointer_type(ptr->ret->data_type))
	{
		error("store through non-pointer");
		return NULL;
	}
	cse_clear();
	const_invalidate_all();
	TAC *code=join_tac(ptr->tac, value->tac);
	TAC *store=mk_tac(TAC_STORE, ptr->ret, value->ret, NULL);
	store->prev=code;
	return store;
}

EXP *do_array_element(SYM *array, EXP *index)
{
	if(array==NULL)
	{
		error("subscript on null symbol");
		return mk_exp(NULL, NULL, NULL);
	}
	if(array->type!=SYM_VAR)
	{
		error("subscript on non-variable symbol");
		return mk_exp(NULL, NULL, NULL);
	}
	if(!is_array_type(array->data_type) && !is_pointer_type(array->data_type))
	{
		error("subscript on non-array type");
		return mk_exp(NULL, NULL, NULL);
	}
	if(index==NULL || index->ret==NULL)
	{
		error("array index is invalid");
		return mk_exp(NULL, NULL, NULL);
	}

	int elem_type;
	STRUCT_TYPE *elem_struct=NULL;
	ARRAY_INFO *info=NULL;
	ARRAY_INFO *next_dims=NULL;
	EXP *base_exp=NULL;
	SYM *base_sym=NULL;
	TAC *base_tac=NULL;
	int stride_const=-1;

	if(is_array_type(array->data_type))
	{
		info=(ARRAY_INFO *)array->etc;
		if(info==NULL)
		{
			error("array metadata missing");
			return mk_exp(NULL, NULL, NULL);
		}
		elem_type=info->elem_type;
		elem_struct=info->elem_struct;
		base_exp=do_addr(array);
		base_sym=base_exp->ret;
		base_tac=base_exp->tac;
		stride_const=info->stride;
		next_dims=array_info_clone(info->child);
	}
	else if(is_pointer_type(array->data_type))
	{
		elem_type=pointer_base_type(array->data_type);
		stride_const=type_size(elem_type);
		if(elem_type==TYPE_STRUCT)
		{
			elem_struct=(STRUCT_TYPE *)array->etc;
		}
		base_sym=array;
		base_tac=NULL;
	}
	else
	{
		error("subscript on non-array type");
		return mk_exp(NULL, NULL, NULL);
	}

	SYM *scaled_tmp=mk_tmp();
	TAC *decl=mk_tac(TAC_VAR, scaled_tmp, NULL, NULL);
	decl->prev=index->tac;
	TAC *mul=NULL;
	if(sym_is_numeric_const(index->ret) && index->tac==NULL)
	{
		int folded=stride_const * sym_const_value(index->ret);
		TAC *assign=mk_tac(TAC_COPY, scaled_tmp, mk_const(folded), NULL);
		assign->prev=decl;
		mul=assign;
	}
	else if(stride_const==1)
	{
		TAC *assign=mk_tac(TAC_COPY, scaled_tmp, index->ret, NULL);
		assign->prev=decl;
		mul=assign;
	}
	else
	{
		SYM *stride_sym=mk_const(stride_const);
		mul=mk_tac(TAC_MUL, scaled_tmp, index->ret, stride_sym);
		mul->prev=decl;
	}

	TAC *merged=join_tac(mul, base_tac);

	int ptr_type = (elem_type==TYPE_STRUCT) ? TYPE_PTR_CHAR : pointer_type_from_base(elem_type);
	SYM *addr_tmp=mk_tmp_type(ptr_type);
	addr_tmp->etc=next_dims;
	TAC *addr_decl=mk_tac(TAC_VAR, addr_tmp, NULL, NULL);
	addr_decl->prev=merged;
	SYM *base_symbol=base_sym;
	if(base_symbol==NULL)
	{
		error("array base computation failed");
		if(next_dims!=NULL)
		{
			array_info_free(next_dims);
			addr_tmp->etc=NULL;
		}
		if(base_exp!=NULL) free(base_exp);
		return mk_exp(NULL, NULL, NULL);
	}
	TAC *add=mk_tac(TAC_ADD, addr_tmp, base_symbol, scaled_tmp);
	add->prev=addr_decl;

	EXP *result=mk_exp(NULL, addr_tmp, add);
	if(next_dims!=NULL)
	{
		result->etc=NULL;
	}
	else if(elem_type==TYPE_STRUCT)
	{
		result->etc=elem_struct;
	}
	else
	{
		result->etc=NULL;
	}

	if(base_exp!=NULL)
	{
		free(base_exp);
	}
	return result;
}

EXP *do_array_element_from_exp(EXP *base_ptr, EXP *index)
{
	if(base_ptr==NULL || base_ptr->ret==NULL)
	{
		error("array reference on invalid expression");
		return mk_exp(NULL, NULL, NULL);
	}
	if(index==NULL || index->ret==NULL)
	{
		error("array index is invalid");
		free(base_ptr);
		return mk_exp(NULL, NULL, NULL);
	}
	ARRAY_INFO *info=(ARRAY_INFO *)base_ptr->ret->etc;
	base_ptr->ret->etc=NULL;
	if(info==NULL)
	{
		error("array metadata missing");
		free(base_ptr);
		return mk_exp(NULL, NULL, NULL);
	}
	int elem_type=info->elem_type;
	STRUCT_TYPE *elem_struct=info->elem_struct;
	ARRAY_INFO *next_dims=array_info_clone(info->child);
	int stride_const=info->stride;

	SYM *scaled_tmp=mk_tmp();
	TAC *decl=mk_tac(TAC_VAR, scaled_tmp, NULL, NULL);
	decl->prev=index->tac;
	TAC *mul=NULL;
	if(sym_is_numeric_const(index->ret) && index->tac==NULL)
	{
		int folded=stride_const * sym_const_value(index->ret);
		TAC *assign=mk_tac(TAC_COPY, scaled_tmp, mk_const(folded), NULL);
		assign->prev=decl;
		mul=assign;
	}
	else if(stride_const==1)
	{
		TAC *assign=mk_tac(TAC_COPY, scaled_tmp, index->ret, NULL);
		assign->prev=decl;
		mul=assign;
	}
	else
	{
		SYM *stride_sym=mk_const(stride_const);
		mul=mk_tac(TAC_MUL, scaled_tmp, index->ret, stride_sym);
		mul->prev=decl;
	}

	TAC *merged=join_tac(mul, base_ptr->tac);

	int ptr_type = (elem_type==TYPE_STRUCT) ? TYPE_PTR_CHAR : pointer_type_from_base(elem_type);
	SYM *addr_tmp=mk_tmp_type(ptr_type);
	addr_tmp->etc=next_dims;
	TAC *addr_decl=mk_tac(TAC_VAR, addr_tmp, NULL, NULL);
	addr_decl->prev=merged;
	TAC *add=mk_tac(TAC_ADD, addr_tmp, base_ptr->ret, scaled_tmp);
	add->prev=addr_decl;
	EXP *result=mk_exp(NULL, addr_tmp, add);
	if(next_dims!=NULL)
	{
		result->etc=NULL;
	}
	else if(elem_type==TYPE_STRUCT)
	{
		result->etc=elem_struct;
	}
	else
	{
		result->etc=NULL;
	}

	array_info_free(info);
	free(base_ptr);
	return result;
}
static EXP *struct_field_from_address(EXP *addr_exp, STRUCT_TYPE *stype, char *field_name)
{
	if(stype==NULL)
	{
		error("struct metadata missing");
		free(addr_exp);
		return mk_exp(NULL, NULL, NULL);
	}
	STRUCT_FIELD *field=struct_field_lookup(stype, field_name);
	if(field==NULL)
	{
		error("unknown field in struct");
		free(addr_exp);
		return mk_exp(NULL, NULL, NULL);
	}
	int ptr_type;
	if(field->array_info!=NULL)
	{
		ptr_type = pointer_type_from_base(field->elem_type);
	}
	else
	{
		ptr_type = pointer_type_from_base(field->type);
	}
	SYM *addr_tmp=mk_tmp_type(ptr_type);
	TAC *decl=mk_tac(TAC_VAR, addr_tmp, NULL, NULL);
	decl->prev=addr_exp->tac;
	SYM *offset_sym=mk_const(field->offset);
	TAC *add=mk_tac(TAC_ADD, addr_tmp, addr_exp->ret, offset_sym);
	add->prev=decl;
	EXP *result=mk_exp(NULL, addr_tmp, add);
	if(addr_exp->ret!=NULL && addr_exp->ret->etc!=NULL)
	{
		array_info_free((ARRAY_INFO *)addr_exp->ret->etc);
		addr_exp->ret->etc=NULL;
	}
	if(field->array_info!=NULL)
	{
		addr_tmp->etc=array_info_clone(field->array_info);
		result->etc=NULL;
	}
	else if(field->type==TYPE_STRUCT)
	{
		result->etc=field->elem_struct;
	}
	else
	{
		result->etc=NULL;
	}
	free(addr_exp);
	return result;
}

EXP *do_struct_field(SYM *structure, char *field_name)
{
	if(structure==NULL)
	{
		error("field access on null symbol");
		return mk_exp(NULL, NULL, NULL);
	}
	if(structure->type!=SYM_VAR || structure->data_type!=TYPE_STRUCT)
	{
		error("field access on non-struct");
		return mk_exp(NULL, NULL, NULL);
	}
	STRUCT_TYPE *stype=(STRUCT_TYPE *)structure->etc;
	if(stype==NULL)
	{
		error("struct metadata missing");
		return mk_exp(NULL, NULL, NULL);
	}
	EXP *base_addr=do_addr(structure);
	return struct_field_from_address(base_addr, stype, field_name);
}

EXP *do_struct_field_from_exp(EXP *base_ptr, char *field_name)
{
	if(base_ptr==NULL)
	{
		error("field access on invalid expression");
		return mk_exp(NULL, NULL, NULL);
	}
	STRUCT_TYPE *stype=(STRUCT_TYPE *)base_ptr->etc;
	if(stype==NULL)
	{
		error("field access requires struct pointer");
		free(base_ptr);
		return mk_exp(NULL, NULL, NULL);
	}
	return struct_field_from_address(base_ptr, stype, field_name);
}

TAC *do_break_stmt(void)
{
	SYM *label=loop_current_break();
	if(label==NULL) return NULL;
	return mk_tac(TAC_GOTO, label, NULL, NULL);
}

TAC *do_continue_stmt(void)
{
	SYM *label=loop_current_continue();
	if(label==NULL) return NULL;
	return mk_tac(TAC_GOTO, label, NULL, NULL);
}

EXP *do_bin( int binop, EXP *exp1, EXP *exp2)
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

	if(exp1==NULL || exp2==NULL)
	{
		error("binary op on invalid expression");
		return mk_exp(NULL, NULL, NULL);
	}

	long long lhs_val=0;
	long long rhs_val=0;
	int lhs_const=exp_is_const_int(exp1, &lhs_val);
	int rhs_const=exp_is_const_int(exp2, &rhs_val);

	if(binop==TAC_ADD)
	{
		if(lhs_const && lhs_val==0)
		{
			free(exp1);
			return exp2;
		}
		if(rhs_const && rhs_val==0)
		{
			free(exp2);
			return exp1;
		}
	}
	else if(binop==TAC_SUB)
	{
		if(rhs_const && rhs_val==0)
		{
			free(exp2);
			return exp1;
		}
		if(lhs_const && lhs_val==0 && exp2->ret!=NULL)
		{
			free(exp1);
			return do_un(TAC_NEG, exp2);
		}
		if(exp1->tac==NULL && exp2->tac==NULL && exp1->ret==exp2->ret)
		{
			free(exp2);
			exp1->ret=mk_const(0);
			exp1->tac=NULL;
			return exp1;
		}
	}
	else if(binop==TAC_MUL)
	{
		if(lhs_const && lhs_val==0 && exp2->tac==NULL)
		{
			free(exp2);
			return exp1;
		}
		if(rhs_const && rhs_val==0 && exp1->tac==NULL)
		{
			free(exp1);
			return exp2;
		}
		if(lhs_const && lhs_val==1)
		{
			free(exp1);
			return exp2;
		}
		if(rhs_const && rhs_val==1)
		{
			free(exp2);
			return exp1;
		}
	}
	else if(binop==TAC_DIV)
	{
		if(rhs_const && rhs_val==1)
		{
			free(exp2);
			return exp1;
		}
		if(lhs_const && lhs_val==0 && exp2->tac==NULL)
		{
			free(exp2);
			return exp1;
		}
	}

	if(exp1->tac==NULL && exp2->tac==NULL)
	{
		SYM *cached=cse_lookup(binop, exp1->ret, exp2->ret);
		if(cached!=NULL)
		{
			free(exp2);
			exp1->ret=cached;
			exp1->tac=NULL;
			return exp1;
		}
	}

	if(lhs_const && rhs_const)
	{
		long long v1=lhs_val;
		long long v2=rhs_val;
		long long folded=0;
		int can_fold=0;
		switch(binop)
		{
			case TAC_ADD:
			folded=v1+v2;
			can_fold=1;
			break;
			case TAC_SUB:
			folded=v1-v2;
			can_fold=1;
			break;
			case TAC_MUL:
			folded=v1*v2;
			can_fold=1;
			break;
			case TAC_DIV:
			if(v2!=0)
			{
				folded=v1/v2;
				can_fold=1;
			}
			break;
		}
		if(can_fold)
		{
			SYM *csym=mk_const((int)folded);
			free(exp2);
			exp1->ret=csym;
			exp1->tac=NULL;
			return exp1;
		}
	}

	/*
	if((exp1->ret->type==SYM_INT) && (exp2->ret->type==SYM_INT))
	{
		int newval;

		switch(binop)
		{
			case TAC_ADD:
			newval=exp1->ret->value + exp2->ret->value;
			break;

			case TAC_SUB:
			newval=exp1->ret->value - exp2->ret->value;
			break;

			case TAC_MUL:
			newval=exp1->ret->value * exp2->ret->value;
			break;

			case TAC_DIV:
			newval=exp1->ret->value / exp2->ret->value;
			break;
		}

		exp1->ret=mk_const(newval);

		return exp1;
	}
	*/

	SYM *lhs=exp1->ret;
	SYM *rhs=exp2->ret;
	temp=mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev=join_tac(exp1->tac, exp2->tac);
	ret=mk_tac(binop, temp->a, lhs, rhs);
	ret->prev=temp;

	exp1->ret=temp->a;
	exp1->tac=ret;
	cse_insert(binop, lhs, rhs, temp->a);

	return exp1;  
}   

EXP *do_cmp( int binop, EXP *exp1, EXP *exp2)
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

	if(exp1==NULL || exp2==NULL)
	{
		error("comparison on invalid expression");
		return mk_exp(NULL, NULL, NULL);
	}

	long long lhs_val=0;
	long long rhs_val=0;
	int lhs_const=exp_is_const_int(exp1, &lhs_val);
	int rhs_const=exp_is_const_int(exp2, &rhs_val);

	if(lhs_const && rhs_const)
	{
		int result=0;
		switch(binop)
		{
			case TAC_EQ:
			result=(lhs_val==rhs_val);
			break;
			case TAC_NE:
			result=(lhs_val!=rhs_val);
			break;
			case TAC_LT:
			result=(lhs_val<rhs_val);
			break;
			case TAC_LE:
			result=(lhs_val<=rhs_val);
			break;
			case TAC_GT:
			result=(lhs_val>rhs_val);
			break;
			case TAC_GE:
			result=(lhs_val>=rhs_val);
			break;
			default:
			break;
		}
		free(exp2);
		exp1->ret=mk_const(result);
		exp1->tac=NULL;
		return exp1;
	}

	if(exp1->tac==NULL && exp2->tac==NULL && exp1->ret==exp2->ret)
	{
		int result=0;
		switch(binop)
		{
			case TAC_EQ:
			case TAC_LE:
			case TAC_GE:
			result=1;
			break;
			case TAC_NE:
			case TAC_LT:
			case TAC_GT:
			result=0;
			break;
			default:
			break;
		}
		free(exp2);
		exp1->ret=mk_const(result);
		exp1->tac=NULL;
		return exp1;
	}

	temp=mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev=join_tac(exp1->tac, exp2->tac);
	ret=mk_tac(binop, temp->a, exp1->ret, exp2->ret);
	ret->prev=temp;

	exp1->ret=temp->a;
	exp1->tac=ret;

	return exp1;  
}   

EXP *do_un( int unop, EXP *exp) 
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

	if(exp==NULL)
	{
		error("unary op on invalid expression");
		return mk_exp(NULL, NULL, NULL);
	}

	if(unop==TAC_NEG)
	{
		long long val=0;
		if(exp_is_const_int(exp, &val))
		{
			exp->ret=mk_const((int)(-val));
			exp->tac=NULL;
			return exp;
		}
	}

	temp=mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev=exp->tac;
	ret=mk_tac(unop, temp->a, exp->ret, NULL);
	ret->prev=temp;

	exp->ret=temp->a;
	exp->tac=ret;

	return exp;   
}

TAC *do_call(char *name, EXP *arglist)
{
	EXP  *alt; /* For counting args */
	TAC *code; /* Resulting code */
	TAC *temp; /* Temporary for building code */

	code=NULL;
	for(alt=arglist; alt !=NULL; alt=alt->next) code=join_tac(code, alt->tac);

	while(arglist !=NULL) /* Generate ARG instructions */
	{
		temp=mk_tac(TAC_ACTUAL, arglist->ret, NULL, NULL);
		temp->prev=code;
		code=temp;

		alt=arglist->next;
		arglist=alt;
	};

	temp=mk_tac(TAC_CALL, NULL, (SYM *)strdup(name), NULL);
	temp->prev=code;
	code=temp;

	return code;
}

EXP *do_call_ret(char *name, EXP *arglist)
{
	EXP  *alt; /* For counting args */
	SYM *ret; /* Where function result will go */
	TAC *code; /* Resulting code */
	TAC *temp; /* Temporary for building code */

	ret=mk_tmp(); /* For the result */
	code=mk_tac(TAC_VAR, ret, NULL, NULL);

	for(alt=arglist; alt !=NULL; alt=alt->next) code=join_tac(code, alt->tac);

	while(arglist !=NULL) /* Generate ARG instructions */
	{
		temp=mk_tac(TAC_ACTUAL, arglist->ret, NULL, NULL);
		temp->prev=code;
		code=temp;

		alt=arglist->next;
		arglist=alt;
	};

	temp=mk_tac(TAC_CALL, ret, (SYM *)strdup(name), NULL);
	temp->prev=code;
	code=temp;

	return mk_exp(NULL, ret, code);
}

char *mk_lstr(int i)
{
	char lstr[10]="L";
	sprintf(lstr,"L%d",i);
	return(strdup(lstr));	
}

TAC *do_if(EXP *exp, TAC *stmt)
{
	TAC *label=mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL);
	TAC *code=mk_tac(TAC_IFZ, label->a, exp->ret, NULL);

	code->prev=exp->tac;
	code=join_tac(code, stmt);
	label->prev=code;

	return label;
}

TAC *do_test(EXP *exp, TAC *stmt1, TAC *stmt2)
{
	TAC *label1=mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL);
	TAC *label2=mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL);
	TAC *code1=mk_tac(TAC_IFZ, label1->a, exp->ret, NULL);
	TAC *code2=mk_tac(TAC_GOTO, label2->a, NULL, NULL);

	code1->prev=exp->tac; /* Join the code */
	code1=join_tac(code1, stmt1);
	code2->prev=code1;
	label1->prev=code2;
	label1=join_tac(label1, stmt2);
	label2->prev=label1;
	
	return label2;
}

TAC *do_while(EXP *exp, TAC *stmt, LOOP_INFO *info)
{
	SYM *start_label = info->start_label;
	SYM *break_label = info->break_label;

	TAC *goto_start = mk_tac(TAC_GOTO, start_label, NULL, NULL);
	if(stmt != NULL)
	{
		goto_start = join_tac(stmt, goto_start);
	}

	TAC *chain = goto_start;

	if(exp != NULL)
	{
		TAC *ifz = mk_tac(TAC_IFZ, break_label, exp->ret, NULL);
		ifz->prev = exp->tac;
		chain = join_tac(ifz, chain);
	}

	TAC *start_tac = mk_tac(TAC_LABEL, start_label, NULL, NULL);
	chain = join_tac(start_tac, chain);

	TAC *exit_label = mk_tac(TAC_LABEL, break_label, NULL, NULL);
	exit_label->prev = chain;

	return exit_label;
}

TAC *do_for(TAC *init, EXP *cond, TAC *post, TAC *stmt, LOOP_INFO *info)
{
	SYM *start_label = info->start_label;
	SYM *continue_label = info->continue_label;
	SYM *break_label = info->break_label;

	TAC *goto_start = mk_tac(TAC_GOTO, start_label, NULL, NULL);

	if(post != NULL)
	{
		goto_start = join_tac(post, goto_start);
	}

	TAC *continue_tac = mk_tac(TAC_LABEL, continue_label, NULL, NULL);
	goto_start = join_tac(continue_tac, goto_start);

	TAC *chain = goto_start;

	if(stmt != NULL)
	{
		chain = join_tac(stmt, chain);
	}

	if(cond != NULL)
	{
		TAC *ifz = mk_tac(TAC_IFZ, break_label, cond->ret, NULL);
		ifz->prev = cond->tac;
		chain = join_tac(ifz, chain);
	}

	TAC *start_tac = mk_tac(TAC_LABEL, start_label, NULL, NULL);
	chain = join_tac(start_tac, chain);

	if(init != NULL)
	{
		chain = join_tac(init, chain);
	}

	TAC *exit_label = mk_tac(TAC_LABEL, break_label, NULL, NULL);
	exit_label->prev = chain;

	return exit_label;
}

TAC *do_switch(EXP *expr, SWITCH_CASE *cases, SYM *default_label, TAC *default_code, LOOP_INFO *info)
{
	TAC *sequence = expr ? expr->tac : NULL;
	SYM *expr_temp = mk_tmp();
	TAC *temp_decl = mk_tac(TAC_VAR, expr_temp, NULL, NULL);
	sequence = join_tac(sequence, temp_decl);
	TAC *copy = mk_tac(TAC_COPY, expr_temp, expr->ret, NULL);
	sequence = join_tac(sequence, copy);

	for(SWITCH_CASE *iter=cases; iter!=NULL; iter=iter->next)
	{
		SYM *diff = mk_tmp();
		TAC *diff_decl = mk_tac(TAC_VAR, diff, NULL, NULL);
		sequence = join_tac(sequence, diff_decl);
		TAC *sub = mk_tac(TAC_SUB, diff, expr_temp, iter->value);
		sequence = join_tac(sequence, sub);
		TAC *ifz = mk_tac(TAC_IFZ, iter->label, diff, NULL);
		sequence = join_tac(sequence, ifz);
	}

	SYM *fall_label = default_label ? default_label : info->break_label;
	TAC *jump = mk_tac(TAC_GOTO, fall_label, NULL, NULL);
	sequence = join_tac(sequence, jump);

	for(SWITCH_CASE *iter=cases; iter!=NULL; iter=iter->next)
	{
		if(iter->code != NULL)
		{
			sequence = join_tac(sequence, iter->code);
		}
		else
		{
			TAC *label_tac = mk_tac(TAC_LABEL, iter->label, NULL, NULL);
			sequence = join_tac(sequence, label_tac);
		}
	}

	if(default_code != NULL)
	{
		sequence = join_tac(sequence, default_code);
	}

	TAC *exit_label = mk_tac(TAC_LABEL, info->break_label, NULL, NULL);
	sequence = join_tac(sequence, exit_label);

	return sequence;
}

SYM *get_var(char *name)
{
	SYM *sym=NULL; /* Pointer to looked up symbol */

	if(scope) sym=lookup_sym(sym_tab_local,name);

	if(sym==NULL) sym=lookup_sym(sym_tab_global,name);

	if(sym==NULL)
	{
		error("name not declared as local/global variable");
		return NULL;
	}

	if(sym->type!=SYM_VAR)
	{
		error("not a variable");
		return NULL;
	}

	return sym;
} 

EXP *mk_exp(EXP *next, SYM *ret, TAC *code)
{
	EXP *exp=(EXP *)malloc(sizeof(EXP));

	exp->next=next;
	exp->ret=ret;
	exp->tac=code;
	exp->etc=NULL;

	return exp;
}

EXP *mk_var_exp(SYM *var)
{
	if(var==NULL)
	{
		error("null variable in expression");
		return mk_exp(NULL, NULL, NULL);
	}
	if(var->type!=SYM_VAR)
	{
		return mk_exp(NULL, var, NULL);
	}
	if(var->scope==0 && (var->data_type==TYPE_INT || var->data_type==TYPE_CHAR) && var->is_const)
	{
		SYM *const_sym = (var->data_type==TYPE_CHAR) ? mk_char_const(var->const_value) : mk_const(var->const_value);
		return mk_exp(NULL, const_sym, NULL);
	}
	return mk_exp(NULL, var, NULL);
}

SYM *mk_text(char *text)
{
	SYM *sym=NULL; /* Pointer to looked up symbol */

	sym=lookup_sym(sym_tab_global,text);

	/* text already used */
	if(sym!=NULL)
	{
		return sym;
	}

	/* text unseen before */
	sym=mk_sym();
	sym->type=SYM_TEXT;
	sym->name=text;
	sym->label=next_label++;

	insert_sym(&sym_tab_global,sym);
	return sym;
}

static SYM *mk_number_const(int n, int data_type)
{
	SYM *sym=NULL;
	char name[20];

	sprintf(name, "%c%d", data_type==TYPE_CHAR ? 'C' : 'I', n);

	sym=lookup_sym(sym_tab_global, name);
	if(sym!=NULL)
	{
		return sym;
	}

	sym=mk_sym();
	sym->type=SYM_INT;
	sym->value=n;
	sym->name=strdup(name);
	sym->data_type=data_type;
	insert_sym(&sym_tab_global,sym);

	return sym;
}

SYM *mk_const(int n)
{
	return mk_number_const(n, TYPE_INT);
}

SYM *mk_char_const(int n)
{
	return mk_number_const(n, TYPE_CHAR);
}

char *to_str(SYM *s, char *str) 
{
	if(s==NULL)	return "NULL";

	switch(s->type)
	{
		case SYM_FUNC:
		case SYM_VAR:
		/* Just return the name */
		return s->name;

		case SYM_TEXT:
		/* Put the address of the text */
		sprintf(str, "L%d", s->label);
		return str;

		case SYM_INT:
		/* Convert the number to string */
		sprintf(str, "%d", s->value);
		return str;

		default:
		/* Unknown arg type */
		error("unknown TAC arg type");
		return "?";
	}
} 

void out_str(FILE *f, const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(f, format, args);
    va_end(args);
}

void out_sym(FILE *f, SYM *s)
{
	out_str(f, "%p\t%s", s, s->name);
}

void out_tac(FILE *f, TAC *i)
{
	char sa[12]; /* For text of TAC args */
	char sb[12];
	char sc[12];

	switch(i->op)
	{
		case TAC_UNDEF:
		fprintf(f, "undef");
		break;

		case TAC_ADD:
		fprintf(f, "%s = %s + %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_SUB:
		fprintf(f, "%s = %s - %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_MUL:
		fprintf(f, "%s = %s * %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_DIV:
		fprintf(f, "%s = %s / %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_EQ:
		fprintf(f, "%s = (%s == %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_NE:
		fprintf(f, "%s = (%s != %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_LT:
		fprintf(f, "%s = (%s < %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_LE:
		fprintf(f, "%s = (%s <= %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_GT:
		fprintf(f, "%s = (%s > %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_GE:
		fprintf(f, "%s = (%s >= %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_NEG:
		fprintf(f, "%s = - %s", to_str(i->a, sa), to_str(i->b, sb));
		break;

		case TAC_COPY:
		fprintf(f, "%s = %s", to_str(i->a, sa), to_str(i->b, sb));
		break;

		case TAC_GOTO:
		fprintf(f, "goto %s", i->a->name);
		break;

		case TAC_IFZ:
		fprintf(f, "ifz %s goto %s", to_str(i->b, sb), i->a->name);
		break;

		case TAC_ACTUAL:
		fprintf(f, "actual %s", to_str(i->a, sa));
		break;

		case TAC_FORMAL:
		fprintf(f, "formal %s", to_str(i->a, sa));
		break;

		case TAC_CALL:
		if(i->a==NULL) fprintf(f, "call %s", (char *)i->b);
		else fprintf(f, "%s = call %s", to_str(i->a, sa), (char *)i->b);
		break;

		case TAC_INPUT:
		fprintf(f, "input %s", to_str(i->a, sa));
		break;

		case TAC_OUTPUT:
		fprintf(f, "output %s", to_str(i->a, sa));
		break;

		case TAC_RETURN:
		fprintf(f, "return %s", to_str(i->a, sa));
		break;

		case TAC_LABEL:
		fprintf(f, "label %s", i->a->name);
		break;

		case TAC_ADDR:
		fprintf(f, "%s = &%s", to_str(i->a, sa), to_str(i->b, sb));
		break;

		case TAC_LOAD:
		fprintf(f, "%s = *%s", to_str(i->a, sa), to_str(i->b, sb));
		break;

		case TAC_STORE:
		fprintf(f, "*%s = %s", to_str(i->a, sa), to_str(i->b, sb));
		break;

		case TAC_VAR:
		fprintf(f, "var %s", to_str(i->a, sa));
		break;

		case TAC_BEGINFUNC:
		fprintf(f, "begin");
		break;

		case TAC_ENDFUNC:
		fprintf(f, "end");
		break;

		default:
		error("unknown TAC opcode");
		break;
	}
}
