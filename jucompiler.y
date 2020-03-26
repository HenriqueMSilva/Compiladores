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
%type<aux>program
%type<aux>metodos
%type<aux>MethodHeader
%type<aux>MethodDecl
%type<aux>FormalParams
%type<aux>FormalParamsNext
%type<aux>FieldDeclNext

%union{
    char *id;
    char *aux;
}

%%
program: CLASS ID LBRACE metodos RBRACE                     {printf("\n\n\n%s\n\n\n", $4);}
    ;

metodos: /*empty*/                                          {$$= "";}
        | MethodDecl metodos                                {$$= $1;}
        | FieldDecl  metodos                                
        | SEMICOLON metodos                                 
    ;

MethodDecl: PUBLIC STATIC MethodHeader                      {$$= $3;}
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

MethodHeader: Type ID LPAR FormalParams RPAR                {$$= $2;}
            | VOID ID LPAR FormalParams RPAR                {$$= $2;}
    ;

FormalParams:  /*empty*/                                    
            | Type ID FormalParamsNext                      {$$= $2;}
            | STRING LSQ RSQ ID                             {$$= $4;}
    ;

FormalParamsNext: /*empty*/                                 {$$= "";}
                | COMMA Type ID FormalParamsNext            {$$= $3;}
    ;


MethodBody: LBRACE RBRACE

%%

void yyerror(char *msg) {
    printf("%s", msg);
}
