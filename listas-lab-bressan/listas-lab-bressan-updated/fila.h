#include "lista.h"

typedef tLista tFila;

inline tFila* inicia_pilha(tFila ptfila){
    return inicia_lista(ptfila);
};

//inline tFila* encerra_pilha(){
//    return encerra_lista();
//};

inline void entra(tFila *p, int valor){
    insere_inicio(p,valor);
};

inline void sai(tFila *p, int valor){
    remove_fim(p);
};