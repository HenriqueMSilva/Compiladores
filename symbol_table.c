#include "symbol_table.h"
#include "structures.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

extern 	header_global 	*symtab_global;
extern	table_element_local 	*symtab_local;

/*char * recursao_expr(is_expression_list* expr){

	//se for ID verificar se ja foi declarado
	if( strcmp(expr->operation, "Id" ) == 0 ){

	}


	//se for realint intlot ou bool-> return
	//se for expr-> fazer a logica

}*/
int assinatutas_iguais(table_element_global *newSymbol, table_element_global *aux){

	param_node * param_newSymbol = newSymbol->param_list;
	param_node * param_aux = aux->param_list;

	//testo o return
	if( strcmp(newSymbol->type_return, aux->type_return) != 0 ){
		//metodos diferente
		return 0;
	}

	while(param_newSymbol != NULL && param_aux != NULL){


		//testo os parametros de entrada
		if( strcmp(param_newSymbol->type_param, param_aux->type_param) != 0){
			//parametro diff
			return 0;
		}



		param_newSymbol = param_newSymbol->next;
		param_aux = param_aux->next;
	
	}


	//todos os param era iguais-> assinatura igual
	if(param_newSymbol == NULL && param_aux == NULL){
		return 1;
	}

	return 0;

}


void tenta_inserir_fieldDec_na_tail_global(table_element_global * newSymbol){
	table_element_global *aux;
	table_element_global* previous;

	//Vou inserir o node na Tabela de Simbolos Global
	if(symtab_global->declarations != NULL){	//Se table ja tem elementos
		
		//Procura cauda da lista e verifica se simbolo ja existe
		for(aux = symtab_global->declarations; aux != NULL ; previous = aux, aux = aux->next){


			if(strcmp(aux->name, newSymbol->name) == 0 && aux->type_return == NULL ){
				//encontramos um field dec declarado aj com este nome
				printf("\nTODO FD: Symbol %s already defined\n",aux->name);
				//TODO-controlo se ja foi declarado
				return;
			}
		}
		
		previous->next = newSymbol;	//adiciona ao final da lista
	}else{
		symtab_global->declarations = newSymbol;	
	}

}


void tenta_inserir_metodo_na_tail_global(table_element_global * newSymbol){
	table_element_global *aux;
	table_element_global* previous;

	//Vou inserir o node na Tabela de Simbolos Global
	if(symtab_global->declarations != NULL){	//Se table ja tem elementos
		
		//Procura cauda da lista e verifica se simbolo ja existe 
		for(aux = symtab_global->declarations; aux != NULL ; previous = aux, aux = aux->next){
			if(strcmp(aux->name, newSymbol->name) == 0 && aux->type_return != NULL && assinatutas_iguais(newSymbol, aux) == 1){

				printf("\nTODO M: Symbol %s already defined\n",aux->name);

				//TODO-controlo se ja foi declarado
				return;
			}
		}
		
		previous->next = newSymbol;	//adiciona ao final da lista
	}else{
		symtab_global->declarations = newSymbol;	
	}

}


void tenta_inserir_na_tail_local(table_element_local * new_method){
	table_element_local* aux;
	table_element_local* previous;


	//Vou inserir o node na Tabela de Simbolos Local
	if(symtab_local != NULL){	//Se table ja tem elementos
		
		//Procura cauda da lista e verifica se simbolo ja existe (NOTA: assume-se uma tabela de simbolos local)
		for(aux = symtab_local; aux != NULL ; previous = aux, aux = aux->next){
			if(strcmp(aux->name, new_method->name) == 0){
				//TODO-controlo se ja foi declarado
				return;
			}
		}
		
		previous->next = new_method;	//adiciona ao final da lista
	}else{
		symtab_local = new_method;	
	}

}


char * lowerCase(char * str){
	int i;
	for(i=0; i <= strlen(str); i++){
		if(str[i] >= 65 && str[i] <= 90)
        	str[i] = str[i] + 32;
   }

   return str;
}






header_global* insert_classname(char *str){

	header_global *stg=(header_global*) malloc(sizeof(header_global));

	stg->name = (char*)strdup(str);
	stg->declarations = NULL;

	symtab_global = stg;

	return stg;

}



table_element_local *insert_el_metodo_local(is_methodheader_list* imhl, is_methodbody_list* imbl){
	char * tipo;

	method_var *simb_last_param;
	method_var *var_metodo;

	is_methodparams_list* ast_param_list = imhl->impl;


	table_element_local * new_method = (table_element_local*) malloc(sizeof(table_element_local));

	new_method->name = (char*)strdup(imhl->name);
	new_method->tel = (method_var*) malloc(sizeof(method_var));
	new_method->next = NULL;

	var_metodo = new_method->tel;

	//primeira var e o return
	var_metodo->name = (char*)strdup("return");
	var_metodo->type = (char*)strdup(imhl->type);
	var_metodo->is_param = 0;
	var_metodo->next = NULL;

	simb_last_param = var_metodo;


	//parametros de entrada
	while(ast_param_list != NULL){

		var_metodo = (method_var*) malloc(sizeof(method_var));

		var_metodo->name = (char*)strdup(ast_param_list->name);
		var_metodo->type = (char*)strdup(ast_param_list->type);
		var_metodo->is_param = 1;
		var_metodo->next = NULL;

		simb_last_param->next = var_metodo;
		simb_last_param = var_metodo;  
		
		//avançamos para o proximo parametro da AST
		ast_param_list = ast_param_list->next;
	}

	//adicionar isto ha lista TODO
	//verifica se ja ha um metodo com este nome
	tenta_inserir_na_tail_local(new_method);

	//se o method body
	if(imbl != NULL){
		is_vardecl_list* ast_var_dec_list = imbl->ivdl;
		is_methodbody_list* ast_var_dec_or_statment = imbl;


		//percorrer o body entre statments e var decs
		while(ast_var_dec_or_statment != NULL && ( ast_var_dec_or_statment->ivdl != NULL || ast_var_dec_or_statment->statment != NULL) ){
		//while(ast_var_dec_or_statment != NULL ){  ACHO QUE O WHILE PODIA SER SO ISTO

			//e um statment e nao um var dec
			//Statmente

			if(ast_var_dec_or_statment->statment != NULL){
				
				//percorrer as expr
				//is_expression_list* expr = ast_var_dec_or_statment->statment->expr;
				//recursao_expr(expr);

				//ir para statmet1
				//ir para statmet2
		

				ast_var_dec_or_statment = ast_var_dec_or_statment->next;

			//VarDec
			}else{


				ast_var_dec_list = ast_var_dec_or_statment->ivdl;

				//var decs que foram defenidas numa so linha
				if(ast_var_dec_list != NULL){
					tipo = ast_var_dec_list->type;
				}

				while(ast_var_dec_list != NULL){
				

					var_metodo = (method_var*) malloc(sizeof(method_var));

					var_metodo->name = (char*)strdup(ast_var_dec_list->name);
					var_metodo->type = (char*)strdup(tipo);
					var_metodo->is_param = 0;
					var_metodo->next = NULL;

					simb_last_param->next = var_metodo;
					simb_last_param = var_metodo;  
					

					ast_var_dec_list = ast_var_dec_list->next;


				}

				ast_var_dec_or_statment = ast_var_dec_or_statment->next;


			}
			


		}
	}





	return new_method;
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

		tenta_inserir_fieldDec_na_tail_global(newSymbol);


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


		tenta_inserir_fieldDec_na_tail_global(newSymbol);


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


	tenta_inserir_metodo_na_tail_global(newSymbol);
	
	return newSymbol; 

}



void show_tabela_global(){
	char * str;
	header_global *aux = symtab_global;

	//ficheiro vazio
	if(aux == NULL){
		return;
	}

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

				if( strcmp(str,"bool") == 0 ){
					str = "boolean";
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

			str = lowerCase(aux->declarations->param_list->type_param);

			if( strcmp(str,"bool") == 0 ){
				str = "boolean";
			}

			printf("\t\t%s\n", str );



		}

		
		aux->declarations = aux->declarations->next;
	}

	//ATENTION..............................................nao sei se e preciso TODO
	printf("\n");
}



//reformular os prints dos field dec
void show_tabela_local(){
	char * str;
	table_element_local *tabela_local = symtab_local;
	method_var* variavel;

	while(tabela_local != NULL){
		str = tabela_local->name; 


		printf("===== Method %s(",str);

		
		variavel = tabela_local->tel;
		
		while(variavel != NULL){
			//tudo o que nao for parametro de entrada nao nos interessa
			if(variavel->is_param == 0){
				variavel = variavel->next;
				continue;
			}


			//so quero imprimir os parametros de entrada
			str = lowerCase(variavel->type);



			if( strcmp(str,"stringarray") == 0 ){
				str = "String[]";
			}

			if( strcmp(str,"bool") == 0 ){
				str = "boolean";
			}
	

			printf("%s", str);
		
			if(variavel->next != NULL && variavel->next->is_param == 1){
				printf(",");
			}

			variavel = variavel->next;
		}
		printf(") Symbol Table =====\n");



		variavel = tabela_local->tel;

		while(variavel != NULL){

			str = lowerCase(variavel->type);

			if( strcmp(str,"stringarray") == 0 ){
				str = "String[]";
			}

			if( strcmp(str,"bool") == 0 ){
				str = "boolean";
			}

			printf("%s\t\t%s", variavel->name, str );
		
			if(variavel->is_param == 1){
				printf("\tparam" );
			}
			printf("\n");

			variavel = variavel->next;
		}

		
		tabela_local = tabela_local->next;
		printf("\n");
	}



}


void show_table(){

	show_tabela_global();
	show_tabela_local();

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





