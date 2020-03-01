%{
	int num_linhas = 1;
	int num_colunas = 1;
	int linha_erro = 0;
	int coluna_erro = 0;
	int flag = 0;
	char strlit[200];
%}

letras					[A-Za-z_$]
alfanum					[0-9A-Za-z_$]
space 					(" "|"\t")
reserved 				"++"|"--"|"null"

intlit    				[0-9]|[1-9]+["_"0-9]*[0-9]+
   
exponte                 (e|E)("+"|"-")?["_"0-9]+
reallit					(["_"0-9]+"."["_"0-9]*{exponte}*)|(["_"0-9]+{exponte})|("."["_"0-9]*{exponte}*)

escape					\\f|\\n|\\r|\\t|\\\\|\\

%X COMEN_LINHA COMEN ASPAS

%%
"//"					{BEGIN COMEN_LINHA;num_colunas += yyleng;}
<COMEN_LINHA>.*			{num_colunas += yyleng;}
<COMEN_LINHA>\n 		{BEGIN 0;num_colunas = 1;num_linhas++;}


"/*"					{BEGIN COMEN; linha_erro = num_linhas; coluna_erro = num_colunas; num_colunas += yyleng;}
<COMEN>.				{num_colunas += yyleng;}
<COMEN>"\\n"			{num_colunas += yyleng;}
<COMEN>\n				{num_colunas = 1;num_linhas++;}
<COMEN>"*/" 			{BEGIN 0;num_colunas += yyleng;}
<COMEN><<EOF>> 			{BEGIN 0;printf("Line %d, column %d: unterminated comment\n", linha_erro, coluna_erro);}


\"						{BEGIN ASPAS;strcpy(strlit, "");linha_erro = num_linhas; coluna_erro = num_colunas; num_colunas += yyleng;}
<ASPAS>\n 				{BEGIN 0;printf("Line %d, column %d: unterminated string literal\n", linha_erro, coluna_erro);num_colunas += yyleng;num_linhas++;}
<ASPAS>{alfanum}		{strcat(strlit, yytext);num_colunas += yyleng;}
<ASPAS>{escape}			{strcat(strlit, yytext);num_colunas += yyleng;}
<ASPAS>{space}			{strcat(strlit, yytext);num_colunas += yyleng;}
<ASPAS>\"				{BEGIN 0;if(flag==0){printf("STRLIT(\"%s\")\n",strlit);}num_colunas += yyleng;}
<ASPAS><<EOF>> 			{BEGIN 0; printf("Line %d, column %d: unterminated string literal\n", linha_erro, coluna_erro);}
<ASPAS>[^\\]			{num_colunas += yyleng;}



true|false				{if(flag==0){printf("BOOLLIT\n");}num_colunas+= yyleng;}
"&&" 					{if(flag==0){printf("AND\n");}num_colunas+= yyleng;}
"=" 					{if(flag==0){printf("ASSIGN\n");}num_colunas+= yyleng;}
"*" 					{if(flag==0){printf("STAR\n");}num_colunas+= yyleng;}
"_" 					{if(flag==0){printf("BLANKID\n");}num_colunas+= yyleng;}
"," 					{if(flag==0){printf("COMMA\n");}num_colunas+= yyleng;}
"/" 					{if(flag==0){printf("DIV\n");}num_colunas+= yyleng;}
"=="					{if(flag==0){printf("EQ\n");}num_colunas+= yyleng;}
">=" 					{if(flag==0){printf("GE\n");}num_colunas+= yyleng;}
">" 					{if(flag==0){printf("GT\n");}num_colunas+= yyleng;}
"{" 					{if(flag==0){printf("LBRACE\n");}num_colunas+= yyleng;}
"<=" 					{if(flag==0){printf("LE\n");}num_colunas+= yyleng;}
"(" 					{if(flag==0){printf("LPAR\n");}num_colunas+= yyleng;}	
")" 					{if(flag==0){printf("RPAR\n");}num_colunas+= yyleng;}
"["						{if(flag==0){printf("LSQ\n");}num_colunas+= yyleng;}
"<" 					{if(flag==0){printf("LT\n");}num_colunas+= yyleng;}
"-" 					{if(flag==0){printf("MINUS\n");}num_colunas+= yyleng;}
"%" 					{if(flag==0){printf("MOD\n");}num_colunas+= yyleng;}
"!=" 					{if(flag==0){printf("NE\n");}num_colunas+= yyleng;}
"!" 					{if(flag==0){printf("NOT\n");}num_colunas+= yyleng;}
"||" 					{if(flag==0){printf("OR\n");}num_colunas+= yyleng;}
"+" 					{if(flag==0){printf("PLUS\n");}num_colunas+= yyleng;}
"}" 					{if(flag==0){printf("RBRACE\n");}num_colunas+= yyleng;}
"]"     				{if(flag==0){printf("RSQ\n");}num_colunas+= yyleng;}
";" 					{if(flag==0){printf("SEMICOLON\n");}num_colunas+= yyleng;}
"->"     				{if(flag==0){printf("ARROW\n");}num_colunas+= yyleng;}
"<<"     				{if(flag==0){printf("LSHIFT\n");}num_colunas+= yyleng;}
">>"     				{if(flag==0){printf("RSHIFT\n");}num_colunas+= yyleng;}
"^"     				{if(flag==0){printf("XOR\n");}num_colunas+= yyleng;}
boolean					{if(flag==0){printf("BOOL\n");}num_colunas+= yyleng;}
class					{if(flag==0){printf("CLASS\n");}num_colunas+= yyleng;}
".length"				{if(flag==0){printf("DOTLENGTH\n");}num_colunas+= yyleng;}
double					{if(flag==0){printf("DOUBLE\n");}num_colunas+= yyleng;}
else 					{if(flag==0){printf("ELSE\n");}num_colunas+= yyleng;}
for 					{if(flag==0){printf("FOR\n");}num_colunas+= yyleng;}
if 						{if(flag==0){printf("IF\n");}num_colunas+= yyleng;}
var 					{if(flag==0){printf("VAR\n");}num_colunas+= yyleng;}
int 					{if(flag==0){printf("INT\n");}num_colunas+= yyleng;}
System.out.print 		{if(flag==0){printf("PRINT\n");}num_colunas+= yyleng;}
Integer.parseInt 		{if(flag==0){printf("PARSEINT\n");}num_colunas+= yyleng;}
public					{if(flag==0){printf("PUBLIC\n");}num_colunas+= yyleng;}
return 					{if(flag==0){printf("RETURN\n");}num_colunas+= yyleng;}
static					{if(flag==0){printf("STATIC\n");}num_colunas+= yyleng;}
String					{if(flag==0){printf("STRING\n");}num_colunas+= yyleng;}
void					{if(flag==0){printf("VOID\n");}num_colunas+= yyleng;} 
while					{if(flag==0){printf("WHILE\n");}num_colunas+= yyleng;}
package					{if(flag==0){printf("PACKAGE\n");}num_colunas+= yyleng;}
func 					{if(flag==0){printf("FUNC\n");}num_colunas+= yyleng;}

{space}					{num_colunas += yyleng;}
{reserved}				{if(flag==0){printf("RESERVED(%s)\n", yytext);}num_colunas+= yyleng;}

{letras}{alfanum}*		{if(flag==0){printf("ID(%s)\n",yytext);}num_colunas+= yyleng;}
{reallit}				{if(flag==0){printf("REALLIT(%s)\n",yytext);}num_colunas+= yyleng;}
{intlit}				{if(flag==0){printf("INTLIT(%s)\n",yytext);}num_colunas+= yyleng;}

\n      				{num_colunas = 1; num_linhas++;}
.	 					{num_colunas+= yyleng;}


%%
int main(int argc, char *argv[]){
	if(argc == 2){
		if(strcmp(argv[1],"-l") == 0){
			flag = 0;
			while(yylex()){}
		}else if(strcmp(argv[1],"-e1") == 0){
			flag = 1;
			while(yylex()){}
		}
	}else if(argc == 1){
			flag = 1;
			while(yylex()){}
		}
	return 0;
}

int yywrap()
{
return 1;
}
