#include <stdio.h>
int main()
{
    char w[20], a[5][10] = {"abcdef", "ghijkl", "mnopq", "rstuv", "wxyz"};
    int i, j;
    for (i = 0; i < 5; i++)
    {
        j = 0;
        while (a[i][j] != '\0')
            j++;
        w[i] = a[i][j - 2];
    }
    w[5] = '\0';
    puts(w);
}