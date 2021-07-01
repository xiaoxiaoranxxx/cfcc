#include <string.h>
#include <stdio.h>

void f(char *s, char *t) //e c

{
    char k;

    k = *s;
    *s = *t;
    *t = k;

    //printf("%c %c-->", *s, *t); //c e

    s++; //g
    t--; //a

    //printf("%c %c\n", *s, *t); //c e

    if (*s)
        f(s, t);
}

int main()

{
    char str[10] = "abcdefg", *p;

    p = str + strlen(str) / 2 + 1;

    // printf("%c\n", *p);

    f(p, p - 2);

    printf("%s\n", str);
}
