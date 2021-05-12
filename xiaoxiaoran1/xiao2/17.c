
//file1.c
#include <stdio.h>

int A; //定义外部变量

//static int A; //使A的作用域只限于本文件

int main()
{
    extern int xiao();
    printf("xiaoxiaoran\n");
    xiao();
    return 0;
}

//file2.c
extern int A; // f1定义的外部变量导入到f2文件
int xiao()
{
    printf("66666");
    return 0;
}