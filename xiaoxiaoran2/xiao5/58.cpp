#include <iostream>
#include <bits/stdc++.h>
/*小明只知道现在是多少年,今年过了多少天,请你帮小明计算出现在的日期.*/
using namespace std;
int g[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n, m;
int main()
{
    while (cin >> n >> m)
    {
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0))
            g[2] = 29;
     
        int _1(1), _2(m);
        while (_2 > g[_1])
            _2 -= g[_1], _1++;
        printf("%04d-%02d-%02d\n", n, _1, _2);
    }
}
/*
2000 3
2000 31
2000 40
2000 60
2000 61
2001 60

2000-01-03
2000-01-31
2000-02-09
2000-02-29
2000-03-01
2001-03-01
*/