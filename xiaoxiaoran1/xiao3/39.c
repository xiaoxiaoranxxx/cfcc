#include <stdio.h>
void fun(int *s, int n1, int n2)
{
    int i, j, t;
    i = n1;
    j = n2;
    while (i < j)
    {
        t = *(s + i);
        *(s + i) = *(s + j);
        *(s + j) = t;
        i++;
        j--;
    }
}
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, i, *p = a;
    fun(p, 0, 3);
    fun(p, 4, 9);
    fun(p, 0, 9);
    for (i = 0; i < 10; i++)
        printf("%d ", *(a + i));
    printf("\n");
}