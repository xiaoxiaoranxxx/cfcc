#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a, b, c, r1, r2;
    cin >> a >> b >> c;
    if ((b * b - 4 * a * c) >= 0)
    {
        r1 = ((-b) + sqrt(b * b - 4 * a * c)) / (2 * a);
        r2 = ((-b) - sqrt(b * b - 4 * a * c)) / (2 * a);
        printf("r1=%7.2lf\n", r1);
        printf("r2=%7.2lf\n", r2);
    }
    else
        cout << "No real roots!" << endl;
    return 0;
}