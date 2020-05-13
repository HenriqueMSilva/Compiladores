/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 68 "jucompiler.y" /* yacc.c:1909  */

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

#line 174 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
