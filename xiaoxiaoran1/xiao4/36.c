#include <stdio.h>
void sp(int *a)
{
    int b = 2;
    *a = *a * 2;
    printf("%d,", *a); //*a=k=6
    a = &b;            //*a=b=2
    *a = *a * 2;       //*a=b=4
    printf("%d,", *a); //4
}
int main()
{
    int k = 3;
    sp(&k);
    printf("%d\n", k); //6
}