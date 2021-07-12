#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//从键盘上输入3个字符串，求出其中最大者。输入3行，每行均为一个字符串。
string compp(string &s1, string &s2)
{
    if (s1 >= s2)
        return s1;
    else
        return s2;
}
int main()
{
    string s1, s2, s3, s4, s5;
    cin >> s1 >> s2 >> s3;
    s4 = compp(s1, s2);
    s5 = compp(s4, s3);
    cout << s5 << endl;
}