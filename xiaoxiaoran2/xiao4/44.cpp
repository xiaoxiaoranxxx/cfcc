#include <iostream>
#include <algorithm>
/*阿里巴巴有一个承重量为 T(T \le 1000)T(T≤1000) 的背包，但并不一定有办法将全部的金币都装进去。他想装走尽可能多价值的金币。所有金币都可以随意分割，分割完的金币重量价值比（也就是单位价格）不变。请问阿里巴巴最多可以拿走多少价值的金币？*/
using namespace std;

struct money
{
    int kg, gg;
    float danjia;
} g[10];
bool cmp(money a, money b) { return a.danjia > b.danjia; }
int main()
{
    int n, t, i;
    cin >> n >> t;
    for (i = 0; i < n; i++)
        cin >> g[i].kg >> g[i].gg, g[i].danjia = g[i].gg / g[i].kg;
    sort(g, g + 10, cmp);
    int bag = 0, value = 0;
    for (i = 0; i < n; i++)
    {
        if (bag + g[i].kg < t)
            bag += g[i].kg, value += g[i].gg;
        else
        {
            value += (t - bag) * g[i].danjia;
            break;
        }
    }
    cout << value;
}

/*
4 50
10 60
20 100
30 120
15 45

240
*/
