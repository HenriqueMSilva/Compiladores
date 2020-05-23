#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "structures.h"

//STRING ELEMENTS
typedef struct _sel{
	char *string;
	int tamanho;
	int pos;
	struct _sel *next;
} string_element;


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
	struct _sel *string_element;
	struct _teg *declarations;
} header_global;


header_global* insert_classname(char *str);

table_element_global * insert_el_fieldDec_global(is_fielddecl_list* ifdl, char * var_type);
table_element_global *insert_el_metodo_global(is_methodheader_list* imhl);

void tenta_inserir_fieldDec_na_tail_global(	table_element_global * newSymbol, is_fielddecl_list* ifdl);
int tenta_inserir_metodo_na_tail_global(	table_element_global * newSymbol);


table_element_local *insert_el_metodo_local(is_methodheader_list* imhl,is_methodbody_list* imbl);

void tenta_inserir_na_tail_local(	table_element_local * new_method);


char * recursao_expr(is_expression_list* expr, method_var* lista_do_metodo);
char * var_declarada(method_var * lista, char* str);
int metodo_retorna_tipo_param (is_expression_list* expr, method_var* lista_do_metodo,  param_node * param_list);
char * type_call_verification(is_expression_list* expr, method_var* lista_do_metodo);
char * var_declarada_globalmente(char* str);


int ha_metodo_igual_declarado(is_expression_list* expr, method_var* lista_do_metodo);
char*  get_metodo_igual_return_type(is_expression_list* expr, method_var* lista_do_metodo);
int num_metodo_parecido_declarado(is_expression_list* expr, method_var* lista_do_metodo);
char*  get_metodo_parecido_return_type(is_expression_list* expr, method_var* lista_do_metodo);

char *  assinatura_return_iguais(is_expression_list* expr, table_element_local * new_method );
int assinatutas_parecidas_call(is_expression_list* expr, param_node* param_list, method_var* lista_do_metodo);
int assinatutas_iguais_call(is_expression_list* expr, param_node* param_list, method_var* lista_do_metodo);
int assinatutas_iguais_global(table_element_global *newSymbol, table_element_global *aux);


void print_erro_assign(is_expression_list* expr, char * type);
char * type_print_error(char * str);
char * retorna_operador (char * value);
char * lowerCase(char * str);
void show_tabela_global();
void show_table();

//table_element *search_el(char *str);

#endif
