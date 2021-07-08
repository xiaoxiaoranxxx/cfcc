/*
ASCII码排序
    题目描述
        输入三个字符后，按各字符的ASCII码从小到大的顺序输出这三个字符。
    输入
        输入数据有多组，每组占一行，有三个字符组成，之间无空格。
    输出
        对于每组输入数据，输出一行，字符中间用一个空格分开。
*/
#include <stdio.h>
void sort(char *x, char *y)
{
    char t;
    t = *x;
    *x = *y;
    *y = t;
}
int main()
{
    int i, j;
    char x[3][3];
    for (i = 0; i < 3; i++)
        scanf("%s", x[i]);
    for (i = 0; i < 3; i++)
        for (j = 0; j < 2; j++)
        {
            if (x[i][j] > x[i][j + 1])
                sort(&x[i][j], &x[i][j + 1]);
            if (x[i][0] > x[i][2])
                sort(&x[i][0], &x[i][2]);
        }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%c ", x[i][j]);
        printf("\n");
    }
}