#include <stdio.h>
int main()
{
    int a = 1, num = 5, count = 1;
    printf("Please enter the number you want to guess(1-10):");

    while (num)
    {
        scanf("%d", &a);
        if (!(a >= 0 && a <= 10))
        {
            printf("The value input is incorrect, please re-enter\n-->");
            continue;
        }
        if (a == num)
        {
            printf("\nyou guessed right\nYou guess count-->%d\nvery good", count);
            break;
        }
        else if (a > num)
        {
            printf("\n The result of you guess is bigger-->");
            count++;
            continue;
        }
        else
        {
            printf("\nThe result of you guess is Smaller-->");
            count++;
            continue;
        }
    }
}