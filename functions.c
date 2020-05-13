#include "structures.h"
#include "functions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

is_program* insert_program(char *id, is_metodos* metodos, int linha, int coluna){

	is_program* ip=(is_program*)malloc(sizeof(is_program));

    ip->metodos=metodos;
    
    ip->linha=linha;
	ip->coluna=coluna;

	ip->classname=(char*)strdup(id);

	return ip;
}


is_metodos* insert_metodos(char *evocation, is_fielddecl_list* ifl, is_methoddecl_list* iml, is_metodos* head){

	    is_metodos* im=(is_metodos*)malloc(sizeof(is_metodos));

        im->evocation=(char*)strdup(evocation);
        if(strcmp("Field",im->evocation) == 0){
        	im->ifl=ifl;
        	im->imdl=NULL;
        }else if(strcmp("Method",im->evocation) == 0){
        	im->imdl=iml;
        	im->ifl=NULL;
        }else{
        	return head;
        }

        im->next = head;


        return im;
}



is_fielddecl_list* insert_field(char *type , char *name, is_fielddecl_list* head, int linha , int coluna){

		is_fielddecl_list* ifl=(is_fielddecl_list*)malloc(sizeof(is_fielddecl_list));

        ifl->type=(char*)strdup(type);
        ifl->name=(char*)strdup(name);

        ifl->linha=linha;
        ifl->coluna=coluna;

        ifl->next=head;

        return ifl;

}


is_methoddecl_list* insert_methoddecl(is_methodheader_list* header,is_methodbody_list* body){

		is_methoddecl_list* imdl=(is_methoddecl_list*)malloc(sizeof(is_methoddecl_list));

		imdl->imhl=header;
		imdl->imbl=body;

		return imdl;
}





is_methodheader_list* insert_methodheader(char *type , char *id, is_methodparams_list* impl, int linha, int coluna){

		is_methodheader_list* imhl=(is_methodheader_list*)malloc(sizeof(is_methodheader_list));

        imhl->type=(char*)strdup(type);
        imhl->name=(char*)strdup(id);
        imhl->anotar_body = 1;

        imhl->linha = linha;
        imhl->coluna = coluna;

        imhl->impl=impl;

        return imhl;
}


is_methodparams_list* insert_methodparams(char *type , char *name, is_methodparams_list* head, int linha, int coluna){

		is_methodparams_list* impl=(is_methodparams_list*)malloc(sizeof(is_methodparams_list));

        impl->type=(char*)strdup(type);
        impl->name=(char*)strdup(name);
        
        impl->linha=linha;
        impl->coluna=coluna;

        impl->next=head;

        return impl;

}


is_methodbody_list* insert_methodbody(char *type, is_vardecl_list* vardecl , is_statment_list* statment, is_methodbody_list* body){

        //ver se o st é um block
        if(statment != NULL && strcmp("Block", statment->name_function ) == 0 && statment->num_statements == 0){
        
            is_statment_list* to_free = statment;    
            statment = statment->statment1;

            if(to_free->name_function != NULL){
                free(to_free->name_function);
                to_free->name_function = NULL;
            }
                
            free(to_free);
            to_free = NULL;
        }





		is_methodbody_list* imbl=(is_methodbody_list*)malloc(sizeof(is_methodbody_list));

        imbl->type=(char*)strdup(type);
        if(strcmp("VarDecl",imbl->type) == 0){
        	imbl->ivdl=vardecl;
        	imbl->statment=NULL;
        }else{
        	imbl->ivdl=NULL;
        	imbl->statment=statment;
        }

        imbl->next = body;

        //ver se st e body ta a null-> return NULL
        //tinha um statment que era so {}
        if(strcmp("Statment",imbl->type) == 0 && imbl->statment == NULL && body == NULL){
            is_methodbody_list* to_free = imbl;    
            imbl = NULL ;

            if(to_free->type != NULL){
                free(to_free->type);
                to_free->type = NULL;
            }
        
            free(to_free);
            to_free = NULL;

        }

        return imbl;
}


is_vardecl_list* insert_vardecl(char *type , char *id, is_vardecl_list* vardecl,int linha, int coluna){

		is_vardecl_list* ivdl=(is_vardecl_list*)malloc(sizeof(is_vardecl_list));

        ivdl->type=(char*)strdup(type);
        ivdl->name=(char*)strdup(id);

        ivdl->linha=linha;
        ivdl->coluna=coluna;

        ivdl->next=vardecl;


        return ivdl;
}


is_statment_list*  insert_multiple_statement(char *name_function, is_expression_list* expr, is_statment_list* next_statment, is_statment_list* else_next_statment){

    is_statment_list* isl = insert_statment( name_function,  next_statment, expr);
    is_statment_list* to_free = isl;


    //if ExpA Statment
    if(else_next_statment == NULL){
        isl->statment2 = NULL;
    
    }else{
    //if ExpA Statment Else Statment
        isl->statment2 = else_next_statment;
    }



    //calcula o numero de statments que estao daqui para baixo (incluindo o proprio node)
    if( isl->statment1 != NULL ){
        if(strcmp("Block",isl->statment1->name_function) == 0 ){
            if(isl->statment1->num_statements == 0){
                // st1 = Block {}
                isl->num_statements += 0;
            }else{
                // st1 = Block {Alguma coisa}
                isl->num_statements += 1;
            }

        }else if(strcmp("While",isl->statment1->name_function) == 0 || strcmp("IfElse",isl->statment1->name_function) == 0 || strcmp("If",isl->statment1->name_function) == 0){ 
            isl->num_statements += 1;
       
        }else{

            isl->num_statements += isl->statment1->num_statements;
        }
    }




    if( isl->statment2 != NULL ){
        if(strcmp("Block",isl->statment2->name_function) == 0){
            //isl->num_statements += 1;

            if(isl->statment2->num_statements == 0){
                // st2 = Block {}
                isl->num_statements += 0;
            }else{
                // st2 = Block {Alguma coisa}
                isl->num_statements += 1;
            }


        }else if(strcmp("While",isl->statment2->name_function) == 0 || strcmp("IfElse",isl->statment2->name_function) == 0 || strcmp("If",isl->statment2->name_function) == 0){ 
            isl->num_statements += 1;
       
        }else{
            isl->num_statements += isl->statment2->num_statements;
        }
        
    }


    //aumentamos 1 statment se nao estivermos em nodes "Block" ou em "Statment"
    if(  strcmp("While",isl->name_function) != 0 && strcmp("IfElse",isl->name_function) != 0  && strcmp("If",isl->name_function) != 0  && strcmp("Block",isl->name_function) != 0  && strcmp("Statment",isl->name_function) != 0 ){  
        isl->num_statements += 1;
    }









    //APAGO OS BLOCK COM 0
    //1) So criamos o node "Block" se ele tiver Statments suficientes
    if( strcmp("Block",isl->name_function) == 0 && isl->num_statements == 1 ){
        //nao vou criar o node "Block"
        free(isl->name_function);
        free(isl);
        isl = next_statment;
    }


    //2) Nao estou nem num if, nem num while e tenho um block com 0 sttments ha minha frente 
    if(  strcmp("If",isl->name_function) != 0 && strcmp("While",isl->name_function) != 0 && strcmp("IfElse",isl->name_function) != 0 ){


        if( isl->statment1 != NULL && strcmp("Block",isl->statment1->name_function) == 0 && isl->statment1->num_statements == 0  ){

            //vou apagar o block
            to_free =  isl->statment1;
        
            isl->statment1 = NULL;
        
            free(to_free->name_function);
            free(to_free);

        }

        if( isl->statment2 != NULL && strcmp("Block",isl->statment2->name_function) == 0 && isl->statment2->num_statements == 0  ){

            //vou apagar o block
            to_free =  isl->statment2;
        
            isl->statment2 = NULL;
        
            free(to_free->name_function);
            free(to_free);

          }

    }

    //3) if(Expr); ou while(Expr); preciso de adicionar 1 block 
    if( ( strcmp("If",isl->name_function) == 0 || strcmp("While",isl->name_function) == 0 || strcmp("IfElse",isl->name_function) == 0 ) && isl->statment1 == NULL ) {
        isl->statment1 = insert_statment( "Block",  NULL, NULL);
    }

    //4) else; preciso de adicionar block
    if( strcmp("IfElse", isl->name_function) == 0 && isl->statment2 == NULL){
        isl->statment2 = insert_statment( "Block",  NULL, NULL);
    }



   //5) if(Expr) St ;    preciso de adicionar block 2
    if( strcmp("If", isl->name_function) == 0 ){
        isl->statment2 = insert_statment( "Block",  NULL, NULL);
    }
    


    return isl;
}



is_statment_list* insert_statment( char *name_function, is_statment_list* statment, is_expression_list* expr){

		is_statment_list* isl=(is_statment_list*)malloc(sizeof(is_statment_list));

        isl->name_function=(char*)strdup(name_function);
        isl->statment1=statment;
        isl->statment2=NULL;
        isl->expr=expr;
        isl->num_statements=0;

        return isl;

}


is_expression_list* insert_expr(char *operation, char *value, is_expression_list* expr1,  is_expression_list* expr2, int linha, int coluna){

		is_expression_list* isl=(is_expression_list*)malloc(sizeof(is_expression_list));

		

        isl->operation=(char*)strdup(operation);
        isl->value = (char*)strdup(value);
        isl->tipo = NULL;

        isl->linha = linha;
        isl->coluna = coluna;

        isl->expr1 = expr1;
        isl->expr2 = expr2;

        return isl;
}

void printCallMore(is_expression_list* expr){
    if(strcmp(expr->tipo,"stringarray") == 0){
        printf("String[]");
    }else if(strcmp(expr->tipo,"bool") == 0){
        printf("boolean");
    }else{
        printf("%s",expr->tipo);
    }
    
    if(expr->expr2 != NULL){
         printf(",");
        printCallMore(expr->expr2);
    }
}

void print_expr(is_expression_list* expr, int n){
    int i=0, apply=0;

    if(strcmp("Operacao",expr->operation) == 0){
        for(i=0;i<n;i++){
            printf(".");
        }
        printf("%s",expr->value);
        
        //evita variaveis como o shift e se estiverem vazias
        if( (expr->tipo != NULL)  ){

            //havia variaveis que estavam como bool nao podiamos mudar na raiz
            if( strcmp(expr->tipo,"bool") == 0){
                printf(" - boolean");
            }else{
                printf(" - %s",expr->tipo);
            }
        }

        printf("\n");

    }else if(strcmp("ParseArgs",expr->operation) == 0 || strcmp("Call",expr->operation) == 0 || strcmp("Assign",expr->operation) == 0 || strcmp("Length",expr->operation) == 0){
        for(i=0;i<n;i++){
            printf(".");
        }
        printf("%s",expr->operation);

        if((expr->tipo != NULL)){

            if((strcmp("Length",expr->operation) == 0 || strcmp("ParseArgs",expr->operation) == 0)){
                
                if(strcmp(expr->tipo,"undef") == 0){
                    printf(" - undef");
                }else{
                    printf(" - int");

                }


                /*if(strcmp(expr->tipo,"String[]") == 0){
                    printf(" - int");
                }else{
                    printf(" - undef");
                }*/

            }else if(strcmp(expr->tipo,"stringarray") == 0){
                printf(" - String[]");
            }else if(strcmp(expr->tipo,"bool") == 0){
                printf(" - boolean");
            }else{
                printf(" - %s",expr->tipo);
            }
            
        }

        printf("\n");
        for(i=0;i<n+2;i++){
            printf(".");
        }

        printf("Id(%s)",expr->value);

        

        //printar a frente do ID os parametros, a funcao tem de ser call
        if(strcmp("Call",expr->operation) == 0){
            
            if(expr->expr1 != NULL){
        
                //RTE 
                if(expr->tipo != NULL){
        
                    if(strcmp(expr->tipo,"undef") == 0){
                    
                        printf(" - undef");
                    
                    }else{
                        printf(" - (");
                        printCallMore(expr->expr1);
                        printf(")");
                    }
                
                }   

            }else{
                 //RTE 
                if(expr->tipo != NULL){
                    if(strcmp(expr->tipo,"undef") == 0){
                    
                        printf(" - undef");
                    
                    }else{
                        printf(" - ()");
                    }

                }
            }
        //caso nao seja call e um ID normal 
        }else{
            if((expr->tipo != NULL)){

                //necessario devido a problemas de definicao
                if(strcmp(expr->tipo,"stringarray") == 0){
                    printf(" - String[]");
                }else if(strcmp(expr->tipo,"bool") == 0){
                    printf(" - boolean");
                }else if(strcmp(expr->tipo,"undef") == 0){
                    printf(" - undef");
                }else{
                    printf(" - %s",expr->tipo);
                }
            
            }

        }

        printf("\n");

    }else if(strcmp("CallMore",expr->operation) == 0){
        apply = 1;
    }else{
        for(i=0;i<n;i++){
            printf(".");
        }
        printf("%s(%s)",expr->operation, expr->value);

        if( (expr->tipo != NULL)  ){

                if(strcmp(expr->tipo,"stringarray") == 0){
                    printf(" - String[]");
                }else if(strcmp(expr->tipo,"bool") == 0){
                    printf(" - boolean");
                }else{
                    printf(" - %s",expr->tipo);
                }
        }
        
        printf("\n");
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
    }else if(strcmp("ParseArgsStatment",statment->name_function) == 0  || strcmp("Statment",statment->name_function) == 0  || strcmp("AssignStatment",statment->name_function) == 0 ||  strcmp("Call",statment->name_function) == 0) {
        // NAO FAZ NADA
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
    n = printNameFunction(statment,n);

    if(statment->expr != NULL){

        print_expr(statment->expr,n);
        
    }


    if(statment->statment1 != NULL){
        funca_recursiva_statment(statment->statment1, n);
    }

    if(statment->statment2 != NULL){
        funca_recursiva_statment(statment->statment2, n);
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

                        if(strcmp("Print",statment->name_function) == 0 || strcmp("Return",statment->name_function) == 0 ){
                            
                            printf("......%s\n",statment->name_function);
                            if(statment->expr != NULL){
                                print_expr(statment->expr,8);
                            }

                        }else if(strcmp("If",statment->name_function) == 0 || strcmp("While",statment->name_function) == 0 || strcmp("IfElse",statment->name_function) == 0 || strcmp("Statment",statment->name_function) == 0 || strcmp("Block",statment->name_function) == 0 ){
                            
                            funca_recursiva_statment(statment,6);
                            
                        }else{

                            //CASOS ESPECIAIS TIPO CALL / ASSIGN / PARSEARGSSTATMENT
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



void free_is_expression_list(is_expression_list* expr){
    if(expr != NULL){

        if(expr->expr1){
            free_is_expression_list(expr->expr1);
        }


        if(expr->expr2){
            free_is_expression_list(expr->expr2);
        }

        if(expr->operation != NULL){
            free(expr->operation);
            expr->operation = NULL;
        }

        if(expr->value != NULL){
            free(expr->value);
            expr->value = NULL;
        }

        free(expr);
        expr = NULL;
    }

}

void free_is_statment_list(is_statment_list* statment){
    if(statment != NULL){

        if(statment->expr != NULL){
            free_is_expression_list(statment->expr);
        }

        if(statment->statment1 != NULL){
            free_is_statment_list(statment->statment1);
        }

        if(statment->statment2 != NULL){
            free_is_statment_list(statment->statment2);
        }

        if(statment->name_function != NULL){
            free(statment->name_function);
            statment->name_function = NULL;
        }

        free(statment);
        statment = NULL;
    }

}


void free_is_vardecl_list(is_vardecl_list* ivdl){
    if(ivdl != NULL){

        if(ivdl->next != NULL){
            free_is_vardecl_list(ivdl->next);        
        }


        if(ivdl->type != NULL){
            free(ivdl->type);
            ivdl->type = NULL;
        }

        if(ivdl->name != NULL){
            free(ivdl->name);
            ivdl->name = NULL;
        }

        free(ivdl);
        ivdl = NULL;
    }
}


void free_is_methodbody_list(is_methodbody_list* imbl){
    if(imbl != NULL){

        if(imbl->ivdl != NULL){
            free_is_vardecl_list(imbl->ivdl);     
        }

        if(imbl->statment!= NULL){
            free_is_statment_list(imbl->statment);
        }

        if(imbl->next != NULL){
            free_is_methodbody_list(imbl->next);
        }

        if(imbl->type != NULL){
            free(imbl->type);
            imbl->type = NULL;
        }

        free(imbl);
        imbl = NULL;    
    }

}



void free_is_methodparams_list(is_methodparams_list* impl){
    if(impl != NULL){

        if(impl->next){
            free_is_methodparams_list(impl->next);
        }

        if(impl->type != NULL){
            free(impl->type);
            impl->type = NULL;
        }


        if(impl->name != NULL){
            free(impl->name);
            impl->name = NULL;
        }

        free(impl);
        impl = NULL;
    }

}


void free_is_methodheader_list(is_methodheader_list* imhl){
    if(imhl != NULL){

        if(imhl->impl != NULL){
            free_is_methodparams_list(imhl->impl);
        }    

        if(imhl->type != NULL){
            free(imhl->type);
            imhl->type = NULL;
        }

        if(imhl->name != NULL){
            free(imhl->name);
            imhl->name = NULL;
        }

        free(imhl);
        imhl = NULL;
    }

}

void free_is_methoddecl_list(is_methoddecl_list* imdl){
    if(imdl != NULL){

        //method header
        if(imdl->imhl != NULL ){
            free_is_methodheader_list(imdl->imhl);
        }

        //method body
        if(imdl->imbl != NULL ){
            free_is_methodbody_list(imdl->imbl);
        }
    
        free(imdl);
        imdl = NULL;
    }

}            


void free_is_fielddecl_list(is_fielddecl_list* ifl){
    if(ifl != NULL){

        if(ifl->next != NULL){
            free_is_fielddecl_list(ifl->next);
        }


        if(ifl->type != NULL){
            free(ifl->type);
            ifl->type = NULL;
        }

        if(ifl->name != NULL){
            free(ifl->name);
            ifl->name = NULL;
        }

        free(ifl);
        ifl = NULL;
    }
}



void free_is_metodos(is_metodos* metodos){

        if(metodos != NULL){
     
            if(metodos->next != NULL){
                free_is_metodos(metodos->next);            
            }

            if(metodos->ifl != NULL){
                free_is_fielddecl_list(metodos->ifl);            
            }

            if(metodos->imdl != NULL){
                free_is_methoddecl_list(metodos->imdl);            
            }

            if(metodos->evocation != NULL){
                free(metodos->evocation);
                metodos->evocation = NULL;
            }

            free(metodos);
            metodos = NULL;
        }
    
}


void free_tree(is_program* myprogram){
    if(myprogram != NULL){

        if(myprogram->metodos != NULL){
            free_is_metodos(myprogram->metodos);
        }
        
        if(myprogram->classname != NULL){
            free(myprogram->classname);
        }

        free(myprogram);
        myprogram = NULL;
    }
        
}