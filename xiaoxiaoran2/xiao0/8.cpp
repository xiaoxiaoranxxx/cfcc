#include <iostream>
#include <bits/stdc++.h>

#define x 100000

using namespace std;

int main()
{
    //某企业发放的奖金根据利润提成。利润I低于或等于100000时，奖金可提10 % ；
    //利润高于100000元，低于200000元（100000 < I <= 200000）时，
    //低于100000元的部分仍按10 % 提成，高于100000元的部分提成比例为7 .5 % ；
    //200000 < I <= 400000时，低于200000元的部分仍按上述方法提成（下同），高于200000元的部分按5 % 提成；
    //400000 < I <= 600000元时，高于400000元的部分按3 % 提成；
    //600000<I <= 1000000时，高于600000元的部分按1.5 % 提成；
    //I> 1000000元时，超过1000000元的部分按1 % 提成。 
    
    double money, xiao = 0;
    cin >> money;
    cout << fixed << setprecision(2);

    if (money <= x)
        xiao = money * 0.1;
    else if (money > x && money <= 2 * x)
        xiao = ((money - x) * 0.075) + 10000;
    else if (money > 2 * x && money <= 4 * x)
        xiao = (money - 2 * x) * 0.05 + 10000 + 7500;
    else if (money > 4 * x && money <= 6 * x)
        xiao = (money - 4 * x) * 0.03 + 10000 + 7500 + 10000;
    else if (money > 6 * x && money <= 10 * x)
        xiao = (money - 6 * x) * 0.015 + 10000 + 7500 + 10000 + 6000;
    else
        xiao = (money - 10 * x) * 0.01 + 10000 + 7500 + 10000 + 6000 + 6000;
    cout << xiao << endl;
}