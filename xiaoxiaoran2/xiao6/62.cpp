#include <bits/stdc++.h>

/*对每个单词来说，输出一行内容，统计这个单词在第几行出现过，并且按从小到大排序，序号不应该重复输出，序号间用空格分隔，如果这个单词一次也没出现过，则输出一个空行*/

using namespace std;
int n, m;
string s;
unordered_map<string, vector<int>> mp;
int main()
{
    cin >> n;
    getchar();
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> s)
            mp[s].push_back(i);
    }
    cin >> m;
    while (m--)
    {
        cin >> s;
        unordered_map<int, int> st;
        for (auto i : mp[s])
            if (!st[i])
                cout << i << " ", st[i]++;
        cout << endl;
    }
}
/*
3
how are you i am fine think you
do i do o pick you come on well are your all
but i think you is were took wall
5
you
i
all
wall
were

1 2 3 
1 2 3 
2 
3 
3 
*/