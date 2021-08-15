#include <iostream>
#include <bits/stdc++.h>
/*小明有一个数组A,有n个不重复的元素,他想知道对于每一个位置的元素 x   在x i​ 之后值大于 x i  的值中的最小值*/
using namespace std;

int main()
{
    int a[10000];
    int index, min, i, j, num;
    cin >> num;
    for (i = 0; i < num; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < num; i++)
    {
        min = a[i];
        for (j = i; j < num; j++)
        {
            if (a[j] > a[i])
            {
                min = a[j];
                break;
            }
        }
        for (j = i; j < num; j++)
        {
            if (a[j] > a[i] && a[j] < min)
                min = a[j];
        }
        if (a[i] == min)
            cout << -1 << " ";
        else
            cout << min << " ";
    }
}

/*
case 1
5
1 5 2 4 3

2 -1 3 -1 -1 
case2
5
2 3 1 5 4

3 4 4 -1 -1 


*/
