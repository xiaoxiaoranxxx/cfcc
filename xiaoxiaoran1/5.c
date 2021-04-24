#include <stdio.h>
int main()
{
    int number, a[4], i, count = 0;
    printf("Please enter a number of no more than 5 digits:");
    scanf("%d",&number);
    a[4] = number / 10000;
    a[3] = number % 10000 / 1000;
    a[2] = number % 1000 / 100;
    a[1] = number % 10000 % 100 / 10;
    a[0] = number % 10000 % 100 % 10;
    printf("\n positive sequence-->");
    for (i = 4; i >= 0; i--)
    {
        if (!a[i] == 0)
        {
            count++;
            printf("%d ", a[i]);
        }
    }
    printf("\n reverse order-->");
    for (i = 0; i <= 4; i++)
    {
        if (!a[i] == 0)
            printf("%d ", a[i]);
    }
    printf("\n The number of digits of this-->%d", count);
}