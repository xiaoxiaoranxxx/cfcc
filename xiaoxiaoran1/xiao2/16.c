#include <stdio.h>
void get_put()
{
    char ch;
    ch = getchar();
    if (ch != '\n')
        get_put();
    putchar(ch);
}
int main()
{
    get_put();
    printf("\n");
}

// 1234  ->  4321