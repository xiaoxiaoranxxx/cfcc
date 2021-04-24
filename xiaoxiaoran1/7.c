#include <stdio.h>
int main()
{
    int a=1, num = 5, count = 1;
    printf("请输入要猜的数字(1-10):");
    
    while (num)
    {
        scanf("%d", &a);
        if (!(a >= 0 && a <= 10))
        {
            printf("\n-->");
            continue;
        }
        if (a == num)
        {
            printf("\n?????????\n?????????%d??.?????", count);
            break;
        }
        else if (a > num)
        {
            printf("\n????,??????????-->");
            count++;
            continue;
        }
        else
        {
            printf("\n????,??????????-->");
            count++;
            continue;
        }
    }
}