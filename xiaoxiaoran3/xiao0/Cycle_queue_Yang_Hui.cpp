#include <stdio.h>
#include <malloc.h>
#define maxsize 100
#define ok 1
#define error 0

typedef int status;
typedef int qelemtype;
typedef struct
{
    qelemtype *base;
    int front;
    int rear;
} sqqueue;

status initqueue(sqqueue &Q)
{
    Q.base = (qelemtype *)malloc(maxsize * sizeof(qelemtype));
    if (!Q.base)
        return error;
    Q.front = Q.rear;
    return ok;
}
status enquene(sqqueue &Q, qelemtype e)
{
    if ((Q.rear + 1) % maxsize == Q.front) //队列满
        return error;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % maxsize;
    return ok;
}
status dequene(sqqueue &Q, qelemtype &e)
{
    if (Q.front == Q.rear) //队列空
        return error;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % maxsize;
    return ok;
}
status outputqueue(sqqueue Q)
{
    while (Q.front != Q.rear)
    {
        printf("%d ", Q.base[Q.front]);
        Q.front = (Q.front + 1) % maxsize;
    }
    printf("\n");
    return ok;
}

void out_YangHui_number(int n)
{
    sqqueue Q;
    initqueue(Q);
    qelemtype x;

    int s1 = 0, s2 = 1, i, j;
    printf("1\n");
    enquene(Q, s1 + s2);
    for (i = 2; i <= n; i++)
    {
        s1 = 0;
        for (j = 1; j <= i - 1; j++)
        {
            dequene(Q, x);
            s2 = x;
            printf("%d ", s2);
            enquene(Q, s1 + s2);
            s1 = s2;
        }
        printf("1");
        enquene(Q, 1 + s2);
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    // 队列功能测试
    // sqqueue Q;
    // initqueue(Q);
    // qelemtype x;
    // for (int i = 0; i < 5; i++)
    // {
    //     x = i * 8;
    //     enquene(Q, x);
    // }
    // outputqueue(Q);
    // dequene(Q, x);
    // outputqueue(Q);

    out_YangHui_number(8);
    
    return 0;
}
