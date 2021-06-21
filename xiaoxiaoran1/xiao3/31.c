#include <stdio.h>

union data
{
    int ii;
    char cc;
    float ff;
} a1;

int main()
{
    //共用体只能有一个成员,其他会覆盖
    union data a2;

    a2.ii = 100;
    printf("%d %c %f\n", a2.ii, a2.cc, a2.ff);

    a2.cc = 'g';
    printf("%d %c %f\n", a2.ii, a2.cc, a2.ff);

    a2.ff = 1.111;
    printf("%d %c %f\n", a2.ii, a2.cc, a2.ff);

    enum weekday
    {
        qqqqqqq,
        wwwwwwwww,
        eeeeee,
        ree,
        te,
        y,
        u
    };

    enum weekday xiao;

    xiao = y;

    
}