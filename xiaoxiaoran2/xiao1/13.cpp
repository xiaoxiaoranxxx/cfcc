#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*将一个长度为10的整型数组中的值按逆序重新存放。
如：原来的顺序为1,2,3,4,5,6,7,8,9,0，要求改为0,9,8,7,6,5,4,3,2,1*/

int main()
{
    int a[10];
    int i, m;
    for (i = 0; i < 10; i++)
        cin >> a[i];

    for (i = 0; i < 5; i++)
    {
        m = a[i];
        a[i] = a[9 - i];
        a[9 - i] = m;
    }

    for (i = 0; i < 10; i++)
        cout << a[i] << endl;
    return 0;
}