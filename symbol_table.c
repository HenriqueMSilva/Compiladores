#include "symbol_table.h"
#include "structures.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

extern 	header_global 	*symtab_global;
extern	table_element_local 	*symtab_local;

char * recursao_expr(is_expression_list* expr, method_var* lista_do_metodo ){
	char * tipo;
	char * str1;
	char * str2;
	char * operador;

	//se for ID verificar se ja foi declarado
	if( strcmp(expr->operation, "Id" ) == 0 ){
	
		//averiguar se a var foi declarado no metodo //serve para saber o tipo da var
		tipo =  var_declarada(lista_do_metodo, expr->value);

		if( tipo != NULL ){
			//estava declarada
			expr->tipo = tipo;
			return expr->tipo;
		}


		//averiguar se a var foi declarado globalmente
		tipo =  var_declarada_globalmente(expr->value);

		if( tipo != NULL ){
			//estava declarada
			expr->tipo = tipo;
			return expr->tipo;
		}
	}


	//se for realint intlot ou bool-> return
	if(strcmp(expr->operation, "RealLit" ) == 0 ){
		expr->tipo = "double";
		return expr->tipo; 
	}

	if(strcmp(expr->operation, "BoolLit" ) == 0 ){
		expr->tipo = "bool";
		return expr->tipo; 
	}

	if(strcmp(expr->operation, "DecLit" ) == 0){ 
		expr->tipo = "int"; 
		return expr->tipo;
	}

	if(strcmp(expr->operation, "StrLit" ) == 0){ 
		expr->tipo = "String"; 
		return expr->tipo;
	}



	//TODO estes do comentarios + prints da tabela ast
	if(expr->expr1 != NULL ){
		recursao_expr(expr->expr1, lista_do_metodo);
	}

	if(expr->expr2 != NULL ){
		recursao_expr(expr->expr2, lista_do_metodo);
	}




	//mesmo raciocionio do call e dos operadores, so tratamos disto depois dos filhos

	//vai atribuir o tipo ao ID que esta associado a estes statment, no print depois resolve-se o tipo
	if(strcmp(expr->operation, "Length" ) == 0 || strcmp(expr->operation, "ParseArgs" ) == 0){ 
		
		tipo =  var_declarada(lista_do_metodo, expr->value);

		if( tipo != NULL){
			

			if(strcmp( lowerCase(tipo), "stringarray" ) == 0){
				//estava declarada
				expr->tipo = "String[]";
				return expr->tipo;
			}else{
				expr->tipo = tipo;
				return expr->tipo;
			}
		}


		//averiguar se a var foi declarado globalmente
		tipo =  var_declarada_globalmente(expr->value);

		if( tipo != NULL){
			if(strcmp(lowerCase(tipo), "stringarray" ) == 0){
				//estava declarada
				expr->tipo = "String[]";
				return expr->tipo;
			}else{
				expr->tipo = tipo;
				return expr->tipo;
			}
		}
	}



	if( strcmp(expr->operation, "Assign" ) == 0 ){
	
		//averiguar se a var foi declarado no metodo //serve para saber o tipo da var
		tipo =  var_declarada(lista_do_metodo, expr->value);

		if( tipo != NULL ){


			//TODO A logica nao esta correta, eu estava a fazer debug
			/*if(strcmp( lowerCase(tipo) ,expr->expr1->tipo) != 0){
				printf("Line %d, col %d: Operator = cannot be applied to types %s, %s\n",expr->linha,expr->coluna, lowerCase(tipo), expr->expr1->tipo);
			}*/

			//estava declarada
			expr->tipo = tipo;
			return expr->tipo;
		}


		//averiguar se a var foi declarado globalmente
		tipo =  var_declarada_globalmente(expr->value);

		if( tipo != NULL ){
			//estava declarada
			expr->tipo = tipo;
			return expr->tipo;
		}
	}


	if(strcmp(expr->operation, "CallMore" ) == 0){

		return expr->tipo;


	}

	if(strcmp(expr->operation, "Call" ) == 0){

	
		//averiguar se o metodo foi declarado globalmente
		tipo = type_call_verification(expr,lista_do_metodo);
		
		if( tipo != NULL ){
			//estava declarada
			expr->tipo = tipo;

			if(strcmp(tipo, "undef" ) == 0){

			}
			return expr->tipo;
		}

	}



if(strcmp(expr->operation, "Operacao" ) == 0){

		//FOi preciso fazer estes ifs porque se nao dava run time error ao passar os tipos para minusculo
		if(expr->expr1 != NULL){
			if(strcmp(expr->expr1->tipo,"Int") == 0 ){
				str1 = "int";
			}else if(strcmp(expr->expr1->tipo,"Double") == 0 ){
				str1 = "double";
			}else if(strcmp(expr->expr1->tipo,"Bool") == 0 ){
				str1 = "bool";
			}else{
				str1 = expr->expr1->tipo;
			}
		}
		if(expr->expr2 != NULL){
			if(strcmp(expr->expr2->tipo,"Int") == 0 ){
				str2 = "int";
			}else if(strcmp(expr->expr2->tipo,"Double") == 0 ){
				str2 = "double";
			}else if(strcmp(expr->expr2->tipo,"Bool") == 0 ){
				str2 = "bool";
			}else{
				str2 = expr->expr2->tipo;
			}

		}


		if((strcmp(expr->value,"Add") == 0 || strcmp(expr->value,"Sub") == 0 || strcmp(expr->value,"Mul") == 0 || strcmp(expr->value,"Div") == 0 || strcmp(expr->value,"Mod") == 0)){

			if(strcmp(str1,"bool") == 0 || strcmp(str2,"bool") == 0 || strcmp(str1,"undef") == 0 || strcmp(str2,"undef") == 0){

				//verifica operador a dar print
				operador = retorna_operador(expr->value);

				if(strcmp(str1,"bool") == 0){
					str1 = "boolean";
				}
				if(strcmp(str2,"bool") == 0){
					str2 = "boolean";
				}

				printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",expr->linha,expr->coluna,operador,str1,str2);

				expr->tipo = "undef";
				return expr->tipo;

			}else if(strcmp(str1,"int")  == 0  && strcmp(str2,"double") == 0){
				expr->tipo = "double";
				return expr->tipo;
			}else if(strcmp(str1,"double")  == 0 && strcmp(str2,"int") == 0){
				expr->tipo = "double";
				return expr->tipo;
			}else{
				//double double ou int int
				expr->tipo = str1; 
				return expr->tipo;
			}

		}else if((strcmp(expr->value,"Minus") == 0 || strcmp(expr->value,"Plus") == 0)){

			if(strcmp(str1,"bool") == 0  || strcmp(str1,"undef") == 0 ){

				operador = retorna_operador(expr->value);

				printf("Line %d, col %d: Operator %s cannot be applied to type %s",expr->linha,expr->coluna,operador,str1);

				expr->tipo = "undef"; 
				return expr->tipo;			
			}else{
				expr->tipo = str1; 
				return expr->tipo;
			}

		}else if(strcmp(expr->value,"Not") == 0){

				if(strcmp(str1,"bool") != 0){
					printf("Line %d, col %d: Operator ! cannot be applied to type %s",expr->linha,expr->coluna,str1);
				}
				expr->tipo = "bool"; 
				return expr->tipo;


		}else if((strcmp(expr->value,"Eq") == 0 || strcmp(expr->value,"Ge") == 0 || strcmp(expr->value,"Gt") == 0 || strcmp(expr->value,"Le") == 0 || strcmp(expr->value,"Lt") == 0 || strcmp(expr->value,"Ne") == 0 || strcmp(expr->value,"And") == 0 || strcmp(expr->value,"Or") == 0 ||  strcmp(expr->value,"Xor") == 0)){
			

			if( (( (strcmp(str1,"int") != 0 && strcmp(str1,"double") != 0) || (strcmp(str1,"int") != 0 && strcmp(str1,"double") != 0) ) && strcmp(str2,str1) != 0) || strcmp(str1,"undef") == 0 || strcmp(str2,"undef") == 0){
				printf("Line %d, col %d: Operator == cannot be applied to types %s, %s\n",expr->linha,expr->coluna,str1,str2);
			}

			expr->tipo = "bool";
			return expr->tipo;
/*			
			if( strcmp(str1,"undef") == 0 || strcmp(str2,"undef") == 0){
				expr->tipo = "undef";
				return expr->tipo;

			}else if(strcmp(str1,str2) == 0){
				// bool bool ou int int ou double double
				expr->tipo = "bool";
				return expr->tipo;
			
			}else if(strcmp(str1,"int")  == 0  && strcmp(str2,"double") == 0){
				expr->tipo = "bool";
				return expr->tipo;
			}else if(strcmp(str1,"double")  == 0 && strcmp(str2,"int") == 0){
				expr->tipo = "bool";
				return expr->tipo;
			}*/
		}
	}


	expr->tipo = "undef";
	return "undef"; 


}

char * retorna_operador (char * value){
	char * operador;
	if(strcmp(value,"Add") == 0 || strcmp(value,"Plus") == 0){
		operador = "+";
	}else if(strcmp(value,"Sub") == 0 || strcmp(value,"Minus") == 0){
		operador = "-";
	}else if(strcmp(value,"Mul") == 0){
		operador = "*";
	}else if(strcmp(value,"Div") == 0){
		operador = "/";
	}else if(strcmp(value,"Mod") == 0){
		operador = "%";
	}

	return operador;
}

void recursao_statment(is_statment_list* statment, table_element_local * new_method ){
		int error_declaration;

		//percorrer as expr	
		if( statment->expr != NULL){
			recursao_expr(statment->expr, new_method->tel);
		}


		if(strcmp(statment->name_function, "Print" ) == 0){

			if(strcmp(statment->expr->tipo,"undef") == 0 ){
				printf("Line %d, col %d: Incompatible type undef in System.out.print statement\n",statment->expr->linha,statment->expr->coluna);
			}
			

		}else if(strcmp(statment->name_function, "Return" ) == 0){

			//verificar return do metodo
			error_declaration = assinatura_return_iguais(statment->expr,new_method);
			if( error_declaration == 0 ){
				printf("Line %d, col %d: Incompatible type %s in return statement\n",statment->expr->linha,statment->expr->coluna,statment->expr->tipo);
			}
		}


		//ir para statmet1
		if(statment->statment1 != NULL ){
			recursao_statment(statment->statment1, new_method );
		}

		//ir para statmet2
		if(statment->statment2 != NULL ){
			recursao_statment(statment->statment2, new_method );
		}


}



//ACHO QUE SO BASTA FAZER ISTO
int assinatura_return_iguais(is_expression_list* expr, table_element_local * new_method ){

	if(new_method->tel != NULL){

		//verificar o return do expr com o return do method que veio do inserir na tabela local
		if(strcmp(lowerCase(new_method->tel->type), lowerCase(expr->tipo)) == 0){
			return 1;
		}

	}

	return 0;

}



 

int metodo_retorna_tipo_param (is_expression_list* expr, method_var* lista_do_metodo,  param_node * param_list){
	//EXPR E O PRIMEIRO CALLMORE
	char *str;
	char *str2;
	int verification = 0; // 1 e true , 0 e false

	//verifica tipo do parametro
	if(expr->expr1 != NULL){
		str = lowerCase(recursao_expr(expr->expr1, lista_do_metodo));
	}
	
	str2 = lowerCase(param_list->type_param);
	


	//passa para o proximo parametro
	if(expr->expr2 != NULL && param_list->next != NULL){
		if(strcmp(str,str2) != 0 && (strcmp(str,"int") != 0 &&  strcmp(str2,"double") != 0) ){
			return 0;
		}
		verification = metodo_retorna_tipo_param(expr->expr2, lista_do_metodo, param_list->next);
	
	}else if(expr->expr2 == NULL && param_list->next == NULL){
		
		if(strcmp(str2,"bool") == 0){
			str2 = "boolean";
		}
		if(strcmp(str,"bool") == 0){
			str = "boolean";
		}
		

		if(strcmp(str,str2) == 0 ){
			expr->tipo = str;
		
			return 2;
		}else if( strcmp(str,"int") == 0 &&  strcmp(str2,"double") == 0){
			expr->tipo = str2;
	
			return 1;
		}else{
			return 0;
		}

	}else if( (expr->expr2 == NULL && param_list->next != NULL) || (expr->expr2 != NULL && param_list->next == NULL) ){

		return 0;
	}


	if(verification == 1 || verification == 2){

		if(strcmp(str2,"bool") == 0){
			str2 = "boolean";
		}
		if(strcmp(str,"bool") == 0){
			str = "boolean";
		}

		if(strcmp(str,str2) == 0 ){
			expr->tipo = str;
			if(verification == 1){

				return 1;
			}

			return 2;
		}else if( strcmp(str,"int") == 0 &&  strcmp(str2,"double") == 0){
			expr->tipo = str2;

			return 1;
		}
	}
	
	return 0;
}	




int ha_metodo_igual_declarado(is_expression_list* expr, method_var* lista_do_metodo){
	table_element_global * tabela_global = symtab_global->declarations;


	while(tabela_global != NULL){

		//ERA UM FIELD DECLARATION
		if(tabela_global->type_return == NULL){
			tabela_global = tabela_global->next;
			continue;
		}


		//printf("%s %s\n",expr->value, tabela_global->name);

		//metodo
		// mesmo nome e memos param entrada
		if( strcmp(expr->value, tabela_global->name) == 0 && assinatutas_iguais_call(expr->expr1 ,tabela_global->param_list, lista_do_metodo) == 1 ){
			return 1;
		}

		tabela_global = tabela_global->next;

	}

	return 0;
}



char*  get_metodo_igual_return_type(is_expression_list* expr, method_var* lista_do_metodo){

	table_element_global * tabela_global = symtab_global->declarations;


	while(tabela_global != NULL){

		//ERA UM FIELD DECLARATION
		if(tabela_global->type_return == NULL){
			tabela_global = tabela_global->next;
			continue;
		}


		//metodo
		// mesmo nome e memos param entrada
		if( strcmp(expr->value, tabela_global->name) == 0 && assinatutas_iguais_call(expr->expr1 ,tabela_global->param_list, lista_do_metodo) == 1 ){
			return tabela_global->type_return;
		}

		tabela_global = tabela_global->next;

	}

	//nunca deve aqui chegar
	return "ERROR";




}



int num_metodo_parecido_declarado(is_expression_list* expr, method_var* lista_do_metodo){


	table_element_global * tabela_global = symtab_global->declarations;

	int num_assinaturas_parecidas = 0;

	while(tabela_global != NULL){

		//ERA UM FIELD DECLARATION
		if(tabela_global->type_return == NULL){
			tabela_global = tabela_global->next;
			continue;
		}


		//metodo
		// mesmo nome e memos param entrada
		if( strcmp(expr->value, tabela_global->name) == 0 && assinatutas_parecidas_call(expr->expr1 ,tabela_global->param_list, lista_do_metodo) == 1 ){
			num_assinaturas_parecidas += 1;
		}

		tabela_global = tabela_global->next;

	}

	return num_assinaturas_parecidas;

}

char*  get_metodo_parecido_return_type(is_expression_list* expr, method_var* lista_do_metodo){
	table_element_global * tabela_global = symtab_global->declarations;



	while(tabela_global != NULL){

		//ERA UM FIELD DECLARATION
		if(tabela_global->type_return == NULL){
			tabela_global = tabela_global->next;
			continue;
		}


		//metodo
		// mesmo nome e memos param entrada
		if( strcmp(expr->value, tabela_global->name) == 0 && assinatutas_parecidas_call(expr->expr1 ,tabela_global->param_list, lista_do_metodo) == 1 ){
			return tabela_global->type_return;
		}

		tabela_global = tabela_global->next;

	}

	//nunca deve aqui chegar
	return "ERROR";

}


//verificar se a funcao esta declarada 
char * type_call_verification(is_expression_list* expr, method_var* lista_do_metodo){
	//table_element_global * tabela_global = symtab_global->declarations;
	//is_expression_list* expr_aux;

	//char * str = NULL;
	//int verification = 0;


//printf("qq %d q\n\n\n\n",ha_metodo_igual_declarado(expr,lista_do_metodo));

	if(ha_metodo_igual_declarado(expr,lista_do_metodo) == 1){
		//vou procurar um metodo igual

		//return "TESTE";

		return  get_metodo_igual_return_type(expr,lista_do_metodo);

	}
	//nao ha um metodo exatamente igual, vamos ver se ha algum parecido


	int num_metodos = num_metodo_parecido_declarado(expr,lista_do_metodo);

	if(  num_metodos == 1) {
		//vou procurar o 1 metodo paracido
		return get_metodo_parecido_return_type(expr,lista_do_metodo);

	}else if(num_metodos > 1){
		//ambig
		return "undef";

	}else if(num_metodos == 0){
		//nao declarado
		printf("Line %d, col %d: Cannot find symbol %s(",expr->linha,expr->coluna,expr->value);
		if(expr->expr1 != NULL){
			expr = expr->expr1;
			while(expr != NULL){
				if(expr->expr1 != NULL){
					printf("%s",lowerCase(expr->expr1->tipo));
				}
				if(expr->expr2 != NULL){
					printf(",");
				}
				expr = expr->expr2;
			}

		}
		printf(")\n");

		return "undef";
	}

	//nunca deve chagar aqui
	return "ERROR1";


/*
	while(tabela_global != NULL){

		//ERA UM FIELD DECLARATION
		if(tabela_global->type_return == NULL){
			tabela_global = tabela_global->next;
			continue;
		}

		//ERA METODO DECLARADO
		if( strcmp(expr->value,tabela_global->name) == 0  ){
			//


			//TEM PARAMETROS DE ENTRADA? NAO
			if(expr->expr1 == NULL && tabela_global->param_list == NULL){
				return tabela_global->type_return;

			//TEM PARAMAETROS DE ENTRADA
			}else{
				
				if(expr->expr1 != NULL && tabela_global->param_list != NULL ){

					verification = metodo_retorna_tipo_param(expr->expr1,lista_do_metodo,tabela_global->param_list);
					
					if(verification == 2){
						return tabela_global->type_return;
					}else if(verification == 1){
						str = tabela_global->type_return;
					}else{
						expr_aux = expr;
						while(expr_aux != NULL){
							expr_aux->tipo = NULL;
							expr_aux = expr_aux->expr2;
						}
					}
				}

			}
		}

		
		tabela_global = tabela_global->next;
	}

	return str;*/
}







char * var_declarada_globalmente(char* str){
	table_element_global * tabela_global = symtab_global->declarations;

	while(tabela_global != NULL){
		
		//sera um field dec ou um metodo?
		if(tabela_global->type_return == NULL){
		//e um field dec
			
			if(strcmp(tabela_global->name, str) == 0){
				// estava declarada
				return tabela_global->param_list->type_param;
			}

		}

		tabela_global = tabela_global->next;
	}

	return NULL;
}



char * var_declarada(method_var * lista, char* str){
	while(lista != NULL){
		if(strcmp(lista->name, str) == 0){

			
			return lista->type;
		}

		lista = lista->next;
	}

	return NULL;

}


int assinatutas_parecidas_call(is_expression_list* expr, param_node* param_list, method_var* lista_do_metodo){
	//expr e o 1 call more <=> 1 parametro chamado 
	//param_list e o 1 parametros declarado
	char * str1;
	char * str2;



	if(expr != NULL){
		//h apelo menos 1 parametro de entrada
		//vai meter tipos na ast
		recursao_expr(expr, lista_do_metodo);
	}
	


	while(expr != NULL && param_list != NULL){


		str1 = lowerCase(expr->expr1->tipo);
		str2 = lowerCase(param_list->type_param);

		//testo os parametros de entrada
		//NOT (parametros aceitaves)
		if( !(strcmp(str1, str2) == 0  || (strcmp(str1, "int") == 0 && strcmp(str2, "double") == 0 )     )  ){
			//parametro diff
			return 0;
		}

		expr->tipo = param_list->type_param;

		expr = expr->expr2;
		param_list = param_list->next;
	
	}


	//todos os param era iguais-> assinatura igual
	if(expr == NULL && param_list == NULL){

		return 1;
	}

	return 0;

}



int assinatutas_iguais_call(is_expression_list* expr, param_node* param_list, method_var* lista_do_metodo){
	//expr e o 1 call more <=> 1 parametro chamado 
	//param_list e o 1 parametros declarado
	char * str1;
	char * str2;



	if(expr != NULL){
		//h apelo menos 1 parametro de entrada
		//vai meter tipos na ast
		recursao_expr(expr, lista_do_metodo);
	}
	


	while(expr != NULL && param_list != NULL){


		str1 = lowerCase(expr->expr1->tipo);
		str2 = lowerCase(param_list->type_param);

		//testo os parametros de entrada
		if( strcmp(str1, str2) != 0){
			//parametro diff
			return 0;
		}

		expr->tipo = param_list->type_param;


		expr = expr->expr2;
		param_list = param_list->next;
	
	}


	//todos os param era iguais-> assinatura igual
	if(expr == NULL && param_list == NULL){

		return 1;
	}

	return 0;

}


int assinatutas_iguais_global(table_element_global *newSymbol, table_element_global *aux){

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


void tenta_inserir_fieldDec_na_tail_global(table_element_global * newSymbol, is_fielddecl_list* ifdl){
	table_element_global *aux;
	table_element_global* previous;

	if(strcmp(newSymbol->name,"_") == 0 ){

		printf("Line %d, col %d: Symbol %s is reserved\n",ifdl->linha, ifdl->coluna, newSymbol->name);
		return;
	}



	//Vou inserir o node na Tabela de Simbolos Global
	if(symtab_global->declarations != NULL){	//Se table ja tem elementos
		
		//Procura cauda da lista e verifica se simbolo ja existe
		for(aux = symtab_global->declarations; aux != NULL ; previous = aux, aux = aux->next){


			if(strcmp(aux->name, newSymbol->name) == 0 && aux->type_return == NULL ){
				//encontramos um field dec declarado aj com este nome
				printf("Line %d, col %d: Symbol %s already defined\n",ifdl->linha, ifdl->coluna, newSymbol->name);
				return;
			}
		}
		
		previous->next = newSymbol;	//adiciona ao final da lista
	}else{
		symtab_global->declarations = newSymbol;	
	}

}


int tenta_inserir_metodo_na_tail_global(table_element_global * newSymbol){
	table_element_global *aux;
	table_element_global* previous;

	
	//Vou inserir o node na Tabela de Simbolos Global
	if(symtab_global->declarations != NULL){	//Se table ja tem elementos
		
		//Procura cauda da lista e verifica se simbolo ja existe 
		for(aux = symtab_global->declarations; aux != NULL ; previous = aux, aux = aux->next){
			if(strcmp(aux->name, newSymbol->name) == 0 && aux->type_return != NULL && assinatutas_iguais_global(newSymbol, aux) == 1){

				//printf("\nTODO M: Symbol %s already defined\n",aux->name);

				//TODO-controlo se ja foi declarado
				return 0;
			}
		}
		//printf("passou");
		previous->next = newSymbol;	//adiciona ao final da lista
	}else{
		symtab_global->declarations = newSymbol;	
	}

	return 1;

}


void tenta_inserir_na_tail_local(table_element_local * new_method){
	table_element_local* aux;
	table_element_local* previous;
	table_element_local * aux_method = new_method;
	method_var * aux_aux_tel;
	method_var * aux_new_method_tel;
	int verifica = 0, counter = 0;

	//Vou inserir o node na Tabela de Simbolos Local
	if(symtab_local != NULL){	//Se table ja tem elementos
		
		//Procura cauda da lista e verifica se simbolo ja existe (NOTA: assume-se uma tabela de simbolos local)
		for(aux = symtab_local; aux != NULL ; previous = aux, aux = aux->next){

			verifica = 0;
			counter = 0;
			
			//printf("%s %s\n",aux->name,aux_method->name);
			if(strcmp(aux->name, aux_method->name) == 0){

				//TEMOS QUE VERIFICAR A PARTIR DO SEGUNDO ELEMENTO PORQUE O PRIMEIRO É O TIPO DO RETURN
				//SE AMBOS DA TABELA LOCAL E DO NOVO SIMBOLO FOREM DIFERENTES NULL PODEMOS VERIFICAS
				if(aux_method->tel->next != NULL && aux->tel->next != NULL){
					

					aux_new_method_tel = aux_method->tel->next;
					aux_aux_tel = aux->tel->next;
					//printf("%s %s\n",aux_new_method_tel->type,aux_aux_tel->type);

					//VERIFICAR A LISTA DE PARAMETROS
					while(aux_aux_tel != NULL && aux_new_method_tel != NULL){
					
						if( (aux_aux_tel->is_param == 1 || aux_aux_tel->is_param == 2) && (aux_new_method_tel->is_param == 1 || aux_new_method_tel->is_param == 2)){

							counter++;

							if(strcmp(aux_aux_tel->type,aux_new_method_tel->type) == 0){
								verifica++;
							}
						}

						if(aux_aux_tel->next == NULL && aux_new_method_tel->next != NULL && ( aux_new_method_tel->next->is_param == 1 || aux_new_method_tel->next->is_param == 2)){
							//esta adicao serve para casos do genero (int,double) (int,double,boolean) em que os dois primeiros param sao iguais
							counter++;
							break;
						}else if(aux_aux_tel->next != NULL && aux_new_method_tel->next == NULL && (aux_aux_tel->next->is_param == 1 || aux_aux_tel->next->is_param == 2)){
							//esta adicao serve para casos do genero (int,double) (int,double,boolean) em que os dois primeiros param sao iguais
							counter++;
							break;
						}

						//printf("%d %d %s\n",counter,verifica,aux_method->name);
						aux_aux_tel = aux_aux_tel->next;
						aux_new_method_tel = aux_new_method_tel->next;
					}
					
					//CONDIÇAO DE PARAGEM SE ENCONTRAMOS UM METODO PARECIDO COM O QUE QUERIAMOS ADICIONAR PARAMOS
					if(verifica == counter){
						return;
					}
				//SE AMBOS SAO NULL ENTAO SAO IGUAIS LOGO NAO ADICIONAMOS
				}else if(aux_method->tel->next == NULL && aux->tel->next == NULL){
					return;
				}
				//OUTROS CASOS VERIFICAM E ACABAM POR ADICIONAR NO FIM
				
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
	free(stg);
}

table_element_local *insert_el_metodo_local(is_methodheader_list* imhl, is_methodbody_list* imbl){
	char * tipo;
	int verifica_param_repetido = 1;

	method_var *simb_last_param;
	method_var *var_metodo;
	method_var* inicio_param_metodo;
	method_var* aux;
	
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
	inicio_param_metodo = var_metodo;

	//parametros de entrada
	while(ast_param_list != NULL){

		aux = inicio_param_metodo;


		//verificar se o parametro da ast que queremos inserir tem o mesmo nome que um param ja inserido antes
		while(aux != NULL){

			if(strcmp(aux->name,ast_param_list->name) == 0 ){
				
				//printf("Line %d, col %d: Symbol %s already defined\n",ast_param_list->linha, ast_param_list->coluna, aux->name);
				
				verifica_param_repetido = 0;
			}

			aux = aux->next;
		}

		
		

		
		var_metodo = (method_var*) malloc(sizeof(method_var));

		var_metodo->name = (char*)strdup(ast_param_list->name);
		var_metodo->type = (char*)strdup(ast_param_list->type);
		if(verifica_param_repetido == 1){
			//param de entrada valido 
			var_metodo->is_param = 1;

		}else if(verifica_param_repetido == 0){
			//param de entrada ja declarado antes
			var_metodo->is_param = 2;
		}

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
		//&& ( ast_var_dec_or_statment->ivdl != NULL || ast_var_dec_or_statment->statment != NULL)
		while(ast_var_dec_or_statment != NULL  ){
		//while(ast_var_dec_or_statment != NULL ){  ACHO QUE O WHILE PODIA SER SO ISTO

			//e um statment e nao um var dec
			//Statmente
			if(ast_var_dec_or_statment->statment != NULL){
				
				recursao_statment(ast_var_dec_or_statment->statment, new_method);


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


					if( var_declarada(new_method->tel, var_metodo->name) != NULL  ){
						//printf("\nTODO VD: Symbol %s already defined\n",var_metodo->name);
						//estava declarada
						free(var_metodo);
						ast_var_dec_list = ast_var_dec_list->next;

					}else{

						simb_last_param->next = var_metodo;
						simb_last_param = var_metodo;  
						

						ast_var_dec_list = ast_var_dec_list->next;

					}

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

		//SERVE PARA ADICIONAR E VERIFICAR SE JA EXISTE
		tenta_inserir_fieldDec_na_tail_global(newSymbol, ifdl);


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


		tenta_inserir_fieldDec_na_tail_global(newSymbol, ifdl);


		ifdl = ifdl->next;
	}

	return para_dar_return;
	free(newSymbol);
}





//Insere um novo elemtento na global devido a Metodo
table_element_global *insert_el_metodo_global(is_methodheader_list* imhl){


	table_element_global *newSymbol;
	is_methodparams_list*  lista_param_entrada_aux;

	//ajuda a detetar nomes repetidos
	int num_param_entrada_percorridos = 0;
	int num_aux;

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

		num_param_entrada_percorridos++;
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
		



		//verificar se ja havia um param com esse nome na AST
		for(lista_param_entrada_aux = imhl->impl, num_aux = 0 ; num_aux < num_param_entrada_percorridos ; num_aux++, lista_param_entrada_aux=lista_param_entrada_aux->next ){

			if(strcmp(lista_param_entrada_aux->name, ast_param_list->name) == 0 ){
				printf("Line %d, col %d: Symbol %s already defined\n",ast_param_list->linha, ast_param_list->coluna, ast_param_list->name);
				break;
			}
		}
		num_param_entrada_percorridos++;



		if(strcmp(ast_param_list->name, "_") == 0 ){
			printf("Line %d, col %d: Symbol %s is reserved\n", ast_param_list->linha, ast_param_list->coluna, ast_param_list->name);
		}

		//avançamos para o proximo parametro da AST
		ast_param_list = ast_param_list->next;



	}


	if( tenta_inserir_metodo_na_tail_global(newSymbol) == 0 ) {
		//a assinatura deste metodo era repetida

		printf("Line %d, col %d: Symbol %s(",imhl->linha,imhl->coluna,imhl->name);
		
		param_node * param = newSymbol->param_list;

		//is_methodparams_list * param = imhl->impl;

		while(param!= NULL){
			printf("%s",type_print_error(param->type_param));
			if(param->next != NULL){
				printf(",");
			}

			param = param->next;
		}

		printf(") already defined\n");

		//nao vamos anotar o body deste metodo
		imhl->anotar_body = 0;
	}
	

	return newSymbol;
}

char * type_print_error(char * str){
	str = lowerCase(str);

	if(strcmp(str,"bool") == 0 ){
		str = "boolean";
	}
	else if(strcmp(str,"stringarray") == 0 ){
		str = "String[]";
	}

	return str;
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

			//devido ao bool
			if( strcmp(lowerCase(aux->declarations->type_return),"bool") == 0 ){
				printf("boolean\n");
			}else{
				printf("%s\n", lowerCase(aux->declarations->type_return) );
			}
			


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
		
			if(variavel->next != NULL && (variavel->next->is_param == 1 || variavel->next->is_param == 2 )){
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


			if(variavel->is_param != 2){
				printf("%s\t\t%s", variavel->name, str );
			}

			if(variavel->is_param == 1){
				printf("\tparam" );
			}

			if(variavel->is_param != 2){
				printf("\n");
			}

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