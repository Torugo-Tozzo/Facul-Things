#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){
    int m1[3][4]{
        {0,1,2,3},
        {0,1,2,3},
        {0,1,2,3}
    };
    int m2[4][5]{
        {0,1,2,3,4},
        {0,1,2,3,4},
        {0,1,2,3,4},
        {0,1,2,3,4}
    };
    int m3[3][5];
/*
0	6	12	18	24
0	6	12	18	24
0	6	12	18	24
*/
    
    // int *p = &m1[0][0], *q = &m2[0][0], *r = &m3[0][0];
    //  int *p1, *q1, *r, *p2, *q2;
    //  r = &m3[0][0];
    // for (p1=&m1[0][0];p1 < &m1[0][0]+12; p1+=4)
    // {
    //     for(q1=&m2[0][0];q1 < &m2[0][0]+5; q1++){
    //        for(p2=p1,q2=q1;p2<p1+4;p2++,q2+5)
    //        *r = *r + *p2 * *q2


    //     }
    // }
    


printf("\n\n%d\n\n",m2[1][2]*m1[1][0]);

    for (int i = 0; i < 3;){  
        for (int j = 0; j < 5;){
            m3[i][j] = ((m1[i][j])*(m2[i][j])) +  ((m1[i][j+1])*(m2[i+1][j])) + ((m1[i][j+2])*(m2[i+2][j])) + ((m1[i][j+3])*(m2[i+3][j]));
            printf(" %d ", m3[i][j]);
            j++;
        }
        printf("\n");
        i++;
        j = 0;
    }
    

    
    // for ()
    // {
    //     *r = *p + *q;
    //     cout << " " << *r;
    //     //printf("%d \n",*r);
    // }
    



    return 0;
}