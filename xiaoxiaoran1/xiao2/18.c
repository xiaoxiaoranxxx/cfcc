#include <stdio.h>

int main()
{
    int x = 10;
    printf("%d,%d,%d\n", x, x++, x++); // 12,11,10

    //i++是先赋值再运算+1；
    //++i是先运算 + 1再赋值；

    int i = 3, j = 0, k = 0, m = 0, n = 0, t = 0, l = 0;

    j = (i++) + (i++) + (i++);
    printf("i=%d,j=%d\n", i, j);  //6,12

    i = 3;
    k = (++i) + (++i) + (++i);
    printf("i=%d,k=%d\n", i, k);  //6,18

    i = 3;
    l = (++i) + (++i) + (i++);
    printf("i=%d,l=%d\n", i, l); //6,15

    i = 3;
    m = (i++) + (++i) + (++i);
    printf("i=%d,m=%d\n", i, m); //6,14

    i = 3;
    n = (i++) * (++i) * (++i);
    printf("i=%d,n=%d\n", i, n); //6,90

    i = 3;
    t = (++i) * (++i) * (i++);
    printf("i=%d,t=%d\n", i, t); //5,125
}
