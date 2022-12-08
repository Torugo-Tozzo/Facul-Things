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

void busca(Arvore *arv, int valor){
  Node *atual = arv->raiz;
  while (atual != NULL)
  {
    if (valor > atual->valor)
    {
      atual = atual->dir;
    }else if (valor < atual->valor)
    {
      atual = atual->esq;
    }else if (valor == atual->valor)
    {
      cout << "valor encontrado" << endl;
      return;
    }
  }
  cout << "valor não encontrado" << endl;
  return;
}

int main()
{

  Arvore *arv = new Arvore; // inicia a arvore

  insere(arv, 20);
  insere(arv, 9);
  insere(arv, 44);
  insere(arv, 2);
  insere(arv, 15);

  busca(arv,2);

  cout << arv->raiz->valor << endl;
  cout << arv->raiz->esq->valor << endl;
}
