#include <stdio.h>
#include <string.h>

struct student
{
    long num;
    char name[20];
    char sex;
    float score;
};

struct student max(struct student stu[])
{
    int i, m = 0;
    for (i = 0; i < 4; i++)
        if (stu[i].name > stu[m].name)
            m = i;
    return stu[m];
}

void print(struct student sss)
{
    printf("%d", sss.num);
}

int main()
{
    struct student stu_1;
    struct student *p;
    p = &stu_1;
    stu_1.num = 12212;
    strcpy(stu_1.name, "xiaoxiaoran");
    stu_1.sex = 'n';

    printf("%d,%d,%d\n", stu_1.num, (*p).num, p->num);

    struct student xiao[4] = {{1, "1", '1', 1.1}, {2, "1", '1', 1.1}, {3, "1", '1', 1.1}, {4, "1", '1', 1.1}};
    for (p = xiao; p < xiao + 4; p++)
        printf("%d ", p->num);
    printf("\n");

    p = xiao;
    print(max(p));
}
