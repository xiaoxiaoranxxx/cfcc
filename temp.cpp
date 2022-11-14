#include <stdio.h>
int main()
{
    int a = 3, b = 4;
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    printf("%d\n", a, b);
    return 0;
}
