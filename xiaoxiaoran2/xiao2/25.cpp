#include <stdio.h>
#include <stdlib.h>
int main()
{
    //输入一个字符串，长度小于等于200，然后将数组逆置输出。
    int i = 0;
    char arry[201];
    char a;
    while (1)
    {
        a = getchar();
        for (i = 0; a != '\n' && i < 200; i++)
        {
            arry[i] = a;
            a = getchar();
        }
        i = i - 1;
        while (i >= 0)
        {
            printf("%c", arry[i]);
            i--;
        }
        printf("\n");
    }
    return 0;
}