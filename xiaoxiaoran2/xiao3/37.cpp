#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
/*编写程序，从键盘输入 n (n<10)个学生的学号（学号为4位的整数，从1000开始）、成绩并存入结构数组中，
按成绩从低到高排序并输出排序后的学生信息。输入输出示例：括号内为说明，无需输入输出*/
using namespace std;
struct student
{
    int xh;
    int cj;
} s[10];

bool cmp(student a, student b)
{
    return a.cj < b.cj;
}

int main()
{
    int n = 3;
    for (int i = 0; i < n; i++)
        cin >> s[i].xh >> s[i].cj;

    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n - i - 1; j++)
    //         if (s[j].cj > s[j + 1].cj)
    //             swap(s[j], s[j + 1]);

    sort(s, s + n,cmp);

    for (int i = 0; i < n; i++)
        cout << s[i].xh << " " << s[i].cj << endl;
    return 0;
}
/*

1000 85
1001 90
1002 75

*/
