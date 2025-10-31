%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tac.h"

int yylex();
void yyerror(char* msg);

int current_decl_type = TYPE_INT;

extern STRUCT_TYPE *current_struct_decl;

%}

%union
{
	char character;
	char *string;
	int number;
	LOOP_INFO *loop;
	SWITCH_CASE *cases;
	SWITCH_BODY *switch_body;
	DEFAULT_BLOCK *def_block;
	SYM *sym;
	TAC *tac;
	EXP	*exp;
	STRUCT_FIELD *struct_field;
	STRUCT_TYPE *struct_type;
}

%token INT CHAR STRUCT EQ NE LT LE GT GE UMINUS IF ELSE WHILE FOR SWITCH CASE DEFAULT BREAK CONTINUE FUNC INPUT OUTPUT RETURN
%token <string> INTEGER IDENTIFIER TEXT
%token <character> CHARACTER

%left EQ NE LT LE GT GE
%left '+' '-'
%left '*' '/'
%right UMINUS DEREF ADDROF

%type <tac> program function_declaration_list function_declaration function parameter_list variable_list declarator statement assignment_statement return_statement if_statement while_statement for_statement switch_statement break_statement continue_statement call_statement block declaration_list declaration statement_list input_statement output_statement for_init for_post case_statement_list struct_declaration_tail
%type <exp> argument_list expression_list expression call_expression expression_opt pointer_lvalue array_reference struct_reference
%type <sym> function_head case_value
%type <loop> switch_header
%type <cases> case_clause
%type <switch_body> switch_sections
%type <def_block> default_clause
%type <number> type_specifier
%type <struct_field> struct_field_list struct_field_decl
%type <struct_type> struct_definition

%%

program : function_declaration_list
{
	tac_last=$1;
	tac_complete();
}
;

function_declaration_list : function_declaration
| function_declaration_list function_declaration
{
	$$=join_tac($1, $2);
}
;

function_declaration : function
| declaration
;

declaration : type_specifier variable_list ';'
{
	$$=$2;
	current_struct_decl=NULL;
}
| struct_definition struct_declaration_tail ';'
{
	$$=$2;
	current_struct_decl=NULL;
}
;

variable_list : declarator
| variable_list ',' declarator
{
	if($1==NULL) $$=$3;
	else if($3==NULL) $$=$1;
	else $$=join_tac($1, $3);
}
;

declarator : IDENTIFIER
{
	$$=declare_var($1, current_decl_type);
}
| IDENTIFIER '[' INTEGER ']'
{
	$$=declare_array($1, current_decl_type, atoi($3));
}
| '*' IDENTIFIER
{
	if(current_decl_type==TYPE_STRUCT)
	{
		error("pointers to struct not supported");
		$$=NULL;
	}
	else
	{
		$$=declare_var($2, pointer_type_from_base(current_decl_type));
	}
}
;

function : function_head '(' parameter_list ')' block
{
	$$=do_func($1, $3, $5);
	scope=0; /* Leave local scope. */
	sym_tab_local=NULL; /* Clear local symbol table. */
}
| error
{
	error("Bad function syntax");
	$$=NULL;
}
;

function_head : IDENTIFIER
{
	$$=declare_func($1);
	scope=1; /* Enter local scope. */
	sym_tab_local=NULL; /* Init local symbol table. */
}
;

type_specifier : INT
{
	current_decl_type = TYPE_INT;
	current_struct_decl = NULL;
	$$ = TYPE_INT;
}
| CHAR
{
	current_decl_type = TYPE_CHAR;
	current_struct_decl = NULL;
	$$ = TYPE_CHAR;
}
| STRUCT IDENTIFIER
{
	STRUCT_TYPE *stype=struct_lookup($2);
	if(stype==NULL)
	{
		error("unknown struct type");
	}
	current_struct_decl = stype;
	current_decl_type = TYPE_STRUCT;
	$$ = TYPE_STRUCT;
}
;

struct_definition : STRUCT IDENTIFIER '{' struct_field_list '}'
{
	STRUCT_TYPE *stype=struct_define($2, $4);
	current_struct_decl = stype;
	current_decl_type = TYPE_STRUCT;
	$$=stype;
}
;

struct_field_list : struct_field_list struct_field_decl
{
	$$=struct_field_list_append($1, $2);
}
| struct_field_decl
{
	$$=$1;
}
;

struct_field_decl : INT IDENTIFIER ';'
{
	$$=struct_field_create($2, TYPE_INT, 0, NULL);
}
| CHAR IDENTIFIER ';'
{
	$$=struct_field_create($2, TYPE_CHAR, 0, NULL);
}
| INT IDENTIFIER '[' INTEGER ']' ';'
{
	$$=struct_field_create($2, TYPE_INT, atoi($4), NULL);
}
| CHAR IDENTIFIER '[' INTEGER ']' ';'
{
	$$=struct_field_create($2, TYPE_CHAR, atoi($4), NULL);
}
| STRUCT IDENTIFIER IDENTIFIER ';'
{
	STRUCT_TYPE *stype=struct_lookup($2);
	if(stype==NULL)
	{
		error("unknown struct type");
		$$=NULL;
	}
	else
	{
		$$=struct_field_create($3, TYPE_STRUCT, 0, stype);
	}
}
| STRUCT IDENTIFIER IDENTIFIER '[' INTEGER ']' ';'
{
	STRUCT_TYPE *stype=struct_lookup($2);
	if(stype==NULL)
	{
		error("unknown struct type");
		$$=NULL;
	}
	else
	{
		$$=struct_field_create($3, TYPE_STRUCT, atoi($5), stype);
	}
}
;

struct_declaration_tail : variable_list
{
	$$=$1;
}
|
{
	$$=NULL;
}
;

parameter_list : IDENTIFIER
{
	$$=declare_para($1, TYPE_INT);
}               
| parameter_list ',' IDENTIFIER
{
	$$=join_tac($1, declare_para($3, TYPE_INT));
}               
|
{
	$$=NULL;
}
;

statement : assignment_statement ';'
| input_statement ';'
| output_statement ';'
| call_statement ';'
| return_statement ';'
| if_statement
| while_statement
| for_statement
| switch_statement
| break_statement ';'
| continue_statement ';'
| block
| error
{
	error("Bad statement syntax");
	$$=NULL;
}
;

block : '{' declaration_list statement_list '}'
{
	$$=join_tac($2, $3);
}               
;

declaration_list        :
{
	$$=NULL;
}
| declaration_list declaration
{
	$$=join_tac($1, $2);
}
;

statement_list : statement
| statement_list statement
{
	$$=join_tac($1, $2);
}               
;

assignment_statement : IDENTIFIER '=' expression
{
	$$=do_assign(get_var($1), $3);
}
| pointer_lvalue '=' expression
{
	$$=do_store($1, $3);
}
;

expression : expression '+' expression
{
	$$=do_bin(TAC_ADD, $1, $3);
}
| expression '-' expression
{
	$$=do_bin(TAC_SUB, $1, $3);
}
| expression '*' expression
{
	$$=do_bin(TAC_MUL, $1, $3);
}
| expression '/' expression
{
	$$=do_bin(TAC_DIV, $1, $3);
}
| '-' expression  %prec UMINUS
{
	$$=do_un(TAC_NEG, $2);
}
| expression EQ expression
{
	$$=do_cmp(TAC_EQ, $1, $3);
}
| expression NE expression
{
	$$=do_cmp(TAC_NE, $1, $3);
}
| expression LT expression
{
	$$=do_cmp(TAC_LT, $1, $3);
}
| expression LE expression
{
	$$=do_cmp(TAC_LE, $1, $3);
}
| expression GT expression
{
	$$=do_cmp(TAC_GT, $1, $3);
}
| expression GE expression
{
	$$=do_cmp(TAC_GE, $1, $3);
}
| '(' expression ')'
{
	$$=$2;
}               
| '&' array_reference %prec ADDROF
{
	$$=$2;
}
| '&' struct_reference %prec ADDROF
{
	$$=$2;
}
| '&' IDENTIFIER %prec ADDROF
{
	$$=do_addr(get_var($2));
}
| '*' expression %prec DEREF
{
	$$=do_deref($2);
}
| INTEGER
{
	$$=mk_exp(NULL, mk_const(atoi($1)), NULL);
}
| CHARACTER
{
	$$=mk_exp(NULL, mk_char_const($1), NULL);
}
| IDENTIFIER
{
	$$=mk_exp(NULL, get_var($1), NULL);
}
| call_expression
{
	$$=$1;
}               
| array_reference
{
	if($1->etc!=NULL)
	{
		error("struct element requires field selection");
	free($1);
	$$=mk_exp(NULL, NULL, NULL);
	}
	else
	{
		$$=do_deref($1);
	}
}
| struct_reference
{
	$$=do_deref($1);
}
| error
{
	error("Bad expression syntax");
	$$=mk_exp(NULL, NULL, NULL);
}
;

argument_list           :
{
	$$=NULL;
}
| expression_list
;

expression_list : expression
|  expression_list ',' expression
{
	$3->next=$1;
	$$=$3;
}
;

input_statement : INPUT IDENTIFIER
{
	$$=do_input(get_var($2));
}
;

output_statement : OUTPUT expression
{
	TAC *out=do_output($2->ret);
	out->prev=$2->tac;
	$$=out;
}
| OUTPUT TEXT
{
	$$=do_output(mk_text($2));
}
;

return_statement : RETURN expression
{
	TAC *t=mk_tac(TAC_RETURN, $2->ret, NULL, NULL);
	t->prev=$2->tac;
	$$=t;
}               
;

if_statement : IF '(' expression ')' block
{
	$$=do_if($3, $5);
}
| IF '(' expression ')' block ELSE block
{
	$$=do_test($3, $5, $7);
}
;

while_statement : WHILE '(' expression ')'
{
	LOOP_INFO *info=(LOOP_INFO *)malloc(sizeof(LOOP_INFO));
	info->start_label=mk_label(mk_lstr(next_label++));
	info->continue_label=info->start_label;
	info->break_label=mk_label(mk_lstr(next_label++));
	loop_push(info->continue_label, info->break_label);
	$<loop>$=info;
}
statement
{
	LOOP_INFO *info=$<loop>5;
	loop_pop();
	$$=do_while($3, $6, info);
	free(info);
}               
;

for_statement : FOR '(' for_init ';' expression_opt ';' for_post ')'
{
	LOOP_INFO *info=(LOOP_INFO *)malloc(sizeof(LOOP_INFO));
	info->start_label=mk_label(mk_lstr(next_label++));
	info->continue_label=mk_label(mk_lstr(next_label++));
	info->break_label=mk_label(mk_lstr(next_label++));
	loop_push(info->continue_label, info->break_label);
	$<loop>$=info;
}
statement
{
	LOOP_INFO *info=$<loop>9;
	loop_pop();
	$$=do_for($3, $5, $7, $10, info);
	free(info);
}
;

for_init : assignment_statement
{
	$$=$1;
}
|
{
	$$=NULL;
}
;

for_post : assignment_statement
{
	$$=$1;
}
|
{
	$$=NULL;
}
;

expression_opt : expression
{
	$$=$1;
}
|
{
	$$=mk_exp(NULL, mk_const(1), NULL);
}
;

break_statement : BREAK
{
	$$=do_break_stmt();
}
;

continue_statement : CONTINUE
{
	$$=do_continue_stmt();
}
;

array_reference : IDENTIFIER '[' expression ']'
{
	$$=do_array_element(get_var($1), $3);
}
| struct_reference '[' expression ']'
{
	$$=do_array_element_from_exp($1, $3);
}
;

pointer_lvalue : '*' IDENTIFIER
{
	$$=mk_exp(NULL, get_var($2), NULL);
}
| array_reference
{
	if($1->etc!=NULL)
	{
		error("struct element requires field selection");
	free($1);
	$$=NULL;
	}
	else
	{
		$$=$1;
	}
}
| struct_reference
{
	$$=$1;
}
;

struct_reference : IDENTIFIER '.' IDENTIFIER
{
	$$=do_struct_field(get_var($1), $3);
}
| array_reference '.' IDENTIFIER
{
	$$=do_struct_field_from_exp($1, $3);
}
| struct_reference '.' IDENTIFIER
{
	$$=do_struct_field_from_exp($1, $3);
}
;

switch_header :
{
	LOOP_INFO *info=(LOOP_INFO *)malloc(sizeof(LOOP_INFO));
	info->start_label=NULL;
	info->continue_label=NULL;
	info->break_label=mk_label(mk_lstr(next_label++));
	loop_push(NULL, info->break_label);
	$$=info;
}
;

switch_statement : SWITCH '(' expression ')' switch_header '{' switch_sections '}'
{
	SWITCH_BODY *body=$7;
	LOOP_INFO *info=$5;
	loop_pop();
	$$=do_switch($3, body->cases, body->default_label, body->default_code, info);
	free(body);
	free(info);
}
;

switch_sections :
{
	SWITCH_BODY *body=(SWITCH_BODY *)malloc(sizeof(SWITCH_BODY));
	body->cases=NULL;
	body->default_label=NULL;
	body->default_code=NULL;
	$$=body;
}
| switch_sections case_clause
{
	SWITCH_BODY *body=$1;
	if(body->cases==NULL)
	{
		body->cases=$2;
	}
	else
	{
		SWITCH_CASE *iter=body->cases;
		while(iter->next!=NULL) iter=iter->next;
		iter->next=$2;
	}
	$$=body;
}
| switch_sections default_clause
{
	SWITCH_BODY *body=$1;
	if(body->default_code!=NULL)
	{
		error("duplicate default label in switch");
	}
	else
	{
		body->default_label=$2->label;
		body->default_code=$2->code;
	}
	free($2);
	$$=body;
}
;

case_clause : CASE case_value ':' case_statement_list
{
	SWITCH_CASE *node=(SWITCH_CASE *)malloc(sizeof(SWITCH_CASE));
	node->value=$2;
	node->label=mk_label(mk_lstr(next_label++));
	TAC *label_tac=mk_tac(TAC_LABEL, node->label, NULL, NULL);
	node->code=join_tac(label_tac, $4);
	node->next=NULL;
	$$=node;
}
;

case_value : INTEGER
{
	$$=mk_const(atoi($1));
}
| CHARACTER
{
	$$=mk_char_const($1);
}
;

default_clause : DEFAULT ':' case_statement_list
{
	DEFAULT_BLOCK *block=(DEFAULT_BLOCK *)malloc(sizeof(DEFAULT_BLOCK));
	block->label=mk_label(mk_lstr(next_label++));
	TAC *label_tac=mk_tac(TAC_LABEL, block->label, NULL, NULL);
	block->code=join_tac(label_tac, $3);
	$$=block;
}
;

case_statement_list : case_statement_list statement
{
	$$=join_tac($1, $2);
}
|
{
	$$=NULL;
}
;

call_statement : IDENTIFIER '(' argument_list ')'
{
	$$=do_call($1, $3);
}
;

call_expression : IDENTIFIER '(' argument_list ')'
{
	$$=do_call_ret($1, $3);
}
;

%%

void yyerror(char* msg) 
{
	fprintf(stderr, "%s: line %d\n", msg, yylineno);
	exit(0);
}
