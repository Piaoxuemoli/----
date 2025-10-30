%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tac.h"

int yylex();
void yyerror(char* msg);

int current_decl_type = TYPE_INT;

%}

%union
{
	char character;
	char *string;
	int number;
	LOOP_INFO *loop;
	SYM *sym;
	TAC *tac;
	EXP	*exp;
}

%token INT CHAR EQ NE LT LE GT GE UMINUS IF ELSE WHILE FOR BREAK CONTINUE FUNC INPUT OUTPUT RETURN
%token <string> INTEGER IDENTIFIER TEXT
%token <character> CHARACTER

%left EQ NE LT LE GT GE
%left '+' '-'
%left '*' '/'
%right UMINUS

%type <tac> program function_declaration_list function_declaration function parameter_list variable_list statement assignment_statement return_statement if_statement while_statement for_statement break_statement continue_statement call_statement block declaration_list declaration statement_list input_statement output_statement for_init for_post
%type <exp> argument_list expression_list expression call_expression expression_opt
%type <sym> function_head
%type <number> type_specifier

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
}
;

variable_list : IDENTIFIER
{
	$$=declare_var($1, current_decl_type);
}               
| variable_list ',' IDENTIFIER
{
	$$=join_tac($1, declare_var($3, current_decl_type));
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
	$$ = TYPE_INT;
}
| CHAR
{
	current_decl_type = TYPE_CHAR;
	$$ = TYPE_CHAR;
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

output_statement : OUTPUT IDENTIFIER
{
	$$=do_output(get_var($2));
}
| OUTPUT TEXT
{
	$$=do_output(mk_text($2));
}
| OUTPUT CHARACTER
{
	$$=do_output(mk_char_const($2));
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
