#define overflow -1
#define ok 1
#define error 0
#define maxsize 16
#define increment 10
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int status;
typedef int elemtype;
typedef struct
{
    elemtype *elem;
    int length;
    int listsize;
} sqlist;

status initlist(sqlist &L)
{
    L.elem = (elemtype *)malloc(maxsize * sizeof(elemtype));
    if (!L.elem)
        exit(overflow);
    L.length = 0;
    L.listsize = maxsize;
    return ok;
}

status insertlist(sqlist &L, int i, elemtype e)
{
    if (i < 1 || i > L.length)
        return error;
    elemtype *p;
    int j;
    if (L.length >= L.listsize)
    {
        p = (elemtype *)realloc(L.elem, (L.listsize + increment) * sizeof(elemtype));
        if (!p)
            exit(overflow);
        L.elem = p;
        L.listsize += increment;
    }
    for (j = L.length - 1; j >= i - 1; --j)
        L.elem[j + 1] = L.elem[j];
    L.elem[j + 1] = e;
    L.length++;
    return ok;
}

void printlist(sqlist L)
{
    int i;
    for (i = 0; i < L.length; i++)
        printf("%d ", L.elem[i]);
    printf("\n");
}

status dellist(sqlist &L, int i, elemtype &e)
{
    int j;
    if (i < 1 || i > L.length)
        return error;
    e = L.elem[i - 1];
    for (j = i; j < L.length; j++)
        L.elem[j - 1] = L.elem[j];
    --L.length;
    return ok;
}

int main()
{
    sqlist LL;
    elemtype x;
    int r, i;

    if (!initlist(LL)) //初始化
        return error;

    for (i = 0; i < 10; i++)
        LL.elem[i] = i * 8;
    LL.length += 10;

    //printf("value index-->");  //插入
    //scanf("%d %d", &x, &r);
    x = 188, r = 3;
    insertlist(LL, r, x);

    printlist(LL);

    //printf("index-->");  //删除
    //scanf("%d", &r);
    dellist(LL, r, x);

    printlist(LL);


    printf("xiaoxiaoran");
}
