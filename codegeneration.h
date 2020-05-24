#ifndef CODEGENERATION_H   
#define CODEGENERATION_H
#include "structures.h"
#include "symbol_table.h"
#include "structures.h"

char * lowerType(char * str);
void generation(is_program* p);
void generation_metodos(is_metodos* metodos);
void generation_field_list(is_fielddecl_list* ifl);
void generation_method_list(is_methoddecl_list* imdl);
void generation_methodheader_list(is_methodheader_list* imhl);
void generation_param_list(is_methodparams_list* impl,char* nameFunction);
void generation_methodbody_list(is_methodbody_list* imbl);
void generation_vardecl_list(is_vardecl_list* ivdl);
void generation_statment_list(is_statment_list* ivdl);
void generation_expression(is_expression_list* expr);
char * generation_tipo(char * str);
char * generationOperation(char * value, char * type);


#endif