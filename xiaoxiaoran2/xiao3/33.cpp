#include <iostream>
using namespace std;
/*X同学出生在“2002年01月07日”，已知1900年1月1日是星期一，你知道他出生的那天是星期几吗？随意给你一个日期，你知道是星期几吗？*/
int CaculateWeekDay(int y, int m, int d)
{
    if (m == 1 || m == 2) //把一月和二月换算成上一年的十三月和是四月
    {
        m += 12;
        y--;
    }
    int Week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    return Week + 1;
}

int main()
{
    int year, month, day;
    char x;
    cin >> year >> x >> month >> x >> day;
    cout << CaculateWeekDay(year, month, day);
    return 0;
}
