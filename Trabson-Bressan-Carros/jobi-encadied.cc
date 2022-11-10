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
    struct Veiculo *prox;
};

struct Cabecalho{
    int tam;
    struct Veiculo *inicio;    
};

Veiculo *bd;

void imprime(Cabecalho *bd){
        Veiculo *percorredor;
        while (percorredor->prox != NULL){
            cout << percorredor->modelo << " ";
            cout << percorredor->marca << " ";
            cout << percorredor->versao << " ";
            cout << percorredor->ano << " ";
            cout << percorredor->kilometragem << " "; 
            cout << percorredor->motor << " "; 
            cout << percorredor->consumo << " "; 
            cout << percorredor->moua << " "; 
            cout << percorredor->direcao << " "; 
            cout << percorredor->cor << " "; 
            cout << percorredor->portas << " ";
            cout << percorredor->placa << " ";  
            cout << percorredor->preco << endl;
            percorredor = percorredor->prox;
            } 
cout << "\n----------------------------------------\n";
}

int main(int argc, char**argv){
    string line;
    ifstream myfile("BD_veiculos_2.txt");
    Cabecalho *cabeca;
    cabeca->inicio = NULL;
    cabeca->tam = 0;
    if(myfile.is_open()){
        while (!myfile.eof()){  
            bd = new Veiculo;      
            myfile >> bd->modelo;
            cout << bd->modelo<< " ";
            myfile >> bd->marca;
            //cout << bd->marca<< " ";
            myfile >> bd->versao;
            //cout << bd->versao<< " ";
            myfile >> bd->ano;
            //cout << bd->ano<< " ";
            myfile >> bd->kilometragem; 
            //cout << bd->kilometragem<< " ";
            myfile >> bd->motor; 
            //cout << bd->modelo<< " ";
            myfile >> bd->consumo; 
            //cout << bd->consumo<< " ";
            myfile >> bd->moua; 
            //cout << bd->moua<< " ";
            myfile >> bd->direcao; 
            //cout << bd->direcao<< " ";
            myfile >> bd->cor;
            //cout << bd->cor<< " ";
            myfile >> bd->portas;
            //cout << bd->portas<< " ";
            myfile >> bd->placa; 
            //cout << bd->placa<< " ";
            myfile >> bd->preco;
            //cout << bd->preco<< " \n";
            //bd->prox = new Veiculo;
            bd = bd->prox;
            cabeca->tam++;
        }
        myfile.close();
   
    cout << "\nLISTA FINAL DE VEICULOS\n------------------------------------------------------------------------------------------------------\n";
    //imprime(&cabeca);
    cout << cabeca->tam;
    }else
        cout << "unable to open the file";}
