#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// 2/1+3/2+5/3+8/5+13/8+...
int main()
{
    int i;
    double sum = 0, s1 = 1, s2 = 2, s3 = 2;
    for (i = 0; i < 20; i++)
    {
        s2 = s1;
        s1 = s3;
        s3 = s1 + s2;
        sum += s1 / s2;
    }
    cout << fixed << setprecision(6);
    cout << sum << endl;

    return 0;
}