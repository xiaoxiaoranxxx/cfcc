#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*给定一个整数数组 x 和一个整数目标值 k，请你在该数组中找出 和为目标值 k 的那 两个 整数，请你判断是否能够满足条件. */
const int N = 1e5 + 111;
int g[N], n, k;
unordered_map<int, int> mp;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> g[i], mp[g[i]]++;
    for (int i = 1; i <= n; i++)
    {
        if (mp[k - g[i]])
        {
            if (g[i] == k - g[i] && (mp[k - g[i]] >= 2))
            {
                cout << "yes";
                return 0;
            }
            else if (g[i] != k - g[i])
            {
                cout << "yes";
                return 0;
            }
        }
    }
    cout << "no" << endl;
    return 0;
}

/*

4 9
2 7 11 15
yes

3 2
1 2 3
no
*/
