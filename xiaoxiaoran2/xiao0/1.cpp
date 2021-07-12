#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    cout << "hello world"
         << "xiaoxiaoran" << endl;
    int x;
    cout << "input a number--> ";
    cin >> x;
    cout << "the number is --> " << x << endl;

    //输入字符串
    string s1;
    getline(cin, s1);
    cout << s1 << endl;

    //设置保留两位小数
    cout << fixed << setprecision(2);

    return 0;
}