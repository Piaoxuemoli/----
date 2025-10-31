/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "mini.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tac.h"

int yylex();
void yyerror(char* msg);

int current_decl_type = TYPE_INT;

extern STRUCT_TYPE *current_struct_decl;

static DIM_LIST *dim_list_prepend(DIM_LIST *tail, int length)
{
	DIM_LIST *node=(DIM_LIST *)malloc(sizeof(DIM_LIST));
	node->length=length;
	node->next=tail;
	return node;
}


#line 94 "mini.y.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "mini.y.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_CHAR = 4,                       /* CHAR  */
  YYSYMBOL_STRUCT = 5,                     /* STRUCT  */
  YYSYMBOL_EQ = 6,                         /* EQ  */
  YYSYMBOL_NE = 7,                         /* NE  */
  YYSYMBOL_LT = 8,                         /* LT  */
  YYSYMBOL_LE = 9,                         /* LE  */
  YYSYMBOL_GT = 10,                        /* GT  */
  YYSYMBOL_GE = 11,                        /* GE  */
  YYSYMBOL_UMINUS = 12,                    /* UMINUS  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_SWITCH = 17,                    /* SWITCH  */
  YYSYMBOL_CASE = 18,                      /* CASE  */
  YYSYMBOL_DEFAULT = 19,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 20,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 21,                  /* CONTINUE  */
  YYSYMBOL_FUNC = 22,                      /* FUNC  */
  YYSYMBOL_INPUT = 23,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 24,                    /* OUTPUT  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_INTEGER = 26,                   /* INTEGER  */
  YYSYMBOL_IDENTIFIER = 27,                /* IDENTIFIER  */
  YYSYMBOL_TEXT = 28,                      /* TEXT  */
  YYSYMBOL_CHARACTER = 29,                 /* CHARACTER  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_DEREF = 34,                     /* DEREF  */
  YYSYMBOL_ADDROF = 35,                    /* ADDROF  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* ','  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_44_ = 44,                       /* '='  */
  YYSYMBOL_45_ = 45,                       /* '&'  */
  YYSYMBOL_46_ = 46,                       /* '.'  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_function_declaration_list = 50, /* function_declaration_list  */
  YYSYMBOL_function_declaration = 51,      /* function_declaration  */
  YYSYMBOL_declaration = 52,               /* declaration  */
  YYSYMBOL_variable_list = 53,             /* variable_list  */
  YYSYMBOL_declarator = 54,                /* declarator  */
  YYSYMBOL_array_dimensions = 55,          /* array_dimensions  */
  YYSYMBOL_function = 56,                  /* function  */
  YYSYMBOL_function_head = 57,             /* function_head  */
  YYSYMBOL_type_specifier = 58,            /* type_specifier  */
  YYSYMBOL_struct_definition = 59,         /* struct_definition  */
  YYSYMBOL_struct_field_list = 60,         /* struct_field_list  */
  YYSYMBOL_struct_field_decl = 61,         /* struct_field_decl  */
  YYSYMBOL_struct_declaration_tail = 62,   /* struct_declaration_tail  */
  YYSYMBOL_parameter_list = 63,            /* parameter_list  */
  YYSYMBOL_statement = 64,                 /* statement  */
  YYSYMBOL_block = 65,                     /* block  */
  YYSYMBOL_declaration_list = 66,          /* declaration_list  */
  YYSYMBOL_statement_list = 67,            /* statement_list  */
  YYSYMBOL_assignment_statement = 68,      /* assignment_statement  */
  YYSYMBOL_expression = 69,                /* expression  */
  YYSYMBOL_argument_list = 70,             /* argument_list  */
  YYSYMBOL_expression_list = 71,           /* expression_list  */
  YYSYMBOL_input_statement = 72,           /* input_statement  */
  YYSYMBOL_output_statement = 73,          /* output_statement  */
  YYSYMBOL_return_statement = 74,          /* return_statement  */
  YYSYMBOL_if_statement = 75,              /* if_statement  */
  YYSYMBOL_while_statement = 76,           /* while_statement  */
  YYSYMBOL_77_1 = 77,                      /* @1  */
  YYSYMBOL_for_statement = 78,             /* for_statement  */
  YYSYMBOL_79_2 = 79,                      /* @2  */
  YYSYMBOL_for_init = 80,                  /* for_init  */
  YYSYMBOL_for_post = 81,                  /* for_post  */
  YYSYMBOL_expression_opt = 82,            /* expression_opt  */
  YYSYMBOL_break_statement = 83,           /* break_statement  */
  YYSYMBOL_continue_statement = 84,        /* continue_statement  */
  YYSYMBOL_array_reference = 85,           /* array_reference  */
  YYSYMBOL_pointer_lvalue = 86,            /* pointer_lvalue  */
  YYSYMBOL_struct_reference = 87,          /* struct_reference  */
  YYSYMBOL_switch_header = 88,             /* switch_header  */
  YYSYMBOL_switch_statement = 89,          /* switch_statement  */
  YYSYMBOL_switch_sections = 90,           /* switch_sections  */
  YYSYMBOL_case_clause = 91,               /* case_clause  */
  YYSYMBOL_case_value = 92,                /* case_value  */
  YYSYMBOL_default_clause = 93,            /* default_clause  */
  YYSYMBOL_case_statement_list = 94,       /* case_statement_list  */
  YYSYMBOL_call_statement = 95,            /* call_statement  */
  YYSYMBOL_call_expression = 96            /* call_expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   434

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,     2,
      40,    41,    32,    30,    37,    31,    46,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    36,
       2,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    34,    35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    71,    72,    78,    79,    82,    87,    94,
      95,   103,   107,   111,   125,   129,   135,   141,   148,   156,
     162,   168,   181,   190,   194,   200,   204,   208,   212,   216,
     229,   244,   249,   254,   258,   263,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   287,
     294,   297,   303,   304,   310,   314,   320,   324,   328,   332,
     336,   340,   344,   348,   352,   356,   360,   364,   368,   372,
     376,   380,   384,   388,   392,   396,   400,   413,   417,   425,
     428,   431,   432,   439,   445,   451,   457,   465,   469,   476,
     475,   494,   493,   511,   516,   521,   526,   531,   536,   541,
     547,   553,   557,   561,   567,   571,   584,   590,   594,   598,
     605,   615,   627,   634,   649,   666,   678,   682,   688,   698,
     703,   708,   714
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "CHAR",
  "STRUCT", "EQ", "NE", "LT", "LE", "GT", "GE", "UMINUS", "IF", "ELSE",
  "WHILE", "FOR", "SWITCH", "CASE", "DEFAULT", "BREAK", "CONTINUE", "FUNC",
  "INPUT", "OUTPUT", "RETURN", "INTEGER", "IDENTIFIER", "TEXT",
  "CHARACTER", "'+'", "'-'", "'*'", "'/'", "DEREF", "ADDROF", "';'", "','",
  "'['", "']'", "'('", "')'", "'{'", "'}'", "'='", "'&'", "'.'", "':'",
  "$accept", "program", "function_declaration_list",
  "function_declaration", "declaration", "variable_list", "declarator",
  "array_dimensions", "function", "function_head", "type_specifier",
  "struct_definition", "struct_field_list", "struct_field_decl",
  "struct_declaration_tail", "parameter_list", "statement", "block",
  "declaration_list", "statement_list", "assignment_statement",
  "expression", "argument_list", "expression_list", "input_statement",
  "output_statement", "return_statement", "if_statement",
  "while_statement", "@1", "for_statement", "@2", "for_init", "for_post",
  "expression_opt", "break_statement", "continue_statement",
  "array_reference", "pointer_lvalue", "struct_reference", "switch_header",
  "switch_statement", "switch_sections", "case_clause", "case_value",
  "default_clause", "case_statement_list", "call_statement",
  "call_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-119)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      71,   -92,   -92,   -92,   -14,   -92,     8,    11,   -92,   -92,
     -92,     0,    50,    50,    39,   -92,   -92,    31,    67,    84,
      89,   -92,    83,    80,    75,   -92,    66,   109,   -92,   -92,
     -92,    50,   -92,   113,   119,   120,     2,   -92,   121,   108,
     110,   -92,    76,    79,   125,   -92,   -92,   -92,   -92,   -92,
      67,   -92,   126,   -92,   129,   107,   247,   -92,   -92,   -92,
     -92,   131,   -92,   116,   117,   130,   132,   -92,   -92,   146,
      28,   137,   -18,   147,   -92,   -92,   -92,   215,   139,   140,
     142,   143,   -92,   -92,   -92,   144,   145,   -19,   148,    24,
     -92,   160,   -92,   137,   137,    69,   137,   -92,   -92,   -92,
      25,   -92,   -92,   137,   137,   137,   157,   401,   -19,    24,
     -92,   401,   137,    68,   137,   171,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   137,   172,   137,   137,   173,
     -92,   287,   299,    98,   -92,   165,   305,    68,   -92,   -92,
     341,    64,   -19,    24,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   347,   401,   163,   168,   401,   -92,
     357,   -92,   401,   391,   -92,   108,   -92,    92,   -92,   166,
     -92,    16,    16,    16,    16,    16,    16,    97,    97,   -92,
     -92,   -92,   -92,   137,   -92,   -92,   192,   260,   401,   174,
     167,   -92,   401,   108,   -92,    69,   -92,   -92,   -92,   183,
      18,   -92,     5,   161,   -92,   -92,   -92,   260,   -92,   -92,
     164,   -92,   -92,   -92,   170,   202,   -92
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    17,    19,    20,     0,    18,     0,     0,     3,     6,
       5,     0,     0,    32,    21,     1,     4,    35,    11,     0,
       0,     9,    31,     0,     0,    33,     0,     0,    12,    13,
       7,     0,     8,     0,     0,     0,     0,    24,     0,     0,
       0,    10,     0,     0,     0,    22,    23,    34,    50,    16,
      15,    25,     0,    27,     0,     0,     0,    14,    26,    28,
      29,     0,    48,     0,     0,     0,     0,    99,   100,     0,
       0,     0,     0,     0,    51,    52,    47,     0,     0,     0,
       0,     0,    41,    42,    43,     0,     0,   105,     0,   106,
      44,     0,    30,     0,     0,    94,     0,    83,    78,    72,
      74,    85,    73,     0,     0,     0,     0,    84,    76,    77,
      75,    86,     0,     0,     0,     0,   104,    49,    53,    36,
      37,    38,    40,    45,    46,     0,     0,     0,     0,     0,
      39,     0,     0,     0,    93,     0,     0,     0,    60,    71,
       0,    70,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,    80,    54,   107,
       0,   108,    55,     0,   109,     0,    89,     0,   110,     0,
      67,    61,    62,    63,    64,    65,    66,    56,    57,    58,
      59,   101,   121,     0,   103,   102,    87,     0,    97,     0,
       0,   122,    82,     0,    90,    96,   112,    88,    95,     0,
       0,    91,     0,     0,   111,   113,   114,     0,   116,   117,
       0,   120,    92,   120,     0,     0,   119
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,   -92,   207,   177,   224,   210,   -25,   -92,   -92,
     -92,   -92,   -92,   213,   -92,   -92,   -53,   -38,   -92,   -92,
     -91,   -61,   106,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -56,   -92,   -54,
     -92,   -92,   -92,   -92,   -92,   -92,    33,   -92,   -92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,    20,    21,    28,    10,    11,
      12,    13,    36,    37,    23,    26,   216,    76,    56,    77,
      78,   155,   156,   157,    79,    80,    81,    82,    83,   187,
      84,   207,   135,   199,   189,    85,    86,   108,    88,   109,
     190,    90,   200,   205,   210,   206,   214,    91,   110
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      87,    49,    89,    75,   134,    33,    34,    35,    15,   107,
     111,    -2,     1,    14,     2,     3,     4,    52,    54,   125,
     112,    87,   113,    89,   118,    57,   114,   126,   115,    98,
      61,   208,   131,   132,   209,   136,   202,   203,     5,    87,
      17,    89,   138,   139,   140,    45,   150,   151,   152,   153,
     142,   154,   143,   158,    99,   100,   101,   102,    25,   103,
     104,   204,   128,   112,   160,   137,   162,   163,   105,    98,
     129,   115,     1,   106,     2,     3,     4,    18,    33,    34,
      35,    24,    19,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    98,    99,   100,   133,   102,     5,   103,
     104,    73,   112,    38,   198,    27,   188,    39,   105,   -79,
     115,    29,    51,   106,    27,    53,    32,    27,    99,   100,
      31,   102,   192,   103,   104,    30,    31,   186,   -98,   152,
     153,    87,   105,    89,   194,    40,   112,   106,    98,    87,
      42,    89,   114,    60,   115,    27,    43,    44,    47,    50,
      48,    87,    55,    89,   212,   197,    93,    94,    87,    87,
      89,    89,    58,    99,   100,    59,   102,    92,   103,   104,
      95,    62,    96,    97,   116,   119,   120,   105,   121,   122,
     123,   124,   106,    63,   141,    64,    65,    66,  -118,  -118,
      67,    68,   127,    69,    70,    71,   130,    72,   159,   161,
     164,   167,    73,    62,   182,   183,   193,   191,   211,   196,
     195,   213,    48,  -118,    16,    63,    62,    64,    65,    66,
    -115,  -115,    67,    68,   201,    69,    70,    71,    63,    72,
      64,    65,    66,    74,    73,    67,    68,    22,    69,    70,
      71,    41,    72,   169,    48,  -115,   215,    73,    62,    46,
       2,     3,     4,     0,     0,     0,     0,    48,   117,     0,
      63,    62,    64,    65,    66,     0,     0,    67,    68,     0,
      69,    70,    71,    63,    72,    64,    65,    66,     0,    73,
      67,    68,     0,    69,    70,    71,     0,    72,     0,    48,
       0,     0,    73,   144,   145,   146,   147,   148,   149,     0,
       0,     0,    48,     0,     0,   144,   145,   146,   147,   148,
     149,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,     0,     0,     0,     0,     0,     0,   165,   150,
     151,   152,   153,     0,     0,   150,   151,   152,   153,     0,
     166,     0,     0,     0,     0,     0,   168,   144,   145,   146,
     147,   148,   149,   144,   145,   146,   147,   148,   149,     0,
       0,     0,     0,   144,   145,   146,   147,   148,   149,     0,
       0,   150,   151,   152,   153,     0,     0,   150,   151,   152,
     153,     0,   170,     0,     0,     0,   181,   150,   151,   152,
     153,     0,     0,     0,     0,     0,   184,   144,   145,   146,
     147,   148,   149,     0,     0,     0,     0,   144,   145,   146,
     147,   148,   149,     0,     0,     0,     0,     0,     0,     0,
       0,   150,   151,   152,   153,     0,     0,     0,     0,     0,
     185,   150,   151,   152,   153
};

static const yytype_int16 yycheck[] =
{
      56,    39,    56,    56,    95,     3,     4,     5,     0,    70,
      71,     0,     1,    27,     3,     4,     5,    42,    43,    38,
      38,    77,    40,    77,    77,    50,    44,    46,    46,     1,
      55,    26,    93,    94,    29,    96,    18,    19,    27,    95,
      40,    95,   103,   104,   105,    43,    30,    31,    32,    33,
     106,   112,   106,   114,    26,    27,    28,    29,    27,    31,
      32,    43,    38,    38,   125,    40,   127,   128,    40,     1,
      46,    46,     1,    45,     3,     4,     5,    27,     3,     4,
       5,    42,    32,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,     1,    26,    27,    27,    29,    27,    31,
      32,    32,    38,    37,   195,    38,   167,    41,    40,    41,
      46,    27,    36,    45,    38,    36,    36,    38,    26,    27,
      37,    29,   183,    31,    32,    36,    37,   165,    36,    32,
      33,   187,    40,   187,   187,    26,    38,    45,     1,   195,
      27,   195,    44,    36,    46,    38,    27,    27,    27,    39,
      42,   207,    27,   207,   207,   193,    40,    40,   214,   215,
     214,   215,    36,    26,    27,    36,    29,    36,    31,    32,
      40,     1,    40,    27,    27,    36,    36,    40,    36,    36,
      36,    36,    45,    13,    27,    15,    16,    17,    18,    19,
      20,    21,    44,    23,    24,    25,    36,    27,    27,    27,
      27,    36,    32,     1,    41,    37,    14,    41,    47,    42,
      36,    47,    42,    43,     7,    13,     1,    15,    16,    17,
      18,    19,    20,    21,    41,    23,    24,    25,    13,    27,
      15,    16,    17,    56,    32,    20,    21,    13,    23,    24,
      25,    31,    27,   137,    42,    43,   213,    32,     1,    36,
       3,     4,     5,    -1,    -1,    -1,    -1,    42,    43,    -1,
      13,     1,    15,    16,    17,    -1,    -1,    20,    21,    -1,
      23,    24,    25,    13,    27,    15,    16,    17,    -1,    32,
      20,    21,    -1,    23,    24,    25,    -1,    27,    -1,    42,
      -1,    -1,    32,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    42,    -1,    -1,     6,     7,     8,     9,    10,
      11,     6,     7,     8,     9,    10,    11,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    30,
      31,    32,    33,    -1,    -1,    30,    31,    32,    33,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    41,     6,     7,     8,
       9,    10,    11,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    30,    31,    32,    33,    -1,    -1,    30,    31,    32,
      33,    -1,    41,    -1,    -1,    -1,    39,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    39,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      39,    30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,    27,    49,    50,    51,    52,
      56,    57,    58,    59,    27,     0,    51,    40,    27,    32,
      53,    54,    53,    62,    42,    27,    63,    38,    55,    27,
      36,    37,    36,     3,     4,     5,    60,    61,    37,    41,
      26,    54,    27,    27,    27,    43,    61,    27,    42,    65,
      39,    36,    55,    36,    55,    27,    66,    55,    36,    36,
      36,    55,     1,    13,    15,    16,    17,    20,    21,    23,
      24,    25,    27,    32,    52,    64,    65,    67,    68,    72,
      73,    74,    75,    76,    78,    83,    84,    85,    86,    87,
      89,    95,    36,    40,    40,    40,    40,    27,     1,    26,
      27,    28,    29,    31,    32,    40,    45,    69,    85,    87,
      96,    69,    38,    40,    44,    46,    27,    43,    64,    36,
      36,    36,    36,    36,    36,    38,    46,    44,    38,    46,
      36,    69,    69,    27,    68,    80,    69,    40,    69,    69,
      69,    27,    85,    87,     6,     7,     8,     9,    10,    11,
      30,    31,    32,    33,    69,    69,    70,    71,    69,    27,
      69,    27,    69,    69,    27,    41,    41,    36,    41,    70,
      41,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    39,    41,    37,    39,    39,    65,    77,    69,    82,
      88,    41,    69,    14,    64,    36,    42,    65,    68,    81,
      90,    41,    18,    19,    43,    91,    93,    79,    26,    29,
      92,    47,    64,    47,    94,    94,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    54,    55,    55,    56,    56,    57,    58,
      58,    58,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    62,    62,    63,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    65,
      66,    66,    67,    67,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    71,    71,    72,    73,    73,    74,    75,    75,    77,
      76,    79,    78,    80,    80,    81,    81,    82,    82,    83,
      84,    85,    85,    85,    86,    86,    86,    87,    87,    87,
      88,    89,    90,    90,    90,    91,    92,    92,    93,    94,
      94,    95,    96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     3,     1,
       3,     1,     2,     2,     4,     3,     5,     1,     1,     1,
       1,     2,     5,     2,     1,     3,     4,     3,     4,     4,
       5,     1,     0,     1,     3,     0,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     2,     2,     1,     1,     4,
       0,     2,     1,     2,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     3,     2,     2,     2,     2,     5,     7,     0,
       6,     0,    10,     1,     0,     1,     0,     1,     0,     1,
       1,     4,     4,     4,     2,     1,     1,     3,     3,     3,
       0,     8,     0,     2,     2,     4,     1,     1,     3,     2,
       0,     4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: function_declaration_list  */
#line 65 "mini.y"
{
	tac_last=(yyvsp[0].tac);
	tac_complete();
}
#line 1380 "mini.y.c"
    break;

  case 4: /* function_declaration_list: function_declaration_list function_declaration  */
#line 73 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1388 "mini.y.c"
    break;

  case 7: /* declaration: type_specifier variable_list ';'  */
#line 83 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
	current_struct_decl=NULL;
}
#line 1397 "mini.y.c"
    break;

  case 8: /* declaration: struct_definition struct_declaration_tail ';'  */
#line 88 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
	current_struct_decl=NULL;
}
#line 1406 "mini.y.c"
    break;

  case 10: /* variable_list: variable_list ',' declarator  */
#line 96 "mini.y"
{
	if((yyvsp[-2].tac)==NULL) (yyval.tac)=(yyvsp[0].tac);
	else if((yyvsp[0].tac)==NULL) (yyval.tac)=(yyvsp[-2].tac);
	else (yyval.tac)=join_tac((yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 1416 "mini.y.c"
    break;

  case 11: /* declarator: IDENTIFIER  */
#line 104 "mini.y"
{
	(yyval.tac)=declare_var((yyvsp[0].string), current_decl_type);
}
#line 1424 "mini.y.c"
    break;

  case 12: /* declarator: IDENTIFIER array_dimensions  */
#line 108 "mini.y"
{
	(yyval.tac)=declare_array((yyvsp[-1].string), current_decl_type, (yyvsp[0].dimensions));
}
#line 1432 "mini.y.c"
    break;

  case 13: /* declarator: '*' IDENTIFIER  */
#line 112 "mini.y"
{
	if(current_decl_type==TYPE_STRUCT)
	{
		error("pointers to struct not supported");
		(yyval.tac)=NULL;
	}
	else
	{
		(yyval.tac)=declare_var((yyvsp[0].string), pointer_type_from_base(current_decl_type));
	}
}
#line 1448 "mini.y.c"
    break;

  case 14: /* array_dimensions: '[' INTEGER ']' array_dimensions  */
#line 126 "mini.y"
{
	(yyval.dimensions)=dim_list_prepend((yyvsp[0].dimensions), atoi((yyvsp[-2].string)));
}
#line 1456 "mini.y.c"
    break;

  case 15: /* array_dimensions: '[' INTEGER ']'  */
#line 130 "mini.y"
{
	(yyval.dimensions)=dim_list_prepend(NULL, atoi((yyvsp[-1].string)));
}
#line 1464 "mini.y.c"
    break;

  case 16: /* function: function_head '(' parameter_list ')' block  */
#line 136 "mini.y"
{
	(yyval.tac)=do_func((yyvsp[-4].sym), (yyvsp[-2].tac), (yyvsp[0].tac));
	scope=0; /* Leave local scope. */
	sym_tab_local=NULL; /* Clear local symbol table. */
}
#line 1474 "mini.y.c"
    break;

  case 17: /* function: error  */
#line 142 "mini.y"
{
	error("Bad function syntax");
	(yyval.tac)=NULL;
}
#line 1483 "mini.y.c"
    break;

  case 18: /* function_head: IDENTIFIER  */
#line 149 "mini.y"
{
	(yyval.sym)=declare_func((yyvsp[0].string));
	scope=1; /* Enter local scope. */
	sym_tab_local=NULL; /* Init local symbol table. */
}
#line 1493 "mini.y.c"
    break;

  case 19: /* type_specifier: INT  */
#line 157 "mini.y"
{
	current_decl_type = TYPE_INT;
	current_struct_decl = NULL;
	(yyval.number) = TYPE_INT;
}
#line 1503 "mini.y.c"
    break;

  case 20: /* type_specifier: CHAR  */
#line 163 "mini.y"
{
	current_decl_type = TYPE_CHAR;
	current_struct_decl = NULL;
	(yyval.number) = TYPE_CHAR;
}
#line 1513 "mini.y.c"
    break;

  case 21: /* type_specifier: STRUCT IDENTIFIER  */
#line 169 "mini.y"
{
	STRUCT_TYPE *stype=struct_lookup((yyvsp[0].string));
	if(stype==NULL)
	{
		error("unknown struct type");
	}
	current_struct_decl = stype;
	current_decl_type = TYPE_STRUCT;
	(yyval.number) = TYPE_STRUCT;
}
#line 1528 "mini.y.c"
    break;

  case 22: /* struct_definition: STRUCT IDENTIFIER '{' struct_field_list '}'  */
#line 182 "mini.y"
{
	STRUCT_TYPE *stype=struct_define((yyvsp[-3].string), (yyvsp[-1].struct_field));
	current_struct_decl = stype;
	current_decl_type = TYPE_STRUCT;
	(yyval.struct_type)=stype;
}
#line 1539 "mini.y.c"
    break;

  case 23: /* struct_field_list: struct_field_list struct_field_decl  */
#line 191 "mini.y"
{
	(yyval.struct_field)=struct_field_list_append((yyvsp[-1].struct_field), (yyvsp[0].struct_field));
}
#line 1547 "mini.y.c"
    break;

  case 24: /* struct_field_list: struct_field_decl  */
#line 195 "mini.y"
{
	(yyval.struct_field)=(yyvsp[0].struct_field);
}
#line 1555 "mini.y.c"
    break;

  case 25: /* struct_field_decl: INT IDENTIFIER ';'  */
#line 201 "mini.y"
{
	(yyval.struct_field)=struct_field_create((yyvsp[-1].string), TYPE_INT, NULL, NULL);
}
#line 1563 "mini.y.c"
    break;

  case 26: /* struct_field_decl: INT IDENTIFIER array_dimensions ';'  */
#line 205 "mini.y"
{
	(yyval.struct_field)=struct_field_create((yyvsp[-2].string), TYPE_INT, (yyvsp[-1].dimensions), NULL);
}
#line 1571 "mini.y.c"
    break;

  case 27: /* struct_field_decl: CHAR IDENTIFIER ';'  */
#line 209 "mini.y"
{
	(yyval.struct_field)=struct_field_create((yyvsp[-1].string), TYPE_CHAR, NULL, NULL);
}
#line 1579 "mini.y.c"
    break;

  case 28: /* struct_field_decl: CHAR IDENTIFIER array_dimensions ';'  */
#line 213 "mini.y"
{
	(yyval.struct_field)=struct_field_create((yyvsp[-2].string), TYPE_CHAR, (yyvsp[-1].dimensions), NULL);
}
#line 1587 "mini.y.c"
    break;

  case 29: /* struct_field_decl: STRUCT IDENTIFIER IDENTIFIER ';'  */
#line 217 "mini.y"
{
	STRUCT_TYPE *stype=struct_lookup((yyvsp[-2].string));
	if(stype==NULL)
	{
		error("unknown struct type");
		(yyval.struct_field)=NULL;
	}
	else
	{
		(yyval.struct_field)=struct_field_create((yyvsp[-1].string), TYPE_STRUCT, NULL, stype);
	}
}
#line 1604 "mini.y.c"
    break;

  case 30: /* struct_field_decl: STRUCT IDENTIFIER IDENTIFIER array_dimensions ';'  */
#line 230 "mini.y"
{
	STRUCT_TYPE *stype=struct_lookup((yyvsp[-3].string));
	if(stype==NULL)
	{
		error("unknown struct type");
		(yyval.struct_field)=NULL;
	}
	else
	{
		(yyval.struct_field)=struct_field_create((yyvsp[-2].string), TYPE_STRUCT, (yyvsp[-1].dimensions), stype);
	}
}
#line 1621 "mini.y.c"
    break;

  case 31: /* struct_declaration_tail: variable_list  */
#line 245 "mini.y"
{
	(yyval.tac)=(yyvsp[0].tac);
}
#line 1629 "mini.y.c"
    break;

  case 32: /* struct_declaration_tail: %empty  */
#line 249 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1637 "mini.y.c"
    break;

  case 33: /* parameter_list: IDENTIFIER  */
#line 255 "mini.y"
{
	(yyval.tac)=declare_para((yyvsp[0].string), TYPE_INT);
}
#line 1645 "mini.y.c"
    break;

  case 34: /* parameter_list: parameter_list ',' IDENTIFIER  */
#line 259 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), declare_para((yyvsp[0].string), TYPE_INT));
}
#line 1653 "mini.y.c"
    break;

  case 35: /* parameter_list: %empty  */
#line 263 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1661 "mini.y.c"
    break;

  case 48: /* statement: error  */
#line 281 "mini.y"
{
	error("Bad statement syntax");
	(yyval.tac)=NULL;
}
#line 1670 "mini.y.c"
    break;

  case 49: /* block: '{' declaration_list statement_list '}'  */
#line 288 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), (yyvsp[-1].tac));
}
#line 1678 "mini.y.c"
    break;

  case 50: /* declaration_list: %empty  */
#line 294 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1686 "mini.y.c"
    break;

  case 51: /* declaration_list: declaration_list declaration  */
#line 298 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1694 "mini.y.c"
    break;

  case 53: /* statement_list: statement_list statement  */
#line 305 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1702 "mini.y.c"
    break;

  case 54: /* assignment_statement: IDENTIFIER '=' expression  */
#line 311 "mini.y"
{
	(yyval.tac)=do_assign(get_var((yyvsp[-2].string)), (yyvsp[0].exp));
}
#line 1710 "mini.y.c"
    break;

  case 55: /* assignment_statement: pointer_lvalue '=' expression  */
#line 315 "mini.y"
{
	(yyval.tac)=do_store((yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1718 "mini.y.c"
    break;

  case 56: /* expression: expression '+' expression  */
#line 321 "mini.y"
{
	(yyval.exp)=do_bin(TAC_ADD, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1726 "mini.y.c"
    break;

  case 57: /* expression: expression '-' expression  */
#line 325 "mini.y"
{
	(yyval.exp)=do_bin(TAC_SUB, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1734 "mini.y.c"
    break;

  case 58: /* expression: expression '*' expression  */
#line 329 "mini.y"
{
	(yyval.exp)=do_bin(TAC_MUL, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1742 "mini.y.c"
    break;

  case 59: /* expression: expression '/' expression  */
#line 333 "mini.y"
{
	(yyval.exp)=do_bin(TAC_DIV, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1750 "mini.y.c"
    break;

  case 60: /* expression: '-' expression  */
#line 337 "mini.y"
{
	(yyval.exp)=do_un(TAC_NEG, (yyvsp[0].exp));
}
#line 1758 "mini.y.c"
    break;

  case 61: /* expression: expression EQ expression  */
#line 341 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_EQ, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1766 "mini.y.c"
    break;

  case 62: /* expression: expression NE expression  */
#line 345 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_NE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1774 "mini.y.c"
    break;

  case 63: /* expression: expression LT expression  */
#line 349 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_LT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1782 "mini.y.c"
    break;

  case 64: /* expression: expression LE expression  */
#line 353 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_LE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1790 "mini.y.c"
    break;

  case 65: /* expression: expression GT expression  */
#line 357 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_GT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1798 "mini.y.c"
    break;

  case 66: /* expression: expression GE expression  */
#line 361 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_GE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1806 "mini.y.c"
    break;

  case 67: /* expression: '(' expression ')'  */
#line 365 "mini.y"
{
	(yyval.exp)=(yyvsp[-1].exp);
}
#line 1814 "mini.y.c"
    break;

  case 68: /* expression: '&' array_reference  */
#line 369 "mini.y"
{
	(yyval.exp)=(yyvsp[0].exp);
}
#line 1822 "mini.y.c"
    break;

  case 69: /* expression: '&' struct_reference  */
#line 373 "mini.y"
{
	(yyval.exp)=(yyvsp[0].exp);
}
#line 1830 "mini.y.c"
    break;

  case 70: /* expression: '&' IDENTIFIER  */
#line 377 "mini.y"
{
	(yyval.exp)=do_addr(get_var((yyvsp[0].string)));
}
#line 1838 "mini.y.c"
    break;

  case 71: /* expression: '*' expression  */
#line 381 "mini.y"
{
	(yyval.exp)=do_deref((yyvsp[0].exp));
}
#line 1846 "mini.y.c"
    break;

  case 72: /* expression: INTEGER  */
#line 385 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, mk_const(atoi((yyvsp[0].string))), NULL);
}
#line 1854 "mini.y.c"
    break;

  case 73: /* expression: CHARACTER  */
#line 389 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, mk_char_const((yyvsp[0].character)), NULL);
}
#line 1862 "mini.y.c"
    break;

  case 74: /* expression: IDENTIFIER  */
#line 393 "mini.y"
{
	(yyval.exp)=mk_var_exp(get_var((yyvsp[0].string)));
}
#line 1870 "mini.y.c"
    break;

  case 75: /* expression: call_expression  */
#line 397 "mini.y"
{
	(yyval.exp)=(yyvsp[0].exp);
}
#line 1878 "mini.y.c"
    break;

  case 76: /* expression: array_reference  */
#line 401 "mini.y"
{
	if((yyvsp[0].exp)->etc!=NULL)
	{
		error("struct element requires field selection");
	free((yyvsp[0].exp));
	(yyval.exp)=mk_exp(NULL, NULL, NULL);
	}
	else
	{
		(yyval.exp)=do_deref((yyvsp[0].exp));
	}
}
#line 1895 "mini.y.c"
    break;

  case 77: /* expression: struct_reference  */
#line 414 "mini.y"
{
	(yyval.exp)=do_deref((yyvsp[0].exp));
}
#line 1903 "mini.y.c"
    break;

  case 78: /* expression: error  */
#line 418 "mini.y"
{
	error("Bad expression syntax");
	(yyval.exp)=mk_exp(NULL, NULL, NULL);
}
#line 1912 "mini.y.c"
    break;

  case 79: /* argument_list: %empty  */
#line 425 "mini.y"
{
	(yyval.exp)=NULL;
}
#line 1920 "mini.y.c"
    break;

  case 82: /* expression_list: expression_list ',' expression  */
#line 433 "mini.y"
{
	(yyvsp[0].exp)->next=(yyvsp[-2].exp);
	(yyval.exp)=(yyvsp[0].exp);
}
#line 1929 "mini.y.c"
    break;

  case 83: /* input_statement: INPUT IDENTIFIER  */
#line 440 "mini.y"
{
	(yyval.tac)=do_input(get_var((yyvsp[0].string)));
}
#line 1937 "mini.y.c"
    break;

  case 84: /* output_statement: OUTPUT expression  */
#line 446 "mini.y"
{
	TAC *out=do_output((yyvsp[0].exp)->ret);
	out->prev=(yyvsp[0].exp)->tac;
	(yyval.tac)=out;
}
#line 1947 "mini.y.c"
    break;

  case 85: /* output_statement: OUTPUT TEXT  */
#line 452 "mini.y"
{
	(yyval.tac)=do_output(mk_text((yyvsp[0].string)));
}
#line 1955 "mini.y.c"
    break;

  case 86: /* return_statement: RETURN expression  */
#line 458 "mini.y"
{
	TAC *t=mk_tac(TAC_RETURN, (yyvsp[0].exp)->ret, NULL, NULL);
	t->prev=(yyvsp[0].exp)->tac;
	(yyval.tac)=t;
}
#line 1965 "mini.y.c"
    break;

  case 87: /* if_statement: IF '(' expression ')' block  */
#line 466 "mini.y"
{
	(yyval.tac)=do_if((yyvsp[-2].exp), (yyvsp[0].tac));
}
#line 1973 "mini.y.c"
    break;

  case 88: /* if_statement: IF '(' expression ')' block ELSE block  */
#line 470 "mini.y"
{
	(yyval.tac)=do_test((yyvsp[-4].exp), (yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 1981 "mini.y.c"
    break;

  case 89: /* @1: %empty  */
#line 476 "mini.y"
{
	LOOP_INFO *info=(LOOP_INFO *)malloc(sizeof(LOOP_INFO));
	info->start_label=mk_label(mk_lstr(next_label++));
	info->continue_label=info->start_label;
	info->break_label=mk_label(mk_lstr(next_label++));
	loop_push(info->continue_label, info->break_label);
	(yyval.loop)=info;
}
#line 1994 "mini.y.c"
    break;

  case 90: /* while_statement: WHILE '(' expression ')' @1 statement  */
#line 485 "mini.y"
{
	LOOP_INFO *info=(yyvsp[-1].loop);
	loop_pop();
	(yyval.tac)=do_while((yyvsp[-3].exp), (yyvsp[0].tac), info);
	free(info);
}
#line 2005 "mini.y.c"
    break;

  case 91: /* @2: %empty  */
#line 494 "mini.y"
{
	LOOP_INFO *info=(LOOP_INFO *)malloc(sizeof(LOOP_INFO));
	info->start_label=mk_label(mk_lstr(next_label++));
	info->continue_label=mk_label(mk_lstr(next_label++));
	info->break_label=mk_label(mk_lstr(next_label++));
	loop_push(info->continue_label, info->break_label);
	(yyval.loop)=info;
}
#line 2018 "mini.y.c"
    break;

  case 92: /* for_statement: FOR '(' for_init ';' expression_opt ';' for_post ')' @2 statement  */
#line 503 "mini.y"
{
	LOOP_INFO *info=(yyvsp[-1].loop);
	loop_pop();
	(yyval.tac)=do_for((yyvsp[-7].tac), (yyvsp[-5].exp), (yyvsp[-3].tac), (yyvsp[0].tac), info);
	free(info);
}
#line 2029 "mini.y.c"
    break;

  case 93: /* for_init: assignment_statement  */
#line 512 "mini.y"
{
	(yyval.tac)=(yyvsp[0].tac);
}
#line 2037 "mini.y.c"
    break;

  case 94: /* for_init: %empty  */
#line 516 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 2045 "mini.y.c"
    break;

  case 95: /* for_post: assignment_statement  */
#line 522 "mini.y"
{
	(yyval.tac)=(yyvsp[0].tac);
}
#line 2053 "mini.y.c"
    break;

  case 96: /* for_post: %empty  */
#line 526 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 2061 "mini.y.c"
    break;

  case 97: /* expression_opt: expression  */
#line 532 "mini.y"
{
	(yyval.exp)=(yyvsp[0].exp);
}
#line 2069 "mini.y.c"
    break;

  case 98: /* expression_opt: %empty  */
#line 536 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, mk_const(1), NULL);
}
#line 2077 "mini.y.c"
    break;

  case 99: /* break_statement: BREAK  */
#line 542 "mini.y"
{
	(yyval.tac)=do_break_stmt();
}
#line 2085 "mini.y.c"
    break;

  case 100: /* continue_statement: CONTINUE  */
#line 548 "mini.y"
{
	(yyval.tac)=do_continue_stmt();
}
#line 2093 "mini.y.c"
    break;

  case 101: /* array_reference: IDENTIFIER '[' expression ']'  */
#line 554 "mini.y"
{
	(yyval.exp)=do_array_element(get_var((yyvsp[-3].string)), (yyvsp[-1].exp));
}
#line 2101 "mini.y.c"
    break;

  case 102: /* array_reference: struct_reference '[' expression ']'  */
#line 558 "mini.y"
{
	(yyval.exp)=do_array_element_from_exp((yyvsp[-3].exp), (yyvsp[-1].exp));
}
#line 2109 "mini.y.c"
    break;

  case 103: /* array_reference: array_reference '[' expression ']'  */
#line 562 "mini.y"
{
	(yyval.exp)=do_array_element_from_exp((yyvsp[-3].exp), (yyvsp[-1].exp));
}
#line 2117 "mini.y.c"
    break;

  case 104: /* pointer_lvalue: '*' IDENTIFIER  */
#line 568 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, get_var((yyvsp[0].string)), NULL);
}
#line 2125 "mini.y.c"
    break;

  case 105: /* pointer_lvalue: array_reference  */
#line 572 "mini.y"
{
	if((yyvsp[0].exp)->etc!=NULL)
	{
		error("struct element requires field selection");
	free((yyvsp[0].exp));
	(yyval.exp)=NULL;
	}
	else
	{
		(yyval.exp)=(yyvsp[0].exp);
	}
}
#line 2142 "mini.y.c"
    break;

  case 106: /* pointer_lvalue: struct_reference  */
#line 585 "mini.y"
{
	(yyval.exp)=(yyvsp[0].exp);
}
#line 2150 "mini.y.c"
    break;

  case 107: /* struct_reference: IDENTIFIER '.' IDENTIFIER  */
#line 591 "mini.y"
{
	(yyval.exp)=do_struct_field(get_var((yyvsp[-2].string)), (yyvsp[0].string));
}
#line 2158 "mini.y.c"
    break;

  case 108: /* struct_reference: array_reference '.' IDENTIFIER  */
#line 595 "mini.y"
{
	(yyval.exp)=do_struct_field_from_exp((yyvsp[-2].exp), (yyvsp[0].string));
}
#line 2166 "mini.y.c"
    break;

  case 109: /* struct_reference: struct_reference '.' IDENTIFIER  */
#line 599 "mini.y"
{
	(yyval.exp)=do_struct_field_from_exp((yyvsp[-2].exp), (yyvsp[0].string));
}
#line 2174 "mini.y.c"
    break;

  case 110: /* switch_header: %empty  */
#line 605 "mini.y"
{
	LOOP_INFO *info=(LOOP_INFO *)malloc(sizeof(LOOP_INFO));
	info->start_label=NULL;
	info->continue_label=NULL;
	info->break_label=mk_label(mk_lstr(next_label++));
	loop_push(NULL, info->break_label);
	(yyval.loop)=info;
}
#line 2187 "mini.y.c"
    break;

  case 111: /* switch_statement: SWITCH '(' expression ')' switch_header '{' switch_sections '}'  */
#line 616 "mini.y"
{
	SWITCH_BODY *body=(yyvsp[-1].switch_body);
	LOOP_INFO *info=(yyvsp[-3].loop);
	loop_pop();
	(yyval.tac)=do_switch((yyvsp[-5].exp), body->cases, body->default_label, body->default_code, info);
	free(body);
	free(info);
}
#line 2200 "mini.y.c"
    break;

  case 112: /* switch_sections: %empty  */
#line 627 "mini.y"
{
	SWITCH_BODY *body=(SWITCH_BODY *)malloc(sizeof(SWITCH_BODY));
	body->cases=NULL;
	body->default_label=NULL;
	body->default_code=NULL;
	(yyval.switch_body)=body;
}
#line 2212 "mini.y.c"
    break;

  case 113: /* switch_sections: switch_sections case_clause  */
#line 635 "mini.y"
{
	SWITCH_BODY *body=(yyvsp[-1].switch_body);
	if(body->cases==NULL)
	{
		body->cases=(yyvsp[0].cases);
	}
	else
	{
		SWITCH_CASE *iter=body->cases;
		while(iter->next!=NULL) iter=iter->next;
		iter->next=(yyvsp[0].cases);
	}
	(yyval.switch_body)=body;
}
#line 2231 "mini.y.c"
    break;

  case 114: /* switch_sections: switch_sections default_clause  */
#line 650 "mini.y"
{
	SWITCH_BODY *body=(yyvsp[-1].switch_body);
	if(body->default_code!=NULL)
	{
		error("duplicate default label in switch");
	}
	else
	{
		body->default_label=(yyvsp[0].def_block)->label;
		body->default_code=(yyvsp[0].def_block)->code;
	}
	free((yyvsp[0].def_block));
	(yyval.switch_body)=body;
}
#line 2250 "mini.y.c"
    break;

  case 115: /* case_clause: CASE case_value ':' case_statement_list  */
#line 667 "mini.y"
{
	SWITCH_CASE *node=(SWITCH_CASE *)malloc(sizeof(SWITCH_CASE));
	node->value=(yyvsp[-2].sym);
	node->label=mk_label(mk_lstr(next_label++));
	TAC *label_tac=mk_tac(TAC_LABEL, node->label, NULL, NULL);
	node->code=join_tac(label_tac, (yyvsp[0].tac));
	node->next=NULL;
	(yyval.cases)=node;
}
#line 2264 "mini.y.c"
    break;

  case 116: /* case_value: INTEGER  */
#line 679 "mini.y"
{
	(yyval.sym)=mk_const(atoi((yyvsp[0].string)));
}
#line 2272 "mini.y.c"
    break;

  case 117: /* case_value: CHARACTER  */
#line 683 "mini.y"
{
	(yyval.sym)=mk_char_const((yyvsp[0].character));
}
#line 2280 "mini.y.c"
    break;

  case 118: /* default_clause: DEFAULT ':' case_statement_list  */
#line 689 "mini.y"
{
	DEFAULT_BLOCK *block=(DEFAULT_BLOCK *)malloc(sizeof(DEFAULT_BLOCK));
	block->label=mk_label(mk_lstr(next_label++));
	TAC *label_tac=mk_tac(TAC_LABEL, block->label, NULL, NULL);
	block->code=join_tac(label_tac, (yyvsp[0].tac));
	(yyval.def_block)=block;
}
#line 2292 "mini.y.c"
    break;

  case 119: /* case_statement_list: case_statement_list statement  */
#line 699 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 2300 "mini.y.c"
    break;

  case 120: /* case_statement_list: %empty  */
#line 703 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 2308 "mini.y.c"
    break;

  case 121: /* call_statement: IDENTIFIER '(' argument_list ')'  */
#line 709 "mini.y"
{
	(yyval.tac)=do_call((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 2316 "mini.y.c"
    break;

  case 122: /* call_expression: IDENTIFIER '(' argument_list ')'  */
#line 715 "mini.y"
{
	(yyval.exp)=do_call_ret((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 2324 "mini.y.c"
    break;


#line 2328 "mini.y.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 720 "mini.y"


void yyerror(char* msg) 
{
	fprintf(stderr, "%s: line %d\n", msg, yylineno);
	exit(0);
}
