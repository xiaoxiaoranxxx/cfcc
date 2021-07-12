#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, temp;
    char x[10];
    for (i = 0; i < 10; i++)
        cin >> x[i];

    for (i = 0; i < 10; i++)
        for (j = 0; j < 10 - i - 1; j++)
            if (x[j] > x[j + 1])
            {
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }

    for (i = 0; i < 10; i++)
        cout << x[i] << endl;
}
