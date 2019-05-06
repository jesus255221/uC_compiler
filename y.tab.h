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
     PRINT = 258,
     IF = 259,
     ELSE = 260,
     FOR = 261,
     WHILE = 262,
     SEMICOLON = 263,
     COMMA = 264,
     INC = 265,
     DEC = 266,
     ASGN = 267,
     ADDASGN = 268,
     SUBASGN = 269,
     MULASGN = 270,
     DIVASGN = 271,
     MODASGN = 272,
     LT = 273,
     MT = 274,
     LTE = 275,
     MTE = 276,
     EQ = 277,
     NE = 278,
     AND = 279,
     OR = 280,
     NOT = 281,
     RTN = 282,
     CONTINUE = 283,
     BREAK = 284,
     LB = 285,
     RB = 286,
     LSB = 287,
     RSB = 288,
     LCB = 289,
     RCB = 290,
     QUOTA = 291,
     STR_CONST = 292,
     INT = 293,
     FLOAT = 294,
     BOOL = 295,
     VOID = 296,
     STRING = 297,
     LOWER_THAN_ELSE = 298,
     SUB = 299,
     ADD = 300,
     MOD = 301,
     DIV = 302,
     MUL = 303,
     I_CONST = 304,
     F_CONST = 305,
     TRUE = 306,
     FALSE = 307,
     ID = 308
   };
#endif
/* Tokens.  */
#define PRINT 258
#define IF 259
#define ELSE 260
#define FOR 261
#define WHILE 262
#define SEMICOLON 263
#define COMMA 264
#define INC 265
#define DEC 266
#define ASGN 267
#define ADDASGN 268
#define SUBASGN 269
#define MULASGN 270
#define DIVASGN 271
#define MODASGN 272
#define LT 273
#define MT 274
#define LTE 275
#define MTE 276
#define EQ 277
#define NE 278
#define AND 279
#define OR 280
#define NOT 281
#define RTN 282
#define CONTINUE 283
#define BREAK 284
#define LB 285
#define RB 286
#define LSB 287
#define RSB 288
#define LCB 289
#define RCB 290
#define QUOTA 291
#define STR_CONST 292
#define INT 293
#define FLOAT 294
#define BOOL 295
#define VOID 296
#define STRING 297
#define LOWER_THAN_ELSE 298
#define SUB 299
#define ADD 300
#define MOD 301
#define DIV 302
#define MUL 303
#define I_CONST 304
#define F_CONST 305
#define TRUE 306
#define FALSE 307
#define ID 308




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 56 "compiler_hw2.y"
{
    int i_val;
    double f_val;
    bool b_val;
    char *type;
    char *name;
}
/* Line 1529 of yacc.c.  */
#line 163 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

