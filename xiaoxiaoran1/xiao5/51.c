#include <stdlib.h>
#include <stdio.h>
void fun(int a[], int n, int *max, int *d)
{
    int i;
    *max = a[0];
    *d = 0;
    for (i = 0; i < n; i++)
        if (a[i] > *max)
        {
            *max = a[i];
            *d = i;
        }
}

int main()
{
    int i, x[20] = {41, 17, 34, 0, 19, 24, 288, 8, 12, 14}, max, index, n = 10;
    // for (i = 0; i < n; i++)
    // {
    //     x[i] = rand() % 50;
    //     printf("%4d", x[i]);
    // }
    printf("\n");
    fun(x, n, &max, &index);
    printf("Max =%5d ,  Index =%4d\n", max, index);
}