#include <stdio.h>

struct student
{
    int num;
    float score;
    struct student *next;
};

int main()
{
    struct student a, b, c, *head, *p;
    a.num = 11111;
    a.score = 88.8;
    b.num = 22222;
    b.score = 33.8;
    c.num = 33333;
    c.score = 238.8;

    head = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    p = head;

    do
    {
        printf("%ld %5.1f\n", p->num, p->score);
        p = p->next;
    } while (p != NULL);
}