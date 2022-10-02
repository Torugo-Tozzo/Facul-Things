#include <stdio.h>

int vetor[] = {1,2,3,4,5,6,7,8,9,10};
int vetor2[10];

int main(){
    int tam = sizeof(vetor)/sizeof(vetor[0]);
    int lim = tam/2;
    int temp;

    printf("%d \n",tam);
    for(int i=0;i<tam;i++){
        printf(" %d ",vetor[i]);
    }

    /*
    printf("\n");
    for(int i=0;i < lim;i++){
        temp = vetor[i];
        vetor[i]= vetor[(tam-1)-i];
        vetor[(tam-1)-i] = temp;
        printf("\n");
            for(int i=0;i<tam;i++){
            printf(" %d ",vetor[i]);
            }
    }
    */

    /*
    for(int i=0;i < tam;i++){
        vetor2[i]=vetor[(tam-1)-i];
        printf("%d,%d\n",vetor2[i],vetor[i]);
    }
    */
}