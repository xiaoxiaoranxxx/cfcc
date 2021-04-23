#include <stdio.h>

int main()
{
    int i, j, row = 0, colum = 0, max;
    int a[3][4] = {{1, 2, 32, 3}, {12, 312, 21, 3}, {2, 3, 12, 2}};
    max = a[0][0];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
                row = i;
                colum = j;
            }
        }
    printf("最大值为:%d\n坐标为:a[%d][%d]", max, row, colum);
}