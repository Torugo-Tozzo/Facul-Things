#include <iostream>
#include <fstream>

using namespace std;

typedef struct Veiculo{
    string modelo;
    string marca;
    string versão;
    int ano;
    int kilometragem;
    string motor;
    string consumo;
    string moua;
    string direcao;
    string cor;
    int portas;
    string placa;

};
Veiculo *bd[50];

int main(int argc, char**argv){

    // ofstream myfile;
    // myfile.open("lombada.txt");
    // if (myfile.is_open())
    // {
    //     myfile << "Thubirabiron daum daum\n";
    //     myfile << "Thubirau daum daum derum dum da darao\n";
    //     myfile.close();
    // }
    // else
    //     cout << "unable to open the file";
    
    string line;
    ifstream myfile("BD_veiculos.txt");
    if(myfile.is_open()){
        while (!myfile.eof())
        {
        for (int i = 0; i < 12; i++)
        {
            myfile >> line;
            cout << "  " << line;
            
        }
        cout << endl;
            // myfile >> line;
            // cout << " string " << line << endl;

        }
        myfile.close();
    }
    else
         cout << "unable to open the file";
    
}