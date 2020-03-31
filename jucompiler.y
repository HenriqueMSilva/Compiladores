%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "y.tab.h"
int yydebug = 1;

extern int linha_erro, coluna_erro, num_colunas, num_linhas, error_sequence,erro_sintaxe;
extern char* yytext;
int yylex (void);
void yyerror(char* s);

is_program* myprogram;

%}

%token AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR RPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS DOTLENGTH DOUBLE ELSE IF INT PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE RESERVED

%token<id>ID INTLIT STRLIT REALLIT BOOLLIT

%type<ip>program
%type<im>metodos
%type<ifl>FieldDeclNext FieldDecl
%type<imdl>MethodDecl
%type<imhl>MethodHeader
%type<impl>MethodParams MethodParamsNext
%type<imbl>body MethodBody
%type<ivdl>VarDecl VarDeclNext
%type<state> Statement StatementZrOuMais
%type<iel>StatementPrint StatementExpOp Expr ExprA MethodInvocation ParseArgs ExpCommaExpOP CommaExprZrOuMais
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
%right ELSE

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



Statement:  IF LPAR  ExprA RPAR Statement    %prec REDUCE   {$$ = insert_multiple_statement("If", $3, $5, NULL);}
        |   IF LPAR  ExprA RPAR Statement ELSE Statement    {$$ = insert_multiple_statement("If", $3, $5, $7);}
        |   WHILE LPAR ExprA RPAR Statement                 {}
        |   RETURN StatementExpOp SEMICOLON                 {$$ = insert_statment("Return",NULL,$2);}
        |   LBRACE StatementZrOuMais RBRACE                 {$$ = $2;}
        |   PRINT LPAR StatementPrint RPAR SEMICOLON        {$$ = insert_statment("Print",NULL,$3);}
        |   MethodInvocation SEMICOLON                      {$$ = insert_statment("Call",NULL,$1);}
        |   ID ASSIGN ExprA  SEMICOLON                      {$$ = insert_statment("AssignStatment",NULL,insert_expr("Assign",$1,$3,NULL));}
        |   ParseArgs SEMICOLON                             {$$ = insert_statment("ParseArgs",NULL,$1);}
        |   SEMICOLON                                       {$$ = NULL;printf("semi\n");}
    ; 

StatementZrOuMais: /*empty*/                                {$$ = NULL;}
            | Statement  StatementZrOuMais                  {$$ = insert_multiple_statement("Statment", NULL, $1, $2);}
    ;

StatementExpOp: /*empty*/                                   {$$ = NULL;}
            |     ExprA                                     {$$ = $1;}
    ;

StatementPrint: STRLIT                                      {$$ = insert_expr("StrLit",$1,NULL,NULL);}
        |     ExprA                                         {$$ = $1;}
    ;




MethodInvocation: ID LPAR ExpCommaExpOP RPAR                 {$$ = insert_expr("Call",$1,$3,NULL);}
    ;

ExpCommaExpOP: /*empty*/                                     {$$ = NULL;} 
            |  ExprA CommaExprZrOuMais                       {$$ = insert_expr("CallMore","",$1,$2);} 
    ;

CommaExprZrOuMais: /*empty*/                                 {$$ = NULL;}
         | COMMA  ExprA CommaExprZrOuMais                    {$$ = insert_expr("CallMore","",$2,$3);}
    ;


ParseArgs:  PARSEINT LPAR ID LSQ  ExprA RSQ RPAR  {$$ = insert_expr("ParseArgs",$3,$5,NULL);}
    ;



ExprA: Expr                                     {$$ = $1;}
    |  ID ASSIGN ExprA                          {$$ = insert_expr("Assign",$1,$3,NULL);}
    |  LPAR ID ASSIGN ExprA RPAR                {$$ = insert_expr("Assign",$2,$4,NULL);}
    ;


Expr: Expr AND Expr                             {$$ = insert_expr("Operacao","And",$1,$3);}
    | Expr OR Expr                              {$$ = insert_expr("Operacao","Or",$1,$3);}
    | Expr EQ Expr                              {$$ = insert_expr("Operacao","Eq",$1,$3);}
    | Expr GE Expr                              {$$ = insert_expr("Operacao","Ge",$1,$3);}
    | Expr GT Expr                              {$$ = insert_expr("Operacao","Gt",$1,$3);}
    | Expr LE Expr                              {$$ = insert_expr("Operacao","Le",$1,$3);}
    | Expr LT Expr                              {$$ = insert_expr("Operacao","Lt",$1,$3);}
    | Expr NE Expr                              {$$ = insert_expr("Operacao","Ne",$1,$3);}
    | Expr PLUS Expr                            {$$ = insert_expr("Operacao","Add",$1,$3);}
    | Expr MINUS Expr                           {$$ = insert_expr("Operacao","Sub",$1,$3);}               
    | Expr STAR Expr                            {$$ = insert_expr("Operacao","Mul",$1,$3);}
    | Expr DIV Expr                             {$$ = insert_expr("Operacao","Div",$1,$3);}
    | Expr MOD Expr                             {$$ = insert_expr("Operacao","Mod",$1,$3);} 
    | Expr XOR Expr                             {$$ = insert_expr("Operacao","Xor",$1,$3);}
    | Expr LSHIFT Expr                          {$$ = insert_expr("Operacao","Lshift",$1,$3);}
    | Expr RSHIFT Expr                          {$$ = insert_expr("Operacao","Rshift",$1,$3);}
    | NOT Expr                                  {$$ = insert_expr("Operacao","Not",$2,NULL);}
    | MINUS Expr                                {$$ = insert_expr("Operacao","Minus",$2,NULL);}
    | PLUS Expr                                 {$$ = insert_expr("Operacao","Plus",$2,NULL);}
    | LPAR ExprA RPAR                           {$$ = $2;}
    | MethodInvocation                          {$$ = $1;}
    | ParseArgs                                 {$$ = $1;} 
    | ID                                        {$$ = insert_expr("Id",$1,NULL,NULL);}
    | ID DOTLENGTH                              {$$ = insert_expr("Length",$1,NULL,NULL);}
    | REALLIT                                   {$$ = insert_expr("RealLit",$1,NULL,NULL);}
    | BOOLLIT                                   {$$ = insert_expr("BoolLit",$1,NULL,NULL);}
    | INTLIT                                    {$$ = insert_expr("DecLit",$1,NULL,NULL);}
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