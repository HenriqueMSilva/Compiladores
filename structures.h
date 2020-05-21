#ifndef STRUCTURES_H
#define STRUCTURES_H

// EXPR
typedef struct _s11 {
    char *id;
    int linha;
    int coluna;
} id_lin_col;

// EXPR
typedef struct _s10 {
    char *generation_type;
    char *operation;
    char *value;
	char * tipo;

    int linha;
    int coluna;

    int linha2;
    int coluna2;

    struct _s10* expr1;
    struct _s10* expr2;
} is_expression_list;

// STATMENT
typedef struct _s9 {
	char *name_function;
	int num_statements;
	is_expression_list* expr;
	struct _s9* statment1;
	struct _s9* statment2;
} is_statment_list;



// VARDECL
typedef struct _s8 {
    char* generation_type;
    char* type;
    char* name;

    int linha;
    int coluna;

    struct _s8* next;
} is_vardecl_list;

// METHOD BODY
typedef struct _s7 {
    char* type;
    is_vardecl_list* ivdl;
    is_statment_list* statment;
    struct _s7* next;
} is_methodbody_list;



//PARAMETROS HEADER
typedef struct _s6 {
    char* generation_type;
    char* type;
    char* name;
    
    int linha;
    int coluna;

    struct _s6* next;
} is_methodparams_list;

//HEADER
typedef struct _s5 {
    char* type;
    char* name;
    int anotar_body;
    
    int linha;
    int coluna;

    is_methodparams_list* impl;
} is_methodheader_list;

//METODO DECLARATION
typedef struct _s4 {
    is_methodheader_list* imhl;
    is_methodbody_list* imbl;
} is_methoddecl_list;




//VARIAVEIS GLOBAIS
typedef struct _s3 {
    char* type;
    char* name;

    int linha;
    int coluna;

    struct _s3* next;
} is_fielddecl_list;

// ESCOLHA DE METODOS
typedef struct _s2 {
	char* evocation;
    is_fielddecl_list* ifl;
    is_methoddecl_list* imdl;
    struct _s2* next;
} is_metodos;

//PROGRAM
typedef struct _s1 {
    is_metodos* metodos;
    char* classname;

    int linha;
    int coluna;

} is_program;

#endif
