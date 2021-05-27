#include <stdio.h>
#include <string.h>

int sort(char **p) //用冒泡法对5个字符串排序
{
    int i, j;
    char *pchange; //声明指向字符变量的指针
    for (i = 0; i < 5; i++)
        for (j = i + 1; j < 5; j++)
            //将p指向的指针数组元素所指向的第i个元素和其后面的元素比较，
            //将最小的换到i的位置上。
            if (strcmp(*(p + i), *(p + j)) > 0)
            {
                pchange = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = pchange;
            }
    return 0;
}

int main()
{
    int i;
    char **p, *pstr[5], str[5][10];
    for (i = 0; i < 5; i++)
        //将第i个字符串的首地址赋予指针数组pstr的第i个元素
        pstr[i] = str[i];
    printf("Please input the string:\n");
    for (i = 0; i < 5; i++) //输入5个字符串
        scanf("%s", pstr[i]);
    p = pstr;
    sort(p);
    printf("Sorting result:\n");
    for (i = 0; i < 5; i++) //输出排序后的结果
        printf("%s\n", pstr[i]);
}
