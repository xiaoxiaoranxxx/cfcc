#include <stdio.h>

void sort(int array[], int n);

int main()
{
    int a[10] = {32, 324, 2, 12, 121, 212, 334, 222, 11, 3222}, i;
    sort(a, 10);
    printf("This is the order of order-->");
    for (i = 0; i < 10;i++)
        printf("%d ", a[i]);
}

void sort(int array[], int n)
{
    int i, j, k, t;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
            if (array[j] < array[k])
                k = j;
        t = array[k];
        array[k] = array[i];
        array[i] = t;
    }
}