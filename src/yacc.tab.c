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
     CREATE = 258,
     DROP = 259,
     USE = 260,
     DESC = 261,
     SHOW = 262,
     INSERT = 263,
     DATABASE = 264,
     TABLE = 265,
     INTO = 266,
     VALUES = 267,
     WHERE = 268,
     SET = 269,
     UPDATE = 270,
     SELECT = 271,
     DELETE = 272,
     OP_FROM = 273,
     OP_GROUP = 274,
     OP_BY = 275,
     OP_INT = 276,
     VARCHAR = 277,
     OP_SUM = 278,
     OP_MAX = 279,
     OP_MIN = 280,
     OP_AVG = 281,
     OP_CHECK = 282,
     OP_IN = 283,
     OP_LIKE = 284,
     OP_NOT = 285,
     OP_NULL = 286,
     OP_PRIMARY = 287,
     OP_KEY = 288,
     OP_AND = 289,
     OP_OR = 290,
     OP_LE = 291,
     OP_GE = 292,
     OP_IS = 293,
     OP_EQUAL = 294,
     OP_NOT_EQUAL = 295,
     NUMBER = 296,
     STRING = 297,
     IDENT = 298
   };
#endif
/* Tokens.  */
#define CREATE 258
#define DROP 259
#define USE 260
#define DESC 261
#define SHOW 262
#define INSERT 263
#define DATABASE 264
#define TABLE 265
#define INTO 266
#define VALUES 267
#define WHERE 268
#define SET 269
#define UPDATE 270
#define SELECT 271
#define DELETE 272
#define OP_FROM 273
#define OP_GROUP 274
#define OP_BY 275
#define OP_INT 276
#define VARCHAR 277
#define OP_SUM 278
#define OP_MAX 279
#define OP_MIN 280
#define OP_AVG 281
#define OP_CHECK 282
#define OP_IN 283
#define OP_LIKE 284
#define OP_NOT 285
#define OP_NULL 286
#define OP_PRIMARY 287
#define OP_KEY 288
#define OP_AND 289
#define OP_OR 290
#define OP_LE 291
#define OP_GE 292
#define OP_IS 293
#define OP_EQUAL 294
#define OP_NOT_EQUAL 295
#define NUMBER 296
#define STRING 297
#define IDENT 298




/* Copy the first part of user declarations.  */
#line 1 "yacc.y"

	#include "main.h"
	#include "Terminal.h"

	extern "C"			
	{					
		void yyerror(const char *s);
		extern int yylex(void);
	}

	DBManger terminal;

	std::string regexChange(std::string con) {
		std::string res = "";
		for (int i = 0; i < con.length(); i++)
			if (con[i] == '%') res = res + ".*"; else
			if (con[i] == '_') res = res + "."; else
			res = res + con[i];
		return res;
	}
	int hxtot=0;



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
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 216 "yacc.tab.c"

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
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   258

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNRULES -- Number of states.  */
#define YYNSTATES  211

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    50,     2,     2,
      55,    51,    48,    46,    53,    47,    56,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
      44,    54,    45,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    14,    17,    20,    23,
      26,    32,    39,    46,    53,    58,    63,    71,    77,    81,
      83,    87,    89,    93,    97,   101,   105,   107,   109,   111,
     113,   117,   121,   125,   128,   131,   135,   139,   143,   147,
     151,   155,   159,   163,   167,   171,   175,   179,   183,   187,
     191,   195,   199,   203,   207,   211,   215,   219,   223,   227,
     231,   235,   239,   243,   247,   251,   255,   259,   261,   266,
     271,   276,   281,   283,   285,   287,   291,   295,   299,   303,
     309,   312,   315,   318,   321,   324,   330,   333,   336,   339,
     342,   348,   354,   362,   370,   376,   385,   389
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    58,    59,    -1,    59,    -1,    77,    52,
      -1,    75,    52,    -1,    60,    52,    -1,    61,    52,    -1,
      62,    52,    -1,    63,    52,    -1,     8,    11,    43,    12,
      74,    -1,    15,    43,    14,    65,    13,    67,    -1,    16,
      64,    18,    64,    13,    67,    -1,    16,    48,    18,    64,
      13,    67,    -1,    16,    64,    18,    64,    -1,    16,    48,
      18,    64,    -1,    16,    64,    18,    64,    19,    20,    64,
      -1,    17,    18,    43,    13,    67,    -1,    64,    53,    72,
      -1,    72,    -1,    65,    53,    66,    -1,    66,    -1,    72,
      54,    42,    -1,    72,    54,    41,    -1,    72,    54,    31,
      -1,    72,    54,    67,    -1,    68,    -1,    69,    -1,    70,
      -1,    71,    -1,    55,    67,    51,    -1,    67,    34,    67,
      -1,    67,    35,    67,    -1,    30,    67,    -1,    47,    67,
      -1,    72,    46,    41,    -1,    72,    47,    41,    -1,    41,
      46,    72,    -1,    41,    47,    72,    -1,    72,    45,    41,
      -1,    72,    44,    41,    -1,    72,    54,    41,    -1,    72,
      37,    41,    -1,    72,    36,    41,    -1,    41,    45,    72,
      -1,    41,    44,    72,    -1,    41,    54,    72,    -1,    41,
      37,    72,    -1,    41,    36,    72,    -1,    72,    45,    42,
      -1,    72,    44,    42,    -1,    72,    54,    42,    -1,    72,
      37,    42,    -1,    72,    36,    42,    -1,    42,    45,    72,
      -1,    42,    44,    72,    -1,    42,    54,    72,    -1,    42,
      37,    72,    -1,    42,    36,    72,    -1,    72,    29,    42,
      -1,    72,    45,    72,    -1,    72,    44,    72,    -1,    72,
      54,    72,    -1,    72,    37,    72,    -1,    72,    36,    72,
      -1,    72,    38,    31,    -1,    43,    56,    43,    -1,    43,
      -1,    23,    55,    72,    51,    -1,    26,    55,    72,    51,
      -1,    24,    55,    72,    51,    -1,    25,    55,    72,    51,
      -1,    41,    -1,    42,    -1,    31,    -1,    73,    53,    31,
      -1,    73,    53,    41,    -1,    73,    53,    42,    -1,    55,
      73,    51,    -1,    74,    53,    55,    73,    51,    -1,     3,
      76,    -1,     4,    76,    -1,     7,    76,    -1,     5,    43,
      -1,     9,    43,    -1,     3,    78,    55,    80,    51,    -1,
       4,    78,    -1,     6,    78,    -1,     7,    78,    -1,    10,
      43,    -1,    43,    21,    55,    41,    51,    -1,    43,    22,
      55,    41,    51,    -1,    43,    21,    55,    41,    51,    30,
      31,    -1,    43,    22,    55,    41,    51,    30,    31,    -1,
      32,    33,    55,    43,    51,    -1,    27,    55,    43,    28,
      55,    73,    51,    51,    -1,    80,    53,    79,    -1,    79,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    68,    73,    77,    81,    85,    89,    93,
     100,   110,   118,   124,   130,   136,   142,   148,   159,   164,
     172,   176,   183,   187,   191,   195,   201,   205,   209,   213,
     217,   222,   227,   232,   237,   244,   250,   256,   262,   268,
     274,   280,   286,   292,   298,   304,   310,   316,   322,   330,
     336,   342,   348,   354,   360,   366,   372,   378,   384,   390,
     398,   405,   412,   419,   426,   435,   443,   449,   455,   460,
     465,   470,   477,   482,   487,   492,   496,   500,   506,   511,
     517,   521,   525,   529,   535,   542,   546,   550,   554,   560,
     566,   570,   574,   578,   582,   586,   592,   596
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CREATE", "DROP", "USE", "DESC", "SHOW",
  "INSERT", "DATABASE", "TABLE", "INTO", "VALUES", "WHERE", "SET",
  "UPDATE", "SELECT", "DELETE", "OP_FROM", "OP_GROUP", "OP_BY", "OP_INT",
  "VARCHAR", "OP_SUM", "OP_MAX", "OP_MIN", "OP_AVG", "OP_CHECK", "OP_IN",
  "OP_LIKE", "OP_NOT", "OP_NULL", "OP_PRIMARY", "OP_KEY", "OP_AND",
  "OP_OR", "OP_LE", "OP_GE", "OP_IS", "OP_EQUAL", "OP_NOT_EQUAL", "NUMBER",
  "STRING", "IDENT", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "')'", "';'", "','", "'='", "'('", "'.'", "$accept", "StmtBlock", "Stmt",
  "InsertStmt", "UpdateStmt", "SelectStmt", "DeleteStmt", "DBIDENTList",
  "AssignList", "Assign", "Expr", "Id2Num", "Id2Str", "Id2Id", "IdIsNULL",
  "DBIDENT", "Price", "Value", "DatabaseStmt", "DatabaseIdent",
  "TableStmt", "TableIdent", "TableEntity", "TableEntityList", 0
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
     295,   296,   297,   298,    60,    62,    43,    45,    42,    47,
      37,    41,    59,    44,    61,    40,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      60,    61,    62,    62,    62,    62,    62,    63,    64,    64,
      65,    65,    66,    66,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      70,    70,    70,    70,    70,    71,    72,    72,    72,    72,
      72,    72,    73,    73,    73,    73,    73,    73,    74,    74,
      75,    75,    75,    75,    76,    77,    77,    77,    77,    78,
      79,    79,    79,    79,    79,    79,    80,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     2,     2,     2,     2,
       5,     6,     6,     6,     4,     4,     7,     5,     3,     1,
       3,     1,     3,     3,     3,     3,     1,     1,     1,     1,
       3,     3,     3,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     4,     4,
       4,     4,     1,     1,     1,     3,     3,     3,     3,     5,
       2,     2,     2,     2,     2,     5,     2,     2,     2,     2,
       5,     5,     7,     7,     5,     8,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,    81,    86,    83,    87,    82,    88,     0,     0,
       0,     0,     0,     0,    67,     0,     0,    19,     0,     1,
       2,     6,     7,     8,     9,     5,     4,    84,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,     0,     0,     0,    21,     0,
       0,     0,     0,     0,    66,    15,    14,    18,     0,     0,
       0,     0,     0,    85,     0,     0,    10,     0,     0,     0,
      68,    70,    71,    69,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    26,    27,    28,    29,     0,     0,     0,
       0,     0,    96,    74,    72,    73,     0,     0,    11,    20,
      24,    23,    22,    25,    13,    12,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
      16,    48,    47,    45,    44,    37,    38,    46,    58,    57,
      55,    54,    56,    30,    31,    32,    59,    43,    53,    64,
      42,    52,    63,    65,    40,    50,    61,    39,    49,    60,
      35,    36,    41,    51,    62,     0,    94,    90,    91,    75,
      76,    77,     0,     0,     0,     0,    79,     0,    92,    93,
      95
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,    15,    36,    67,    68,
     102,   103,   104,   105,   106,   107,   116,    86,    16,    20,
      17,    21,    64,    65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -156
static const yytype_int16 yypact[] =
{
     207,    44,    44,   -36,    22,    44,    31,    14,    13,    42,
      18,  -156,    43,    61,    83,    84,    90,    93,   100,   119,
    -156,    49,  -156,  -156,  -156,  -156,  -156,  -156,   120,    72,
      98,   111,   128,   131,   109,   157,   -12,  -156,   144,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,    46,
     162,    76,    76,    76,    76,    76,   153,    76,    76,    76,
     178,   149,   170,    47,  -156,    34,   150,    -1,  -156,   152,
     165,   166,   168,   169,  -156,     2,    -5,  -156,    51,   182,
     171,   172,   173,  -156,    46,   -22,   154,    51,    76,    41,
    -156,  -156,  -156,  -156,    51,    51,   201,    51,   148,   164,
      51,    51,    56,  -156,  -156,  -156,  -156,   110,   202,   186,
     190,   191,  -156,  -156,  -156,  -156,    52,   179,    56,  -156,
    -156,   148,   164,    56,    56,    56,    76,  -156,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
    -156,    28,    51,    51,   193,    91,   126,   205,   135,   147,
     192,   196,   156,   183,   188,   189,   194,  -156,    66,   -22,
     195,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,   208,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,   -22,  -156,   211,   213,  -156,
    -156,  -156,    58,    59,   215,   216,  -156,   198,  -156,  -156,
    -156
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,   234,  -156,  -156,  -156,  -156,   -56,  -156,   163,
     -84,  -156,  -156,  -156,  -156,    -8,  -155,  -156,  -156,    26,
    -156,    25,   174,  -156
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      37,    75,    76,   118,   202,   123,    58,    24,    95,   113,
     124,   125,    87,   127,    96,    94,   140,   141,    39,   114,
     115,     1,     2,     3,     4,     5,     6,    23,    22,    25,
      27,    26,    19,     7,     8,     9,    30,    31,    32,    33,
     203,    59,    28,    69,    70,    71,    72,    73,    59,    37,
      37,    77,    88,    18,    19,    59,    34,    29,   174,   175,
      38,    35,   142,   143,    30,    31,    32,    33,    81,    82,
     160,    97,   120,    61,    30,    31,    32,    33,    62,   173,
      69,    97,   121,   122,    34,    83,    51,    84,   100,    63,
     142,   143,    98,    99,    34,    41,   101,   199,   100,    30,
      31,    32,    33,   157,    49,   158,   101,   200,   201,   206,
     207,   158,   158,    42,    30,    31,    32,    33,    37,    34,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   177,   178,    34,    43,    44,   179,   182,   144,
     186,   189,    45,    47,   194,    46,   145,   146,   147,    30,
      31,    32,    33,    52,   148,   149,   150,   151,    30,    31,
      32,    33,    48,    50,   152,    56,    53,   180,   181,    34,
      30,    31,    32,    33,    66,    57,   184,   185,    34,    30,
      31,    32,    33,    54,   128,   129,    55,    60,   187,   188,
      34,    78,   130,   131,   132,   133,    74,   192,   193,    34,
     135,   136,   134,    80,    79,    85,    89,   117,   137,   138,
       1,     2,     3,     4,     5,     6,    90,    91,   139,    92,
      93,   126,     7,     8,     9,   108,   109,   110,   111,   154,
     153,   155,   156,   190,   159,   176,   183,   191,   195,   196,
     197,   204,   142,   205,    40,   198,   208,   209,    59,   210,
       0,   119,     0,     0,     0,     0,     0,     0,   112
};

static const yytype_int16 yycheck[] =
{
       8,    57,    58,    87,   159,    89,    18,    43,    13,    31,
      94,    95,    13,    97,    19,    13,   100,   101,     0,    41,
      42,     3,     4,     5,     6,     7,     8,     2,     2,     4,
       5,     5,    10,    15,    16,    17,    23,    24,    25,    26,
     195,    53,    11,    51,    52,    53,    54,    55,    53,    57,
      58,    59,    53,     9,    10,    53,    43,    43,   142,   143,
      18,    48,    34,    35,    23,    24,    25,    26,    21,    22,
     126,    30,    31,    27,    23,    24,    25,    26,    32,    51,
      88,    30,    41,    42,    43,    51,    14,    53,    47,    43,
      34,    35,    41,    42,    43,    52,    55,    31,    47,    23,
      24,    25,    26,    51,    55,    53,    55,    41,    42,    51,
      51,    53,    53,    52,    23,    24,    25,    26,   126,    43,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    41,    42,    43,    52,    52,   145,   146,    29,
     148,   149,    52,    43,   152,    52,    36,    37,    38,    23,
      24,    25,    26,    55,    44,    45,    46,    47,    23,    24,
      25,    26,    43,    43,    54,    56,    55,    41,    42,    43,
      23,    24,    25,    26,    12,    18,    41,    42,    43,    23,
      24,    25,    26,    55,    36,    37,    55,    43,    41,    42,
      43,    13,    44,    45,    46,    47,    43,    41,    42,    43,
      36,    37,    54,    33,    55,    55,    54,    53,    44,    45,
       3,     4,     5,     6,     7,     8,    51,    51,    54,    51,
      51,    20,    15,    16,    17,    43,    55,    55,    55,    43,
      28,    41,    41,    41,    55,    42,    31,    41,    55,    51,
      51,    30,    34,    30,    10,    51,    31,    31,    53,    51,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    84
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    15,    16,    17,
      58,    59,    60,    61,    62,    63,    75,    77,     9,    10,
      76,    78,    76,    78,    43,    78,    76,    78,    11,    43,
      23,    24,    25,    26,    43,    48,    64,    72,    18,     0,
      59,    52,    52,    52,    52,    52,    52,    43,    43,    55,
      43,    14,    55,    55,    55,    55,    56,    18,    18,    53,
      43,    27,    32,    43,    79,    80,    12,    65,    66,    72,
      72,    72,    72,    72,    43,    64,    64,    72,    13,    55,
      33,    21,    22,    51,    53,    55,    74,    13,    53,    54,
      51,    51,    51,    51,    13,    13,    19,    30,    41,    42,
      47,    55,    67,    68,    69,    70,    71,    72,    43,    55,
      55,    55,    79,    31,    41,    42,    73,    53,    67,    66,
      31,    41,    42,    67,    67,    67,    20,    67,    36,    37,
      44,    45,    46,    47,    54,    36,    37,    44,    45,    54,
      67,    67,    34,    35,    29,    36,    37,    38,    44,    45,
      46,    47,    54,    28,    43,    41,    41,    51,    53,    55,
      64,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    51,    67,    67,    42,    41,    42,    72,
      41,    42,    72,    31,    41,    42,    72,    41,    42,    72,
      41,    41,    41,    42,    72,    55,    51,    51,    51,    31,
      41,    42,    73,    73,    30,    30,    51,    51,    31,    31,
      51
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
#line 64 "yacc.y"
    {
	
		;}
    break;

  case 3:
#line 68 "yacc.y"
    {
	
		;}
    break;

  case 4:
#line 73 "yacc.y"
    {
	
	;}
    break;

  case 5:
#line 77 "yacc.y"
    {
	
	;}
    break;

  case 6:
#line 81 "yacc.y"
    {

	;}
    break;

  case 7:
#line 85 "yacc.y"
    {

	;}
    break;

  case 8:
#line 89 "yacc.y"
    {

	;}
    break;

  case 9:
#line 93 "yacc.y"
    {

	;}
    break;

  case 10:
#line 100 "yacc.y"
    {
		hxtot=hxtot+1;
		if (hxtot == 52)
			int hx= 0;
		terminal.insertIntoValues((yyvsp[(3) - (5)].strValue), (yyvsp[(5) - (5)].ValueEntityLists));
	;}
    break;

  case 11:
#line 110 "yacc.y"
    {
		terminal.updateTable((yyvsp[(2) - (6)].strValue), (yyvsp[(4) - (6)].assignLists), (yyvsp[(6) - (6)].expr));
		(yyvsp[(6) - (6)].expr)->deleteExpr();
		delete (yyvsp[(6) - (6)].expr);
	;}
    break;

  case 12:
#line 118 "yacc.y"
    {
		terminal.selectFromTable((yyvsp[(2) - (6)].dbIdentLists), (yyvsp[(4) - (6)].dbIdentLists), (yyvsp[(6) - (6)].expr));	
		(yyvsp[(6) - (6)].expr)->deleteExpr();
		delete (yyvsp[(6) - (6)].expr);
	;}
    break;

  case 13:
#line 124 "yacc.y"
    {
		terminal.selectAllFromTable((yyvsp[(4) - (6)].dbIdentLists), (yyvsp[(6) - (6)].expr));
		(yyvsp[(6) - (6)].expr)->deleteExpr();
		delete (yyvsp[(6) - (6)].expr);
	;}
    break;

  case 14:
#line 130 "yacc.y"
    {
		Expr * con = new ConstExpr();
		terminal.selectFromTable((yyvsp[(2) - (4)].dbIdentLists), (yyvsp[(4) - (4)].dbIdentLists), con);	
		delete con;
	;}
    break;

  case 15:
#line 136 "yacc.y"
    {
		Expr * con = new ConstExpr();
		terminal.selectAllFromTable((yyvsp[(4) - (4)].dbIdentLists), con);
		delete con;
	;}
    break;

  case 16:
#line 142 "yacc.y"
    {
		terminal.selectFromTable((yyvsp[(2) - (7)].dbIdentLists), (yyvsp[(4) - (7)].dbIdentLists), (yyvsp[(7) - (7)].dbIdentLists));
	;}
    break;

  case 17:
#line 148 "yacc.y"
    {
		terminal.deleteTable((yyvsp[(3) - (5)].strValue), (yyvsp[(5) - (5)].expr));
		(yyvsp[(5) - (5)].expr)->deleteExpr();
		delete (yyvsp[(5) - (5)].expr);
	;}
    break;

  case 18:
#line 160 "yacc.y"
    {
		(yyval.dbIdentLists).push_back((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 19:
#line 165 "yacc.y"
    {
		(yyval.dbIdentLists).clear();
		(yyval.dbIdentLists).push_back((yyvsp[(1) - (1)].dbIdent));
	;}
    break;

  case 20:
#line 172 "yacc.y"
    {
		(yyval.assignLists).push_back((yyvsp[(3) - (3)].assign));
	;}
    break;

  case 21:
#line 176 "yacc.y"
    {
		(yyval.assignLists).clear();
		(yyval.assignLists).push_back((yyvsp[(1) - (1)].assign));
	;}
    break;

  case 22:
#line 183 "yacc.y"
    {
		(yyval.assign) = Assign((yyvsp[(1) - (3)].dbIdent), (yyvsp[(3) - (3)].strValue));	
	;}
    break;

  case 23:
#line 187 "yacc.y"
    {
		(yyval.assign) = Assign((yyvsp[(1) - (3)].dbIdent), (yyvsp[(3) - (3)].intValue));
	;}
    break;

  case 24:
#line 191 "yacc.y"
    {
		(yyval.assign) = Assign((yyvsp[(1) - (3)].dbIdent));
	;}
    break;

  case 25:
#line 195 "yacc.y"
    {
		(yyval.assign) = Assign((yyvsp[(1) - (3)].dbIdent), (yyvsp[(3) - (3)].expr));
	;}
    break;

  case 26:
#line 201 "yacc.y"
    {
		(yyval.expr) = (yyvsp[(1) - (1)].expr);
	;}
    break;

  case 27:
#line 205 "yacc.y"
    {
		(yyval.expr) = (yyvsp[(1) - (1)].expr);
	;}
    break;

  case 28:
#line 209 "yacc.y"
    {
		(yyval.expr) = (yyvsp[(1) - (1)].expr);
	;}
    break;

  case 29:
#line 213 "yacc.y"
    {
		(yyval.expr) = (yyvsp[(1) - (1)].expr);
	;}
    break;

  case 30:
#line 217 "yacc.y"
    {
		(yyval.expr) = new Unary((yyvsp[(2) - (3)].expr));
		(yyval.expr) -> setType(TREE_OP_EQ);
	;}
    break;

  case 31:
#line 222 "yacc.y"
    {
		(yyval.expr) = new Binary((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));
		(yyval.expr) -> setType(TREE_OP_AND);
	;}
    break;

  case 32:
#line 227 "yacc.y"
    {
		(yyval.expr) = new Binary((yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));
		(yyval.expr) -> setType(TREE_OP_OR);
	;}
    break;

  case 33:
#line 232 "yacc.y"
    {
		(yyval.expr) = new Unary((yyvsp[(2) - (2)].expr));
		(yyval.expr) -> setType(TREE_OP_NOT);
	;}
    break;

  case 34:
#line 237 "yacc.y"
    {
		(yyval.expr) = new Unary((yyvsp[(2) - (2)].expr));
		(yyval.expr) -> setType(TREE_OP_NEG);
	;}
    break;

  case 35:
#line 244 "yacc.y"
    {
		(yyval.expr) = new Id2Num((yyvsp[(3) - (3)].intValue));
		(yyval.expr) -> setType(TREE_OP_PLUS);
		(yyval.expr) -> setDBIdent((yyvsp[(1) - (3)].dbIdent));
	;}
    break;

  case 36:
#line 250 "yacc.y"
    {
		(yyval.expr) = new Id2Num((yyvsp[(3) - (3)].intValue));
		(yyval.expr) -> setType(TREE_OP_MINUS);
		(yyval.expr) -> setDBIdent((yyvsp[(1) - (3)].dbIdent));
	;}
    break;

  case 37:
#line 256 "yacc.y"
    {
		(yyval.expr) = new Id2Num((yyvsp[(1) - (3)].intValue));
		(yyval.expr) -> setType(TREE_OP_PLUS);
		(yyval.expr) -> setDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 38:
#line 262 "yacc.y"
    {
		(yyval.expr) = new Id2Num((yyvsp[(1) - (3)].intValue));
		(yyval.expr) -> setType(TREE_OP_MINUS1);
		(yyval.expr) -> setDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 39:
#line 268 "yacc.y"
    {
		(yyval.expr) = new Id2Num((yyvsp[(3) - (3)].intValue));
		(yyval.expr) -> setType(TREE_OP_GT);
		(yyval.expr) -> setDBIdent((yyvsp[(1) - (3)].dbIdent));
	;}
    break;

  case 40:
#line 274 "yacc.y"
    {
		(yyval.expr) = new Id2Num((yyvsp[(3) - (3)].intValue));
		(yyval.expr) -> setType(TREE_OP_LT);
		(yyval.expr) -> setDBIdent((yyvsp[(1) - (3)].dbIdent));
	;}
    break;

  case 41:
#line 280 "yacc.y"
    {
		(yyval.expr) = new Id2Num((yyvsp[(3) - (3)].intValue));
		(yyval.expr) -> setType(TREE_OP_EQ);
		(yyval.expr) -> setDBIdent((yyvsp[(1) - (3)].dbIdent));
	;}
    break;

  case 42:
#line 286 "yacc.y"
    {
		(yyval.expr) = new Id2Num((yyvsp[(3) - (3)].intValue));
		(yyval.expr) -> setType(TREE_OP_GE);
		(yyval.expr) -> setDBIdent((yyvsp[(1) - (3)].dbIdent));
	;}
    break;

  case 43:
#line 292 "yacc.y"
    {
		(yyval.expr) = new Id2Num((yyvsp[(3) - (3)].intValue));
		(yyval.expr) -> setType(TREE_OP_LE);
		(yyval.expr) -> setDBIdent((yyvsp[(1) - (3)].dbIdent));
	;}
    break;

  case 44:
#line 298 "yacc.y"
    {
		(yyval.expr) = new Id2Num((yyvsp[(1) - (3)].intValue));
		(yyval.expr) -> setType(TREE_OP_LT);
		(yyval.expr) -> setDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 45:
#line 304 "yacc.y"
    {
		(yyval.expr) = new Id2Num((yyvsp[(1) - (3)].intValue));
		(yyval.expr) -> setType(TREE_OP_GT);
		(yyval.expr) -> setDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 46:
#line 310 "yacc.y"
    {
		(yyval.expr) = new Id2Num((yyvsp[(1) - (3)].intValue));
		(yyval.expr) -> setType(TREE_OP_EQ);
		(yyval.expr) -> setDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 47:
#line 316 "yacc.y"
    {
		(yyval.expr) = new Id2Num((yyvsp[(1) - (3)].intValue));
		(yyval.expr) -> setType(TREE_OP_LE);
		(yyval.expr) -> setDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 48:
#line 322 "yacc.y"
    {
		(yyval.expr) = new Id2Num((yyvsp[(1) - (3)].intValue));
		(yyval.expr) -> setType(TREE_OP_GE);
		(yyval.expr) -> setDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 49:
#line 330 "yacc.y"
    {
		(yyval.expr) = new Id2Str((yyvsp[(3) - (3)].strValue));
		(yyval.expr) -> setType(TREE_OP_GT);
		(yyval.expr) -> setDBIdent((yyvsp[(1) - (3)].dbIdent));
	;}
    break;

  case 50:
#line 336 "yacc.y"
    {
		(yyval.expr) = new Id2Str((yyvsp[(3) - (3)].strValue));
		(yyval.expr) -> setType(TREE_OP_LT);
		(yyval.expr) -> setDBIdent((yyvsp[(1) - (3)].dbIdent));
	;}
    break;

  case 51:
#line 342 "yacc.y"
    {
		(yyval.expr) = new Id2Str((yyvsp[(3) - (3)].strValue));
		(yyval.expr) -> setType(TREE_OP_EQ);
		(yyval.expr) -> setDBIdent((yyvsp[(1) - (3)].dbIdent));
	;}
    break;

  case 52:
#line 348 "yacc.y"
    {
		(yyval.expr) = new Id2Str((yyvsp[(3) - (3)].strValue));
		(yyval.expr) -> setType(TREE_OP_GE);
		(yyval.expr) -> setDBIdent((yyvsp[(1) - (3)].dbIdent));
	;}
    break;

  case 53:
#line 354 "yacc.y"
    {
		(yyval.expr) = new Id2Str((yyvsp[(3) - (3)].strValue));
		(yyval.expr) -> setType(TREE_OP_LE);
		(yyval.expr) -> setDBIdent((yyvsp[(1) - (3)].dbIdent));
	;}
    break;

  case 54:
#line 360 "yacc.y"
    {
		(yyval.expr) = new Id2Str((yyvsp[(1) - (3)].strValue));
		(yyval.expr) -> setType(TREE_OP_LT);
		(yyval.expr) -> setDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 55:
#line 366 "yacc.y"
    {
		(yyval.expr) = new Id2Str((yyvsp[(1) - (3)].strValue));
		(yyval.expr) -> setType(TREE_OP_GT);
		(yyval.expr) -> setDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 56:
#line 372 "yacc.y"
    {
		(yyval.expr) = new Id2Str((yyvsp[(1) - (3)].strValue));
		(yyval.expr) -> setType(TREE_OP_EQ);
		(yyval.expr) -> setDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 57:
#line 378 "yacc.y"
    {
		(yyval.expr) = new Id2Str((yyvsp[(1) - (3)].strValue));
		(yyval.expr) -> setType(TREE_OP_LE);
		(yyval.expr) -> setDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 58:
#line 384 "yacc.y"
    {
		(yyval.expr) = new Id2Str((yyvsp[(1) - (3)].strValue));
		(yyval.expr) -> setType(TREE_OP_GE);
		(yyval.expr) -> setDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 59:
#line 390 "yacc.y"
    {
		(yyval.expr) = new Id2Str(regexChange((yyvsp[(3) - (3)].strValue)));
		(yyval.expr) -> setType(TREE_OP_EQ);
		(yyval.expr) -> setDBIdent((yyvsp[(1) - (3)].dbIdent));
	;}
    break;

  case 60:
#line 398 "yacc.y"
    {
		(yyval.expr) = new Id2Id();
		(yyval.expr) -> setType(TREE_OP_GT);
		(yyval.expr) -> setLefDBIdent((yyvsp[(1) - (3)].dbIdent));
		(yyval.expr) -> setRigDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 61:
#line 405 "yacc.y"
    {
		(yyval.expr) = new Id2Id();
		(yyval.expr) -> setType(TREE_OP_LT);
		(yyval.expr) -> setLefDBIdent((yyvsp[(1) - (3)].dbIdent));
		(yyval.expr) -> setRigDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 62:
#line 412 "yacc.y"
    {
		(yyval.expr) = new Id2Id();
		(yyval.expr) -> setType(TREE_OP_EQ);
		(yyval.expr) -> setLefDBIdent((yyvsp[(1) - (3)].dbIdent));
		(yyval.expr) -> setRigDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 63:
#line 419 "yacc.y"
    {
		(yyval.expr) = new Id2Id();
		(yyval.expr) -> setType(TREE_OP_GE);
		(yyval.expr) -> setLefDBIdent((yyvsp[(1) - (3)].dbIdent));
		(yyval.expr) -> setRigDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 64:
#line 426 "yacc.y"
    {
		(yyval.expr) = new Id2Id();
		(yyval.expr) -> setType(TREE_OP_LE);
		(yyval.expr) -> setLefDBIdent((yyvsp[(1) - (3)].dbIdent));
		(yyval.expr) -> setRigDBIdent((yyvsp[(3) - (3)].dbIdent));
	;}
    break;

  case 65:
#line 435 "yacc.y"
    {
		(yyval.expr) = new IdIsNULL();
		(yyval.expr) -> setType(TREE_OP_IS);
		(yyval.expr) -> setDBIdent((yyvsp[(1) - (3)].dbIdent));
	;}
    break;

  case 66:
#line 443 "yacc.y"
    {
		(yyval.dbIdent).work = -1;
		(yyval.dbIdent).table = (yyvsp[(1) - (3)].strValue);
		(yyval.dbIdent).ident = (yyvsp[(3) - (3)].strValue);
	;}
    break;

  case 67:
#line 449 "yacc.y"
    {
		(yyval.dbIdent).work = -1;
		(yyval.dbIdent).table = "";
		(yyval.dbIdent).ident = (yyvsp[(1) - (1)].strValue);
	;}
    break;

  case 68:
#line 455 "yacc.y"
    {
		(yyval.dbIdent) = (yyvsp[(3) - (4)].dbIdent);
		(yyval.dbIdent).work = 0;
	;}
    break;

  case 69:
#line 460 "yacc.y"
    {
		(yyval.dbIdent) = (yyvsp[(3) - (4)].dbIdent);
		(yyval.dbIdent).work = 1;
	;}
    break;

  case 70:
#line 465 "yacc.y"
    {
		(yyval.dbIdent) = (yyvsp[(3) - (4)].dbIdent);
		(yyval.dbIdent).work = 2;
	;}
    break;

  case 71:
#line 470 "yacc.y"
    {
		(yyval.dbIdent) = (yyvsp[(3) - (4)].dbIdent);
		(yyval.dbIdent).work = 3;
	;}
    break;

  case 72:
#line 477 "yacc.y"
    {
		(yyval.PriceEntityLists).clear();
		(yyval.PriceEntityLists).push_back(PriceEntity((yyvsp[(1) - (1)].intValue), 0));
	;}
    break;

  case 73:
#line 482 "yacc.y"
    {
		(yyval.PriceEntityLists).clear();
		(yyval.PriceEntityLists).push_back(PriceEntity((yyvsp[(1) - (1)].strValue), 0));
	;}
    break;

  case 74:
#line 487 "yacc.y"
    {
		(yyval.PriceEntityLists).clear();
		(yyval.PriceEntityLists).push_back(PriceEntity(0, 1));
	;}
    break;

  case 75:
#line 492 "yacc.y"
    {
		(yyval.PriceEntityLists).push_back(PriceEntity(0, 1));	
	;}
    break;

  case 76:
#line 496 "yacc.y"
    {
		(yyval.PriceEntityLists).push_back(PriceEntity((yyvsp[(3) - (3)].intValue), 0));
	;}
    break;

  case 77:
#line 500 "yacc.y"
    {
		(yyval.PriceEntityLists).push_back(PriceEntity((yyvsp[(3) - (3)].strValue), 0));
	;}
    break;

  case 78:
#line 506 "yacc.y"
    {
		(yyval.ValueEntityLists).clear();
		(yyval.ValueEntityLists).push_back((yyvsp[(2) - (3)].PriceEntityLists));
	;}
    break;

  case 79:
#line 511 "yacc.y"
    {
		(yyval.ValueEntityLists).push_back((yyvsp[(4) - (5)].PriceEntityLists));
	;}
    break;

  case 80:
#line 517 "yacc.y"
    {
		terminal.createDatabase((yyvsp[(2) - (2)].strValue));
	;}
    break;

  case 81:
#line 521 "yacc.y"
    {
		terminal.dropDatabase((yyvsp[(2) - (2)].strValue));
	;}
    break;

  case 82:
#line 525 "yacc.y"
    {
		terminal.showDatabase((yyvsp[(2) - (2)].strValue));
	;}
    break;

  case 83:
#line 529 "yacc.y"
    {
		terminal.useDatabase((yyvsp[(2) - (2)].strValue));
	;}
    break;

  case 84:
#line 535 "yacc.y"
    {
		(yyval.strValue) = (yyvsp[(2) - (2)].strValue);
	;}
    break;

  case 85:
#line 542 "yacc.y"
    {
		terminal.createTable((yyvsp[(2) - (5)].strValue), (yyvsp[(4) - (5)].TableEntityLists));
	;}
    break;

  case 86:
#line 546 "yacc.y"
    {
		terminal.dropTable((yyvsp[(2) - (2)].strValue));
	;}
    break;

  case 87:
#line 550 "yacc.y"
    {
		terminal.showTable((yyvsp[(2) - (2)].strValue));
	;}
    break;

  case 88:
#line 554 "yacc.y"
    {
		terminal.showTable((yyvsp[(2) - (2)].strValue));
	;}
    break;

  case 89:
#line 560 "yacc.y"
    {
		(yyval.strValue) = (yyvsp[(2) - (2)].strValue);
	;}
    break;

  case 90:
#line 566 "yacc.y"
    {
				(yyval.tableEntity) = TableEntity((yyvsp[(1) - (5)].strValue), "int", (yyvsp[(4) - (5)].intValue), 0);
			;}
    break;

  case 91:
#line 570 "yacc.y"
    {
				(yyval.tableEntity) = TableEntity((yyvsp[(1) - (5)].strValue), "varchar", (yyvsp[(4) - (5)].intValue), 0);
			;}
    break;

  case 92:
#line 574 "yacc.y"
    {
				(yyval.tableEntity) = TableEntity((yyvsp[(1) - (7)].strValue), "int", (yyvsp[(4) - (7)].intValue), 1);
			;}
    break;

  case 93:
#line 578 "yacc.y"
    {
				(yyval.tableEntity) = TableEntity((yyvsp[(1) - (7)].strValue), "varchar", (yyvsp[(4) - (7)].intValue), 1);
			;}
    break;

  case 94:
#line 582 "yacc.y"
    {
				(yyval.tableEntity) = TableEntity((yyvsp[(4) - (5)].strValue), "", 0, 0, 1);
			;}
    break;

  case 95:
#line 586 "yacc.y"
    {
				(yyval.tableEntity) = TableEntity((yyvsp[(3) - (8)].strValue), (yyvsp[(6) - (8)].PriceEntityLists));
			;}
    break;

  case 96:
#line 592 "yacc.y"
    {
				(yyval.TableEntityLists).push_back((yyvsp[(3) - (3)].tableEntity));
			;}
    break;

  case 97:
#line 596 "yacc.y"
    {
				(yyval.TableEntityLists).clear();
				(yyval.TableEntityLists).push_back((yyvsp[(1) - (1)].tableEntity));
			;}
    break;


/* Line 1267 of yacc.c.  */
#line 2380 "yacc.tab.c"
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


#line 601 "yacc.y"


void yyerror(const char *s)	{
	printf("err!\n");
}

int main()
{
		yyparse();
	return 0;
}

