#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node   // Nós que vão preencher a arvore
{
  int valor;
  Node *esq;
  Node *dir;
};

struct Arvore   // Estrutura que vai representar a arvore e vai ter a raíz
{
  Node *raiz;
};

void insere(Arvore *arv, int valor)
{
  Node *novo = new Node;  //Nó que vai ser inserido
  novo->esq = NULL;    // a esquerda da arv é NULL 
  novo->dir = NULL;    // a direita da arv é NULL 
  novo->valor = valor; // Armazena a informação 

  if (arv->raiz == NULL)    
  {                           
    arv->raiz = novo;     //Caso a arvore esteja sem Raiz
  }
  else
  { // se nao for a raiz
    Node *atual = arv->raiz;
    Node *anterior;           // anterior sera importante para a atribuição do novo nó
    while (true)
    {
      anterior = atual;
      if (valor < atual->valor)
      { // ir para esquerda
        atual = atual->esq;
        if (atual == NULL)    // caso nulo, sera exatamente aqui que devemos inserir
        {
          anterior->esq = novo;   //insere e encerra a funcao
          cout << "valor "<< novo->valor <<" inserido na arvore!" << endl;
          return;
        }
      } // fim da condição ir a esquerda
      else if(valor > atual->valor)
      { // ir para direita
        atual = atual->dir;
        if (atual == NULL)  // caso nulo, sera exatamente aqui que devemos inserir
        {
          anterior->dir = novo;
          cout << "valor "<< novo->valor <<" inserido na arvore!" << endl;
          return;
        }
      }else   //caso o valor ja conste na arvore ele não vai inseri-lo novamente
      {
        cout << "valor " << valor << " ja existente na arvore, tente outro!" << endl;
        return;
      }
       // fim da condição ir a direita
    }   // fim do laço while
  }     // fim do else não raiz
}

void busca(Arvore *arv, int valor){
  Node *atual = arv->raiz;
  while (atual != NULL)       //enquanto não encontrar Nó Nulo ele percorre a arvore
  {
    if (valor > atual->valor)   //se maior vai pra direita
    {
      atual = atual->dir;
    }else if (valor < atual->valor)   // se menor vai pra esquerda
    {
      atual = atual->esq;             
    }else if (valor == atual->valor)  // se for igual, encontrou
    {
      cout << "valor encontrado" << endl;
      return; // termina aqui a funcao se achar
    }
  }
  cout << "valor não encontrado" << endl;
  return; // caso não encontre 
}

int main()
{

  Arvore *arv = new Arvore; // inicia a arvore

  insere(arv, 20);
  insere(arv, 9);
  insere(arv, 44);
  insere(arv, 2);
  insere(arv, 15);
  insere(arv, 15);

  busca(arv,2);

  cout << arv->raiz->valor << endl;
  cout << arv->raiz->esq->dir->valor << endl;
}
