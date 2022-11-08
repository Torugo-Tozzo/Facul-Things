/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>


using namespace std;

typedef struct no {
	int valor;  //'carga útil' do nó
    int chave; //num cenario real, poderia ser: nome, endereco...
	struct no * prox;  // ponteiro para o próximo nó da lista encadeada
} no;

typedef struct {
	int tam;            //critério de busca da ordenação
	struct no *inicio; // ponteiro para o próximo nó da lista encadeada
} Lista;

/**
 * Realiza a alocacao do espaco para que a lista possa comecar
 * a receber nos.
 * @return a lista vazia.
 */
Lista* inicia_lista(Lista nova_lista) {
	nova_lista.tam = 0;
	nova_lista.inicio = NULL;
    cout << "-A lista foi iniciada."<<endl;
	return 0;
}

/**
 * Desaloca o espaco previamente alocado para a lista encadeada.
 * @param ptlista ponteiro para a lista.
 * @return NULL para atualizar o ponteiro da lista.
 */
Lista * encerra_lista(Lista * ptlista) {
	no * ant = ptlista->inicio;
	no * pont = ptlista->inicio;
	
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
no * busca(Lista * ptlista, int valor) {
	no *percorredor;
    int cont = 1;
    percorredor = ptlista->inicio;
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
void insere_inicio(Lista  *ptlista, int valor){
    no *novo = (no*)malloc(sizeof(no));
    novo->valor = valor;
    novo->prox = ptlista->inicio;
    ptlista->inicio = novo;
    ptlista->tam++;
    cout<<"valor inserido no inicio da lista= " << valor <<endl;
}
/**
 * Realiza a insercao do elemento no fim da lista ligada.
 * @param valor a ser inserido.
 */
void insere_fim(Lista * ptlista, int valor){
      no *percorredor, *novo = (no*)malloc(sizeof(no));
      novo->valor = valor;
      novo->prox = NULL;
      if (ptlista->inicio == NULL){
        ptlista->inicio = novo;
        ptlista->tam++;
      }else{
        percorredor = ptlista->inicio; 
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
void remove_inicio(Lista * ptlista){
    no *aRemover = NULL; 
    no *inicio = ptlista->inicio; 
    if (ptlista->inicio != NULL){
        aRemover = ptlista->inicio;
        ptlista->inicio = aRemover->prox;
        free(aRemover);
        ptlista->tam--;
        cout << "Primeiro elemento da lista removido!\n";
    }else cout << "Lista já vazia";
    
}

/**
 * Realiza a remocao do último elemento da lista encadeada, se houver.
 * @return nulo em caso de lista vazia, senão retorna o nó removido.
 */
void remove_fim(Lista * ptlista){
    no *percorredor;
    percorredor = ptlista->inicio;
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
void imprime(Lista * ptlista){
    no *inicio = ptlista->inicio;
    while (inicio != NULL){
        cout << " " << inicio->valor << " ";
        inicio = inicio->prox;
    }
    cout << "\n\n";
}
Lista lista1;
int main() {
    // Lista lista1;
    // lista1.tam = 0;
	// lista1.inicio = NULL;

    inicia_lista(lista1);
    
    insere_inicio(&lista1, 5);
    
    insere_inicio(&lista1, 10);

    insere_inicio(&lista1, 13);

    insere_inicio(&lista1, 30);

    insere_fim(&lista1, 44);

    insere_fim(&lista1, 55);

    insere_fim(&lista1, 66);

    remove_fim(&lista1);

    imprime(&lista1);

    busca(&lista1,44);
/*
    insere_fim(lista1, 15);
    cout<<"insere 3: ";
    imprime(lista1);

    insere_fim(lista1, 12);
    cout<<"insere 4: ";
    imprime(lista1);

    insere_inicio(lista1, 20);
    cout<<"insere 5: ";
    imprime(lista1);

    p = remove_inicio(lista1);
    cout<<"remove 1: "<< p->valor <<endl;
    delete (p);
    imprime(lista1);

    p = remove_fim(lista1);
    cout<<"remove 2: "<< p->valor <<endl;
    delete (p);
    imprime(lista1);

    p = remove_inicio(lista1);
    cout<<"remove 3: "<< p->valor <<endl;
    delete (p);
    imprime(lista1);

    p = remove_fim(lista1);
    cout<<"remove 4: "<< p->valor <<endl;
    delete (p);
    imprime(lista1);

    p = remove_inicio(lista1);
    cout<<"remove 5: "<< p->valor <<endl;
    delete (p);
    imprime(lista1);

    p = remove_inicio(lista1);
    cout<<"remove 6: "<< endl;
    delete (p);
    imprime(lista1);
*/
   //lista1 = encerra_lista(lista1);

    return (EXIT_SUCCESS);
}