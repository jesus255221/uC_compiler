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
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw2.y"

    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <string.h>
    #define MAX_SYMBOL 1024
    #define MAX_SCOPE 1024

    extern int yylineno;
    extern int yylex();
    extern void yyerror(char*);
    extern char* yytext;   // Get current token from lex
    extern char buf[256];  // Get current code line from lex

    int Scope_num = 0;

    typedef struct symbol {
        int Index;
        int Scope;
        char *Name, *Kind, *Type, *Attribute;
        // union {
        //     int i_value;
        //     double f_value;
        //     char* s_value;
        //     bool b_value;
        // };
        struct symbol* next_node;
    } Symbol;

    typedef struct scope {
        int Scope_number;
        int Scope_index;
        struct scope* next_scope;
        Symbol* first_node;
    } Scope;

    // Scope** Scopes = NULL;
    Scope** Scopes;
    // Scope* Scopes = NULL;

    /* Symbol table function - you can add new function if needed. */
    int lookup_symbol();
    // Scope** create_symbol(Scope**, int);
    void create_symbol(Scope**, int);
    // Scope* create_symbol(Scope*, int);
    Scope* insert_symbol(Scope*, int, char *, char *, char *, char*);
    void dump_symbol(Symbol*);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
#line 56 "compiler_hw2.y"
{
    int i_val;
    double f_val;
    bool b_val;
    char *type;
    char *name;
}
/* Line 193 of yacc.c.  */
#line 260 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 273 "y.tab.c"

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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   389

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNRULES -- Number of states.  */
#define YYNSTATES  165

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    16,    20,    25,
      27,    31,    34,    37,    41,    44,    46,    48,    50,    52,
      54,    56,    58,    60,    66,    70,    72,    74,    76,    78,
      80,    82,    84,    86,    90,    92,    94,   100,   106,   114,
     116,   119,   121,   123,   127,   129,   131,   133,   135,   137,
     139,   141,   145,   147,   151,   153,   157,   161,   163,   167,
     171,   175,   179,   181,   185,   189,   191,   195,   199,   203,
     205,   208,   211,   214,   217,   220,   222,   226,   231,   234,
     237,   239,   243,   245,   247,   251,   257,   264,   272,   279,
     287,   290,   293,   296
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    56,    -1,    55,    56,    -1,    57,    -1,
      64,    -1,    65,    58,    61,    -1,    53,    30,    31,    -1,
      53,    30,    59,    31,    -1,    60,    -1,    59,     9,    60,
      -1,    65,    53,    -1,    34,    35,    -1,    34,    62,    35,
      -1,    63,    62,    -1,    63,    -1,    64,    -1,    61,    -1,
      70,    -1,    69,    -1,    84,    -1,    85,    -1,    68,    -1,
      65,    53,    12,    66,     8,    -1,    65,    53,     8,    -1,
      38,    -1,    39,    -1,    40,    -1,    42,    -1,    41,    -1,
      72,    -1,    49,    -1,    50,    -1,    36,    37,    36,    -1,
      51,    -1,    52,    -1,     3,    30,    71,    31,     8,    -1,
       4,    30,    71,    31,    63,    -1,     4,    30,    71,    31,
      63,     5,    63,    -1,     8,    -1,    71,     8,    -1,    72,
      -1,    74,    -1,    53,    73,    72,    -1,    12,    -1,    13,
      -1,    14,    -1,    15,    -1,    16,    -1,    17,    -1,    75,
      -1,    74,    25,    75,    -1,    76,    -1,    75,    24,    76,
      -1,    77,    -1,    76,    22,    77,    -1,    76,    23,    77,
      -1,    78,    -1,    77,    18,    78,    -1,    77,    19,    78,
      -1,    77,    20,    78,    -1,    77,    21,    78,    -1,    79,
      -1,    78,    45,    79,    -1,    78,    44,    79,    -1,    80,
      -1,    79,    48,    80,    -1,    79,    47,    80,    -1,    79,
      46,    80,    -1,    81,    -1,    10,    80,    -1,    11,    80,
      -1,    26,    80,    -1,    45,    80,    -1,    44,    80,    -1,
      83,    -1,    81,    30,    31,    -1,    81,    30,    82,    31,
      -1,    81,    10,    -1,    81,    11,    -1,    72,    -1,    82,
       9,    72,    -1,    53,    -1,    67,    -1,    30,    71,    31,
      -1,     7,    30,    71,    31,    63,    -1,     6,    30,    70,
      70,    31,    63,    -1,     6,    30,    70,    70,    71,    31,
      63,    -1,     6,    30,    64,    70,    31,    63,    -1,     6,
      30,    64,    70,    71,    31,    63,    -1,    29,     8,    -1,
      28,     8,    -1,    27,     8,    -1,    27,    71,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   110,   120,   121,   125,   129,   132,   138,
     139,   143,   150,   151,   155,   156,   160,   161,   162,   163,
     164,   165,   166,   170,   173,   181,   182,   183,   184,   185,
     189,   193,   194,   195,   196,   197,   201,   205,   206,   210,
     211,   215,   219,   220,   224,   225,   226,   227,   228,   229,
     233,   234,   238,   239,   243,   244,   245,   249,   250,   251,
     252,   253,   257,   258,   259,   263,   264,   265,   270,   278,
     279,   280,   281,   282,   283,   287,   288,   289,   290,   291,
     295,   296,   300,   301,   302,   307,   308,   309,   310,   311,
     315,   316,   317,   318
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "IF", "ELSE", "FOR", "WHILE",
  "SEMICOLON", "COMMA", "INC", "DEC", "ASGN", "ADDASGN", "SUBASGN",
  "MULASGN", "DIVASGN", "MODASGN", "LT", "MT", "LTE", "MTE", "EQ", "NE",
  "AND", "OR", "NOT", "RTN", "CONTINUE", "BREAK", "LB", "RB", "LSB", "RSB",
  "LCB", "RCB", "QUOTA", "STR_CONST", "INT", "FLOAT", "BOOL", "VOID",
  "STRING", "LOWER_THAN_ELSE", "SUB", "ADD", "MOD", "DIV", "MUL",
  "I_CONST", "F_CONST", "TRUE", "FALSE", "ID", "$accept", "program",
  "external_declaration", "function_definition", "function_declarator",
  "param_list", "param_declaration", "compound_stat", "stats", "stat",
  "declaration_stat", "type", "initializer", "constant", "print_func",
  "selection_stat", "expression_stat", "expression",
  "assignment_expression", "assignment_operator", "logical_or_experssion",
  "logical_and_experssion", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "argument_expression_list", "primary_expression",
  "iteration_stat", "jump_stat", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    57,    58,    58,    59,
      59,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    64,    64,    65,    65,    65,    65,    65,
      66,    67,    67,    67,    67,    67,    68,    69,    69,    70,
      70,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      74,    74,    75,    75,    76,    76,    76,    77,    77,    77,
      77,    77,    78,    78,    78,    79,    79,    79,    79,    80,
      80,    80,    80,    80,    80,    81,    81,    81,    81,    81,
      82,    82,    83,    83,    83,    84,    84,    84,    84,    84,
      85,    85,    85,    85
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     3,     4,     1,
       3,     2,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     5,     5,     7,     1,
       2,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     2,     2,     2,     1,     3,     4,     2,     2,
       1,     3,     1,     1,     3,     5,     6,     7,     6,     7,
       2,     2,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    25,    26,    27,    29,    28,     0,     2,     4,     5,
       0,     1,     3,     0,     0,    24,     0,     0,     0,     6,
       0,     0,     0,     0,     0,     0,     0,    31,    32,    34,
      35,    82,     0,    83,    30,    42,    50,    52,    54,    57,
      62,    65,    69,    75,     7,     0,     9,     0,     0,     0,
       0,     0,    39,     0,     0,     0,    12,    17,     0,    15,
      16,     0,    22,    19,    18,     0,    41,    20,    21,    82,
      70,    71,    72,     0,     0,    74,    73,    44,    45,    46,
      47,    48,    49,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    79,
       0,     0,     8,    11,     0,     0,     0,     0,    92,     0,
      91,    90,    13,    14,     0,    40,    84,    33,    43,    51,
      53,    55,    56,    58,    59,    60,    61,    64,    63,    68,
      67,    66,    76,    80,     0,    10,     0,     0,     0,     0,
       0,    93,     0,    77,     0,     0,     0,     0,     0,    81,
      36,    37,     0,     0,     0,     0,    85,     0,    88,     0,
      86,     0,    38,    89,    87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    14,    45,    46,    57,    58,    59,
      60,    61,    32,    33,    62,    63,    64,    65,    66,    83,
      35,    36,    37,    38,    39,    40,    41,    42,   134,    43,
      67,    68
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -103
static const yytype_int16 yypact[] =
{
     130,  -103,  -103,  -103,  -103,  -103,    35,  -103,  -103,  -103,
     -48,  -103,  -103,    -2,   -27,  -103,   300,    81,    19,  -103,
     336,   336,   336,   300,   -13,   336,   336,  -103,  -103,  -103,
    -103,   150,    13,  -103,  -103,    14,    28,    21,    60,   -12,
      47,  -103,     4,  -103,  -103,     9,  -103,    37,    32,    61,
      67,    69,  -103,   195,    48,    92,  -103,  -103,    93,   103,
    -103,    49,  -103,  -103,  -103,   119,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,   104,    98,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,   300,  -103,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,  -103,  -103,
     242,   130,  -103,  -103,   300,   300,   149,   300,  -103,   128,
    -103,  -103,  -103,  -103,    30,  -103,  -103,  -103,  -103,    28,
      21,    60,    60,   -12,   -12,   -12,   -12,    47,    47,  -103,
    -103,  -103,  -103,  -103,    10,  -103,   107,   109,   206,   206,
     115,  -103,   300,  -103,   141,   103,   253,   289,   103,  -103,
    -103,   145,   103,   120,   103,   127,  -103,   103,  -103,   103,
    -103,   103,  -103,  -103,  -103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,   155,  -103,  -103,  -103,    72,   160,   117,   -56,
       2,     3,  -103,  -103,  -103,  -103,  -102,   -22,   -16,  -103,
    -103,    95,    91,   -37,    26,   -28,    -9,  -103,  -103,  -103,
    -103,  -103
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      34,    73,     9,    10,   139,    13,    15,    18,     9,    10,
      16,    70,    71,    72,    98,    99,    75,    76,   101,   142,
      47,    84,    48,    49,    74,    50,    51,    52,    17,    20,
      21,   109,    93,    94,   100,    11,   146,   147,    15,    85,
     102,   143,    16,    87,    88,    22,    53,    54,    55,    23,
     121,   122,    86,    18,    56,    24,   110,     1,     2,     3,
       4,     5,   104,    25,    26,   127,   128,   118,    27,    28,
      29,    30,    31,     1,     2,     3,     4,     5,    89,    90,
      91,    92,   136,   137,   133,   140,   129,   130,   131,   151,
     103,   105,   156,    95,    96,    97,   158,   106,   160,   107,
     111,   162,   114,   163,    47,   164,    48,    49,   138,    50,
      51,    52,    44,    20,    21,   123,   124,   125,   126,     1,
       2,     3,     4,     5,   153,   155,   149,   115,   112,    22,
      53,    54,    55,    23,   117,   116,   141,    18,   144,    24,
     145,     1,     2,     3,     4,     5,   148,    25,    26,   150,
     157,   159,    27,    28,    29,    30,    31,    52,   161,    20,
      21,    12,    77,    78,    79,    80,    81,    82,     1,     2,
       3,     4,     5,   135,    19,    22,   113,   120,     0,    23,
     119,     0,     0,     0,     0,    24,     0,     1,     2,     3,
       4,     5,     0,    25,    26,     0,     0,     0,    27,    28,
      29,    30,    31,   108,     0,    20,    21,     0,     0,     0,
       0,     0,     0,     0,    52,     0,    20,    21,     0,     0,
       0,    22,     0,     0,     0,    23,     0,     0,     0,     0,
       0,    24,    22,     0,     0,     0,    23,     0,     0,    25,
      26,     0,    24,     0,    27,    28,    29,    30,    31,     0,
      25,    26,    20,    21,     0,    27,    28,    29,    30,    31,
       0,     0,     0,    20,    21,     0,     0,     0,    22,     0,
       0,     0,    23,   132,     0,     0,     0,     0,    24,    22,
       0,     0,     0,    23,   152,     0,    25,    26,     0,    24,
       0,    27,    28,    29,    30,    31,     0,    25,    26,    20,
      21,     0,    27,    28,    29,    30,    31,     0,     0,     0,
      20,    21,     0,     0,     0,    22,     0,     0,     0,    23,
     154,     0,     0,     0,     0,    24,    22,     0,     0,     0,
      23,     0,     0,    25,    26,     0,    24,     0,    27,    28,
      29,    30,    31,     0,    25,    26,    20,    21,     0,    27,
      28,    29,    30,    31,     0,     0,     0,     0,     0,     0,
       0,     0,    22,     0,     0,     0,    23,     0,     0,     0,
       0,     0,    24,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,    27,    28,    29,    30,    69
};

static const yytype_int16 yycheck[] =
{
      16,    23,     0,     0,   106,    53,     8,    34,     6,     6,
      12,    20,    21,    22,    10,    11,    25,    26,     9,     9,
      17,     8,     3,     4,    37,     6,     7,     8,    30,    10,
      11,    53,    44,    45,    30,     0,   138,   139,     8,    25,
      31,    31,    12,    22,    23,    26,    27,    28,    29,    30,
      87,    88,    24,    34,    35,    36,     8,    38,    39,    40,
      41,    42,    30,    44,    45,    93,    94,    83,    49,    50,
      51,    52,    53,    38,    39,    40,    41,    42,    18,    19,
      20,    21,   104,   105,   100,   107,    95,    96,    97,   145,
      53,    30,   148,    46,    47,    48,   152,    30,   154,    30,
       8,   157,    53,   159,   101,   161,     3,     4,   106,     6,
       7,     8,    31,    10,    11,    89,    90,    91,    92,    38,
      39,    40,    41,    42,   146,   147,   142,     8,    35,    26,
      27,    28,    29,    30,    36,    31,     8,    34,    31,    36,
      31,    38,    39,    40,    41,    42,    31,    44,    45,     8,
       5,    31,    49,    50,    51,    52,    53,     8,    31,    10,
      11,     6,    12,    13,    14,    15,    16,    17,    38,    39,
      40,    41,    42,   101,    14,    26,    59,    86,    -1,    30,
      85,    -1,    -1,    -1,    -1,    36,    -1,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    -1,    -1,    49,    50,
      51,    52,    53,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    10,    11,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    26,    -1,    -1,    -1,    30,    -1,    -1,    44,
      45,    -1,    36,    -1,    49,    50,    51,    52,    53,    -1,
      44,    45,    10,    11,    -1,    49,    50,    51,    52,    53,
      -1,    -1,    -1,    10,    11,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    36,    26,
      -1,    -1,    -1,    30,    31,    -1,    44,    45,    -1,    36,
      -1,    49,    50,    51,    52,    53,    -1,    44,    45,    10,
      11,    -1,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      10,    11,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    36,    26,    -1,    -1,    -1,
      30,    -1,    -1,    44,    45,    -1,    36,    -1,    49,    50,
      51,    52,    53,    -1,    44,    45,    10,    11,    -1,    49,
      50,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    49,    50,    51,    52,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    39,    40,    41,    42,    55,    56,    57,    64,
      65,     0,    56,    53,    58,     8,    12,    30,    34,    61,
      10,    11,    26,    30,    36,    44,    45,    49,    50,    51,
      52,    53,    66,    67,    72,    74,    75,    76,    77,    78,
      79,    80,    81,    83,    31,    59,    60,    65,     3,     4,
       6,     7,     8,    27,    28,    29,    35,    61,    62,    63,
      64,    65,    68,    69,    70,    71,    72,    84,    85,    53,
      80,    80,    80,    71,    37,    80,    80,    12,    13,    14,
      15,    16,    17,    73,     8,    25,    24,    22,    23,    18,
      19,    20,    21,    44,    45,    46,    47,    48,    10,    11,
      30,     9,    31,    53,    30,    30,    30,    30,     8,    71,
       8,     8,    35,    62,    53,     8,    31,    36,    72,    75,
      76,    77,    77,    78,    78,    78,    78,    79,    79,    80,
      80,    80,    31,    72,    82,    60,    71,    71,    64,    70,
      71,     8,     9,    31,    31,    31,    70,    70,    31,    72,
       8,    63,    31,    71,    31,    71,    63,     5,    63,    31,
      63,    31,    63,    63,    63
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 103 "compiler_hw2.y"
    {
        // Scopes = create_symbol(Scopes, Scope_num);
        if (Scopes == NULL) {
            Scopes = (Scope**) malloc(sizeof(Scope*));
        }
        create_symbol(Scopes, Scope_num);
    }
    break;

  case 3:
#line 110 "compiler_hw2.y"
    {
        // Scopes = create_symbol(Scopes, Scope_num);
        if (Scopes == NULL) {
            Scopes = (Scope**) malloc(sizeof(Scope*));
        }
        create_symbol(Scopes, Scope_num);
    }
    break;

  case 7:
#line 129 "compiler_hw2.y"
    {
        Scope_num++;
    }
    break;

  case 8:
#line 132 "compiler_hw2.y"
    {
        Scope_num++;
    }
    break;

  case 11:
#line 143 "compiler_hw2.y"
    {
        // Scopes = create_symbol(Scopes, Scope_num + 1);
        create_symbol(Scopes, Scope_num+1);
    }
    break;

  case 23:
#line 170 "compiler_hw2.y"
    {
        
    }
    break;

  case 24:
#line 173 "compiler_hw2.y"
    {

    }
    break;

  case 25:
#line 181 "compiler_hw2.y"
    { (yyval.type) = "int"; }
    break;

  case 26:
#line 182 "compiler_hw2.y"
    { (yyval.type) = "float"; }
    break;

  case 27:
#line 183 "compiler_hw2.y"
    { (yyval.type) = "bool"; }
    break;

  case 28:
#line 184 "compiler_hw2.y"
    { (yyval.type) = "string"; }
    break;

  case 29:
#line 185 "compiler_hw2.y"
    { (yyval.type) = "void"; }
    break;

  case 55:
#line 244 "compiler_hw2.y"
    { (yyval.f_val) = (yyvsp[(1) - (3)].f_val) == (yyvsp[(3) - (3)].f_val); }
    break;

  case 56:
#line 245 "compiler_hw2.y"
    { (yyval.f_val) = (yyvsp[(1) - (3)].f_val) != (yyvsp[(3) - (3)].f_val); }
    break;

  case 58:
#line 250 "compiler_hw2.y"
    { (yyval.f_val) = (yyvsp[(1) - (3)].f_val) < (yyvsp[(3) - (3)].f_val); }
    break;

  case 59:
#line 251 "compiler_hw2.y"
    { (yyval.f_val) = (yyvsp[(1) - (3)].f_val) > (yyvsp[(3) - (3)].f_val); }
    break;

  case 60:
#line 252 "compiler_hw2.y"
    { (yyval.f_val) = (yyvsp[(1) - (3)].f_val) <= (yyvsp[(3) - (3)].f_val); }
    break;

  case 61:
#line 253 "compiler_hw2.y"
    { (yyval.f_val) = (yyvsp[(1) - (3)].f_val) >= (yyvsp[(3) - (3)].f_val); }
    break;

  case 63:
#line 258 "compiler_hw2.y"
    { (yyval.f_val) = (yyvsp[(1) - (3)].f_val) + (yyvsp[(3) - (3)].f_val); }
    break;

  case 64:
#line 259 "compiler_hw2.y"
    { (yyval.f_val) = (yyvsp[(1) - (3)].f_val) - (yyvsp[(3) - (3)].f_val); }
    break;

  case 66:
#line 264 "compiler_hw2.y"
    { (yyval.f_val) = (yyvsp[(1) - (3)].f_val) * (yyvsp[(3) - (3)].f_val); }
    break;

  case 67:
#line 265 "compiler_hw2.y"
    { 
        if ((yyvsp[(3) - (3)].f_val) == 0)
            yyerror("Divide by zero !!");
        else
            (yyval.f_val) = (yyvsp[(1) - (3)].f_val) / (yyvsp[(3) - (3)].f_val); }
    break;

  case 68:
#line 270 "compiler_hw2.y"
    { 
        if ((yyvsp[(3) - (3)].f_val) == 0)
            yyerror("Moded by zero !!");
        else
            (yyval.f_val) = (yyvsp[(1) - (3)].i_val) % (yyvsp[(3) - (3)].i_val); }
    break;

  case 70:
#line 279 "compiler_hw2.y"
    { (yyval.f_val) = ++(yyvsp[(2) - (2)].f_val); }
    break;

  case 71:
#line 280 "compiler_hw2.y"
    { (yyval.f_val) = --(yyvsp[(2) - (2)].f_val); }
    break;

  case 72:
#line 281 "compiler_hw2.y"
    { (yyval.f_val) = !(yyvsp[(2) - (2)].f_val); }
    break;

  case 73:
#line 282 "compiler_hw2.y"
    { (yyval.f_val) = (yyvsp[(2) - (2)].f_val); }
    break;

  case 74:
#line 283 "compiler_hw2.y"
    { (yyval.f_val) = -(yyvsp[(2) - (2)].f_val); }
    break;

  case 84:
#line 302 "compiler_hw2.y"
    { (yyval.f_val) = (yyvsp[(2) - (3)].f_val); }
    break;


/* Line 1267 of yacc.c.  */
#line 1847 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
		      yytoken, &yylval);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 319 "compiler_hw2.y"


/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;
    yyparse();
	printf("\nTotal lines: %d \n",yylineno);
    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

void create_symbol(Scope** Scopes, int Scope_num) {
    Scope* cursor;
    if (*Scopes == NULL) {
        *Scopes = (Scope*) malloc(sizeof(Scope));
        ((Scope*) *Scopes)->Scope_number = 0;// Init
        ((Scope*) *Scopes)->Scope_index = 0;
        ((Scope*) *Scopes)->next_scope = NULL;
        ((Scope*) *Scopes)->first_node = NULL;
        printf("Init");
        // return Scopes;
    }
    else {
        cursor = ((Scope*) *Scopes);
        while(cursor->next_scope != NULL) { //Walk to the end
            cursor = cursor->next_scope;
        }
        if (cursor->Scope_number < Scope_num) {
            printf("MALLOC");
            cursor->next_scope = (Scope*) malloc(sizeof(Scope));
            ((Scope*) cursor->next_scope)->Scope_number = Scope_num;
            ((Scope*) cursor->next_scope)->Scope_index = 0;
            ((Scope*) cursor->next_scope)->next_scope = NULL;
            ((Scope*) cursor->next_scope)->first_node = NULL;
        }
        // return Scopes;
    }
}

// Scope** create_symbol(Scope** Scopes, int Scope_num) {
//     Scope* cursor;
//     if (Scopes == NULL) {
//         Scopes = (Scope**) malloc(sizeof(Scope*));
//         *Scopes = (Scope*) malloc(sizeof(Scope));
//         ((Scope*) *Scopes)->Scope_number = 0;// Init
//         ((Scope*) *Scopes)->Scope_index = 0;
//         ((Scope*) *Scopes)->next_scope = NULL;
//         ((Scope*) *Scopes)->first_node = NULL;
//         return Scopes;
//     }
//     else {
//         cursor = ((Scope*) *Scopes);
//         while(cursor->next_scope != NULL) { //Walk to the end
//             cursor = cursor->next_scope;
//         }
//         if (cursor->Scope_number < Scope_num) {
//             cursor->next_scope = (Scope*) malloc(sizeof(Scope));
//             ((Scope*) cursor->next_scope)->Scope_number = Scope_num;
//             ((Scope*) cursor->next_scope)->Scope_index = 0;
//             ((Scope*) cursor->next_scope)->next_scope = NULL;
//             ((Scope*) cursor->next_scope)->first_node = NULL;
//         }
//         return Scopes;
//     }
// }

// Scope* create_symbol(Scope* Scopes, int Scope_num) {
    
//     if (Scopes == NULL) {
//         Scopes = (Scope*) malloc(sizeof(Scope));
//         Scopes->Scope_number = 0;
//         Scopes->Scope_index = 0;
//         Scopes->next_scope = NULL;
//         Scopes->first_node = NULL;
//     }
//     else {
//         Scope* cursor = Scopes;
//         while (cursor->next_scope != NULL) {
//             cursor = cursor->next_scope;
//         }
//         printf("%d\n", cursor->Scope_number );
//         if (cursor->Scope_number < Scope_num) {
//             cursor->next_scope = (Scope*) malloc(sizeof(Scope));
//             cursor->next_scope->Scope_number = 0;
//             cursor->next_scope->Scope_index = 0;
//             cursor->next_scope->next_scope = NULL;
//             cursor->next_scope->first_node = NULL;
//             printf("%d\n", Scope_num);
//             printf("MALLOC\n");
//         }
//     }
//     return Scopes;
// }

// Scope* insert_symbol(Scope* Scopes, int Scope_num, char *Name, char *Kind, char *Type, char* Attribute) {

//     Scope* current_scope = Scopes;
//     while (current_scope->Scope_number < Scope_num) {
//         current_scope = current_scope->next_scope;
//     }
//     Symbol* current_symbol = current_scope->first_node;
//     if (current_symbol == NULL) {
//         current_symbol = (Symbol*) malloc(sizeof(Symbol));
//     }
//     else {
//         while (current_symbol->next_node != NULL) {
//             if (current_symbol->Name == Name && current_symbol->Scope == Scope_num) {
//                 char msg[1024];
//                 strcpy(msg, "Redeclared ");
//                 strcat(msg, Type);
//                 strcat(msg, "<");
//                 strcat(msg, Name);
//                 strcat(msg, ">");
//                 yyerror(msg);
//                 return Scopes;
//             }
//             else {
//                 current_symbol = current_symbol->next_node;
//             }
//         }
//         current_symbol = (Symbol*) malloc(sizeof(Symbol));
//     }
//     current_symbol->Index = current_scope->Scope_index;
//     current_scope->Scope_index++;
//     current_symbol->Scope = Scope_num;
//     current_symbol->Name = strdup(Name);
//     current_symbol->Kind = strdup(Kind);
//     current_symbol->Type = strdup(Type);
//     current_symbol->Attribute = strdup(Attribute);
//     return Scopes;
// }

// Scope** insert_symbol(Scope** Scopes, int Scope_num, char *Name, char *Kind, char *Type, char* Attribute) {

//     Scope* current_scope = Scopes;
//     while (current_scope->Scope_number < Scope_num) {
//         current_scope = current_scope->next_scope;
//     }
//     Symbol* current_symbol = current_scope->first_node;
//     if (current_symbol == NULL) {
//         current_symbol = (Symbol*) malloc(sizeof(Symbol));
//     }
//     else {
//         while (current_symbol->next_node != NULL) {
//             if (current_symbol->Name == Name && current_symbol->Scope == Scope_num) {
//                 char msg[1024];
//                 strcpy(msg, "Redeclared ");
//                 strcat(msg, Type);
//                 strcat(msg, "<");
//                 strcat(msg, Name);
//                 strcat(msg, ">");
//                 yyerror(msg);
//                 return Scopes;
//             }
//             else {
//                 current_symbol = current_symbol->next_node;
//             }
//         }
//         current_symbol = (Symbol*) malloc(sizeof(Symbol));
//     }
//     current_symbol->Index = current_scope->Scope_index;
//     current_scope->Scope_index++;
//     current_symbol->Scope = Scope_num;
//     current_symbol->Name = strdup(Name);
//     current_symbol->Kind = strdup(Kind);
//     current_symbol->Type = strdup(Type);
//     current_symbol->Attribute = strdup(Attribute);
//     return Scopes;
// }

int lookup_symbol() { return 0; }

void dump_symbol(Symbol* symtbl) {
    if (symtbl) {
        printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
    }
}

