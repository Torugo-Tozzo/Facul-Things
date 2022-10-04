#include <iostream>

using namespace std;

int inst =0;

    
 // namespace std;

int fatorial(int n){
    cout << "instancia " << ++inst << " quando n = " << n << "\n";
    if (n<2)
        return 1;
        else
            return n*fatorial(n-1);
}



int fatorial2(int n){
        if(n<0)
        return -1;
    int fat = 1;
        while (n>1){
        fat = fat*n;
        n--;
        }
        return fat;
}

int main(void){
    int n, ft;
    cout << "Fatorial" << endl;
    cout << "digite n";
    cin >> n;
    ft = fatorial(n);
    if(ft<0)
    cout << "valor invalido" <<endl;
    cout << "fatorial de " << n << " = " << ft;

}

