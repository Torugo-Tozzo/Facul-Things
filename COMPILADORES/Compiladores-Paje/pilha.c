#define TAM_PILHA 100

struct {
    int valor;
    char tipo;
} pilha[TAM_PILHA];
int topo = -1;

void empilha (int valor, char tipo){
    if(topo == TAM_PILHA)
        msg("Pilha cheia\n");
    pilha[++topo].valor = valor;
    pilha[topo].tipo = tipo;
}

int desempilha(){
    if (topo == -1)
        msg("Pilha vazia");
    return pilha[topo--].valor;
}

char desempilha_tipo(){
    if (topo == -1)
        msg("Pilha vazia");
    return pilha[topo].tipo;
}

void mostra_pilha(char *s){
    int i;
    printf("\nPilha: (%s) = [ ", s);
    for(i = topo; i >= 0; i--)
        printf("(%d, %c) ", pilha[i].valor, pilha[i].tipo);
    printf("]\n");
}