#include <stdio.h>
#include <string.h>

struct student
{
    int num;
    char name[20];
    char sex;
} a = {121, "xiao", 'x'}, b;

struct person
{
    char name[20];
    int count;
} leader[3] = {"a", 0, "b", 0, "c", 0};

int main()
{
    struct student c;
    struct student d={222,"we",'r'};

    printf("%s\nb.name-->", a.name);
    scanf("%s", &b.name);
    printf("b.name=%s\n", b.name);

    char leader_name[20];
    for (int i = 0; i < 3; i++)
    {
        printf("\n-->");
        scanf("%s", leader_name);
        if (strcmp(leader_name, leader[0].name) == 0)
            leader[0].count += 3;
        else
            leader[1].count += 2;
    }
    for (int i = 0; i < 3; i++)
        printf("\nleader[%d]-->%d ", i, leader[i].count);
}