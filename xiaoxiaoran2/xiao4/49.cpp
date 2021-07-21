#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int p[N]; //定义多个集合

/*
A地区在地震过后，连接所有村庄的公路都造成了损坏而无法通车。政府派人修复这些公路。
给出A地区的村庄数N，和公路数M，公路是双向的。并告诉你每条公路的连着哪两个村庄，并告诉你什么时候能修完这条公路。问最早什么时候任意两个村庄能够通车，即最早什么时候任意两条村庄都存在至少一条修复完成的道路（可以由多条公路连成一条道路）

输入格式:
第1行两个正整数N,M

下面M行，每行3个正整数x,y,t，告诉你这条公路连着x,y两个村庄，在时间t时能修复完成这条公路。
N⩽1000,M⩽100000
x⩽N,y⩽N,t⩽100000,x⩽N,y⩽N,t⩽100000

*/
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    /*    经上述可以发现,每个集合中只有祖宗节点的p[x]值等于他自己,即:    p[x]=x;    */
    return p[x]; //找到了便返回祖宗节点的值
}
struct node
{
    int a;
    int b;
    int time;
} a[2000];
bool cmp(node a, node b)
{
    return a.time < b.time;
}
int main()
{
    int n, m, i;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        cin >> a[i].a >> a[i].b >> a[i].time;
    sort(a, a + n, cmp);
    for (i = 0; i < m; i++)
        p[i] = i;
    for (i = 0; i < m; i++)
    {
        if (find(p[a[i].a]) != find(p[a[i].b]))
        {
            p[find(p[a[i].a])] = find(p[a[i].b]);
            n--;
        }
        if (n == 1)
        {
            cout << a[i].time;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}

/*
4 4
1 2 6
1 3 4
1 4 5
4 2 3

*/
