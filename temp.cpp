#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[100];
    printf("输入一串中文:");

    scanf("%s", &a);
    printf("%s\n", a);
    return 0;
}