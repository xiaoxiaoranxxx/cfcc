#include <iostream>
using namespace std;
const int N = 10;
int a[N], b[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i] - a[i - 1]; //构建差分数组
    }
    int l, r, c;
    while (m--)
    {
        scanf("%d%d%d", &l, &r, &c);
        b[l] += c; //将序列中[l, r]之间的每个数都加上c
        b[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i] + a[i - 1]; //前缀和运算
        printf("%d ", a[i]);
    }
    return 0;
}
/*
输入一个长度为 n 的整数序列。

接下来输入 m 个操作，每个操作包含三个整数 l,r,c，表示将序列中 [l,r] 之间的每个数加上 c。

请你输出进行完所有操作后的序列。

输入格式
第一行包含两个整数 n 和 m。

第二行包含 n 个整数，表示整数序列。

接下来 m 行，每行包含三个整数 l，r，c，表示一个操作。

6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1

*/
