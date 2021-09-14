#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
    int number;        //数据域，存储编号数值
    struct Node *next; //指针域，指向下一个节点
} Node;

/*创建链表节点的函数*/
Node *CreatNode(int x)
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->number = x; //将链表节点的数据域赋值为编号
    p->next = NULL;
    return p;
}

/*创建环形链表，存放整数1到n*/
Node *CreatJoseph(int n)
{
    Node *head, *p, *q;
    int i;
    for (i = 1; i <= n; i++)
    {
        p = CreatNode(i); //创建链表节点，并完成赋值
        if (i == 1)       //如果是头结点
            head = p;
        else //不是头结点，则指向下一个节点
            q->next = p;
        q = p;
    }
    q->next = head; //末尾节点指向头结点，构成循环链表
    return head;
}

void RunJoseph(int n, int m)
{
    Node *p, *q;
    p = CreatJoseph(n);  //创建循环链表形式的约瑟夫环
    int i, count = 0;    //记录次数
    while (p->next != p) //循环条件，当前链表数目大于1
    {
        for (i = 1; i < m - 1; i++) //开始计数
            p = p->next;
        //第m个人出圈
        q = p->next;
        p->next = q->next;
        p = p->next;
        count++;
        printf("第%d次出圈的元素为%d--\n", count, q->number); //输出序号
        free(q);
    }
    printf("\n最后剩下的数为：%d\n", p->number);
}


int main()
{
    RunJoseph(11, 3);
}
