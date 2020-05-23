#include "codegeneration.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

extern 	header_global 	*symtab_global;
extern	table_element_local 	*symtab_local;

int methodcounter = 0;
int registocounter = 1;

void generation(is_program* p){

	generation_metodos(p->metodos);
}


void generation_metodos(is_metodos* metodos){
	is_metodos* tmp;
	string_element 	*tabela_global = symtab_global->string_element;

	char * typeFunction;
	char * nameFunction;
	char * aux;
	int hasmain = 0, stringcounter = 0;

	//printf das variaveis globais
	for(tmp=metodos; tmp; tmp=tmp->next){
        if(tmp->ifl != NULL){
        	generation_field_list(tmp->ifl);
        }
    }

	//falta as aspas , nao as sei meter
	printf("@.str.int = constant [3 x i8] c\"%%d\\00\"\n");
	printf("@.str.double = constant [6 x i8] c\"%%.16e\\00\"\n");
	printf("@.str.true = constant [5 x i8] c\"true\\00\"\n");
	printf("@.str.false = constant [6 x i8] c\"false\\00\"\n");


	//print das strings 
	while(tabela_global != NULL){
		tabela_global->pos = stringcounter;
		printf("@.str.%d = constant [%d x i8] c\"%s\\00\"\n",tabela_global->pos,tabela_global->tamanho,tabela_global->string); // tamanho mais 1 para contar com o \n pelo o que parece
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
            if(strcmp(nameFunction,"main") == 0){
            	hasmain = 1;
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


    //verificar se existe main fiz uma aldrabice com um if e um contador, era para fazer com as tabelas mas nao as consegui fazer com que acede.se aqui
    if(hasmain == 0){
    	printf("define i32 @main(i32 %%.size,i8** %%.args){\n");
    	printf("ret i32 0\n}\n");
    }else{
    	printf("define i32 @main(i32 %%.size,i8** %%.args){\n");
		printf("call void @main.entry(i32 %%.size, i8** %%.args)\n");
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
	while(temp != NULL){

		if( strcmp(temp->type,"Double") == 0){
			aux = "0.0";
		}else if(strcmp(temp->type,"Int") == 0){
			aux = "0";
		}else if(strcmp(temp->type,"Bool") == 0){
			aux = "0";
		}
		printf("@%s = common global %s %s\n",temp->name, lowerType(temp->type) ,aux);
		temp = temp->next;
	}

}


//print dos metodos
void generation_method_list(is_methoddecl_list* imdl){

    is_methoddecl_list* tmp = imdl;

    //le parametros e nome da funçao
    generation_methodheader_list(tmp->imhl);
 
 	//le body
 	generation_methodbody_list(tmp->imbl);

 
}



void generation_methodheader_list(is_methodheader_list* imhl){

	is_methodparams_list* ast_param_list = imhl->impl;

	//print do tipo da funcao
	printf("define %s @",generation_tipo(lowerType(imhl->type)));

	//verificar se a funçao é a main
	if(strcmp(imhl->name,"main") == 0){
		printf("%s.entry(i32 %%.size.,",imhl->name);
	}else{ //verificar o counter??? como fazer counter
		printf("method_%s_%d(",imhl->name,methodcounter);
	}
	
	methodcounter++;
	
	while(ast_param_list != NULL){

		if( strcmp(ast_param_list->type,"Double") == 0){
			ast_param_list->generation_type = "double";
		}else if( strcmp(ast_param_list->type,"Int") == 0){
			ast_param_list->generation_type = "i32";
		}else if( strcmp(ast_param_list->type,"Bool") == 0){
			ast_param_list->generation_type = "i1";
		}else if( strcmp(ast_param_list->type,"StringArray") == 0){
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

	if(strcmp(nameFunction,"main") == 0){
		printf("%%size. = alloca i32\n");
		printf("store i32 %%.size., i32* %%size.\n");
	}

	while(asl != NULL){

		printf("%%%s = alloca %s\n",asl->name, asl->generation_type);
		printf("store %s %%.%s, %s* %%%s\n", asl->generation_type,asl->name,asl->generation_type,asl->name);

		asl = asl->next;
	}
}


void generation_methodbody_list(is_methodbody_list* imbl){

	is_methodbody_list* tmp;


	for(tmp=imbl; tmp; tmp=tmp->next){
        if(tmp->ivdl != NULL){
        	generation_vardecl_list(tmp->ivdl);
        }
	    if(tmp->statment != NULL){
	    	generation_statment_list(tmp->statment);
	    }
    }
}


void generation_vardecl_list(is_vardecl_list* ivdl){

	is_vardecl_list* temp = ivdl;

	while(temp != NULL){

		if( strcmp(temp->type,"Double") == 0){
			temp->generation_type = "double";
		}else if( strcmp(temp->type,"Int") == 0){
			temp->generation_type = "i32";
		}else if( strcmp(temp->type,"Bool") == 0){
			temp->generation_type = "i1";
		}else if( strcmp(temp->type,"StringArray") == 0){
			temp->generation_type = "i8**";
		}

		printf("%%%s = alloca %s\n",temp->name,temp->generation_type);
		temp = temp->next;
	}
}



void generation_statment_list(is_statment_list* statment){

	if(statment->expr != NULL){
		generation_expression(statment->expr);
	}
	

	
	if(strcmp(statment->name_function,"Return") == 0){
		//se for undef entao return; logo é void
		if(strcmp(statment->expr->tipo,"undef") != 0){
			printf("ret %s %%.%d\n",statment->expr->generation_type,statment->expr->registo_number);
		}
	}


	//ir para statmet1
	if(statment->statment1 != NULL ){
		generation_statment_list(statment->statment1);
	}

	//ir para statmet2
	if(statment->statment2 != NULL ){
		generation_statment_list(statment->statment2);
	}


}




void generation_expression(is_expression_list* expr){


	if(expr->expr1 != NULL ){
		generation_expression(expr->expr1 );
	}

	if(expr->expr2 != NULL ){
		generation_expression(expr->expr2 );
	}

	//printf("%s %s\n",expr->operation,expr->value);

	//se for ID retorna registo
	if( strcmp(expr->operation, "Id" ) == 0){

		expr->generation_type = generation_tipo(expr->tipo);
		expr->registo_number = registocounter;


		printf("%%.%d = load %s, %s* %%%s\n",registocounter,expr->generation_type,expr->generation_type,expr->value);
		registocounter++;

	}

	//adicionar a um registo o valor inteiro
	if(strcmp(expr->operation, "DecLit" ) == 0){

		expr->generation_type = generation_tipo(expr->tipo);
		expr->registo_number = registocounter;
		printf("%%.%d = add %s 0, %s\n",expr->registo_number,expr->generation_type,expr->value);
		registocounter++;
	}

	//adicionar a um registo o valor double
	if(strcmp(expr->operation, "RealLit" ) == 0){

		//REVER AINDA NAO ESTA BEM
		expr->generation_type = generation_tipo(expr->tipo);
		expr->registo_number = registocounter;
		printf("%%.%d = fadd  %s 0.000000, %s\n",expr->registo_number,expr->generation_type,expr->value);
		registocounter++;
	}

	//adicionar a um registo o valor bool
	if(strcmp(expr->operation, "BoolLit" ) == 0){

		expr->generation_type = generation_tipo(expr->tipo);
		expr->registo_number = registocounter;
		printf("%%.%d = or %s false, %s\n",expr->registo_number,expr->generation_type,expr->value);
		registocounter++;
	}


	/*if(	strcmp(expr->operation, "StrLit" ) == 0){

		//REVER AINDA NAO ESTA BEM
		expr->generation_type = generation_tipo(expr->tipo);
		expr->registo_number = registocounter;
		printf("%%.%d = or %s ?, %s\n",expr->registo_number,expr->generation_type,expr->value);
		registocounter++;
	}*/




	/*if((strcmp(expr->operation,"Call") == 0)){
		table_element_global* tabela_global = symtab_global->declarations;

		printf("%s %s\n",expr->value,expr->tipo);

		if(tabela_global != NULL){
			
			if(){

			}

			tabela_global = tabela_global->next;
		}
	}*/



	if( strcmp(expr->operation, "Assign" ) == 0 ){
		
		expr->generation_type = generation_tipo(expr->tipo);
		printf("store %s %%.%d, %s* %%%s\n",expr->generation_type,expr->expr1->registo_number,expr->generation_type,expr->value);
	
	}


	if((strcmp(expr->value,"Add") == 0)){
		/*if(expr->expr1 != NULL ){
			printf("%s %s\n",expr->expr1->value,expr->expr1->tipo);
		}

		if(expr->expr2 != NULL ){
			printf("%s %s\n",expr->expr2->value,expr->expr2->tipo);
		}*/
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