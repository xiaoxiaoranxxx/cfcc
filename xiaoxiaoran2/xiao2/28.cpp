#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <map>
using namespace std;
/*map（映射）——map就是从键（key）到值（value）的映射。例如可以这样用：
先定义map<string,int> m;    赋值m["green"]=8 。看起来就是数组的高级版，可以改变下标的表示。
当遇到让我们计算 一篇文章中某单词出现的次数时，（如果它只提问一次单词a出现的次数，那么我们直接遍历一次，但是如果它问了很多次时，总不能一遍遍遍历吧，会超时的）这时候就用到映射了。*/

map<string, int> m;

int main()
{
    char s[100];
    string a;
    while (gets(s))
    {
        stringstream ss(s);
        while (ss >> a)
        {
            if (m.count(a) == 0)
                m[a] = 0;
            m[a]++;
        }
        map<string, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++)
            cout << it->first << " " << it->second << endl;
    }
}
// a s a d ew s ew d
