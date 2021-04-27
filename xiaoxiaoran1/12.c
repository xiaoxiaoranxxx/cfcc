#include <stdio.h>
#include <string.h>

void xiao_strcat(char x[], char y[]);
int xiao_strclen(char x[]);
void xiao_strcpy(char x[], char y[]);
int xiao_strcmp(char x[], char y[]);

int main()
{
    int i = 0, j = 0, i1, i2;
    char a1[81] = {"xiaoxiaoran"}, a2[81] = {"zuixiu!"}, a3[81];

    xiao_strcat(a1, a2);
    printf("\n%s", strcat(a1, a2));

    i1 = xiao_strclen(a1);
    i2 = xiao_strclen(a1);
    printf("\n%d=%d\n", i1, i2);

    strcpy(a2, "xxx");
    xiao_strcpy(a2, "xxx");
    puts(a2);

    i = strcmp(a1, a2);
    i = xiao_strcmp(a1, a2);
    if (i > 0)
        printf("Big");
    else if (i == 0)
        printf("==");
    else
        printf("Small");
}

void xiao_strcat(char x[], char y[])
{
    int i = 0;
    int j = 0;
    while (x[i] != '\0')
        i++;
    while (y[j] != '\0')
        x[i++] = y[j++];
    x[i] = '\0';
    puts(x);
}

int xiao_strclen(char x[])
{
    int i = 0;
    while (x[i] != '\0')
        i++;
    return i;
}

int xiao_strcmp(char x[], char y[])
{
    int i;
    for (i = 0; !(x[i] == '\0' && y[i] == '\0'); i++)
    {
        if (x[i] > y[i])
            return x[i];
        if (x[i] < y[i])
            return -y[i];
    }
    return 0;
}

void xiao_strcpy(char x[], char y[])
{
    int i;
    if (x[0] != 0)
    {
        memset(x, 0, 200);
    }
    for (i = 0; i < strlen(y); i++)
        x[i] = y[i];
}
