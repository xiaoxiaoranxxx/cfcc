#include <stdio.h>
int main()
{
    int a=1, num = 5, count = 1;
    printf("请输入你要猜的数字(1-10):");
    while (num)
    {
        scanf("%d", &a);
        if (!(a >= 0 && a <= 10))
        {
            printf("\n输入的数字有误..请重新输入-->");
            continue;
        }
        if (a == num)
        {
            printf("\n恭喜你猜对了\n你一共猜了%d次.秀秀的", count);
            break;
        }
        else if (a > num)
        {
            printf("\n大了,请重新输入-->");
            count++;
            continue;
        }
        else
        {
            printf("\n小了,请重新输入-->");
            count++;
            continue;
        }
    }
}