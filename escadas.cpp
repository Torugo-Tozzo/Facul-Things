#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

void escada(int n)
{
    for (int index1 = 0; index1 < n; index1++)
    {
        for (int index2 = 0; index2 <= n; index2++)
        {
            if (index2 > index1)
            {
                cout << " ";
            }
            else
            {
                cout << "#";
            }
        };
        cout << "\n";
    };
};

void esscadaInvertida(int n)
{
    for (int index1 = 0; index1 < n; index1++)
    {
        for (int index2 = 0; index2 <= n; index2++)
        {
            if (n - index2 > index1)
            {
                cout << " ";
            }
            else
            {
                cout << "#";
            }
        };
        cout << "\n";
    };
};

int main()
{
    int n;
    cin >> n;
    escada(n);
    esscadaInvertida(n);
};
