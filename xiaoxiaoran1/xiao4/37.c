#include <stdio.h>
int f(int n)
{
    int t = 0, a = 5;
    if (n / 2)
    {
        int a = 6;
        t += a++;
    }
    else
    {
        int a = 7;
        t += a++;
    }
    printf("-------->a=%d,t=%d ", a,t);
    return t + a++;
}
int main()
{
    int s = 0, i = 0;  //s
    for (; i < 2; i++){
        s += f(i);
        printf("%d\n", s);
    } //i
       
    printf("%d\n", s);
}

// -------->a=5,t=7 12
// -------->a=5,t=7 24
// 24