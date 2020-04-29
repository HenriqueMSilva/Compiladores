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

	return stg;

}

/*table_element_local *insert_el_local(char *str){

	table_element_local *newSymbol =(table_element_local*) malloc(sizeof(table_element_local));
	table_element_local *aux;
	table_element_local* previous;


}*/

void tenta_inserir_na_tail_global(	table_element_global * newSymbol){
	table_element_global *aux;
	table_element_global* previous;

	//Vou inserir o node na Tabela de Simbolos Global
	if(symtab_global->declarations != NULL){	//Se table ja tem elementos
		
		//Procura cauda da lista e verifica se simbolo ja existe (NOTA: assume-se uma tabela de simbolos globais!)
		for(aux = symtab_global->declarations; aux != NULL ; previous = aux, aux = aux->next){
			if(strcmp(aux->name, newSymbol->name) == 0){
				//TODO-controlo se ja foi declarado
				return;
			}
		}
		
		previous->next = newSymbol;	//adiciona ao final da lista
	}else{
		symtab_global->declarations = newSymbol;	
	}

}


//Insere um novo(s) elemtentos na global devido a FieldDeclaration             
table_element_global * insert_el_fieldDec_global(is_fielddecl_list* ifdl, char * var_type){
		
	table_element_global *newSymbol;

	table_element_global* para_dar_return;

	//temos um filddec
	if(ifdl != NULL){

		newSymbol = (table_element_global*) malloc(sizeof(table_element_global));

		para_dar_return = newSymbol;


		newSymbol->name = (char*)strdup(ifdl->name);
		newSymbol->param_list = (param_node*) malloc(sizeof(param_node));
		newSymbol->type_return = NULL;
		newSymbol->next = NULL;


		newSymbol->param_list->type_param = (char*)strdup(var_type);
		newSymbol->param_list->next = NULL;

		tenta_inserir_na_tail_global(newSymbol);


	}

	ifdl = ifdl->next;

	//ainda temos mais variaveis do tipo ifdl->type?
	while(ifdl != NULL){

		newSymbol = (table_element_global*) malloc(sizeof(table_element_global));

		newSymbol->name = (char*)strdup(ifdl->name);
		newSymbol->param_list = (param_node*) malloc(sizeof(param_node));
		newSymbol->type_return = NULL;
		newSymbol->next = NULL;


		newSymbol->param_list->type_param = (char*)strdup(var_type);
		newSymbol->param_list->next = NULL;


		tenta_inserir_na_tail_global(newSymbol);


		ifdl = ifdl->next;
	}



	return para_dar_return;

}





//Insere um novo elemtento na global devido a Metodo
table_element_global *insert_el_metodo_global(is_methodheader_list* imhl){


	table_element_global *newSymbol;


	//VARIAVEIS PARA AJUDAR A INSERIR NA TABELA OS PARAMETROS DO METEDO
	is_methodparams_list* ast_param_list = imhl->impl;
	param_node *simb_input_param;
	param_node *simb_last_param;

	
	newSymbol = (table_element_global*) malloc(sizeof(table_element_global));

	newSymbol->name = (char*)strdup(imhl->name);
	newSymbol->type_return= (char*)strdup(imhl->type);
	newSymbol->param_list = NULL;
	newSymbol->next = NULL;



	//INSERIR OS PARAMETROS NA LISTA DE PARAMETROS DO METODO
	//EXISTE 1 PARAMETRO?
	if(ast_param_list != NULL){

		simb_input_param = (param_node*) malloc(sizeof(param_node));
		simb_input_param->type_param = (char*)strdup(ast_param_list->type);
		simb_input_param->next = NULL;
		
		newSymbol->param_list = simb_input_param;

		//ponteiro para o ultimo elemento da lista de parametros do metodo na tabela de simbolos
		simb_last_param = simb_input_param;
		
		//avançamos para o proximo parametro da AST
		ast_param_list = ast_param_list->next;
	}

	//EXISTEM 2 PARAMETROS?
	while(ast_param_list != NULL){


		simb_input_param = (param_node*) malloc(sizeof(param_node));
		simb_input_param->type_param = (char*)strdup(ast_param_list->type);
		simb_input_param->next = NULL;

		//adiciona o elem a lista
		simb_last_param->next = simb_input_param; 

		//atualizamos o ponteiro para o ultimo elemento da lista
		simb_last_param = simb_input_param;
		
		//avançamos para o proximo parametro da AST
		ast_param_list = ast_param_list->next;
	}


	tenta_inserir_na_tail_global(newSymbol);
	
	return newSymbol; 

}

char * lowerCase(char * str){
	int i;
	for(i=0; i <= strlen(str); i++){
		if(str[i] >= 65 && str[i] <= 90)
        	str[i] = str[i] + 32;
   }

   return str;
}

//reformular os prints dos field dec
void show_tabela_global(){
	char * str;
	header_global *aux = symtab_global;
	printf("===== Class %s Symbol Table =====\n", aux->name);
	while(aux->declarations != NULL){
		
		//METODO
		if(aux->declarations->type_return != NULL){
	
			printf("%s", aux->declarations->name);

			printf("\t(");

			//parametros de entrada
			while(aux->declarations->param_list != NULL){
				str = lowerCase(aux->declarations->param_list->type_param);

				if( strcmp(str,"stringarray") == 0 ){
					str = "String[]";
				}


				printf("%s", str );
				aux->declarations->param_list = aux->declarations->param_list->next;

				if(aux->declarations->param_list != NULL){
					printf(",");
				}
			
			
	
			}
			printf(")\t");
			printf("%s\n", lowerCase(aux->declarations->type_return) );


		}else{
		//FieldDec
		
			printf("%s", aux->declarations->name);
			printf("\t%s\n", lowerCase(aux->declarations->param_list->type_param) );



		}

		
		aux->declarations = aux->declarations->next;
	}

	//ATENTION..............................................nao sei se e preciso TODO
	printf("\n");
}

void show_table(){

	show_tabela_global();

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





