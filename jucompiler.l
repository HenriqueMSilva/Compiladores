%%
";" 					{printf("SEMICOLON\n");}
"package"				{printf("PACKAGE\n");}
"return" 				{printf("RETURN\n");}
"&&" 					{printf("AND\n");}
"_"						{printf("BLANKID\n");}
"=" 					{printf("ASSIGN\n");}
"*" 					{printf("STAR\n");}
"," 					{printf("COMMA\n");}
"/" 					{printf("DIV\n");}
"=="					{printf("EQ\n");}
">=" 					{printf("GE\n");}
">" 					{printf("GT\n");}
"{" 					{printf("LBRACE\n");}
"<=" 					{printf("LE\n");}
"'" 					{printf("LPAR\n");}
"["						{printf("LSQ\n");}
"<" 					{printf("LT\n");}
"-" 					{printf("MINUS\n");}
"%" 					{printf("MOD\n");}
"!=" 					{printf("NE\n");}
"!" 					{printf("NOT\n");}
"||" 					{printf("OR\n");}
"+" 					{printf("PLUS\n");};
"}" 					{printf("RBRACE\n");}
"("   					{printf("LPAR\n");}
")" 					{printf("RPAR\n");}
"]"     				{printf("RSQ\n");}
else 					{printf("ELSE\n");}
for 					{printf("FOR\n");}
if 						{printf("IF\n");}
var 					{printf("VAR\n");}
int 					{printf("INT\n");}
float32 				{printf("FLOAT32\n");}
bool 					{printf("BOOL\n");};
string 					{printf("STRING\n");}
fmt.Println 			{printf("PRINT\n");}
strconv.Atoi 			{printf("PARSEINT\n");}
func 					{printf("FUNC\n");}
os.Args 				{printf("CMDARGS\n");}
"--" 					{printf("RESERVED(%s)\n", yytext);}
"++" 					{printf("RESERVED(%s)\n", yytext);}
. {;} \
%%
int main()
{
yylex();
return 0;
}

int yywrap()
{
return 1;
}
