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
/* matrix esperada!
0	6	12	18	24
0	6	12	18	24
0	6	12	18	24
*/
    // COM PONTEIROS SERIA ALGO ASSIM +-:
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
        // for ()
    // {
    //     *r = *p + *q;
    //     cout << " " << *r;
    //     //printf("%d \n",*r);
    // }

    for (int i = 0; i < 3; i++){  
        for (int j = 0; j < 5; j++){
            m3[i][j] = ((m1[i][0])*(m2[0][j])) 
            +  ((m1[i][1])*(m2[1][j])) 
            + ((m1[i][2])*(m2[2][j])) 
            + ((m1[i][3])*(m2[3][j]));
            printf(" %d ", m3[i][j]);
    }
    printf("\n");
}

    return 0;
}
