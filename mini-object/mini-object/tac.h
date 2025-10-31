#ifndef TAC_H
#define TAC_H

#include <stdio.h>

/* data type */
#define TYPE_INT 0
#define TYPE_CHAR 1
#define TYPE_PTR_INT 2
#define TYPE_PTR_CHAR 3
#define TYPE_ARRAY_INT 4
#define TYPE_ARRAY_CHAR 5
#define TYPE_STRUCT 6
#define TYPE_ARRAY_STRUCT 7

/* type of symbol */
#define SYM_UNDEF 0
#define SYM_VAR 1
#define SYM_FUNC 2
#define SYM_TEXT 3
#define SYM_INT 4
#define SYM_LABEL 5
#define SYM_STRUCT 6

/* type of tac */
#define TAC_UNDEF 0
#define TAC_ADD 1
#define TAC_SUB 2
#define TAC_MUL 3
#define TAC_DIV 4
#define TAC_EQ 5
#define TAC_NE 6
#define TAC_LT 7
#define TAC_LE 8
#define TAC_GT 9
#define TAC_GE 10
#define TAC_NEG 11
#define TAC_COPY 12
#define TAC_GOTO 13
#define TAC_IFZ 14
#define TAC_BEGINFUNC 15
#define TAC_ENDFUNC 16
#define TAC_LABEL 17
#define TAC_VAR 18
#define TAC_FORMAL 19
#define TAC_ACTUAL 20
#define TAC_CALL 21
#define TAC_RETURN 22
#define TAC_INPUT 23
#define TAC_OUTPUT 24
#define TAC_ADDR 25
#define TAC_LOAD 26
#define TAC_STORE 27

typedef struct sym
{
	char *name;
	int type;
	int scope;
	int offset;
	int data_type;
	int value;
	int label;
	void *address;
	void *etc;
	struct sym *next;
} SYM;

struct struct_type;

typedef struct dim_list
{
	int length;
	struct dim_list *next;
} DIM_LIST;

typedef struct array_info
{
	int length;
	int elem_type;
	int elem_size;
	struct struct_type *elem_struct;
	struct array_info *child;
	int stride;
	int total_size;
} ARRAY_INFO;

typedef struct struct_field
{
	char *name;
	int type;
	int offset;
	int size;
	int elem_type;
	int elem_size;
	struct struct_type *elem_struct;
	ARRAY_INFO *array_info;
	struct struct_field *next;
} STRUCT_FIELD;

typedef struct struct_type
{
	char *name;
	STRUCT_FIELD *fields;
	int size;
	struct struct_type *next;
} STRUCT_TYPE;

typedef struct tac
{
	struct tac *next;
	struct tac *prev;
	int op;
	SYM *a;
	SYM *b;
	SYM *c;
	void *etc;
} TAC;

typedef struct exp
{
	struct exp *next;
	TAC *tac;
	SYM *ret;
	void *etc;
} EXP;

typedef struct switch_case
{
	SYM *value;
	SYM *label;
	TAC *code;
	struct switch_case *next;
} SWITCH_CASE;

typedef struct switch_body
{
	SWITCH_CASE *cases;
	SYM *default_label;
	TAC *default_code;
} SWITCH_BODY;

typedef struct default_block
{
	SYM *label;
	TAC *code;
} DEFAULT_BLOCK;

typedef struct loop_info
{
	SYM *start_label;
	SYM *continue_label;
	SYM *break_label;
} LOOP_INFO;

/* pointer helpers */
int is_pointer_type(int data_type);
int pointer_type_from_base(int base_type);
int pointer_base_type(int pointer_type);
int is_array_type(int data_type);
int array_base_type(int array_type);
int type_size(int data_type);
STRUCT_TYPE *struct_lookup(char *name);
STRUCT_TYPE *struct_define(char *name, STRUCT_FIELD *fields);
STRUCT_FIELD *struct_field_create(char *name, int base_type, DIM_LIST *dims, STRUCT_TYPE *elem_struct);
STRUCT_FIELD *struct_field_list_append(STRUCT_FIELD *list, STRUCT_FIELD *field);
STRUCT_FIELD *struct_field_lookup(STRUCT_TYPE *type, char *name);

/* global var */
extern FILE *file_x, *file_s;
extern int yylineno, scope, next_tmp, next_label;
extern SYM *sym_tab_global, *sym_tab_local;
extern TAC *tac_first, *tac_last;

/* function */
void tac_init(void);
void tac_complete(void);
TAC *join_tac(TAC *c1, TAC *c2);
void out_str(FILE *f, const char *format, ...);
void out_sym(FILE *f, SYM *s);
void out_tac(FILE *f, TAC *i);
SYM *mk_label(char *name);
SYM *mk_tmp(void);
SYM *mk_tmp_type(int data_type);
SYM *mk_const(int n);
SYM *mk_char_const(int n);
SYM *mk_text(char *text);
TAC *mk_tac(int op, SYM *a, SYM *b, SYM *c);
EXP *mk_exp(EXP *next, SYM *ret, TAC *code);
char *mk_lstr(int i);
SYM *get_var(char *name);
SYM *declare_func(char *name);
TAC *declare_var(char *name, int data_type);
TAC *declare_para(char *name, int data_type);
TAC *declare_array(char *name, int base_type, DIM_LIST *dims);
TAC *do_func(SYM *name, TAC *args, TAC *code);
TAC *do_assign(SYM *var, EXP *exp);
TAC *do_output(SYM *var);
TAC *do_input(SYM *var);
TAC *do_call(char *name, EXP *arglist);
TAC *do_if(EXP *exp, TAC *stmt);
TAC *do_test(EXP *exp, TAC *stmt1, TAC *stmt2);
TAC *do_while(EXP *exp, TAC *stmt, LOOP_INFO *info);
TAC *do_for(TAC *init, EXP *cond, TAC *post, TAC *stmt, LOOP_INFO *info);
TAC *do_switch(EXP *expr, SWITCH_CASE *cases, SYM *default_label, TAC *default_code, LOOP_INFO *info);
EXP *do_bin(int binop, EXP *exp1, EXP *exp2);
EXP *do_cmp(int binop, EXP *exp1, EXP *exp2);
EXP *do_un(int unop, EXP *exp);
EXP *do_call_ret(char *name, EXP *arglist);
EXP *do_addr(SYM *var);
EXP *do_deref(EXP *ptr);
TAC *do_store(EXP *ptr, EXP *value);
EXP *do_array_element(SYM *array, EXP *index);
EXP *do_array_element_from_exp(EXP *base_ptr, EXP *index);
EXP *do_struct_field(SYM *structure, char *field_name);
EXP *do_struct_field_from_exp(EXP *base_ptr, char *field_name);
TAC *do_break_stmt(void);
TAC *do_continue_stmt(void);
void error(const char *format, ...);
void loop_push(SYM *continue_label, SYM *break_label);
void loop_pop(void);
SYM *loop_current_continue(void);
SYM *loop_current_break(void);

extern STRUCT_TYPE *current_struct_decl;

#endif /* TAC_H */
