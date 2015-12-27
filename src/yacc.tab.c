/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc.y" /* yacc.c:339  */

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


#line 89 "yacc.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yacc.tab.h".  */
#ifndef YY_YY_YACC_TAB_H_INCLUDED
# define YY_YY_YACC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 179 "yacc.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   249

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    67,    72,    76,    80,    84,    88,    92,
      99,   106,   114,   120,   126,   132,   138,   144,   155,   160,
     168,   172,   179,   183,   187,   193,   197,   201,   205,   209,
     214,   219,   224,   229,   236,   242,   248,   254,   260,   266,
     272,   278,   284,   290,   298,   304,   310,   316,   322,   328,
     334,   340,   346,   352,   358,   366,   373,   380,   387,   394,
     403,   411,   417,   423,   428,   433,   438,   445,   450,   455,
     460,   464,   468,   474,   479,   485,   489,   493,   497,   503,
     510,   514,   518,   522,   528,   534,   538,   542,   546,   550,
     554,   560,   564
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "TableStmt", "TableIdent", "TableEntity", "TableEntityList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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

#define YYPACT_NINF -150

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-150)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     175,    21,    21,   -36,     9,    21,    16,   -28,    50,    17,
     169,  -150,   -11,    30,    40,    43,    55,    84,   113,   114,
    -150,   106,  -150,  -150,  -150,  -150,  -150,  -150,   122,   157,
     115,   133,   134,   138,   -18,    46,   -14,  -150,   151,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,    67,
     183,    -3,    -3,    -3,    -3,    -3,   153,    -3,    -3,    -3,
     186,   145,   168,   111,  -150,   -17,   147,    -1,  -150,   149,
     154,   155,   158,   159,  -150,     5,    -5,  -150,    36,   161,
     152,   160,   162,  -150,    67,    26,   163,    36,    -3,    74,
    -150,  -150,  -150,  -150,    36,    36,   188,    36,   -12,    64,
      36,    36,    37,  -150,  -150,  -150,  -150,    52,   184,   170,
     173,   177,  -150,  -150,  -150,  -150,    12,   164,    37,  -150,
    -150,  -150,  -150,    37,    37,    -3,  -150,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,  -150,    19,    36,
      36,   178,    61,    88,   180,   117,   121,   125,   166,   171,
     172,   174,  -150,   156,    26,   176,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,   190,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,    26,  -150,   196,   197,
    -150,  -150,  -150,   101,   102,   199,   200,  -150,   181,  -150,
    -150,  -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     0,     0,     0,     0,     0,     0,     0,
      75,     0,    76,    81,    78,    82,    77,    83,     0,     0,
       0,     0,     0,     0,    62,     0,     0,    19,     0,     1,
       2,     6,     7,     8,     9,     5,     4,    79,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,     0,    21,     0,
       0,     0,     0,     0,    61,    15,    14,    18,     0,     0,
       0,     0,     0,    80,     0,     0,    10,     0,     0,     0,
      63,    65,    66,    64,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    25,    26,    27,    28,     0,     0,     0,
       0,     0,    91,    69,    67,    68,     0,     0,    11,    20,
      24,    23,    22,    13,    12,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    73,     0,     0,    16,    43,    42,    40,    39,
      41,    53,    52,    50,    49,    51,    29,    30,    31,    54,
      38,    48,    59,    37,    47,    58,    60,    35,    45,    56,
      34,    44,    55,    36,    46,    57,     0,    89,    85,    86,
      70,    71,    72,     0,     0,     0,     0,    74,     0,    87,
      88,    90
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,   218,  -150,  -150,  -150,  -150,   -56,  -150,   146,
     -84,  -150,  -150,  -150,  -150,    -8,  -149,  -150,  -150,     4,
    -150,    24,   165,  -150
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,    15,    36,    67,    68,
     102,   103,   104,   105,   106,   107,   116,    86,    16,    20,
      17,    21,    64,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      37,    75,    76,   118,    58,   193,    22,    24,    95,    26,
     123,   124,    87,   126,    96,    29,   137,   138,    94,    19,
      30,    31,    32,    33,   127,   128,    23,    28,    25,    27,
      18,    19,   129,   130,    83,    38,    84,   194,    56,    59,
      34,    41,   131,    69,    70,    71,    72,    73,    59,    37,
      37,    77,    88,   139,   140,   167,   168,   113,    59,    30,
      31,    32,    33,   152,    57,   153,    97,   114,   115,   155,
     166,   139,   140,    30,    31,    32,    33,    98,    99,    34,
      69,   141,    42,   100,    30,    31,    32,    33,   142,   143,
     144,   101,    43,    34,    61,    44,   145,   146,    35,    62,
     132,   133,   170,   171,    34,   120,   147,    45,   134,   135,
      63,    30,    31,    32,    33,   121,   122,    37,   136,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   173,
     174,    34,    81,    82,   172,   175,    46,   179,   182,   185,
      30,    31,    32,    33,    30,    31,    32,    33,    30,    31,
      32,    33,   197,   198,   153,   153,    47,    48,   177,   178,
      34,    49,   180,   181,    34,    50,   183,   184,    34,    39,
      52,    51,     1,     2,     3,     4,     5,     6,     1,     2,
       3,     4,     5,     6,     7,     8,     9,   190,    53,    54,
       7,     8,     9,    55,    60,    66,    74,   191,   192,    78,
      79,    80,    85,    89,   108,    90,    91,   109,   125,    92,
      93,   176,   148,   149,   150,   110,   117,   111,   151,   154,
     169,   186,   187,   188,   139,   189,   195,   196,    40,    59,
     199,   200,   201,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112
};

static const yytype_int16 yycheck[] =
{
       8,    57,    58,    87,    18,   154,     2,    43,    13,     5,
      94,    95,    13,    97,    19,    43,   100,   101,    13,    10,
      23,    24,    25,    26,    36,    37,     2,    11,     4,     5,
       9,    10,    44,    45,    51,    18,    53,   186,    56,    53,
      43,    52,    54,    51,    52,    53,    54,    55,    53,    57,
      58,    59,    53,    34,    35,   139,   140,    31,    53,    23,
      24,    25,    26,    51,    18,    53,    30,    41,    42,   125,
      51,    34,    35,    23,    24,    25,    26,    41,    42,    43,
      88,    29,    52,    47,    23,    24,    25,    26,    36,    37,
      38,    55,    52,    43,    27,    52,    44,    45,    48,    32,
      36,    37,    41,    42,    43,    31,    54,    52,    44,    45,
      43,    23,    24,    25,    26,    41,    42,   125,    54,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,    41,
      42,    43,    21,    22,   142,   143,    52,   145,   146,   147,
      23,    24,    25,    26,    23,    24,    25,    26,    23,    24,
      25,    26,    51,    51,    53,    53,    43,    43,    41,    42,
      43,    55,    41,    42,    43,    43,    41,    42,    43,     0,
      55,    14,     3,     4,     5,     6,     7,     8,     3,     4,
       5,     6,     7,     8,    15,    16,    17,    31,    55,    55,
      15,    16,    17,    55,    43,    12,    43,    41,    42,    13,
      55,    33,    55,    54,    43,    51,    51,    55,    20,    51,
      51,    31,    28,    43,    41,    55,    53,    55,    41,    55,
      42,    55,    51,    51,    34,    51,    30,    30,    10,    53,
      31,    31,    51,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84
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
      31,    41,    42,    67,    67,    20,    67,    36,    37,    44,
      45,    54,    36,    37,    44,    45,    54,    67,    67,    34,
      35,    29,    36,    37,    38,    44,    45,    54,    28,    43,
      41,    41,    51,    53,    55,    64,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    51,    67,    67,    42,
      41,    42,    72,    41,    42,    72,    31,    41,    42,    72,
      41,    42,    72,    41,    42,    72,    55,    51,    51,    51,
      31,    41,    42,    73,    73,    30,    30,    51,    51,    31,
      31,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      60,    61,    62,    62,    62,    62,    62,    63,    64,    64,
      65,    65,    66,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    70,    70,    70,
      71,    72,    72,    72,    72,    72,    72,    73,    73,    73,
      73,    73,    73,    74,    74,    75,    75,    75,    75,    76,
      77,    77,    77,    77,    78,    79,    79,    79,    79,    79,
      79,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     2,     2,     2,     2,
       5,     6,     6,     6,     4,     4,     7,     5,     3,     1,
       3,     1,     3,     3,     3,     1,     1,     1,     1,     3,
       3,     3,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     4,     4,     4,     4,     1,     1,     1,
       3,     3,     3,     3,     5,     2,     2,     2,     2,     2,
       5,     2,     2,     2,     2,     5,     5,     7,     7,     5,
       8,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 63 "yacc.y" /* yacc.c:1646  */
    {
	
		}
#line 1404 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "yacc.y" /* yacc.c:1646  */
    {
	
		}
#line 1412 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 72 "yacc.y" /* yacc.c:1646  */
    {
	
	}
#line 1420 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 76 "yacc.y" /* yacc.c:1646  */
    {
	
	}
#line 1428 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 80 "yacc.y" /* yacc.c:1646  */
    {

	}
#line 1436 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 84 "yacc.y" /* yacc.c:1646  */
    {

	}
#line 1444 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 88 "yacc.y" /* yacc.c:1646  */
    {

	}
#line 1452 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 92 "yacc.y" /* yacc.c:1646  */
    {

	}
#line 1460 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 99 "yacc.y" /* yacc.c:1646  */
    {
		terminal.insertIntoValues((yyvsp[-2].strValue), (yyvsp[0].ValueEntityLists));
	}
#line 1468 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 106 "yacc.y" /* yacc.c:1646  */
    {
		terminal.updateTable((yyvsp[-4].strValue), (yyvsp[-2].assignLists), (yyvsp[0].expr));
		(yyvsp[0].expr)->deleteExpr();
		delete (yyvsp[0].expr);
	}
#line 1478 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 114 "yacc.y" /* yacc.c:1646  */
    {
		terminal.selectFromTable((yyvsp[-4].dbIdentLists), (yyvsp[-2].dbIdentLists), (yyvsp[0].expr));	
		(yyvsp[0].expr)->deleteExpr();
		delete (yyvsp[0].expr);
	}
#line 1488 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 120 "yacc.y" /* yacc.c:1646  */
    {
		terminal.selectAllFromTable((yyvsp[-2].dbIdentLists), (yyvsp[0].expr));
		(yyvsp[0].expr)->deleteExpr();
		delete (yyvsp[0].expr);
	}
#line 1498 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 126 "yacc.y" /* yacc.c:1646  */
    {
		Expr * con = new ConstExpr();
		terminal.selectFromTable((yyvsp[-2].dbIdentLists), (yyvsp[0].dbIdentLists), con);	
		delete con;
	}
#line 1508 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 132 "yacc.y" /* yacc.c:1646  */
    {
		Expr * con = new ConstExpr();
		terminal.selectAllFromTable((yyvsp[0].dbIdentLists), con);
		delete con;
	}
#line 1518 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 138 "yacc.y" /* yacc.c:1646  */
    {
		terminal.selectFromTable((yyvsp[-5].dbIdentLists), (yyvsp[-3].dbIdentLists), (yyvsp[0].dbIdentLists));
	}
#line 1526 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 144 "yacc.y" /* yacc.c:1646  */
    {
		terminal.deleteTable((yyvsp[-2].strValue), (yyvsp[0].expr));
		(yyvsp[0].expr)->deleteExpr();
		delete (yyvsp[0].expr);
	}
#line 1536 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 156 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.dbIdentLists).push_back((yyvsp[0].dbIdent));
	}
#line 1544 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 161 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.dbIdentLists).clear();
		(yyval.dbIdentLists).push_back((yyvsp[0].dbIdent));
	}
#line 1553 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 168 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.assignLists).push_back((yyvsp[0].assign));
	}
#line 1561 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 172 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.assignLists).clear();
		(yyval.assignLists).push_back((yyvsp[0].assign));
	}
#line 1570 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 179 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.assign) = Assign((yyvsp[-2].dbIdent), (yyvsp[0].strValue));	
	}
#line 1578 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 183 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.assign) = Assign((yyvsp[-2].dbIdent), (yyvsp[0].intValue));
	}
#line 1586 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 187 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.assign) = Assign((yyvsp[-2].dbIdent));
	}
#line 1594 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 193 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = (yyvsp[0].expr);
	}
#line 1602 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 197 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = (yyvsp[0].expr);
	}
#line 1610 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 201 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = (yyvsp[0].expr);
	}
#line 1618 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 205 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = (yyvsp[0].expr);
	}
#line 1626 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 209 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Unary((yyvsp[-1].expr));
		(yyval.expr) -> setType(TREE_OP_EQ);
	}
#line 1635 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 214 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Binary((yyvsp[-2].expr), (yyvsp[0].expr));
		(yyval.expr) -> setType(TREE_OP_AND);
	}
#line 1644 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 219 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Binary((yyvsp[-2].expr), (yyvsp[0].expr));
		(yyval.expr) -> setType(TREE_OP_OR);
	}
#line 1653 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 224 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Unary((yyvsp[0].expr));
		(yyval.expr) -> setType(TREE_OP_NOT);
	}
#line 1662 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 229 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Unary((yyvsp[0].expr));
		(yyval.expr) -> setType(TREE_OP_NEG);
	}
#line 1671 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 236 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Num((yyvsp[0].intValue));
		(yyval.expr) -> setType(TREE_OP_GT);
		(yyval.expr) -> setDBIdent((yyvsp[-2].dbIdent));
	}
#line 1681 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 242 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Num((yyvsp[0].intValue));
		(yyval.expr) -> setType(TREE_OP_LT);
		(yyval.expr) -> setDBIdent((yyvsp[-2].dbIdent));
	}
#line 1691 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 248 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Num((yyvsp[0].intValue));
		(yyval.expr) -> setType(TREE_OP_EQ);
		(yyval.expr) -> setDBIdent((yyvsp[-2].dbIdent));
	}
#line 1701 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 254 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Num((yyvsp[0].intValue));
		(yyval.expr) -> setType(TREE_OP_GE);
		(yyval.expr) -> setDBIdent((yyvsp[-2].dbIdent));
	}
#line 1711 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 260 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Num((yyvsp[0].intValue));
		(yyval.expr) -> setType(TREE_OP_LE);
		(yyval.expr) -> setDBIdent((yyvsp[-2].dbIdent));
	}
#line 1721 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 266 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Num((yyvsp[-2].intValue));
		(yyval.expr) -> setType(TREE_OP_LT);
		(yyval.expr) -> setDBIdent((yyvsp[0].dbIdent));
	}
#line 1731 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 272 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Num((yyvsp[-2].intValue));
		(yyval.expr) -> setType(TREE_OP_GT);
		(yyval.expr) -> setDBIdent((yyvsp[0].dbIdent));
	}
#line 1741 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 278 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Num((yyvsp[-2].intValue));
		(yyval.expr) -> setType(TREE_OP_EQ);
		(yyval.expr) -> setDBIdent((yyvsp[0].dbIdent));
	}
#line 1751 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 284 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Num((yyvsp[-2].intValue));
		(yyval.expr) -> setType(TREE_OP_LE);
		(yyval.expr) -> setDBIdent((yyvsp[0].dbIdent));
	}
#line 1761 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 290 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Num((yyvsp[-2].intValue));
		(yyval.expr) -> setType(TREE_OP_GE);
		(yyval.expr) -> setDBIdent((yyvsp[0].dbIdent));
	}
#line 1771 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 298 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Str((yyvsp[0].strValue));
		(yyval.expr) -> setType(TREE_OP_GT);
		(yyval.expr) -> setDBIdent((yyvsp[-2].dbIdent));
	}
#line 1781 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 304 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Str((yyvsp[0].strValue));
		(yyval.expr) -> setType(TREE_OP_LT);
		(yyval.expr) -> setDBIdent((yyvsp[-2].dbIdent));
	}
#line 1791 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 310 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Str((yyvsp[0].strValue));
		(yyval.expr) -> setType(TREE_OP_EQ);
		(yyval.expr) -> setDBIdent((yyvsp[-2].dbIdent));
	}
#line 1801 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 316 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Str((yyvsp[0].strValue));
		(yyval.expr) -> setType(TREE_OP_GE);
		(yyval.expr) -> setDBIdent((yyvsp[-2].dbIdent));
	}
#line 1811 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 322 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Str((yyvsp[0].strValue));
		(yyval.expr) -> setType(TREE_OP_LE);
		(yyval.expr) -> setDBIdent((yyvsp[-2].dbIdent));
	}
#line 1821 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 328 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Str((yyvsp[-2].strValue));
		(yyval.expr) -> setType(TREE_OP_LT);
		(yyval.expr) -> setDBIdent((yyvsp[0].dbIdent));
	}
#line 1831 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 334 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Str((yyvsp[-2].strValue));
		(yyval.expr) -> setType(TREE_OP_GT);
		(yyval.expr) -> setDBIdent((yyvsp[0].dbIdent));
	}
#line 1841 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 340 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Str((yyvsp[-2].strValue));
		(yyval.expr) -> setType(TREE_OP_EQ);
		(yyval.expr) -> setDBIdent((yyvsp[0].dbIdent));
	}
#line 1851 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 346 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Str((yyvsp[-2].strValue));
		(yyval.expr) -> setType(TREE_OP_LE);
		(yyval.expr) -> setDBIdent((yyvsp[0].dbIdent));
	}
#line 1861 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 352 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Str((yyvsp[-2].strValue));
		(yyval.expr) -> setType(TREE_OP_GE);
		(yyval.expr) -> setDBIdent((yyvsp[0].dbIdent));
	}
#line 1871 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 358 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Str(regexChange((yyvsp[0].strValue)));
		(yyval.expr) -> setType(TREE_OP_EQ);
		(yyval.expr) -> setDBIdent((yyvsp[-2].dbIdent));
	}
#line 1881 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 366 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Id();
		(yyval.expr) -> setType(TREE_OP_GT);
		(yyval.expr) -> setLefDBIdent((yyvsp[-2].dbIdent));
		(yyval.expr) -> setRigDBIdent((yyvsp[0].dbIdent));
	}
#line 1892 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 373 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Id();
		(yyval.expr) -> setType(TREE_OP_LT);
		(yyval.expr) -> setLefDBIdent((yyvsp[-2].dbIdent));
		(yyval.expr) -> setRigDBIdent((yyvsp[0].dbIdent));
	}
#line 1903 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 380 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Id();
		(yyval.expr) -> setType(TREE_OP_EQ);
		(yyval.expr) -> setLefDBIdent((yyvsp[-2].dbIdent));
		(yyval.expr) -> setRigDBIdent((yyvsp[0].dbIdent));
	}
#line 1914 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 387 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Id();
		(yyval.expr) -> setType(TREE_OP_GE);
		(yyval.expr) -> setLefDBIdent((yyvsp[-2].dbIdent));
		(yyval.expr) -> setRigDBIdent((yyvsp[0].dbIdent));
	}
#line 1925 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 394 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new Id2Id();
		(yyval.expr) -> setType(TREE_OP_LE);
		(yyval.expr) -> setLefDBIdent((yyvsp[-2].dbIdent));
		(yyval.expr) -> setRigDBIdent((yyvsp[0].dbIdent));
	}
#line 1936 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 403 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.expr) = new IdIsNULL();
		(yyval.expr) -> setType(TREE_OP_IS);
		(yyval.expr) -> setDBIdent((yyvsp[-2].dbIdent));
	}
#line 1946 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 411 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.dbIdent).work = -1;
		(yyval.dbIdent).table = (yyvsp[-2].strValue);
		(yyval.dbIdent).ident = (yyvsp[0].strValue);
	}
#line 1956 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 417 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.dbIdent).work = -1;
		(yyval.dbIdent).table = "";
		(yyval.dbIdent).ident = (yyvsp[0].strValue);
	}
#line 1966 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 423 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.dbIdent) = (yyvsp[-1].dbIdent);
		(yyval.dbIdent).work = 0;
	}
#line 1975 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 428 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.dbIdent) = (yyvsp[-1].dbIdent);
		(yyval.dbIdent).work = 1;
	}
#line 1984 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 433 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.dbIdent) = (yyvsp[-1].dbIdent);
		(yyval.dbIdent).work = 2;
	}
#line 1993 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 438 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.dbIdent) = (yyvsp[-1].dbIdent);
		(yyval.dbIdent).work = 3;
	}
#line 2002 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 445 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.PriceEntityLists).clear();
		(yyval.PriceEntityLists).push_back(PriceEntity((yyvsp[0].intValue), 0));
	}
#line 2011 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 450 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.PriceEntityLists).clear();
		(yyval.PriceEntityLists).push_back(PriceEntity((yyvsp[0].strValue), 0));
	}
#line 2020 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 455 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.PriceEntityLists).clear();
		(yyval.PriceEntityLists).push_back(PriceEntity(0, 1));
	}
#line 2029 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 460 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.PriceEntityLists).push_back(PriceEntity(0, 1));	
	}
#line 2037 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 464 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.PriceEntityLists).push_back(PriceEntity((yyvsp[0].intValue), 0));
	}
#line 2045 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 468 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.PriceEntityLists).push_back(PriceEntity((yyvsp[0].strValue), 0));
	}
#line 2053 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 474 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.ValueEntityLists).clear();
		(yyval.ValueEntityLists).push_back((yyvsp[-1].PriceEntityLists));
	}
#line 2062 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 479 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.ValueEntityLists).push_back((yyvsp[-1].PriceEntityLists));
	}
#line 2070 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 485 "yacc.y" /* yacc.c:1646  */
    {
		terminal.createDatabase((yyvsp[0].strValue));
	}
#line 2078 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 489 "yacc.y" /* yacc.c:1646  */
    {
		terminal.dropDatabase((yyvsp[0].strValue));
	}
#line 2086 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 493 "yacc.y" /* yacc.c:1646  */
    {
		terminal.showDatabase((yyvsp[0].strValue));
	}
#line 2094 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 497 "yacc.y" /* yacc.c:1646  */
    {
		terminal.useDatabase((yyvsp[0].strValue));
	}
#line 2102 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 503 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.strValue) = (yyvsp[0].strValue);
	}
#line 2110 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 510 "yacc.y" /* yacc.c:1646  */
    {
		terminal.createTable((yyvsp[-3].strValue), (yyvsp[-1].TableEntityLists));
	}
#line 2118 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 514 "yacc.y" /* yacc.c:1646  */
    {
		terminal.dropTable((yyvsp[0].strValue));
	}
#line 2126 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 518 "yacc.y" /* yacc.c:1646  */
    {
		terminal.showTable((yyvsp[0].strValue));
	}
#line 2134 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 522 "yacc.y" /* yacc.c:1646  */
    {
		terminal.showTable((yyvsp[0].strValue));
	}
#line 2142 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 528 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.strValue) = (yyvsp[0].strValue);
	}
#line 2150 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 534 "yacc.y" /* yacc.c:1646  */
    {
				(yyval.tableEntity) = TableEntity((yyvsp[-4].strValue), "int", (yyvsp[-1].intValue), 0);
			}
#line 2158 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 538 "yacc.y" /* yacc.c:1646  */
    {
				(yyval.tableEntity) = TableEntity((yyvsp[-4].strValue), "varchar", (yyvsp[-1].intValue), 0);
			}
#line 2166 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 542 "yacc.y" /* yacc.c:1646  */
    {
				(yyval.tableEntity) = TableEntity((yyvsp[-6].strValue), "int", (yyvsp[-3].intValue), 1);
			}
#line 2174 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 546 "yacc.y" /* yacc.c:1646  */
    {
				(yyval.tableEntity) = TableEntity((yyvsp[-6].strValue), "varchar", (yyvsp[-3].intValue), 1);
			}
#line 2182 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 550 "yacc.y" /* yacc.c:1646  */
    {
				(yyval.tableEntity) = TableEntity((yyvsp[-1].strValue), "", 0, 0, 1);
			}
#line 2190 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 554 "yacc.y" /* yacc.c:1646  */
    {
				(yyval.tableEntity) = TableEntity((yyvsp[-5].strValue), (yyvsp[-2].PriceEntityLists));
			}
#line 2198 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 560 "yacc.y" /* yacc.c:1646  */
    {
				(yyval.TableEntityLists).push_back((yyvsp[0].tableEntity));
			}
#line 2206 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 564 "yacc.y" /* yacc.c:1646  */
    {
				(yyval.TableEntityLists).clear();
				(yyval.TableEntityLists).push_back((yyvsp[0].tableEntity));
			}
#line 2215 "yacc.tab.c" /* yacc.c:1646  */
    break;


#line 2219 "yacc.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
  return yyresult;
}
#line 569 "yacc.y" /* yacc.c:1906  */


void yyerror(const char *s)	{
	printf("err!\n");
}

int main()
{
		yyparse();
	return 0;
}
