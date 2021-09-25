#define stack_init_size 100
#define stackincrement 30
#define overflow -1
#define ok 1
#define error 0
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int status;
typedef char selemtype;
typedef struct
{
    selemtype *base;
    selemtype *top;
    int stacksize;
} sqstack;

status initstack(sqstack &S)
{
    S.base = (selemtype *)malloc(stack_init_size * sizeof(selemtype));
    if (!S.base)
        exit(overflow);
    S.top = S.base;
    S.stacksize = stack_init_size;
    return ok;
}
status push(sqstack &S, selemtype e)
{
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (selemtype *)realloc(S.base, (S.stacksize + stackincrement) * sizeof(selemtype));
        if (!S.base)
            exit(overflow);
        S.top = S.base + S.stacksize;
        S.stacksize += stackincrement;
    }
    *S.top++ = e;
    return ok;
}
status pop(sqstack &S, selemtype &e)
{
    if (S.top == S.base)
        return error;
    e = *--S.top;
    return ok;
}
status stackempty(sqstack S)
{
    if (S.base == S.top)
        return true;
    return false;
}

void convesion(int num, int Y) //进制转换
{
    sqstack S;
    int result;
    selemtype x, e;
    initstack(S); //初始化栈

    while (num)
    {
        result = num % Y;
        if (result <= 9)
            x = result + '0';
        else
            x = result - 10 + 'A';

        push(S, x);
        num = num / Y;
    }
    printf("%d-->", Y);

    while (!stackempty(S))
    {
        pop(S, e);
        printf("%c", e);
    }

    printf("\n");
}
int main(int argc, char const *argv[])
{
    int number = 15;
    convesion(number, 16);
    convesion(number, 2);
    convesion(number, 8);

    return 0;
}
