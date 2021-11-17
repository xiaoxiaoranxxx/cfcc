#include <stdio.h>

int main()
{
    int i, j, k;
    for (i = 1; i < 10; i++)
    {
        k = i;
        for (j = 1; j <= 10 - i; j++, k++)
            printf("%dx%d=%d ", i, k, i * k);
        printf("\n");
    }
}  
