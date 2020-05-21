#include "codegeneration.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int methodcounter = 0;

void generation(is_program* p){

	generation_metodos(p->metodos);
}


void generation_metodos(is_metodos* metodos){
	is_metodos* tmp;

	for(tmp=metodos; tmp; tmp=tmp->next){
        if(tmp->ifl != NULL){
        	generation_field_list(tmp->ifl);
        }
    }

	//falta as aspas , nao as sei meter
	printf("@.str.int = constant [3 x i8] c""""%%d\\00""""\n");
	printf("@.str.double = constant [6 x i8] c""%%.16e\\00""\n");
	printf("@.str.true = constant [5 x i8] c""true\\00""\n");
	printf("@.str.false = constant [6 x i8] c""false\\00""\n");

	// \n so se encontrar mos nas strings
	//printf("@.str.0 = constant [2 x i8]\n");	

	for(tmp=metodos; tmp; tmp=tmp->next){
        if(tmp->imdl != NULL){
            generation_method_list(tmp->imdl);
        }
    }

}


//print de variaveis globais
void generation_field_list(is_fielddecl_list* ifl){

	is_fielddecl_list* temp = ifl;
	char * aux;
	while(temp != NULL){

		if( strcmp(temp->type,"Double") == 0){
			aux = "0.0";
		}else if(strcmp(temp->type,"Int") == 0){
			aux = "0";
		}else if(strcmp(temp->type,"Bool") == 0){
			aux = "i1"; //o joda e o miguel meteram assim mas not sure
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
 	//TODO
}



void generation_methodheader_list(is_methodheader_list* imhl){

	is_methodparams_list* ast_param_list = imhl->impl;
	char * type = NULL;

	//print do tipo da funcao
	printf("define %s @",lowerType(imhl->type));

	//verificar se a funçao é a main
	if(strcmp(imhl->name,"main") == 0){
		printf("%s(",imhl->name);
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


	generation_param_list(imhl->impl);

}


void generation_param_list(is_methodparams_list* impl){

	is_methodparams_list* asl = impl;

	while(asl != NULL){

		printf("%%%s = alloca %s\n",asl->name,asl->generation_type);
		printf("store %s %%.%s, %s* %%%s\n", asl->generation_type,asl->name,asl->generation_type,asl->name);

		asl = asl->next;
	}
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