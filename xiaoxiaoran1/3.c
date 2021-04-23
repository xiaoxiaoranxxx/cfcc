#include <stdio.h>
int main()
{
    int a[] = {234112, 4, 124, 21, 2, 4, 23, 5, 23, 123, 5, 23, 5, 231, 22};
    int length, k, i, j;
    length = sizeof(a) / sizeof(a[0]);
    for (i = 0; i < 14; i++)
        for (j = 0; j < 14 - i; j++)
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