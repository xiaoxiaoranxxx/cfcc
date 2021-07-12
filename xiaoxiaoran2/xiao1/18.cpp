#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 将一个2行3列的矩阵（二维数组）行列互换，存储到另一个3行2列的矩阵中。

//     要求以整型数据为例来解答。

int main()
{
    int a[2][3], b[3][2], i;
    for (i = 0; i < 3; i++)
    {
        cin >> a[0][i];
        b[i][0] = a[0][i];
    }
    for (i = 0; i < 3; i++)
    {
        cin >> a[1][i];
        b[i][1] = a[1][i];
    }
    for (i = 0; i < 3; i++)
        cout << b[i][0]<< " " << b[i][1] << endl;
}