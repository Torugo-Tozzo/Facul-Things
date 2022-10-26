#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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
    float preco;

};
Veiculo *bd[50];
float aux[50];

int r;
int newtam;

int busca(Veiculo *bd[],int tam,string exemplo){
    //BUSCA    
    for(int j = 0; j < tam; j++ ){
        //oq vai ser buscado (placa)
        if (bd[j]->placa == exemplo)
        {
            r = j;
            cout << "\n encontrado na posição = " << j << ".\n";
        }else 
        cout << "...";
        r = -1;  
    }
return r;
}
int exclui(Veiculo *bd[],int *tam,string ex){
    bd[busca(bd,*tam,ex)];
    if (r == -1){
        cout << "\nNão exite chefe\n";
    }
    else{
    bd[r] = NULL;
    for (int i = r; i < *tam; i++)
    {
        bd[i] = bd[i+1];
    
    *tam = *tam-1;
    }
    }
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
    
}

int ordena(Veiculo *bd[],int tam,float aux[]){
    for (int i = 0; i < tam; i++){
       aux[i] = bd[i]->preco;   
    }
    sort(&aux[0],&aux[tam]);
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
    //exclui(bd,&tam,"BEIFESB");
    cout << "tam = " << tam <<"\n";

    // string placa1;
    // cout << "placa do veiculo a ser buscado:";
    // cin >> placa1;
    //while(int c = 0){
    // int condition;
    // cout << "faz oq com esse veiculo patrão? \n1 = exclui. \n2 = add uma lata velha. \n3 = kitar \n ";
    // cin >> condition;
    // string md;
    // string mar;
    // string ver;
    // string year;
    // string kms;
    // string pot;
    // string con;
    // string moa;
    // string dir;
    // string color;
    // string door;
    // string plaq;
    // string price;
    // switch (condition)
    // {
    // case 1:
    //     exclui(bd,tam,placa1);
    //     break;
    // case 2:
    //     cout << "modelo";cin >> md;
    //     cout << "marca";cin >> mar;
    //     cout << "versao (ex:hat sedan SUV....)";cin >> ver;
    //     cout << "ano";cin >> year;
    //     cout << "kilometragem";cin >> kms;
    //     cout << "motor(ex: 1.0 2.0 1.6....)";cin >> pot;
    //     cout << "flex? gasolina?";cin >>con;
    //     cout << "manual ou automatico?";cin >> moa;
    //     cout << "direção?";cin >> dir;
    //     cout << "cor:";cin >> color;
    //     cout << "portas:";cin >> door;
    //     cout << "placa";cin >> plaq;
    //     cout << "preço:";cin >> price;
    //     insere(bd,tam,md,mar,ver,year,kms,pot,con,moa,dir,color,door,plaq,price);
    //     break;
    // case 3:
    //     printf("flw");
    //     //c=1;
    //     break;
    // default:
    //     printf("?");
    //     break;
    // }
    //}
    //busca(bd, tam, placa);
    //exclui(bd,tam,placa);
    insere(bd,&tam,"BIBACAR","HOULA","Sedã","2024","2.4","1111111","Flex","Automatico","Elétrica","Rosa","4","GAY2469",1783.00);
    
    ordena(bd,tam,aux);
    

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
    for (int i = 0; i < tam; i++)
    {
        cout << aux[i] <<"\n";
    }
    

    }
    else
         cout << "unable to open the file";

}
