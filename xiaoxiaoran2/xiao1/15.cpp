#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
using namespace std;

/*有一行电文，已按如下规律译成密码：
A-->Z        a-->z
B-->Y        b-->y
C-->X        c-->x
......         ......
即第一个字母变成第26个字母，第i个字母变成第（26-i+1)个字母，非字母字符不变。要求根据密码译回原文，并输出。*/

int main()
{
    char str1[26], str2[26], sr, area;
    int i, n;
    for (i = 0; i <= 25; i++)
    {
        str1[i] = 'a' + i;
        str2[i] = 'A' + i;
    }

    for (n = 0; n <= 9; n++)
    {
        scanf("%c", &area);
        for (i = 0; i <= 25; i++)
            if (area == str1[i])
                sr = str1[24 - i + 1];
        for (i = 0; i <= 25; i++)
            if (area == str2[i])
                sr = str2[24 - i + 1];
        if (area < 65 || (area > 90 && area < 97) || area > 122)
            sr = area;
        printf("%c", sr);
    }
}
