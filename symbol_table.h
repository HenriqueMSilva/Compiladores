#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "structures.h"
//VARIAVEIS DO METODO
typedef struct _tel{
	char *name;
	char *type;
	char *param;
	struct _tel *next;
} table_element_local;


//TABELA DE SIMBOLOS LOCAL
typedef struct _hl{
	char *name;
	table_element_local *tel;
	struct _hl *next;
} header_local;


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
void tenta_inserir_na_tail_global(	table_element_global * newSymbol);

table_element_local *insert_el_local(char *str);

void show_tabela_global();
void show_table();

//table_element *search_el(char *str);

#endif
