#include <stdio.h>

void move(char, char);
void hanoi(int, char, char, char);

int main()
{
    int m;
    printf("Enter m-->");
    scanf("%d", &m);
    hanoi(m, 'a', 'b', 'c');
}

void move(char x, char y)
{
    printf("put %c-->%c\n", x, y);
}
void hanoi(int n, char x1, char x2, char x3)
{
    if (n == 1)
        move(x1, x3);
    else
    {
        hanoi(n - 1, x1, x3, x2);
        move(x1, x3);
        hanoi(n - 1, x2, x1, x3);
    }
}