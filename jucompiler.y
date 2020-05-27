%{
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

%}



%token<id> AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR RPAR LSQ LT MINUS MOD NE NOT OR  RBRACE RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS DOTLENGTH DOUBLE ELSE IF INT PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE RESERVED ID INTLIT STRLIT REALLIT BOOLLIT PLUS


%type<ip>program
%type<im>metodos
%type<ifl>FieldDeclNext FieldDecl
%type<imdl>MethodDecl
%type<imhl>MethodHeader
%type<impl>MethodParams MethodParamsNext
%type<imbl>body MethodBody
%type<ivdl>VarDecl VarDeclNext
%type<state> Statement StatementZrOuMais 
%type<iel>StatementPrint StatementExpOp  Expr ExprA MethodInvocation  ParseArgs ExpCommaExpOP CommaExprZrOuMais
%type<str>Type



%right ASSIGN
%left OR
%left AND
%left XOR
%left EQ NE
%left GE GT LT LE
%left LSHIFT RSHIFT
%left PLUS MINUS
%left STAR DIV MOD
%right NOT
%left LPAR RPAR LSQ RSQ



%nonassoc REDUCE
%right ELSE

/*
%destructor{ if($$!= NULL){free($$); $$ = NULL;} } <id>
%destructor{ if($$!= NULL){free_is_metodos($$); $$ = NULL; } } <im>
%destructor{ if($$!= NULL){free_is_fielddecl_list($$); $$ = NULL; } } <ifl>
%destructor{ if($$!= NULL){free_is_methoddecl_list($$); $$ = NULL;} } <imdl>
%destructor{ if($$!= NULL){free_is_methodheader_list($$); $$ = NULL;} } <imhl>
%destructor{ if($$!= NULL){free_is_methodparams_list($$); $$ = NULL;} } <impl>
%destructor{ if($$!= NULL){free_is_methodbody_list($$); $$ = NULL;} } <imbl>
%destructor{ if($$!= NULL){free_is_vardecl_list($$); $$ = NULL;} } <ivdl>
%destructor{ if($$!= NULL){free_is_statment_list($$); $$ = NULL;} } <state>
%destructor{ if($$!= NULL){free_is_expression_list($$); $$ = NULL;} } <iel>
*/

%union{
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
}

%%

program: CLASS ID LBRACE metodos RBRACE                     {$$=myprogram=insert_program($2->id, $4, $2->linha, $2->coluna); free($2->id);}
    ;

metodos: /*empty*/                                          {$$ = NULL;}
        | MethodDecl metodos                                {$$=insert_metodos("Method",NULL,$1,$2);}     
        | FieldDecl  metodos                                {$$=insert_metodos("Field",$1,NULL,$2);}
        | SEMICOLON  metodos                                {$$=insert_metodos("Semicolon",NULL,NULL,$2);}
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody           {$$=insert_methoddecl($3,$4);}
    ;

FieldDecl:  PUBLIC STATIC Type ID FieldDeclNext SEMICOLON   {$$=insert_field($3,$4->id,$5,$4->linha, $4->coluna );free($4->id);}
    ;

FieldDeclNext:  /*empty*/                                   {$$ = NULL;}     
             |  COMMA ID FieldDeclNext                      {$$=insert_field("",$2->id,$3,$2->linha, $2->coluna ); free($2->id);}
    ;

Type: BOOL                                                  {$$="Bool";}
    | INT                                                   {$$="Int";}
    | DOUBLE                                                {$$="Double";}

    ;

MethodHeader: Type ID LPAR MethodParams RPAR                {$$=insert_methodheader($1,$2->id,$4, $2->linha, $2->coluna );free($2->id);}
            | VOID ID LPAR MethodParams RPAR                {$$=insert_methodheader("Void",$2->id,$4, $2->linha, $2->coluna);free($2->id);}
    ;

MethodParams:  /*empty*/                                    {$$ = NULL;}
            | Type ID MethodParamsNext                      {$$=insert_methodparams($1,$2->id,$3 , $2->linha, $2->coluna);free($2->id);}
            | STRING LSQ RSQ ID                             {$$=insert_methodparams("StringArray",$4->id,NULL, $1->linha, $1->coluna);free($4->id);}
    ;

MethodParamsNext: /*empty*/                                 {$$ = NULL;}
                | COMMA Type ID MethodParamsNext            {$$=insert_methodparams($2,$3->id,$4, $3->linha, $3->coluna);free($3->id);}
    ;

MethodBody: LBRACE body RBRACE                              {$$ = $2;}
    ;

body:   /*empty*/                                           {$$ = NULL;}
    |   VarDecl  body                                       {$$=insert_methodbody("VarDecl",$1,NULL,$2);}
    |   Statement body                                      {$$=insert_methodbody("Statement",NULL,$1,$2);}
    ;

VarDecl: Type ID  VarDeclNext SEMICOLON                     {$$=insert_vardecl($1,$2->id,$3, $2->linha, $2->coluna);free($2->id);}
    ;

VarDeclNext: /*empty*/                                      {$$ = NULL;}
           | COMMA ID  VarDeclNext                          {$$=insert_vardecl("",$2->id,$3, $2->linha, $2->coluna);free($2->id);}
    ;

Statement:  IF LPAR  ExprA RPAR   Statement  %prec REDUCE   {$$ = insert_multiple_statement("If", $3, $5, NULL);}
        |   IF LPAR  ExprA RPAR Statement ELSE Statement    {$$ = insert_multiple_statement("IfElse", $3, $5, $7);}


        |   WHILE LPAR ExprA RPAR Statement                 {$$ = insert_multiple_statement("While", $3, $5, NULL);}
        |   RETURN StatementExpOp SEMICOLON                 {if($2==NULL){$2=insert_expr("Emp_Return","",NULL,NULL,$1->linha, $1->coluna,-1,-1);}     $$ = insert_multiple_statement("Return", $2, NULL, NULL);}
        |   LBRACE StatementZrOuMais RBRACE                 {$$ = insert_multiple_statement("Block", NULL, $2, NULL);}
        |   PRINT LPAR StatementPrint RPAR SEMICOLON        {$$ = insert_multiple_statement("Print", $3, NULL, NULL);}
        |   MethodInvocation SEMICOLON                      {$$ = insert_multiple_statement("Call", $1, NULL, NULL);}
        |   ID ASSIGN ExprA  SEMICOLON                      {$$ = insert_multiple_statement("AssignStatment", insert_expr("Assign",$1->id,$3,NULL, $1->linha,$1->coluna,$2->linha, $2->coluna), NULL, NULL );free($1->id);}
        |   ParseArgs SEMICOLON                             {$$ = insert_multiple_statement("ParseArgsStatment", $1,NULL, NULL);}
        |   SEMICOLON                                       {$$ = NULL;}
    ; 


StatementZrOuMais: /*empty*/                                {$$ = NULL;}
            | Statement  StatementZrOuMais                  {$$ = insert_multiple_statement("Statment", NULL, $1, $2);}
    ;

StatementExpOp: /*empty*/                                   {$$ = NULL;}
            |     ExprA                                     {$$ = $1;}
    ;

StatementPrint: STRLIT                                      {$$ = insert_expr("StrLit",$1->id,NULL,NULL, $1->linha,$1->coluna,-1,-1);free($1->id);}
        |     ExprA                                         {$$ = $1;}
    ;




MethodInvocation: ID LPAR ExpCommaExpOP RPAR                 {$$ = insert_expr("Call",$1->id,$3,NULL, $1->linha,$1->coluna,-1,-1);free($1->id);}
    ;

ExpCommaExpOP: /*empty*/                                     {$$ = NULL;} 
            |  ExprA CommaExprZrOuMais                       {$$ = insert_expr("CallMore","",$1,$2, -1,-1,-1,-1);}
    ;

CommaExprZrOuMais: /*empty*/                                 {$$ = NULL;}
         | COMMA  ExprA CommaExprZrOuMais                    {$$ = insert_expr("CallMore","",$2,$3, -1,-1,-1,-1);}
    ;


ParseArgs:  PARSEINT LPAR ID LSQ  ExprA RSQ RPAR             {$$ = insert_expr("ParseArgs",$3->id,$5,NULL, $1->linha,$1->coluna,$3->linha,$3->coluna);free($3->id);}


    ;



ExprA: Expr                                     {$$ = $1;}
    |  ID ASSIGN ExprA                          {$$ = insert_expr("Assign",$1->id,$3,NULL,$1->linha,$1->coluna,$2->linha,$2->coluna );free($1->id);}
    ;


Expr: Expr AND Expr                             {$$ = insert_expr("Operacao","And",$1,$3,$2->linha,$2->coluna,-1,-1);}
    | Expr OR Expr                              {$$ = insert_expr("Operacao","Or",$1,$3, $2->linha,$2->coluna,-1,-1);}
    | Expr EQ Expr                              {$$ = insert_expr("Operacao","Eq",$1,$3, $2->linha,$2->coluna,-1,-1);}
    | Expr GE Expr                              {$$ = insert_expr("Operacao","Ge",$1,$3, $2->linha,$2->coluna,-1,-1);}
    | Expr GT Expr                              {$$ = insert_expr("Operacao","Gt",$1,$3, $2->linha,$2->coluna,-1,-1);}
    | Expr LE Expr                              {$$ = insert_expr("Operacao","Le",$1,$3, $2->linha,$2->coluna,-1,-1);}
    | Expr LT Expr                              {$$ = insert_expr("Operacao","Lt",$1,$3, $2->linha,$2->coluna,-1,-1);}
    | Expr NE Expr                              {$$ = insert_expr("Operacao","Ne",$1,$3, $2->linha,$2->coluna,-1,-1);}
    | Expr PLUS Expr                            {$$ = insert_expr("Operacao","Add",$1,$3, $2->linha,$2->coluna,-1,-1);}
    | Expr MINUS Expr                           {$$ = insert_expr("Operacao","Sub",$1,$3, $2->linha,$2->coluna,-1,-1);}               
    | Expr STAR Expr                            {$$ = insert_expr("Operacao","Mul",$1,$3, $2->linha,$2->coluna,-1,-1);}
    | Expr DIV Expr                             {$$ = insert_expr("Operacao","Div",$1,$3, $2->linha,$2->coluna,-1,-1);}
    | Expr MOD Expr                             {$$ = insert_expr("Operacao","Mod",$1,$3, $2->linha,$2->coluna,-1,-1);}
    | Expr XOR Expr                             {$$ = insert_expr("Operacao","Xor",$1,$3, $2->linha,$2->coluna,-1,-1);}
    | Expr LSHIFT Expr                          {$$ = insert_expr("Operacao","Lshift",$1,$3, $2->linha,$2->coluna,-1,-1);}
    | Expr RSHIFT Expr                          {$$ = insert_expr("Operacao","Rshift",$1,$3, $2->linha,$2->coluna,-1,-1);}
    | NOT Expr                                  {$$ = insert_expr("Operacao","Not",$2,NULL, $1->linha,$1->coluna,-1,-1);}
    | MINUS Expr %prec NOT                      {$$ = insert_expr("Operacao","Minus",$2,NULL, $1->linha,$1->coluna,-1,-1);}
    | PLUS Expr %prec NOT                       {$$ = insert_expr("Operacao","Plus",$2,NULL, $1->linha,$1->coluna,-1,-1);}
    | LPAR ExprA RPAR                           {$$ = $2;}
    | MethodInvocation                          {$$ = $1;}
    | ParseArgs                                 {$$ = $1;} 
    | ID                                        {$$ = insert_expr("Id",$1->id,NULL,NULL, $1->linha,$1->coluna,-1,-1);free($1->id);}
    | ID DOTLENGTH                              {$$ = insert_expr("Length",$1->id,NULL,NULL, $1->linha,$1->coluna,$2->linha, $2->coluna);free($1->id);}
    | REALLIT                                   {$$ = insert_expr("RealLit",$1->id,NULL,NULL, $1->linha,$1->coluna,-1,-1);free($1->id);}
    | BOOLLIT                                   {$$ = insert_expr("BoolLit",$1->id,NULL,NULL, $1->linha,$1->coluna,-1,-1);free($1->id);}
    | INTLIT                                    {$$ = insert_expr("DecLit",$1->id,NULL,NULL, $1->linha,$1->coluna,-1,-1);free($1->id);}
    ; 




FieldDecl : error SEMICOLON                                 {$$=NULL;}
    ;

Statement : error SEMICOLON                                 {$$=NULL;}
    ;
ParseArgs: PARSEINT LPAR error RPAR                         {$$=NULL;}
    ; 

MethodInvocation: ID LPAR error RPAR                        {$$=NULL; free($1->id);}
    ;

Expr: LPAR error RPAR                                       {$$=NULL;}
    ;

%%

void yyerror(char *msg) {
    erro_sintaxe=1;
    printf("Line %d, col %d: %s: %s\n", num_linhas, num_colunas - (int) strlen(yylval.id->id) , msg, yylval.id->id);

 
}