#include <stdio.h>

//指针引用字符串

void pointer_Quote_string()
{
    char xiao[] = "xiaoxiaoran zui xiuxiuxiu";
    char *x_xiao = "xiaoxiaoranxiuxiuxiu";
    printf("%s--%c--%s", xiao, xiao[0], x_xiao);
}

//指针调指向的函数
int max(int x, int y)
{
    return x > y ? x : y;
}
void pointer_adjustment()
{
    int max(int, int);
    int (*p)(int, int);
    int a = 2, b = 3, c;
    p = max;
    c = (*p)(a, b);
    printf("%d", c);
}

//指向函数的指针作函数参数
int add(int x,int y)
{
    return x + y;
}
int Pointer_to_function_parameters(int x,int y,int (*p)(int,int))
{
    int max(int, int);
    int add(int, int);
    int xiao;
    xiao = (*p)(x, y);
    return xiao;
}



int main()
{
    //pointer_adjustment();
    int a;
    a=Pointer_to_function_parameters(1, 2, add);
    printf("%d", a);
}