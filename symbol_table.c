#include "symbol_table.h"
#include "structures.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

extern 	header_global 	*symtab_global;
extern	header_local 	*symtab_local;

header_global* insert_classname(char *str){

	header_global *stg=(header_global*) malloc(sizeof(header_global));

	stg->name = (char*)strdup(str);
	stg->declarations = NULL;

	symtab_global = stg;
	
}


//Insere um novo identificador na cauda de uma lista ligada de simbolo
table_element_global *insert_el(char *str, char *type,  is_methodparams_list* imdl, char *declaration){

	table_element_global *newSymbol =(table_element_global*) malloc(sizeof(table_element_global));
	table_element_global *aux;
	table_element_global* previous;
	
	//VARIAVEIS PARA AJUDAR A INSERIR NA TABELA OS PARAMETROS DO METEDO
	is_methodparams_list* auxparam = imdl;
	param_list *paramlist;
	param_list *auxparamlist; 

	//SE FOR UMA VARIAVEL O PARAMETRO LIST VAI SER NULL
	if(strcmp(declaration,"FieldDeclaration") == 0){

		newSymbol->name = (char*)strdup(str);
		newSymbol->type_return= (char*)strdup(type);
		newSymbol->param_list_type = NULL;

	//CASO SEJA METHOD PODE OU NAO SER VAZIO
	}else if(strcmp(declaration,"MethodDeclaration") == 0){

		newSymbol->name = (char*)strdup(str);
		newSymbol->type_return= (char*)strdup(type);
		newSymbol->param_list_type = NULL;

		//INSERIR OS PARAMETROS NA LISTA DE PARAMETROS DO METODO
		//EXISTE 1 PARAMETRO?
		if(auxparam != NULL){
			paramlist =(param_list*) malloc(sizeof(param_list));

			paramlist->type_param = (char*)strdup(auxparam->type);
			paramlist->next = NULL;
			
			newSymbol->param_list_type = paramlist;

			auxparamlist = paramlist;
			
			auxparam = auxparam->next;
		}
		//EXISTEM 2 PARAMETROS?
		while(auxparam != NULL){
			paramlist =(param_list*) malloc(sizeof(param_list));

			paramlist->type_param = (char*)strdup(auxparam->type);
			paramlist->next = NULL;
			
			auxparamlist->next = paramlist;
			auxparamlist = paramlist;

			auxparam = auxparam->next;
		}

	}
	newSymbol->next=NULL;

	if(symtab_global->declarations != NULL){	//Se table ja tem elementos
		//Procura cauda da lista e verifica se simbolo ja existe (NOTA: assume-se uma tabela de simbolos globais!)
		for(aux=symtab_global->declarations; aux; previous=aux, aux=aux->next){
			if(strcmp(aux->name, str)==0){
				return NULL;
			}
		}
		
		previous->next=newSymbol;	//adiciona ao final da lista
	}
	else	//symtab_global tem um elemento -> o novo simbolo
		symtab_global->declarations = newSymbol;		
	
	return newSymbol; 
}

char * lowerCase(char * str){
	for(int i=0; i<=strlen(str); i++){
		if(str[i]>=65&&str[i]<=90)
         str[i]=str[i]+32;
   }

   return str;
}

void show_table(){

	char * str;
	header_global *aux = symtab_global;
	printf("===== Class %s Symbol Table =====\n", aux->name);
	while(aux->declarations != NULL){
		
			
		printf("%s", aux->declarations->name);
		printf("\t(");

		//parametros de entrada
		while(aux->declarations->param_list_type != NULL){
			str = lowerCase(aux->declarations->param_list_type->type_param);

			if( strcmp(str,"stringarray") == 0 ){
				str = "String[]";
			}


			printf("%s", str );
			aux->declarations->param_list_type = aux->declarations->param_list_type->next;

			if(aux->declarations->param_list_type != NULL){
				printf(",");
			}
		
			
	
		}
		printf(")\t");
		printf("%s\n", lowerCase(aux->declarations->type_return) );

		aux->declarations = aux->declarations->next;
	}
	//ATENTION..............................................nao sei se e preciso TODO
	printf("\n");

}

//Procura um identificador, devolve 0 caso nao exista
/*table_element *search_el(char *str)
{
table_element *aux;

for(aux=symtab_global; aux; aux=aux->next)
	if(strcmp(aux->name, str)==0)
		return aux;

return NULL;
}*/





