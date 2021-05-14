
#include <stdio.h>
#include <math.h>

int main()
{
    float x, y;

    while (1)
    {
        printf("\nenter x-->");
        scanf("%f", &x);
        if (x < 40)
        {
            if (x >= 20)
            {
                y = -0.5 * x + 20;
                break;
            }
            else if (x >= 10)
            {
                y = 10;
                break;
            }
            else if (x >= 0)
            {
                y = x;
                break;
            }
            else
            {
                y = 0;
                break;
            }
        }
        else
        {
            printf("\nRepetition x");
            continue;
        }
    }
    printf("this is y-->%f", y);
}
