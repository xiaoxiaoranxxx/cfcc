#include <stdio.h>

void f(int b[], int n, int flag)

{
    int i, j, t;

    for (i = 0; i < n - 1; i++)

        for (j = i + 1; j < n; j++)

            if (flag ? b[i] > b[j] : b[i] < b[j])
            {
                t = b[i];
                b[i] = b[j];
                b[j] = t;
            }
}

int main()

{
    int a[10] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10}, i;

    f(&a[2], 5, 0);
    for (i = 0; i < 10; i++)
        printf("%d,", a[i]);

    printf("\n");

    f(a, 5, 1);
    for (i = 0; i < 10; i++)
        printf("%d,", a[i]);
}
