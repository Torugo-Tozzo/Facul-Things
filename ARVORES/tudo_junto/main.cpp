#include <stdio.h>
#include <malloc.h>
#include <cstdlib>
#include <iostream>
# include "AVL.cpp"
# include "Binaria.cpp"

using namespace std;

int main(int argc, char** argv) {

    PONT arvoreAVL;
    NO* arvoreBi;
    bool *mudou;
    int n;

    inicializar(&arvoreAVL);
    inserirAVL(&arvoreAVL,1,mudou);
    inserirAVL(&arvoreAVL,2,mudou);
    inserirAVL(&arvoreAVL,3,mudou);
    inserirAVL(&arvoreAVL,4,mudou);
    inserirAVL(&arvoreAVL,5,mudou);
    inserirAVL(&arvoreAVL,6,mudou);
    inserirAVL(&arvoreAVL,7,mudou);
    inserirAVL(&arvoreAVL,8,mudou);
    inserirAVL(&arvoreAVL,9,mudou);
    inserirAVL(&arvoreAVL,10,mudou);
    inserirAVL(&arvoreAVL,11,mudou);
    inserirAVL(&arvoreAVL,12,mudou);
    inserirAVL(&arvoreAVL,13,mudou);
    inserirAVL(&arvoreAVL,14,mudou);
    inserirAVL(&arvoreAVL,15,mudou);


    cout << "test" << endl;
    cout << arvoreAVL->chave << endl;
    cout << "\n-----------------------" << endl;

    mostraArvore(arvoreAVL,0);

    /*
    ----------------------------------------------
    arvore printada por niveis do 1° ao n°, ex:
    ----------------------------------------------
    inicializar(&arvore);
    inserirAVL(&arvore,20,mudou);
    inserirAVL(&arvore,10,mudou);
    inserirAVL(&arvore,40,mudou);
    inserirAVL(&arvore,70,mudou);
    inserirAVL(&arvore,30,mudou);
    inserirAVL(&arvore,3,mudou);
    inserirAVL(&arvore,13,mudou);
    ----------------------------------------------
    output esperado:
    ----------------------------------------------
    nv1     nv2     nv3
    20
            10
                    3
                    13
            40
                    30
                    70
    ----------------------------------------------
    */
   destruirArvore(&arvoreAVL);

       Node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);
    insert(root, 9);
    insert(root, 10);
    insert(root, 11);
    insert(root, 12);
    insert(root, 13);

    inorder(root);
    std::cout << "------------------" << std::endl;

    printTree(root,0);

    return 0;

}