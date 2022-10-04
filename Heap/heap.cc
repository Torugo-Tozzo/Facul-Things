#include <stdio.h>

#include <iostream>

using namespace std;

void HeapSort(int a[], int b[], int c[])
{
    for (int i = 0; i < 3;)
    {
        for (int j = 0; j < 6;)
        {
            for (int k = 0; k < 10;)
            {
                if (a[i] < b[j] && i < 4 /*tamanho vetor A*/)
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
int main(void)
{
    int veta[] = {0, 3, 4, 7};
    int vetb[] = {1, 2, 5, 6, 8, 9};
    int vetc[10];

    HeapSort(veta, vetb, vetc);

}
