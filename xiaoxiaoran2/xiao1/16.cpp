/*比较两个字符串s1和s2的大小，如果s1>s2，则输出一个正数；若s1=s2，则输出0；若s1<s2，则输出一个负数。
要求：不用strcpy函数；两个字符串用gets函数读入。
例如："A"与"C"相比，由于"A"<"C"，应输出负数，同时由于"A"与"C"的ASCII码差值为2，因此应输出"-2"。
同理："And"和"Aid"比较，根据第2个字符比较的结果，"n"比"i"大5，因此应该输出"5"*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int xiao(char x, char y)
{
    if (x == y)
        return 0;
    else
        return x - y;
}
int main()
{
    char x[10], y[10];
    int sum = 0, i;
    cin >> x >> y;
    for (i = 0; i < strlen(x); i++)
        sum += xiao(x[i], y[i]);
    cout << sum << endl;
}