#ifndef CODEGENERATION_H   
#define CODEGENERATION_H
#include "structures.h"
#include "symbol_table.h"
#include "structures.h"


int verifica_variavel(is_methodheader_list* imhl,is_expression_list* expr);
char * lowerType(char * str);
char * novo_formato_int(char * str);
void generation(is_program* p);
void generation_metodos(is_metodos* metodos);
void generation_field_list(is_fielddecl_list* ifl);
void generation_method_list(is_methoddecl_list* imdl);
void generation_methodheader_list(is_methodheader_list* imhl);
void generation_param_list(is_methodparams_list* impl,char* nameFunction);
void generation_methodbody_list(is_methodbody_list* imbl,is_methodheader_list* imhl);
void generation_vardecl_list(is_vardecl_list* ivdl,is_methodheader_list* imhl);
void generation_statment_list(is_statment_list* ivdl,is_methodheader_list* imhl);
void generation_expression(is_expression_list* expr,is_methodheader_list* imhl);
char * generation_tipo(char * str);
char * generationOperation(char * value, char * type);
int assinaturas_iguais_local(is_methodheader_list* imhl,table_element_local *tabela_local);



#endif