#include "lista.h"

typedef tLista tPilha;

inline tPilha* inicia_pilha(tPilha ptpilha){
    return inicia_lista(ptpilha);
};

//inline tPilha* encerra_pilha(){
//    return encerra_lista();
//};

inline void push(tPilha *p, int valor){
    insere_inicio(p,valor);
};

inline void pop(tPilha *p, int valor){
    remove_inicio(p);
};