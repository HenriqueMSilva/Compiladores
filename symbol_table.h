#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

//TABELA DE SIMBOLOS GLOBAL
typedef struct _hg{
	char *name;
	struct _teg *next;
} header_global;

//METODOS NA CLASSE
typedef struct _teg{
	char *name;
	param_list *param_list_type;
	char *type_return;
	struct _teg *next;
} table_element_global;

//LISTA DAS VARIAVEIS QUE CADA METODO RECEBE
typedef struct param{
	char *type_param;
	struct param *next;
} param_list;


//TABELA DE SIMBOLOS LOCAL
typedef struct _hl{
	char *name;
	table_element_local *tel;
	struct _hl *next;
} header_local;

//VARIAVEIS DO METODO
typedef struct _tel{
	char *name;
	char *type;
	char *param;
	struct _tel *next;
} table_element_local;




table_element *insert_el(char *str, char *t);
void show_table();
table_element *search_el(char *str);

#endif
