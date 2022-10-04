#include <iostream>

using namespace std;

int inst = 0;

void fibonacci(int n, int ult, int penult){
    cout << endl << " instancia " << ++inst << " ";
    cout << ult << " ";
    if(ult + penult < n)
        fibonacci(n, ult+penult,ult);
}

int main(void){
    int n, ft;
    cout << "calculo da sequencia de fibonacci : " << endl;
    cout << "Digite n \n";
    cin >> n;
    cout << "Sequencia = ";
    fibonacci(n,1,0); 
}