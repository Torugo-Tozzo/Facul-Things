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

};

Veiculo *bd[50];
float vetprecos[50];
float vex[11];
string vetplacas[50];

int r = -2;
int newtam;

void imprime(Veiculo *bd[],int tam){
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
            cout << bd[j]->placa << " ";  
            cout << bd[j]->preco << endl; 
        }
}
void imprime1(Veiculo *bd[],int tam,int j){
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
            cout << bd[j]->placa << " ";  
            cout << bd[j]->preco << endl; 
}
int busca(Veiculo *bd[],int tam,string exemplo){
    //BUSCA    
    for(int j = 0; j < tam; j++ ){
        //oq vai ser buscado (placa)
        if (bd[j]->placa == exemplo){
            r = j;
            cout << "\nEncontrado na posição = " << j+1 << ".\n";
            j = tam;
        }if(j == tam-1 && r == -2){ 
        r = -1;
        }  
    }
return r;
}
int exclui(Veiculo *bd[],int *tam,string ex){
    cout << "buscando..." <<endl;
    bd[busca(bd,*tam,ex)];
    bd[r] = NULL;
    for (int i = r; i < *tam; i++){
        bd[i] = bd[i+1];
    }
    bd[*tam] = NULL;
    *tam = *tam-1;
    cout << "cvetprecoso na posição "<< r <<" excluido!\n";
    return 0;
}

int insere(Veiculo *bd[], int *tam,string model,string marc,string ver,string an,string mot,string kilo,string con,string mou,string dire,string tinta,string port,string plac,float prec){  
        if (bd[*tam] == NULL){
            bd[*tam] = new Veiculo; 
            bd[*tam]->modelo = model;
            bd[*tam]->marca = marc;
            bd[*tam]->versao = ver;
            bd[*tam]->ano = an;
            bd[*tam]->motor = mot; 
            bd[*tam]->kilometragem = kilo; 
            bd[*tam]->consumo = con; 
            bd[*tam]->moua = mou; 
            bd[*tam]->direcao = dire; 
            bd[*tam]->cor = tinta; 
            bd[*tam]->portas = port;  
            bd[*tam]->placa = plac; 
            bd[*tam]->preco = prec;    
        *tam = *tam +1;
    }
    return 0;   
}
int ordprecos(Veiculo *bd[],int tam,float vetprecos[]){
    for (int i = 0; i < tam; i++){
       vetprecos[i] = bd[i]->preco;  
    }
    sort(&vetprecos[0],&vetprecos[tam]);
    return 0;
} 
int ordplacas(Veiculo *bd[],int tam,string vetplacas[]){
    for (int i = 0; i < tam; i++){
        vetplacas[i]=bd[i]->placa;
    }
    sort(&vetplacas[0],&vetplacas[tam]);
    return 0;
}

void dezprox(float vetprecos[], int tam, float x,int k){
    for (int i = 0; i < tam; i++){
       vetprecos[i] = bd[i]->preco;  
    }
	priority_queue<pair<int, int> > pq;
	for (int i = 0; i < k; i++)
		pq.push({ abs(vetprecos[i] - x), i });
	for (int i = k; i < tam; i++) {
		float diff = abs(vetprecos[i] - x);
		if (diff > pq.top().first)
			continue;
		pq.pop();
		pq.push({ diff, i });}
	while (pq.empty() == false) {
        for(int j = 0; j < tam; j++ ){
        if (bd[j]->preco == vetprecos[pq.top().second]){
            imprime1(bd,tam,j);
            j = tam;}}
		pq.pop();}
}
void salva(Veiculo *bd[], int tam){
    ofstream myfile2("BD_veiculos_2.txt");
        if(myfile2.is_open()){
        for(int j = 0; j < tam; j++ ){
            myfile2 << bd[j]->modelo << " ";
            myfile2 << bd[j]->marca << " ";
            myfile2 << bd[j]->versao << " ";
            myfile2 << bd[j]->ano << " ";
            myfile2 << bd[j]->kilometragem << " "; 
            myfile2 << bd[j]->motor << " "; 
            myfile2 << bd[j]->consumo << " "; 
            myfile2 << bd[j]->moua << " "; 
            myfile2 << bd[j]->direcao << " "; 
            myfile2 << bd[j]->cor << " "; 
            myfile2 << bd[j]->portas << " ";
            myfile2 << bd[j]->placa << " ";  
            myfile2 << bd[j]->preco << endl; 
        }}
}

int main(int argc, char**argv){
    string line;
    ifstream myfile("BD_veiculos_2.txt");
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
            myfile >> bd[tam]->preco;
        
        tam++;
        }
        myfile.close();
        imprime(bd,tam);
    for(int i = tam; i < 50;i++){
        bd[i] = NULL;
    }
   
    string placa1;

    int c;

    while(c != 5){
    for(int i = 0;i != 1;){
    cout << "\nplaca do veiculo a ser buscado:";
    cin >> placa1;
    busca(bd,tam,placa1);
    if(r != -1){
        cout << "Achei o veiculo!\n";
        i = 1;
    }if(r == -1){
        cout << "placa não encontrada, tenta dnovo\n";}
    }    
    int condition;
    cout << "faz oq com esse veiculo patrão?\n0 = informações do veiculo.  \n1 = exclui. \n2 = adicionar um outro veiculo \n3 = mostrar as placas ordenadas. \n4 = mostrar 10 preços proximos\n5 = ver lista atual de todos os veiculos.\n6 = SAIR \n ";
    cin >> condition;
    string md;
    string mar;
    string ver;
    string year;
    string kms;
    string pot;
    string con;
    string moa;
    string dir;
    string color;
    string door;
    string plaq;
    float price;
    switch (condition)
    {
    case 0:
        imprime1(bd,tam,r);
        break;
    case 1:
        exclui(bd,&tam,placa1);
        imprime(bd,tam);
        break;
    case 2:
        //if(tam<50){
        cout << "INSIRA: modelo:";cin >> md;
        cout << "INSIRA: marca:";cin >> mar;
        cout << "INSIRA: versao (ex:hat sedan SUV....):";cin >> ver;
        cout << "INSIRA: ano:";cin >> year;
        cout << "INSIRA: kilometragem:";cin >> kms;
        cout << "INSIRA: motor(ex: 1.0 2.0 1.6....):";cin >> pot;
        cout << "INSIRA: flex? gasolina?:";cin >>con;
        cout << "INSIRA: manual ou automatico?:";cin >> moa;
        cout << "INSIRA: direção?:";cin >> dir;
        cout << "INSIRA: cor:";cin >> color;
        cout << "INSIRA: n de portas:";cin >> door;
        cout << "INSIRA: placa:";cin >> plaq;
        cout << "INSIRA: preço:";cin >> price;
        insere(bd,&tam,md,mar,ver,year,kms,pot,con,moa,dir,color,door,plaq,price);
       // }
        break;
    case 3:
        ordplacas(bd,tam,vetplacas);
        for (int i = 0; i < tam; i++){
        cout << vetplacas[i] <<"\n";
    }
        break;
    case 4:
        dezprox(vetprecos,tam,vetprecos[r],10);
        break;
    case 5:
        imprime(bd,tam);
        break;
    case 6:
    printf("flw");
        salva(bd,tam);
        c=5;
        break;
    default:
        printf("?");
        break;
    }
    }
    
    cout << "LISTA FINAL DE VEICULOS\n-----------------------------\n";
    imprime(bd,tam);
    }
    else
         cout << "unable to open the file";

}
