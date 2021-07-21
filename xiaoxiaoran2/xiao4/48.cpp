#include <iostream>
using namespace std;
const int N = 3000;
//对于每一个 Z​i​​ =2 的操作，都有一行输出，每行包含一个大写字母，为 Y 或者 N 。
int p[N]; //定义多个集合
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    /*    经上述可以发现,每个集合中只有祖宗节点的p[x]值等于他自己,即:    p[x]=x;    */
    return p[x]; //找到了便返回祖宗节点的值
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    while (m--)
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (*op == '1')   
            p[find(a)] = find(b);    //集合合并操作
        else if (find(a) == find(b)) //如果祖宗节点一样,就输出yes
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
/*
4 7
2 1 2
1 1 2
2 1 2
1 3 4
2 1 4
1 2 3
2 1 4

*/
