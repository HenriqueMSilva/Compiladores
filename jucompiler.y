%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

int yylex (void);
void yyerror(char* s);

%}

%token BOOLLIT AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR RPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS DOTLENGTH DOUBLE ELSE IF INT PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE REALLIT 
%token<id>INTLIT 
%token<id>ID 
%type<id>program
%type<id>metodos
%type<id>MethodDecl
%type<id>FieldDecl
%type<id>FieldDeclNext
%type<id>MethodHeader
%type<id>FormalParams
%type<id>FormalParamsNext
%type<id>MethodBody
%type<id>Body
%type<id>VarDecl
%type<id>VarDeclNext
%type<id>Statement
%type<id>StatementZrOuMais
%type<id>StatementExpOp
%type<id>Expr


%left OR
%left AND
%left EQ NE LT LE GT GE
%left PLUS MINUS
%left STAR DIV MOD
%right NOT

%nonassoc REDUCE
%nonassoc ELSE
%nonassoc OPERADORES

%union{
    char *id;
}

%%
program: CLASS ID LBRACE metodos RBRACE                     {printf("\n%s\n", $4);}
    ;

metodos: /*empty*/                                          {}
        | MethodDecl metodos                                {$$= $1;}
        | FieldDecl  metodos                                {$$= $1;} 
        | SEMICOLON metodos                                 {}
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody           {$$= $4;}
    ;

FieldDecl:  PUBLIC STATIC Type ID FieldDeclNext SEMICOLON   {}
    ;

FieldDeclNext:  /*empty*/                                   {}     
             |  COMMA ID FieldDeclNext                      {}
    ;

Type: BOOL
    | INT
    | DOUBLE
    ;

MethodHeader: Type ID LPAR FormalParams RPAR                {$$= $4;}
            | VOID ID LPAR FormalParams RPAR                {$$= $4;}
    ;

FormalParams:  /*empty*/                                    {}
            | Type ID FormalParamsNext                      {$$= $3;}
            | STRING LSQ RSQ ID                             {$$= $4;}
    ;

FormalParamsNext: /*empty*/                                 {}
                | COMMA Type ID FormalParamsNext            {$$= $3;}
    ;


MethodBody: LBRACE Body RBRACE                              {$$= $2;}
    ;

Body:  /*empty*/                                            {} 
    |  VarDecl  Body                                        {} 
    |  Statement Body                                       {$$ = $1;} 
    ;

VarDecl: Type ID  VarDeclNext SEMICOLON                     {$$= strcat($2,$3);}
    ;

VarDeclNext: /*empty*/                                      {}
           | COMMA ID  VarDeclNext                          {$$= $2;}
    ;




Statement: LBRACE StatementZrOuMais RBRACE                  {$$= $2;}
    ;

StatementZrOuMais: /*empty*/                                {}
            | Statement  StatementZrOuMais                  {$$= $1;}
    ;

Statement:  IF LPAR Expr RPAR Statement %prec REDUCE        {$$= $5;}
        |   IF LPAR Expr RPAR Statement ELSE Statement      {}
        |   WHILE LPAR Expr RPAR Statement                  {}
        |   RETURN StatementExpOp SEMICOLON                 {}
    ; 

StatementExpOp: /*empty*/                                   {}
            |    Expr                                       {}
    ;


Statement:  StateMethodIAssignmentParseArgs SEMICOLON       {}
        |   PRINT StatementExpOp SEMICOLON                  {$$= $2;}
    ; 


StateMethodIAssignmentParseArgs : /*empty*/                 {}             
        | MethodInvocation                                  {} 
        | Assigment                                         {} 
        | ParseArgs                                         {} 
    ;


MethodInvocation: ID LPAR ExpCommaExpOP RPAR                 {} 
    ;

ExpCommaExpOP: /*empty*/                                     {} 
        | Expr CommaExprZrOuMais                             {} 
    ;
CommaExprZrOuMais: /*empty*/                                 {}
        | COMMA Expr CommaExprZrOuMais                       {}
    ;

Assigment: ID ASSIGN Expr                                    {}
    ;
     


ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR                {}
    ;




Expr: Expr PLUS Expr         {printf("+");}
    | Expr MINUS Expr                             {printf("-");}               
    | Expr STAR Expr                            {printf("*");}
    | Expr DIV Expr                                 {printf("/");}
    | Expr MOD Expr                                     {printf("mod");}
    | Expr AND Expr
    | Expr OR Expr
    | Expr XOR Expr
    | Expr LSHIFT Expr
    | Expr RSHIFT Expr
    | Expr EQ Expr
    | Expr GE Expr
    | Expr GT Expr
    | Expr LE Expr
    | Expr LT Expr
    | Expr NE Expr
    | NOT Expr
    | MINUS Expr
    | PLUS Expr
    | INTLIT                                                 {$$ =$1;}
    ; 

%%

void yyerror(char *msg) {
    printf("%s", msg);
}
