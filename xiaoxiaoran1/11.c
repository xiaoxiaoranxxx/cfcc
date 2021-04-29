#include <stdio.h>
#include <string.h>

int login(char account[]);
void password(char x[]);
//account-->xiao123 password-->xiao
int main()
{
    int result = 1;
    char xiao_account[10];
    char xiao_password[10];
    while (result)
    {
        result = login(xiao_account);
        if (result == 1)
            printf("\nAccount does not exist\nPlease re-enter-->");
    }
    password(xiao_password);
}

int login(char account[])
{
    char x_login[] = {"xiao123"};
    printf("Please enter your account-->");
    gets(account);
    if (strcmp(strlwr(account), strlwr(x_login)) == 0)
        return 0;
    return 1;
}

void password(char password[])
{
    int num = 3;
    char x_password[10] = {"xiao"};
    printf("\nPlease enter your password-->");
    while (1)
    {
        gets(password);
        if (strcmp(password, x_password) == 0)
        {
            printf("login successful");
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
