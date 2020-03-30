#include "structures.h"
#include "functions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

is_program* insert_program(char *id, is_metodos* metodos){

	is_program* ip=(is_program*)malloc(sizeof(is_program));

	ip->metodos=metodos;
	ip->classname=(char*)strdup(id);  ;

	return ip;
}


is_metodos* insert_metodos(char *evocation, is_fielddecl_list* ifl, is_methoddecl_list* iml,is_metodos* head){

	    is_metodos* im=(is_metodos*)malloc(sizeof(is_metodos));

        im->evocation=(char*)strdup(evocation);
        if(strcmp("Field",(char*)strdup(evocation)) == 0){
        	im->ifl=ifl;
        	im->imdl=NULL;
        }else if(strcmp("Method",(char*)strdup(evocation)) == 0){
        	im->imdl=iml;
        	im->ifl=NULL;
        }else{
        	return head;
        }

        im->next = head;


        return im;
}



is_fielddecl_list* insert_field(char *type , char *name, is_fielddecl_list* head){

		is_fielddecl_list* ifl=(is_fielddecl_list*)malloc(sizeof(is_fielddecl_list));

        ifl->type=(char*)strdup(type);
        ifl->name=(char*)strdup(name);
        ifl->next=head;

        return ifl;

}


is_methoddecl_list* insert_methoddecl(is_methodheader_list* header,is_methodbody_list* body){

		is_methoddecl_list* imdl=(is_methoddecl_list*)malloc(sizeof(is_methoddecl_list));

		imdl->imhl=header;
		imdl->imbl=body;

		return imdl;
}





is_methodheader_list* insert_methodheader(char *type , char *id, is_methodparams_list* impl){

		is_methodheader_list* imhl=(is_methodheader_list*)malloc(sizeof(is_methodheader_list));

        imhl->type=(char*)strdup(type);
        imhl->name=(char*)strdup(id);
        imhl->impl=impl;

        return imhl;
}


is_methodparams_list* insert_methodparams(char *type , char *name, is_methodparams_list* head){

		is_methodparams_list* impl=(is_methodparams_list*)malloc(sizeof(is_methodparams_list));

        impl->type=(char*)strdup(type);
        impl->name=(char*)strdup(name);
        impl->next=head;

        return impl;

}


is_methodbody_list* insert_methodbody(char *type, is_vardecl_list* vardecl , is_statment_list* statment, is_methodbody_list* body){

		is_methodbody_list* imbl=(is_methodbody_list*)malloc(sizeof(is_methodbody_list));

        imbl->type=(char*)strdup(type);
        if(strcmp("VarDecl",(char*)strdup(type)) == 0){
        	imbl->ivdl=vardecl;
        	imbl->statment=NULL;
        }else{
        	imbl->ivdl=NULL;
        	imbl->statment=statment;
        }

        imbl->next = body;


        return imbl;
}


is_vardecl_list* insert_vardecl(char *type , char *id, is_vardecl_list* vardecl){

		is_vardecl_list* ivdl=(is_vardecl_list*)malloc(sizeof(is_vardecl_list));

        ivdl->type=(char*)strdup(type);
        ivdl->name=(char*)strdup(id);
        ivdl->next=vardecl;

        return ivdl;
}



is_statment_list* insert_statment( char *name_function, is_statment_list* statment, is_expression_list* expr){

		is_statment_list* isl=(is_statment_list*)malloc(sizeof(is_statment_list));

        isl->name_function=(char*)strdup(name_function);
        isl->statment=statment;
        isl->expr=expr;

        return isl;

}


is_expression_list* insert_expr(char *operation, char *value, is_expression_list* expr1,  is_expression_list* expr2){

		is_expression_list* isl=(is_expression_list*)malloc(sizeof(is_expression_list));

        isl->operation=(char*)strdup(operation);
        isl->value=(char*)strdup(value);
       // expr1->next= expr2;
        isl->next=expr1;

        return isl;
}