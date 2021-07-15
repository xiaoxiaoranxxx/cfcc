#include <iostream>
#include <algorithm>
#define maxn 102
using namespace std;
/*表示你喜欢看的节目的总数，然后是n行数据，每行包括两个数据，分别表示第i个节目的开始和结束时间*/
struct Node
{
    int l, r;
} arr[maxn];
bool cmp(Node a, Node b)
{
    return a.r < b.r;
}
int main()
{
    int n, i, ans, flag;
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> arr[i].l >> arr[i].r;
    sort(arr, arr + n, cmp);
    flag = arr[0].r;
    ans = 1;
    for (i = 1; i < n; ++i)
        if (arr[i].l >= flag)
        {
            ++ans;
            flag = arr[i].r;
        }
    cout << ans << endl;
    return 0;
}

/*
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9

*/
