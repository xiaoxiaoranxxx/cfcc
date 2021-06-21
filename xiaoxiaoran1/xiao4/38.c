#include <stdio.h>
int *f(int *s, int *t)
{
    int *k;
    if (*s < *t)
    {
        k = s;
        s = t;
        t = k;
    }
    return s;
}
int main()
{
    int i = 3, j = 5, *p = &i, *q = &j, *r;
    r = f(p, q);
    printf("%d,%d,%d,%d,%d\n", i, j, *p, *q, *r); // 3 5 3 5 5
}