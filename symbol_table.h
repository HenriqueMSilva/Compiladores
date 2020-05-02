#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "structures.h"
//VARIAVEIS DO METODO
typedef struct _tel{
	char *name;
	char *type;
	int is_param;
	struct _tel *next;
} method_var;


//TABELA DE SIMBOLOS LOCAL
typedef struct _hl{
	char *name;
	method_var *tel;
	struct _hl *next;
} table_element_local;


//LISTA DAS VARIAVEIS QUE CADA METODO RECEBE
typedef struct param{
	char *type_param;
	struct param *next;
} param_node;

//METODOS NA CLASSE
typedef struct _teg{
	char *name;
	param_node *param_list;
	char *type_return;
	struct _teg *next;
} table_element_global;

//TABELA DE SIMBOLOS GLOBAL
typedef struct _hg{
	char *name;
	struct _teg *declarations;
} header_global;


header_global* insert_classname(char *str);

table_element_global * insert_el_fieldDec_global(is_fielddecl_list* ifdl, char * var_type);
table_element_global *insert_el_metodo_global(is_methodheader_list* imhl);

void tenta_inserir_fieldDec_na_tail_global(	table_element_global * newSymbol);
void tenta_inserir_metodo_na_tail_global(	table_element_global * newSymbol);
int assinatutas_iguais(table_element_global *newSymbol, table_element_global *aux);


table_element_local *insert_el_metodo_local(is_methodheader_list* imhl,is_methodbody_list* imbl);

void tenta_inserir_na_tail_local(	table_element_local * new_method);


char * recursao_expr(is_expression_list* expr, method_var* lista_do_metodo);
char * var_declarada(method_var * lista, char* str);
char * var_declarada_globalmente(char* str);

void show_tabela_global();
void show_table();

//table_element *search_el(char *str);

#endif
