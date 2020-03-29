%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
int yydebug =1;

extern int linha_erro, coluna_erro, num_colunas, num_linhas, error_sequence, last_token;
extern char* yytext;
int yylex (void);
void yyerror(char* s);

%}

%token BOOLLIT AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR RPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS DOTLENGTH DOUBLE ELSE IF INT PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE REALLIT

%token<id>ID INTLIT STRLIT
%type<id>Assigment Expr MethodInvocation StateMethodIAssignmentParseArgs ExpCommaExpOP

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
        | MethodDecl metodos                                {}
        | FieldDecl  metodos                                {} 
        | SEMICOLON metodos                                 {}
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody           {}
    ;

FieldDecl:  PUBLIC STATIC Type ID FieldDeclNext SEMICOLON   {}
        |   error SEMICOLON                                 {}
    ;

FieldDeclNext:  /*empty*/                                   {}     
             |  COMMA ID FieldDeclNext                      {}
    ;

Type: BOOL
    | INT
    | DOUBLE
    ;

MethodHeader: Type ID LPAR MethodParams RPAR                {}
            | VOID ID LPAR MethodParams RPAR                {}
    ;

MethodParams:  /*empty*/                                    {}
            | Type ID MethodParamsNext                      {}
            | STRING LSQ RSQ ID                             {}
    ;

MethodParamsNext: /*empty*/                                 {}
                | COMMA Type ID MethodParamsNext            {}
    ;


MethodBody: LBRACE Body RBRACE                              {}
    ;

Body:  /*empty*/                                            {} 
    |  VarDecl  Body                                        {} 
    |  Statement Body                                       {} 
    ;

VarDecl: Type ID  VarDeclNext SEMICOLON                     {}
    ;

VarDeclNext: /*empty*/                                      {}
           | COMMA ID  VarDeclNext                          {}
    ;






Statement:  IF LPAR Expr RPAR Statement %prec REDUCE        {}
        |   IF LPAR Expr RPAR Statement ELSE Statement      {}
        |   WHILE LPAR Expr RPAR Statement                  {}
        |   RETURN StatementExpOp SEMICOLON                 {}
        |   LBRACE StatementZrOuMais RBRACE                 {}
        |   StateMethodIAssignmentParseArgs SEMICOLON       {}
        |   PRINT LPAR StatementPrint RPAR SEMICOLON        {}
        |   error SEMICOLON                                 {}
    ; 

StatementZrOuMais: /*empty*/                                {}
            | Statement  StatementZrOuMais                  {}
    ;

StatementExpOp: /*empty*/                                   {}
            |    Expr                                       {}
    ;

StatementPrint: STRLIT                                      {}
        |    Expr                                           {}
    ;

StateMethodIAssignmentParseArgs : /*empty*/                 {}             
        | MethodInvocation                                  {} 
        | Assigment                                         {} 
        | ParseArgs                                         {} 
    ;





MethodInvocation: ID LPAR ExpCommaExpOP RPAR                 {}
                | ID LPAR error RPAR                         {}
    ;

ExpCommaExpOP: /*empty*/                                     {} 
            | Expr CommaExprZrOuMais                         {} 
    ;

CommaExprZrOuMais: /*empty*/                                 {}
         | COMMA Expr CommaExprZrOuMais                      {}
    ;

Assigment: ID ASSIGN Expr                                    {}
    ;
     
ParseArgs:  PARSEINT LPAR ID LSQ Expr RSQ RPAR               {}
        |   PARSEINT LPAR error RPAR                         {}
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
    | LPAR error RPAR                           {}
    | MethodInvocation                          {}
    | Assigment                                 {} 
    | ParseArgs                                 {} 
    | ID                                        {}
    | ID DOTLENGTH                              {}
    | REALLIT                                   {}
    | BOOLLIT                                   {}
    | INTLIT                                    {}
    ; 



%%

void yyerror(char *msg) {
    /*last_token = -1 default
        last_token = 0 STRLIT
    */

    /*Quando o erro foi de uma STRLIT*/
    if( last_token == 0 && error_sequence == 0){
        printf("Line %d, col %d: %s: %s\n", num_linhas, num_colunas - (int) strlen(yylval.id) + 1 , msg, yylval.id);
        last_token = -1;

    /*Outros casos*/
    }else if (last_token == -1){
        printf("Line %d, col %d: %s: %s\n", num_linhas, num_colunas , msg, yylval.id);
    }
}