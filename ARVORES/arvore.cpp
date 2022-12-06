#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

struct Node{
	int valor;  //'carga útil' do nó
    Node *dir;
    Node *esq;
};

struct Cabecalho{
	int altura;            
	Node *raiz;  
};

void inicia_arvore(Cabecalho *arvore1) {
	arvore1->raiz = NULL;
    cout << "-A arvore foi iniciada."<<endl;
}

void insere(Cabecalho *arvore, int valor){
    Node *percorredor, *novo = new Node;
    percorredor = arvore->raiz;
    if (arvore->raiz == NULL ){
            novo->valor = valor;
            arvore->raiz = novo;
            cout << "valor inserido na raiz" << endl;
    }else{
        while (percorredor != NULL){
            if (valor < percorredor->valor){
                    percorredor = percorredor->esq;
            }else if(valor > percorredor->valor){
                    percorredor = percorredor->dir;
            }else if(valor == percorredor->valor){
                    cout << "valor ja existente na arvore" << endl;
                    goto Jaexiste;
            }
        }
        novo->valor = valor;
        percorredor = novo;
        cout << "valor inserido na arvore" << endl;
    }
    Jaexiste:
    cout << "." << endl;
}

int main() {

Cabecalho *arvore = new Cabecalho;
insere(arvore, 5);  
insere(arvore, 4);
insere(arvore, 6);
insere(arvore, 5);
}