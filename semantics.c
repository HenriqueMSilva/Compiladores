#include "structures.h"
#include "semantics.h"
#include "symbol_table.h"
#include <stdio.h>

int check_program(is_program* p) {
    int errorcount=0;

    insert_classname(p->classname);
    errorcount = check_metodos(p->metodos);
    return errorcount;
}

int check_metodos(is_metodos* metodos){
    int errorcount=0;
    is_metodos* tmp;
    
    for(tmp=metodos; tmp; tmp=tmp->next){
        if(tmp->ifl != NULL){
            errorcount+=check_field_list(tmp->ifl);
        }
        if(tmp->imdl != NULL){
            errorcount+=check_method_list(tmp->imdl);
        }
    }
    return errorcount;
}

int check_field_list(is_fielddecl_list* ifl ) {

    //table_element_global* newel = insert_el_fieldDec_global(ifl, ifl->type);
    insert_el_fieldDec_global(ifl, ifl->type);

    /*if(newel==NULL) {
        printf("Symbol %s already defined!\n", ifl->name);
        return 1;
    }*/

    return 0;
}

int check_method_list(is_methoddecl_list* imdl) {
    int errorcount=0;
    is_methoddecl_list* tmp = imdl;

    //e sempre diferente de null
    if(tmp->imhl != NULL){
        errorcount+=check_methodheader_list(tmp->imhl);
    }    
    //o body pode ser null
    if(tmp->imbl != NULL){
        errorcount+=check_methodbody_list(tmp->imhl, tmp->imbl);
    }

    return errorcount;
}



int check_methodheader_list(is_methodheader_list* imhl) {
    table_element_global* newel = insert_el_metodo_global(imhl);

    if(newel==NULL) {
        printf("Symbol %s already defined!\n", imhl->name);
        return 1;
    }
    return 0;
}

int check_methodbody_list(is_methodheader_list* imhl, is_methodbody_list* imbl){
    insert_el_metodo_local(imhl, imbl);
    
    return 0;
}

/*int check_double_dec(is_double_dec* idd) {
    table_element* newel=insert_el(idd->id, doub);

    if(newel==NULL) {
        printf("Symbol %s already defined!\n", idd->id);
        return 1;
    }
    return 0;
}

int check_statement_list(is_statement_list* isl) {
    int errorcount=0;
    is_statement_list* tmp;

    for(tmp=isl; tmp; tmp=tmp->next)
        errorcount+=check_statement(tmp->val);
    return errorcount;
}


int check_statement(is_statement* is) {
    switch(is->disc_d) {
        case d_write: return check_write_statement(is->data_statement.u_write_statement);    
    }
}

int check_write_statement(is_write_statement* iws) {
    table_element* aux=search_el(iws->id);

    if(aux==NULL) {
        printf("Symbol %s not declared!\n", iws->id);
        return 1;
    }
    return 0;
}*/



