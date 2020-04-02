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


is_metodos* insert_metodos(char *evocation, is_fielddecl_list* ifl, is_methoddecl_list* iml, is_metodos* head){

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


is_statment_list*  insert_multiple_statement(char *name_function, is_expression_list* expr, is_statment_list* next_statment, is_statment_list* else_next_statment){

    is_statment_list* isl = insert_statment( name_function,  next_statment, expr);
    
    //if ExpA Statment
    if(else_next_statment == NULL){
        isl->statment2 = NULL;
    }else{
    //if ExpA Statment Else Statment
        isl->statment2 = else_next_statment;
    }


    if(strcmp("Statment",isl->name_function) == 0){
        if(next_statment != NULL){
            isl->num_statements++; 
        }

        if(else_next_statment != NULL){
            isl->num_statements += else_next_statment->num_statements; 
        }
    }else if(strcmp("Block",isl->name_function) == 0 && next_statment == NULL){
        return NULL;
    }else if(strcmp("Block",isl->name_function) == 0 && next_statment != NULL){
       isl->num_statements = next_statment->num_statements; 
    }else{
        isl->num_statements = 1; 
    }


    return isl;
}



is_statment_list* insert_statment( char *name_function, is_statment_list* statment, is_expression_list* expr){

		is_statment_list* isl=(is_statment_list*)malloc(sizeof(is_statment_list));

        isl->name_function=(char*)strdup(name_function);
        isl->statment1=statment;
        isl->statment2=NULL;
        isl->expr=expr;

        return isl;

}


is_expression_list* insert_expr(char *operation, char *value, is_expression_list* expr1,  is_expression_list* expr2){

		is_expression_list* isl=(is_expression_list*)malloc(sizeof(is_expression_list));

		

        isl->operation=(char*)strdup(operation);
        isl->value=(char*)strdup(value);
       	isl->expr1=expr1;
        isl->expr2=expr2;

        return isl;
}



void print_expr(is_expression_list* expr, int n){
    int i=0, apply=0;

    if(strcmp("Operacao",expr->operation) == 0){
        for(i=0;i<n;i++){
            printf(".");
        }
        printf("%s\n",expr->value);
    }else if(strcmp("ParseArgs",expr->operation) == 0 || strcmp("Call",expr->operation) == 0 || strcmp("Assign",expr->operation) == 0 || strcmp("Length",expr->operation) == 0){
        for(i=0;i<n;i++){
            printf(".");
        }
        printf("%s\n",expr->operation);
        for(i=0;i<n+2;i++){
            printf(".");
        }
        printf("Id(%s)\n",expr->value);

    }else if(strcmp("CallMore",expr->operation) == 0){
        apply = 1;
    }else{
        for(i=0;i<n;i++){
            printf(".");
        }
        printf("%s(%s)\n",expr->operation,expr->value);
    }

    if(apply == 0){
        n = n +2;
    }
    
    if(expr->expr1 != NULL){
        print_expr(expr->expr1,n);
    }
    if(expr->expr2 != NULL){
        print_expr(expr->expr2,n);
    }

}

int printNameFunction(is_statment_list* statment, int n){
    int i=0;

     if(strcmp("IfElse",statment->name_function) == 0){
        for(i=0;i<n;i++){
            printf(".");
        }
        printf("If\n");
        n = n+2;
    }else if(strcmp("Statment",statment->name_function) == 0  || strcmp("AssignStatment",statment->name_function) == 0 ||  strcmp("Call",statment->name_function) == 0) {
        // NAO FAZ NADA
    }else if(strcmp("Block",statment->name_function) == 0 ){
        if(statment->statment1 != NULL &&statment->statment1->num_statements > 1){
            for(i=0;i<n;i++){
                printf(".");
            }
            printf("%s\n",statment->name_function);
            n = n+2;
        }
    }else {
        for(i=0;i<n;i++){
            printf(".");
        }
        printf("%s\n",statment->name_function);
        n = n+2;
    }
    return n;
}

void funca_recursiva_statment(is_statment_list* statment, int n){
    int i = 0, entry=0;

    //printf("%s -> %d\n",statment->name_function,statment->num_statements);
    n = printNameFunction(statment,n);

    if(statment->expr != NULL){

        print_expr(statment->expr,n);
        
    }

    if(statment->statment1 != NULL){
        funca_recursiva_statment(statment->statment1, n);
    }else{
        if(strcmp("If",statment->name_function) == 0 ){
            for(i=0;i<n;i++){
                printf(".");
            }
            printf("Block\n");
            entry=1;
        }
    }

    if(statment->statment2 != NULL){
        funca_recursiva_statment(statment->statment2, n);
    }

    if(strcmp("If",statment->name_function) == 0 ){
        if(statment->statment1 == NULL && entry == 0){
            for(i=0;i<n;i++){
                printf(".");
            }
            printf("Block\n");
        }
        if(statment->statment2 == NULL && strcmp("While",statment->name_function) != 0){
            for(i=0;i<n;i++){
                printf(".");
            }
            printf("Block\n");
        }
        n = n+2;
    }else if(strcmp("While",statment->name_function) == 0){
        if(statment->statment1 == NULL){
            for(i=0;i<n;i++){
                printf(".");
            }
            printf("Block\n");
        }
    }

}

void print_tree(is_program* myprogram){
    char  *auxiliar = "";
    is_metodos* metodos= myprogram->metodos;
    is_fielddecl_list* field;
    is_methoddecl_list* method;
    is_methodparams_list* params;
    is_methodbody_list* body;
    is_vardecl_list* vardecl;
    is_statment_list* statment;

    printf("Program\n");
    printf("..Id(%s)\n",myprogram->classname);
    while(metodos != NULL){
        if(strcmp("Field",metodos->evocation) == 0){
            field = metodos->ifl;
            while(field != NULL){
                printf("..FieldDecl\n");
                if(strcmp("",field->type) != 0){
                    printf("....%s\n",field->type);
                    auxiliar = field->type; 
                }else{
                    printf("....%s\n",auxiliar);
                }
                printf("....Id(%s)\n",field->name);
                field = field->next;
            }
        }else{
            printf("..MethodDecl\n");
            method = metodos->imdl;
            printf("....MethodHeader\n");
            printf("......%s\n",method->imhl->type);
            printf("......Id(%s)\n",method->imhl->name);
            params = method->imhl->impl;
            printf("......MethodParams\n");
            while(params != NULL){
                printf("........ParamDecl\n");
                printf("..........%s\n",params->type);
                printf("..........Id(%s)\n",params->name);
                params = params->next;
            }
            printf("....MethodBody\n");
            body = metodos->imdl->imbl;
            while(body != NULL){
                // VARDEC
                if(strcmp("VarDecl",body->type) == 0){
                    vardecl = body->ivdl;
                    while(vardecl != NULL){
                        printf("......VarDecl\n");
                        
                        if(strcmp("",vardecl->type) != 0){
                            printf("........%s\n",vardecl->type);
                            auxiliar = vardecl->type; 
                        }else{
                            printf("........%s\n",auxiliar);
                        }
                        

                        printf("........Id(%s)\n",vardecl->name);
                        vardecl = vardecl->next;
                    }
                }else{
                    // STATEMENTS
                    statment = body->statment;
                    if(statment != NULL){
                        if(strcmp("Print",statment->name_function) == 0 || strcmp("Return",statment->name_function) == 0){
                            
                            printf("......%s\n",statment->name_function);
                            if(statment->expr != NULL){
                                print_expr(statment->expr,8);
                            }

                        }else if(strcmp("If",statment->name_function) == 0 || strcmp("While",statment->name_function) == 0 || strcmp("IfElse",statment->name_function) == 0 || strcmp("Statment",statment->name_function) == 0 || strcmp("Block",statment->name_function) == 0){
                            
                            funca_recursiva_statment(statment,6);
                            
                        }else{

                            //CASOS ESPECIAIS TIPO CALL / ASSIGN / PARSEARGS
                            if(statment->expr != NULL){
                                print_expr(statment->expr,6);
                            } 
                        }
                    }
                    
                }

                body = body->next;
            }
        }
        metodos= metodos->next;
    }   
}