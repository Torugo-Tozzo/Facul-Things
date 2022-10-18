#include <iostream>
#include <fstream>

using namespace std;

typedef struct Veiculo{
    string modelo;
    string marca;
    string versão;
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
            bd[i] = new Veiculo;
            switch (i)
            {
            case 0:
                bd[i]->modelo = line;
                break;
            case 1:
                bd[i]->marca = line;
                break;
            case 2:
                bd[i]->versão = line;
                break;
            case 3:
                bd[i]->ano = line;
                break;
            case 4:
                bd[i]->kilometragem = line;
                break;
            case 5:
                bd[i]->motor = line;
                break;
            case 6:
                bd[i]->consumo = line;
                break;
            case 7:
                bd[i]->moua = line;
                break;
            case 8:
                bd[i]->direcao = line;
                break;
            case 9:
                bd[i]->cor = line;
                break;
            case 10:
                bd[i]->portas = line;
                break;
            case 11:
                bd[i]->placa = line;
                break;
            
            default:
                break;
            }
            

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
