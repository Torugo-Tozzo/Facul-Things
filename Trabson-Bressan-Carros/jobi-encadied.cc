/*
        !!!!!!AVISO IMPORTANTE!!!!!!
        Nesta implementação de lista encadiada, 
        o primeiro slot (o primeiro nó da lista), ficará sempre vazio, contendo valores nulos
        ou seja a lista começa a partir do segundo nó
*/
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

int resultado;

void imprime(Cabecalho *exemplo){
        Veiculo *percorredor;
        percorredor = exemplo->inicio;
        while (percorredor != NULL){
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
cout << "-------------------------------------------------------------------------------\n";
}

void busca(Cabecalho *cabeca, string placaexemplo){
    Veiculo *percorredor;
    percorredor = cabeca->inicio->prox;
    int pos = 1;
    while (pos <= cabeca->tam){
        if(percorredor->placa != placaexemplo){
        percorredor = percorredor->prox;
        pos++;
        }else if(percorredor->placa == placaexemplo){
            cout << "Carro encontrado na posição " << pos <<  endl;
            resultado = pos;
            pos = cabeca->tam+1;
            }else cout << "Tem essa placa aqui não, fiotão.";
    }
}

void exclui(Cabecalho *cabeca,string placaexemplo){
    Veiculo *percorredor;
    Veiculo *ant;
    percorredor = cabeca->inicio;
    while(percorredor->placa != placaexemplo){
        ant =percorredor;
        percorredor = percorredor->prox;
    }
    ant->prox = percorredor->prox;
    free(percorredor);   
    cabeca->tam--;
}

void insere_inicio(Cabecalho *cabeca , string modelo,string marca,string versao,string ano,string kilometragem,string motor,string consumo,string moua,string direcao,string cor,string portas,string placa,float preco){
    Veiculo *novo = new Veiculo;
    novo->modelo = modelo;
    novo->marca = marca;
    novo->versao = versao;
    novo->ano = ano;
    novo->kilometragem = kilometragem;
    novo->motor = motor;
    novo->consumo = consumo;
    novo->moua = moua;
    novo->direcao = direcao;
    novo->cor = cor;
    novo->portas = portas;
    novo->placa = placa;
    novo->preco = preco;
    novo->prox = cabeca->inicio->prox;
    cabeca->inicio->prox = novo;
    cabeca->tam++;
    cout<<"veiculo inserido no inicio da lista "  << endl;
}

void insere_fim(Cabecalho *cabeca , string modelo,string marca,string versao,string ano,string kilometragem,string motor,string consumo,string moua,string direcao,string cor,string portas,string placa,float preco){
    Veiculo *novo = new Veiculo;
    novo->modelo = modelo;
    novo->marca = marca;
    novo->versao = versao;
    novo->ano = ano;
    novo->kilometragem = kilometragem;
    novo->motor = motor;
    novo->consumo = consumo;
    novo->moua = moua;
    novo->direcao = direcao;
    novo->cor = cor;
    novo->portas = portas;
    novo->placa = placa;
    novo->preco = preco;
    Veiculo *percorredor;
    percorredor = cabeca->inicio;
    while(percorredor->prox != NULL){percorredor = percorredor->prox;}
    percorredor->prox = novo;
    novo->prox = NULL;
    cabeca->tam++;
    cout<<"veiculo inserido no fim da lista "  << endl;
}

int main(int argc, char**argv){
    string line;
    ifstream myfile("BD_veiculos_2.txt");
    Cabecalho *cabeca = new Cabecalho;
    Veiculo *bd;
    cabeca->inicio = new Veiculo;
    bd = cabeca->inicio;
    if(myfile.is_open()){
        while (!myfile.eof()){
            bd->prox = new Veiculo;
            bd = bd->prox;

            myfile >> bd->modelo;
            myfile >> bd->marca;
            myfile >> bd->versao;
            myfile >> bd->ano;
            myfile >> bd->kilometragem; 
            myfile >> bd->motor; 
            myfile >> bd->consumo; 
            myfile >> bd->moua; 
            myfile >> bd->direcao; 
            myfile >> bd->cor;
            myfile >> bd->portas;
            myfile >> bd->placa; 
            myfile >> bd->preco;
            
            cabeca->tam++;
        }
        myfile.close();

    cout << "Tamanho da lista = " << cabeca->tam << endl;
    imprime(cabeca);

    busca(cabeca,"MAN7774");

    exclui(cabeca,"MAN7774");
    

    cout << "Tamanho da lista = " << cabeca->tam << endl;
    imprime(cabeca);
    
    //exclui(cabeca,"PAE2146");
    //imprime(cabeca);
    
    insere_inicio(cabeca,"TESTE","TESTE","TESTE","TESTE","TESTE","TESTE","TESTE","TESTE","TESTE","TESTE","TESTE","TESTE",0.00);
    
    imprime(cabeca);

    insere_fim(cabeca,"TESTE","TESTE","TESTE","TESTE","TESTE","TESTE","TESTE","TESTE","TESTE","TESTE","TESTE","TESTE",0.00);
    imprime(cabeca);
    }else
        cout << "unable to open the file";}
