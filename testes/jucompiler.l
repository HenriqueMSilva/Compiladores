%{
	int num_linhas = 1;
	int num_colunas = 1;
	int flag = 0;

%}

reserved 				"++"|"--"|"null"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"char"|"const"|"continue"|"default"|"do"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"instance"|"long"|"native"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile"|"Integer"|"System"


space 					(" "|\t)
lineTerminator			\n|\r|(\r\n)


letras					[A-Za-z_$]
alfanum					[0-9A-Za-z_$]
%%

{reserved}				{printf("RESERVED(%s)\n",yytext);num_colunas+= yyleng;}

true|false				{if(flag==0){printf("BOOLLIT(%s)\n",yytext);}num_colunas+= yyleng;}
"&&" 					{if(flag==0){printf("AND\n");}num_colunas+= yyleng;}
"=" 					{if(flag==0){printf("ASSIGN\n");}num_colunas+= yyleng;}
"*" 					{if(flag==0){printf("STAR\n");}num_colunas+= yyleng;}
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
.length					{if(flag==0){printf("DOTLENGTH\n");}num_colunas+= yyleng;}
double					{if(flag==0){printf("DOUBLE\n");}num_colunas+= yyleng;}
else 					{if(flag==0){printf("ELSE\n");}num_colunas+= yyleng;}
if 						{if(flag==0){printf("IF\n");}num_colunas+= yyleng;}
int 					{if(flag==0){printf("INT\n");}num_colunas+= yyleng;}
System.out.print 		{if(flag==0){printf("PRINT\n");}num_colunas+= yyleng;}
Integer.parseInt 		{if(flag==0){printf("PARSEINT\n");}num_colunas+= yyleng;}
public					{if(flag==0){printf("PUBLIC\n");}num_colunas+= yyleng;}
return 					{if(flag==0){printf("RETURN\n");}num_colunas+= yyleng;}
static					{if(flag==0){printf("STATIC\n");}num_colunas+= yyleng;}
String					{if(flag==0){printf("STRING\n");}num_colunas+= yyleng;}
void					{if(flag==0){printf("VOID\n");}num_colunas+= yyleng;} 
while					{if(flag==0){printf("WHILE\n");}num_colunas+= yyleng;}



{lineTerminator}		{num_colunas = 1;num_linhas++;}
{space}					{num_colunas += yyleng;}
{letras}{alfanum}*		{printf("ID(%s)\n",yytext);num_colunas+= yyleng;}
. 						{;}

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
