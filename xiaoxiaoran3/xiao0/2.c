/**
给出n个大于0且小于1000000000的数字，按每位数字之和从大到小打印出来。例如，1234的每位和为10的数字小于83的和为11的数字。如果和相同，则用ASCII进行比较，例如，71小于8，81小于810.
    输入
        第一行是一个数字N，表示要排序的N个数字。(N<100000)
    接下来是用空格隔开的N个数字。
    输出
        以空格分隔的从大到小排序的数字 。
*/
#include <stdio.h>
#include <math.h>
int ssum(int x)
{
    int sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int xiu(int x)
{
    while (x > 10)
        x /= 10;
    return x;
}


int asum(int x, int y)
{
    if (xiu(x) > xiu(y))
        return 0;
    else
        return 1;
}

int main()
{
    int N, i, j, temp;

    N = 12;
    int num[N];
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &num[i]);
    for (i = 0; i < N; i++)
        for (j = 0; j < N - i - 1; j++)
        {
            if (ssum(num[j]) < ssum(num[j + 1]))
            {
                temp = num[j + 1];
                num[j + 1] = num[j];
                num[j] = temp;
            }
            else if (ssum(num[j]) == ssum(num[j + 1]))
                if (asum(num[j], num[j + 1]))
                {
                    temp = num[j + 1];
                    num[j + 1] = num[j];
                    num[j] = temp;
                }
        }
    for (i = 0; i < N; i++)
        printf("%d ", num[i]);
}
