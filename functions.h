#include "structures.h"

is_program* insert_program(char *id,is_metodos* metodos, int linha, int coluna);
is_metodos* insert_metodos(char *evocation, is_fielddecl_list* ifl, is_methoddecl_list* iml,is_metodos* head);
is_fielddecl_list* insert_field(char *type , char *name, is_fielddecl_list* ifl, int linha, int coluna);
is_methoddecl_list* insert_methoddecl(is_methodheader_list* header,is_methodbody_list* body);
is_methodheader_list* insert_methodheader(char *type , char *id, is_methodparams_list* impl, int linha, int coluna);
is_methodparams_list* insert_methodparams(char *type , char *name, is_methodparams_list* head,int linha, int coluna);
is_methodbody_list* insert_methodbody(char *type, is_vardecl_list* vardecl , is_statment_list* statment, is_methodbody_list* body);
is_vardecl_list* insert_vardecl(char *type , char *id, is_vardecl_list* vardecl, int linha, int coluna);
is_statment_list*  insert_multiple_statement(char *name_function, is_expression_list* expr, is_statment_list* next_statment, is_statment_list* else_next_statment);
is_statment_list* insert_statment( char *name_function, is_statment_list* statment, is_expression_list* expr);
is_expression_list* insert_expr(char *operation, char *value, is_expression_list* expr1,  is_expression_list* expr2, int linha, int coluna, int linha2, int coluna2);
void print_tree(is_program* myprogram);
void free_tree(is_program* myprogram);
void free_is_metodos(is_metodos* metodos);
void free_is_fielddecl_list(is_fielddecl_list* ifl);
void free_is_methoddecl_list(is_methoddecl_list* imdl);
void free_is_methodheader_list(is_methodheader_list* imhl);
void free_is_methodparams_list(is_methodparams_list* impl);
void free_is_methodbody_list(is_methodbody_list* imbl);
void free_is_vardecl_list(is_vardecl_list* ivdl);
void free_is_statment_list(is_statment_list* statment);
void free_is_expression_list(is_expression_list* expr);