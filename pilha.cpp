#include <iostream>

using namespace std;

struct id
{
    int chave;
    int valor;
};

void adiciona(int x, int vet[])
{
    int i;


    /*if (i < 5)
    {
        vet[i] = x;
        
        printf("%d",i,"%d",vet[i]);
        i++;
    }*/
}

/*
int x;
    cout << "idade?" << endl;
    cin >> x;
    cout << "vc tem "<<x<< "anos \n";
*/

int main(void)
{
    id vetor[3] = {7851, 1, 3527, 2, 9363, 3};
    cout << vetor[2].valor << endl;
    int x;
    int para = 1;
    int digito;
    int vet[5];
    cout << " 1 - Adiciona \n 2 - exclui\n 3 - sair\n"
         << endl;
    cin >> digito;
    while(para == 1){
    switch (digito)
    {
    case 1:
        //add
        cout << "valor a ser adicionado" << endl;
        cin >> x;
        adiciona(x, vet);
        break;
    case 2:
        // remove
        cout << "not implemented yet";
        break;
    case 3:
        cout << " tchau! ";
        para = 0;
        break;
    default: 
        cout << " ? ? ? ";
    }
    }
    
}
