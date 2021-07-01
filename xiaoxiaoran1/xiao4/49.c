#include <stdio.h>

#include <stdlib.h>

void main()

{

    int a[100], i;

    FILE *fp;

    for (i = 0; i < 20; i++)

        a[i] = rand() % 100 + 1;

    fp = fopen("data.txt", "w+b");

    fwrite(a, sizeof(int), 20, fp);

    fclose(fp);
}
