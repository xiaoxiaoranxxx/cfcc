#include <stdio.h>

int main()
{
    int a1, a2, result, z_result;
    char sign;
    printf("请输入等式:");
    scanf("%d%c%d=%d", &a1, &sign, &a2, &result);
    if (sign == '+')
        z_result = a1 + a2;
    else if (sign == '-')
        z_result = a1 - a2;
    else if (sign == '*')
        z_result = a1 * a2;
    else if (sign == '/')
        z_result = a1 / a2;
    else if (sign == '%')
        z_result = a1 % a2;

    if (result == z_result)
        printf("\nperfect");
    else
        printf("\nerror\n这正确的是:%d%c%d=%d", a1, sign, a2, z_result);
}