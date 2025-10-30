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


#line 84 "mini.y.c"

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
  YYSYMBOL_EQ = 5,                         /* EQ  */
  YYSYMBOL_NE = 6,                         /* NE  */
  YYSYMBOL_LT = 7,                         /* LT  */
  YYSYMBOL_LE = 8,                         /* LE  */
  YYSYMBOL_GT = 9,                         /* GT  */
  YYSYMBOL_GE = 10,                        /* GE  */
  YYSYMBOL_UMINUS = 11,                    /* UMINUS  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_SWITCH = 16,                    /* SWITCH  */
  YYSYMBOL_CASE = 17,                      /* CASE  */
  YYSYMBOL_DEFAULT = 18,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 19,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 20,                  /* CONTINUE  */
  YYSYMBOL_FUNC = 21,                      /* FUNC  */
  YYSYMBOL_INPUT = 22,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 23,                    /* OUTPUT  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_INTEGER = 25,                   /* INTEGER  */
  YYSYMBOL_IDENTIFIER = 26,                /* IDENTIFIER  */
  YYSYMBOL_TEXT = 27,                      /* TEXT  */
  YYSYMBOL_CHARACTER = 28,                 /* CHARACTER  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_DEREF = 33,                     /* DEREF  */
  YYSYMBOL_ADDROF = 34,                    /* ADDROF  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* '='  */
  YYSYMBOL_42_ = 42,                       /* '&'  */
  YYSYMBOL_43_ = 43,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_function_declaration_list = 46, /* function_declaration_list  */
  YYSYMBOL_function_declaration = 47,      /* function_declaration  */
  YYSYMBOL_declaration = 48,               /* declaration  */
  YYSYMBOL_variable_list = 49,             /* variable_list  */
  YYSYMBOL_declarator = 50,                /* declarator  */
  YYSYMBOL_function = 51,                  /* function  */
  YYSYMBOL_function_head = 52,             /* function_head  */
  YYSYMBOL_type_specifier = 53,            /* type_specifier  */
  YYSYMBOL_parameter_list = 54,            /* parameter_list  */
  YYSYMBOL_statement = 55,                 /* statement  */
  YYSYMBOL_block = 56,                     /* block  */
  YYSYMBOL_declaration_list = 57,          /* declaration_list  */
  YYSYMBOL_statement_list = 58,            /* statement_list  */
  YYSYMBOL_assignment_statement = 59,      /* assignment_statement  */
  YYSYMBOL_expression = 60,                /* expression  */
  YYSYMBOL_argument_list = 61,             /* argument_list  */
  YYSYMBOL_expression_list = 62,           /* expression_list  */
  YYSYMBOL_input_statement = 63,           /* input_statement  */
  YYSYMBOL_output_statement = 64,          /* output_statement  */
  YYSYMBOL_return_statement = 65,          /* return_statement  */
  YYSYMBOL_if_statement = 66,              /* if_statement  */
  YYSYMBOL_while_statement = 67,           /* while_statement  */
  YYSYMBOL_68_1 = 68,                      /* @1  */
  YYSYMBOL_for_statement = 69,             /* for_statement  */
  YYSYMBOL_70_2 = 70,                      /* @2  */
  YYSYMBOL_for_init = 71,                  /* for_init  */
  YYSYMBOL_for_post = 72,                  /* for_post  */
  YYSYMBOL_expression_opt = 73,            /* expression_opt  */
  YYSYMBOL_break_statement = 74,           /* break_statement  */
  YYSYMBOL_continue_statement = 75,        /* continue_statement  */
  YYSYMBOL_pointer_lvalue = 76,            /* pointer_lvalue  */
  YYSYMBOL_switch_header = 77,             /* switch_header  */
  YYSYMBOL_switch_statement = 78,          /* switch_statement  */
  YYSYMBOL_switch_sections = 79,           /* switch_sections  */
  YYSYMBOL_case_clause = 80,               /* case_clause  */
  YYSYMBOL_case_value = 81,                /* case_value  */
  YYSYMBOL_default_clause = 82,            /* default_clause  */
  YYSYMBOL_case_statement_list = 83,       /* case_statement_list  */
  YYSYMBOL_call_statement = 84,            /* call_statement  */
  YYSYMBOL_call_expression = 85            /* call_expression  */
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   338

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
       2,     2,     2,     2,     2,     2,     2,     2,    42,     2,
      37,    38,    31,    29,    36,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    35,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    27,    28,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    49,    49,    56,    57,    63,    64,    67,    73,    74,
      80,    84,    90,    96,   103,   111,   116,   123,   127,   132,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   156,   163,   166,   172,   173,   179,   183,
     189,   193,   197,   201,   205,   209,   213,   217,   221,   225,
     229,   233,   237,   241,   245,   249,   253,   257,   261,   269,
     272,   275,   276,   283,   289,   293,   297,   303,   311,   315,
     322,   321,   340,   339,   357,   362,   367,   372,   377,   382,
     387,   393,   399,   406,   416,   428,   435,   450,   467,   479,
     483,   489,   499,   504,   509,   515
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "CHAR", "EQ",
  "NE", "LT", "LE", "GT", "GE", "UMINUS", "IF", "ELSE", "WHILE", "FOR",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "CONTINUE", "FUNC", "INPUT",
  "OUTPUT", "RETURN", "INTEGER", "IDENTIFIER", "TEXT", "CHARACTER", "'+'",
  "'-'", "'*'", "'/'", "DEREF", "ADDROF", "';'", "','", "'('", "')'",
  "'{'", "'}'", "'='", "'&'", "':'", "$accept", "program",
  "function_declaration_list", "function_declaration", "declaration",
  "variable_list", "declarator", "function", "function_head",
  "type_specifier", "parameter_list", "statement", "block",
  "declaration_list", "statement_list", "assignment_statement",
  "expression", "argument_list", "expression_list", "input_statement",
  "output_statement", "return_statement", "if_statement",
  "while_statement", "@1", "for_statement", "@2", "for_init", "for_post",
  "expression_opt", "break_statement", "continue_statement",
  "pointer_lvalue", "switch_header", "switch_statement", "switch_sections",
  "case_clause", "case_value", "default_clause", "case_statement_list",
  "call_statement", "call_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-92)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      86,   -59,   -59,   -59,   -59,     4,    57,   -59,   -59,   -59,
     -14,   -13,   -59,   -59,    25,   -59,    28,    39,   -59,   -59,
      58,   -59,   -59,   -13,    33,    23,   -59,   -59,   -59,   -59,
     199,   -59,    47,    54,    62,    64,   -59,   -59,    78,    17,
      72,   -26,    80,   -59,   -59,   -59,   170,    73,    75,    76,
      81,   -59,   -59,   -59,    83,    84,    66,   -59,    85,    72,
      72,   -12,    72,   -59,   -59,   -59,   -59,   -59,   -59,    96,
     -59,    72,    72,    72,    89,   306,   -59,    11,    72,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,    72,   -59,
       0,   252,    82,   -59,    87,   262,    11,   -59,   -59,   296,
     -59,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,   306,    99,   103,   306,   306,    23,   -59,    51,   -59,
     102,   -59,    -4,    -4,    -4,    -4,    -4,    -4,    15,    15,
     -59,   -59,   -59,    72,   108,   225,   306,   106,   105,   -59,
     306,    23,   -59,   -12,   -59,   -59,   -59,   107,    38,   -59,
      -8,   104,   -59,   -59,   -59,   225,   -59,   -59,   111,   -59,
     -59,   -59,   112,   141,   -59
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    13,    15,    16,    14,     0,     0,     3,     6,     5,
       0,     0,     1,     4,    19,    10,     0,     0,     8,    17,
       0,    11,     7,     0,     0,     0,     9,    18,    34,    12,
       0,    32,     0,     0,     0,     0,    80,    81,     0,     0,
       0,     0,     0,    35,    36,    31,     0,     0,     0,     0,
       0,    25,    26,    27,     0,     0,     0,    28,     0,     0,
       0,    75,     0,    63,    64,    65,    66,    58,    54,    56,
      55,     0,     0,     0,     0,    67,    57,     0,     0,    82,
      33,    37,    20,    21,    22,    24,    29,    30,     0,    23,
       0,     0,     0,    74,     0,     0,     0,    44,    53,     0,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,     0,    60,    38,    39,     0,    70,     0,    83,
       0,    51,    45,    46,    47,    48,    49,    50,    40,    41,
      42,    43,    94,     0,    68,     0,    78,     0,     0,    95,
      62,     0,    71,    77,    85,    69,    76,     0,     0,    72,
       0,     0,    84,    86,    87,     0,    89,    90,     0,    93,
      73,    93,     0,     0,    92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   -59,   140,   118,   -59,   126,   -59,   -59,   -59,
     -59,   -30,   -24,   -59,   -59,   -58,   -38,    70,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -11,
     -59,   -59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,    17,    18,     9,    10,    11,
      20,   164,    45,    30,    46,    47,   111,   112,   113,    48,
      49,    50,    51,    52,   135,    53,   155,    94,   147,   137,
      54,    55,    56,   138,    57,   148,   153,   158,   154,   162,
      58,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    29,    75,    93,    12,   101,   102,   103,   104,   105,
     106,    77,    67,    15,    92,    78,    81,   156,    16,    42,
     157,    90,    91,    14,    95,   107,   108,   109,   110,   107,
     108,   109,   110,    97,    98,    99,    68,    69,   116,    70,
     114,    71,    72,    64,    65,    66,   109,   110,    73,   -59,
     115,    19,    67,    74,    21,   150,   151,    -2,     1,    27,
       2,     3,    28,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    67,    22,    23,    68,    69,   152,    70,
     136,    71,    72,     4,    59,   146,   -79,     1,    73,     2,
       3,    60,   134,    74,    24,   140,    25,    68,    69,    61,
      70,    62,    71,    72,    63,   142,    79,    88,    82,    73,
      83,    84,     4,    31,    74,   100,    85,   145,    86,    87,
      89,   141,   118,    78,    32,   160,    33,    34,    35,   -91,
     -91,    36,    37,    96,    38,    39,    40,   132,    41,   133,
     139,   143,    31,    42,   144,   149,    13,   159,    43,    26,
     163,    28,   -91,    32,   161,    33,    34,    35,   -88,   -88,
      36,    37,     0,    38,    39,    40,   120,    41,     0,     0,
       0,    31,    42,     0,     0,     0,     0,     0,     0,     0,
      28,   -88,    32,     0,    33,    34,    35,     0,     0,    36,
      37,     0,    38,    39,    40,     0,    41,     0,     0,     0,
      31,    42,     2,     3,     0,     0,     0,     0,     0,    28,
      80,    32,     0,    33,    34,    35,     0,     0,    36,    37,
       0,    38,    39,    40,     0,    41,    31,     0,     0,     0,
      42,     0,     0,     0,     0,     0,     0,    32,    28,    33,
      34,    35,     0,     0,    36,    37,     0,    38,    39,    40,
       0,    41,     0,     0,     0,     0,    42,   101,   102,   103,
     104,   105,   106,     0,    28,     0,     0,   101,   102,   103,
     104,   105,   106,     0,     0,     0,     0,     0,     0,     0,
       0,   107,   108,   109,   110,     0,     0,     0,     0,     0,
     117,   107,   108,   109,   110,     0,     0,     0,     0,     0,
     119,   101,   102,   103,   104,   105,   106,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   108,   109,   110,     0,
       0,     0,     0,     0,   121,   107,   108,   109,   110
};

static const yytype_int16 yycheck[] =
{
      30,    25,    40,    61,     0,     5,     6,     7,     8,     9,
      10,    37,     1,    26,    26,    41,    46,    25,    31,    31,
      28,    59,    60,    37,    62,    29,    30,    31,    32,    29,
      30,    31,    32,    71,    72,    73,    25,    26,    38,    28,
      78,    30,    31,    26,    27,    28,    31,    32,    37,    38,
      88,    26,     1,    42,    26,    17,    18,     0,     1,    26,
       3,     4,    39,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,     1,    35,    36,    25,    26,    40,    28,
     118,    30,    31,    26,    37,   143,    35,     1,    37,     3,
       4,    37,   116,    42,    36,   133,    38,    25,    26,    37,
      28,    37,    30,    31,    26,   135,    26,    41,    35,    37,
      35,    35,    26,     1,    42,    26,    35,   141,    35,    35,
      35,    13,    35,    41,    12,   155,    14,    15,    16,    17,
      18,    19,    20,    37,    22,    23,    24,    38,    26,    36,
      38,    35,     1,    31,    39,    38,     6,    43,    30,    23,
     161,    39,    40,    12,    43,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    96,    26,    -1,    -1,
      -1,     1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    12,    -1,    14,    15,    16,    -1,    -1,    19,
      20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,    -1,
       1,    31,     3,     4,    -1,    -1,    -1,    -1,    -1,    39,
      40,    12,    -1,    14,    15,    16,    -1,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,     1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    12,    39,    14,
      15,    16,    -1,    -1,    19,    20,    -1,    22,    23,    24,
      -1,    26,    -1,    -1,    -1,    -1,    31,     5,     6,     7,
       8,     9,    10,    -1,    39,    -1,    -1,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      38,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      38,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    38,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,    26,    45,    46,    47,    48,    51,
      52,    53,     0,    47,    37,    26,    31,    49,    50,    26,
      54,    26,    35,    36,    36,    38,    50,    26,    39,    56,
      57,     1,    12,    14,    15,    16,    19,    20,    22,    23,
      24,    26,    31,    48,    55,    56,    58,    59,    63,    64,
      65,    66,    67,    69,    74,    75,    76,    78,    84,    37,
      37,    37,    37,    26,    26,    27,    28,     1,    25,    26,
      28,    30,    31,    37,    42,    60,    85,    37,    41,    26,
      40,    55,    35,    35,    35,    35,    35,    35,    41,    35,
      60,    60,    26,    59,    71,    60,    37,    60,    60,    60,
      26,     5,     6,     7,     8,     9,    10,    29,    30,    31,
      32,    60,    61,    62,    60,    60,    38,    38,    35,    38,
      61,    38,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    38,    36,    56,    68,    60,    73,    77,    38,
      60,    13,    55,    35,    39,    56,    59,    72,    79,    38,
      17,    18,    40,    80,    82,    70,    25,    28,    81,    43,
      55,    43,    83,    83,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    49,    49,
      50,    50,    51,    51,    52,    53,    53,    54,    54,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    62,    63,    64,    64,    64,    65,    66,    66,
      68,    67,    70,    69,    71,    71,    72,    72,    73,    73,
      74,    75,    76,    77,    78,    79,    79,    79,    80,    81,
      81,    82,    83,    83,    84,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     3,
       1,     2,     5,     1,     1,     1,     1,     1,     3,     0,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     4,     0,     2,     1,     2,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     1,     1,     1,     0,
       1,     1,     3,     2,     2,     2,     2,     2,     5,     7,
       0,     6,     0,    10,     1,     0,     1,     0,     1,     0,
       1,     1,     2,     0,     8,     0,     2,     2,     4,     1,
       1,     3,     2,     0,     4,     4
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
#line 50 "mini.y"
{
	tac_last=(yyvsp[0].tac);
	tac_complete();
}
#line 1312 "mini.y.c"
    break;

  case 4: /* function_declaration_list: function_declaration_list function_declaration  */
#line 58 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1320 "mini.y.c"
    break;

  case 7: /* declaration: type_specifier variable_list ';'  */
#line 68 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1328 "mini.y.c"
    break;

  case 9: /* variable_list: variable_list ',' declarator  */
#line 75 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 1336 "mini.y.c"
    break;

  case 10: /* declarator: IDENTIFIER  */
#line 81 "mini.y"
{
	(yyval.tac)=declare_var((yyvsp[0].string), current_decl_type);
}
#line 1344 "mini.y.c"
    break;

  case 11: /* declarator: '*' IDENTIFIER  */
#line 85 "mini.y"
{
	(yyval.tac)=declare_var((yyvsp[0].string), pointer_type_from_base(current_decl_type));
}
#line 1352 "mini.y.c"
    break;

  case 12: /* function: function_head '(' parameter_list ')' block  */
#line 91 "mini.y"
{
	(yyval.tac)=do_func((yyvsp[-4].sym), (yyvsp[-2].tac), (yyvsp[0].tac));
	scope=0; /* Leave local scope. */
	sym_tab_local=NULL; /* Clear local symbol table. */
}
#line 1362 "mini.y.c"
    break;

  case 13: /* function: error  */
#line 97 "mini.y"
{
	error("Bad function syntax");
	(yyval.tac)=NULL;
}
#line 1371 "mini.y.c"
    break;

  case 14: /* function_head: IDENTIFIER  */
#line 104 "mini.y"
{
	(yyval.sym)=declare_func((yyvsp[0].string));
	scope=1; /* Enter local scope. */
	sym_tab_local=NULL; /* Init local symbol table. */
}
#line 1381 "mini.y.c"
    break;

  case 15: /* type_specifier: INT  */
#line 112 "mini.y"
{
	current_decl_type = TYPE_INT;
	(yyval.number) = TYPE_INT;
}
#line 1390 "mini.y.c"
    break;

  case 16: /* type_specifier: CHAR  */
#line 117 "mini.y"
{
	current_decl_type = TYPE_CHAR;
	(yyval.number) = TYPE_CHAR;
}
#line 1399 "mini.y.c"
    break;

  case 17: /* parameter_list: IDENTIFIER  */
#line 124 "mini.y"
{
	(yyval.tac)=declare_para((yyvsp[0].string), TYPE_INT);
}
#line 1407 "mini.y.c"
    break;

  case 18: /* parameter_list: parameter_list ',' IDENTIFIER  */
#line 128 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), declare_para((yyvsp[0].string), TYPE_INT));
}
#line 1415 "mini.y.c"
    break;

  case 19: /* parameter_list: %empty  */
#line 132 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1423 "mini.y.c"
    break;

  case 32: /* statement: error  */
#line 150 "mini.y"
{
	error("Bad statement syntax");
	(yyval.tac)=NULL;
}
#line 1432 "mini.y.c"
    break;

  case 33: /* block: '{' declaration_list statement_list '}'  */
#line 157 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), (yyvsp[-1].tac));
}
#line 1440 "mini.y.c"
    break;

  case 34: /* declaration_list: %empty  */
#line 163 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1448 "mini.y.c"
    break;

  case 35: /* declaration_list: declaration_list declaration  */
#line 167 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1456 "mini.y.c"
    break;

  case 37: /* statement_list: statement_list statement  */
#line 174 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1464 "mini.y.c"
    break;

  case 38: /* assignment_statement: IDENTIFIER '=' expression  */
#line 180 "mini.y"
{
	(yyval.tac)=do_assign(get_var((yyvsp[-2].string)), (yyvsp[0].exp));
}
#line 1472 "mini.y.c"
    break;

  case 39: /* assignment_statement: pointer_lvalue '=' expression  */
#line 184 "mini.y"
{
	(yyval.tac)=do_store((yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1480 "mini.y.c"
    break;

  case 40: /* expression: expression '+' expression  */
#line 190 "mini.y"
{
	(yyval.exp)=do_bin(TAC_ADD, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1488 "mini.y.c"
    break;

  case 41: /* expression: expression '-' expression  */
#line 194 "mini.y"
{
	(yyval.exp)=do_bin(TAC_SUB, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1496 "mini.y.c"
    break;

  case 42: /* expression: expression '*' expression  */
#line 198 "mini.y"
{
	(yyval.exp)=do_bin(TAC_MUL, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1504 "mini.y.c"
    break;

  case 43: /* expression: expression '/' expression  */
#line 202 "mini.y"
{
	(yyval.exp)=do_bin(TAC_DIV, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1512 "mini.y.c"
    break;

  case 44: /* expression: '-' expression  */
#line 206 "mini.y"
{
	(yyval.exp)=do_un(TAC_NEG, (yyvsp[0].exp));
}
#line 1520 "mini.y.c"
    break;

  case 45: /* expression: expression EQ expression  */
#line 210 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_EQ, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1528 "mini.y.c"
    break;

  case 46: /* expression: expression NE expression  */
#line 214 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_NE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1536 "mini.y.c"
    break;

  case 47: /* expression: expression LT expression  */
#line 218 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_LT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1544 "mini.y.c"
    break;

  case 48: /* expression: expression LE expression  */
#line 222 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_LE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1552 "mini.y.c"
    break;

  case 49: /* expression: expression GT expression  */
#line 226 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_GT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1560 "mini.y.c"
    break;

  case 50: /* expression: expression GE expression  */
#line 230 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_GE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1568 "mini.y.c"
    break;

  case 51: /* expression: '(' expression ')'  */
#line 234 "mini.y"
{
	(yyval.exp)=(yyvsp[-1].exp);
}
#line 1576 "mini.y.c"
    break;

  case 52: /* expression: '&' IDENTIFIER  */
#line 238 "mini.y"
{
	(yyval.exp)=do_addr(get_var((yyvsp[0].string)));
}
#line 1584 "mini.y.c"
    break;

  case 53: /* expression: '*' expression  */
#line 242 "mini.y"
{
	(yyval.exp)=do_deref((yyvsp[0].exp));
}
#line 1592 "mini.y.c"
    break;

  case 54: /* expression: INTEGER  */
#line 246 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, mk_const(atoi((yyvsp[0].string))), NULL);
}
#line 1600 "mini.y.c"
    break;

  case 55: /* expression: CHARACTER  */
#line 250 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, mk_char_const((yyvsp[0].character)), NULL);
}
#line 1608 "mini.y.c"
    break;

  case 56: /* expression: IDENTIFIER  */
#line 254 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, get_var((yyvsp[0].string)), NULL);
}
#line 1616 "mini.y.c"
    break;

  case 57: /* expression: call_expression  */
#line 258 "mini.y"
{
	(yyval.exp)=(yyvsp[0].exp);
}
#line 1624 "mini.y.c"
    break;

  case 58: /* expression: error  */
#line 262 "mini.y"
{
	error("Bad expression syntax");
	(yyval.exp)=mk_exp(NULL, NULL, NULL);
}
#line 1633 "mini.y.c"
    break;

  case 59: /* argument_list: %empty  */
#line 269 "mini.y"
{
	(yyval.exp)=NULL;
}
#line 1641 "mini.y.c"
    break;

  case 62: /* expression_list: expression_list ',' expression  */
#line 277 "mini.y"
{
	(yyvsp[0].exp)->next=(yyvsp[-2].exp);
	(yyval.exp)=(yyvsp[0].exp);
}
#line 1650 "mini.y.c"
    break;

  case 63: /* input_statement: INPUT IDENTIFIER  */
#line 284 "mini.y"
{
	(yyval.tac)=do_input(get_var((yyvsp[0].string)));
}
#line 1658 "mini.y.c"
    break;

  case 64: /* output_statement: OUTPUT IDENTIFIER  */
#line 290 "mini.y"
{
	(yyval.tac)=do_output(get_var((yyvsp[0].string)));
}
#line 1666 "mini.y.c"
    break;

  case 65: /* output_statement: OUTPUT TEXT  */
#line 294 "mini.y"
{
	(yyval.tac)=do_output(mk_text((yyvsp[0].string)));
}
#line 1674 "mini.y.c"
    break;

  case 66: /* output_statement: OUTPUT CHARACTER  */
#line 298 "mini.y"
{
	(yyval.tac)=do_output(mk_char_const((yyvsp[0].character)));
}
#line 1682 "mini.y.c"
    break;

  case 67: /* return_statement: RETURN expression  */
#line 304 "mini.y"
{
	TAC *t=mk_tac(TAC_RETURN, (yyvsp[0].exp)->ret, NULL, NULL);
	t->prev=(yyvsp[0].exp)->tac;
	(yyval.tac)=t;
}
#line 1692 "mini.y.c"
    break;

  case 68: /* if_statement: IF '(' expression ')' block  */
#line 312 "mini.y"
{
	(yyval.tac)=do_if((yyvsp[-2].exp), (yyvsp[0].tac));
}
#line 1700 "mini.y.c"
    break;

  case 69: /* if_statement: IF '(' expression ')' block ELSE block  */
#line 316 "mini.y"
{
	(yyval.tac)=do_test((yyvsp[-4].exp), (yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 1708 "mini.y.c"
    break;

  case 70: /* @1: %empty  */
#line 322 "mini.y"
{
	LOOP_INFO *info=(LOOP_INFO *)malloc(sizeof(LOOP_INFO));
	info->start_label=mk_label(mk_lstr(next_label++));
	info->continue_label=info->start_label;
	info->break_label=mk_label(mk_lstr(next_label++));
	loop_push(info->continue_label, info->break_label);
	(yyval.loop)=info;
}
#line 1721 "mini.y.c"
    break;

  case 71: /* while_statement: WHILE '(' expression ')' @1 statement  */
#line 331 "mini.y"
{
	LOOP_INFO *info=(yyvsp[-1].loop);
	loop_pop();
	(yyval.tac)=do_while((yyvsp[-3].exp), (yyvsp[0].tac), info);
	free(info);
}
#line 1732 "mini.y.c"
    break;

  case 72: /* @2: %empty  */
#line 340 "mini.y"
{
	LOOP_INFO *info=(LOOP_INFO *)malloc(sizeof(LOOP_INFO));
	info->start_label=mk_label(mk_lstr(next_label++));
	info->continue_label=mk_label(mk_lstr(next_label++));
	info->break_label=mk_label(mk_lstr(next_label++));
	loop_push(info->continue_label, info->break_label);
	(yyval.loop)=info;
}
#line 1745 "mini.y.c"
    break;

  case 73: /* for_statement: FOR '(' for_init ';' expression_opt ';' for_post ')' @2 statement  */
#line 349 "mini.y"
{
	LOOP_INFO *info=(yyvsp[-1].loop);
	loop_pop();
	(yyval.tac)=do_for((yyvsp[-7].tac), (yyvsp[-5].exp), (yyvsp[-3].tac), (yyvsp[0].tac), info);
	free(info);
}
#line 1756 "mini.y.c"
    break;

  case 74: /* for_init: assignment_statement  */
#line 358 "mini.y"
{
	(yyval.tac)=(yyvsp[0].tac);
}
#line 1764 "mini.y.c"
    break;

  case 75: /* for_init: %empty  */
#line 362 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1772 "mini.y.c"
    break;

  case 76: /* for_post: assignment_statement  */
#line 368 "mini.y"
{
	(yyval.tac)=(yyvsp[0].tac);
}
#line 1780 "mini.y.c"
    break;

  case 77: /* for_post: %empty  */
#line 372 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1788 "mini.y.c"
    break;

  case 78: /* expression_opt: expression  */
#line 378 "mini.y"
{
	(yyval.exp)=(yyvsp[0].exp);
}
#line 1796 "mini.y.c"
    break;

  case 79: /* expression_opt: %empty  */
#line 382 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, mk_const(1), NULL);
}
#line 1804 "mini.y.c"
    break;

  case 80: /* break_statement: BREAK  */
#line 388 "mini.y"
{
	(yyval.tac)=do_break_stmt();
}
#line 1812 "mini.y.c"
    break;

  case 81: /* continue_statement: CONTINUE  */
#line 394 "mini.y"
{
	(yyval.tac)=do_continue_stmt();
}
#line 1820 "mini.y.c"
    break;

  case 82: /* pointer_lvalue: '*' IDENTIFIER  */
#line 400 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, get_var((yyvsp[0].string)), NULL);
}
#line 1828 "mini.y.c"
    break;

  case 83: /* switch_header: %empty  */
#line 406 "mini.y"
{
	LOOP_INFO *info=(LOOP_INFO *)malloc(sizeof(LOOP_INFO));
	info->start_label=NULL;
	info->continue_label=NULL;
	info->break_label=mk_label(mk_lstr(next_label++));
	loop_push(NULL, info->break_label);
	(yyval.loop)=info;
}
#line 1841 "mini.y.c"
    break;

  case 84: /* switch_statement: SWITCH '(' expression ')' switch_header '{' switch_sections '}'  */
#line 417 "mini.y"
{
	SWITCH_BODY *body=(yyvsp[-1].switch_body);
	LOOP_INFO *info=(yyvsp[-3].loop);
	loop_pop();
	(yyval.tac)=do_switch((yyvsp[-5].exp), body->cases, body->default_label, body->default_code, info);
	free(body);
	free(info);
}
#line 1854 "mini.y.c"
    break;

  case 85: /* switch_sections: %empty  */
#line 428 "mini.y"
{
	SWITCH_BODY *body=(SWITCH_BODY *)malloc(sizeof(SWITCH_BODY));
	body->cases=NULL;
	body->default_label=NULL;
	body->default_code=NULL;
	(yyval.switch_body)=body;
}
#line 1866 "mini.y.c"
    break;

  case 86: /* switch_sections: switch_sections case_clause  */
#line 436 "mini.y"
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
#line 1885 "mini.y.c"
    break;

  case 87: /* switch_sections: switch_sections default_clause  */
#line 451 "mini.y"
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
#line 1904 "mini.y.c"
    break;

  case 88: /* case_clause: CASE case_value ':' case_statement_list  */
#line 468 "mini.y"
{
	SWITCH_CASE *node=(SWITCH_CASE *)malloc(sizeof(SWITCH_CASE));
	node->value=(yyvsp[-2].sym);
	node->label=mk_label(mk_lstr(next_label++));
	TAC *label_tac=mk_tac(TAC_LABEL, node->label, NULL, NULL);
	node->code=join_tac(label_tac, (yyvsp[0].tac));
	node->next=NULL;
	(yyval.cases)=node;
}
#line 1918 "mini.y.c"
    break;

  case 89: /* case_value: INTEGER  */
#line 480 "mini.y"
{
	(yyval.sym)=mk_const(atoi((yyvsp[0].string)));
}
#line 1926 "mini.y.c"
    break;

  case 90: /* case_value: CHARACTER  */
#line 484 "mini.y"
{
	(yyval.sym)=mk_char_const((yyvsp[0].character));
}
#line 1934 "mini.y.c"
    break;

  case 91: /* default_clause: DEFAULT ':' case_statement_list  */
#line 490 "mini.y"
{
	DEFAULT_BLOCK *block=(DEFAULT_BLOCK *)malloc(sizeof(DEFAULT_BLOCK));
	block->label=mk_label(mk_lstr(next_label++));
	TAC *label_tac=mk_tac(TAC_LABEL, block->label, NULL, NULL);
	block->code=join_tac(label_tac, (yyvsp[0].tac));
	(yyval.def_block)=block;
}
#line 1946 "mini.y.c"
    break;

  case 92: /* case_statement_list: case_statement_list statement  */
#line 500 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1954 "mini.y.c"
    break;

  case 93: /* case_statement_list: %empty  */
#line 504 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1962 "mini.y.c"
    break;

  case 94: /* call_statement: IDENTIFIER '(' argument_list ')'  */
#line 510 "mini.y"
{
	(yyval.tac)=do_call((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 1970 "mini.y.c"
    break;

  case 95: /* call_expression: IDENTIFIER '(' argument_list ')'  */
#line 516 "mini.y"
{
	(yyval.exp)=do_call_ret((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 1978 "mini.y.c"
    break;


#line 1982 "mini.y.c"

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

#line 521 "mini.y"


void yyerror(char* msg) 
{
	fprintf(stderr, "%s: line %d\n", msg, yylineno);
	exit(0);
}
