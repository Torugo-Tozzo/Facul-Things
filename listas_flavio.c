#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    int chave;
    int valor;
    struct no_ * prox;
} no;

no * ptlista;

no* inicia_lista(){
    no* tmp = malloc(sizeof(no));
    tmp->chave = 0;
    tmp->valor = 0;
    tmp->prox = NULL;
    return tmp; 
}

void encerra_lista(no* ptlista){
    free(ptlista);
}
void busca_enc(int chave, no* ant, no* pont){

}
int main() {

    ptlista = inicia_lista();
    encerra_lista(ptlista);

    return (EXIT_SUCCESS);
}