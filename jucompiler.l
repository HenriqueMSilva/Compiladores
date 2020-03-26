%{
	#include "y.tab.h"
	int num_linhas = 1;
	int num_colunas = 1;
	int linha_erro = 0;
	int coluna_erro = 0;
	int flag = 0;
	char strlit[200];
	int error_sequence = 0;
%}

valid_escape			\f|\t|\\{2}|\\\"
invalid_escape			[^frtn\\\"]


lineTerminator			\n|\r|(\r\n)


letras					[A-Za-z_\$]
alfanum					[0-9A-Za-z_\$]
space 					(" "|\t|\f)


reserved 				"++"|"--"|"null"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"char"|"const"|"continue"|"default"|"do"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile"|"Integer"|"System"

und_real				 [0-9]|[0-9]["_"0-9]*[0-9]

intlit    				[0-9]|[1-9]["_"0-9]*[0-9]
   
exponte                 (e|E)("+"|"-")?{und_real}+
reallit					({und_real}+"."{und_real}*{exponte}?)|({und_real}+{exponte})|("."{und_real}+{exponte}?)


%X COMEN_LINHA COMEN ASPAS

%%


"//"							{BEGIN COMEN_LINHA;num_colunas += yyleng;}
<COMEN_LINHA>{lineTerminator}	{BEGIN 0;num_colunas = 1;num_linhas++;}
<COMEN_LINHA>.					{num_colunas += yyleng;}


"/*"							{BEGIN COMEN; linha_erro = num_linhas; coluna_erro = num_colunas; num_colunas += yyleng;}
<COMEN>{lineTerminator}			{num_colunas = 1;num_linhas++;}
<COMEN><<EOF>> 					{BEGIN 0;printf("Line %d, col %d: unterminated comment\n", linha_erro, coluna_erro);}
<COMEN>"*/" 					{BEGIN 0;num_colunas += yyleng;}
<COMEN>.						{num_colunas += yyleng;}



\"								{BEGIN ASPAS;strcpy(strlit, "");error_sequence=0;linha_erro = num_linhas; coluna_erro = num_colunas; num_colunas += yyleng;}
<ASPAS>{valid_escape}			{if(error_sequence== 0){strcat(strlit, yytext);}num_colunas += yyleng;}
<ASPAS>{lineTerminator} 		{BEGIN 0; printf("Line %d, col %d: unterminated string literal\n", linha_erro, coluna_erro);num_colunas = 1;num_linhas++;}
<ASPAS>\"						{BEGIN 0; if(flag == 0 && error_sequence== 0){printf("STRLIT(\"%s\")\n",strlit);}num_colunas += yyleng;}
<ASPAS><<EOF>> 					{BEGIN 0; printf("Line %d, col %d: unterminated string literal\n", linha_erro, coluna_erro);}
<ASPAS>\\{lineTerminator}		{BEGIN 0; error_sequence = 1; printf("Line %d, col %d: invalid escape sequence (\\)\n", num_linhas, num_colunas);printf("Line %d, col %d: unterminated string literal\n", linha_erro, coluna_erro); num_linhas++ ; num_colunas = 1;}							
<ASPAS>\\{invalid_escape}		{error_sequence = 1; printf("Line %d, col %d: invalid escape sequence (%s)\n", num_linhas, num_colunas, yytext);num_colunas += yyleng;}							
<ASPAS>.						{if(error_sequence == 0){strcat(strlit, yytext);}num_colunas += yyleng;}



true|false				{if(flag==0){printf("BOOLLIT(%s)\n",yytext);}num_colunas+= yyleng;return BOOLLIT;}
"&&" 					{if(flag==0){printf("AND\n");}num_colunas+= yyleng;return AND;}
"=" 					{if(flag==0){printf("ASSIGN\n");}num_colunas+= yyleng;return ASSIGN;}
"*" 					{if(flag==0){printf("STAR\n");}num_colunas+= yyleng;return STAR;}
"," 					{if(flag==0){printf("COMMA\n");}num_colunas+= yyleng;return COMMA;}
"/" 					{if(flag==0){printf("DIV\n");}num_colunas+= yyleng;return DIV;}
"=="					{if(flag==0){printf("EQ\n");}num_colunas+= yyleng;return EQ;}
">=" 					{if(flag==0){printf("GE\n");}num_colunas+= yyleng;return GE;}
">" 					{if(flag==0){printf("GT\n");}num_colunas+= yyleng;return GT;}
"{" 					{if(flag==0){printf("LBRACE\n");}num_colunas+= yyleng; return LBRACE;}
"<=" 					{if(flag==0){printf("LE\n");}num_colunas+= yyleng;return LE;}
"(" 					{if(flag==0){printf("LPAR\n");}num_colunas+= yyleng; return LPAR;}	
")" 					{if(flag==0){printf("RPAR\n");}num_colunas+= yyleng; return RPAR;}
"["						{if(flag==0){printf("LSQ\n");}num_colunas+= yyleng;return LSQ;}
"<" 					{if(flag==0){printf("LT\n");}num_colunas+= yyleng;return LT;}
"-" 					{if(flag==0){printf("MINUS\n");}num_colunas+= yyleng;return MINUS;}
"%" 					{if(flag==0){printf("MOD\n");}num_colunas+= yyleng;return MOD;}
"!=" 					{if(flag==0){printf("NE\n");}num_colunas+= yyleng;return NE;}
"!" 					{if(flag==0){printf("NOT\n");}num_colunas+= yyleng;return NOT;}
"||" 					{if(flag==0){printf("OR\n");}num_colunas+= yyleng;return OR;}
"+" 					{if(flag==0){printf("PLUS\n");}num_colunas+= yyleng;return PLUS;}
"}" 					{if(flag==0){printf("RBRACE\n");}num_colunas+= yyleng; return RBRACE;}
"]"     				{if(flag==0){printf("RSQ\n");}num_colunas+= yyleng;return RSQ;}
";" 					{if(flag==0){printf("SEMICOLON\n");}num_colunas+= yyleng;return SEMICOLON;}
"->"     				{if(flag==0){printf("ARROW\n");}num_colunas+= yyleng;return ARROW;}
"<<"     				{if(flag==0){printf("LSHIFT\n");}num_colunas+= yyleng;return LSHIFT;}
">>"     				{if(flag==0){printf("RSHIFT\n");}num_colunas+= yyleng;return RSHIFT;}
"^"     				{if(flag==0){printf("XOR\n");}num_colunas+= yyleng;return XOR;}
boolean					{if(flag==0){printf("BOOL\n");}num_colunas+= yyleng; return BOOL;}
class					{if(flag==0){printf("CLASS\n");}num_colunas+= yyleng; return CLASS;}
".length"				{if(flag==0){printf("DOTLENGTH\n");}num_colunas+= yyleng;return DOTLENGTH;}
double					{if(flag==0){printf("DOUBLE\n");}num_colunas+= yyleng; return DOUBLE;}
else 					{if(flag==0){printf("ELSE\n");}num_colunas+= yyleng; return ELSE;}
if 						{if(flag==0){printf("IF\n");}num_colunas+= yyleng; return IF;}
int 					{if(flag==0){printf("INT\n");}num_colunas+= yyleng; return INT;}
"System.out.print" 		{if(flag==0){printf("PRINT\n");}num_colunas+= yyleng;return PRINT;}
"Integer.parseInt" 		{if(flag==0){printf("PARSEINT\n");}num_colunas+= yyleng;return PARSEINT;}
public					{if(flag==0){printf("PUBLIC\n");}num_colunas+= yyleng; return PUBLIC;}
return 					{if(flag==0){printf("RETURN\n");}num_colunas+= yyleng;return RETURN;}
static					{if(flag==0){printf("STATIC\n");}num_colunas+= yyleng; return STATIC;}
String					{if(flag==0){printf("STRING\n");}num_colunas+= yyleng;return STRING;}
void					{if(flag==0){printf("VOID\n");}num_colunas+= yyleng;return VOID;} 
while					{if(flag==0){printf("WHILE\n");}num_colunas+= yyleng;return WHILE;}


{reserved}				{if(flag==0){printf("RESERVED(%s)\n",yytext);}num_colunas+= yyleng;}

{letras}{alfanum}*		{if(flag==0){printf("ID(%s)\n",yytext);}num_colunas+= yyleng; yylval.id = strdup(yytext); return ID;}
{reallit}				{if(flag==0){printf("REALLIT(%s)\n",yytext);}num_colunas+= yyleng;}
{intlit}				{if(flag==0){printf("INTLIT(%s)\n",yytext);}num_colunas+= yyleng;}

{space}					{num_colunas += yyleng;}
{lineTerminator}		{num_colunas = 1;num_linhas++;}

.	 					{printf("Line %d, col %d: illegal character (%s)\n",num_linhas,num_colunas,yytext);num_colunas+= yyleng;}

%%
int main(int argc, char *argv[]){
	if(argc == 2){
		if(strcmp(argv[1],"-l") == 0){
			flag = 0;
			while(yylex()){}
		}else if(strcmp(argv[1],"-e1") == 0){
			flag = 1;
			while(yylex()){}
		}else if(strcmp(argv[1],"-t") == 0){
			yyparse();
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
