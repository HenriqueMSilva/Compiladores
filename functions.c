#include "structures.h"
#include "functions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

is_program* insert_program(is_metodos* metodos){

	is_program* ip=(is_program*)malloc(sizeof(is_program));

	ip->vlist=ivl;
	ip->slist=isl;

	return ip;
}


is_metodos* insert_metodos(is_fieldecl_list* ifl, is_methoddecl_list* iml, char type){

}





is_fielddecl_list* insert_field(type , id){

}


is_methoddecl_list* insert_method(header, body){

}





is_methodheader_list* insert_methodheader(type , ID, MethodParams){

}



is_methodparams_list* insert_methodparams( paramedcl){

}


is_paramedcl_list* insert_paramedcl( type ou stringarray , id){

}





/*is_methodbody_list* insert_methodbody(){

}*/