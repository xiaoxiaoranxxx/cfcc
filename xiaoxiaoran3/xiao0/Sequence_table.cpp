#define overflow -1
#define ok 1
#define error 0
#define maxsize 6
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

//typedef struct 是为了使用这个结构体方便。
//若用typedef，可以这样写：typedef struct node{}NODE; 。在申请变量时就可以这样写：NODE n;其实就相当于 NODE 是node 的别名。区别就在于使用时，是否可以省去struct这个关键字。

status initlist(sqlist &L)
{
    L.elem = (elemtype *)malloc(maxsize * sizeof(elemtype));
    if (!L.elem)
        exit(overflow);
    L.length = 0;
    L.listsize = maxsize;
    return ok;
}

int main()
{
    sqlist LL;
    elemtype x;
    int r, i;

    if (!initlist(LL)) //初始化
        return error;

    printf("xiaoxiaoran");
}
