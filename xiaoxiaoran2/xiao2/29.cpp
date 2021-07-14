#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

/*
已知学生的信息包括姓名、成绩。编写程序从键盘输入5个学生的信息，输出其中成绩最高者的姓名和成绩。
输入格式:
  每条信息占一行，姓名和成绩之间用空格分隔。
输出格式:
  输出成绩保留1位小数。
*/
using namespace std;
struct student
{
    char xh[5];
    float score;
} s[5];

int main()
{

    for (int i = 0; i < 5; i++)
        cin >> s[i].xh >> s[i].score;

    float max = s[0].score;

    int num = 0;
    for (int i = 0; i < 5; i++)

        if (s[i].score > max)
        {
            swap(s[i].score, max);
            num = i;
        }
    
    cout << fixed << setprecision(1);
    cout << "name = " << s[num].xh << ", score = " << max << endl;

    return 0;
}
