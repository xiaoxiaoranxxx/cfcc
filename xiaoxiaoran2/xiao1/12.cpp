#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*有一个已排好序的数组，要求输入一个数后，按原来排序的规律将它插入到数组中。
假设数组长度为10，数组中前9个数（这9个数要求从键盘上输入，输入时要满足自小到大的输入顺序）已经按从小到大进行排序。
然后再从键盘上输入一个整数，将此整数插入到前有序的9个数中，使得最终的10个数依然是从小到大有序的。

输入
    第一行输入以空格分隔的9个整数数，要求按从小到大的顺序输入。
    第二行输入一个整数
输出
    从小到大输出这10个数，每个数一行。*/
int main()
{
    int a[10];
    int i, t, m;
    for (i = 0; i < 9; i++)
        cin >> a[i];

    cin >> a[9];

    for (i = 0; i < 10; i++)
        for (t = 0; t < 10 - i - 1; t++)
            if (a[t] > a[t + 1])
            {
                m = a[t];
                a[t] = a[t + 1];
                a[t + 1] = m;
            }
    for (i = 0; i < 10; i++)
        cout << a[i] << endl;
    return 0;
}