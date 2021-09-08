#include <iostream>
#include <bits/stdc++.h>
/*小明有一个数组A,有n个不重复的元素,他想知道对于每一个位置的元素 x   在x i​ 之后值大于 x i  的值中的最小值*/
using namespace std;
const int N = 1e6 + 111;
int n, g[N];
set<int> st;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> g[i], st.insert(g[i]);
    for (int i = 1; i <= n; i++)
    {
        auto t = st.lower_bound(g[i]);
        if (++t == st.end())
            cout << -1 << " ", st.erase(--t);
        else
            cout << *(t) << " ", st.erase(--t);
    }
    return 0;
}
/*
case 1
5
1 5 2 4 3

2 -1 3 -1 -1 
case2
5
2 3 1 5 4

3 4 4 -1 -1 


*/
