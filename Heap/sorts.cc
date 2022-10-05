#include <stdlib.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int inst = 0;
int tamanho = 10;
int *z;

void HeapSort(int a[], int b[], int c[])
{
    for (int i = 0; i < 3;)
    {
        for (int j = 0; j < 6;)
        {
            for (int k = 0; k < 10;)
            {
                if (a[i] < b[j] && i < 4 /*4 = tamanho vetor A*/)
                {
                    c[k] = a[i];
                    printf("%d \n", c[k]);
                    i++;
                    k++;
                }
                else
                {
                    c[k] = b[j];
                    printf("%d \n", c[k]);
                    j++;
                    k++;
                }
            }
        }
    }
}

int* inicializa(int tam){
    int *v = (int *)malloc(tam*sizeof(int));
    int *p;
    srand(time(NULL));
    for (p = v; p<v+tam; p++)
    {
        *p = rand() % 100;
        /* code */
    }
    return v;
}

void debug(int p, int r,int v[]){
    inst++;

    cout << endl<<" "<< inst<<"instancia p"<< p << "r"<<r<<" -> ";
    for(z=v;z<v+tamanho;z++){
        cout<<" " << *z << " ";
    }
    cout << endl;
}

void intercala1(int p, int q, int r, int v[]){
    int *w;
    w = (int *)malloc((r-p) * sizeof (int));
    int i = p, j=q;
    int k = 0;
    while (i<q && j < r){
        if (v[i] <= v[j]){
        w[k++] = v[i++];
    }
    else{
        w[k++] = v[j++];}
    }
    while (i < q)
    {
        w[k++] = v[i++];
    }
    while (j<r)
    {
        w[k++] = v[j++];
    }
    for (i=p; i<r; ++i)
    {
        v[i] = w[i-p];
    }
    free (w);
} 

int separa(int v[], int p,int r){
    int c = v[r];  //pivô
    int temp, j = p;
    for(int k = p; k<r; ++k){
        if (v[k] <= c){
            temp = v[j];
            v[j] = v[k];
            v[k] = temp;
            ++j;
        }
    }
    v[r] = v[j];
    v[j] = c;
    return j;
}

void QuickSort(int v[], int p, int r){
    if (p < r)
    {
        int j = separa(v,p,r);
        QuickSort(v,p,j-1);
        QuickSort(v,j+1,r);
    }
    
}

void MergeSort(int p,int r,int v[]){
    if(p<r-1){
        int q = (p+q)/2;
        MergeSort(p,q,v);
        MergeSort(q,r,v);
        intercala1(p,q,r,v);
    }
    //debug(p,r,v);
}    
    
int main(void){
    int v[10] ={5,6,1,9,4,8,2,7,3,0} ;
    int veta[] = {0, 3, 4, 7};
    int vetb[] = {1, 2, 5, 6, 8, 9};
    int vetc[10];

    //HeapSort(veta, vetb, vetc);

 
    //v* = inicializa(10);

}