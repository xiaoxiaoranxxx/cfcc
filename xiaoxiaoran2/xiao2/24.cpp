#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;
/*给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。
我们假设对于小写字母有'a' < 'b' < ... < 'y' < 'z'，而且给定的字符串中的字母已经按照从小到大的顺序排列*/

void permute(string s, int i)
{
    if (i >= s.size())
        cout << s << endl;
    for (int j = i; j < s.size(); j++)
    {
        swap(s[i], s[j]);
        permute(s, i + 1);
    }
}

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    permute(s, 0);

    // char a[6];
    // int ll;
    // cin >> a;
    // ll = strlen(a);
    // do
    // {
    //     for (int i = 0; i < ll; i++)
    //         cout << a[i];
    //     cout << endl;
    // } while (next_permutation(a, a + ll));
    // return 0;
}