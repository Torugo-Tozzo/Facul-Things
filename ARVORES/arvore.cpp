#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
  int valor;
  Node *esq;
  Node *dir;
};

struct Arvore
{
  Node *raiz;
};

void insere(Arvore *arv, int valor)
{
  Node *novo = new Node;
  novo->esq = NULL;    /* a esquerda da arv é NULL */
  novo->dir = NULL;    /* a direita da arv é NULL */
  novo->valor = valor; /* Armazena a informação */

  if (arv->raiz == NULL)
  {
    arv->raiz = novo;
  }
  else
  { // se nao for a raiz
    Node *atual = arv->raiz;
    Node *anterior;
    while (true)
    {
      anterior = atual;
      if (valor <= atual->valor)
      { // ir para esquerda
        atual = atual->esq;
        if (atual == NULL)
        {
          anterior->esq = novo;
          return;
        }
      } // fim da condição ir a esquerda
      else
      { // ir para direita
        atual = atual->dir;
        if (atual == NULL)
        {
          anterior->dir = novo;
          return;
        }
      } // fim da condição ir a direita
    }   // fim do laço while
  }     // fim do else não raiz
}

//busca
//excluir 
//em ordem 
//pos ordem
//pre prdem

int main()
{

  Arvore *arv = new Arvore; // Nó raiz que inicia a arvore

  insere(arv, 55);
  insere(arv, 9);

  cout << arv->raiz->valor << endl;
  cout << arv->raiz->esq->valor << endl;
}
