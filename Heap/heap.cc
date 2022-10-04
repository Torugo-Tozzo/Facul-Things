#include <stdio.h>

#include <iostream>

using namespace std;

void HeapSort(int a[],int b[],int c[]){
    
    for(int i=0;i < 3;){

        for (int j = 0; j < 5;){
            if(a[i]<b[j]){
            printf("%d \n",a[i]);
            i++;
            }
            else{
            printf("%d \n",b[j]);
            j++;
            }
        }
        
        
    }        
}
    




int main(void){
    int veta[] = {0,3,4,7};
    int vetb[] = {1,2,5,6,8,9};
    int vetc[10];

HeapSort(veta,vetb,vetc);

    //
}