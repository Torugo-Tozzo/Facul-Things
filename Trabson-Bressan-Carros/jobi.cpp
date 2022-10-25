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
    string preco;

};
Veiculo *bd[50];


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
        }  
    }
return r;
}
void exclui(Veiculo *bd[],int tam,string ex){
    bd[busca(bd,tam,ex)];
    bd[r] = NULL;
    for (int i = r; i < tam; i++)
    {
        bd[i] = bd[i+1];
    }
    //delete(bd[tam-1]);
    //delete(bd[j]);
}
int insere(Veiculo *bd[], int tam,string model,string marc,string ver,string an,string mot,string kilo,string con,string mou,string dire,string tinta,string port,string plac,string prec){  
        if (bd[tam] == NULL){
            bd[tam] = new Veiculo; 
            bd[tam]->modelo = model;
            bd[tam]->marca = marc;
            bd[tam]->versao = ver;
            bd[tam]->ano = an;
            bd[tam]->motor = mot; 
            bd[tam]->kilometragem = kilo; 
            bd[tam]->consumo = con; 
            bd[tam]->moua = mou; 
            bd[tam]->direcao = dire; 
            bd[tam]->cor = tinta; 
            bd[tam]->portas = port;  
            bd[tam]->placa = plac; 
            bd[tam]->preco = prec;    
        newtam = tam + 1; 
        
        
    }
    return newtam;
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
    cout << "placa do veiculo a ser buscado:";
    cin >> placa1;
    
    while(int c =! 1){
    int condition;
    cout << "faz oq com esse veiculo patrão? \n1 = exclui. \n2 = buscar outra lata velha. \n3 = add um veiculo \n 4 ou qualquer otro num = sair";
    cin >> condition;
    
    
    switch (condition)
    {
    case 1:
        exclui(bd,tam,placa1);
        break;
    case 2:
        string modelim;cout << "modelo";cin >> modelim;
        string marquinha;cout << "marca";cin >> marquinha;
        string versaozinha;cout << "versao (ex:hat sedan SUV....)";cin >> versaozinha;
        string aninho;cout << "ano";cin >> aninho;
        string kilometrinho;cout << "kilometragem";cin >> kilometrinho;
        string motorzim;cout << "motor(ex: 1.0 2.0 1.6....)";cin >> motorzim;
        string conzinho;cout << "";cin >>conzinho;
        string mouzinho;cout << "";cin >> ;
        string direzinha;cout << "";cin >> ;
        string modelim;cout << "";cin >> ;
        string modelim;cout << "";cin >> ;
        string modelim;cout << "";cin >> ;
        string modelim;cout << "";cin >> ;
        insere(bd,tam,modelim,marquinha,versaozinha,aninho,kilometrinho,motorzim,conzinho,mouzinho,direzinha,corzinha,portinha,plaquinha,precim);
        break;
    case 3:
        break;
    
    default:
        break;
    }
    }
    //busca(bd, tam, placa);
    //exclui(bd,tam,placa);
    //insere(bd,tam,"BIBACAR","HOULA","Sedã","2024","2.4","1111111","Flex","Automatico","Elétrica","Rosa","4","GAY2469","BARATINHO");

    //cout << "\n posição 31: " << bd[31] << ".\n";
    //cout << " posição 32: " << bd[32] << ".\n";
    //cout << "ano do carro excluído " << bd[32]->ano << ".\n"; 

    //cout << "newtam = " << newtam <<"\n";

    //cout << "\nbd[tam] = "<< bd[tam];

    for(int j = 0; j < newtam; j++ ){
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