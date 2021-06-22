#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
    int a = 1, num = 5, count = 1, flag = 1;

    int rand();
    int srand();
    srand((unsigned)time(NULL));
    num = rand() % 10;

    //printf("\nThis generated random number is-->%d\n", num);

    printf("Please enter the number you want to guess(1-10):");

    while (flag)
    {
        scanf("%d", &a);
        if (!(a >= 0 && a <= 10))
            printf("\nThe value input is incorrect, please re-enter-->");
        else
        {
            if (a == num)
            {
                printf("\nyou guessed right\nYou guess count-->%d\nvery good", count);
                flag = 0;
            }
            else if (a > num)
                printf("\n The result of you guess is bigger-->");
            else
                printf("\nThe result of you guess is Smaller-->");
            count++;
        }
    }
}