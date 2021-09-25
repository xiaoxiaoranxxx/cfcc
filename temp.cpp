#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define TRUE 1
#define FLASE 0
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int Status;
typedef int ElemType;

typedef struct LNode
{
    ElemType data;      //数据域
    struct LNode *next; //指针域
} LNode, *LinkList;

//用头插法逆序建立带头结点的单链表
Status CreatLinkL1(LinkList &L, int n, ElemType *E)
{
    int i;
    LinkList p;
    L = (LinkList)malloc(sizeof(LNode));
    if (!L)
        return ERROR;
    L->next = NULL; //建立头结点，假定与元素结点结构相同
    for (i = n - 1; i >= 0; --i)
    { //从后向前输入元素
        if (!(p = (LinkList)malloc(sizeof(LNode))))
            ; //生成新结点
        return ERROR;
        p->data = E[i];
        //将新结点插入到表头
        p->next = L->next;
        L->next = p;
    }
    return OK;
}

//用尾插法建立带头结点的单链表
Status CreatLinkL2(LinkList &L, int n, ElemType *E)
{
    int i;
    LinkList p, r;
    L = (LinkList)malloc(sizeof(LNode));
    if (!L)
        return ERROR;
    r = L; //初始化尾指针
    for (i = 0; i < n; i++)
    {
        if (!(p = (LinkList)malloc(sizeof(LNode))))
            ; //生成新结点
        return ERROR;
        p->data = E[i];
        //将新结点插入到表尾
        r->next = p;
        r = r->next;
    }
    r->next = NULL;
    return OK;
}

//在带头结点的单链表L中第i个位置插入元素e
Status InsertLinkL(LinkList &L, int i, ElemType e)
{
    LinkList s;
    LinkList p = L; //初始化，p指向头结点
    int k = 0;      //k位计数器
    while (p->next != NULL && k < i - 1)
    { //定位指针p指向第i-1个元素或p为空
        p = p->next;
        k++;
    }
    if (!p->next || k > i - 1)
        return ERROR;                           //定位插入点失败
    if (!(s = (LinkList)malloc(sizeof(LNode)))) //申请元素e的结点空间
        return OVERFLOW;                        //内存无空闲单元，无法申请到空间
    s->data = e;                                //将元素e存放进新开辟的结点s里
    //将新结点s插入到链表中
    s->next = p->next;
    p->next = s;
    return OK;
}

//在带头结点的单链表L中，删除第i个元素，并由e返回其值
Status Del_LinkL1(LinkList L, int i, ElemType &e)
{
    int k = 0;      //k初始化，k为计数器
    LinkList p = L; //p指向头结点
    LinkList q;
    //逐一移动指针p，直到p指向第i-1个结点或p为空
    while (p->next != NULL && k < i - 1)
    {
        p = p->next;
        k++;
    }
    if (!p->next || k > i - 1)
        return ERROR;  //无法删除
    q = p->next;       //令q指向待删除的元素结点
    p->next = q->next; //将q结点从链表中删除
    e = q->data;
    free(q);
    return OK;
}

//在带头结点的单链表中删除值为e的结点，成功返回OK,失败返回ERROR
Status Del_LinkL2(LinkList &L, ElemType e)
{
    LinkList p, q; //p为被删除结点的前驱，q为被删除结点
    p = L;
    q = L->next;
    //定位指针q指向被删除的结点
    while (q->data != e && q)
    {
        p = q;
        q = q->next;
    }
    if (p == NULL)
        return ERROR;  //链表为空
    p->next = q->next; //被删结点从链表中脱离
    free(q);           //释放被删除结点的空间
    return OK;
}

//在带头结点的单链表L中删除值为e的所有结点，成功返回TURE,没有找到返回FLASE
Status Del_LinkL3(LinkList &L, ElemType e)
{
    LinkList p, q; //p为被删除结点的前驱，q为被删除结点
    int tag = FLASE;
    p = L;
    q = L->next;
    while (q != NULL)
    { //定位指针q指向被删结点
        if (q->data == e)
        {
            p->next = q->next; //让q结点从链表中脱离
            free(q);
            tag = TRUE;
        }
        else
            p = q;
        q = q->next;
    }
    return tag;
}

//输出带头结点的单链表中所有结点的值
void PrintLinkL(LinkList L)
{
    LinkList p = L->next;
    while (p)
    {
        printf("%d-->", p->data);
        p = p->next; //遍历下一个结点
    }
    printf("\n");
}

//释放带头结点的链表空间（含头结点）
void FreeLinkL(LinkList &L)
{
    LinkList p, q;
    p = L;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    L = NULL; //将链表头指针置空
}

//主函数
int main()
{

    ElemType E[] = {34, 12, 45, 64, 36, 28, 45, 56}; //准备线性表
    int i, n = 8;
    LinkList head;
    ElemType rc;
    printf("(1)头插入法创建单链表......\n");
    if (!CreatLinkL1(head, n, E))
    {
        printf("内存空间不够，创建失败 ！\n");
        return 0;
    }
    else
    {
        printf("创建完成。链表输出：");
        PrintLinkL(head);
    }
    printf("(2)尾插入法创建单链表......\n");
    FreeLinkL(head);
    if (!CreatLinkL2(head, n, E))
    {
        printf("内存空间不够，创建失败 ！\n");
        return 0;
    }
    else
    {
        printf("创建完成。链表输出：");
        PrintLinkL(head);
    }
    printf("(3)指定位置插入......\n");
    printf("输入插入位置和新元素值-->");
    scanf("%d%d", &i, &rc);
    if (!InsertLinkL(head, i, rc))
        printf("参数错误或内存空间不够，插入失败 ！\n");
    else
    {
        printf("插入成功 ！链表输出：");
        PrintLinkL(head);
    }
    printf("(4)删除指定位置结点......\n");
    printf("输入被删结点位置-->");
    scanf("%d", &i);
    if (!Del_LinkL1(head, i, rc))
        printf("参数错误，删除失败 ！\n");
    else
    {
        printf("删除成功！被删结点值是：%d\n    链表输出：", rc);
        PrintLinkL(head);
    }
    printf("(5)删除指定值结点......\n");
    printf("输入被删结点的值-->");
    scanf("%d", &rc);
    if (!Del_LinkL2(head, rc))
        printf("输入的值不存在 ！\n");
    else
    {
        printf("删除成功 ！ 链表输出：");
        PrintLinkL(head);
    }
    printf("(6)删除指定值所有的结点......\n");
    printf("输入被删结点的值-->");
    scanf("%d", &rc);
    if (!Del_LinkL3(head, rc))
        printf("输入的值不存在 ！\n");
    else
    {
        printf("删除成功 ! 链表输出：");
        PrintLinkL(head);
    }
    printf("(7)清空链表......\n");
    FreeLinkL(head);
    if (!head)
        printf("链表已清空\n");
    else
        printf("清空链表失败 ！");
    return 0;
}
