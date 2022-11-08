/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>

#include "lista.h"

using namespace std;

/**
 * Realiza a alocacao do espaco para que a lista possa comecar
 * a receber nos.
 * @return a lista vazia.
 */
tLista* inicia_lista(tLista nova_lista) {
	nova_lista.tam = 0;
	nova_lista.lista = NULL;

        cout << "-A lista foi iniciada."<<endl;
	return 0;
}

/**
 * Desaloca o espaco previamente alocado para a lista encadeada.
 * @param ptlista ponteiro para a lista.
 * @return NULL para atualizar o ponteiro da lista.
 */
tLista * encerra_lista(tLista * ptlista) {
	no * ant = ptlista->lista;
	no * pont = ptlista->lista;
	
	while(ant != NULL){
		pont = ant->prox;
		delete(ant);
		ant = pont;
	}
	delete(ptlista);
        cout << "-A lista foi removida."<<endl;
	
        return NULL;
}
/**
 * Busca pelo valor de chave passado dentro da lista encadeada.
 * @param chave a ser buscada.
 * @param ant ponteiro anterior a posicao encontrada.
 * @return verdareiro se o elemento foi encontrado.
 */
no * busca(tLista * ptlista, int valor) {
	no *percorredor;
    int cont = 1;
    percorredor = ptlista->lista;
    while (percorredor->prox != NULL){
        if (percorredor->valor == valor){
         cout << "valor encontrado no nó[" << cont <<"]\n";   
        }
        percorredor = percorredor->prox;
        cont++;
    }
    return 0;
}
/**
 * Realiza a insercao do elemento no início da lista ligada.
 * @param valor a ser inserido.
 */
void insere_inicio(tLista * ptlista, int valor){
	no *novo = (no*)malloc(sizeof(no));
    novo->valor = valor;
    novo->prox = ptlista->lista;
    ptlista->lista = novo;
    ptlista->tam++;
    cout<<"valor inserido no inicio da lista= " << valor <<endl;
}

/**
 * Realiza a insercao do elemento no fim da lista ligada.
 * @param valor a ser inserido.
 */
void insere_fim(tLista * ptlista, int valor){
	no *percorredor, *novo = (no*)malloc(sizeof(no));
      novo->valor = valor;
      novo->prox = NULL;
      if (ptlista->lista == NULL){
        ptlista->lista = novo;
        ptlista->tam++;
      }else{
        percorredor = ptlista->lista; 
        while (percorredor->prox != NULL){
        percorredor = percorredor->prox;
        }
        percorredor->prox = novo;
        cout<<"valor inserido no final da lista = " << valor << endl;
      }ptlista->tam++;
}

/**
 * Realiza a remocao do primeiro elemento da lista encadeada, se houver.
 * @return nulo em caso de lista vazia, senão retorna o nó removido.
 */
no * remove_inicio(tLista * ptlista){
	no *aRemover = NULL; 
    no *inicio = ptlista->lista; 
    if (ptlista->lista != NULL){
        aRemover = ptlista->lista;
        ptlista->lista = aRemover->prox;
        free(aRemover);
        ptlista->tam--;
        cout << "Primeiro elemento da lista removido!\n";
    }else cout << "Lista já vazia";
}

/**
 * Realiza a remocao do último elemento da lista encadeada, se houver.
 * @return nulo em caso de lista vazia, senão retorna o nó removido.
 */
no * remove_fim(tLista * ptlista){
	no *percorredor;
    percorredor = ptlista->lista;
    while (percorredor->prox->prox != NULL){
        percorredor = percorredor->prox;
    }if (percorredor->prox->prox == NULL){
        percorredor->prox = NULL;
        free(percorredor->prox);
        ptlista->tam--;
        cout << "Ultimo elemento da lista removido!\n";
    }else cout << "deu errado!";
}

/**
 * Imprime a lista encadeada.
 */
void imprime(tLista * ptlista){
	no *inicio = ptlista->lista;
    while (inicio != NULL){
        cout << " " << inicio->valor << " ";
        inicio = inicio->prox;
    }
    cout << "\n\n";
}

