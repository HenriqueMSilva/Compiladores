#include "codegeneration.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

extern 	header_global 	*symtab_global;
extern	table_element_local 	*symtab_local;


int registocounter = 1;
int whilecounter = 1;
int ifcounter = 1;

void generation(is_program* p){

	generation_metodos(p->metodos);
	
}


void generation_metodos(is_metodos* metodos){
	is_metodos* tmp;
	string_element 	*tabela_global = symtab_global->string_element;

	char * typeFunction;
	char * nameFunction;
	char * mainType;
	char * aux;
	int hasmain = 0, stringcounter = 0;


	printf("@.argc = common global i32 0\n");
	//printf das variaveis globais
	for(tmp=metodos; tmp; tmp=tmp->next){
        if(tmp->ifl != NULL){
        	generation_field_list(tmp->ifl);
        }
    }

    if(metodos != NULL){

		printf("@.str.argv = constant [3 x i8] c\"%%s\\00\"\n");
		printf("@.str.int = constant [3 x i8] c\"%%d\\00\"\n");
		printf("@.str.double = constant [6 x i8] c\"%%.16e\\00\"\n");
		printf("@.str.true = constant [5 x i8] c\"true\\00\"\n");
		printf("@.str.false = constant [6 x i8] c\"false\\00\"\n");
	}

	if(symtab_global->minus_operation == 1){
		printf("@.str.minus = constant [2 x i8] c\"-\\00\"\n");
	}

	if(symtab_global->plus_operation == 1){
		printf("@.str.plus = constant [2 x i8] c\"+\\00\"\n");
	}


	//print das strings 
	while(tabela_global != NULL){

		tabela_global->pos = stringcounter;
		printf("@.str.%d = constant [%d x i8] c\"%s\\00\"\n",tabela_global->pos,tabela_global->tamanho,tabela_global->string);
		stringcounter++;
		tabela_global = tabela_global->next; 
	}


	//print do metodo
	for(tmp=metodos; tmp; tmp=tmp->next){

        if(tmp->imdl != NULL){
            generation_method_list(tmp->imdl);

            typeFunction = tmp->imdl->imhl->type;
            nameFunction = tmp->imdl->imhl->name;

            //se for main

            if( strcmp(nameFunction,"main") == 0 && tmp->imdl->imhl->impl != NULL && strcmp(tmp->imdl->imhl->impl->type,"StringArray") == 0 ){

            	hasmain = 1;

            	if( strcmp(tmp->imdl->imhl->type,"Double") == 0){
					mainType = "double";
				}else if( strcmp(tmp->imdl->imhl->type,"Int") == 0){
					mainType = "i32";
				}else if( strcmp(tmp->imdl->imhl->type,"Bool") == 0){
					mainType= "i1";
				}else if( strcmp(tmp->imdl->imhl->type,"Void") == 0){
					mainType= "void";
				}

            }

            //se for void
			if( strcmp(typeFunction,"Void") == 0 ){
				printf("ret void\n}\n");
			}else{

				if( strcmp(typeFunction,"Double") == 0){
					aux = "0.0";
				}else if(strcmp(typeFunction,"Int") == 0){
					aux = "0";
				}else if(strcmp(typeFunction,"Bool") == 0){
					aux = "0"; 
				}
				printf("ret %s %s\n}\n",generation_tipo(lowerType(typeFunction)),aux);
			}
        }

        registocounter = 1;
    }

        //verificar entry e size nao sei bem disso ainda
    if(hasmain == 0){
    	printf("define i32 @main(i32 %%.argc, i8** %%.argv){\n");
    	printf("ret i32 0\n}\n");
    }else{
    	printf("define i32 @main(i32 %%.argc, i8** %%.argv){\n");
    	printf("%%.argc_1 = alloca i32\n");
    	printf("store i32 %%.argc, i32* %%.argc_1\n");
    	printf("%%.1 = load i32, i32* %%.argc_1\n");
    	printf("store i32 %%.1, i32* @.argc\n");
		printf("call %s @main.nossa(i8** %%.argv)\n",mainType);
		printf("ret i32 0\n}\n");
    }

    //nos casos testes isto estava sempre no fim
    printf("declare i32 @printf(i8*, ...)\n");
    printf("declare i32 @atoi(i8*)\n");
}


//print de variaveis globais
void generation_field_list(is_fielddecl_list* ifl){

	is_fielddecl_list* temp = ifl;
	char * aux = NULL;
	char * aux2 = NULL;

	if( strcmp(lowerType(temp->type),"double") == 0){
		aux = "0.0";
	}else if(strcmp(lowerType(temp->type),"int") == 0){
		aux = "0";
	}else if(strcmp(lowerType(temp->type),"boolean") == 0){
		aux = "0";
	}

	if(temp != NULL){
		aux2 = generation_tipo(temp->type);
	}


	while(temp != NULL){

		printf("@%s = common global %s %s\n",temp->name,aux2 ,aux);
		temp = temp->next;
	}

}


//print dos metodos
void generation_method_list(is_methoddecl_list* imdl){

    is_methoddecl_list* tmp = imdl;

    //le parametros e nome da funçao
    generation_methodheader_list(tmp->imhl);
 
 	//le body
 	generation_methodbody_list(tmp->imbl,tmp->imhl);

 
}



void generation_methodheader_list(is_methodheader_list* imhl){

	is_methodparams_list* ast_param_list = imhl->impl;
	//TODO aumentar este buffer?


	//print do tipo da funcao
	printf("define %s @",generation_tipo(lowerType(imhl->type)));




	//peco desculpa por estes ifs
	if(strcmp(imhl->name,"main") == 0 && imhl->impl != NULL  ){
		//ver se e a main(String[])

		if( strcmp( lowerType(imhl->impl->type), "String[]") == 0 ){
			//printf("\n\n\n-%s--------------------\n\n\n\n",imhl->impl->type );
			printf("%s.nossa(",imhl->name);
		}else{ 
			//p.e main(int)
			//nome da funcao
			printf("%s(",imhl->nome_llvm);

		}

	}else{
		//nome da funcao
		printf("%s(",imhl->nome_llvm);

	}


	//verificar se a funçao é a main

	
	
	while(ast_param_list != NULL){

		if( strcmp(lowerType(ast_param_list->type),"double") == 0){
			ast_param_list->generation_type = "double";
		}else if( strcmp(lowerType(ast_param_list->type),"int") == 0){
			ast_param_list->generation_type = "i32";
		}else if( strcmp(lowerType(ast_param_list->type),"boolean") == 0){
			ast_param_list->generation_type = "i1";
		}else if( strcmp(lowerType(ast_param_list->type),"String[]") == 0){
			ast_param_list->generation_type = "i8**";
		}

		printf("%s %%.%s",ast_param_list->generation_type,ast_param_list->name);

		if(ast_param_list->next != NULL){
			printf(", ");
		}
		ast_param_list = ast_param_list->next;
	}
	printf(") {\n");


	generation_param_list(imhl->impl,imhl->name);

}


void generation_param_list(is_methodparams_list* impl, char* nameFunction){

	is_methodparams_list* asl = impl;

	while(asl != NULL){

		printf("%%%s = alloca %s\n",asl->name, asl->generation_type);
		printf("store %s %%.%s, %s* %%%s\n", asl->generation_type,asl->name,asl->generation_type,asl->name);

		asl = asl->next;
	}
}


void generation_methodbody_list(is_methodbody_list* imbl,is_methodheader_list* imhl){

	is_methodbody_list* tmp;

	for(tmp=imbl; tmp; tmp=tmp->next){
        if(tmp->ivdl != NULL){
        	generation_vardecl_list(tmp->ivdl,imhl);
        }
	    if(tmp->statment != NULL){
	    	generation_statment_list(tmp->statment,imhl);
	    }
    }
}


int assinaturas_iguais_local(is_methodheader_list* imhl,table_element_local *tabela_local ){


	method_var *  local_param = tabela_local->tel;
	is_methodparams_list * ast_param = imhl->impl;
	


	//skip do param return;
	if(local_param->is_param == 0 && strcmp(local_param->name,"return") == 0  ){
		local_param = local_param->next;
	}

	

	while( local_param != NULL && ast_param != NULL && local_param->is_param == 1){

		
		//testo os parametros de entrada
		if( ! (strcmp(lowerType(local_param->type) , lowerType(ast_param->type) ) == 0 && local_param->is_param == 1)  ){
			//parametro diff
			
			return 0;
		}



		local_param = local_param->next;
		ast_param = ast_param->next;
	
	}


	//todos os param era iguais-> assinatura igual
	if( (local_param == NULL || (local_param != NULL && local_param->is_param == 0)) && ast_param == NULL){

		return 1;
	}

	return 1;

}



void generation_vardecl_list(is_vardecl_list* ivdl,is_methodheader_list* imhl){

	table_element_local *tabela_local;
	is_vardecl_list* temp = ivdl;
	method_var *  local_param = NULL;

	char * aux = NULL;

	if( strcmp(temp->type,"Double") == 0){
		aux = "double";
	}else if( strcmp(temp->type,"Int") == 0){
		aux = "i32";
	}else if( strcmp(temp->type,"Bool") == 0){
		aux = "i1";
	}else if( strcmp(temp->type,"StringArray") == 0){
		aux = "i8**";
	}

	temp->generation_type = aux;
	while(temp != NULL){
		tabela_local = symtab_local;

		while(tabela_local != NULL){

			if(strcmp(tabela_local->name, imhl->name) == 0){
				if( assinaturas_iguais_local(imhl, tabela_local) == 1){
					local_param = tabela_local->tel->next;
					while(local_param != NULL){
						if(strcmp(temp->name,local_param->name) == 0 ){

							local_param->is_declared = 1;
							break;
						}
						
						local_param = local_param->next;
					}
				}

			}
			tabela_local = tabela_local->next;
		}



		temp->generation_type = aux;
		printf("%%%s = alloca %s\n",temp->name,temp->generation_type);
		temp = temp->next;
	}
}



void generation_statment_list(is_statment_list* statment,is_methodheader_list* imhl){

	if(statment->expr != NULL /*&& strcmp(statment->name_function,"While") != 0*/){
		generation_expression(statment->expr, imhl);
	}
	

	if(strcmp(statment->name_function,"Print") == 0){

		if(strcmp(lowerType(statment->expr->tipo),"String") == 0){
			string_element 	*string_element = symtab_global->string_element;

			while(string_element != NULL){
				if(string_element->printed == 0){
					printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([%d x i8], [%d x i8]* @.str.%d, i32 0, i32 0))\n",registocounter,string_element->tamanho,string_element->tamanho,string_element->pos);
					string_element->printed = 1;
					break;
				}
				string_element = string_element->next; 
			}
		
		}else if(strcmp(lowerType(statment->expr->tipo),"String[]") == 0 && strcmp(statment->expr->operation,"ParseArgs") == 0 ){
			//Parse.Int( args[ExprA] ) 
			
			printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr  ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %%.%d)\n",registocounter, statment->expr->registo_number);



		}else if(strcmp(lowerType(statment->expr->tipo),"String[]") == 0 && strcmp(statment->expr->operation,"Length") == 0 ){
            //args.lenght
       
			printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %%.%d)\n",registocounter,statment->expr->registo_number);

        }else if(strcmp(lowerType(statment->expr->tipo),"boolean") == 0){

			printf("br i1 %%.%d, label %%then%d, label %%else%d\n",statment->expr->registo_number,ifcounter,ifcounter);
			printf("then%d:\n",ifcounter);
			printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))\n",registocounter);
			printf("br label %%ifCont%d\n",ifcounter);
			printf("else%d:\n",ifcounter);
			registocounter++;
			printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))\n",registocounter);
			printf("br label %%ifCont%d\n",ifcounter);
			printf("ifCont%d:\n",ifcounter);

		}else if(strcmp(lowerType(statment->expr->tipo),"int") == 0){

			printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %%.%d)\n",registocounter,statment->expr->registo_number);
		
		}else if(strcmp(lowerType(statment->expr->tipo),"double") == 0){

			printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %%.%d)\n",registocounter,statment->expr->registo_number);
		}

		registocounter++;
		ifcounter++;
	}

	if(strcmp(statment->name_function,"While") == 0){ 
		statment->number_condition = whilecounter;
		printf("br label %%while%d\n",statment->number_condition);
		printf("while%d:\n",statment->number_condition);
		whilecounter++;
	}

	if(strcmp(statment->name_function,"If") == 0 || strcmp(statment->name_function,"IfElse") == 0){
		statment->number_condition = ifcounter;
		printf("br i1 %%.%d, label %%then%d, label %%else%d\n",statment->expr->registo_number,statment->number_condition ,statment->number_condition);
		printf("then%d:\n",statment->number_condition);
		ifcounter++;
	}

	if(strcmp(statment->name_function,"Return") == 0){


		//simb table ponteiro num returrn;
		//simb table tipo returrn;

		//se for undef entao return; logo é void
		if(strcmp(statment->expr->tipo,"undef") != 0){
			printf("ret %s %%.%d\n",statment->expr->generation_type,statment->expr->registo_number);
		}
	}

	if(strcmp(statment->name_function,"Call") == 0){
		//nao preciso de fazer nada

	}



	//ir para statmet1
	if(statment->statment1 != NULL ){
		generation_statment_list(statment->statment1,imhl);
	}

	if(strcmp(statment->name_function,"If") == 0 || strcmp(statment->name_function,"IfElse") == 0){
		printf("br label %%ifCont%d\n",statment->number_condition);
		printf("else%d:\n",statment->number_condition);
	}

	//ir para statmet2
	if(statment->statment2 != NULL ){
		generation_statment_list(statment->statment2,imhl);
	}



	if(strcmp(statment->name_function,"While") == 0){

		if(statment->expr != NULL){
			generation_expression(statment->expr,imhl);
		}
		
		printf("br i1 %%.%d, label %%while%d, label %%whileCont%d\n", statment->expr->registo_number, statment->number_condition,statment->number_condition);
		printf("whileCont%d:\n",statment->number_condition);
	}

	if(strcmp(statment->name_function,"If") == 0 || strcmp(statment->name_function,"IfElse") == 0){
		printf("br label %%ifCont%d\n",statment->number_condition);
		printf("ifCont%d:\n",statment->number_condition);
	}

}


int verifica_variavel(is_methodheader_list* imhl, is_expression_list* expr){
	table_element_local *tabela_local = symtab_local;
	method_var *  local_param = NULL;


	while(tabela_local != NULL){

		//verifica nome da funçao
		if(strcmp(tabela_local->name, imhl->name) == 0){


			//verifica assinatura da funçao
			if( assinaturas_iguais_local(imhl, tabela_local) == 1){


				//percorro lista de parametros da tabela local
				local_param = tabela_local->tel->next;
				while(local_param != NULL){


					//printf("expr:%s loacal: %s\n\n\n", expr->value, local_param->name);
					if(strcmp(expr->value,local_param->name) == 0 && local_param->is_declared == 1){
						//se for local
						return 1;
					}
					
					local_param = local_param->next;
				}
			}

		}
		tabela_local = tabela_local->next;
	}
	
	return 0;
}




/*
void guarda_nome_func_llvm(char* nome_guardar, is_methodheader_list* imhl , table_element_global * metodos_da_classe){
	//expr do call
	// metodos_da_class e a tabela SIMB global
	
	param_node * simb_param;	
	is_methodparams_list* ast_param;

	char * ast_tipo;
	char * simb_tipo;


	while(metodos_da_classe != NULL){


		//compara o nome das funcoes
		if(strcmp(metodos_da_classe->name, imhl->name) == 0){


			ast_param = imhl->impl;
			simb_param = metodos_da_classe->param_list;


			//percorrer os parametos de entrada das duas funcoes
			while( simb_param != NULL &&  ast_param != NULL){

 				ast_tipo =  lowerType(ast_param->type);
 				simb_tipo =  lowerType(simb_param->type_param);


				if(strcmp(ast_tipo, simb_tipo) != 0 ){
					//tipos dos parametros de entrada differentes
					break;
				}

				//eram iguais, vamos verificar o proximo parametro

				ast_param = ast_param->next;
				simb_param = simb_param->next;
			}


			if(simb_param == NULL &&  ast_param == NULL){
				
				//assinaturas iguais
				metodos_da_classe->nome_llvm = nome_guardar;


				//printf("\n\nGuardou: %s Na FUNC: %s\n\n\n",metodos_da_classe->nome_llvm, metodos_da_classe->name );
				return; 
			}


		}

		metodos_da_classe = metodos_da_classe->next;

	}


}*/

table_element_global * devolve_nome_func_llvm_parecida(is_expression_list * expr, table_element_global * metodos_da_classe){
//expr do call
	// metodos_da_class e a tabela SIMB global

	is_expression_list* ast_param; 
	param_node * simb_param;

	char * ast_tipo;
	char * simb_tipo;

	while(metodos_da_classe != NULL){


		//e um field dec
		if(metodos_da_classe->type_return == NULL){
			metodos_da_classe = metodos_da_classe->next;
			continue;
		}


		//compara o nome das funcoes
		if(strcmp(metodos_da_classe->name, expr->value ) == 0){

			//callmore
			ast_param =	expr->expr1;
			simb_param = metodos_da_classe->param_list;

			//percorrer os parametos de entrada das duas funcoes
			while( simb_param != NULL &&  ast_param != NULL){

 				ast_tipo =  lowerType(ast_param->expr1->tipo);
 				simb_tipo =  lowerType(simb_param->type_param);


				if(strcmp(ast_param->expr1->operation,"Length") == 0 || strcmp(ast_param->expr1->operation,"ParseArgs") == 0 ){
	            	ast_tipo = "int";
				}


				//NOT (parametros aceitaves)
				if( !(strcmp(ast_tipo, simb_tipo) == 0  || (strcmp( lowerType(ast_tipo), "int") == 0 && strcmp(lowerType(simb_tipo), "double") == 0) )  ){
					//tipos dos parametros de entrada differentes
					break;

				}

				//eram iguais, vamos verificar o proximo parametro

				ast_param = ast_param->expr2;
				simb_param = simb_param->next;
			}


			if(simb_param == NULL &&  ast_param == NULL){
				//assinaturas iguais
				//return metodos_da_classe->nome_llvm;
				return metodos_da_classe;
			}

		}

		metodos_da_classe = metodos_da_classe->next;

	}


	//NUNCA DEVE CHEGAR AQUI
	return NULL;



}

table_element_global * devolve_nome_func_llvm_igual(is_expression_list * expr, table_element_global * metodos_da_classe){
	//expr do call
	// metodos_da_class e a tabela SIMB global

	is_expression_list* ast_param; 
	param_node * simb_param;

	char * ast_tipo;
	char * simb_tipo;

	while(metodos_da_classe != NULL){

		//e um field dec
		if(metodos_da_classe->type_return == NULL){
			metodos_da_classe = metodos_da_classe->next;
			continue;
		}

		//compara o nome das funcoes
		if(strcmp(metodos_da_classe->name, expr->value ) == 0){

			//callmore
			ast_param =	expr->expr1;
			simb_param = metodos_da_classe->param_list;

			//percorrer os parametos de entrada das duas funcoes
			while( simb_param != NULL &&  ast_param != NULL){

 				ast_tipo =  lowerType(ast_param->expr1->tipo);
 				simb_tipo =  lowerType(simb_param->type_param);

				if(strcmp(ast_param->expr1->operation,"Length") == 0 || strcmp(ast_param->expr1->operation,"ParseArgs") == 0 ){
	            	ast_tipo = "int";
				}


				if(strcmp(ast_tipo, simb_tipo) != 0 ){
					//tipos dos parametros de entrada differentes
					break;

				}

				//eram iguais, vamos verificar o proximo parametro

				ast_param = ast_param->expr2;
				simb_param = simb_param->next;
			}


			if(simb_param == NULL &&  ast_param == NULL){
				//assinaturas iguais
				//return metodos_da_classe->nome_llvm;
				return metodos_da_classe;

			}

		}

		metodos_da_classe = metodos_da_classe->next;

	}


	//chega aqui se nao encontro uma funcao declarada igual
	//e possivel chegar aqui se estiver a ser usada uma funcao 
	return NULL;

}




int convertType(const char* value, double *destination) {
  char sentinel;
  return sscanf(value,"%lf %c", destination, &sentinel) == 1;
}


char * novo_formato_int(char * str){
	int i,k=0;

	char * new_str =  (char*) malloc(100*sizeof(char)); 

	for(i=0;i<strlen(str);i++){
		//ignorar o _
		if( str[i] != '_'){
			new_str[k] = str[i];
			k++;
		}
	}
	return new_str;
}


void generation_expression(is_expression_list* expr,is_methodheader_list* imhl){
	char * aux = NULL;
	int result= 0;

	if(expr->expr1 != NULL  ){
		generation_expression(expr->expr1,imhl );
	}

	if(expr->expr2 != NULL && strcmp(expr->value,"And") != 0 && strcmp(expr->value,"Or") != 0){
		generation_expression(expr->expr2,imhl );
	}

	//printf("%s %s\n",expr->operation,expr->value);

	//se for ID retorna registo
	if( strcmp(expr->operation, "Id" ) == 0){

		result = verifica_variavel(imhl,expr);

		expr->generation_type = generation_tipo(lowerType(expr->tipo));
		expr->registo_number = registocounter;

		if(result == 1){
			//se for local
			printf("%%.%d = load %s, %s* %%%s\n",registocounter,expr->generation_type,expr->generation_type,expr->value);
		
		}else {
			//se for global
			printf("%%.%d = load %s, %s* @%s\n",registocounter,expr->generation_type,expr->generation_type,expr->value);
		}

		registocounter++;

	}

	//adicionar a um registo o valor inteiro
	if(strcmp(expr->operation, "DecLit" ) == 0){

		expr->generation_type = generation_tipo(lowerType(expr->tipo));
		expr->registo_number = registocounter;


		char * str = expr->value;
		

		char * new_str = novo_formato_int(str);

		printf("%%.%d = add %s 0, %s\n",expr->registo_number,expr->generation_type,new_str);
		registocounter++;
	}

	//adicionar a um registo o valor double
	if(strcmp(expr->operation, "RealLit" ) == 0){

		//REVER AINDA NAO ESTA BEM
		expr->generation_type = generation_tipo(lowerType(expr->tipo));
		expr->registo_number = registocounter;


		char * str = expr->value;
		

		char * new_str = novo_formato_int(str);

		double x;
		convertType(new_str, &x);


		printf("%%.%d = fadd  %s 0.000000, %.16e\n",expr->registo_number,expr->generation_type,x);
		registocounter++;
	}

	//adicionar a um registo o valor bool
	if(strcmp(expr->operation, "BoolLit" ) == 0){

		expr->generation_type = generation_tipo(lowerType(expr->tipo));
		expr->registo_number = registocounter;
		printf("%%.%d = or %s false, %s\n",expr->registo_number,expr->generation_type,expr->value);
		registocounter++;
	}


	if(strcmp(expr->operation,"ParseArgs") == 0 ){
		//Parse.Int( args[ExprA] ) 
		
		//este generation tipo e problematico? TODO
		expr->generation_type = generation_tipo("int");

		//printf("-%s-\n\n\n",expr->generation_type );
		


		//vou buscar a %argv local 								
		printf("%%.%d = load i8**, i8*** %%%s\n",registocounter, expr->value);
        registocounter++;
        

    	//novo index
    	printf("%%.%d = add i32 1 , %%.%d \n",registocounter, expr->expr1->registo_number );
    	registocounter++;

        
    	//ponteiro com o endereco do paramentro de entrada certo
      	printf("%%.%d = getelementptr i8*, i8** %%.%d, i32 %%.%d\n",registocounter, registocounter - 2, registocounter - 1 );
		registocounter++;
		

		//registo com o int em string p.e. "15"
		printf("%%.%d = load i8*, i8** %%.%d\n", registocounter, registocounter - 1);
		registocounter++;


		//%.6 = call i32 @atoi(i8* %.5)
		printf("%%.%d = call i32 @atoi(i8* %%.%d)\n", registocounter, registocounter - 1);
		expr->registo_number = registocounter;
		registocounter++;


	


	}



	if(strcmp(expr->operation,"Length") == 0 ){
        //args.lenght

		//este generation tipo e problematico? TODO
		expr->generation_type = generation_tipo("int");
	
    
        printf("%%.%d = load i32, i32* @.argc\n",registocounter);
        registocounter++;


		expr->registo_number = registocounter;
        printf("%%.%d = sub i32 %%.%d, 1 \n",registocounter, registocounter-1 );
        registocounter++;
    
	}



	if(strcmp(expr->operation, "Call" ) == 0){
		char * nome_llvm;
		is_expression_list * param;
		param_node * simb_param;
		
		table_element_global * ref_funcao;

		char * tipo;
		int numero;
		int offset = 0;



		//nome da funcao igual 
		ref_funcao = devolve_nome_func_llvm_igual(expr, symtab_global->declarations);
		
		if(ref_funcao == NULL){
			//nome da funcao parecida 
			ref_funcao = devolve_nome_func_llvm_parecida(expr, symtab_global->declarations);
		}

		//printf("\n\n%s\n\nhega aqui\n\n\n\n",ref_funcao->nome_llvm);

		nome_llvm = ref_funcao->nome_llvm; 

		expr->registo_number = registocounter;
		expr->generation_type = generation_tipo(lowerType(expr->tipo));

		//printf("...\n\n\n");
		//printf("%s\n",expr->tipo  );


		//callmore
		param = expr->expr1;
		
		//1 param da simb table
		simb_param = ref_funcao->param_list;

		//----------------------------------
		//se estivermos a meter um int no lugar de um double temos de converter primeiro antes do call
		while(param != NULL){


			tipo = param->expr1->generation_type;
			numero = param->expr1->registo_number;


			if(strcmp(lowerType(simb_param->type_param),"double") == 0 && (strcmp(lowerType(param->expr1->tipo),"int") ==0 || strcmp( lowerType(param->expr1->tipo),"String[]") == 0) ){

				printf("%%.%d = sitofp i32 %%.%d to double\n",registocounter, numero );

 				//tipo = "i32"; 
 				//numero = registocounter; 

 				offset += 1;

				registocounter++;
				
			}

			param = param->expr2;
		}












		//--------------------------------
		//print do call
		if( strcmp(lowerType(expr->tipo),"void") != 0){
			printf("%%.%d = ",registocounter);
			
			offset += 1;
			registocounter++;
		}


		printf("call %s @%s(", expr->generation_type, nome_llvm  );


		//callmore
		param = expr->expr1;
		
		//1 param da simb table
		simb_param = ref_funcao->param_list;

		while(param != NULL){


			tipo = param->expr1->generation_type;
			numero = param->expr1->registo_number;


			if(strcmp(lowerType(simb_param->type_param),"double") == 0 && (strcmp(lowerType(param->expr1->tipo),"int") ==0 || strcmp( lowerType(param->expr1->tipo),"String[]") == 0) ){

				//printf("%%.%d = sitofp i32 %%.%d to double\n",registocounter, numero );

 				tipo = "double"; 
 				numero = registocounter - offset; 
				
			}



			printf("%s %%.%d", tipo, numero  );

			if(param->expr2 != NULL){
				printf(", ");
			}	

			param = param->expr2;
		}

		printf(")\n");






	}


	if(strcmp(expr->operation, "CallMore" ) == 0){
		//nao precisa de fazer nada
	}


	if( strcmp(expr->operation, "Assign" ) == 0 ){
		


		result = verifica_variavel(imhl,expr);

		expr->generation_type = generation_tipo(lowerType(expr->tipo));
		expr->registo_number = registocounter-1;		
		//printf("%d\n", result);

		//printf("%s %d \n",expr->value,registocounter);
		if(result == 1){
			//se for local

			//printf("%s %s",expr->tipo,expr->expr1->tipo);
			if(strcmp(lowerType(expr->tipo),"double") ==0 && (strcmp(lowerType(expr->expr1->tipo),"int") ==0 || strcmp(lowerType(expr->expr1->tipo),"String[]") == 0) ){

				printf("%%.%d = sitofp %s %%.%d to %s\n",registocounter,expr->expr1->generation_type,expr->expr1->registo_number,expr->generation_type);

				expr->expr1->registo_number = registocounter;
				expr->registo_number = registocounter;
				
				printf("store %s %%.%d, %s* %%%s\n",expr->generation_type,registocounter,expr->generation_type,expr->value);

				registocounter++;
			}else{

				printf("store %s %%.%d, %s* %%%s\n",expr->generation_type, expr->expr1->registo_number,expr->generation_type,expr->value);
				
			}
		
		}else{
			//se for global

			if(strcmp(lowerType(lowerType(expr->tipo)),"double") == 0 &&  (strcmp(lowerType(expr->expr1->tipo),"int") ==0 || strcmp(lowerType(expr->expr1->tipo),"String[]") == 0)){
				
				printf("%%.%d = sitofp %s %%.%d to %s\n",registocounter,expr->expr1->generation_type,expr->expr1->registo_number,expr->generation_type);
				
				expr->expr1->registo_number = registocounter;
				expr->registo_number = registocounter;
				
				printf("store %s %%.%d, %s* @%s\n",expr->generation_type,registocounter,expr->generation_type,expr->value);
				registocounter++;
			}else{
			
				printf("store %s %%.%d, %s* @%s\n",expr->generation_type,expr->expr1->registo_number,expr->generation_type,expr->value);
					
			}
		}
			
			//printf("%s %s %s\n",expr->value,expr->tipo,expr->generation_type);
	}





	if((strcmp(expr->value,"Add") == 0 || strcmp(expr->value,"Sub") == 0 || strcmp(expr->value,"Mul") == 0 || strcmp(expr->value,"Div") == 0 || strcmp(expr->value,"Mod") == 0)){

		expr->generation_type = generation_tipo(lowerType(expr->tipo));


		if(strcmp(lowerType(expr->tipo),"double") == 0){
			aux = generationOperation( expr->value, lowerType(expr->tipo));
		}

		if(strcmp(lowerType(expr->tipo),"int") == 0 ){
			aux = generationOperation( expr->value,lowerType(expr->tipo));
		}

		if( ((strcmp(lowerType(expr->expr1->tipo),"int") == 0 || strcmp(lowerType(expr->expr1->tipo),"String[]") == 0 ) && strcmp(lowerType(expr->expr2->tipo),"double") == 0) ){

			printf("%%.%d = sitofp %s %%.%d to %s\n",registocounter,expr->expr1->generation_type,expr->expr1->registo_number,expr->generation_type);
			expr->expr1->registo_number = registocounter;
		}

		if((strcmp(lowerType(expr->expr1->tipo),"double") == 0 && (strcmp(lowerType(expr->expr2->tipo),"int") == 0 || strcmp(lowerType(expr->expr2->tipo),"String[]") == 0 ))){
			printf("%%.%d = sitofp %s %%.%d to %s\n",registocounter,expr->expr2->generation_type,expr->expr2->registo_number,expr->generation_type);
			expr->expr2->registo_number = registocounter;
		}



		registocounter++;

		printf("%%.%d = %s %s %%.%d, %%.%d\n",registocounter,aux,expr->generation_type,expr->expr1->registo_number,expr->expr2->registo_number);
		
		expr->registo_number = registocounter;
		registocounter++;
	}





	if(strcmp(expr->value,"Eq") == 0 || strcmp(expr->value,"Ne") == 0 || strcmp(expr->value,"Ge") == 0 || strcmp(expr->value,"Gt") == 0 || strcmp(expr->value,"Le") == 0 || strcmp(expr->value,"Lt") == 0 ){

		//tipo boolean
		expr->generation_type = generation_tipo(lowerType(expr->tipo));


		//verifica se algum deles e double para passar o inteiro para double
		if( (strcmp(lowerType(expr->expr1->tipo),"int") == 0 || strcmp(lowerType(expr->expr1->tipo),"String[]") == 0 ) && strcmp(lowerType(expr->expr2->tipo),"double") == 0 ){
			printf("%%.%d = sitofp %s %%.%d to double\n",registocounter,expr->expr1->generation_type,expr->expr1->registo_number);
			expr->expr1->registo_number = registocounter;
			registocounter++;
		}

		if( strcmp(lowerType(expr->expr1->tipo),"double") == 0 && (strcmp(lowerType(expr->expr2->tipo),"int") == 0 || strcmp(lowerType(expr->expr2->tipo),"String[]") == 0 )  ){
			printf("%%.%d = sitofp %s %%.%d to double\n",registocounter,expr->expr2->generation_type,expr->expr2->registo_number);
			expr->expr2->registo_number = registocounter;
			registocounter++;
		}
		
		

		//printa consoante o tipo double e int
		if(strcmp(lowerType(expr->expr1->tipo),"double") == 0 || strcmp(lowerType(expr->expr2->tipo),"double") == 0){
			aux = generationOperation( expr->value, "double");	
			printf("%%.%d = fcmp %s double %%.%d, %%.%d\n",registocounter,aux,expr->expr1->registo_number,expr->expr2->registo_number);
		}

		if((strcmp(lowerType(expr->expr1->tipo),"int") == 0 || strcmp(lowerType(expr->expr1->tipo),"String[]") == 0 ) && (strcmp(lowerType(expr->expr2->tipo),"int") == 0 || strcmp(lowerType(expr->expr2->tipo),"String[]") == 0 )){
			aux = generationOperation( expr->value, "int");	
			printf("%%.%d = icmp %s %s %%.%d, %%.%d\n",registocounter,aux, expr->expr1->generation_type  ,expr->expr1->registo_number,expr->expr2->registo_number);
		}


		//printa consoante o tipo boolean
		if((strcmp(lowerType(expr->expr1->tipo),"boolean") == 0 && strcmp(lowerType(expr->expr2->tipo),"boolean") == 0)){
			printf("%%.%d = zext i1 %%.%d to i32\n",registocounter,expr->expr1->registo_number);
			expr->expr1->registo_number = registocounter;
			registocounter++;


			printf("%%.%d = zext i1 %%.%d to i32\n",registocounter,expr->expr2->registo_number);
			expr->expr2->registo_number = registocounter;
			registocounter++;


			aux = generationOperation( expr->value, "int");	
			printf("%%.%d = icmp %s i32 %%.%d, %%.%d\n",registocounter,aux,expr->expr1->registo_number,expr->expr2->registo_number);

		}



		expr->registo_number = registocounter;
		registocounter++;
	}



	if(strcmp(expr->value,"And") == 0){

		printf("br i1 %%.%d, label %%thenaux%d, label %%else%d\n",expr->expr1->registo_number,ifcounter,ifcounter);
		printf("thenaux%d:\n",ifcounter);

		if(expr->expr2 != NULL){
			generation_expression(expr->expr2,imhl );
		}

		printf("br label %%then%d\n",ifcounter);
		printf("then%d:\n",ifcounter);

		printf("%%.%d = add i1 0, %%.%d\n",registocounter,expr->expr2->registo_number);

		printf("br label %%ifCont%d\n",ifcounter);


		printf("else%d:\n",ifcounter);
		printf("br label %%ifCont%d\n",ifcounter);
		printf("ifCont%d:\n",ifcounter);

		registocounter++;


		printf("%%.%d = phi i1 [  %%.%d, %%then%d ], [ %%.%d, %%else%d ]\n",registocounter,expr->expr2->registo_number+1,ifcounter,expr->expr1->registo_number,ifcounter);

		expr->generation_type = generation_tipo(lowerType(expr->tipo));
		expr->registo_number = registocounter;

		ifcounter++;
		registocounter++;
	}


	if(strcmp(expr->value,"Or") == 0){

		printf("br i1 %%.%d, label %%then%d, label %%elseaux%d\n",expr->expr1->registo_number,ifcounter,ifcounter);
		printf("then%d:\n",ifcounter);
		printf("br label %%ifCont%d\n",ifcounter);

		printf("elseaux%d:\n",ifcounter);

		if(expr->expr2 != NULL){
			generation_expression(expr->expr2,imhl );
		}

		printf("br label %%else%d\n",ifcounter);
		printf("else%d:\n",ifcounter);


		printf("%%.%d = add i1 0, %%.%d\n",registocounter,expr->expr2->registo_number);

		printf("br label %%ifCont%d\n",ifcounter);

		printf("ifCont%d:\n",ifcounter);

		registocounter++;

		printf("%%.%d = phi i1 [  %%.%d, %%then%d ], [ %%.%d, %%else%d ]\n",registocounter,expr->expr1->registo_number,ifcounter,expr->expr2->registo_number+1,ifcounter);

		expr->generation_type = generation_tipo(lowerType(expr->tipo));
		expr->registo_number = registocounter;

		ifcounter++;
		registocounter++;
	}


	if(strcmp(expr->value,"Minus") == 0){

		expr->generation_type = generation_tipo(expr->tipo);
		expr->registo_number = registocounter;
		
		if(strcmp(lowerType(expr->tipo),"double") == 0){
			printf("%%.%d = fmul double -1.0, %%.%d\n",expr->registo_number,expr->expr1->registo_number);
		}
		if(strcmp(lowerType(expr->tipo),"int") == 0){
			printf("%%.%d = mul i32 -1, %%.%d\n",expr->registo_number,expr->expr1->registo_number);
		}

		registocounter++;
	}


	if(strcmp(expr->value,"Plus") == 0){
		expr->generation_type = generation_tipo(expr->tipo);
		expr->registo_number = registocounter;
		
		if(strcmp(lowerType(expr->tipo),"double") == 0){
			printf("%%.%d = fmul double 1.0, %%.%d\n",expr->registo_number,expr->expr1->registo_number);
		}
		if(strcmp(lowerType(expr->tipo),"int") == 0){
			printf("%%.%d = mul i32 1, %%.%d\n",expr->registo_number,expr->expr1->registo_number);
		}
		

		registocounter++;
	}



	if(strcmp(expr->value,"Not") == 0){

		printf("%%.%d = alloca i1\n",registocounter);
		printf("br i1 %%.%d, label %%then%d, label %%else%d\n",expr->expr1->registo_number,ifcounter,ifcounter);
		printf("then%d:\n",ifcounter);
		printf("store i1 false, i1* %%.%d\n",registocounter);
		printf("br label %%ifCont%d\nelse%d:\n",ifcounter,ifcounter);
		printf("store i1 true, i1* %%.%d\n",registocounter);
		printf("br label %%ifCont%d\nifCont%d:\n",ifcounter,ifcounter);
		registocounter++;
		printf("%%.%d = load i1, i1* %%.%d\n",registocounter,registocounter-1);

		expr->expr1->registo_number = registocounter; 
		expr->generation_type =  generation_tipo(lowerType(expr->tipo));
		expr->registo_number = expr->expr1->registo_number;
		ifcounter++;
		registocounter++;
	}	

	if(strcmp(expr->value,"Xor") == 0){

		printf("%%.%d = alloca i1\n",registocounter);
		printf("br i1 %%.%d, label %%then%d, label %%else%d\n",expr->expr1->registo_number,ifcounter,ifcounter);
		printf("then%d:\n",ifcounter);
		printf("store i1 false, i1* %%.%d\n",registocounter);
		printf("br label %%ifCont%d\nelse%d:\n",ifcounter,ifcounter);
		printf("store i1 true, i1* %%.%d\n",registocounter);
		printf("br label %%ifCont%d\nifCont%d:\n",ifcounter,ifcounter);
		registocounter++;
		printf("%%.%d = load i1, i1* %%.%d\n",registocounter,registocounter-1);
		registocounter++;
		printf("%%.%d = xor i1 %%.%d, %%.%d\n",registocounter,registocounter-1,expr->expr2->registo_number);

		expr->expr1->registo_number = registocounter; 
		expr->generation_type =  generation_tipo(lowerType(expr->tipo));
		expr->registo_number = expr->expr1->registo_number;
		ifcounter++;
		registocounter++;

	}
}




char * generation_tipo(char * str){
	char * aux = NULL;	

	if( strcmp(lowerType(str),"double") == 0){
		aux = "double";
	}else if( strcmp(lowerType(str),"int") == 0){
		aux = "i32";
	}else if( strcmp(lowerType(str),"boolean") == 0){
		aux = "i1";
	}else if( strcmp(lowerType(str),"stringarray") == 0){
		aux = "i8**";
	}else if( strcmp(lowerType(str),"void") == 0){
		aux = "void";
	}else if( strcmp(lowerType(str),"String") == 0){
		aux = "i8*";
	}

	return aux;
}




char * lowerType (char * value){
	char * operador = NULL;

	if(strcmp(value,"stringarray") == 0 || strcmp(value,"StringArray") == 0 || strcmp(value,"String[]") == 0){
		operador = "String[]";
	}else if(strcmp(value,"int") == 0 || strcmp(value,"Int") == 0){
		operador = "int";
	}else if(strcmp(value,"double") == 0 || strcmp(value,"Double") == 0){
		operador = "double";
	}else if(strcmp(value,"bool") == 0 || strcmp(value,"Bool") == 0 || strcmp(value,"boolean") == 0){
		operador = "boolean";
	}else if(strcmp(value,"String") == 0 || strcmp(value,"string") == 0){
		operador = "String";
	}else if(strcmp(value,"Void") == 0 || strcmp(value,"void") == 0){
		operador = "void";
	}else if(strcmp(value,"If") == 0 || strcmp(value,"IfElse") == 0){
		operador = "if";
	}else if(strcmp(value,"While") == 0){
		operador = "while";
	}

	return operador;

}


char * generationOperation(char * value, char * type){
	char * operador = NULL;
	
	if( strcmp(value,"Add") == 0 && strcmp(type,"int") == 0 ){
		operador = "add";
	}else if(strcmp(value,"Add") == 0  && strcmp(type,"double") == 0 ){
		operador = "fadd";
	}else if( strcmp(value,"Sub") == 0 && strcmp(type,"int") == 0 ){
		operador = "sub";
	}else if(strcmp(value,"Sub") == 0 && strcmp(type,"double") == 0 ){
		operador = "fsub";
	}else if(strcmp(value,"Mul") == 0  && strcmp(type,"int") == 0){
		operador = "mul";
	}else if(strcmp(value,"Mul") == 0  && strcmp(type,"double") == 0){
		operador = "fmul";
	}else if(strcmp(value,"Div") == 0  && strcmp(type,"int") == 0){
		operador = "sdiv";
	}else if(strcmp(value,"Div") == 0  && strcmp(type,"double") == 0){
		operador = "fdiv";
	}else if(strcmp(value,"Mod") == 0  && strcmp(type,"int") == 0){
		operador = "srem";
	}else if(strcmp(value,"Mod") == 0  && strcmp(type,"double") == 0){
		operador = "frem";
	}else if(strcmp(value,"Eq") == 0 && strcmp(type,"double") == 0){
		operador = "oeq";
	}else if(strcmp(value,"Ge") == 0 && strcmp(type,"double") == 0){
		operador = "oge";
	}else if(strcmp(value,"Gt") == 0 && strcmp(type,"double") == 0){
		operador = "ogt";
	}else if(strcmp(value,"Le") == 0 && strcmp(type,"double") == 0){
		operador = "ole";
	}else if(strcmp(value,"Lt") == 0 && strcmp(type,"double") == 0){
		operador = "olt";
	}else if(strcmp(value,"Ne") == 0 && strcmp(type,"double") == 0){
		operador = "one";
	}else if(strcmp(value,"Eq") == 0 && strcmp(type,"int") == 0){
		operador = "eq";
	}else if(strcmp(value,"Ge") == 0 && strcmp(type,"int") == 0){
		operador = "sge";
	}else if(strcmp(value,"Gt") == 0 && strcmp(type,"int") == 0){
		operador = "sgt";
	}else if(strcmp(value,"Le") == 0 && strcmp(type,"int") == 0){
		operador = "sle";
	}else if(strcmp(value,"Lt") == 0 && strcmp(type,"int") == 0){
		operador = "slt";
	}else if(strcmp(value,"Ne") == 0 && strcmp(type,"int") == 0){
		operador = "ne";
	}else if(strcmp(value,"And") == 0){
		operador = "and";
	}else if(strcmp(value,"Or") == 0){
		operador = "or";
	}else if( strcmp(value,"Minus") == 0 || strcmp(value,"Plus") == 0){
		operador = "fneg";
	}

	return operador;
}