#include <stdio.h>
int main()
{
    int i, t[][3] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (i = 0; i < 3; i++)
        printf("%d ", t[2 - i][i]);
}