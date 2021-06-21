#include <stdio.h>

int main()
{
    int a[3][4] = {1, 2, 3, 4, 8, 1, 2, 3, 3, 9, 2, 1};
    int *p;
    int (*xiao)[4]; //包含4个元素的一维数组

    printf("%d %d %d\n", a[1], a, a + 1); //6422000 6421984 6422000
    printf("%d %d %d\n", a[0][0], *((*a + 0) + 0), *a[0]);

    for (p = a[0]; p < a[0] + 12; p++)
    {
        if ((p - a[0]) % 4 == 0)
            printf("\n");
        printf("%4d", *p);
    }

    printf("\n\n");

    p = a[0];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("a[%d,%d]=%d   ", i, j, *p++);
        printf("\n");
    }

    xiao = a;
    printf("\n%d %d %d\n", *(*(xiao + 0) + 0), *(*(xiao + 1) + 1), *(*(xiao + 2) + 2));
}