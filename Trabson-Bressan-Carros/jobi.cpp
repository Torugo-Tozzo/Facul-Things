#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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
int busca(Veiculo *bd[],int tam,string exemplo){
    //BUSCA    
    for(int j = 0; j < tam; j++ ){
        //oq vai ser buscado (placa)
        if (bd[j]->placa == exemplo){
            r = j;
            cout << "Encontrado na posição = " << j << ".\n";
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
    cout << "carro na posição "<< r <<" excluido!\n";
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
    for (int i = 0; i < tam; i++)
    {
        vetplacas[i]=bd[i]->placa;
    }
    sort(&vetplacas[0],&vetplacas[tam]);
    return 0;
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
    cout << "faz oq com esse veiculo patrão? \n1 = exclui. \n2 = add uma lata velha. \n3 = mostrar as placas ordenadas. \n4 = buscar outra placa \n5 = kitar \n ";
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
    case 1:
        exclui(bd,&tam,placa1);
        imprime(bd,tam);
        break;
    case 2:
        cout << "modelo";cin >> md;
        cout << "marca";cin >> mar;
        cout << "versao (ex:hat sedan SUV....)";cin >> ver;
        cout << "ano";cin >> year;
        cout << "kilometragem";cin >> kms;
        cout << "motor(ex: 1.0 2.0 1.6....)";cin >> pot;
        cout << "flex? gasolina?";cin >>con;
        cout << "manual ou automatico?";cin >> moa;
        cout << "direção?";cin >> dir;
        cout << "cor:";cin >> color;
        cout << "n de portas::";cin >> door;
        cout << "placa:";cin >> plaq;
        cout << "preço:";cin >> price;
        insere(bd,&tam,md,mar,ver,year,kms,pot,con,moa,dir,color,door,plaq,price);
        break;
    case 3:
        ordplacas(bd,tam,vetplacas);
        for (int i = 0; i < tam; i++){
        cout << vetplacas[i] <<"\n";
    }
        break;
    case 4:

        break;
    case 5:
        printf("flw");
        c=5;
        break;
    default:
        printf("?");
        break;
    }
    }
    // busca(bd, tam, placa);
    // exclui(bd,tam,placa);
    // insere(bd,&tam,"BIBACAR","HOULA","Sedã","2024","2.4","1111111","Flex","Automatico","Elétrica","Rosa","4","AAA1111",1783.00);
    // ordprecos(bd,tam,vetprecos);
    // ordplacas(bd,tam,vetplacas);
    cout << "LISTA FINAL DE CARROS\n-----------------------------\n";
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
    else
         cout << "unable to open the file";

}
