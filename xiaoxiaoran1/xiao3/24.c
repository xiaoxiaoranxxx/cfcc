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
int add(int x, int y)
{
    return x + y;
}
int Pointer_to_function_parameters(int x, int y, int (*p)(int, int))
{
    int max(int, int);
    int add(int, int);
    int xiao;
    xiao = (*p)(x, y);
    return xiao;
}

//返回指针
float *Return_pointer(float (*pointer)[4], int n)
{
    float *pt;
    pt = *(pointer + n);
    return pt;
}

//指针数组
void Pointer_array(char *name[], int n)
{
    int i = 0;
    char *p;
    p = name[0];
    while (i < n)
    {
        p = *(name + i++);
        printf("%s\n", p);
    }
}

//多重指针
void Multiple_pointer()
{
    // int a[2] = {1, 2};
    // int *num[2] = {&a[0], &a[1]};
    // int **P , i;
    // p = num[0];  //报错 未定义p
    // for (i = 0; i < 2; i++,p++)
    //     printf("%d ", **p);
}

int main()
{
    //pointer_adjustment();

    int a;

    //a = Pointer_to_function_parameters(1, 2, max);  //2

    // float score[][4] = {{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}};
    // float *p = Return_pointer(score, 0);
    // for (int i = 0; i < 4;i++)
    //     printf("%f ", *(p + i));

    // char *name[] = {"aaaa", "ssss", "ddddd", "fffffff", "ggggg"};
    // Pointer_array(name, 5);

    Multiple_pointer();
}