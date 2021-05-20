#include <stdio.h>

void sort(int *x, int n)
{
    int i, j, k, t;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
            if (*(x + j) > *(x + k))
                k = j;
        if (k != i)
        {
            t = *(x + i);
            *(x + i) = *(x + k);
            *(x + k) = t;
        }
    }
}

int main()
{
    int a[] = {234112, 4, 124, 21, 2, 4, 23, 5, 23, 123, 5, 23, 5, 231, 22};
    int length, k, i, j;
    length = sizeof(a) / sizeof(a[0]);
    // printf("-->%d\n", length);//15

    sort(a, length);
    for (i = 0; i < length; i++)
        printf("%d ", a[i]);
    printf("\n");

    for (i = 0; i < length; i++)
        for (j = 0; j < length - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                // k = a[j + 1];
                // a[j + 1] = a[j];
                // a[j] = k;
                k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
        }

    for (i = 0; i < length; i++)
        printf("%d ", a[i]);
}