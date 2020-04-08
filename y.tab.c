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
    PLUS = 277,
    RBRACE = 278,
    RSQ = 279,
    SEMICOLON = 280,
    ARROW = 281,
    LSHIFT = 282,
    RSHIFT = 283,
    XOR = 284,
    BOOL = 285,
    CLASS = 286,
    DOTLENGTH = 287,
    DOUBLE = 288,
    ELSE = 289,
    IF = 290,
    INT = 291,
    PRINT = 292,
    PARSEINT = 293,
    PUBLIC = 294,
    RETURN = 295,
    STATIC = 296,
    STRING = 297,
    VOID = 298,
    WHILE = 299,
    RESERVED = 300,
    ID = 301,
    INTLIT = 302,
    STRLIT = 303,
    REALLIT = 304,
    BOOLLIT = 305,
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
#define PLUS 277
#define RBRACE 278
#define RSQ 279
#define SEMICOLON 280
#define ARROW 281
#define LSHIFT 282
#define RSHIFT 283
#define XOR 284
#define BOOL 285
#define CLASS 286
#define DOTLENGTH 287
#define DOUBLE 288
#define ELSE 289
#define IF 290
#define INT 291
#define PRINT 292
#define PARSEINT 293
#define PUBLIC 294
#define RETURN 295
#define STATIC 296
#define STRING 297
#define VOID 298
#define WHILE 299
#define RESERVED 300
#define ID 301
#define INTLIT 302
#define STRLIT 303
#define REALLIT 304
#define BOOLLIT 305
#define REDUCE 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 54 "jucompiler.y" /* yacc.c:355  */

    char *id;
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

#line 240 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 257 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   384

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

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
       0,    70,    70,    73,    74,    75,    76,    79,    82,    85,
      86,    89,    90,    91,    95,    96,    99,   100,   101,   104,
     105,   108,   111,   112,   113,   116,   119,   120,   123,   124,
     127,   128,   129,   130,   131,   132,   133,   134,   138,   139,
     142,   143,   146,   147,   153,   156,   157,   160,   161,   165,
     170,   171,   172,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     208,   211,   213,   216,   219
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "ASSIGN", "STAR", "COMMA", "DIV",
  "EQ", "GE", "GT", "LBRACE", "LE", "LPAR", "RPAR", "LSQ", "LT", "MINUS",
  "MOD", "NE", "NOT", "OR", "PLUS", "RBRACE", "RSQ", "SEMICOLON", "ARROW",
  "LSHIFT", "RSHIFT", "XOR", "BOOL", "CLASS", "DOTLENGTH", "DOUBLE",
  "ELSE", "IF", "INT", "PRINT", "PARSEINT", "PUBLIC", "RETURN", "STATIC",
  "STRING", "VOID", "WHILE", "RESERVED", "ID", "INTLIT", "STRLIT",
  "REALLIT", "BOOLLIT", "REDUCE", "$accept", "program", "metodos",
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

#define YYPACT_NINF -41

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-41)))

#define YYTABLE_NINF -46

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,   -40,    10,    45,   -41,    11,    32,    11,    17,    37,
      11,    11,   -41,   -41,   -22,   -41,   -41,   -41,   -41,   -41,
     -41,    21,    50,    83,    87,    38,   149,   -41,    62,    60,
      62,    90,    92,   165,   -41,    99,   106,   107,   193,   109,
      39,    79,   101,   149,   149,   102,   105,   120,    93,   124,
     134,   138,   -41,   -41,   165,   132,   193,   179,     2,    25,
     199,   199,   199,    33,   -41,   -41,   -41,   129,   -41,   -41,
     -41,   247,   193,   193,    96,   150,   -41,   -41,   -41,   -41,
     -41,   133,   152,   -41,   -41,   -41,   -41,   -41,   145,   -41,
     147,   -41,   148,   153,   151,    89,   156,   131,    41,   -41,
     -41,   -41,   193,   -41,   -41,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   157,   139,   159,   161,   177,   117,   142,   158,    78,
     -41,    24,   166,   -41,   193,   -41,   193,   -41,   -41,   299,
     -41,   -41,   348,   356,   356,   356,   356,    48,   -41,   348,
     274,    48,   332,   332,   324,    24,   -41,   -41,   -41,   193,
     -41,   150,   -41,   -41,   162,   160,   -41,   173,   184,   -41,
     177,   -41,   152,    24,   200,   -41,   -41,   -41,   -41,   -41
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,    80,     6,     0,     2,     4,     5,    11,    13,
      12,     0,     0,     0,     0,     9,     0,     7,    16,     0,
      16,     0,     0,     0,    37,     0,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,     0,     8,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    79,    77,    78,     0,    73,    74,
      41,    50,     0,     0,     0,    26,    21,    23,    24,    34,
      36,     0,    19,    15,    10,    14,    39,    32,     0,    42,
       0,    43,     0,     0,     0,    75,     0,     0,    75,    70,
      69,    71,     0,    76,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,     0,     0,
      17,     0,     0,    82,     0,    84,     0,    72,    51,    53,
      63,    64,    55,    56,    57,    58,    59,    62,    65,    60,
      54,    61,    67,    68,    66,     0,    35,    83,    44,     0,
      46,    26,    25,    18,     0,    28,    33,     0,     0,    30,
      47,    27,    19,     0,     0,    52,    48,    20,    29,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -41,   -41,   126,   -41,   -41,   168,    -1,   -41,   190,    35,
     -41,   -28,   -41,    61,   -32,   169,   -41,   -41,   -26,   -41,
      54,   -24,   -33,   -29
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    10,    11,    31,    41,    23,    49,   130,
      27,    42,    43,   127,    44,    55,    67,    90,    68,   124,
     160,    69,    96,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    54,    46,    92,     1,    70,     3,    45,    18,    46,
       4,    19,     6,    22,    20,    77,    78,    45,    45,    46,
      46,    21,    54,    88,    91,    32,    94,    48,    45,    48,
      46,    99,   100,   101,    -3,    33,     7,   102,    59,   121,
     122,   125,    60,    73,    29,    61,    74,    62,    93,    34,
       8,    30,    74,   106,    74,   107,     5,    12,    14,    35,
      15,    36,    37,    37,    38,   103,   114,    24,    39,   138,
      40,    95,    64,   103,    65,    66,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    18,   136,    26,    19,    25,   123,    20,   165,
      28,   167,    74,   168,    47,    45,    50,    46,    18,    59,
     -45,    19,    56,    60,    20,    52,    61,    53,    62,    57,
      58,   103,    72,   169,    76,    75,   170,    79,   164,    45,
      80,    46,    94,    13,    37,    81,    16,    17,    83,    82,
      29,   178,    63,    64,    59,    65,    66,    45,    60,    46,
      32,    61,    85,    62,   104,    87,   126,   128,   129,   131,
      33,   132,   133,   161,   156,   135,    32,   162,   134,    37,
     137,   155,   -22,   157,    34,   158,    33,    63,    64,    18,
      65,    66,    19,   159,    35,    20,    36,    37,   -38,    38,
      34,   166,    59,    39,   173,    40,    60,   174,   175,    61,
      35,    62,    36,    37,   163,    38,    59,   177,   172,    39,
      60,    40,    97,    61,   179,    62,    60,    37,    84,    61,
      51,    62,   171,    86,   176,    63,    64,    89,    65,    66,
       0,    37,     0,     0,     0,     0,     0,    37,     0,    63,
      64,     0,    65,    66,     0,    98,    64,     0,    65,    66,
     105,     0,   106,     0,   107,   108,   109,   110,     0,   111,
       0,     0,     0,   112,   113,   114,   115,     0,   116,   117,
       0,     0,     0,     0,   118,   119,   120,   105,     0,   106,
       0,   107,   108,   109,   110,     0,   111,     0,     0,     0,
     112,   113,   114,   115,     0,     0,   117,     0,     0,     0,
       0,   118,   119,   120,   106,     0,   107,   108,   109,   110,
       0,   111,     0,     0,     0,   112,   113,   114,   115,     0,
       0,   117,     0,     0,     0,     0,   118,   119,   120,   106,
       0,   107,   108,   109,   110,     0,   111,   106,     0,   107,
     112,   113,   114,   115,     0,     0,   117,     0,     0,   113,
     114,   118,   119,   106,   117,   107,     0,   109,   110,     0,
     111,   106,     0,   107,   112,   113,   114,     0,     0,     0,
     117,     0,     0,   113,   114,   118,   119,     0,   117,     0,
       0,     0,     0,   118,   119
};

static const yytype_int16 yycheck[] =
{
      26,    33,    26,     1,    31,    38,    46,    33,    30,    33,
       0,    33,     1,    14,    36,    43,    44,    43,    44,    43,
      44,    43,    54,    56,    57,     1,     1,    28,    54,    30,
      54,    60,    61,    62,    23,    11,    25,     4,    13,    72,
      73,    74,    17,     4,     6,    20,    13,    22,    46,    25,
      39,    13,    13,     5,    13,     7,    11,    25,    41,    35,
      23,    37,    38,    38,    40,    32,    18,    46,    44,   102,
      46,    46,    47,    32,    49,    50,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    30,     4,    11,    33,    46,     1,    36,   131,
      13,   134,    13,   136,    42,   131,    46,   131,    30,    13,
      14,    33,    13,    17,    36,    25,    20,    25,    22,    13,
      13,    32,    13,   155,    23,    46,   159,    25,   129,   155,
      25,   155,     1,     7,    38,    15,    10,    11,    14,    46,
       6,   173,    46,    47,    13,    49,    50,   173,    17,   173,
       1,    20,    14,    22,    25,    23,     6,    24,     6,    14,
      11,    14,    14,    46,    25,    14,     1,    25,    15,    38,
      14,    14,    23,    14,    25,    14,    11,    46,    47,    30,
      49,    50,    33,     6,    35,    36,    37,    38,    23,    40,
      25,    25,    13,    44,    34,    46,    17,    24,    14,    20,
      35,    22,    37,    38,    46,    40,    13,   172,    46,    44,
      17,    46,    13,    20,    14,    22,    17,    38,    50,    20,
      30,    22,   161,    54,   170,    46,    47,    48,    49,    50,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    38,    -1,    46,
      47,    -1,    49,    50,    -1,    46,    47,    -1,    49,    50,
       3,    -1,     5,    -1,     7,     8,     9,    10,    -1,    12,
      -1,    -1,    -1,    16,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,     3,    -1,     5,
      -1,     7,     8,     9,    10,    -1,    12,    -1,    -1,    -1,
      16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,     5,    -1,     7,     8,     9,    10,
      -1,    12,    -1,    -1,    -1,    16,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    27,    28,    29,     5,
      -1,     7,     8,     9,    10,    -1,    12,     5,    -1,     7,
      16,    17,    18,    19,    -1,    -1,    22,    -1,    -1,    17,
      18,    27,    28,     5,    22,     7,    -1,     9,    10,    -1,
      12,     5,    -1,     7,    16,    17,    18,    -1,    -1,    -1,
      22,    -1,    -1,    17,    18,    27,    28,    -1,    22,    -1,
      -1,    -1,    -1,    27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    53,    46,     0,    11,     1,    25,    39,    54,
      55,    56,    25,    54,    41,    23,    54,    54,    30,    33,
      36,    43,    58,    59,    46,    46,    11,    62,    13,     6,
      13,    57,     1,    11,    25,    35,    37,    38,    40,    44,
      46,    58,    63,    64,    66,    70,    73,    42,    58,    60,
      46,    60,    25,    25,    66,    67,    13,    13,    13,    13,
      17,    20,    22,    46,    47,    49,    50,    68,    70,    73,
      74,    75,    13,     4,    13,    46,    23,    63,    63,    25,
      25,    15,    46,    14,    57,    14,    67,    23,    74,    48,
      69,    74,     1,    46,     1,    46,    74,    13,    46,    75,
      75,    75,     4,    32,    25,     3,     5,     7,     8,     9,
      10,    12,    16,    17,    18,    19,    21,    22,    27,    28,
      29,    74,    74,     1,    71,    74,     6,    65,    24,     6,
      61,    14,    14,    14,    15,    14,     4,    14,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    14,    25,    14,    14,     6,
      72,    46,    25,    46,    58,    66,    25,    74,    74,    66,
      74,    65,    46,    34,    24,    14,    72,    61,    66,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    54,    54,    55,    56,    57,
      57,    58,    58,    58,    59,    59,    60,    60,    60,    61,
      61,    62,    63,    63,    63,    64,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    71,    71,    72,    72,    73,
      74,    74,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      56,    66,    73,    70,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     2,     2,     2,     4,     6,     0,
       3,     1,     1,     1,     5,     5,     0,     3,     4,     0,
       4,     3,     0,     2,     2,     4,     0,     3,     5,     7,
       5,     3,     3,     5,     2,     4,     2,     1,     0,     2,
       0,     1,     1,     1,     4,     0,     2,     0,     3,     7,
       1,     3,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     3,     1,     1,     1,     2,     1,     1,     1,
       2,     2,     4,     4,     3
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
#line 70 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ip)=myprogram=insert_program((yyvsp[-3].id), (yyvsp[-1].im));}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 73 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.im) = NULL;}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 74 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.im)=insert_metodos("Method",NULL,(yyvsp[-1].imdl),(yyvsp[0].im));}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 75 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.im)=insert_metodos("Field",(yyvsp[-1].ifl),NULL,(yyvsp[0].im));}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 76 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.im)=insert_metodos("Semicolon",NULL,NULL,(yyvsp[0].im));}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 79 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.imdl)=insert_methoddecl((yyvsp[-1].imhl),(yyvsp[0].imbl));}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 82 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ifl)=insert_field((yyvsp[-3].id),(yyvsp[-2].id),(yyvsp[-1].ifl));}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 85 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ifl) = NULL;}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 86 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ifl)=insert_field("",(yyvsp[-1].id),(yyvsp[0].ifl));}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 89 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.id)="Bool";}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 90 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.id)="Int";}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 91 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.id)="Double";}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 95 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.imhl)=insert_methodheader((yyvsp[-4].id),(yyvsp[-3].id),(yyvsp[-1].impl));}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 96 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.imhl)=insert_methodheader("Void",(yyvsp[-3].id),(yyvsp[-1].impl));}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 99 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.impl) = NULL;}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 100 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.impl)=insert_methodparams((yyvsp[-2].id),(yyvsp[-1].id),(yyvsp[0].impl));}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 101 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.impl)=insert_methodparams("StringArray",(yyvsp[0].id),NULL);}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 104 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.impl) = NULL;}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 105 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.impl)=insert_methodparams((yyvsp[-2].id),(yyvsp[-1].id),(yyvsp[0].impl));}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 108 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.imbl) = (yyvsp[-1].imbl);}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 111 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.imbl) = NULL;}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 112 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.imbl)=insert_methodbody("VarDecl",(yyvsp[-1].ivdl),NULL,(yyvsp[0].imbl));}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 113 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.imbl)=insert_methodbody("Statement",NULL,(yyvsp[-1].state),(yyvsp[0].imbl));}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 116 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ivdl)=insert_vardecl((yyvsp[-3].id),(yyvsp[-2].id),(yyvsp[-1].ivdl));}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 119 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ivdl) = NULL;}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 120 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ivdl)=insert_vardecl("",(yyvsp[-1].id),(yyvsp[0].ivdl));}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 123 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("If", (yyvsp[-2].iel), (yyvsp[0].state), NULL);}
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 124 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("IfElse", (yyvsp[-4].iel), (yyvsp[-2].state), (yyvsp[0].state));}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 127 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("While", (yyvsp[-2].iel), (yyvsp[0].state), NULL);}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 128 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("Return", (yyvsp[-1].iel), NULL, NULL);}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 129 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("Block", NULL, (yyvsp[-1].state), NULL);}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 130 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("Print", (yyvsp[-2].iel), NULL, NULL);}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 131 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("Call", (yyvsp[-1].iel), NULL, NULL);}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 132 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("AssignStatment", insert_expr("Assign",(yyvsp[-3].id),(yyvsp[-1].iel),NULL), NULL, NULL );}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 133 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("ParseArgsStatment", (yyvsp[-1].iel),NULL, NULL);}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 134 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = NULL;}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 138 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = NULL;}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 139 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state) = insert_multiple_statement("Statment", NULL, (yyvsp[-1].state), (yyvsp[0].state));}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 142 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = NULL;}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 143 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = (yyvsp[0].iel);}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 146 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("StrLit",(yyvsp[0].id),NULL,NULL);}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 147 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = (yyvsp[0].iel);}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 153 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Call",(yyvsp[-3].id),(yyvsp[-1].iel),NULL);}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 156 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = NULL;}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 157 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("CallMore","",(yyvsp[-1].iel),(yyvsp[0].iel));}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 160 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = NULL;}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 161 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("CallMore","",(yyvsp[-1].iel),(yyvsp[0].iel));}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 165 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("ParseArgs",(yyvsp[-4].id),(yyvsp[-2].iel),NULL);}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 170 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = (yyvsp[0].iel);}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 171 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Assign",(yyvsp[-2].id),(yyvsp[0].iel),NULL);}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 172 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Assign",(yyvsp[-3].id),(yyvsp[-1].iel),NULL);}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 176 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","And",(yyvsp[-2].iel),(yyvsp[0].iel));}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 177 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Or",(yyvsp[-2].iel),(yyvsp[0].iel));}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 178 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Eq",(yyvsp[-2].iel),(yyvsp[0].iel));}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 179 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Ge",(yyvsp[-2].iel),(yyvsp[0].iel));}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 180 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Gt",(yyvsp[-2].iel),(yyvsp[0].iel));}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 181 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Le",(yyvsp[-2].iel),(yyvsp[0].iel));}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 182 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Lt",(yyvsp[-2].iel),(yyvsp[0].iel));}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 183 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Ne",(yyvsp[-2].iel),(yyvsp[0].iel));}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 184 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Add",(yyvsp[-2].iel),(yyvsp[0].iel));}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 185 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Sub",(yyvsp[-2].iel),(yyvsp[0].iel));}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 186 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Mul",(yyvsp[-2].iel),(yyvsp[0].iel));}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 187 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Div",(yyvsp[-2].iel),(yyvsp[0].iel));}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 188 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Mod",(yyvsp[-2].iel),(yyvsp[0].iel));}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 189 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Xor",(yyvsp[-2].iel),(yyvsp[0].iel));}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 190 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Lshift",(yyvsp[-2].iel),(yyvsp[0].iel));}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 191 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Rshift",(yyvsp[-2].iel),(yyvsp[0].iel));}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 192 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Not",(yyvsp[0].iel),NULL);}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 193 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Minus",(yyvsp[0].iel),NULL);}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 194 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Operacao","Plus",(yyvsp[0].iel),NULL);}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 195 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = (yyvsp[-1].iel);}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 196 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = (yyvsp[0].iel);}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 197 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = (yyvsp[0].iel);}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 198 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Id",(yyvsp[0].id),NULL,NULL);}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 199 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("Length",(yyvsp[-1].id),NULL,NULL);}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 200 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("RealLit",(yyvsp[0].id),NULL,NULL);}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 201 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("BoolLit",(yyvsp[0].id),NULL,NULL);}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 202 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel) = insert_expr("DecLit",(yyvsp[0].id),NULL,NULL);}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 208 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ifl)=NULL;}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 211 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.state)=NULL;}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 213 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel)=NULL;}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 216 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel)=NULL;}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 219 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.iel)=NULL;}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1993 "y.tab.c" /* yacc.c:1646  */
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
#line 222 "jucompiler.y" /* yacc.c:1906  */


void yyerror(char *msg) {
    erro_sintaxe=1;
    printf("Line %d, col %d: %s: %s\n", num_linhas, num_colunas - (int) strlen(yylval.id) , msg, yylval.id);
 
}
