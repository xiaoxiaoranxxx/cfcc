#include <stdio.h>
#include <malloc.h>

#include "graph.h"

int visited[MAXV]; // 访问标志
int queue[MAXV];   // 广度优先遍历存储队列

void CreatMG(MGraph &mg) // 建立图的邻接矩阵
{
    int i, j;
    int A[7][7]; // 临时数组，指定图有7个顶点
    mg.vexnum = 7;
    mg.arcnum = 9; // 指定图有9条边
    for (i = 0; i < mg.vexnum; i++)
        for (j = 0; j < mg.vexnum; j++)
            A[i][j] = 0;
    A[0][1] = A[0][2] = A[0][6] = 1; // 为邻接矩阵上三角赋值
    A[1][3] = 1;
    A[2][3] = A[2][5] = A[2][6] = 1;
    A[3][4] = 1;
    A[5][6] = 1;
    for (i = 1; i < mg.vexnum; i++) // 为邻接矩阵下三角赋值
        for (j = 0; j < i; j++)
            A[i][j] = A[j][i];
    for (i = 0; i < mg.vexnum; i++)
        for (j = 0; j < mg.vexnum; j++)
            mg.arcs[i][j] = A[i][j];
}

void CreatLG(LGraph *&lg, MGraph mg) //由图的邻接矩阵创建图的邻接表
{
    int i, j;
    ArcNode *p; //指向表结点的临时指针
    lg = (LGraph *)malloc(sizeof(LGraph));
    for (i = 0; i < mg.vexnum; i++) //为邻接表所有头结点的指针域赋初值
        lg->vertices[i].firstarc = NULL;
    for (i = 0; i < mg.vexnum; i++)
        for (j = mg.vexnum - 1; j >= 0; j--)
            if (mg.arcs[i][j] != 0)
            {                                           //若顶点i、j之间有边
                p = (ArcNode *)malloc(sizeof(ArcNode)); // 准备新表结点
                p->adjvex = j;
                p->weight = mg.arcs[i][j];
                p->nextarc = lg->vertices[i].firstarc; // 总是将新结点插入到i链表表首
                lg->vertices[i].firstarc = p;
            }
    lg->vexnum = mg.vexnum;
    lg->arcnum = mg.arcnum;
}

void OutputMG(MGraph mg) //输出图的邻接矩阵
{
    int i, j;
    for (i = 0; i < mg.vexnum; i++)
    {
        for (j = 0; j < mg.vexnum; j++)
            printf("%3d", mg.arcs[i][j]);
        printf("\n");
    }
}

void OutputLG(LGraph *lg) //输出图的邻接表
{
    int i;
    ArcNode *p;
    for (i = 0; i < lg->vexnum; i++)
    {
        p = lg->vertices[i].firstarc;
        if (p)
            printf("%3d：", i);
        while (p)
        {
            printf("%3d", p->adjvex);
            p = p->nextarc;
        }
        printf("\n");
    }
}

void LDFS(LGraph *lg, int i)
// 邻接表表示的图的递归深度优先遍历
{
    ArcNode *p;
    printf("%3d", i); // 访问顶点i
    visited[i] = 1;   // 置顶点i已被访问
    p = lg->vertices[i].firstarc;
    while (p)
    {                                // 检查所有与顶点i相邻接的顶点
        if (visited[p->adjvex] == 0) // 如果该顶点未被访问过
            LDFS(lg, p->adjvex);     // 从邻接顶点出发深度优先搜索
        p = p->nextarc;              // 考察下一个邻接顶点
    }
}

void MDFS(MGraph mg, int i)
// 邻接矩阵表示的图的递归深度优先遍历
{
    int j;
    printf("%3d", i); // 访问顶点i
    visited[i] = 1;   // 置顶点i已被访问
    for (j = 0; j < mg.vexnum; j++)
    { // 检查所有与顶点i相邻接的顶点
        if (mg.arcs[i][j] && visited[j] == 0)
            // 如果该顶点有边且未被访问过
            MDFS(mg, j); // 从邻接顶点出发深度优先搜索
    }
}

void LBFS(LGraph *lg, int s)
{
    // 邻接表表示的图的广度优先遍历
    int i, v, w, front, rear;
    ArcNode *p;
    for (i = 0; i < lg->vexnum; i++)
        visited[i] = 0; // 置全部顶点为未访问标志
    front = rear = 0;   // 队列置空
    printf("%3d", s);   // 访问出发顶点
    visited[s] = 1;     // 置该顶点已被访问标志
    queue[rear++] = s;  //出发顶点进队
    while (front < rear)
    {                       // 队不空循环
        v = queue[front++]; // 取队列首顶点
        for (p = lg->vertices[v].firstarc; p != NULL; p = p->nextarc)
        {
            // 按邻接表顺序考察与顶点v邻接的各顶点w
            w = p->adjvex;
            if (visited[w] == 0)
            {                      // 顶点w未被访问过
                printf("%3d", w);  // 访问顶点w
                visited[w] = 1;    // 置顶点w已被访问标志
                queue[rear++] = w; // 顶点w进队
            }
        }
    }
}

void MBFS(MGraph mg, int s)
{
    // 邻接矩阵表示的图的广度优先遍历
    int i, j, v, front, rear;
    for (i = 0; i < mg.vexnum; i++)
        visited[i] = 0;  // 置全部顶点为未访问标志
    front = rear = 0;    // 队列置空
    printf("%3d", s);    // 访问出发顶点
    visited[s] = 1;      // 置该顶点已被访问标志
    queue[rear++] = s;   // 出发顶点进队
    while (front < rear) // 队不空循环
    {
        v = queue[front++]; // 取队首顶点
        for (i = v; i < mg.vexnum; i++)
            for (j = 0; j < mg.vexnum; j++)
            {                                         // 按邻接矩阵顺序考察与顶点v邻接的各顶点w
                if (mg.arcs[v][j] && visited[j] == 0) //如果该顶点有边且未被访问过
                {
                    printf("%3d", j);  // 访问顶点j
                    visited[j] = 1;    // 置顶点w已被访问标志
                    queue[rear++] = j; // 顶点j进队
                }
            }
    }
}

int main()
{
    LGraph *lg;
    MGraph mg;
    int i;
    CreatMG(mg);
    CreatLG(lg, mg);
    printf("（1）当前图的邻接矩阵是：\n");
    OutputMG(mg);
    printf("（2）当前图的邻接表是：\n");
    OutputLG(lg);
    for (i = 0; i < mg.vexnum; i++)
        visited[i] = 0; // 置全部顶点为未访问标志
    printf("\n");
    printf("（3）邻接表表示的图的深度优先遍历序列是：");
    LDFS(lg, 3);
    printf("\n");
    for (i = 0; i < mg.vexnum; i++)
        visited[i] = 0; // 重置全部顶点为未访问标志
    printf("（4）邻接矩阵表示的图的深度优先遍历序列是：");
    MDFS(mg, 3);
    printf("\n");
    printf("（5）邻接表表示的图的广度优先遍历序列是：");
    LBFS(lg, 3);
    printf("\n");
    printf("（6）邻接矩阵表示的图的广度优先遍历序列是：");
    MBFS(mg, 3);
    printf("\n");
}
