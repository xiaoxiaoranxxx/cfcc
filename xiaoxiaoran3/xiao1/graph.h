#define MAXV 30 // 最大顶点数
typedef int InfoType;
//以下定义图的邻接矩阵数据结构
typedef struct
{                  //定义图的顶点结构
    int no;        //顶点编号
    InfoType info; //顶点其它信息，可用于
} VertexType;
typedef struct
{                          //定义图邻接矩阵
    VertexType vexs[MAXV]; //顶点向量
    int arcs[MAXV][MAXV];  //邻接矩阵
    int vexnum, arcnum;    //图的当前顶点数和边数
} MGraph;
//以下定义图的邻接表数据结构
typedef struct ArcNode
{                            //定义表结点类型
    int adjvex;              //顶点序号
    int weight;              //边或弧的权值
    struct ArcNode *nextarc; //指向下一个表结点的指针
} ArcNode;
typedef struct VNode
{ //定义头结点类型
    VertexType data;
    ArcNode *firstarc;
} VNode;
//typedef  VNode  AdjList[MAXV];	//定义头结点数组
typedef struct
{ //定义图的邻接表类型
    VNode vertices[MAXV];
    int vexnum, arcnum;
} LGraph;
