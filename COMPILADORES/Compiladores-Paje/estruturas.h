#define TAM_TAB 100

enum {INT = 1, LOG, VAL = 10, REF};

typedef struct no *lista;

struct no{
    int tipo;
    int mec;
    lista prox;
} lparametros;

struct elem_tab_simbolos
{
    char id[30];
    int endereco;
    int tipo;
    int mec;
    int rotulo;
    char escopo;
    char cat;
    int npar;
    lista listapar;
} TabSimb[TAM_TAB], elem_tab;