#define overflow -1
#define ok 1
#define error 0
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int status;
typedef int elemtype;

typedef struct lnode
{
    elemtype data;
    struct lnode *next;
} lnode, *linklist;

status creatlink1(linklist &L, int n, elemtype *e) //从表头插入
{
    int i;
    linklist p;
    L = (linklist)malloc(sizeof(lnode));
    if (!L)
        return error;
    L->next = NULL;
    for (i = n - 1; i >= 0; --i)
    {
        if (!(p = (linklist)malloc(sizeof(lnode))))
            return error;
        p->data = e[i];
        p->next = L->next;
        L->next = p;
    }
    return ok;
}

void printlink1(linklist L){
    linklist p = L->next;
    while (p)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("end\n");
}

int main()
{
    elemtype e[]={1,22,339,44,55,66,332,188,2333};
    int i, n = 9;
    linklist head;
    elemtype rc;

    if(!creatlink1(head,n,e))  //创建链表
        return error;
    printlink1(head);

    printf("xiaoxiaoran");
}
