#include <iostream>
#include <fstream>

using namespace std;

typedef struct Veiculo{
    string modelo;
    string marca;
    string versao;
    string ano;
    string kilometragem;
    string motor;
    string consumo;
    string moua;
    string direcao;
    string cor;
    string portas;
    string placa;

};
Veiculo *bd[50];



void busca(Veiculo *bd[],int tam,string exemplo){
    //BUSCA    
    for(int j = 0; j < tam; j++ ){
        //oq vai ser buscado (placa)
        if (bd[j]->placa == exemplo)
        {
            
            cout << "\n encontrado na posição = " << j << " ! \n";
            
        }  
    }

}
void exclui(Veiculo *bd[],int tam,int j){
    bd[j] = NULL;
    //delete(bd[j]);
}


int main(int argc, char**argv){
 
    string line;
    ifstream myfile("BD_veiculos.txt");
    int tam = 0;
    if(myfile.is_open()){
        while (!myfile.eof())
        {
            bd[tam] = new Veiculo;          
            myfile >> bd[tam]->modelo ;
            myfile >> bd[tam]->marca ;
            myfile >> bd[tam]->versao;
            myfile >> bd[tam]->ano;
            myfile >> bd[tam]->kilometragem; 
            myfile >> bd[tam]->motor; 
            myfile >> bd[tam]->consumo; 
            myfile >> bd[tam]->moua; 
            myfile >> bd[tam]->direcao; 
            myfile >> bd[tam]->cor; 
            myfile >> bd[tam]->portas;  
            myfile >> bd[tam]->placa; 
        
        tam++;

        }
        myfile.close();
        for(int j = 0; j < tam; j++ ){
            cout << bd[j]->modelo << " ";
            cout << bd[j]->marca << " ";
            cout << bd[j]->versao << " ";
            cout << bd[j]->ano << " ";
            cout << bd[j]->kilometragem << " "; 
            cout << bd[j]->motor << " "; 
            cout << bd[j]->consumo << " "; 
            cout << bd[j]->moua << " "; 
            cout << bd[j]->direcao << " "; 
            cout << bd[j]->cor << " "; 
            cout << bd[j]->portas << " ";  
            cout << bd[j]->placa << endl; 
        }
    for(int i = tam; i < 50;i++){
        bd[i] = NULL;
        }

    busca(bd, tam, "MAN7774");


    exclui(bd,tam,30);
    cout << " valor: " << bd[30] << " \n";

    }
    else
         cout << "unable to open the file";

}
