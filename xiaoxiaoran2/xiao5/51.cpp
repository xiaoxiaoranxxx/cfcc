#include <iostream>
using namespace std;
const int N = 8;
int a[N], n, ans, sum;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], ans += a[i];
    for (int i = 0; i < n; i++)
    {
        if (sum > 0)
            sum += a[i];
        else
            sum = a[i];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}
/*
给出一个长度为 nn 的序列 aa，选出其中连续且非空的一段使得这段和最大。

输入格式
第一行是一个整数，表示序列的长度 nn。

第二行有 nn 个整数，第 ii 个整数表示序列的第 ii 个数字 a_ia i
​
7
2 -4 3 -1 2 -4 3

*/
