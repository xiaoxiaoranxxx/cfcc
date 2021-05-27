#include <stdio.h>
int main()
{
    int a = 25, b = 9, i;
    printf("The %d & %d is %d \n", a, b, a & b); //计算两个数的与运算-->&
                                                 //00000011010
                                                 //00000010011
                                                 //00000010010

    printf("The %d | %d is %d \n", a, b, a | b); //计算两个数的或运算-->|
                                                 //00000011010
                                                 //00000010011
                                                 //00000011011

    printf("The %d ^ %d is %d \n", a, b, a ^ b); //计算两个数的异或运算-->^
                                                 //00000011010
                                                 //00000010011
                                                 //00000001001

    printf("The ~%d is %d \n", a, ~a);           //计算a进行取反运算的值-->~
                                                 //00000011010
                                                 //11111100101
                                                 
    printf("decimal\t\tshift left by\tresult\n");
    for (i = 1; i < 9; i++)
    {
        b = a << i;                          //使a左移i位
        printf("%d\t\t%d\t\t%d\n", a, i, b); //输出当前左移结果
    }
    printf("decimal\t\tshift right by\tresult\n");
    for (i = 1; i < 9; i++)
    {
        b = a >> i;                          //使a右移i位
        printf("%d\t\t%d\t\t%d\n", a, i, b); //输出当前右移结果
    }
}
