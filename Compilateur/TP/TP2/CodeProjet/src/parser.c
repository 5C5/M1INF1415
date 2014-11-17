/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "src/parser.y"


#include <cstddef>
#include "tdi.h"
#include "tds.h"

extern int yyerror ( char* );
extern int yylex ();

int context;
//on crée une variable globale pour contenir le contexte, pour l'optimisation

/* Line 371 of yacc.c  */
#line 81 "src/parser.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "parser.h".  */
#ifndef YY_YY_SRC_PARSER_H_INCLUDED
# define YY_YY_SRC_PARSER_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_PROGRAM = 258,
     KW_CONST = 259,
     KW_TYPE = 260,
     KW_VAR = 261,
     KW_ARRAY = 262,
     KW_OF = 263,
     KW_RECORD = 264,
     KW_BEGIN = 265,
     KW_END = 266,
     KW_DIV = 267,
     KW_MOD = 268,
     KW_AND = 269,
     KW_OR = 270,
     KW_XOR = 271,
     KW_NOT = 272,
     KW_IF = 273,
     KW_THEN = 274,
     KW_ELSE = 275,
     KW_WHILE = 276,
     KW_DO = 277,
     KW_REPEAT = 278,
     KW_UNTIL = 279,
     KW_FOR = 280,
     KW_TO = 281,
     KW_DOWNTO = 282,
     KW_PROC = 283,
     KW_FUNC = 284,
     KW_INTEGER = 285,
     KW_REAL = 286,
     KW_BOOLEAN = 287,
     KW_CHAR = 288,
     KW_STRING = 289,
     KW_WRITE = 290,
     KW_WRITELN = 291,
     KW_READ = 292,
     SEP_SCOL = 293,
     SEP_DOT = 294,
     SEP_DOTS = 295,
     SEP_DOTDOT = 296,
     SEP_COMMA = 297,
     SEP_CO = 298,
     SEP_CF = 299,
     SEP_PO = 300,
     SEP_PF = 301,
     OP_EQ = 302,
     OP_NEQ = 303,
     OP_LT = 304,
     OP_LTE = 305,
     OP_GT = 306,
     OP_GTE = 307,
     OP_ADD = 308,
     OP_SUB = 309,
     OP_MUL = 310,
     OP_SLASH = 311,
     OP_EXP = 312,
     OP_AFFECT = 313,
     TOK_IDENT = 314,
     TOK_INTEGER = 315,
     TOK_REAL = 316,
     TOK_BOOLEAN = 317,
     TOK_CHAR = 318,
     TOK_STRING = 319,
     OP_POS = 320,
     OP_NEG = 321,
     OP_PTR = 322,
     OP_DOT = 323,
     KW_IFX = 324
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 14 "src/parser.y"

	int ident;		/* Numéro de l'identificateur*/
	int valentier;
	double valreel;
	int valbooleen;
	char valcar;
	char* valchaine;
	int nb_arg;		/* Nombre d'argument d'une fonction*/
	char* type;		// chaine de caractère pour faire remonter les types lors de l'analyse


/* Line 387 of yacc.c  */
#line 205 "src/parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_SRC_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 233 "src/parser.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   464

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNRULES -- Number of states.  */
#define YYNSTATES  249

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    11,    17,    22,    25,    26,    29,
      31,    36,    43,    46,    47,    50,    52,    57,    59,    61,
      63,    65,    67,    69,    71,    73,    75,    77,    79,    81,
      83,    87,    91,    93,    97,    99,   101,   103,   110,   112,
     114,   118,   122,   124,   128,   131,   132,   135,   137,   142,
     146,   148,   151,   152,   156,   158,   160,   162,   166,   168,
     171,   174,   178,   182,   184,   186,   188,   192,   197,   201,
     204,   208,   211,   214,   218,   223,   226,   230,   232,   237,
     242,   251,   256,   263,   267,   272,   274,   279,   284,   289,
     291,   293,   295,   297,   299,   301,   303,   305,   307,   312,
     316,   320,   324,   328,   332,   336,   340,   343,   346,   350,
     354,   358,   362,   366,   370,   374,   378,   382,   385,   389,
     391,   393,   395,   397,   399,   401,   406,   410,   414
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      71,     0,    -1,    72,    38,    73,    39,    -1,     3,    59,
      -1,    75,    78,    94,    98,   113,    -1,    75,    78,    94,
     113,    -1,     4,    76,    -1,    -1,    76,    77,    -1,    77,
      -1,    59,    47,   117,    38,    -1,    59,    40,    84,    47,
     117,    38,    -1,     5,    79,    -1,    -1,    79,    80,    -1,
      80,    -1,    59,    47,    81,    38,    -1,    82,    -1,    83,
      -1,    85,    -1,    87,    -1,    89,    -1,    91,    -1,    84,
      -1,    59,    -1,    30,    -1,    31,    -1,    32,    -1,    33,
      -1,    34,    -1,    45,    86,    46,    -1,    86,    42,    59,
      -1,    59,    -1,    88,    41,    88,    -1,    59,    -1,    60,
      -1,    63,    -1,     7,    43,    90,    44,     8,    83,    -1,
      59,    -1,    87,    -1,     9,    92,    11,    -1,    92,    38,
      93,    -1,    93,    -1,    97,    40,    83,    -1,     6,    95,
      -1,    -1,    95,    96,    -1,    96,    -1,    97,    40,    83,
      38,    -1,    97,    42,    59,    -1,    59,    -1,    99,    38,
      -1,    -1,    99,    38,   100,    -1,   100,    -1,   101,    -1,
     109,    -1,   102,    38,    74,    -1,   103,    -1,   103,   104,
      -1,    28,    59,    -1,    45,   105,    46,    -1,   105,    38,
     106,    -1,   106,    -1,   107,    -1,   108,    -1,    97,    40,
      83,    -1,     6,    97,    40,    83,    -1,   110,    38,    74,
      -1,   111,   112,    -1,   111,   104,   112,    -1,    29,    59,
      -1,    40,    83,    -1,    10,   114,    11,    -1,    10,   114,
      38,    11,    -1,    10,    11,    -1,   114,    38,   115,    -1,
     115,    -1,    21,   117,    22,   115,    -1,    23,   114,    24,
     117,    -1,    25,    59,    58,   117,   116,   117,    22,   115,
      -1,    18,   117,    19,   115,    -1,    18,   117,    19,   115,
      20,   115,    -1,   122,    58,   117,    -1,    59,    45,   123,
      46,    -1,    59,    -1,    35,    45,   123,    46,    -1,    36,
      45,   123,    46,    -1,    37,    45,   122,    46,    -1,    36,
      -1,   113,    -1,    26,    -1,    27,    -1,   118,    -1,   119,
      -1,   120,    -1,   121,    -1,   122,    -1,    59,    45,   123,
      46,    -1,   117,    53,   117,    -1,   117,    54,   117,    -1,
     117,    55,   117,    -1,   117,    56,   117,    -1,   117,    12,
     117,    -1,   117,    13,   117,    -1,   117,    57,   117,    -1,
      54,   117,    -1,    53,   117,    -1,   117,    47,   117,    -1,
     117,    48,   117,    -1,   117,    49,   117,    -1,   117,    50,
     117,    -1,   117,    51,   117,    -1,   117,    52,   117,    -1,
     117,    14,   117,    -1,   117,    15,   117,    -1,   117,    16,
     117,    -1,    17,   117,    -1,    45,   117,    46,    -1,    60,
      -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,    59,
      -1,   122,    43,   117,    44,    -1,   122,    39,    59,    -1,
     123,    42,   117,    -1,   117,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   126,   129,   132,   135,   136,   139,   140,
     143,   144,   147,   148,   151,   152,   155,   158,   159,   162,
     163,   164,   165,   168,   169,   172,   173,   174,   175,   176,
     179,   182,   183,   186,   189,   190,   191,   194,   197,   198,
     201,   204,   205,   208,   211,   212,   215,   216,   219,   222,
     223,   226,   227,   230,   231,   234,   235,   238,   241,   242,
     245,   248,   251,   252,   255,   256,   259,   262,   265,   268,
     269,   272,   275,   278,   279,   280,   283,   284,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   302,   303,   306,   307,   308,   309,   310,   311,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   325,   326,
     327,   328,   329,   330,   333,   334,   335,   336,   339,   340,
     341,   342,   343,   344,   347,   348,   349,   352,   353
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_PROGRAM", "KW_CONST", "KW_TYPE",
  "KW_VAR", "KW_ARRAY", "KW_OF", "KW_RECORD", "KW_BEGIN", "KW_END",
  "KW_DIV", "KW_MOD", "KW_AND", "KW_OR", "KW_XOR", "KW_NOT", "KW_IF",
  "KW_THEN", "KW_ELSE", "KW_WHILE", "KW_DO", "KW_REPEAT", "KW_UNTIL",
  "KW_FOR", "KW_TO", "KW_DOWNTO", "KW_PROC", "KW_FUNC", "KW_INTEGER",
  "KW_REAL", "KW_BOOLEAN", "KW_CHAR", "KW_STRING", "KW_WRITE",
  "KW_WRITELN", "KW_READ", "SEP_SCOL", "SEP_DOT", "SEP_DOTS", "SEP_DOTDOT",
  "SEP_COMMA", "SEP_CO", "SEP_CF", "SEP_PO", "SEP_PF", "OP_EQ", "OP_NEQ",
  "OP_LT", "OP_LTE", "OP_GT", "OP_GTE", "OP_ADD", "OP_SUB", "OP_MUL",
  "OP_SLASH", "OP_EXP", "OP_AFFECT", "TOK_IDENT", "TOK_INTEGER",
  "TOK_REAL", "TOK_BOOLEAN", "TOK_CHAR", "TOK_STRING", "OP_POS", "OP_NEG",
  "OP_PTR", "OP_DOT", "KW_IFX", "$accept", "Program", "ProgramHeader",
  "Block", "BlockSimple", "BlockDeclConst", "ListDeclConst", "DeclConst",
  "BlockDeclType", "ListDeclType", "DeclType", "Type", "UserType",
  "SimpleType", "BaseType", "EnumType", "ListEnumValue", "InterType",
  "InterBase", "ArrayType", "ArrayIndex", "RecordType", "RecordFields",
  "RecordField", "BlockDeclVar", "ListDeclVar", "DeclVar", "ListIdent",
  "BlockDeclFunc", "ListDeclFunc", "DeclFunc", "ProcDecl", "ProcHeader",
  "ProcIdent", "FormalArgs", "ListFormalArgs", "FormalArg", "ValFormalArg",
  "VarFormalArg", "FuncDecl", "FuncHeader", "FuncIdent", "FuncResult",
  "BlockCode", "ListInstr", "Instr", "ForDirection", "Expression",
  "MathExpr", "CompExpr", "BoolExpr", "AtomExpr", "VarExpr", "ListeExpr", YY_NULL
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    73,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    81,    81,    82,
      82,    82,    82,    83,    83,    84,    84,    84,    84,    84,
      85,    86,    86,    87,    88,    88,    88,    89,    90,    90,
      91,    92,    92,    93,    94,    94,    95,    95,    96,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   102,   102,
     103,   104,   105,   105,   106,   106,   107,   108,   109,   110,
     110,   111,   112,   113,   113,   113,   114,   114,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   116,   116,   117,   117,   117,   117,   117,   117,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   119,   119,
     119,   119,   119,   119,   120,   120,   120,   120,   121,   121,
     121,   121,   121,   121,   122,   122,   122,   123,   123
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     5,     4,     2,     0,     2,     1,
       4,     6,     2,     0,     2,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     3,     1,     1,     1,     6,     1,     1,
       3,     3,     1,     3,     2,     0,     2,     1,     4,     3,
       1,     2,     0,     3,     1,     1,     1,     3,     1,     2,
       2,     3,     3,     1,     1,     1,     3,     4,     3,     2,
       3,     2,     2,     3,     4,     2,     3,     1,     4,     4,
       8,     4,     6,     3,     4,     1,     4,     4,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     1,     7,     0,     0,    13,
       0,     6,     9,     2,     0,    45,     0,     0,     8,     0,
      12,    15,     0,    52,    25,    26,    27,    28,    29,     0,
       0,     0,     0,     0,   124,   119,   120,   121,   122,   123,
       0,    93,    94,    95,    96,    97,     0,    14,    50,    44,
      47,     0,     0,     0,     0,     0,    54,    55,     0,    58,
      56,     0,     0,     0,   117,     0,   107,   106,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,    35,    36,     0,    17,    18,    23,    19,    20,
       0,    21,    22,    46,     0,     0,    60,    71,     0,     4,
      51,     7,     0,    59,     7,     0,     0,    69,     0,   118,
     128,     0,   103,   104,   114,   115,   116,   108,   109,   110,
     111,   112,   113,    99,   100,   101,   102,   105,   126,     0,
       0,     0,    42,     0,    32,     0,    16,     0,    24,     0,
      49,    75,     0,     0,     0,     0,     0,    89,     0,    85,
      90,     0,    77,     0,    53,    57,    13,     0,     0,     0,
      63,    64,    65,    68,    72,    70,    11,     0,    98,   125,
      34,    39,     0,    40,     0,     0,     0,    30,    34,    33,
      48,     0,     0,     0,     0,     0,     0,     0,     0,    73,
       0,     0,    45,     0,     0,     0,    61,   127,     0,    41,
      43,    31,     0,     0,     0,     0,     0,     0,     0,   124,
       0,     0,    74,    76,    83,     0,     0,    66,    62,     0,
      81,    78,    79,     0,    86,    87,    88,    84,     5,    67,
      37,     0,    91,    92,     0,    82,     0,     0,    80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,   165,   166,    11,    12,    15,    20,
      21,    94,    95,    96,    97,    98,   145,    99,   100,   101,
     182,   102,   141,   142,    23,    49,    50,    51,    54,    55,
      56,    57,    58,    59,   113,   169,   170,   171,   172,    60,
      61,    62,   117,   160,   161,   162,   244,   120,    41,    42,
      43,    44,    45,   121
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -173
static const yytype_int16 yypact[] =
{
       0,   -36,    35,    10,  -173,  -173,    33,    19,    49,   116,
      36,    19,  -173,  -173,    63,   121,   149,   141,  -173,    94,
      63,  -173,    88,    -7,  -173,  -173,  -173,  -173,  -173,   103,
     141,   141,   141,   141,   117,  -173,  -173,  -173,  -173,  -173,
     208,  -173,  -173,  -173,  -173,     6,    70,  -173,  -173,    88,
    -173,    92,   102,   108,   163,   147,  -173,  -173,   152,   146,
    -173,   154,    44,   141,   139,   220,   139,   139,   141,   141,
     141,   141,   141,   141,  -173,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   148,   141,   155,    88,
     170,   165,  -173,  -173,   192,  -173,  -173,  -173,  -173,  -173,
     167,  -173,  -173,  -173,   -23,   172,  -173,  -173,   128,  -173,
      -7,    33,    12,  -173,    33,   -23,   197,  -173,   266,  -173,
     361,     5,   139,   139,   139,    17,    17,   407,   407,   407,
     407,   407,   407,    17,    17,   139,   139,  -173,  -173,   280,
      22,    -6,  -173,   100,  -173,    52,  -173,    32,  -173,   200,
    -173,  -173,   141,   141,    89,   180,   195,   196,   198,    -1,
    -173,     1,  -173,    47,  -173,  -173,   116,    88,   114,   -12,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,   141,  -173,  -173,
     201,  -173,   203,  -173,    88,   -23,   183,  -173,  -173,  -173,
    -173,   293,   339,    -5,   186,   141,   141,   189,   141,  -173,
     134,   141,   121,   126,   -23,    12,  -173,   361,   241,  -173,
    -173,  -173,    89,    89,   141,    89,   141,    71,    74,  -173,
     -19,    77,  -173,  -173,   361,   163,   -23,  -173,  -173,   -23,
     230,  -173,   361,   162,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,    89,  -173,  -173,   141,  -173,   350,    89,  -173
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,  -173,  -173,   137,   246,  -173,   242,   118,  -173,
     234,  -173,  -173,   -98,   267,  -173,  -173,   145,   140,  -173,
    -173,  -173,  -173,   104,    84,  -173,   240,   -87,  -173,  -173,
     181,  -173,  -173,  -173,   228,  -173,    93,  -173,  -173,  -173,
    -173,  -173,   184,   -53,   143,  -172,  -173,   -17,  -173,  -173,
    -173,  -173,  -104,    30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -125
static const yytype_int16 yytable[] =
{
      40,   109,   143,     1,   163,   183,   149,    24,    25,    26,
      27,    28,   199,    64,    65,    66,    67,   174,   167,   214,
      86,    52,    53,     4,    87,   168,   205,   236,   223,    69,
      70,    71,   184,   215,   206,     5,   148,     7,  -124,   200,
     230,   231,  -124,   223,   198,    86,   118,   177,     6,    87,
     163,   178,   122,   123,   124,   125,   126,  -124,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   245,
     139,    48,    83,    84,    85,   248,    16,    88,    10,    89,
     203,   180,    92,    17,   115,    93,    86,   210,    13,   112,
      87,   188,    92,   220,   186,    93,   163,   143,   187,   108,
      24,    25,    26,    27,    28,   201,   227,   152,   163,   163,
     153,   163,   154,   177,   155,    90,   177,   234,   168,   177,
     235,    14,    19,   237,   156,   157,   158,    22,   239,    91,
      92,   240,   104,    93,   105,   191,   192,   163,   108,   151,
     185,    46,   105,   163,   108,   222,   152,    48,   159,   153,
      63,   154,   152,   155,   204,   153,   105,   154,    30,   155,
     207,   106,    68,   156,   157,   158,   226,   107,   105,   156,
     157,   158,   238,   108,    69,    70,    71,    72,    73,    24,
      25,    26,    27,    28,   224,   110,    31,   159,   242,   243,
     111,   112,   114,   159,    32,    33,    85,   232,   140,   233,
      34,    35,    36,    37,    38,    39,   -34,   138,   147,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      69,    70,    71,    72,    73,   217,   218,   246,   221,   144,
     146,   150,    69,    70,    71,    72,    73,   115,   190,   194,
     195,   196,   211,   197,   216,   -38,    74,   208,   219,   229,
     241,   173,     9,    18,    47,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,   119,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    69,    70,
      71,    72,    73,    29,   202,   181,   225,   189,   209,   103,
     116,   164,    69,    70,    71,    72,    73,   193,   228,     0,
     175,     0,     0,     0,   176,    69,    70,    71,    72,    73,
       0,     0,   212,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,   179,     0,     0,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    69,    70,    71,    72,    73,     0,     0,     0,     0,
       0,   213,    69,    70,    71,    72,    73,     0,     0,     0,
       0,     0,   247,    69,    70,    71,    72,    73,     0,     0,
       0,     0,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    69,
      70,    71,    72,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -125,  -125,  -125,  -125,  -125,  -125,
      81,    82,    83,    84,    85
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-173)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-125)))

static const yytype_int16 yycheck[] =
{
      17,    54,    89,     3,   108,    11,   104,    30,    31,    32,
      33,    34,    11,    30,    31,    32,    33,   115,     6,    24,
      39,    28,    29,    59,    43,   112,    38,    46,   200,    12,
      13,    14,    38,    38,    46,     0,    59,     4,    39,    38,
     212,   213,    43,   215,    45,    39,    63,    42,    38,    43,
     154,    46,    69,    70,    71,    72,    73,    58,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   241,
      87,    59,    55,    56,    57,   247,    40,     7,    59,     9,
     167,    59,    60,    47,    40,    63,    39,   185,    39,    45,
      43,    59,    60,   197,    42,    63,   200,   184,    46,    10,
      30,    31,    32,    33,    34,    58,   204,    18,   212,   213,
      21,   215,    23,    42,    25,    45,    42,    46,   205,    42,
      46,     5,    59,    46,    35,    36,    37,     6,   226,    59,
      60,   229,    40,    63,    42,   152,   153,   241,    10,    11,
      40,    47,    42,   247,    10,    11,    18,    59,    59,    21,
      47,    23,    18,    25,    40,    21,    42,    23,    17,    25,
     177,    59,    45,    35,    36,    37,    40,    59,    42,    35,
      36,    37,   225,    10,    12,    13,    14,    15,    16,    30,
      31,    32,    33,    34,   201,    38,    45,    59,    26,    27,
      38,    45,    38,    59,    53,    54,    57,   214,    43,   216,
      59,    60,    61,    62,    63,    64,    41,    59,    41,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      12,    13,    14,    15,    16,   195,   196,   244,   198,    59,
      38,    59,    12,    13,    14,    15,    16,    40,    38,    59,
      45,    45,    59,    45,    58,    44,    38,    44,    59,     8,
      20,   114,     6,    11,    20,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    12,    13,
      14,    15,    16,    16,   166,   140,   202,   147,   184,    49,
      62,   110,    12,    13,    14,    15,    16,   154,   205,    -1,
     116,    -1,    -1,    -1,    38,    12,    13,    14,    15,    16,
      -1,    -1,    19,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    22,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    22,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    71,    72,    59,     0,    38,     4,    73,    75,
      59,    76,    77,    39,     5,    78,    40,    47,    77,    59,
      79,    80,     6,    94,    30,    31,    32,    33,    34,    84,
      17,    45,    53,    54,    59,    60,    61,    62,    63,    64,
     117,   118,   119,   120,   121,   122,    47,    80,    59,    95,
      96,    97,    28,    29,    98,    99,   100,   101,   102,   103,
     109,   110,   111,    47,   117,   117,   117,   117,    45,    12,
      13,    14,    15,    16,    38,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    39,    43,     7,     9,
      45,    59,    60,    63,    81,    82,    83,    84,    85,    87,
      88,    89,    91,    96,    40,    42,    59,    59,    10,   113,
      38,    38,    45,   104,    38,    40,   104,   112,   117,    46,
     117,   123,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,    59,   117,
      43,    92,    93,    97,    59,    86,    38,    41,    59,    83,
      59,    11,    18,    21,    23,    25,    35,    36,    37,    59,
     113,   114,   115,   122,   100,    74,    75,     6,    97,   105,
     106,   107,   108,    74,    83,   112,    38,    42,    46,    44,
      59,    87,    90,    11,    38,    40,    42,    46,    59,    88,
      38,   117,   117,   114,    59,    45,    45,    45,    45,    11,
      38,    58,    78,    97,    40,    38,    46,   117,    44,    93,
      83,    59,    19,    22,    24,    38,    58,   123,   123,    59,
     122,   123,    11,   115,   117,    94,    40,    83,   106,     8,
     115,   115,   117,   117,    46,    46,    46,    46,   113,    83,
      83,    20,    26,    27,   116,   115,   117,    22,   115
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      
/* Line 1792 of yacc.c  */
#line 1704 "src/parser.c"
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


/* Line 2055 of yacc.c  */
#line 356 "src/parser.y"

