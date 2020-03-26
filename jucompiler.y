%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

int yylex (void);
void yyerror(char* s);

%}

%token BOOLLIT AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR RPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS DOTLENGTH DOUBLE ELSE IF INT PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE

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


%union{
    char *id;
}

%%
program: CLASS ID LBRACE metodos RBRACE                     {printf("\n\n\n%s\n\n\n", $4);}
    ;

metodos: /*empty*/                                          {$$= "";}
        | MethodDecl metodos                                {$$= $1;}
        | FieldDecl  metodos                                
        | SEMICOLON metodos                                 
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody           {$$= $4;}
    ;

FieldDecl:  PUBLIC STATIC Type ID FieldDeclNext SEMICOLON   
    ;

FieldDeclNext:  /*empty*/                                   {$$= "";}     
             |  COMMA ID
    ;

Type: BOOL
    | INT
    | DOUBLE
    ;

MethodHeader: Type ID LPAR FormalParams RPAR                {$$= $4;}
            | VOID ID LPAR FormalParams RPAR                {$$= $4;}
    ;

FormalParams:  /*empty*/                                    {$$= "";}
            | Type ID FormalParamsNext                      {$$= $3;}
            | STRING LSQ RSQ ID                             {$$= $4;}
    ;

FormalParamsNext: /*empty*/                                 {$$= "";}
                | COMMA Type ID FormalParamsNext            {$$= $3;}
    ;


MethodBody: LBRACE Body RBRACE                              {$$= $2;}
    ;

Body:  /*empty*/                                            {$$= "";} 
    |  VarDecl  Body                                        {$$= $1;} 
    ;

VarDecl: Type ID  VarDeclNext SEMICOLON                     {$$= strcat($2,$3);}
    ;

VarDeclNext: /*empty*/                                      {$$= "";}
           | COMMA ID                                       {$$= $2;}
    ;




Statement:  WHILE LPAR Expr RPAR StatementBrackets
        |   IF LPAR Expr RPAR Statement StatementElse
        |   RETURN StatementReturn SEMICOLON
    ;

StatementBrackets: LBRACE Statement RBRACE
    ;

StatementElse:  /*empty*/ 
            |   ELSE Statement
    ;

StatementReturn: /*empty*/
            |    Expr
    ;

Expr: INTLIT
    ;

%%

void yyerror(char *msg) {
    printf("%s", msg);
}
