#include <stdio.h>

int main()
{
    int a[15], i, j, number, top, bottom, mid, address, flag = 1, sign;
    char continue_xiu;
    for (i = 1, j = 0; i <= 30; i += 2, j++)
        a[j] = i;
    for (i = 0; i < 15; i++)
        printf("%d ", a[i]);
    while (flag)
    {
        printf("\nPlease enter the number you are looking for-->");
        scanf("%d", &number);
        sign = 0;
        top = 0;
        bottom = sizeof(a) / sizeof(a[0]) - 1; //14
        if ((number < a[0]) || (number > a[bottom]))
            address = -1;
        while ((!sign) && (top <= bottom))
        {
            mid = (top + bottom) / 2;
            if (number == a[mid])
            {
                address = mid;
                printf("\nfound %d,the address is a[%d]\n", number, address);
                sign = 1;
            }
            else if (number < a[mid])
                bottom = mid - 1;
            else
                top = mid + 1;
        }
        if (!sign || address == -1)
            printf("cannot find %d\n", number);
        printf("continue(y/n)-->");
        scanf("%s", &continue_xiu);
        if (continue_xiu == 'n')
            flag = 0;
    }
}
