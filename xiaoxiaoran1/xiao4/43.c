#include <stdio.h>
#include <stdlib.h>

struct A
{
    int a;
    char b[10];
    double c;
};
struct A f(struct A t);
int main()
{
    struct A a = {1001, "ZhangDa", 1098.0};
    a = f(a);
    printf("%d,%s,%6.1f\n", a.a, a.b, a.c);
}
struct A f(struct A t)
{
    t.a = 1002;
    strcpy(t.b, "ChangRong");
    t.c = 1202.0;
    return t;
}