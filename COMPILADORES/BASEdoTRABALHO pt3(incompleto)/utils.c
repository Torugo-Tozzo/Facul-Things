// estrutura da tabela de simbolos

#define TAM_TAB 100

struct elemTabSimbolos
{
    char id[100];   // identificador
    int end;        //endereco  
    int tip;        // tipo da variavel
}   tabSimb[TAM_TAB], elemTab;

int posTab = 0;

int buscaSimbolo (char *id)
{
    int i;
    for (i = posTab - 1; strcmp(tabSimb[i].id, id) && i >= 0; i--)
        ;    /* code */
    if (i == -1)
        yyerror("identificador nao encontrado");
    return i;
}

void insereSimbolo (struct elemTabSimbolos elem){
    int i;
    if (posTab == TAM_TAB)
        yyerror("Tabela cheia");
    for (i = posTab - 1; strcmp(tabSimb[i].id, elem.id) && i >= 0; i--)
        ;
    i = buscaSimbolo(elem.id);
    if(i != -1)
        yyerror("Identificador duplicado");
    tabSimb[posTab++] = elem;
}

int desempilha()
{
    if (topo == -1)
        yyerror("pilha ssemantica vaiza");
    return pilha[topo--];
}

void testaTipo(int tipo1, int tipo2, int ret)
{
    int t1 = desempilha();
    int t2 = desempilha();
    if (t1 != tipo1 || t2 != tipo2)
        yyerror("Incompatibilidade de tipo");
    empilha(ret);
}