%{
// Henrique Miguel Silva 2017246594
//Pedro Almeida 2017255094	

	#include "structures.h"
	#include "functions.h"
	#include "symbol_table.h"
	#include "semantics.h"
	#include "y.tab.h"
	int num_linhas = 1;
	int num_colunas = 1;
	int linha_erro = 0;
	int coluna_erro = 0;
	int flag = 0;
	int erro_sintaxe = 0;
	char strlit[200];
	int error_sequence = 0;

	extern is_program* myprogram;
	header_global 	*symtab_global 	= NULL;
	table_element_local 	*symtab_local 	= NULL;
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



\"								{BEGIN ASPAS;strcpy(strlit, "\"");error_sequence=0;linha_erro = num_linhas; coluna_erro = num_colunas; num_colunas += yyleng;}
<ASPAS>{valid_escape}			{if(error_sequence== 0){strcat(strlit, yytext);}num_colunas += yyleng;}
<ASPAS>{lineTerminator} 		{BEGIN 0; printf("Line %d, col %d: unterminated string literal\n", linha_erro, coluna_erro);num_colunas = 1;num_linhas++;}
<ASPAS>\"						{BEGIN 0; strcat(strlit, "\"");  if(flag == 0 && error_sequence== 0){ printf("STRLIT(%s)\n",strlit);} num_colunas += yyleng; yylval.id=(id_lin_col*) malloc(sizeof(id_lin_col)); yylval.id->id=strdup(strlit); yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); if(error_sequence == 0){return STRLIT;}else{ free(yylval.id->id); free(yylval.id); } }
<ASPAS><<EOF>> 					{BEGIN 0; printf("Line %d, col %d: unterminated string literal\n", linha_erro, coluna_erro);}
<ASPAS>\\{lineTerminator}		{BEGIN 0; error_sequence = 1; printf("Line %d, col %d: invalid escape sequence (\\)\n", num_linhas, num_colunas);printf("Line %d, col %d: unterminated string literal\n", linha_erro, coluna_erro); num_linhas++ ; num_colunas = 1;}							
<ASPAS>\\{invalid_escape}		{error_sequence = 1; printf("Line %d, col %d: invalid escape sequence (%s)\n", num_linhas, num_colunas, yytext);num_colunas += yyleng;}							
<ASPAS>.						{if(error_sequence == 0){strcat(strlit, yytext);}num_colunas += yyleng;}



true|false				{if(flag==0){printf("BOOLLIT(%s)\n",yytext);}num_colunas+= yyleng; yylval.id=(id_lin_col*) malloc(sizeof(id_lin_col)); yylval.id->id=strdup(yytext); yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id);  return BOOLLIT;}
"&&" 					{if(flag==0){printf("AND\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return AND;}
"=" 					{if(flag==0){printf("ASSIGN\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return ASSIGN;}
"*" 					{if(flag==0){printf("STAR\n");}num_colunas+= yyleng;  yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return STAR;}
"," 					{if(flag==0){printf("COMMA\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return COMMA;}
"/" 					{if(flag==0){printf("DIV\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return DIV;}
"=="					{if(flag==0){printf("EQ\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return EQ;}
">=" 					{if(flag==0){printf("GE\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return GE;}
">" 					{if(flag==0){printf("GT\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return GT;}
"{" 					{if(flag==0){printf("LBRACE\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return LBRACE;}
"<=" 					{if(flag==0){printf("LE\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return LE;}
"(" 					{if(flag==0){printf("LPAR\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return LPAR;}	
")" 					{if(flag==0){printf("RPAR\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return RPAR;}
"["						{if(flag==0){printf("LSQ\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return LSQ;}
"<" 					{if(flag==0){printf("LT\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return LT;}
"-" 					{if(flag==0){printf("MINUS\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return MINUS;}
"%" 					{if(flag==0){printf("MOD\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return MOD;}
"!=" 					{if(flag==0){printf("NE\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return NE;}
"!" 					{if(flag==0){printf("NOT\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return NOT;}
"||" 					{if(flag==0){printf("OR\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return OR;}
"+" 					{if(flag==0){printf("PLUS\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return PLUS;}
"}" 					{if(flag==0){printf("RBRACE\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return RBRACE;}
"]"     				{if(flag==0){printf("RSQ\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return RSQ;}
";" 					{if(flag==0){printf("SEMICOLON\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return SEMICOLON;}
"->"     				{if(flag==0){printf("ARROW\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return ARROW;}
"<<"     				{if(flag==0){printf("LSHIFT\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return LSHIFT;}
">>"     				{if(flag==0){printf("RSHIFT\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return RSHIFT;}
"^"     				{if(flag==0){printf("XOR\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return XOR;}
boolean					{if(flag==0){printf("BOOL\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return BOOL;}
class					{if(flag==0){printf("CLASS\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return CLASS;}
".length"				{if(flag==0){printf("DOTLENGTH\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return DOTLENGTH;}
double					{if(flag==0){printf("DOUBLE\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return DOUBLE;}
else 					{if(flag==0){printf("ELSE\n");}num_colunas+= yyleng;yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id);  return ELSE;}
if 						{if(flag==0){printf("IF\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return IF;}
int 					{if(flag==0){printf("INT\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return INT;}
"System.out.print" 		{if(flag==0){printf("PRINT\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return PRINT;}
"Integer.parseInt" 		{if(flag==0){printf("PARSEINT\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return PARSEINT;} 
public					{if(flag==0){printf("PUBLIC\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return PUBLIC;}
return 					{if(flag==0){printf("RETURN\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return RETURN;}
static					{if(flag==0){printf("STATIC\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return STATIC;}
String					{if(flag==0){printf("STRING\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return STRING;}
void					{if(flag==0){printf("VOID\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return VOID;} 
while					{if(flag==0){printf("WHILE\n");}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return WHILE;}


{reserved}				{if(flag==0){printf("RESERVED(%s)\n",yytext);}num_colunas+= yyleng; yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return RESERVED;}


{letras}{alfanum}*		{if(flag==0){printf("ID(%s)\n",yytext);}num_colunas+= yyleng; yylval.id=(id_lin_col*) malloc(sizeof(id_lin_col)); yylval.id->id=strdup(yytext); yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id);  return ID;}
{reallit}				{if(flag==0){printf("REALLIT(%s)\n",yytext);}num_colunas+= yyleng; yylval.id=(id_lin_col*) malloc(sizeof(id_lin_col)); yylval.id->id=strdup(yytext); yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return REALLIT;}
{intlit}				{if(flag==0){printf("INTLIT(%s)\n",yytext);}num_colunas+= yyleng; yylval.id=(id_lin_col*) malloc(sizeof(id_lin_col)); yylval.id->id=strdup(yytext); yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id); return INTLIT;}


{space}					{num_colunas += yyleng;}
{lineTerminator}		{num_colunas = 1;num_linhas++; }

.	 					{printf("Line %d, col %d: illegal character (%s)\n",num_linhas,num_colunas,yytext);num_colunas+= yyleng;  return yytext[0];  }

%%


int main(int argc, char *argv[]){
	if(argc == 2){
		if(strcmp(argv[1],"-l") == 0){
			flag = 0;
			while(yylex()){}
		}else if(strcmp(argv[1],"-e1") == 0){
			flag = 1;
			while(yylex()){}
		}else if(strcmp(argv[1],"-e2") == 0){
			flag = 1;
			yyparse();
			free_tree(myprogram);
			
		}else if(strcmp(argv[1],"-t") == 0){

			flag = 1;
			yyparse();
			if(erro_sintaxe == 0){
				print_tree(myprogram);
			}
		}else if(strcmp(argv[1],"-s") == 0){
			int errors;

			flag = 1;
		    yyparse();

			if(erro_sintaxe == 0){

		    	errors=check_program(myprogram);

			    if(errors>0){
			        printf("The program has %d errors!\n", errors);
			    }else{
			    	show_table();
			    	print_tree(myprogram);
			    }
			}

		free_tree(myprogram);


		}
	}else if(argc == 1){
		int errors;
		flag = 1;
		yyparse();
		
		if(erro_sintaxe == 0){

	   		errors=check_program(myprogram);

		}

		free_tree(myprogram);




		}
	return 0;
}

int yywrap()
{
	yylval.id=(id_lin_col*)malloc(sizeof(id_lin_col)); yylval.id->id=yytext; yylval.id->linha = num_linhas; yylval.id->coluna = num_colunas - (int) strlen(yylval.id->id);

return 1;
}



