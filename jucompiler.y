%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "y.tab.h"
int yydebug = 0;

extern int linha_erro, coluna_erro, num_colunas, num_linhas, error_sequence,erro_sintaxe;
extern char* yytext;
int yylex (void);
void yyerror(char* s);

is_program* myprogram;

%}

%token BOOLLIT AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR RPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS DOTLENGTH DOUBLE ELSE IF INT PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE REALLIT RESERVED

%token<id>ID INTLIT STRLIT

%type<ip>program
%type<im>metodos
%type<ifl>FieldDeclNext FieldDecl
%type<imdl>MethodDecl
%type<imhl>MethodHeader
%type<impl>MethodParams MethodParamsNext
%type<imbl>body MethodBody
%type<ivdl>VarDecl VarDeclNext
%type<state> Statement
%type<iel>StatementPrint StatementExpOp Expr
%type<id>Type


%right ASSIGN
%left OR
%left AND
%left XOR
%left GE LE LT GT EQ NE
%left LSHIFT RSHIFT
%left PLUS MINUS
%left STAR DIV MOD
%right NOT
%left LPAR RPAR LSQ RSQ LBRACE RBRACE

%nonassoc REDUCE
%nonassoc ELSE

%union{
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
}

%%

program: CLASS ID LBRACE metodos RBRACE                     {$$=myprogram=insert_program($2, $4);}
    ;

metodos: /*empty*/                                          {$$ = NULL;}
        | MethodDecl metodos                                {$$=insert_metodos("Method",NULL,$1,$2);}      
        | FieldDecl  metodos                                {$$=insert_metodos("Field",$1,NULL,$2);}
        | SEMICOLON  metodos                                {$$=insert_metodos("Semicolon",NULL,NULL,$2);}
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody           {$$=insert_methoddecl($3,$4);}
    ;

FieldDecl:  PUBLIC STATIC Type ID FieldDeclNext SEMICOLON   {$$=insert_field($3,$4,$5);}
    ;

FieldDeclNext:  /*empty*/                                   {$$ = NULL;}     
             |  COMMA ID FieldDeclNext                      {$$=insert_field("",$2,$3);}
    ;

Type: BOOL                                                  {$$="Bool";}
    | INT                                                   {$$="Int";}
    | DOUBLE                                                {$$="Double";}
    ;

MethodHeader: Type ID LPAR MethodParams RPAR                {$$=insert_methodheader($1,$2,$4);}
            | VOID ID LPAR MethodParams RPAR                {$$=insert_methodheader("Void",$2,$4);}
    ;

MethodParams:  /*empty*/                                    {$$ = NULL;}
            | Type ID MethodParamsNext                      {$$=insert_methodparams($1,$2,$3);}
            | STRING LSQ RSQ ID                             {$$=insert_methodparams("StringArray",$4,NULL);}
    ;

MethodParamsNext: /*empty*/                                 {$$ = NULL;}
                | COMMA Type ID MethodParamsNext            {$$=insert_methodparams($2,$3,$4);}
    ;

MethodBody: LBRACE body RBRACE                              {$$ = $2;} 
    ;

body:   /*empty*/                                           {$$ = NULL;}
    |   VarDecl  body                                       {$$=insert_methodbody("VarDecl",$1,NULL,$2);} 
    |   Statement body                                      {$$=insert_methodbody("Statement",NULL,$1,$2);} 
    ;

VarDecl: Type ID  VarDeclNext SEMICOLON                     {$$=insert_vardecl($1,$2,$3);}
    ;

VarDeclNext: /*empty*/                                      {$$ = NULL;}
           | COMMA ID  VarDeclNext                          {$$=insert_vardecl("",$2,$3);}
    ;






Statement:  IF LPAR Expr RPAR Statement %prec REDUCE        {}
        |   IF LPAR Expr RPAR Statement ELSE Statement      {}
        |   WHILE LPAR Expr RPAR Statement                  {}
        |   RETURN StatementExpOp SEMICOLON                 {}
        |   LBRACE StatementZrOuMais RBRACE                 {}
        |   StateMethodIAssignmentParseArgs SEMICOLON       {}
        |   PRINT LPAR StatementPrint RPAR SEMICOLON        {$$ = insert_statment("Print",NULL,$3);}
    ; 

StatementZrOuMais: /*empty*/                                {}
            | Statement  StatementZrOuMais                  {}
    ;

StatementExpOp: /*empty*/                                   {$$ = NULL;}
            |    Expr                                       {$$ = $1;}
    ;

StatementPrint: STRLIT                                      {$$ = insert_expr("StrLit",$1,NULL,NULL);}
        |    Expr                                           {$$ = $1;}
    ;

StateMethodIAssignmentParseArgs : /*empty*/                 {}             
        | MethodInvocation                                  {} 
        | Assigment                                         {} 
        | ParseArgs                                         {} 
    ;





MethodInvocation: ID LPAR ExpCommaExpOP RPAR                 {}
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
    ;






Expr: Expr AND Expr                             {$$ = insert_expr("Operacao","And",$1,$3);}
    | Expr OR Expr                              {$$ = insert_expr("Operacao","Or",$1,$3);}
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
    | MethodInvocation                          {}
    | Assigment                                 {}
    | ParseArgs                                 {} 
    | ID                                        {$$ = insert_expr("Id",$1,NULL,NULL);}
    | ID DOTLENGTH                              {}
    | REALLIT                                   {}
    | BOOLLIT                                   {}
    | INTLIT                                    {}
    ; 




FieldDecl : error SEMICOLON                                 {}
    ;

Statement : error SEMICOLON                                 {}
    ;
ParseArgs: PARSEINT LPAR error RPAR                         {}
    ; 

MethodInvocation: ID LPAR error RPAR                        {}
    ;

Expr: LPAR error RPAR                                       {}
    ;

%%

void yyerror(char *msg) {
    erro_sintaxe=1;
    printf("Line %d, col %d: %s: %s\n", num_linhas, num_colunas - (int) strlen(yylval.id) , msg, yylval.id);
 
}