#include <stdio.h>

int main()
{
    int a[10] = {1, 2, 3, 1, 4, 56, 7, 8, 1, 9};
    int *xiao = a; // 数组名即为指针常量,存放a[0]的地址

    printf("%d %d\n", *xiao, xiao); //1 6422000

    for (int i = 0; i < 10; i++, xiao++)
    {
        printf("%d ", *xiao);
    }

    printf("\n");

    xiao = a; //指针复位
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", *xiao++); //先运算,再加 //同级,自左向右
    }

    printf("\n");

    for (xiao = a; xiao < (a + 10); xiao++)
        printf("%d ", *xiao);
}
