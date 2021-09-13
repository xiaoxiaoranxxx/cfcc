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

status creatlink(linklist &L, int n, elemtype *e) //从表头插入
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

void printlink(linklist L)
{
    linklist p = L->next;
    while (p)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("end\n");
}

status insertlink(linklist &L, int i, elemtype e)
{
    linklist s, p = L;
    int k = 0;
    while (p->next != NULL && k < i - 1)
    {
        p = p->next;
        ++k;
    }
    if (!p->next || k > i - 1)
        return error;
    if (!(s = (linklist)malloc(sizeof(lnode))))
        return overflow;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return ok;
}

status dellink(linklist L, int i, elemtype &e)
{
    int k;
    linklist q, p = L;
    while (p->next != NULL && k < i - 1)
    {
        p = p->next;
        k++;
    }
    if (!p->next || k > i - 1)
        return error;
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return ok;
}

void freelink(linklist &L)
{
    linklist p, q;
    p = L;
    while (p != NULL)
    {
        p = L->next;
        q = p->next;
        free(q);
    }
    L = NULL;
}
int main()
{
    elemtype e[] = {1, 22, 339, 44, 55, 66, 332, 188, 2333};
    int i, n = 9;
    linklist head;
    elemtype rc;

    if (!creatlink(head, n, e)) //创建链表
        return error;
    printlink(head);

    // printf("index value-->");
    // scanf("%d%d", &i, &rc);
    i = 2, rc = 9999;
    if (!insertlink(head, i, rc)) //插入
        return error;
    printlink(head);

    // printf("index value-->");
    // scanf("%d%d", &i, &rc);
    i = 2, rc = 9999;
    if (!dellink(head, i, rc)) //删除
        return error;
    printlink(head);

    freelink(head); //释放链表
    if (head)
        printf("xiaoxiaoran");
}
