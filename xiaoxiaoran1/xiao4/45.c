#include<stdio.h>
main()
{
    FILE *fp;
    int i, a[6] = {1, 2, 3, 4, 5, 6}, k;
    fp = fopen("data.dat", "w+");
    fprintf(fp, "%d\n", a[0]);
    for (i = 1; i<6; i++)
    {
        rewind(fp);
        fprintf(fp, "%d\n", a[i]);
    }
    rewind(fp);
    fscanf(fp, "%d", &k);
    fclose(fp);
    printf("%d\n", k);
}