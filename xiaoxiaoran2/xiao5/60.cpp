#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
/*统计一个给定字符串中指定的字符出现的次数*/

int showTimes(char c, string s)
{
    int t = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (c == s[i])
            t++;
    }
    return t;
}
int main()
{
    char s1[6], s2[81];
    while (gets(s1))
    {
        if (s1[0] == '#')
            break;
        gets(s2);
        for (int i = 0; s1[i] != '\0'; i++)
            cout << s1[i] << " " << showTimes(s1[i], s2) << endl;
        }
    return 0;
}

/*
Sample Input
I
THIS IS A TEST
i ng
this is a long test string
#

Sample Output
I 2
i 3
  5
n 2
g 2 

*/