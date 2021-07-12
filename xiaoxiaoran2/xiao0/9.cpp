#include <iostream>
#include <bits/stdc++.h>

//求圆周率pi的近似值
int main()
{
    double PI = 0, mu = 1;
    int i = 1;
    while (mu <= 1000000)
    {
        if (i % 2)
            PI += 1 / mu;
        else
            PI -= 1 / mu;
        mu += 2;
        i++;
    }
    PI *= 4;
    printf("PI=%10.8f", PI);
    return 0;
}
