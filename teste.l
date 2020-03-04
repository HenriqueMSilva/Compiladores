valid_escape			\f|\r|"\t"|\\{2}|\\"


%X ASPAS

%%

\"								{BEGIN ASPAS;printf("dentro");}
{valid_escape}					{printf("Valid\n");}


%%

int main(int argc, char *argv[]){
	
	while(yylex()){}	
	return 0;
}

int yywrap()
{
return 1;
}


\"									{BEGIN ASPAS;strcpy(strlit, "");error_sequence=0;linha_erro = num_linhas; coluna_erro = num_colunas; num_colunas += yyleng;}
<ASPAS>{valid_escape}				{if(error_sequence== 0){strcat(strlit, yytext);}num_colunas += yyleng;}
<ASPAS>{lineTerminator} 			{BEGIN 0; printf("Line %d, col %d: unterminated string literal\n", linha_erro, coluna_erro);num_colunas = 1;num_linhas++;}
<ASPAS>\"							{BEGIN 0; if(flag == 0 && error_sequence== 0){printf("STRLIT(\"%s\")\n",strlit);}num_colunas += yyleng;}
<ASPAS><<EOF>> 						{BEGIN 0; printf("Line %d, col %d: unterminated string literal\n", linha_erro, coluna_erro);}
<ASPAS>\\{invalid_escape}			{error_sequence = 1; printf("Line %d, col %d: invalid escape sequence (%s)\n", num_linhas, num_colunas, yytext);num_colunas += yyleng;}							
<ASPAS>.							{if(error_sequence == 0){strcat(strlit, yytext);}num_colunas += yyleng;}
