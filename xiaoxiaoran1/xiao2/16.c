#include <stdio.h>

int main()
{
    int f(int);
    f(3);
    f(3);
}

int f(int a)
{
    auto int b = 3;  //自动变量,调用时分配,结束即释放
    static int c = 1; //静态变量,调用时分配,结束保留原值
    printf("a+3-->%d\n", a + b);
    printf("c-->%d\n", c++);
}
