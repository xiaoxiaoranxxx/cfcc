#include <stdio.h>
#include <math.h>
#include <time.h>

int rand_num()
{
    int rand();
    int srand();
    int num;
    srand((unsigned)time(NULL));
    num = rand();
    return num % 1000;
}

char operator()
{
    int a = rand_num() % 5;
    switch (a)
    {
    case 1:
        return '+';
    case 2:
        return '-';
    case 3:
        return '*';
    case 4:
        return '/';
    case 5:
        return '%';
    default:
        return '%';
    }
}

float Calculate(char s, float x, float y)
{
    switch (s)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    case '%':
        return (int)x % (int)y;
    default:
        return 0;
    }
}

int produce_algorite()
{
    int a1 = rand_num()/11, a2 = rand_num() /12, a3;
    float result;
    int static count = 1;
    int static right_count = 0;
    char sign = operator();
    printf("\nquestion,This is your %d question-->", count++);
    printf("%d%c%d=", a1, sign, a2);
    scanf("%d", &a3);
    result = Calculate(sign, a1, a2);
    if (a3 == result)
    {
        printf("\nvery good-->xiu xiu xiu\n");
        right_count++;
    }
    else
    {
        printf("false\n");
        printf("the right is --> %d%c%d=%f\n\n", a1, sign, a2, result);
    }
    return right_count;
}

int Number_questions(int n)
{
    int i = 0, t;
    while (i < n)
    {
        t = produce_algorite();
        i++;
    }
    printf("\nhappy everyday \nbyebye");
    return t;
}

int main()
{
    int xiao, xiu, t;
    printf("Daily Issue,happy everyday\n");
    printf("Please enter the number of questions you want to do-->");
    scanf("%d", &xiao);
    xiu = Number_questions(xiao);

    printf("\nThis is correct count-->%d", xiu);
}
