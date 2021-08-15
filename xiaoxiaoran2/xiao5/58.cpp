#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void MonthDay(int year, int yearDay, int *pMonth, int *pDay)
{
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //这个数组保存每月的天数
    if ((year % 4 == 0 && year % 100 != 0 )|| year % 400 == 0)         //判断是否为闰年
        days[1] = 29;                                                //闰年的二月有29天
    *pMonth = 1;                                                     //从一月开始看
    while (yearDay > days[*pMonth - 1])                              //如果哪一天超出这个月
    {
        yearDay -= days[*pMonth - 1]; //求出超出此月的天数
        (*pMonth)++;                  //继续考虑下一月
    }
    *pDay = yearDay;
}

int main()
{
    int year, yearDay, month, day;
    while (cin >> year >> yearDay)
    {
        MonthDay(year, yearDay, &month, &day);
        printf("%d-%02d-%02d\n", year, month, day);
    }
    return 0;
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