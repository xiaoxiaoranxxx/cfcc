#include <iostream>
#include <cmath>
/*首先输出两人生日相隔的天数，如果两人的生日相隔天数是奇数，则输出“对不起，我们有缘无份”，如果是偶数，则输出“傻瓜，我心仪的人其实是你呀！”*/

using namespace std;
struct Date
{
    int y; //year
    int m; //month
    int d; //day in month
};
bool isLeap(int y) //判断是否是闰年
{
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)); //真返回为1，假为0
}
int daysOfMonth(int y, int m)
{
    int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m != 2)
        return day[m - 1];
    else
        return 28 + isLeap(y);
}
int daysOfDate(Date d) //计算一共的天数
{
    int days = d.d;
    for (int y = 1; y < d.y; y++) //计算年
        days += 365 + isLeap(y);
    for (int m = 1; m < d.m; m++) //计算月
        days += daysOfMonth(d.y, m);
    return days;
}
int main()
{
    Date d1, d2;
    char x;
    int xiao;
    cin >> d1.y >> x >> d1.m >> x >> d1.d;
    cin >> d2.y >> x >> d2.m >> x >> d2.d;
    int days1 = daysOfDate(d1);
    int days2 = daysOfDate(d2);
    xiao = abs(days2 - days1);
    cout << "我们生日相差" << xiao << "天" << endl;
    if (xiao % 2 == 0)
        cout << "傻瓜,我心仪的人其实是你呀!" << endl;
    else
        cout << "对不起,我们有缘无份" << endl;
    return 0;
}
