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


int r;

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
int insere(Veiculo *bd[], int tam){
    for (int i = 0; i < tam ; i++){
        if (bd[i] == NULL){
        // trocar bd[i] NULL por bd[1] CONTEUDO
        i = tam;
        tam++;   
        }
    }
    return tam;
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


    string placa = "JHE7846";

    busca(bd, tam, placa);
    exclui(bd,tam,placa);
    //insere(bd,tam,pos);
    cout << "ano do carro excluído " << bd[29]->ano << ".\n";
    cout << "ano do carro excluído " << bd[30]->ano << ".\n"; 

    cout << "ano do carro excluído " << bd[29] << ".\n";
    cout << "ano do carro excluído " << bd[30] << ".\n";
    cout << "ano do carro excluído " << bd[31] << ".\n";
    // 2015
    cout << "tam = " << tam <<"\n";
    }
    else
         cout << "unable to open the file";

}
