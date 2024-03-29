/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_Indent = 258,
     T_Dedent = 259,
     T_import = 260,
     T_True = 261,
     T_False = 262,
     T_not = 263,
     T_and = 264,
     T_or = 265,
     T_if = 266,
     T_else = 267,
     T_elif = 268,
     T_for = 269,
     T_in = 270,
     T_range = 271,
     T_list = 272,
     T_plus = 273,
     T_minus = 274,
     T_star = 275,
     T_divide = 276,
     T_modulus = 277,
     T_LT = 278,
     T_GT = 279,
     T_LTE = 280,
     T_GTE = 281,
     T_EQ = 282,
     T_NEQ = 283,
     T_semicolon = 284,
     T_colon = 285,
     T_comma = 286,
     T_assignment = 287,
     T_left_sq_b = 288,
     T_right_sq_b = 289,
     T_left_par = 290,
     T_right_par = 291,
     T_number = 292,
     T_identifier = 293,
     T_string = 294,
     T_Newline = 295
   };
#endif
/* Tokens.  */
#define T_Indent 258
#define T_Dedent 259
#define T_import 260
#define T_True 261
#define T_False 262
#define T_not 263
#define T_and 264
#define T_or 265
#define T_if 266
#define T_else 267
#define T_elif 268
#define T_for 269
#define T_in 270
#define T_range 271
#define T_list 272
#define T_plus 273
#define T_minus 274
#define T_star 275
#define T_divide 276
#define T_modulus 277
#define T_LT 278
#define T_GT 279
#define T_LTE 280
#define T_GTE 281
#define T_EQ 282
#define T_NEQ 283
#define T_semicolon 284
#define T_colon 285
#define T_comma 286
#define T_assignment 287
#define T_left_sq_b 288
#define T_right_sq_b 289
#define T_left_par 290
#define T_right_par 291
#define T_number 292
#define T_identifier 293
#define T_string 294
#define T_Newline 295




/* Copy the first part of user declarations.  */
#line 1 "test1_y.y"


#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include "test1.hpp"
#include <vector>

#define DEBUG 1

using namespace std;
symbol_table test;

int flag = 1;
int temp_no = 0;
int label_no = 0;
char *empty_string = strdup("");


extern my_stack_t *ptr_my_stack;

quadruple_t *ptr_quad;

void yyerror(const char *error_msg);

void init(my_stack_t *ptr_my_stack);
void push(my_stack_t *ptr_my_stack, int ind_lev);

int counter = 0;
int for_scope = 0;
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
int scope_count;
string final_int_code;
extern "C"
{
    int yyparse(void);
    int yylex(void);
    
    int yywrap()
    {
        return 1;
    }
}




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 53 "test1_y.y"
{
    int indentation_level;
    char *text;

    struct s1 {char *addr; char *code; char *true_l; char *false_l; char *sym_tab_info;} inter_code;

    struct s2 {char *start_r; char *end_r; char *step_r; char *sym_tab_info;} range_icg;

}
/* Line 193 of yacc.c.  */
#line 236 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 261 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    12,    14,    16,    19,
      21,    24,    28,    30,    32,    35,    37,    39,    43,    45,
      49,    52,    56,    58,    62,    64,    67,    69,    73,    77,
      81,    85,    89,    93,    97,    99,   103,   107,   109,   113,
     117,   121,   123,   126,   129,   131,   133,   135,   137,   141,
     143,   145,   147,   149,   154,   156,   158,   165,   167,   169,
     170,   175,   177,   181,   184,   188,   191,   193,   196,   198,
     199,   205,   206,   210,   211,   219,   222,   224,   225,   227,
     231,   233,   238,   245,   254,   256,   258
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    40,    43,    -1,    44,    43,
      -1,    -1,    45,    -1,    62,    -1,    47,    46,    -1,    40,
      -1,    29,    40,    -1,    29,    47,    46,    -1,    49,    -1,
      48,    -1,     5,    38,    -1,    50,    -1,    52,    -1,    38,
      32,    51,    -1,    52,    -1,    17,    35,    36,    -1,    33,
      34,    -1,    52,    10,    53,    -1,    53,    -1,    53,     9,
      54,    -1,    54,    -1,     8,    54,    -1,    55,    -1,    55,
      23,    56,    -1,    55,    24,    56,    -1,    55,    27,    56,
      -1,    55,    26,    56,    -1,    55,    25,    56,    -1,    55,
      28,    56,    -1,    55,    15,    56,    -1,    56,    -1,    56,
      18,    57,    -1,    56,    19,    57,    -1,    57,    -1,    57,
      20,    58,    -1,    57,    21,    58,    -1,    57,    22,    58,
      -1,    58,    -1,    18,    58,    -1,    19,    58,    -1,    59,
      -1,    38,    -1,    60,    -1,    61,    -1,    35,    52,    36,
      -1,    37,    -1,    39,    -1,     6,    -1,     7,    -1,    38,
      33,    52,    34,    -1,    63,    -1,    72,    -1,    11,    64,
      30,    65,    70,    71,    -1,    52,    -1,    45,    -1,    -1,
      40,     3,    66,    68,    -1,    45,    -1,    40,     3,    68,
      -1,    44,     4,    -1,    44,    69,     4,    -1,    44,    69,
      -1,    44,    -1,    40,    69,    -1,    40,    -1,    -1,    13,
      64,    30,    65,    70,    -1,    -1,    12,    30,    65,    -1,
      -1,    14,    73,    74,    15,    77,    30,    67,    -1,    75,
      76,    -1,    38,    -1,    -1,    31,    -1,    31,    75,    76,
      -1,    78,    -1,    16,    35,    79,    36,    -1,    16,    35,
      79,    31,    79,    36,    -1,    16,    35,    79,    31,    79,
      31,    79,    36,    -1,    38,    -1,    37,    -1,    61,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,   112,   132,   157,   173,   183,   199,   219,
     230,   244,   265,   276,   288,   302,   315,   327,   362,   372,
     384,   396,   417,   428,   448,   459,   473,   484,   537,   590,
     643,   696,   749,   802,   855,   866,   901,   933,   943,   975,
    1007,  1039,  1049,  1081,  1112,  1122,  1137,  1147,  1157,  1173,
    1183,  1193,  1219,  1246,  1263,  1277,  1287,  1377,  1394,  1404,
    1403,  1418,  1427,  1437,  1449,  1468,  1482,  1491,  1500,  1511,
    1520,  1557,  1566,  1578,  1577,  1665,  1671,  1677,  1678,  1679,
    1685,  1696,  1707,  1718,  1730,  1743,  1748
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Indent", "T_Dedent", "T_import",
  "T_True", "T_False", "T_not", "T_and", "T_or", "T_if", "T_else",
  "T_elif", "T_for", "T_in", "T_range", "T_list", "T_plus", "T_minus",
  "T_star", "T_divide", "T_modulus", "T_LT", "T_GT", "T_LTE", "T_GTE",
  "T_EQ", "T_NEQ", "T_semicolon", "T_colon", "T_comma", "T_assignment",
  "T_left_sq_b", "T_right_sq_b", "T_left_par", "T_right_par", "T_number",
  "T_identifier", "T_string", "T_Newline", "$accept", "prog_start",
  "input_file", "statement", "simple_statement", "next_simple_statement",
  "small_statement", "import_statement", "expr_statement",
  "assignment_statement", "assignment_expr", "or_test", "and_test",
  "not_test", "comparison", "arith_exp", "arith_exp2", "factor", "term",
  "constant", "list_index", "compound_statement", "if_statement", "test",
  "suite", "@1", "suite_for", "suite1", "repeat_statement",
  "elif_statement", "optional_else", "for_statement", "@2", "exprlist",
  "first_exprlist", "last_exprlist", "testlist", "range_fn", "range_term", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    44,    44,    45,    46,
      46,    46,    47,    47,    48,    49,    49,    50,    51,    51,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    56,    57,    57,
      57,    57,    58,    58,    58,    59,    59,    59,    59,    60,
      60,    60,    60,    61,    62,    62,    63,    64,    65,    66,
      65,    67,    67,    68,    68,    69,    69,    69,    69,    70,
      70,    71,    71,    73,    72,    74,    75,    76,    76,    76,
      77,    78,    78,    78,    79,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     1,     1,     2,     1,
       2,     3,     1,     1,     2,     1,     1,     3,     1,     3,
       2,     3,     1,     3,     1,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     4,     1,     1,     6,     1,     1,     0,
       4,     1,     3,     2,     3,     2,     1,     2,     1,     0,
       5,     0,     3,     0,     7,     2,     1,     0,     1,     3,
       1,     4,     6,     8,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,    51,    52,     0,     0,    73,     0,     0,     0,
      49,    45,    50,     5,     0,     2,     5,     6,     0,    13,
      12,    15,    16,    22,    24,    26,    34,    37,    41,    44,
      46,    47,     7,    54,    55,    14,    45,    25,    57,     0,
       0,    42,    43,     0,     0,     0,     3,     1,     4,     0,
       9,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,    77,
      48,     0,     0,    17,    18,     0,    10,     0,    21,    23,
      33,    27,    28,    31,    30,    29,    32,    35,    36,    38,
      39,    40,     0,    58,    69,     0,    78,    75,     0,    20,
      53,    11,    59,     0,    71,     0,     0,    80,    77,    19,
       0,     0,     0,    56,     0,     0,    79,     0,    60,     0,
       0,    85,    84,    86,     0,     0,    61,    74,    63,    68,
      66,     0,    69,    72,     0,    81,     0,    67,    65,    64,
      70,     0,    62,     0,    82,     0,    83
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    51,    18,    19,    20,    21,
      73,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    39,    94,   110,   127,   118,   131,   104,
     113,    34,    40,    68,    69,    97,   106,   107,   124
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -112
static const yytype_int16 yypact[] =
{
      57,   -29,  -112,  -112,   168,   168,  -112,    12,    12,   168,
    -112,   -11,  -112,    57,    69,  -112,    57,  -112,   -24,  -112,
    -112,  -112,    79,    45,  -112,   116,    18,    52,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,    60,  -112,    79,    76,
      61,  -112,  -112,    19,   163,   168,  -112,  -112,  -112,    95,
    -112,  -112,   168,   168,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,   110,  -112,    93,    88,
    -112,    85,    87,  -112,    79,    32,  -112,   -24,    45,  -112,
      18,    18,    18,    18,    18,    18,    18,    52,    52,  -112,
    -112,  -112,   119,  -112,   114,   122,    61,  -112,   115,  -112,
    -112,  -112,  -112,   168,   134,   117,   124,  -112,    88,  -112,
     154,   133,   136,  -112,    44,   118,  -112,     6,  -112,   110,
     110,  -112,    60,  -112,     2,   161,  -112,  -112,  -112,    72,
      72,   173,   114,  -112,    44,  -112,   154,  -112,  -112,  -112,
    -112,    17,  -112,    44,  -112,   131,  -112
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,  -112,    54,  -102,   -59,   101,   130,  -112,  -112,  -112,
    -112,    -5,   132,    -1,  -112,   155,    23,    -6,  -112,  -112,
    -108,  -112,  -112,    80,   -32,  -112,  -112,    49,   -25,    56,
    -112,  -112,  -112,  -112,    94,    86,  -112,  -112,  -111
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      38,    41,    42,    37,    43,    49,   123,    93,   117,    35,
     128,     1,     2,     3,     4,   130,    50,     5,     2,     3,
       6,    44,    45,   141,     7,     8,   123,   130,   130,    52,
       7,     8,   145,   134,   117,   123,    61,    62,   135,    74,
      75,     9,    52,    10,    11,    12,   129,     9,   143,    10,
      36,    12,    79,   144,    53,    70,   126,    89,    90,    91,
      93,    93,     1,     2,     3,     4,   100,    46,     5,    47,
      48,     6,    63,    64,    65,     7,     8,     1,     2,     3,
       4,   121,   122,     5,    87,    88,     6,   132,   133,    52,
       7,     8,     9,    45,    10,    11,    12,    13,    38,    67,
       1,     2,     3,     4,   137,   138,    66,     9,    95,    10,
      11,    12,   129,     7,     8,     1,     2,     3,     4,    96,
      98,    99,   102,     1,     2,     3,     4,   103,     7,     8,
       9,    54,    10,    11,    12,    76,     7,     8,   105,    55,
      56,    57,    58,    59,    60,     9,   112,    10,    11,    12,
      92,   109,   114,     9,   115,    10,    11,    12,   125,     1,
       2,     3,     4,   119,   136,     5,   120,   146,     6,     2,
       3,     4,     7,     8,     2,     3,     4,   139,   101,    77,
      71,     7,     8,   111,    78,   142,     7,     8,   140,     9,
     108,    10,    11,    12,   116,     0,    72,     0,     9,     0,
      10,    36,    12,     9,     0,    10,    36,    12,     0,    80,
      81,    82,    83,    84,    85,    86
};

static const yytype_int16 yycheck[] =
{
       5,     7,     8,     4,     9,    29,   114,    66,   110,    38,
       4,     5,     6,     7,     8,   117,    40,    11,     6,     7,
      14,    32,    33,   134,    18,    19,   134,   129,   130,    10,
      18,    19,   143,    31,   136,   143,    18,    19,    36,    44,
      45,    35,    10,    37,    38,    39,    40,    35,    31,    37,
      38,    39,    53,    36,     9,    36,   115,    63,    64,    65,
     119,   120,     5,     6,     7,     8,    34,    13,    11,     0,
      16,    14,    20,    21,    22,    18,    19,     5,     6,     7,
       8,    37,    38,    11,    61,    62,    14,   119,   120,    10,
      18,    19,    35,    33,    37,    38,    39,    40,   103,    38,
       5,     6,     7,     8,   129,   130,    30,    35,    15,    37,
      38,    39,    40,    18,    19,     5,     6,     7,     8,    31,
      35,    34,     3,     5,     6,     7,     8,    13,    18,    19,
      35,    15,    37,    38,    39,    40,    18,    19,    16,    23,
      24,    25,    26,    27,    28,    35,    12,    37,    38,    39,
      40,    36,    35,    35,    30,    37,    38,    39,    40,     5,
       6,     7,     8,    30,     3,    11,    30,    36,    14,     6,
       7,     8,    18,    19,     6,     7,     8,     4,    77,    49,
      17,    18,    19,   103,    52,   136,    18,    19,   132,    35,
      96,    37,    38,    39,   108,    -1,    33,    -1,    35,    -1,
      37,    38,    39,    35,    -1,    37,    38,    39,    -1,    54,
      55,    56,    57,    58,    59,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,     8,    11,    14,    18,    19,    35,
      37,    38,    39,    40,    42,    43,    44,    45,    47,    48,
      49,    50,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    72,    38,    38,    54,    52,    64,
      73,    58,    58,    52,    32,    33,    43,     0,    43,    29,
      40,    46,    10,     9,    15,    23,    24,    25,    26,    27,
      28,    18,    19,    20,    21,    22,    30,    38,    74,    75,
      36,    17,    33,    51,    52,    52,    40,    47,    53,    54,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    58,
      58,    58,    40,    45,    65,    15,    31,    76,    35,    34,
      34,    46,     3,    13,    70,    16,    77,    78,    75,    36,
      66,    64,    12,    71,    35,    30,    76,    44,    68,    30,
      30,    37,    38,    61,    79,    40,    45,    67,     4,    40,
      44,    69,    65,    65,    31,    36,     3,    69,    69,     4,
      70,    79,    68,    31,    36,    79,    36
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 90 "test1_y.y"
    {
                (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
                final_int_code = (yyvsp[(1) - (1)].inter_code).code;
                
                // printf("\n\n\n\nGenerated Intermediate Code: \n\n%s\n\n\n",$1.code);
                // FILE *fp = fopen("generated_intermediate_code.txt","w");

                // if(fp!=NULL)
                // {
                //   fputs($1.code,fp);
                // }
                // else
                // {
                //   printf("\nError: Unable to open file\n");
                // }

                //disp_quad(ptr_quad);
                

             }
    break;

  case 3:
#line 113 "test1_y.y"
    {
                // vector<string> temp1{$1,$2}; 
                // $$ = conversion(temp1);

                (yyval.inter_code).code = (yyvsp[(2) - (2)].inter_code).code;
                (yyval.inter_code).addr = (yyvsp[(2) - (2)].inter_code).addr;
                (yyval.inter_code).true_l = (yyvsp[(2) - (2)].inter_code).true_l;
                (yyval.inter_code).false_l = (yyvsp[(2) - (2)].inter_code).false_l;
                (yyval.inter_code).sym_tab_info = (yyvsp[(2) - (2)].inter_code).sym_tab_info;

                #if DEBUG
                printf("\n\ninside input file newline(stmt):\n\n");
                printf("$2:\n%s\n",(yyvsp[(2) - (2)].inter_code).code);
                #endif

                
                //printf("\n\n\n\n1. Generated Intermediate Code: \n %s\n\n\n",$$.code);

              }
    break;

  case 4:
#line 133 "test1_y.y"
    {
                // vector<string> temp1{$1,$2}; 
                // $$ = conversion(temp1);

                vector<string> gen_int_code{(yyvsp[(1) - (2)].inter_code).code,(yyvsp[(2) - (2)].inter_code).code};
                (yyval.inter_code).code = conversion(gen_int_code);

                #if DEBUG
                printf("\n\ninside input file(stmt):\n\n");
                printf("$1:\n%s\n",(yyvsp[(1) - (2)].inter_code).code);
                printf("$2:\n%s\n",(yyvsp[(2) - (2)].inter_code).code);
                #endif

                
                (yyval.inter_code).addr = (yyvsp[(2) - (2)].inter_code).addr;
                (yyval.inter_code).true_l = (yyvsp[(2) - (2)].inter_code).true_l;
                (yyval.inter_code).false_l = (yyvsp[(2) - (2)].inter_code).false_l;

                vector<string> temp_sym_tab{(yyvsp[(1) - (2)].inter_code).sym_tab_info,(yyvsp[(2) - (2)].inter_code).sym_tab_info};
                (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

                //printf("\n\n\n\n2. Generated Intermediate Code: \n %s\n\n\n",$$.code);

              }
    break;

  case 5:
#line 157 "test1_y.y"
    {
                #if DEBUG
                printf("\n\ninside input file blank(stmt):\n\n");
                printf("$$:\n%s\n",(yyval.inter_code).code);
                #endif

                (yyval.inter_code).code = empty_string;
                (yyval.inter_code).addr = "";
                (yyval.inter_code).true_l = "";
                (yyval.inter_code).false_l = "";
                (yyval.inter_code).sym_tab_info = "";

                //printf("\n\n\n3. Generated Intermediate Code: \n %s\n\n",$$.code);
              }
    break;

  case 6:
#line 174 "test1_y.y"
    {
                (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
                (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
                (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
                (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
                (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;

              }
    break;

  case 7:
#line 184 "test1_y.y"
    {
                (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
                (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
                (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
                (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
                (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;

                #if DEBUG
                printf("\n\ninside stmt (compound stmt):\n\n");
                printf("%s\n",(yyval.inter_code).code);
                #endif

              }
    break;

  case 8:
#line 200 "test1_y.y"
    {
                      //  vector<string> temp1{$1,$2}; 
                      //  $$ = conversion(temp1);

                      vector<string> gen_int_code{(yyvsp[(1) - (2)].inter_code).code,(yyvsp[(2) - (2)].inter_code).code};
                      (yyval.inter_code).code = conversion(gen_int_code);

                      (yyval.inter_code).addr = (yyvsp[(1) - (2)].inter_code).addr;
                      (yyval.inter_code).true_l = (yyvsp[(1) - (2)].inter_code).true_l;
                      (yyval.inter_code).false_l = (yyvsp[(1) - (2)].inter_code).false_l;

                      vector<string> temp_sym_tab{(yyvsp[(1) - (2)].inter_code).sym_tab_info,(yyvsp[(2) - (2)].inter_code).sym_tab_info};
                      (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

                      //printf("\n\n\n\nsimple_stmt Generated Intermediate Code: \n %s\n\n\n",$$.code);

                     }
    break;

  case 9:
#line 220 "test1_y.y"
    {
                            (yyval.inter_code).code = "";
                            (yyval.inter_code).addr = "";
                            (yyval.inter_code).true_l = "";
                            (yyval.inter_code).false_l = "";
                            (yyval.inter_code).sym_tab_info = "";


                          }
    break;

  case 10:
#line 231 "test1_y.y"
    {
                            // vector<string> temp1{$1,$2}; 
                            // $$ = conversion(temp1);

                            (yyval.inter_code).code = "";
                            (yyval.inter_code).addr = "";
                            (yyval.inter_code).true_l = "";
                            (yyval.inter_code).false_l = "";
                            (yyval.inter_code).sym_tab_info = "";


                          }
    break;

  case 11:
#line 245 "test1_y.y"
    {
                            // vector<string> temp1{$1,$2,$3}; 
                            // $$ = conversion(temp1);

                            vector<string> gen_int_code{(yyvsp[(2) - (3)].inter_code).code,(yyvsp[(3) - (3)].inter_code).code};
                            (yyval.inter_code).code = conversion(gen_int_code);

                            (yyval.inter_code).addr = (yyvsp[(2) - (3)].inter_code).addr;
                            (yyval.inter_code).true_l = (yyvsp[(2) - (3)].inter_code).true_l;
                            (yyval.inter_code).false_l = (yyvsp[(2) - (3)].inter_code).false_l;
                            
                            vector<string> temp_sym_tab{(yyvsp[(2) - (3)].inter_code).sym_tab_info,(yyvsp[(3) - (3)].inter_code).sym_tab_info};
                            (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);


                          }
    break;

  case 12:
#line 266 "test1_y.y"
    {
                      (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
                      (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
                      (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
                      (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
                      (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;


                    }
    break;

  case 13:
#line 277 "test1_y.y"
    {
                      (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
                      (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
                      (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
                      (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
                      (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;


                    }
    break;

  case 14:
#line 289 "test1_y.y"
    {
                       vector<string> temp1{(yyvsp[(1) - (2)].text),(yyvsp[(2) - (2)].text)}; 
                       (yyval.inter_code).code = conversion(temp1);

                       (yyval.inter_code).addr = "";
                       (yyval.inter_code).true_l = "";
                       (yyval.inter_code).false_l = "";
                       (yyval.inter_code).sym_tab_info = "";

                       
                     }
    break;

  case 15:
#line 303 "test1_y.y"
    {
                    (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
                    (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
                    (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
                    (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
                    (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;


                    //printf("\n\n\n\n expr Generated Intermediate Code: \n %s\n\n\n",$$.code);

                  }
    break;

  case 16:
#line 316 "test1_y.y"
    {
                    (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
                    (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
                    (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
                    (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
                    (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;


                  }
    break;

  case 17:
#line 328 "test1_y.y"
    {
                                if(!test.declaration_exists((yyvsp[(1) - (3)].text), scope_count))
                                {
                                    test.insert((yyvsp[(1) - (3)].text), (yylsp[(1) - (3)]).first_line, (yyvsp[(3) - (3)].inter_code).sym_tab_info, scope_count, (yylsp[(1) - (3)]).first_column);
                                }
                                else
                                {
                                    int temp2 = test.update_identifier((yyvsp[(1) - (3)].text), scope_count, (yyvsp[(3) - (3)].inter_code).sym_tab_info);
                                }

                                //vector<string> temp1{$1,$2,$3}; 
                                //$$ = conversion(temp1); 

                                vector<string> gen_int_code{(yyvsp[(3) - (3)].inter_code).code,(yyvsp[(1) - (3)].text),"=",(yyvsp[(3) - (3)].inter_code).addr,"\n"};
                                (yyval.inter_code).code = conversion(gen_int_code);

                                #if DEBUG
                                printf("\ninside assignment expression: %s\n",(yyval.inter_code).code);
                                printf("\n$3:%s\n$1:%s\n$2:%s\n$3.addr:%s\n",(yyvsp[(3) - (3)].inter_code).code,(yyvsp[(1) - (3)].text),(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).addr);
                                #endif

                                (yyval.inter_code).addr = (yyvsp[(3) - (3)].inter_code).addr;
                                (yyval.inter_code).true_l = (yyvsp[(3) - (3)].inter_code).true_l;
                                (yyval.inter_code).false_l = (yyvsp[(3) - (3)].inter_code).false_l;
                                
                                vector<string> temp_sym_tab{(yyvsp[(1) - (3)].text),"=",(yyvsp[(3) - (3)].inter_code).sym_tab_info};
                                (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

                                push_quad(ptr_quad, "=", (yyvsp[(3) - (3)].inter_code).addr, "", (yyvsp[(1) - (3)].text));


                          }
    break;

  case 18:
#line 363 "test1_y.y"
    {
                    (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
                    (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
                    (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
                    (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
                    (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;

                  }
    break;

  case 19:
#line 373 "test1_y.y"
    {
                    vector<string> temp1{(yyvsp[(1) - (3)].text),(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].text)}; 
                    (yyval.inter_code).code = "";
                    (yyval.inter_code).addr = conversion(temp1);
                    (yyval.inter_code).true_l = "";
                    (yyval.inter_code).false_l = "";
                    (yyval.inter_code).sym_tab_info = conversion(temp1);


                  }
    break;

  case 20:
#line 385 "test1_y.y"
    {
                    vector<string> temp1{(yyvsp[(1) - (2)].text),(yyvsp[(2) - (2)].text)}; 
                    (yyval.inter_code).code = "";
                    (yyval.inter_code).addr = conversion(temp1);
                    (yyval.inter_code).true_l = "";
                    (yyval.inter_code).false_l = "";
                    (yyval.inter_code).sym_tab_info = conversion(temp1);

                  }
    break;

  case 21:
#line 397 "test1_y.y"
    {
              // vector<string> temp1{$1,$2,$3}; 
              // $$ = conversion(temp1);

              (yyval.inter_code).addr = (yyvsp[(1) - (3)].inter_code).addr;

              vector<string> gen_int_code{(yyvsp[(1) - (3)].inter_code).code,(yyvsp[(1) - (3)].inter_code).false_l,":\n",(yyvsp[(3) - (3)].inter_code).code,"\n"};
              (yyval.inter_code).code = conversion(gen_int_code);

              vector<string> label_t_temp{(yyvsp[(3) - (3)].inter_code).true_l,":\n",(yyvsp[(1) - (3)].inter_code).true_l};
              (yyval.inter_code).true_l = conversion(label_t_temp);

              (yyval.inter_code).false_l = (yyvsp[(3) - (3)].inter_code).false_l;

              vector<string> temp_sym_tab{(yyvsp[(1) - (3)].inter_code).sym_tab_info,(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).sym_tab_info};
              (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

              

            }
    break;

  case 22:
#line 418 "test1_y.y"
    {
              (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
              (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
              (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
              (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
              (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;

            }
    break;

  case 23:
#line 429 "test1_y.y"
    {
              // vector<string> temp1{$1,$2,$3}; 
              // $$ = conversion(temp1);

              (yyval.inter_code).addr = (yyvsp[(1) - (3)].inter_code).addr;

              vector<string> gen_int_code{(yyvsp[(1) - (3)].inter_code).code,(yyvsp[(1) - (3)].inter_code).true_l,":\n",(yyvsp[(3) - (3)].inter_code).code,"\n"};
              (yyval.inter_code).code = conversion(gen_int_code);

              vector<string> label_t_temp{(yyvsp[(3) - (3)].inter_code).false_l,":\n",(yyvsp[(1) - (3)].inter_code).false_l};
              (yyval.inter_code).false_l = conversion(label_t_temp);

              (yyval.inter_code).true_l = (yyvsp[(3) - (3)].inter_code).true_l;

              vector<string> temp_sym_tab{(yyvsp[(1) - (3)].inter_code).sym_tab_info,(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).sym_tab_info};
              (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);


            }
    break;

  case 24:
#line 449 "test1_y.y"
    {
              (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
              (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
              (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
              (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
              (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;

            }
    break;

  case 25:
#line 460 "test1_y.y"
    {
              // vector<string> temp1{$1,$2,$3}; 
              // $$ = conversion(temp1);

              (yyval.inter_code).false_l = (yyvsp[(2) - (2)].inter_code).true_l;
              (yyval.inter_code).true_l = (yyvsp[(2) - (2)].inter_code).false_l;
              (yyval.inter_code).code = (yyvsp[(2) - (2)].inter_code).code;
              (yyval.inter_code).addr = (yyvsp[(2) - (2)].inter_code).addr;
              vector<string> temp_sym_tab{(yyvsp[(1) - (2)].text),(yyvsp[(2) - (2)].inter_code).sym_tab_info};
              (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);
              
            }
    break;

  case 26:
#line 474 "test1_y.y"
    {
              (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
              (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
              (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
              (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
              (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;

            }
    break;

  case 27:
#line 485 "test1_y.y"
    {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                (yyval.inter_code).true_l = t2;

                string temp_l_2 = to_string(label_no);
                string l_no_2 = "L";
                temp_l_2 = l_no_2 + temp_l_2;
                char *t3 = new char[temp_l_2.size() + 1];
                copy(temp_l_2.begin(),temp_l_2.end(), t3);

                ++label_no;
                
                (yyval.inter_code).false_l = t3;

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t4 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t4);

                (yyval.inter_code).addr = t4;

                ++temp_no;

                vector<string> gen_int_code{(yyvsp[(1) - (3)].inter_code).code,(yyvsp[(3) - (3)].inter_code).code,t4,"=",(yyvsp[(1) - (3)].inter_code).addr,(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).addr,"\n","if",t4,"goto",(yyval.inter_code).true_l,"\n","goto",(yyval.inter_code).false_l,"\n"};
                (yyval.inter_code).code = conversion(gen_int_code);

                string temp_val = string((yyvsp[(1) - (3)].inter_code).addr) + string((yyvsp[(2) - (3)].text)) + string((yyvsp[(3) - (3)].inter_code).addr);

                test.insert(temp, (yylsp[(1) - (3)]).first_line, temp_val, scope_count, (yylsp[(1) - (3)]).first_column);

                vector<string> temp_sym_tab{(yyvsp[(1) - (3)].inter_code).sym_tab_info,(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).sym_tab_info};
                (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, (yyvsp[(2) - (3)].text), (yyvsp[(1) - (3)].inter_code).addr, (yyvsp[(3) - (3)].inter_code).addr, t4);
                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "if", t4, "", t2);
                push_quad(ptr_quad, "Label", "", "", t3);
                push_quad(ptr_quad, "goto", "", "", t3);

              }
    break;

  case 28:
#line 538 "test1_y.y"
    {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                (yyval.inter_code).true_l = t2;

                string temp_l_2 = to_string(label_no);
                string l_no_2 = "L";
                temp_l_2 = l_no_2 + temp_l_2;
                char *t3 = new char[temp_l_2.size() + 1];
                copy(temp_l_2.begin(),temp_l_2.end(), t3);

                ++label_no;
                
                (yyval.inter_code).false_l = t3;

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t4 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t4);

                (yyval.inter_code).addr = t4;

                ++temp_no;

                vector<string> gen_int_code{(yyvsp[(1) - (3)].inter_code).code,(yyvsp[(3) - (3)].inter_code).code,t4,"=",(yyvsp[(1) - (3)].inter_code).addr,(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).addr,"\n","if",t4,"goto",(yyval.inter_code).true_l,"\n","goto",(yyval.inter_code).false_l,"\n"};
                (yyval.inter_code).code = conversion(gen_int_code);

                string temp_val = string((yyvsp[(1) - (3)].inter_code).addr) + string((yyvsp[(2) - (3)].text)) + string((yyvsp[(3) - (3)].inter_code).addr);

                test.insert(temp, (yylsp[(1) - (3)]).first_line, temp_val, scope_count, (yylsp[(1) - (3)]).first_column);

                vector<string> temp_sym_tab{(yyvsp[(1) - (3)].inter_code).sym_tab_info,(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).sym_tab_info};
                (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, (yyvsp[(2) - (3)].text), (yyvsp[(1) - (3)].inter_code).addr, (yyvsp[(3) - (3)].inter_code).addr, t4);
                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "if", t4, "", t2);
                push_quad(ptr_quad, "Label", "", "", t3);
                push_quad(ptr_quad, "goto", "", "", t3);

              }
    break;

  case 29:
#line 591 "test1_y.y"
    {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                (yyval.inter_code).true_l = t2;

                string temp_l_2 = to_string(label_no);
                string l_no_2 = "L";
                temp_l_2 = l_no_2 + temp_l_2;
                char *t3 = new char[temp_l_2.size() + 1];
                copy(temp_l_2.begin(),temp_l_2.end(), t3);

                ++label_no;
                
                (yyval.inter_code).false_l = t3;

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t4 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t4);

                (yyval.inter_code).addr = t4;

                ++temp_no;

                vector<string> gen_int_code{(yyvsp[(1) - (3)].inter_code).code,(yyvsp[(3) - (3)].inter_code).code,t4,"=",(yyvsp[(1) - (3)].inter_code).addr,(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).addr,"\n","if",t4,"goto",(yyval.inter_code).true_l,"\n","goto",(yyval.inter_code).false_l,"\n"};
                (yyval.inter_code).code = conversion(gen_int_code);

                string temp_val = string((yyvsp[(1) - (3)].inter_code).addr) + string((yyvsp[(2) - (3)].text)) + string((yyvsp[(3) - (3)].inter_code).addr);

                test.insert(temp, (yylsp[(1) - (3)]).first_line, temp_val, scope_count, (yylsp[(1) - (3)]).first_column);

                vector<string> temp_sym_tab{(yyvsp[(1) - (3)].inter_code).sym_tab_info,(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).sym_tab_info};
                (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, (yyvsp[(2) - (3)].text), (yyvsp[(1) - (3)].inter_code).addr, (yyvsp[(3) - (3)].inter_code).addr, t4);
                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "if", t4, "", t2);
                push_quad(ptr_quad, "Label", "", "", t3);
                push_quad(ptr_quad, "goto", "", "", t3);

              }
    break;

  case 30:
#line 644 "test1_y.y"
    {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                (yyval.inter_code).true_l = t2;

                string temp_l_2 = to_string(label_no);
                string l_no_2 = "L";
                temp_l_2 = l_no_2 + temp_l_2;
                char *t3 = new char[temp_l_2.size() + 1];
                copy(temp_l_2.begin(),temp_l_2.end(), t3);

                ++label_no;
                
                (yyval.inter_code).false_l = t3;

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t4 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t4);

                (yyval.inter_code).addr = t4;

                ++temp_no;

                vector<string> gen_int_code{(yyvsp[(1) - (3)].inter_code).code,(yyvsp[(3) - (3)].inter_code).code,t4,"=",(yyvsp[(1) - (3)].inter_code).addr,(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).addr,"\n","if",t4,"goto",(yyval.inter_code).true_l,"\n","goto",(yyval.inter_code).false_l,"\n"};
                (yyval.inter_code).code = conversion(gen_int_code);

                string temp_val = string((yyvsp[(1) - (3)].inter_code).addr) + string((yyvsp[(2) - (3)].text)) + string((yyvsp[(3) - (3)].inter_code).addr);

                test.insert(temp, (yylsp[(1) - (3)]).first_line, temp_val, scope_count, (yylsp[(1) - (3)]).first_column);

                vector<string> temp_sym_tab{(yyvsp[(1) - (3)].inter_code).sym_tab_info,(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).sym_tab_info};
                (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, (yyvsp[(2) - (3)].text), (yyvsp[(1) - (3)].inter_code).addr, (yyvsp[(3) - (3)].inter_code).addr, t4);
                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "if", t4, "", t2);
                push_quad(ptr_quad, "Label", "", "", t3);
                push_quad(ptr_quad, "goto", "", "", t3);
              
              }
    break;

  case 31:
#line 697 "test1_y.y"
    {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                (yyval.inter_code).true_l = t2;

                string temp_l_2 = to_string(label_no);
                string l_no_2 = "L";
                temp_l_2 = l_no_2 + temp_l_2;
                char *t3 = new char[temp_l_2.size() + 1];
                copy(temp_l_2.begin(),temp_l_2.end(), t3);

                ++label_no;
                
                (yyval.inter_code).false_l = t3;

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t4 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t4);

                (yyval.inter_code).addr = t4;

                ++temp_no;

                vector<string> gen_int_code{(yyvsp[(1) - (3)].inter_code).code,(yyvsp[(3) - (3)].inter_code).code,t4,"=",(yyvsp[(1) - (3)].inter_code).addr,(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).addr,"\n","if",t4,"goto",(yyval.inter_code).true_l,"\n","goto",(yyval.inter_code).false_l,"\n"};
                (yyval.inter_code).code = conversion(gen_int_code);

                string temp_val = string((yyvsp[(1) - (3)].inter_code).addr) + string((yyvsp[(2) - (3)].text)) + string((yyvsp[(3) - (3)].inter_code).addr);

                test.insert(temp, (yylsp[(1) - (3)]).first_line, temp_val, scope_count, (yylsp[(1) - (3)]).first_column);

                vector<string> temp_sym_tab{(yyvsp[(1) - (3)].inter_code).sym_tab_info,(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).sym_tab_info};
                (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, (yyvsp[(2) - (3)].text), (yyvsp[(1) - (3)].inter_code).addr, (yyvsp[(3) - (3)].inter_code).addr, t4);
                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "if", t4, "", t2);
                push_quad(ptr_quad, "Label", "", "", t3);
                push_quad(ptr_quad, "goto", "", "", t3);
              
              }
    break;

  case 32:
#line 750 "test1_y.y"
    {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                (yyval.inter_code).true_l = t2;

                string temp_l_2 = to_string(label_no);
                string l_no_2 = "L";
                temp_l_2 = l_no_2 + temp_l_2;
                char *t3 = new char[temp_l_2.size() + 1];
                copy(temp_l_2.begin(),temp_l_2.end(), t3);

                ++label_no;
                
                (yyval.inter_code).false_l = t3;

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t4 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t4);

                (yyval.inter_code).addr = t4;

                ++temp_no;

                vector<string> gen_int_code{(yyvsp[(1) - (3)].inter_code).code,(yyvsp[(3) - (3)].inter_code).code,t4,"=",(yyvsp[(1) - (3)].inter_code).addr,(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).addr,"\n","if",t4,"goto",(yyval.inter_code).true_l,"\n","goto",(yyval.inter_code).false_l,"\n"};
                (yyval.inter_code).code = conversion(gen_int_code);

                string temp_val = string((yyvsp[(1) - (3)].inter_code).addr) + string((yyvsp[(2) - (3)].text)) + string((yyvsp[(3) - (3)].inter_code).addr);

                test.insert(temp, (yylsp[(1) - (3)]).first_line, temp_val, scope_count, (yylsp[(1) - (3)]).first_column);

                vector<string> temp_sym_tab{(yyvsp[(1) - (3)].inter_code).sym_tab_info,(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).sym_tab_info};
                (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, (yyvsp[(2) - (3)].text), (yyvsp[(1) - (3)].inter_code).addr, (yyvsp[(3) - (3)].inter_code).addr, t4);
                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "if", t4, "", t2);
                push_quad(ptr_quad, "Label", "", "", t3);
                push_quad(ptr_quad, "goto", "", "", t3);
              
              }
    break;

  case 33:
#line 803 "test1_y.y"
    {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                (yyval.inter_code).true_l = t2;

                string temp_l_2 = to_string(label_no);
                string l_no_2 = "L";
                temp_l_2 = l_no_2 + temp_l_2;
                char *t3 = new char[temp_l_2.size() + 1];
                copy(temp_l_2.begin(),temp_l_2.end(), t3);

                ++label_no;
                
                (yyval.inter_code).false_l = t3;

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t4 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t4);

                (yyval.inter_code).addr = t4;

                ++temp_no;

                vector<string> gen_int_code{(yyvsp[(1) - (3)].inter_code).code,(yyvsp[(3) - (3)].inter_code).code,t4,"=",(yyvsp[(1) - (3)].inter_code).addr,(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).addr,"\n","if",t4,"goto",(yyval.inter_code).true_l,"\n","goto",(yyval.inter_code).false_l,"\n"};
                (yyval.inter_code).code = conversion(gen_int_code);

                string temp_val = string((yyvsp[(1) - (3)].inter_code).addr) + string((yyvsp[(2) - (3)].text)) + string((yyvsp[(3) - (3)].inter_code).addr);

                test.insert(temp, (yylsp[(1) - (3)]).first_line, temp_val, scope_count, (yylsp[(1) - (3)]).first_column);

                vector<string> temp_sym_tab{(yyvsp[(1) - (3)].inter_code).sym_tab_info,(yyvsp[(2) - (3)].text),(yyvsp[(3) - (3)].inter_code).sym_tab_info};
                (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, (yyvsp[(2) - (3)].text), (yyvsp[(1) - (3)].inter_code).addr, (yyvsp[(3) - (3)].inter_code).addr, t4);
                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "if", t4, "", t2);
                push_quad(ptr_quad, "Label", "", "", t3);
                push_quad(ptr_quad, "goto", "", "", t3);
              
              }
    break;

  case 34:
#line 856 "test1_y.y"
    {
                (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
                (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
                (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
                (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
                (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;

              }
    break;

  case 35:
#line 867 "test1_y.y"
    {
                //vector<string> temp1{$1,$2,$3}; 
                //$$ = conversion(temp1);

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t2 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t2);

                (yyval.inter_code).addr = t2;

                ++temp_no;

                vector<string> gen_int_code{(yyvsp[(1) - (3)].inter_code).code,(yyvsp[(3) - (3)].inter_code).code,temp,"=",(yyvsp[(1) - (3)].inter_code).addr,"+",(yyvsp[(3) - (3)].inter_code).addr,"\n"};
                (yyval.inter_code).code = conversion(gen_int_code);

                string temp_val = string((yyvsp[(1) - (3)].inter_code).addr) + string("+") + string((yyvsp[(3) - (3)].inter_code).addr);

                test.insert(temp, (yylsp[(1) - (3)]).first_line, temp_val, scope_count, (yylsp[(1) - (3)]).first_column);

                (yyval.inter_code).true_l = (yyvsp[(1) - (3)].inter_code).true_l;
                (yyval.inter_code).false_l = (yyvsp[(1) - (3)].inter_code).false_l;

                vector<string> temp_sym_tab{(yyvsp[(1) - (3)].inter_code).sym_tab_info,"+",(yyvsp[(3) - (3)].inter_code).sym_tab_info};
                (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, "+", (yyvsp[(1) - (3)].inter_code).addr, (yyvsp[(3) - (3)].inter_code).addr, t2);

                #if DEBUG
                printf("\ninside arith exp (plus):\n%s \n\n",(yyval.inter_code).code);
                #endif

              }
    break;

  case 36:
#line 902 "test1_y.y"
    {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t2 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t2);

                (yyval.inter_code).addr = t2;

                ++temp_no;

                vector<string> gen_int_code{(yyvsp[(1) - (3)].inter_code).code,(yyvsp[(3) - (3)].inter_code).code,temp,"=",(yyvsp[(1) - (3)].inter_code).addr,"-",(yyvsp[(3) - (3)].inter_code).addr,"\n"};
                (yyval.inter_code).code = conversion(gen_int_code);

                string temp_val = string((yyvsp[(1) - (3)].inter_code).addr) + string("-") + string((yyvsp[(3) - (3)].inter_code).addr);

                test.insert(temp, (yylsp[(1) - (3)]).first_line, temp_val, scope_count, (yylsp[(1) - (3)]).first_column);

                (yyval.inter_code).true_l = (yyvsp[(1) - (3)].inter_code).true_l;
                (yyval.inter_code).false_l = (yyvsp[(1) - (3)].inter_code).false_l;

                vector<string> temp_sym_tab{(yyvsp[(1) - (3)].inter_code).sym_tab_info,"-",(yyvsp[(3) - (3)].inter_code).sym_tab_info};
                (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, "-", (yyvsp[(1) - (3)].inter_code).addr, (yyvsp[(3) - (3)].inter_code).addr, t2);


              }
    break;

  case 37:
#line 934 "test1_y.y"
    {
                (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
                (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
                (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
                (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
                (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;
              }
    break;

  case 38:
#line 944 "test1_y.y"
    {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t2 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t2);

                (yyval.inter_code).addr = t2;

                ++temp_no;

                vector<string> gen_int_code{(yyvsp[(1) - (3)].inter_code).code,(yyvsp[(3) - (3)].inter_code).code,temp,"=",(yyvsp[(1) - (3)].inter_code).addr,"*",(yyvsp[(3) - (3)].inter_code).addr,"\n"};
                (yyval.inter_code).code = conversion(gen_int_code);

                string temp_val = string((yyvsp[(1) - (3)].inter_code).addr) + string("*") + string((yyvsp[(3) - (3)].inter_code).addr);

                test.insert(temp, (yylsp[(1) - (3)]).first_line, temp_val, scope_count, (yylsp[(1) - (3)]).first_column);

                (yyval.inter_code).true_l = (yyvsp[(1) - (3)].inter_code).true_l;
                (yyval.inter_code).false_l = (yyvsp[(1) - (3)].inter_code).false_l;

                vector<string> temp_sym_tab{(yyvsp[(1) - (3)].inter_code).sym_tab_info,"*",(yyvsp[(3) - (3)].inter_code).sym_tab_info};
                (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, "*", (yyvsp[(1) - (3)].inter_code).addr, (yyvsp[(3) - (3)].inter_code).addr, t2);

              }
    break;

  case 39:
#line 976 "test1_y.y"
    {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t2 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t2);

                (yyval.inter_code).addr = t2;

                ++temp_no;

                vector<string> gen_int_code{(yyvsp[(1) - (3)].inter_code).code,(yyvsp[(3) - (3)].inter_code).code,temp,"=",(yyvsp[(1) - (3)].inter_code).addr,"/",(yyvsp[(3) - (3)].inter_code).addr,"\n"};
                (yyval.inter_code).code = conversion(gen_int_code);

                string temp_val = string((yyvsp[(1) - (3)].inter_code).addr) + string("/") + string((yyvsp[(3) - (3)].inter_code).addr);

                test.insert(temp, (yylsp[(1) - (3)]).first_line, temp_val, scope_count, (yylsp[(1) - (3)]).first_column);

                (yyval.inter_code).true_l = (yyvsp[(1) - (3)].inter_code).true_l;
                (yyval.inter_code).false_l = (yyvsp[(1) - (3)].inter_code).false_l;

                vector<string> temp_sym_tab{(yyvsp[(1) - (3)].inter_code).sym_tab_info,"/",(yyvsp[(3) - (3)].inter_code).sym_tab_info};
                (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, "/", (yyvsp[(1) - (3)].inter_code).addr, (yyvsp[(3) - (3)].inter_code).addr, t2);

              }
    break;

  case 40:
#line 1008 "test1_y.y"
    {
                // vector<string> temp1{$1,$2,$3}; 
                // $$ = conversion(temp1);

                string temp = to_string(temp_no);
                string t_no = "t";
                temp = t_no + temp;
                char *t2 = new char[temp.size() + 1];
                copy(temp.begin(),temp.end(), t2);

                (yyval.inter_code).addr = t2;

                ++temp_no;

                vector<string> gen_int_code{(yyvsp[(1) - (3)].inter_code).code,(yyvsp[(3) - (3)].inter_code).code,temp,"=",(yyvsp[(1) - (3)].inter_code).addr,"%",(yyvsp[(3) - (3)].inter_code).addr,"\n"};
                (yyval.inter_code).code = conversion(gen_int_code);

                string temp_val = string((yyvsp[(1) - (3)].inter_code).addr) + string("%") + string((yyvsp[(3) - (3)].inter_code).addr);

                test.insert(temp, (yylsp[(1) - (3)]).first_line, temp_val, scope_count, (yylsp[(1) - (3)]).first_column);

                (yyval.inter_code).true_l = (yyvsp[(1) - (3)].inter_code).true_l;
                (yyval.inter_code).false_l = (yyvsp[(1) - (3)].inter_code).false_l;

                vector<string> temp_sym_tab{(yyvsp[(1) - (3)].inter_code).sym_tab_info,"%",(yyvsp[(3) - (3)].inter_code).sym_tab_info};
                (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

                push_quad(ptr_quad, "%", (yyvsp[(1) - (3)].inter_code).addr, (yyvsp[(3) - (3)].inter_code).addr, t2);

              }
    break;

  case 41:
#line 1040 "test1_y.y"
    {
                (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
                (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
                (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
                (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
                (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;
              }
    break;

  case 42:
#line 1050 "test1_y.y"
    { 
            // vector<string> temp1{$1,$2}; 
            // $$ = conversion(temp1);

            string temp = to_string(temp_no);
            string t_no = "t";
            temp = t_no + temp;
            char *t2 = new char[temp.size() + 1];
            copy(temp.begin(),temp.end(), t2);

            (yyval.inter_code).addr = t2;

            ++temp_no;

            vector<string> gen_int_code{(yyvsp[(2) - (2)].inter_code).code,temp,"=",(yyvsp[(1) - (2)].text),(yyvsp[(2) - (2)].inter_code).addr,"\n"};
            (yyval.inter_code).code = conversion(gen_int_code);

            string temp_val = string((yyvsp[(1) - (2)].text)) + string((yyvsp[(2) - (2)].inter_code).addr);

            test.insert(temp, (yylsp[(1) - (2)]).first_line, temp_val, scope_count, (yylsp[(1) - (2)]).first_column);

            (yyval.inter_code).true_l = (yyvsp[(2) - (2)].inter_code).true_l;
            (yyval.inter_code).false_l = (yyvsp[(2) - (2)].inter_code).false_l;

            vector<string> temp_sym_tab{(yyvsp[(1) - (2)].text),(yyvsp[(2) - (2)].inter_code).sym_tab_info};
            (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

            push_quad(ptr_quad, (yyvsp[(1) - (2)].text), (yyvsp[(2) - (2)].inter_code).addr, "", t2);

          }
    break;

  case 43:
#line 1082 "test1_y.y"
    {
            // vector<string> temp1{$1,$2}; 
            // $$ = conversion(temp1);

            string temp = to_string(temp_no);
            string t_no = "t";
            temp = t_no + temp;
            char *t2 = new char[temp.size() + 1];
            copy(temp.begin(),temp.end(), t2);

            (yyval.inter_code).addr = t2;

            ++temp_no;

            vector<string> gen_int_code{(yyvsp[(2) - (2)].inter_code).code,temp,"=",(yyvsp[(1) - (2)].text),(yyvsp[(2) - (2)].inter_code).addr,"\n"};
            (yyval.inter_code).code = conversion(gen_int_code);

            string temp_val = string((yyvsp[(1) - (2)].text)) + string((yyvsp[(2) - (2)].inter_code).addr);

            test.insert(temp, (yylsp[(1) - (2)]).first_line, temp_val, scope_count, (yylsp[(1) - (2)]).first_column);

            (yyval.inter_code).true_l = (yyvsp[(2) - (2)].inter_code).true_l;
            (yyval.inter_code).false_l = (yyvsp[(2) - (2)].inter_code).false_l;

            vector<string> temp_sym_tab{(yyvsp[(1) - (2)].text),(yyvsp[(2) - (2)].inter_code).sym_tab_info};
            (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

            push_quad(ptr_quad, (yyvsp[(1) - (2)].text), (yyvsp[(2) - (2)].inter_code).addr, "", t2);
            
          }
    break;

  case 44:
#line 1113 "test1_y.y"
    {
            (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
            (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
            (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
            (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
            (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;
          }
    break;

  case 45:
#line 1123 "test1_y.y"
    {
              if(!test.declaration_exists((yyvsp[(1) - (1)].text), scope_count))
              {
                  flag = 0;
                  printf("\n\nvariable \'%s\' not declared before\n\n\n",(yyvsp[(1) - (1)].text));
                  yyerror("Undeclared variable");
              }
              (yyval.inter_code).addr = (yyvsp[(1) - (1)].text);
              (yyval.inter_code).code = "";
              (yyval.inter_code).true_l = "";
              (yyval.inter_code).false_l = "";
              (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].text);

          }
    break;

  case 46:
#line 1138 "test1_y.y"
    {
            (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
            (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
            (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
            (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
            (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;

          }
    break;

  case 47:
#line 1148 "test1_y.y"
    {
            (yyval.inter_code).code = (yyvsp[(1) - (1)].text);
            (yyval.inter_code).addr = "";
            (yyval.inter_code).true_l = "";
            (yyval.inter_code).false_l = "";
            (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].text);

          }
    break;

  case 48:
#line 1158 "test1_y.y"
    {
            // vector<string> temp1{$1,$2,$3}; 
            // $$ = conversion(temp1);

            (yyval.inter_code).code = (yyvsp[(2) - (3)].inter_code).code;
            (yyval.inter_code).addr = (yyvsp[(2) - (3)].inter_code).addr;
            (yyval.inter_code).true_l = (yyvsp[(2) - (3)].inter_code).true_l;
            (yyval.inter_code).false_l = (yyvsp[(2) - (3)].inter_code).false_l;

            vector<string> temp_sym_tab{(yyvsp[(1) - (3)].text),(yyvsp[(2) - (3)].inter_code).sym_tab_info,(yyvsp[(3) - (3)].text)};
            (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

          }
    break;

  case 49:
#line 1174 "test1_y.y"
    {
                (yyval.inter_code).addr = (yyvsp[(1) - (1)].text);
                (yyval.inter_code).code = "";
                (yyval.inter_code).true_l = "";
                (yyval.inter_code).false_l = "";
                (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].text);

              }
    break;

  case 50:
#line 1184 "test1_y.y"
    {
                (yyval.inter_code).addr = (yyvsp[(1) - (1)].text);
                (yyval.inter_code).code = "";
                (yyval.inter_code).true_l = "";
                (yyval.inter_code).false_l = "";
                (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].text);

              }
    break;

  case 51:
#line 1194 "test1_y.y"
    {
                (yyval.inter_code).addr = (yyvsp[(1) - (1)].text);

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                (yyval.inter_code).true_l = t2;

                (yyval.inter_code).false_l = "";

                vector<string> gen_int_code{"goto",(yyval.inter_code).true_l,"\n"};
                (yyval.inter_code).code = conversion(gen_int_code);

                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "goto", "", "", t2);

                (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].text);

              }
    break;

  case 52:
#line 1220 "test1_y.y"
    {
                (yyval.inter_code).addr = (yyvsp[(1) - (1)].text);

                (yyval.inter_code).true_l = "";

                string temp_l = to_string(label_no);
                string l_no = "L";
                temp_l = l_no + temp_l;
                char *t2 = new char[temp_l.size() + 1];
                copy(temp_l.begin(),temp_l.end(), t2);

                ++label_no;
                
                (yyval.inter_code).false_l = t2;

                vector<string> gen_int_code{"goto",(yyval.inter_code).false_l,"\n"};
                (yyval.inter_code).code = conversion(gen_int_code);

                push_quad(ptr_quad, "Label", "", "", t2);
                push_quad(ptr_quad, "goto", "", "", t2);

                (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].text);

              }
    break;

  case 53:
#line 1247 "test1_y.y"
    {
                if(!test.declaration_exists((yyvsp[(1) - (4)].text), scope_count))
                {
                    flag = 0;
                    printf("\n\nvariable \' %s \' not declared before\n\n\n",(yyvsp[(1) - (4)].text));
                    yyerror("Undeclared variable");

                }

                vector<string> temp1{(yyvsp[(1) - (4)].text),(yyvsp[(2) - (4)].text),(yyvsp[(3) - (4)].inter_code).code,(yyvsp[(4) - (4)].text)}; 
                (yyval.text) = conversion(temp1);
                  
              }
    break;

  case 54:
#line 1264 "test1_y.y"
    {
                        (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
                        (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
                        (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
                        (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
                        (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;

                        #if DEBUG
                        printf("\n\ninside compound statement(if):\n\n");
                        printf("%s\n\n",(yyval.inter_code).code);
                        #endif
                      }
    break;

  case 55:
#line 1278 "test1_y.y"
    {
                        (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
                        (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
                        (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
                        (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
                        (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;
                      }
    break;

  case 56:
#line 1288 "test1_y.y"
    {
                    string temp_l = to_string(label_no);
                    string l_no = "L";
                    temp_l = l_no + temp_l;
                    char *t2 = new char[temp_l.size() + 1];
                    copy(temp_l.begin(),temp_l.end(), t2);

                    ++label_no;
                
                    (yyval.inter_code).true_l = t2;

                    int ret_elif = strcmp((yyvsp[(5) - (6)].inter_code).code,"");
                    int ret_else = strcmp((yyvsp[(6) - (6)].inter_code).code,"");

                    //there exists both elif and else statements
                    if(ret_elif!=0 && ret_else!=0)
                    {
                      #if DEBUG
                      printf("\n\n\ntest1\n\n\n");
                      #endif
                      vector<string> gen_int_code{(yyvsp[(2) - (6)].inter_code).code,(yyvsp[(2) - (6)].inter_code).true_l,":\n",(yyvsp[(4) - (6)].inter_code).code,"goto ",t2,"\n",(yyvsp[(2) - (6)].inter_code).false_l,":\n",(yyvsp[(5) - (6)].inter_code).code,(yyvsp[(6) - (6)].inter_code).code,t2,":\n"};
                      (yyval.inter_code).code = conversion(gen_int_code);

                      push_quad(ptr_quad, "Label", "", "", t2);
                      push_quad(ptr_quad, "goto", "", "", t2);

                    }

                    //there exists only elif but no else statement
                    else if(ret_elif!=0 && ret_else==0)
                    {
                      #if DEBUG
                      printf("\n\n\ntest2\n\n\n");
                      #endif
                      vector<string> gen_int_code{(yyvsp[(2) - (6)].inter_code).code,(yyvsp[(2) - (6)].inter_code).true_l,":\n",(yyvsp[(4) - (6)].inter_code).code,"goto ",t2,"\n",(yyvsp[(2) - (6)].inter_code).false_l,":\n",(yyvsp[(5) - (6)].inter_code).code,"goto ",t2,"\n",t2,":\n"};
                      (yyval.inter_code).code = conversion(gen_int_code);

                      push_quad(ptr_quad, "Label", "", "", t2);
                      push_quad(ptr_quad, "goto", "", "", t2);

                    }

                    //there exists no elif statement but there is an else statement
                    else if(ret_elif==0 && ret_else!=0)
                    {
                      #if DEBUG
                      printf("\n\n\ntest3\n\n\n");
                      #endif

                      vector<string> gen_int_code{(yyvsp[(2) - (6)].inter_code).code,(yyvsp[(2) - (6)].inter_code).true_l,":\n",(yyvsp[(4) - (6)].inter_code).code,"goto ",t2,"\n",(yyvsp[(2) - (6)].inter_code).false_l,":\n",(yyvsp[(6) - (6)].inter_code).code,t2,":\n"};
                      (yyval.inter_code).code = conversion(gen_int_code);

                      push_quad(ptr_quad, "Label", "", "", t2);
                      push_quad(ptr_quad, "goto", "", "", t2);

                      #if DEBUG
                      printf("\n\ninside if:\n\n");
                      printf("%s\n",(yyval.inter_code).code);
                      #endif

                    }

                    //both elif and else statements don't exist
                    else if(ret_elif==0 && ret_else==0)
                    {
                      #if DEBUG
                      printf("\n\n\ntest4\n\n\n");
                      #endif

                      vector<string> gen_int_code{(yyvsp[(2) - (6)].inter_code).code,(yyvsp[(2) - (6)].inter_code).true_l,":\n",(yyvsp[(4) - (6)].inter_code).code,(yyvsp[(2) - (6)].inter_code).false_l,":\n"};
                      (yyval.inter_code).code = conversion(gen_int_code);

                      #if DEBUG
                      printf("\n\ninside if:\n\n");
                      printf("%s\n",(yyval.inter_code).code);
                      #endif

                    }

                    (yyval.inter_code).addr = (yyvsp[(2) - (6)].inter_code).addr;
                    (yyval.inter_code).false_l = (yyvsp[(2) - (6)].inter_code).false_l;

                    (yyval.inter_code).sym_tab_info = (yyvsp[(2) - (6)].inter_code).sym_tab_info;


                    
                  }
    break;

  case 57:
#line 1378 "test1_y.y"
    {
            // vector<string> temp1{$1,$2}; 
            // $$ = conversion(temp1);

            (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
            (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
            (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
            (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
            (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;


          }
    break;

  case 58:
#line 1395 "test1_y.y"
    {
            (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
            (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
            (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
            (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
            (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;
          }
    break;

  case 59:
#line 1404 "test1_y.y"
    {
            scope_count += 1;
            test.create_map(scope_count);
          }
    break;

  case 60:
#line 1409 "test1_y.y"
    {
            (yyval.inter_code).code = (yyvsp[(4) - (4)].inter_code).code;
            (yyval.inter_code).addr = (yyvsp[(4) - (4)].inter_code).addr;
            (yyval.inter_code).true_l = (yyvsp[(4) - (4)].inter_code).true_l;
            (yyval.inter_code).false_l = (yyvsp[(4) - (4)].inter_code).false_l;
            (yyval.inter_code).sym_tab_info = (yyvsp[(4) - (4)].inter_code).sym_tab_info;
          }
    break;

  case 61:
#line 1419 "test1_y.y"
    {
                (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
                (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
                (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
                (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
                (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;
              }
    break;

  case 62:
#line 1428 "test1_y.y"
    {
                (yyval.inter_code).code = (yyvsp[(3) - (3)].inter_code).code;
                (yyval.inter_code).addr = (yyvsp[(3) - (3)].inter_code).addr;
                (yyval.inter_code).true_l = (yyvsp[(3) - (3)].inter_code).true_l;
                (yyval.inter_code).false_l = (yyvsp[(3) - (3)].inter_code).false_l;
                (yyval.inter_code).sym_tab_info = (yyvsp[(3) - (3)].inter_code).sym_tab_info;
              }
    break;

  case 63:
#line 1438 "test1_y.y"
    {
              scope_count -= (yyvsp[(2) - (2)].indentation_level);

              (yyval.inter_code).code = (yyvsp[(1) - (2)].inter_code).code;
              (yyval.inter_code).addr = (yyvsp[(1) - (2)].inter_code).addr;
              (yyval.inter_code).true_l = (yyvsp[(1) - (2)].inter_code).true_l;
              (yyval.inter_code).false_l = (yyvsp[(1) - (2)].inter_code).false_l;
              (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (2)].inter_code).sym_tab_info;

          }
    break;

  case 64:
#line 1450 "test1_y.y"
    {
              scope_count -= (yyvsp[(3) - (3)].indentation_level);

              vector<string> gen_int_code{(yyvsp[(1) - (3)].inter_code).code,(yyvsp[(2) - (3)].inter_code).code,"\n"};
              (yyval.inter_code).code = conversion(gen_int_code);

              (yyval.inter_code).addr = (yyvsp[(1) - (3)].inter_code).addr;
              (yyval.inter_code).true_l = (yyvsp[(1) - (3)].inter_code).true_l;
              (yyval.inter_code).false_l = (yyvsp[(1) - (3)].inter_code).false_l;

              vector<string> temp_sym_tab{(yyvsp[(1) - (3)].inter_code).sym_tab_info,(yyvsp[(2) - (3)].inter_code).sym_tab_info};
              (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

              

          }
    break;

  case 65:
#line 1469 "test1_y.y"
    {
                        vector<string> gen_int_code{(yyvsp[(1) - (2)].inter_code).code,(yyvsp[(2) - (2)].inter_code).code,"\n"};
                        (yyval.inter_code).code = conversion(gen_int_code);

                        (yyval.inter_code).addr = (yyvsp[(1) - (2)].inter_code).addr;
                        (yyval.inter_code).true_l = (yyvsp[(1) - (2)].inter_code).true_l;
                        (yyval.inter_code).false_l = (yyvsp[(1) - (2)].inter_code).false_l;

                        vector<string> temp_sym_tab{(yyvsp[(1) - (2)].inter_code).sym_tab_info,(yyvsp[(2) - (2)].inter_code).sym_tab_info};
                        (yyval.inter_code).sym_tab_info = conversion(temp_sym_tab);

                      }
    break;

  case 66:
#line 1483 "test1_y.y"
    {
                        (yyval.inter_code).code = (yyvsp[(1) - (1)].inter_code).code;
                        (yyval.inter_code).addr = (yyvsp[(1) - (1)].inter_code).addr;
                        (yyval.inter_code).true_l = (yyvsp[(1) - (1)].inter_code).true_l;
                        (yyval.inter_code).false_l = (yyvsp[(1) - (1)].inter_code).false_l;
                        (yyval.inter_code).sym_tab_info = (yyvsp[(1) - (1)].inter_code).sym_tab_info;
                      }
    break;

  case 67:
#line 1492 "test1_y.y"
    {
                        (yyval.inter_code).code = (yyvsp[(2) - (2)].inter_code).code;
                        (yyval.inter_code).addr = (yyvsp[(2) - (2)].inter_code).addr;
                        (yyval.inter_code).true_l = (yyvsp[(2) - (2)].inter_code).true_l;
                        (yyval.inter_code).false_l = (yyvsp[(2) - (2)].inter_code).false_l;
                        (yyval.inter_code).sym_tab_info = (yyvsp[(2) - (2)].inter_code).sym_tab_info;
                      }
    break;

  case 68:
#line 1501 "test1_y.y"
    {
                        (yyval.inter_code).code = "";
                        (yyval.inter_code).addr = "";
                        (yyval.inter_code).true_l = "";
                        (yyval.inter_code).false_l = "";
                        (yyval.inter_code).sym_tab_info = "";

                      }
    break;

  case 69:
#line 1511 "test1_y.y"
    {
                    (yyval.inter_code).code = "";
                    (yyval.inter_code).addr = "";
                    (yyval.inter_code).true_l = "";
                    (yyval.inter_code).false_l = "";
                    (yyval.inter_code).sym_tab_info = "";

                  }
    break;

  case 70:
#line 1521 "test1_y.y"
    {

                    string temp_l = to_string(label_no);
                    string l_no = "L";
                    temp_l = l_no + temp_l;
                    char *t2 = new char[temp_l.size() + 1];
                    copy(temp_l.begin(),temp_l.end(), t2);

                    (yyval.inter_code).sym_tab_info = (yyvsp[(2) - (5)].inter_code).sym_tab_info;


                    //no more elif statements
                    if(strcmp((yyvsp[(5) - (5)].inter_code).code,"")==0)
                    {
                      vector<string> gen_int_code{(yyvsp[(2) - (5)].inter_code).code,(yyvsp[(2) - (5)].inter_code).true_l,":\n",(yyvsp[(4) - (5)].inter_code).code,"goto ",t2,"\n",(yyvsp[(2) - (5)].inter_code).false_l,":\n"};
                      (yyval.inter_code).code = conversion(gen_int_code);
                      (yyval.inter_code).addr = "";
                      (yyval.inter_code).true_l = "";
                      (yyval.inter_code).false_l = "";

                    }

                    //contains more elif statements
                    else
                    {
                      vector<string> gen_int_code{(yyvsp[(2) - (5)].inter_code).code,(yyvsp[(2) - (5)].inter_code).true_l,":\n",(yyvsp[(4) - (5)].inter_code).code,"goto ",t2,"\n",(yyvsp[(2) - (5)].inter_code).false_l,":\n",(yyvsp[(5) - (5)].inter_code).code};
                      (yyval.inter_code).code = conversion(gen_int_code);
                      (yyval.inter_code).addr = "";
                      (yyval.inter_code).true_l = "";
                      (yyval.inter_code).false_l = "";

                    }

                  }
    break;

  case 71:
#line 1557 "test1_y.y"
    {
                    (yyval.inter_code).code = "";
                    (yyval.inter_code).addr = "";
                    (yyval.inter_code).true_l = "";
                    (yyval.inter_code).false_l = "";
                    (yyval.inter_code).sym_tab_info = "";

                  }
    break;

  case 72:
#line 1567 "test1_y.y"
    {
                    (yyval.inter_code).code = (yyvsp[(3) - (3)].inter_code).code;
                    (yyval.inter_code).addr = (yyvsp[(3) - (3)].inter_code).addr;
                    (yyval.inter_code).true_l = (yyvsp[(3) - (3)].inter_code).true_l;
                    (yyval.inter_code).false_l = (yyvsp[(3) - (3)].inter_code).false_l;
                    (yyval.inter_code).sym_tab_info = (yyvsp[(3) - (3)].inter_code).sym_tab_info;

                  }
    break;

  case 73:
#line 1578 "test1_y.y"
    {
                    scope_count += 1;
                    test.create_map(scope_count);
                  }
    break;

  case 74:
#line 1583 "test1_y.y"
    {
                    string temp_l = to_string(label_no);
                    string l_no = "L";
                    temp_l = l_no + temp_l;
                    char *t2 = new char[temp_l.size() + 1];
                    copy(temp_l.begin(),temp_l.end(), t2);

                    ++label_no;

                    string temp_l_2 = to_string(label_no);
                    string l_no_2 = "L";
                    temp_l_2 = l_no_2 + temp_l_2;
                    char *t3 = new char[temp_l_2.size() + 1];
                    copy(temp_l_2.begin(),temp_l_2.end(), t3);

                    ++label_no;

                    string temp = to_string(temp_no);
                    string t_no = "t";
                    temp = t_no + temp;
                    char *t4 = new char[temp.size() + 1];
                    copy(temp.begin(),temp.end(), t4);

                    ++temp_no;

                    string temp_2 = to_string(temp_no);
                    string t_no_2 = "t";
                    temp_2 = t_no_2 + temp_2;
                    char *t5 = new char[temp_2.size() + 1];
                    copy(temp_2.begin(),temp_2.end(), t5);

                    ++temp_no;

                    vector<string> gen_int_code{(yyvsp[(3) - (7)].text),"=",(yyvsp[(5) - (7)].range_icg).start_r,"\n",t2,":\n",(yyvsp[(7) - (7)].inter_code).code,temp," = ",(yyvsp[(3) - (7)].text)," + ",(yyvsp[(5) - (7)].range_icg).step_r,"\n",(yyvsp[(3) - (7)].text),"=",temp,"\n",temp_2,"=",(yyvsp[(3) - (7)].text)," < ",(yyvsp[(5) - (7)].range_icg).end_r,"\nif ",temp_2," goto ",t2,"\ngoto ",t3,"\n",t3,":\n"};
                    (yyval.inter_code).code = conversion(gen_int_code);

                    string temp_val_1 = string((yyvsp[(3) - (7)].text)) + string("+") + string((yyvsp[(5) - (7)].range_icg).step_r);
                    test.insert(temp, (yylsp[(1) - (7)]).first_line, temp_val_1, scope_count + 1, (yylsp[(1) - (7)]).first_column);

                    string temp_val_2 = string((yyvsp[(3) - (7)].text)) + string("<") + string((yyvsp[(5) - (7)].range_icg).end_r);
                    test.insert(temp_2, (yylsp[(1) - (7)]).first_line, temp_val_2, scope_count + 1, (yylsp[(1) - (7)]).first_column);

                    push_quad(ptr_quad, "=",(yyvsp[(5) - (7)].range_icg).start_r, "", (yyvsp[(3) - (7)].text));

                    push_quad(ptr_quad, "+", (yyvsp[(3) - (7)].text), (yyvsp[(5) - (7)].range_icg).step_r, t4);
                    push_quad(ptr_quad, "=",t4, "", (yyvsp[(3) - (7)].text));

                    push_quad(ptr_quad, "<", (yyvsp[(3) - (7)].text), (yyvsp[(5) - (7)].range_icg).end_r, t5);
                                        
                    push_quad(ptr_quad, "Label", "", "", t2);
                    push_quad(ptr_quad, "if", t4, "", t2);
                    push_quad(ptr_quad, "Label", "", "", t3);
                    push_quad(ptr_quad, "goto", "", "", t3);

                    (yyval.inter_code).addr = "";
                    (yyval.inter_code).true_l = "";
                    (yyval.inter_code).false_l = "";

                    #if DEBUG
                    printf("\nprinting start of range(inside for block action rule: %s\n\n",(yyvsp[(5) - (7)].range_icg).start_r);
                    #endif

                    

                    test.insert((yyvsp[(3) - (7)].text), (yylsp[(3) - (7)]).first_line, (yyvsp[(5) - (7)].range_icg).start_r , scope_count + 1, (yylsp[(3) - (7)]).first_column);
                    

                    #if DEBUG
                    printf("scope count%d\n",scope_count);
                    int temp2 = test.update_identifier((yyvsp[(3) - (7)].text), scope_count, (yyvsp[(5) - (7)].range_icg).start_r);
                    int temp3 = test.declaration_exists((yyvsp[(3) - (7)].text), scope_count);
                    printf("\nprinting dec exists: %d\n\n",temp3);
                    printf("\nprinting identifier: %s\n",(yyvsp[(3) - (7)].text));
                    printf("\nprinting return value of updating symbol table %d\n\n",temp2);
                    #endif

                    (yyval.inter_code).sym_tab_info = "";
                    

                  }
    break;

  case 75:
#line 1666 "test1_y.y"
    {
                (yyval.text) = (yyvsp[(1) - (2)].text);
              }
    break;

  case 76:
#line 1672 "test1_y.y"
    {
                    (yyval.text) = (yyvsp[(1) - (1)].text);
                  }
    break;

  case 77:
#line 1677 "test1_y.y"
    {(yyval.text) = empty_string;}
    break;

  case 79:
#line 1680 "test1_y.y"
    {
                    (yyval.text) = (yyvsp[(2) - (3)].text);
                  }
    break;

  case 80:
#line 1686 "test1_y.y"
    {
                (yyval.range_icg).start_r = (yyvsp[(1) - (1)].range_icg).start_r;
                (yyval.range_icg).end_r = (yyvsp[(1) - (1)].range_icg).end_r;
                (yyval.range_icg).step_r = (yyvsp[(1) - (1)].range_icg).step_r;

              }
    break;

  case 81:
#line 1697 "test1_y.y"
    {
            //  vector<string> temp1{$1,$2,$3,$4}; 
            //  $$ = conversion(temp1);

            (yyval.range_icg).start_r = "0";
            (yyval.range_icg).end_r = (yyvsp[(3) - (4)].text);
            (yyval.range_icg).step_r = "1";

           }
    break;

  case 82:
#line 1708 "test1_y.y"
    {
            //  vector<string> temp1{$1,$2,$3,$4,$5,$6}; 
            //  $$ = conversion(temp1);

            (yyval.range_icg).start_r = (yyvsp[(3) - (6)].text);
            (yyval.range_icg).end_r = (yyvsp[(5) - (6)].text);
            (yyval.range_icg).step_r = "1";

           }
    break;

  case 83:
#line 1719 "test1_y.y"
    {
            //  vector<string> temp1{$1,$2,$3,$4,$5,$6,$7,$8}; 
            //  $$ = conversion(temp1);

            (yyval.range_icg).start_r = (yyvsp[(3) - (8)].text);
            (yyval.range_icg).end_r = (yyvsp[(5) - (8)].text);
            (yyval.range_icg).step_r = (yyvsp[(7) - (8)].text);

           }
    break;

  case 84:
#line 1731 "test1_y.y"
    {
                  if(!test.declaration_exists((yyvsp[(1) - (1)].text), scope_count))
                  {
                      flag = 0;
                      printf("\n\nvariable \'%s\' not declared before\n",(yyvsp[(1) - (1)].text));
                      yyerror("Undeclared Variable");
                      
                  }

                  (yyval.text) = (yyvsp[(1) - (1)].text);
              }
    break;

  case 85:
#line 1744 "test1_y.y"
    {
                (yyval.text) = (yyvsp[(1) - (1)].text);
              }
    break;

  case 86:
#line 1749 "test1_y.y"
    {
                (yyval.text) = (yyvsp[(1) - (1)].text);
              }
    break;


/* Line 1267 of yacc.c.  */
#line 3436 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1759 "test1_y.y"


void yyerror(const char *error_msg)
{
    printf("\nSyntax Error at Line %d, Column : %d %s\n",  yylineno, yylloc.last_column,error_msg);
    exit(0);
}

#include<stdio.h>
extern char yytext[];
extern int column;

int main()
{

    #ifdef YYDEBUG
      yydebug = 1;
    #endif

    scope_count = 0;

    ptr_my_stack = (my_stack_t*)malloc(sizeof(my_stack_t));
    init(ptr_my_stack);
    push(ptr_my_stack,0);

    ptr_quad = (quadruple_t*)malloc(sizeof(quadruple_t));
    init_quad(ptr_quad);




    if (!yyparse() && flag) 
    {
        printf("\n\n\nParsing is successful\n\n\n");
    } 
    else 
    {
        printf("\n\nParsing is unsuccessful\n\n");
    }
            
    cout<<"SYMBOL TABLE: \n";
    cout << test;

    cout<<"\n\n\n\nGenerated Intermediate Code: \n\n" << final_int_code << "\n\n\n";
    FILE *fp = fopen("generated_intermediate_code.txt","w");

    if(fp!=NULL)
    {
      fputs(final_int_code.c_str(),fp);
    }
    else
    {
      printf("\nError: Unable to open file\n");
    }

    disp_quad(ptr_quad,1);
    disp_quad(ptr_quad,0);
        
    return 0;

}
