#include <bits/stdc++.h>
using namespace std;

char line[5000005];
long long ans, x, y;
std::stack<int> s;
const int MOD = 10000;
int main()
{
    scanf("%s", line);
    int n = strlen(line);
    for (int i = 0; i < n; ++i)
    {
        if (line[i] < '0' || line[i] > '9')
            s.push(x), x = 0;
        else
            x = x * 10 + line[i] - '0';
    }
    s.push(x), x = 0; //最后一个数字在循环中会被漏掉，所以要补上
    for (int i = n - 1; i >= 0; --i)
    {
        if (line[i] >= '0' && line[i] <= '9')
            continue;
        if (line[i] == '+')
        {
            ans = (ans + s.top()) % MOD;
            s.pop();
        }
        else if (line[i] == '*')
        {
            x = s.top() % MOD;
            s.pop();
            y = s.top() % MOD;
            s.pop();
            x = x * y % MOD;
            //随时取模防止溢出
            s.push(x);
        }
    }
    ans = (ans + s.top()) % MOD;
    s.pop(); //同样最后一个数字会漏掉...
    printf("%lld\n", ans);
    return 0;
}