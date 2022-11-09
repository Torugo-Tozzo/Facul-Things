#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct Veiculo{
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
    float preco;
    Veiculo *prox;
};

Veiculo *bd;

void imprime(Veiculo *bd,int tam){
        while (bd->prox != NULL){
            cout << bd->modelo << " ";
            cout << bd->marca << " ";
            cout << bd->versao << " ";
            cout << bd->ano << " ";
            cout << bd->kilometragem << " "; 
            cout << bd->motor << " "; 
            cout << bd->consumo << " "; 
            cout << bd->moua << " "; 
            cout << bd->direcao << " "; 
            cout << bd->cor << " "; 
            cout << bd->portas << " ";
            cout << bd->placa << " ";  
            cout << bd->preco << endl;
            } 

}

int main(int argc, char**argv){
    string line;
    ifstream myfile("BD_veiculos_2.txt");
    int tam = 0;
    if(myfile.is_open()){
        while (!myfile.eof()){   
            bd = new Veiculo;       
            myfile >> bd->modelo;
            cout << bd->modelo<< " ";
            myfile >> bd->marca;
            cout << bd->marca<< " ";
            myfile >> bd->versao;
            cout << bd->versao<< " ";
            myfile >> bd->ano;
            cout << bd->ano<< " ";
            myfile >> bd->kilometragem; 
            cout << bd->kilometragem<< " ";
            myfile >> bd->motor; 
            cout << bd->modelo<< " ";
            myfile >> bd->consumo; 
            cout << bd->consumo<< " ";
            myfile >> bd->moua; 
            cout << bd->moua<< " ";
            myfile >> bd->direcao; 
            cout << bd->direcao<< " ";
            myfile >> bd->cor;
            cout << bd->cor<< " ";
            myfile >> bd->portas;
            cout << bd->portas<< " ";
            myfile >> bd->placa; 
            cout << bd->placa<< " ";
            myfile >> bd->preco;
            cout << bd->preco<< " \n";
            bd->prox = new Veiculo;

        tam++;
        }
        myfile.close();
   
    cout << "\nLISTA FINAL DE VEICULOS\n------------------------------------------------------------------------------------------------------\n";
    //imprime(bd,tam);
    
    }else
        cout << "unable to open the file";}