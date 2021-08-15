#include <iostream>
#include <bits/stdc++.h>
/*
如果年份只有一个数字大于0，那么小明把他叫做好年份，比如2000，世纪年，现在小明迫切希望知道下一个幸运年是多久，请你帮他计算一下。
比如 现在是2021年，那么下一个幸运年应该是3000年，
如果 现在是19999年，那么下一个幸运年应该是20000年。
像 1，2，3，10，20，30，100，200，都是幸运年。
而11，21，43，110，101，198都不是幸运年。
*/
using namespace std;

int main()
{
    long int num;
    cin >> num;
    while (num--)
    {
        long int xiao;
        scanf("%ld", &xiao);
        if (xiao < 10)
            cout << 1 << endl;
        else
        {
            long int sum = 0, index, result, chu;
            chu = xiao;
            while (xiao)
            {
                sum++;
                index = xiao;
                xiao /= 10;
            }
            result = (index + 1) * pow(10, sum - 1);
            cout << result - chu << endl;
        }
    }
}
/*
3
4
201
4000

1
99
1000
*/