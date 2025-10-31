/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_MINI_Y_H_INCLUDED
# define YY_YY_MINI_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    CHAR = 259,                    /* CHAR  */
    STRUCT = 260,                  /* STRUCT  */
    EQ = 261,                      /* EQ  */
    NE = 262,                      /* NE  */
    LT = 263,                      /* LT  */
    LE = 264,                      /* LE  */
    GT = 265,                      /* GT  */
    GE = 266,                      /* GE  */
    UMINUS = 267,                  /* UMINUS  */
    IF = 268,                      /* IF  */
    ELSE = 269,                    /* ELSE  */
    WHILE = 270,                   /* WHILE  */
    FOR = 271,                     /* FOR  */
    SWITCH = 272,                  /* SWITCH  */
    CASE = 273,                    /* CASE  */
    DEFAULT = 274,                 /* DEFAULT  */
    BREAK = 275,                   /* BREAK  */
    CONTINUE = 276,                /* CONTINUE  */
    FUNC = 277,                    /* FUNC  */
    INPUT = 278,                   /* INPUT  */
    OUTPUT = 279,                  /* OUTPUT  */
    RETURN = 280,                  /* RETURN  */
    INTEGER = 281,                 /* INTEGER  */
    IDENTIFIER = 282,              /* IDENTIFIER  */
    TEXT = 283,                    /* TEXT  */
    CHARACTER = 284,               /* CHARACTER  */
    DEREF = 285,                   /* DEREF  */
    ADDROF = 286                   /* ADDROF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define CHAR 259
#define STRUCT 260
#define EQ 261
#define NE 262
#define LT 263
#define LE 264
#define GT 265
#define GE 266
#define UMINUS 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define FOR 271
#define SWITCH 272
#define CASE 273
#define DEFAULT 274
#define BREAK 275
#define CONTINUE 276
#define FUNC 277
#define INPUT 278
#define OUTPUT 279
#define RETURN 280
#define INTEGER 281
#define IDENTIFIER 282
#define TEXT 283
#define CHARACTER 284
#define DEREF 285
#define ADDROF 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "mini.y"

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

#line 144 "mini.y.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MINI_Y_H_INCLUDED  */
