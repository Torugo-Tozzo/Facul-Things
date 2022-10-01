#include <iostream>
#include "ordenacao.h"
using namespace std;
int x=11, y=22, z=33;
int *p;
int v[] = {50,51,52,53,54,55,56,57,58,59};
//declaracao de function
void troca(int *a, int *b){ //ass da function
   int aux; // body function
   aux = *a;
   *a = *b;
   *b = aux;
 
}
 
void imprimevetor(int *v){
   for(int *p=v;p < v + 10;p++)
       cout << " " << *p;
   cout << endl;
}
 
// void bubblesort(int *v){
//    int aux;
//    for(int *p = v+9; p > v; p--)
//        for(int *q = v; q < p ;q++)
//            if(*q > *(q+1)){
//                aux = *q;
//                *q = *(q+1);
//                *(q+1) = aux;
//            }
// }

// void insertionsort(int *v){
//    int aux, *q;
//    for(int *p = v+1; p < v+10 ; p++){
//        aux=*p;
//        q= (p-1);
//        while(q >= v && *q > aux){
//             *(q+1) = *q;
//              q--;
//        }
//         *(q+1) = aux;
//    }
// }

// /*
// void insertionsort(int *v){
//    int aux, j;
//    for(int i = 1; i < 10 ; i++){
//        aux=v[i];
//        j=i-1;
//        while(j >=0 && v[j] > aux){
//            v[j+1] = v[j];
//            j--;
//        }
//        v[j+1] = aux;
//    }
// }
// */
 
// void selectionsort(int *v){
//     int aux,*q, *min;
//     for (int *p =v; p<v+10; p++){
//         min = p;
//         aux = *p;
//         for(int *q = p+1; q < v+10; q++)
//             if (*q < aux ){
//                 aux = *q;
//                 min = q;
//             }
//             *min = *p;
//             *p = aux;
//     }
// }
// /*
// void selectionsort(int *v){
//     int aux, j, min;
//     for (int i =0; i<10; i++){
//         min = i;
//         aux = v[i];
//         for(int j = i+1; j < 10; j++)
//             if (v[j] < aux ){
//                 aux = v[j];
//                 min = j;
//             }
//             v[min] = v[i];
//             v[i] = aux;
//     }
// }
// */

int main(int argc, char**argv) {
/*
cout << "antes : " << x << " " << y << " " << z << endl;
 
troca(&x,&y); // function call
 
cout << "dps : " << x << " " << y << " " << z << endl;
*/
 
/*
  cout << "Aritimetica de Ponteiros" << endl;
  cout << endl << "Variaveis" << endl;
  cout << " x: " << x << " y: " << y << " z: " << z << endl;
  cout << "&x" << &x << "&y" << &y << "&z" << &z << endl;
  p=&x;
  cout << "p" << p << "*p " << *p <<endl;
  p++;
  cout << "p" << p << "*p " << *p <<endl;
  p++;
  cout << "p" << p << "*p " << *p <<endl;
  cout << endl << "Vetores \n" << endl;
  cout << " v " << &v << "\n" << endl;
  for (int i = 0; i<10; i++) {
      cout << " i: " << i << " v[i]: " << v[i] << " &v[i]: " << &v[i]<< "\n" << endl;
  }
  for (int i =0;i<10;i++){
      cout << " i: " << i << " *(v+i) " << *(v+i) << " (v+i) " << (v+i) << endl;
  }
  cout <<  endl << "ponteiro com vetores \n" << endl;
  for (p = v; p < v+10; p++ ) {
      cout << " *p: " << *p << " p: " << p << endl;
  }
   */
 
cout << endl << "metodos de ordenação" << endl << endl;
 
int vb0[10] = {0,1,2,3,4,5,6,7,8,9}; // ordenado
int vb1[10] = {5,8,2,0,6,9,1,4,3,7}; // desordenado
int vb2[10] = {9,8,7,6,5,4,3,2,1,0}; // invertido
 
 
cout << " com o vetor ordenado" << endl;
imprimevetor(vb0);
selectionsort(vb0);
imprimevetor(vb0);
 
cout << "  com o vetor desordenado" << endl;
imprimevetor(vb1);
selectionsort(vb1);
imprimevetor(vb1);
 
cout << " com o vetor invertido" << endl;
imprimevetor(vb2);
selectionsort(vb2);
imprimevetor(vb2);
 
 
}
 

