#include <stdio.h>

int main()
{
    int a = 100, b = 12, c;
    int *p1 = &a, *p2 = &b, *p;
    printf("%d %d %d %d %d %d", a, b, *p1, *p2, p1, p2); //100 12 100 12 6422016 6422012

    if (a > b)
    {
        p = p1;
        p1 = p2;
        p2 = p;
        // p1 = &b;
        // p2 = &a;
    }                            //只交换地址,不改变值
    printf("\n%d %d", *p1, *p2); //12 100
    printf("\n%d %d", a, b);     //100 12

    if (a > b)
    {
        c = *p1;
        *p1 = *p2;
        *p2 = c;
    }                            //只交换值,不改地址
    printf("\n%d %d", *p1, *p2); //100 12
    printf("\n%d %d", a, b);     //12 100
}