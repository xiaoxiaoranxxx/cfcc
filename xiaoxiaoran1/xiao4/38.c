#include <stdio.h>

int main()
{
    int a = 1;

    if (1)
    {
        int a = 2;
        printf("%d", a);
    }
    printf("%d", a);
}  //21