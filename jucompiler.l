%{
	int num_linhas = 1;
	int num_colunas = 1;
%}
%X COMEN_LINHA COMEN
letras					([A-Za-z"_""$"])+
nomes	 				(([A-Za-z"_""$"])+[0-9]*)*

%%
"//"					{BEGIN COMEN_LINHA;num_colunas += yyleng;}
<COMEN_LINHA>."\\n"*	{num_colunas += yyleng;}
<COMEN_LINHA>\n 		{BEGIN 0; num_linhas++;num_colunas = 1;}


"/*"					{BEGIN COMEN;num_colunas += yyleng;}
<COMEN>.				{num_colunas += yyleng;}
<COMEN>"\\n"			{num_colunas += yyleng;}
<COMEN>\n				{num_linhas++; num_colunas = 1;}
<COMEN>"*/" 			{BEGIN 0; num_linhas++;num_colunas = 1;}
<COMEN><<EOF>> 			{BEGIN 0; printf("Line %d, column %d: unterminated string literal", num_linhas, num_colunas); num_linhas++;num_colunas = 1;}


true|false				{printf("BOOLLIT\n");num_colunas+= yyleng;}
"&&" 					{printf("AND\n");num_colunas+= yyleng;}
"=" 					{printf("ASSIGN\n");num_colunas+= yyleng;}
"*" 					{printf("STAR\n");num_colunas+= yyleng;}
"_" 					{printf("BLANKID\n");num_colunas+= yyleng;}
"," 					{printf("COMMA\n");num_colunas+= yyleng;}
"/" 					{printf("DIV\n");num_colunas+= yyleng;}
"=="					{printf("EQ\n");num_colunas+= yyleng;}
">=" 					{printf("GE\n");num_colunas+= yyleng;}
">" 					{printf("GT\n");num_colunas+= yyleng;}
"{" 					{printf("LBRACE\n");num_colunas+= yyleng;}
"<=" 					{printf("LE\n");num_colunas+= yyleng;}
"(" 					{printf("LPAR\n");num_colunas+= yyleng;}	
")" 					{printf("RPAR\n");num_colunas+= yyleng;}
"["						{printf("LSQ\n");num_colunas+= yyleng;}
"<" 					{printf("LT\n");num_colunas+= yyleng;}
"-" 					{printf("MINUS\n");num_colunas+= yyleng;}
"%" 					{printf("MOD\n");num_colunas+= yyleng;}
"!=" 					{printf("NE\n");num_colunas+= yyleng;}
"!" 					{printf("NOT\n");num_colunas+= yyleng;}
"||" 					{printf("OR\n");num_colunas+= yyleng;}
"+" 					{printf("PLUS\n");num_colunas+= yyleng;}
"}" 					{printf("RBRACE\n");num_colunas+= yyleng;}
"]"     				{printf("RSQ\n");num_colunas+= yyleng;}
";" 					{printf("SEMICOLON\n");num_colunas+= yyleng;}
"->"     				{printf("ARROW\n");num_colunas+= yyleng;}
"<<"     				{printf("LSHIFT\n");num_colunas+= yyleng;}
">>"     				{printf("RSHIFT\n");num_colunas+= yyleng;}
"^"     				{printf("XOR\n");num_colunas+= yyleng;}
boolean					{printf("BOOL\n");num_colunas+= yyleng;}
class					{printf("CLASS\n");num_colunas+= yyleng;}
".length"				{printf("DOTLENGTH\n");num_colunas+= yyleng;}
double					{printf("DOUBLE\n");num_colunas+= yyleng;}
else 					{printf("ELSE\n");num_colunas+= yyleng;}
for 					{printf("FOR\n");num_colunas+= yyleng;}
if 						{printf("IF\n");num_colunas+= yyleng;}
var 					{printf("VAR\n");num_colunas+= yyleng;}
int 					{printf("INT\n");num_colunas+= yyleng;}
System.out.print 		{printf("PRINT\n");num_colunas+= yyleng;}
Integer.parseInt 		{printf("PARSEINT\n");num_colunas+= yyleng;}
public					{printf("PUBLIC\n");num_colunas+= yyleng;}
return 					{printf("RETURN\n");num_colunas+= yyleng;}
static					{printf("STATIC\n");num_colunas+= yyleng;}
string					{printf("STRING\n");num_colunas+= yyleng;}
void					{printf("VOID\n");num_colunas+= yyleng;} 
while					{printf("WHILE\n");num_colunas+= yyleng;}
package					{printf("PACKAGE\n");num_colunas+= yyleng;}
func 					{printf("FUNC\n");num_colunas+= yyleng;}
os.Args 				{printf("CMDARGS\n");num_colunas+= yyleng;}
"--" 					{printf("RESERVED(%s)\n", yytext);num_colunas+= yyleng;}
"++" 					{printf("RESERVED(%s)\n", yytext);num_colunas+= yyleng;}
. 						{num_colunas+= yyleng;}
\n     					{num_colunas = 1; num_linhas++;}

{nomes}					{printf("ID(%s)\n",yytext);num_colunas+= yyleng;}

%%
int main(int argc, char *argv[]){
	if(strcmp(argv[13],"e") == 0){
		while(yylex()){}
	}
	return 0;
}

int yywrap()
{
return 1;
}
