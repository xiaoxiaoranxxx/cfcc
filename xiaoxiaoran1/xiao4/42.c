#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ss
{
    char name[10];
    int age;
    char sex;
} std[3], *p = std;

struct person
{
    float weight;
    char sex;
    char name[10];
} rec, *ptr;


int main()
{

    scanf("%d", &(*p).age);

    scanf("%s", &std->name);

    scanf("%c", &std[0].sex);

    scanf("%c", &(p->sex));

    ptr = &rec;
    
    scanf("%s", ptr->name);

    scanf("%s", rec.name);

    scanf("%s", (*ptr).name);

    return 0;
}