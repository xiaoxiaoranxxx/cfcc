#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

//输出一个整数，代表最多可以满足奶牛日光浴的奶牛数目。

struct Node
{
    int l; //最小阳光需求度
    int r; //最大阳光需求度
} a[2505];
struct bt
{
    int p;   //固定阳光强度
    int tot; //瓶数
} b[2505];
int ans; //共有多少只奶牛可以满足晒太阳
bool cmp1(Node x, Node y)
{
    return x.l > y.l; //按最小阳光的强度从大到小排序
}
bool cmp2(bt x, bt y)
{
    return x.p > y.p; //按固定阳光强度从大到小排序
}
int main()
{
    int c, l;
    cin >> c >> l; //c只奶牛，l种防晒霜
    for (int i = 1; i <= c; i++)
        cin >> a[i].l >> a[i].r;

    for (int i = 1; i <= l; i++)
        cin >> b[i].p >> b[i].tot;

    sort(a + 1, a + c + 1, cmp1);
    sort(b + 1, b + l + 1, cmp2);

    for (int i = 1; i <= c; i++)
        for (int j = 1; j <= l; j++)
            if (a[i].l <= b[j].p && a[i].r >= b[j].p && b[j].tot != 0)
            {
                b[j].tot--;
                ans++;
                break;
            }
    cout << ans << endl;
    return 0;
}

/*
输入样例：
3 2
3 10
2 5
1 5
6 2
4 1
输出样例：
2
*/
