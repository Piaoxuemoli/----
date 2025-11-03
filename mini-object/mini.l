%{
#include "tac.h"
#include "mini.y.h"

static int parse_char_literal(const char *text)
{
	if(text[1]=='\\')
	{
		switch(text[2])
		{
			case 'n': return '\n';
			case 't': return '\t';
			case 'r': return '\r';
			case '\\': return '\\';
			case '\'': return '\'';
			case '0': return '\0';
			default: return text[2];
		}
	}
	return text[1];
}
%}

%option yylineno

%%

"int"  {  return INT;  }

"char" {  return CHAR; }

"struct" { return STRUCT; }

"input"  {  return INPUT;  }

"output"  {  return OUTPUT;  }

"return"  {  return RETURN;  }

"if"  {  return IF;  }

"else"  {  return ELSE;  }

"while"  {  return WHILE;  }

"for"  {  return FOR; }

"switch" { return SWITCH; }

"case" { return CASE; }

"default" { return DEFAULT; }

"break" { return BREAK; }

"continue" { return CONTINUE; }

[A-Za-z]([A-Za-z]|[0-9])*  {  
	yylval.string = strdup(yytext); 
	return IDENTIFIER;
}

[0-9]*	{
	yylval.string = strdup(yytext); 
	return INTEGER;
}

\'(\\.|[^\\\'])\'  {
	yylval.character = parse_char_literal(yytext);
	return CHARACTER;
}

\"[^\"]*\"  {
	yylval.string = strdup(yytext); 
	return TEXT;
}

"=="  {  return EQ;  }

"!="  {  return NE;  }

"<="  {  return LE;  }

"<"  {  return LT;  }

">="  {  return GE;  }

">"  {  return GT;  }

[ \t\r\n]|#.*

. 	{	return *yytext; }

%%

int yywrap()
{
	return 1;
}

