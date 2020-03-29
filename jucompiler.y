%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

extern int linha_erro, coluna_erro, num_colunas, num_linhas, error_sequence, last_token;
extern char* yytext;
int yylex (void);
void yyerror(char* s);

%}

%token BOOLLIT AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR RPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS DOTLENGTH DOUBLE ELSE IF INT PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE REALLIT

%token<id>ID INTLIT STRLIT
%type<id>program
%type<id>metodos
%type<id>MethodDecl
%type<id>FieldDecl
%type<id>FieldDeclNext
%type<id>MethodHeader
%type<id>MethodParams
%type<id>MethodParamsNext
%type<id>MethodBody
%type<id>Body
%type<id>VarDecl
%type<id>VarDeclNext
%type<id>Statement
%type<id>StatementZrOuMais
%type<id>StatementExpOp
%type<id>StateMethodIAssignmentParseArgs ParseArgs
%type<id>StatementPrint MethodInvocation ExpCommaExpOP CommaExprZrOuMais Assigment Expr

%right ASSIGN
%left OR
%left AND
%left XOR
%left EQ NE LT LE GT GE
%left LSHIFT RSHIFT
%left PLUS MINUS
%left STAR DIV MOD
%right NOT

%nonassoc REDUCE
%nonassoc ELSE

%union{
    char *id;
}

%%

program: CLASS ID LBRACE metodos RBRACE                     {}
    ;

metodos: /*empty*/                                          {}
        | MethodDecl metodos                                {$$= $1;}
        | FieldDecl  metodos                                {} 
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

MethodHeader: Type ID LPAR MethodParams RPAR                {$$= $4;}
            | VOID ID LPAR MethodParams RPAR                {$$= $4;}
    ;

MethodParams:  /*empty*/                                    {}
            | Type ID MethodParamsNext                      {$$= $3;}
            | STRING LSQ RSQ ID                             {$$= $4;}
    ;

MethodParamsNext: /*empty*/                                 {}
                | COMMA Type ID MethodParamsNext            {$$= $3;}
    ;


MethodBody: LBRACE Body RBRACE                              {$$= $2;}
    ;

Body:  /*empty*/                                            {} 
    |  VarDecl  Body                                        {} 
    |  Statement Body                                       {$$ = $1;} 
    ;

VarDecl: Type ID  VarDeclNext SEMICOLON                     {$$= $2;}
    ;

VarDeclNext: /*empty*/                                      {}
           | COMMA ID  VarDeclNext                          {$$= $2;}
    ;






Statement:  IF LPAR Expr RPAR Statement %prec REDUCE        {}
        |   IF LPAR Expr RPAR Statement ELSE Statement      {}
        |   WHILE LPAR Expr RPAR Statement                  {}
        |   RETURN StatementExpOp SEMICOLON                 {}
        |   LBRACE StatementZrOuMais RBRACE                 {}
        |   StateMethodIAssignmentParseArgs SEMICOLON       {}
        |   PRINT LPAR StatementPrint RPAR SEMICOLON        {$$ = $3;}

    ; 

StatementZrOuMais: /*empty*/                                {}
            | Statement  StatementZrOuMais                  {$$= $1;}
    ;

StatementExpOp: /*empty*/                                   {}
            |    Expr                                       {$$ = $1;}
    ;

StatementPrint: STRLIT                                      {}
        |    Expr                                           {$$ = $1;}
    ;

StateMethodIAssignmentParseArgs : /*empty*/                 {}             
        | MethodInvocation                                  {} 
        | Assigment                                         {} 
        | ParseArgs                                         {} 
    ;





MethodInvocation: ID LPAR ExpCommaExpOP RPAR                 {$$ = $3;} 
    ;

ExpCommaExpOP: /*empty*/                                     {} 
            | Expr CommaExprZrOuMais                         {$$ = $1;} 
    ;

CommaExprZrOuMais: /*empty*/                                 {}
         | COMMA Expr CommaExprZrOuMais                      {}
    ;

Assigment: ID ASSIGN Expr                                    {}
    ;
     
ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR                {}
    ;






Expr: Expr AND Expr                             {}
    | Expr OR Expr                              {}
    | Expr EQ Expr                              {}
    | Expr GE Expr                              {}
    | Expr GT Expr                              {}
    | Expr LE Expr                              {}
    | Expr LT Expr                              {}
    | Expr NE Expr                              {}
    | Expr PLUS Expr                            {}
    | Expr MINUS Expr                           {}               
    | Expr STAR Expr                            {}
    | Expr DIV Expr                             {}
    | Expr MOD Expr                             {} 
    | Expr XOR Expr                             {}
    | Expr LSHIFT Expr                          {}
    | Expr RSHIFT Expr                          {}
    | NOT Expr                                  {}
    | MINUS Expr                                {}
    | PLUS Expr                                 {}
    | LPAR Expr RPAR                            {}
    | MethodInvocation                          {$$ = $1;} 
    | Assigment                                 {} 
    | ParseArgs                                 {} 
    | ID DotLengthOp                            {$$ =$1;}
    | REALLIT                                   {}
    | BOOLLIT                                   {}
    | INTLIT                                    {$$ =$1;}
    ; 

DotLengthOp: /*empty*/                                      {}
        | DOTLENGTH                                         {}
    ;



FieldDecl : error SEMICOLON                                 {}
    ;

Statement : error SEMICOLON                      {}
    ;
ParseArgs: PARSEINT LPAR error RPAR                         {}
    ; 

MethodInvocation: ID LPAR error RPAR                        {}
    ;

Expr: LPAR error RPAR                           {}
    ;

%%

void yyerror(char *msg) {

    printf("Line %d, col %d: %s: %s\n", num_linhas, num_colunas - (int) strlen(yylval.id) , msg, yylval.id);
 
    
}