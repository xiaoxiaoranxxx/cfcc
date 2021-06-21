#include <stdio.h>

int main()
{
    int num = 0, zhimu = 0, eng = 0, d_eng = 0, null = 0, qita = 0;
    char xiao;
    xiao = getchar();
    while (xiao != '\n')
    {
        if (xiao >= '0' && xiao <= '9')
            num++;
        else if (xiao == ' ')
            null++;
        else if (xiao >= 'a' && xiao <= 'z')
            eng++;
        else if (xiao >= 'A' && xiao <= 'Z')
            d_eng++;
        else
            qita++;
        printf("%c", xiao);
        xiao = getchar();
    }
    printf("\n this number-->%d\n this space-->%d\n this other-->%d", num, null, qita);
    printf("\n this capital letter-->%d\n This lowercase letter is-->%d\n", d_eng, eng);
}