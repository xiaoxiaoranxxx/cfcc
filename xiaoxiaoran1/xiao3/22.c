#include <stdio.h>
void main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    while (m != n)
    {
        while (m > n)
            m = m - n;
        while (n > m)
            n = n - m;
    }
    printf("%d\n", m);
}