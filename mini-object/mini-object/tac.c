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

void tac_init()
{
	scope=0;
	sym_tab_global=NULL;
	sym_tab_local=NULL;	
	next_tmp=0;
	next_label=1;
}

void tac_complete()
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
	t->data_type=TYPE_INT;
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

	code=mk_tac(TAC_COPY, var, exp->ret, NULL);
	code->prev=exp->tac;

	return code;
}

TAC *do_input(SYM *var)
{
	TAC *code;

	if(var->type !=SYM_VAR) error("input to non-variable");

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
	if(!(var->data_type==TYPE_INT || var->data_type==TYPE_CHAR))
	{
		error("address-of unsupported type");
		return mk_exp(NULL, NULL, NULL);
	}
	SYM *tmp=mk_tmp_type(pointer_type_from_base(var->data_type));
	TAC *decl=mk_tac(TAC_VAR, tmp, NULL, NULL);
	TAC *addr=mk_tac(TAC_ADDR, tmp, var, NULL);
	addr->prev=decl;
	return mk_exp(NULL, tmp, addr);
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
	TAC *code=join_tac(ptr->tac, value->tac);
	TAC *store=mk_tac(TAC_STORE, ptr->ret, value->ret, NULL);
	store->prev=code;
	return store;
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

	temp=mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev=join_tac(exp1->tac, exp2->tac);
	ret=mk_tac(binop, temp->a, exp1->ret, exp2->ret);
	ret->prev=temp;

	exp1->ret=temp->a;
	exp1->tac=ret;

	return exp1;  
}   

EXP *do_cmp( int binop, EXP *exp1, EXP *exp2)
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

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

	return exp;
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
