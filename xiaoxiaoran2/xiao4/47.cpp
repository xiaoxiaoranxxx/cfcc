#include <iostream>
using namespace std;
const int N = 100010;
int p[N]; //定义多个集合

/*
若某个家族人员过于庞大，要判断两个是否是亲戚，确实还很不容易，现在给出某个亲戚关系图，求任意给出的两个人是否具有亲戚关系。
规定：x和y是亲戚，y和z是亲戚，那么x和z也是亲戚。如果x,y是亲戚，那么x的亲戚都是y的亲戚，y的亲戚也都是x的亲戚。

输入格式:
第一行：三个整数n,m,p，（n<=5000,m<=5000,p<=5000），分别表示有n个人，m个亲戚关系，询问p对亲戚关系。

输出格式:
P行，每行一个’Yes’或’No’。表示第i个询问的答案为“具有”或“不具有”亲戚关系。
*/

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x]; //找到了便返回祖宗节点的值
}
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        p[find(a)] = find(b);
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &a, &b);
        if (find(a) == find(b))
            printf("Yes\n");
        else
            printf("No\n");
    }

    // while (m--)
    // {
    //     char op[2];
    //     int a, b;
    //     scanf("%s%d%d", op, &a, &b);
    //     if (*op == 'M')
    //         p[find(a)] = find(b);    //集合合并操作
    //     else if (find(a) == find(b)) //如果祖宗节点一样,就输出yes
    //         printf("Yes\n");
    //     else
    //         printf("No\n");
    // }
    return 0;
}

/*
6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6

*/
