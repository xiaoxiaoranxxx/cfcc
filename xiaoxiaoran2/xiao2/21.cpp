#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*你的任务是计算若干整数的和。
输入
    输入的第一行是一个正数N，表示后面有N行。每一行的第一个数是M，表示本行后面还有M个数。
输出
    对于每一行数据需要在相应的行输出和。*/
    
int main()
{

    int a, b, num = 1, sum = 0, i,N;
    int x[10];
    cin >> N;
    while (N--)
    {
        cin >> num;
        for (i = 0; i < num; i++)
        {
            cin >> x[i];
            sum += x[i];
        }
        cout << sum << endl;
        sum = 0;
    }
}