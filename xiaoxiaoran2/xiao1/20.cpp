#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//写一个函数，将一个字符串中的元音字母复制到另一个字符串中。在主函数中输入一个字符串，通过调用该函数，得到一个有该字符串中的元音字母组成的一个字符串，并输出。

char xiao(char s)
{
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
        return s;
    else
        return '1';
}

int main()
{
    char s[10];
    int i;
    cin >> s;
    for (i = 0; i < strlen(s); i++)
        if (xiao(s[i]) != '1')
            cout << xiao(s[i]);
    return 0;
}