/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "jucompiler.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "y.tab.h"
int yydebug = 0;
int num_statements=0;

extern int linha_erro, coluna_erro, num_colunas, num_linhas, error_sequence,erro_sintaxe;
extern char* yytext;
int yylex (void);
void yyerror(char* s);

is_program* myprogram;


#line 84 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AND = 258,
    ASSIGN = 259,
    STAR = 260,
    COMMA = 261,
    DIV = 262,
    EQ = 263,
    GE = 264,
    GT = 265,
    LBRACE = 266,
    LE = 267,
    LPAR = 268,
    RPAR = 269,
    LSQ = 270,
    LT = 271,
    MINUS = 272,
    MOD = 273,
    NE = 274,
    NOT = 275,
    OR = 276,
    RBRACE = 277,
    RSQ = 278,
    SEMICOLON = 279,
    ARROW = 280,
    LSHIFT = 281,
    RSHIFT = 282,
    XOR = 283,
    BOOL = 284,
    CLASS = 285,
    DOTLENGTH = 286,
    DOUBLE = 287,
    ELSE = 288,
    IF = 289,
    INT = 290,
    PRINT = 291,
    PARSEINT = 292,
    PUBLIC = 293,
    RETURN = 294,
    STATIC = 295,
    STRING = 296,
    VOID = 297,
    WHILE = 298,
    RESERVED = 299,
    ID = 300,
    INTLIT = 301,
    STRLIT = 302,
    REALLIT = 303,
    BOOLLIT = 304,
    PLUS = 305,
    REDUCE = 306
  };
#endif
/* Tokens.  */
#define AND 258
#define ASSIGN 259
#define STAR 260
#define COMMA 261
#define DIV 262
#define EQ 263
#define GE 264
#define GT 265
#define LBRACE 266
#define LE 267
#define LPAR 268
#define RPAR 269
#define LSQ 270
#define LT 271
#define MINUS 272
#define MOD 273
#define NE 274
#define NOT 275
#define OR 276
#define RBRACE 277
#define RSQ 278
#define SEMICOLON 279
#define ARROW 280
#define LSHIFT 281
#define RSHIFT 282
#define XOR 283
#define BOOL 284
#define CLASS 285
#define DOTLENGTH 286
#define DOUBLE 287
#define ELSE 288
#define IF 289
#define INT 290
#define PRINT 291
#define PARSEINT 292
#define PUBLIC 293
#define RETURN 294
#define STATIC 295
#define STRING 296
#define VOID 297
#define WHILE 298
#define RESERVED 299
#define ID 300
#define INTLIT 301
#define STRLIT 302
#define REALLIT 303
#define BOOLLIT 304
#define PLUS 305
#define REDUCE 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 68 "jucompiler.y" /* yacc.c:355  */

    char * str;

    id_lin_col *id;

    is_program* ip;
    is_metodos* im;
    is_fielddecl_list* ifl;

    is_methoddecl_list* imdl;
    is_methodheader_list* imhl;
    is_methodparams_list* impl;
    is_methodbody_list* imbl;
    is_vardecl_list* ivdl;
    is_statment_list* state;
    is_expression_list* iel;

#line 244 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 261 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   377

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    88,    88,    91,    92,    93,    94,    97,   100,   103,
     104,   107,   108,   109,   113,   114,   117,   118,   119,   122,
     123,   126,   129,   130,   131,   134,   137,   138,   141,   142,
     145,   146,   147,   148,   149,   150,   151,   152,   156,   157,
     160,   161,   164,   165,   171,   174,   175,   178,   179,   183,
     190,   191,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   227,
     230,   232,   235,   238
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "ASSIGN", "STAR", "COMMA", "DIV",
  "EQ", "GE", "GT", "LBRACE", "LE", "LPAR", "RPAR", "LSQ", "LT", "MINUS",
  "MOD", "NE", "NOT", "OR", "RBRACE", "RSQ", "SEMICOLON", "ARROW",
  "LSHIFT", "RSHIFT", "XOR", "BOOL", "CLASS", "DOTLENGTH", "DOUBLE",
  "ELSE", "IF", "INT", "PRINT", "PARSEINT", "PUBLIC", "RETURN", "STATIC",
  "STRING", "VOID", "WHILE", "RESERVED", "ID", "INTLIT", "STRLIT",
  "REALLIT", "BOOLLIT", "PLUS", "REDUCE", "$accept", "program", "metodos",
  "MethodDecl", "FieldDecl", "FieldDeclNext", "Type", "MethodHeader",
  "MethodParams", "MethodParamsNext", "MethodBody", "body", "VarDecl",
  "VarDeclNext", "Statement", "StatementZrOuMais", "StatementExpOp",
  "StatementPrint", "MethodInvocation", "ExpCommaExpOP",
  "CommaExprZrOuMais", "ParseArgs", "ExprA", "Expr", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF -46

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-46)))

#define YYTABLE_NINF -46

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,    11,    53,    46,   -46,     3,    52,     3,    45,    64,
       3,     3,   -46,   -46,    77,   -46,   -46,   -46,   -46,   -46,
     -46,    42,    49,    84,    83,    23,   243,   -46,   216,    56,
     216,    80,    92,   265,   -46,    95,   112,   114,   321,   117,
      -1,    87,   113,   243,   243,   110,   115,   125,    96,   134,
     146,   142,   -46,   -46,   265,   135,   321,   283,     5,   116,
     327,   327,    79,   -46,   -46,   -46,   327,   136,   -46,   -46,
     -46,    72,   321,   321,   101,   152,   -46,   -46,   -46,   -46,
     -46,   140,   153,   -46,   -46,   -46,   -46,   -46,   154,   -46,
     156,   -46,   161,   162,   165,   170,    -8,   -46,   -46,   321,
     -46,   -46,   -46,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   171,
     169,   172,   174,   183,   133,   176,   150,   -21,   -46,   282,
     178,   -46,   321,   -46,   -46,   -46,   189,   -46,   -46,    28,
     220,   220,   220,   220,   106,   -46,    28,   164,   137,   137,
     214,   106,   282,   -46,   -46,   -46,   321,   -46,   152,   -46,
     -46,   158,   177,   -46,   181,   -46,   183,   -46,   153,   282,
     195,   -46,   -46,   -46,   -46
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,    79,     6,     0,     2,     4,     5,    11,    13,
      12,     0,     0,     0,     0,     9,     0,     7,    16,     0,
      16,     0,     0,     0,    37,     0,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,     0,     8,    80,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    78,    76,    77,     0,     0,    72,    73,
      41,    50,     0,     0,     0,    26,    21,    23,    24,    34,
      36,     0,    19,    15,    10,    14,    39,    32,     0,    42,
       0,    43,     0,     0,     0,     0,    74,    69,    68,     0,
      75,    70,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     0,     0,    17,     0,
       0,    81,     0,    83,    71,    51,    52,    62,    63,    54,
      55,    56,    57,    58,    61,    64,    59,    53,    66,    67,
      65,    60,     0,    35,    82,    44,     0,    46,    26,    25,
      18,     0,    28,    33,     0,    30,    47,    27,    19,     0,
       0,    48,    20,    29,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,    32,   -46,   -46,   163,    -4,   -46,   182,    43,
     -46,     8,   -46,    60,   -32,   166,   -46,   -46,   -26,   -46,
      62,   -24,   -25,   -45
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    10,    11,    31,    41,    23,    49,   128,
      27,    42,    43,   125,    44,    55,    67,    90,    68,   122,
     157,    69,    70,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    54,    46,    73,     6,    74,    92,    45,    18,    46,
      22,    19,    74,     1,    20,    97,    98,    45,    45,    46,
      46,   101,    54,   100,    48,    -3,    48,     7,    45,    29,
      46,    88,    91,   104,    95,   105,    30,   107,   108,    13,
     109,     8,    16,    17,   110,   111,   112,   119,   120,   123,
      93,    77,    78,     4,   115,   116,     3,     5,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   135,   103,    12,   104,   118,   105,
     106,   107,   108,    99,   109,    14,    15,    24,   110,   111,
     112,   113,    74,   114,    25,    26,    28,   162,   115,   116,
     117,    50,   121,    45,    52,    46,    18,   164,    56,    19,
     100,   104,    20,   105,    59,   -45,    53,    94,    60,    21,
     165,    61,   118,   161,   112,    57,    45,    58,    46,    59,
      72,   166,    75,    60,    79,    76,    61,   173,    37,    80,
      81,    82,   104,    45,   105,    46,    62,    63,    83,    64,
      65,    66,    29,    37,   111,   112,    85,    87,   124,   127,
     102,    62,    63,   126,    64,    65,    66,   103,   129,   104,
     130,   105,   106,   107,   108,   131,   109,   132,   158,   133,
     110,   111,   112,   113,   134,   152,   154,   118,   155,   156,
     115,   116,   117,   153,   104,   160,   105,   106,   107,   108,
     159,   109,   163,   168,   170,   110,   111,   112,   113,   174,
     169,   172,    51,    84,   118,   115,   116,   117,   167,   104,
      86,   105,   106,   107,   108,   104,   109,   105,   171,     0,
     110,   111,   112,   113,     0,     0,     0,   111,   112,   118,
     115,   116,     0,     0,    32,    18,   115,   116,    19,     0,
       0,    20,     0,     0,    33,     0,     0,    47,     0,     0,
       0,     0,     0,     0,   118,   -22,    32,    34,     0,     0,
     118,     0,    18,     0,     0,    19,    33,    35,    20,    36,
      37,     0,    38,    32,     0,     0,    39,   -38,    40,    34,
       0,     0,     0,    33,     0,     0,    59,     0,     0,    35,
      60,    36,    37,    61,    38,     0,    34,     0,    39,     0,
      40,     0,     0,     0,     0,     0,    35,     0,    36,    37,
      37,    38,     0,     0,     0,    39,     0,    40,    62,    63,
      89,    64,    65,    66,    59,     0,     0,     0,    60,     0,
      59,    61,     0,     0,    60,     0,     0,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,    37,     0,    62,    63,     0,    64,
      65,    66,    96,    63,     0,    64,    65,    66
};

static const yytype_int16 yycheck[] =
{
      26,    33,    26,     4,     1,    13,     1,    33,    29,    33,
      14,    32,    13,    30,    35,    60,    61,    43,    44,    43,
      44,    66,    54,    31,    28,    22,    30,    24,    54,     6,
      54,    56,    57,     5,    59,     7,    13,     9,    10,     7,
      12,    38,    10,    11,    16,    17,    18,    72,    73,    74,
      45,    43,    44,     0,    26,    27,    45,    11,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    99,     3,    24,     5,    50,     7,
       8,     9,    10,     4,    12,    40,    22,    45,    16,    17,
      18,    19,    13,    21,    45,    11,    13,   129,    26,    27,
      28,    45,     1,   129,    24,   129,    29,   132,    13,    32,
      31,     5,    35,     7,    13,    14,    24,     1,    17,    42,
     152,    20,    50,   127,    18,    13,   152,    13,   152,    13,
      13,   156,    45,    17,    24,    22,    20,   169,    37,    24,
      15,    45,     5,   169,     7,   169,    45,    46,    14,    48,
      49,    50,     6,    37,    17,    18,    14,    22,     6,     6,
      24,    45,    46,    23,    48,    49,    50,     3,    14,     5,
      14,     7,     8,     9,    10,    14,    12,    15,    45,    14,
      16,    17,    18,    19,    14,    14,    14,    50,    14,     6,
      26,    27,    28,    24,     5,    45,     7,     8,     9,    10,
      24,    12,    24,    45,    23,    16,    17,    18,    19,    14,
      33,   168,    30,    50,    50,    26,    27,    28,   158,     5,
      54,     7,     8,     9,    10,     5,    12,     7,   166,    -1,
      16,    17,    18,    19,    -1,    -1,    -1,    17,    18,    50,
      26,    27,    -1,    -1,     1,    29,    26,    27,    32,    -1,
      -1,    35,    -1,    -1,    11,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    22,     1,    24,    -1,    -1,
      50,    -1,    29,    -1,    -1,    32,    11,    34,    35,    36,
      37,    -1,    39,     1,    -1,    -1,    43,    22,    45,    24,
      -1,    -1,    -1,    11,    -1,    -1,    13,    -1,    -1,    34,
      17,    36,    37,    20,    39,    -1,    24,    -1,    43,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    34,    -1,    36,    37,
      37,    39,    -1,    -1,    -1,    43,    -1,    45,    45,    46,
      47,    48,    49,    50,    13,    -1,    -1,    -1,    17,    -1,
      13,    20,    -1,    -1,    17,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    45,    46,    -1,    48,
      49,    50,    45,    46,    -1,    48,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    53,    45,     0,    11,     1,    24,    38,    54,
      55,    56,    24,    54,    40,    22,    54,    54,    29,    32,
      35,    42,    58,    59,    45,    45,    11,    62,    13,     6,
      13,    57,     1,    11,    24,    34,    36,    37,    39,    43,
      45,    58,    63,    64,    66,    70,    73,    41,    58,    60,
      45,    60,    24,    24,    66,    67,    13,    13,    13,    13,
      17,    20,    45,    46,    48,    49,    50,    68,    70,    73,
      74,    75,    13,     4,    13,    45,    22,    63,    63,    24,
      24,    15,    45,    14,    57,    14,    67,    22,    74,    47,
      69,    74,     1,    45,     1,    74,    45,    75,    75,     4,
      31,    75,    24,     3,     5,     7,     8,     9,    10,    12,
      16,    17,    18,    19,    21,    26,    27,    28,    50,    74,
      74,     1,    71,    74,     6,    65,    23,     6,    61,    14,
      14,    14,    15,    14,    14,    74,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    14,    24,    14,    14,     6,    72,    45,    24,
      45,    58,    66,    24,    74,    66,    74,    65,    45,    33,
      23,    72,    61,    66,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    54,    54,    55,    56,    57,
      57,    58,    58,    58,    59,    59,    60,    60,    60,    61,
      61,    62,    63,    63,    63,    64,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    71,    71,    72,    72,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    56,
      66,    73,    70,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     2,     2,     2,     4,     6,     0,
       3,     1,     1,     1,     5,     5,     0,     3,     4,     0,
       4,     3,     0,     2,     2,     4,     0,     3,     5,     7,
       5,     3,     3,     5,     2,     4,     2,     1,     0,     2,
       0,     1,     1,     1,     4,     0,     2,     0,     3,     7,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     3,     1,     1,     1,     2,     1,     1,     1,     2,
       2,     4,     4,     3
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
#line 88 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ip)=myprogram=insert_program((yyvsp[-3].id)->id, (yyvsp[-1].im), (yyvsp[-3].id)->linha, (yyvsp[-3].id)->coluna); free((yyvsp[-3].id)->id);}
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 91 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.im) = NULL;}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 92 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.im)=insert_metodos("Method",NULL,(yyvsp[-1].imdl),(yyvsp[0].im));}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 93 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.im)=insert_metodos("Field",(yyvsp[-1].ifl),NULL,(yyvsp[0].im));}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 94 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.im)=insert_metodos("Semicolon",NULL,NULL,(yyvsp[0].im));}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 97 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.imdl)=insert_methoddecl((yyvsp[-1].imhl),(yyvsp[0].imbl));}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 100 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ifl)=insert_field((yyvsp[-3].str),(yyvsp[-2].id)->id,(yyvsp[-1].ifl),(yyvsp[-2].id)->linha, (yyvsp[-2].id)->coluna );free((yyvsp[-2].id)->id);}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 103 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ifl) = NULL;}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 104 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ifl)=insert_field("",(yyvsp[-1].id)->id,(yyvsp[0].ifl),(yyvsp[-1].id)->linha, (yyvsp[-1].id)->coluna ); free((yyvsp[-1].id)->id);}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 107 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.str)="Bool";}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 108 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.str)="Int";}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 109 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.str)="Double";}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 113 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.imhl)=insert_methodheader((yyvsp[-4].str),(yyvsp[-3].id)->id,(yyvsp[-1].impl), (yyvsp[-3].id)->linha, (yyvsp[-3].id)->coluna );free((yyvsp[-3].id)->id);}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 114 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.imhl)=insert_methodheader("Void",(yyvsp[-3].id)->id,(yyvsp[-1].impl), (yyvsp[-3].id)->linha, (yyvsp[-3].id)->coluna);free((yyvsp[-3].id)->id);}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 117 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.impl) = NULL;}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 118 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.impl)=insert_methodparams((yyvsp[-2].str),(yyvsp[-1].id)->id,(yyvsp[0].impl) , (yyvsp[-1].id)->linha, (yyvsp[-1].id)->coluna);free((yyvsp[-1].id)->id);}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 119 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.impl)=insert_methodparams("StringArray",(yyvsp[0].id)->id,NULL, (yyvsp[-3].id)->linha, (yyvsp[-3].id)->coluna);free((yyvsp[0].id)->id);}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 122 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.impl) = NULL;}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 123 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.impl)=insert_methodparams((yyvsp[-2].str),(yyvsp[-1].id)->id,(yyvsp[0].impl), (yyvsp[-1].id)->linha, (yyvsp[-1].id)->coluna);free((yyvsp[-1].id)->id);}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 126 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.imbl) = (yyvsp[-1].imbl);}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 129 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.imbl) = NULL;}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 130 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.imbl)=insert_methodbody("VarDecl",(yyvsp[-1].ivdl),NULL,(yyvsp[0].imbl));}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 131 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.imbl)=insert_methodbody("Statement",NULL,(yyvsp[-1].state),(yyvsp[0].imbl));}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 134 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ivdl)=insert_vardecl((yyvsp[-3].str),(yyvsp[-2].id)->id,(yyvsp[-1].ivdl), (yyvsp[-2].id)->linha, (yyvsp[-2].id)->coluna);free((yyvsp[-2].id)->id);}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 137 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ivdl) = NULL;}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 138 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ivdl)=insert_vardecl("",(yyvsp[-1].id)->id,(yyvsp[0].ivdl), (yyvsp[-1].id)->linha, (yyvsp[-1].id)->coluna);free((yyvsp[-1].id)->id);}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 141 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("If", (yyvsp[-2].iel), (yyvsp[0].state), NULL);}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 142 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("IfElse", (yyvsp[-4].iel), (yyvsp[-2].state), (yyvsp[0].state));}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 145 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("While", (yyvsp[-2].iel), (yyvsp[0].state), NULL);}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 146 "jucompiler.y" /* yacc.c:1646  */
    {if((yyvsp[-1].iel)==NULL){(yyvsp[-1].iel)=insert_expr("Emp_Return","",NULL,NULL,(yyvsp[-2].id)->linha, (yyvsp[-2].id)->coluna,-1,-1);}     (yyval.state) = insert_multiple_statement("Return", (yyvsp[-1].iel), NULL, NULL);}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 147 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("Block", NULL, (yyvsp[-1].state), NULL);}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 148 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("Print", (yyvsp[-2].iel), NULL, NULL);}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 149 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("Call", (yyvsp[-1].iel), NULL, NULL);}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 150 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("AssignStatment", insert_expr("Assign",(yyvsp[-3].id)->id,(yyvsp[-1].iel),NULL, (yyvsp[-3].id)->linha,(yyvsp[-3].id)->coluna,(yyvsp[-2].id)->linha, (yyvsp[-2].id)->coluna), NULL, NULL );free((yyvsp[-3].id)->id);}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 151 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("ParseArgsStatment", (yyvsp[-1].iel),NULL, NULL);}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 152 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = NULL;}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 156 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = NULL;}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 157 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("Statment", NULL, (yyvsp[-1].state), (yyvsp[0].state));}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 160 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = NULL;}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 161 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = (yyvsp[0].iel);}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 164 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("StrLit",(yyvsp[0].id)->id,NULL,NULL, (yyvsp[0].id)->linha,(yyvsp[0].id)->coluna,-1,-1);free((yyvsp[0].id)->id);}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 165 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = (yyvsp[0].iel);}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 171 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Call",(yyvsp[-3].id)->id,(yyvsp[-1].iel),NULL, (yyvsp[-3].id)->linha,(yyvsp[-3].id)->coluna,-1,-1);free((yyvsp[-3].id)->id);}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 174 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = NULL;}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 175 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("CallMore","",(yyvsp[-1].iel),(yyvsp[0].iel), -1,-1,-1,-1);}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 178 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = NULL;}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 179 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("CallMore","",(yyvsp[-1].iel),(yyvsp[0].iel), -1,-1,-1,-1);}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 183 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("ParseArgs",(yyvsp[-4].id)->id,(yyvsp[-2].iel),NULL, (yyvsp[-6].id)->linha,(yyvsp[-6].id)->coluna,(yyvsp[-4].id)->linha,(yyvsp[-4].id)->coluna);free((yyvsp[-4].id)->id);}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 190 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = (yyvsp[0].iel);}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 191 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Assign",(yyvsp[-2].id)->id,(yyvsp[0].iel),NULL,(yyvsp[-2].id)->linha,(yyvsp[-2].id)->coluna,(yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna );free((yyvsp[-2].id)->id);}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 195 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","And",(yyvsp[-2].iel),(yyvsp[0].iel),(yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 196 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Or",(yyvsp[-2].iel),(yyvsp[0].iel), (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 197 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Eq",(yyvsp[-2].iel),(yyvsp[0].iel), (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 198 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Ge",(yyvsp[-2].iel),(yyvsp[0].iel), (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 199 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Gt",(yyvsp[-2].iel),(yyvsp[0].iel), (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 200 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Le",(yyvsp[-2].iel),(yyvsp[0].iel), (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 201 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Lt",(yyvsp[-2].iel),(yyvsp[0].iel), (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 202 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Ne",(yyvsp[-2].iel),(yyvsp[0].iel), (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 203 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Add",(yyvsp[-2].iel),(yyvsp[0].iel), (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 204 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Sub",(yyvsp[-2].iel),(yyvsp[0].iel), (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 205 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Mul",(yyvsp[-2].iel),(yyvsp[0].iel), (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 206 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Div",(yyvsp[-2].iel),(yyvsp[0].iel), (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 207 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Mod",(yyvsp[-2].iel),(yyvsp[0].iel), (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 208 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Xor",(yyvsp[-2].iel),(yyvsp[0].iel), (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 209 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Lshift",(yyvsp[-2].iel),(yyvsp[0].iel), (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 210 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Rshift",(yyvsp[-2].iel),(yyvsp[0].iel), (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 211 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Not",(yyvsp[0].iel),NULL, (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 212 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Minus",(yyvsp[0].iel),NULL, (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 213 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Plus",(yyvsp[0].iel),NULL, (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,-1,-1);}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 214 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = (yyvsp[-1].iel);}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 215 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = (yyvsp[0].iel);}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 216 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = (yyvsp[0].iel);}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 217 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Id",(yyvsp[0].id)->id,NULL,NULL, (yyvsp[0].id)->linha,(yyvsp[0].id)->coluna,-1,-1);free((yyvsp[0].id)->id);}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 218 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Length",(yyvsp[-1].id)->id,NULL,NULL, (yyvsp[-1].id)->linha,(yyvsp[-1].id)->coluna,(yyvsp[0].id)->linha, (yyvsp[0].id)->coluna);free((yyvsp[-1].id)->id);}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 219 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("RealLit",(yyvsp[0].id)->id,NULL,NULL, (yyvsp[0].id)->linha,(yyvsp[0].id)->coluna,-1,-1);free((yyvsp[0].id)->id);}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 220 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("BoolLit",(yyvsp[0].id)->id,NULL,NULL, (yyvsp[0].id)->linha,(yyvsp[0].id)->coluna,-1,-1);free((yyvsp[0].id)->id);}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 221 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("DecLit",(yyvsp[0].id)->id,NULL,NULL, (yyvsp[0].id)->linha,(yyvsp[0].id)->coluna,-1,-1);free((yyvsp[0].id)->id);}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 227 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ifl)=NULL;}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 230 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state)=NULL;}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 232 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel)=NULL;}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 235 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel)=NULL; free((yyvsp[-3].id)->id);}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 238 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel)=NULL;}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1989 "y.tab.c" /* yacc.c:1646  */
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
#line 241 "jucompiler.y" /* yacc.c:1906  */


void yyerror(char *msg) {
    erro_sintaxe=1;
    printf("Line %d, col %d: %s: %s\n", num_linhas, num_colunas - (int) strlen(yylval.id->id) , msg, yylval.id->id);

 
}
