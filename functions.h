#include "structures.h"

is_program* insert_program(char *id,is_metodos* metodos);
is_metodos* insert_metodos(char *evocation, is_fielddecl_list* ifl, is_methoddecl_list* iml,is_metodos* head);
is_fielddecl_list* insert_field(char *type , char *name, is_fielddecl_list* ifl);
is_methoddecl_list* insert_methoddecl(is_methodheader_list* header,is_methodbody_list* body);
is_methodheader_list* insert_methodheader(char *type , char *id, is_methodparams_list* impl);
is_methodparams_list* insert_methodparams(char *type , char *name, is_methodparams_list* head);
is_methodbody_list* insert_methodbody(char *type, is_vardecl_list* vardecl , is_statment_list* statment, is_methodbody_list* body);
is_vardecl_list* insert_vardecl(char *type , char *id, is_vardecl_list* vardecl);
is_statment_list*  insert_multiple_statement(char *name_function, is_expression_list* expr, is_statment_list* next_statment, is_statment_list* else_next_statment, int num_statements);
is_statment_list* insert_statment( char *name_function, is_statment_list* statment, is_expression_list* expr);
is_expression_list* insert_expr(char *operation, char *value, is_expression_list* expr1,  is_expression_list* expr2);
void print_tree(is_program* myprogram);