#include <stdio.h>
void reverse(int a[], int n)  //逆序
{
    int i, t;
    for (i = 0; i < n / 2; i++)
    {
        t = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = t;
    }
}
int main()
{
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i, s = 0;
    reverse(b, 8);

    // for (i = 0; i < 10; i++) //8 7 6 5 4 3 2 1 9 10
    //     printf("%d ", b[i]);

    for (i = 6; i < 10; i++)
        s += b[i];
    printf("%d\n", s);  //22
}