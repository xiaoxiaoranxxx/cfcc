#include <stdio.h>
#include <string.h>

int main()
{
    int num = 3;
    char password[10];
    char x_password[10] = {"xiao"};
    printf("Please enter your password-->");
    while (1)
    {

        gets(password);
        if (strcmp(password, x_password) == 0)
        {
            printf("xiuxiu");
            break;
        }
        else
        {
            printf("\nIncorrect password\nRe-enter your password(You still have %d chance)-->", num - 1);
            num--;
            if (num == 0)
            {
                printf("Not allowed to enter,Have exited");
                break;
            }
        }
    }
}