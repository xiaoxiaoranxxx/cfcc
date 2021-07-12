#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// Fibonacci数列
int main()
{
    int a = 1, b = 1;
    int n;
    cin >> n;
    if (n <= 2)
        cout << "1" << endl;
    else
    {
        int s, u, v;
        for (s = 3; s <= n; s++)
        {
            v = b;
            u = a + b;
            a = v;
            b = u;
        }
        cout << b << endl;
    }
    return 0;
}
