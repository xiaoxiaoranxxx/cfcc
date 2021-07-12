#include <cstdio>
#include <cstring>

int main()
{
    char str[50];
    gets(str);
    int len = strlen(str);

    for (int i = 0; i <= len; i++)
    {
        char a = str[i];
        if ('a' <= a && a <= 'z')
        {
            str[i] = 'a' + 'z' - a;
        }
        else if ('A' <= a && a <= 'Z')
        {
            str[i] = 'A' + 'Z' - a;
        }
    }

    puts(str);
    return 0;
}
