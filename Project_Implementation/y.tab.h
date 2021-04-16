/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 53 "test1_y.y"
{
    int indentation_level;
    char *text;

    struct s1 {char *addr; char *code; char *true_l; char *false_l; char *sym_tab_info;} inter_code;

    struct s2 {char *start_r; char *end_r; char *step_r; char *sym_tab_info;} range_icg;

}
/* Line 1529 of yacc.c.  */
#line 139 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;
