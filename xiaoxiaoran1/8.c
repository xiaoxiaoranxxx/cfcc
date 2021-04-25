#include <stdio.h>
int main()
{
    int number, sum = 0;
    printf("Please enter a number-->");
    scanf("%d", &number);
    while (number)
    {
        sum += (number % 10);
        number /= 10;
    }
    printf("This is the sum of this-->%d", sum);
}
