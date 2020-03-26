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
%type<aux>metodos
%type<aux>MethodHeader
%type<aux>MethodDecl

%union{
    char *id;
    char *aux;
}

%%
program: CLASS ID LBRACE metodos RBRACE {printf("boas %s\n", $2);}
    ;

metodos: /*empty*/                      {$$= "";}
        | MethodDecl metodos            {$$= $2;}
    ;

MethodDecl: PUBLIC STATIC MethodHeader   {$$= $3;}
    ;

Type: BOOL
    | INT
    | DOUBLE
    ;

MethodHeader:  Type ID LPAR RPAR        {$$= $2;}
    ;

%%

void yyerror(char *msg) {
    printf("%s", msg);
}
