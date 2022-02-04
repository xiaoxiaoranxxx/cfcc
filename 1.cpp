
#define MAXNUM 100
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int KeyType;
typedef struct
{ // 定义元素的结构类型
    KeyType key;
    int other;
} ElemType;
typedef struct
{ // 定义排序表结构类型
    ElemType r[MAXNUM + 1];
    int length;
} SqList;

void OutputList(SqList L)
{
    int i;
    for (i = 1; i <= L.length; i++)
        printf("%3d", L.r[i].key);
    printf("\n");
}

//（1）创建随机数排序表
void CreatList(SqList &L)
{
    int i;
    do
    {
        printf("  输入排序表长度(1-%d)==>", MAXNUM - 1);
        // 排序表0下标用作监视哨，实际容纳MAXNUM-1个元素
        // scanf("%d", &L.length);
        L.length = 5;
    } while (L.length < 1 || L.length > MAXNUM - 1);
    srand((unsigned)time(NULL));
    for (i = 1; i <= L.length; i++) // 随机产生排序表
        L.r[i].key = 1 + rand() % (MAXNUM - 1);
}

// （2）直接插入排序
void InsertSort(SqList &L, int &cp, int &mv)
{
    int i, j;
    for (i = 2; i <= L.length; i++)
    {
        cp++;
        if (L.r[i].key < L.r[i - 1].key)
        {
            L.r[0] = L.r[i];
            mv++;
            for (j = i - 1; L.r[0].key < L.r[j].key; j--)
            {
                L.r[j + 1] = L.r[j];
                cp++;
                mv++;
               
            }
            cp++;
            L.r[j + 1] = L.r[0];
            mv++;
        } //if
        OutputList(L);
    }
}
// （3）折半插入排序
void BinSort(SqList &L, int &cp, int &mv)
{
    int i, j, low, high, mid;
    for (i = 2; i <= L.length; i++)
    {
        L.r[0] = L.r[i];
        mv++;
        low = 1;
        high = i - 1;
        while (low <= high)
        { // 定位插入点
            mid = (low + high) / 2;
            cp++;
            if (L.r[0].key < L.r[mid].key)
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= high + 1; j--)
        {
            L.r[j + 1] = L.r[j];
            mv++;
        }
        L.r[high + 1] = L.r[0];
        mv++;
    }
}

// （4）希尔排序
void ShellInsert(SqList &L, int dk, int &cp, int &mv)
{
    //对顺序表L作一趟希尔排序
    int i, j;
    for (i = dk + 1; i <= L.length; i++)
    {
        cp++;
        if (L.r[i].key < L.r[i - dk].key)
        { //需将L.r[i]插入有序增量子表
            mv++;
            L.r[0] = L.r[i]; //L.r[i]暂存入L.r[0]
            for (j = i - dk; j > 0 && L.r[0].key < L.r[j].key; j -= dk)
            {
                L.r[j + dk] = L.r[j]; //寻找插入位置时记录后移
                cp++;
                mv++;
            }
            cp++;
            mv++;
            L.r[j + dk] = L.r[0]; //插入
        }                         //if
    }                             //for
} //ShellInsertSort

void ShellSort(SqList &L, int &cp, int &mv)
{
    //按增量序列5,3,1进行希尔排序
    ShellInsert(L, 5, cp, mv); //一趟增量为5的希尔排序
    ShellInsert(L, 3, cp, mv); //二趟增量为3的希尔排序
    ShellInsert(L, 1, cp, mv); //三趟增量为1的希尔排序
} //ShellInsertSort

//（5）冒泡排序
void BubbleSort(SqList &L, int &cp, int &mv)
{
    int i, j, change;
    for (i = 1, change = TRUE; i < L.length && change; i++)
    {
        change = FALSE;
        for (j = 1; j < L.length - i + 1; ++j)
        {
            cp++;
            if (L.r[j].key > L.r[j + 1].key)
            {
                L.r[0] = L.r[j];
                L.r[j] = L.r[j + 1];
                L.r[j + 1] = L.r[0];
                change = TRUE;
                mv += 3;
            } //if
        }     //for
    }         //for
} // BubbleSort

//（6）快速排序
int Partition(SqList &L, int low, int high, int &cp, int &mv)
{
    int i, j;
    KeyType pivotkey;
    L.r[0] = L.r[low];
    mv++;
    pivotkey = L.r[0].key;
    i = low;
    j = high;
    while (i < j)
    {
        while (i < j && L.r[j].key >= pivotkey)
        {
            j--;
            cp++;
        }
        if (i < j)
            cp++;
        L.r[i] = L.r[j];
        mv++;
        while (i < j && L.r[i].key <= pivotkey)
        {
            i++;
            cp++;
        }
        if (i < j)
            cp++;
        L.r[j] = L.r[i];
        mv++;
    }
    L.r[i] = L.r[0];
    mv++;
    return i;
} //Partition

void QSort(SqList &L, int low, int high, int &cp, int &mv)
{
    //对L.r[low]～L.r[high]的元素进行快速排序
    int pivotloc;
    if (low < high)
    {
        pivotloc = Partition(L, low, high, cp, mv); //一趟划分
        QSort(L, low, pivotloc - 1, cp, mv);
        QSort(L, pivotloc + 1, high, cp, mv);
    } //if
} //QSort

//（7）简单选择排序
void SelectSort(SqList &L, int &cp, int &mv)
{                //对顺序表作简单选择排序
    int i, j, k; // j保存剩余元素中最小值元素的下标
    for (i = 1; i < L.length; i++)
    {
        for (k = i + 1, j = i; k <= L.length; k++)
        {
            cp++;
            if (L.r[k].key < L.r[j].key)
                (j = k);
        }
        if (j != i)
        {
            L.r[0] = L.r[i];
            L.r[i] = L.r[j];
            L.r[j] = L.r[0];
            mv += 3;
        }
    } //for
} // SelectSort

//（8）堆排序
void HeapAdjust(SqList &H, int s, int m, int &cp, int &mv)
{
    // H.r[s .. m]中除H.r[s].key外均满足堆的定义
    // 调整H.r[s]的关键字，使H.r[s .. m]成为一个大顶堆
    int j;
    H.r[0] = H.r[s];
    mv++;
    for (j = 2 * s; j <= m; j *= 2)
    { //沿key较大的孩子结点向下筛选
        if (j < m && H.r[j].key < H.r[j + 1].key)
            ++j; //j为key较大的记录的下标
        if (j < m)
            cp++;
        cp++;
        if (H.r[0].key >= H.r[j].key)
            break;
        H.r[s] = H.r[j]; //较大的孩子结点值换到父结点位置
        mv++;
        s = j;
    }
    H.r[s] = H.r[0];
    mv++; //H.r[0]应插入的位置在s处
} // HeapAdjust

void HeapSort(SqList &H, int &cp, int &mv)
{ //对顺序表H进行堆排序
    int i;
    for (i = H.length / 2; i > 0; --i) // 把H建成大顶堆
        HeapAdjust(H, i, H.length, cp, mv);
    for (i = H.length; i > 1; --i)
    {
        H.r[0] = H.r[1];
        H.r[1] = H.r[i];
        H.r[i] = H.r[0];
        mv += 3;
        //堆顶记录和当前未排子序列中最后一个记录相交换
        HeapAdjust(H, 1, i - 1, cp, mv); //将H. r[l .. i - 1] 重新调整为大顶堆
    }
} // HeapSort

//（9）二路归并排序
void Merge(SqList &L, SqList &temp, int i, int m, int n, int &cp, int &mv)
{ // 引入辅助空间temp
    int b = i, j, k;
    for (j = m + 1, k = 1; i <= m && j <= n; ++k)
    {
        if (L.r[i].key < L.r[j].key)
            temp.r[k] = L.r[i++];
        else
            temp.r[k] = L.r[j++];
        cp++;
        mv++;
    }
    for (; i <= m;)
    {
        temp.r[k++] = L.r[i++];
        mv++;
    }
    for (; j <= n;)
    {
        temp.r[k++] = L.r[j++];
        mv++;
    }
    for (i = b, k = 1; i <= n;)
    {
        L.r[i++] = temp.r[k++];
        mv++;
    }
} // Merge
void MergeSort(SqList &L, SqList &temp, int s, int t, int &cp, int &mv)
{ //归并排序
    int m;
    if (s < t)
    {
        m = (s + t) / 2;
        MergeSort(L, temp, s, m, cp, mv);
        MergeSort(L, temp, m + 1, t, cp, mv);
        Merge(L, temp, s, m, t, cp, mv); //合并L.r[s]~L.r[m]与L.r[m+1]~L.r[t]
    }                                    //if
} // MergeSort

//（10）输出排序表

int main()
{
    SqList LL, L; //LL为待排序表，L为排序表
    SqList temp;  //二路归并算法中所使用的临时顺序表
    int cp, mv;   //cp记录元素关键字比较次数，mv记录元素移动次数
    printf("(1)创建随机数排序表......\n");
    CreatList(LL); //待排序序列保存在LL表中
    printf("  排序表输出：");
    OutputList(LL);

    printf("(2)直接插入排序......\n");
    L = LL;
    cp = mv = 0;
    InsertSort(L, cp, mv);
    printf("  排序结果：");
    OutputList(L);
    printf("  排序效率：比较次数%d，移动次数%d。\n", cp, mv);

    // printf("(3)折半插入排序......\n");
    // L = LL;
    // cp = mv = 0;
    // BinSort(L, cp, mv);
    // printf("  排序结果：");
    // OutputList(L);
    // printf("  排序效率：比较次数%d，移动次数%d。\n", cp, mv);

    // printf("(4)希尔排序......\n");
    // L = LL;
    // cp = mv = 0;
    // ShellSort(L, cp, mv);
    // printf("  排序结果：");
    // OutputList(L);
    // printf("  排序效率：比较次数%d，移动次数%d。\n", cp, mv);

    // printf("(5)冒泡排序......\n");
    // L = LL;
    // cp = mv = 0;
    // BubbleSort(L, cp, mv);
    // printf("  排序结果：");
    // OutputList(L);
    // printf("  排序效率：比较次数%d，移动次数%d。\n", cp, mv);
    // getchar();

    // printf("(6)快速排序......\n");
    // L = LL;
    // cp = mv = 0;
    // QSort(L, 1, L.length, cp, mv);
    // printf("  排序结果：");
    // OutputList(L);
    // printf("  排序效率：比较次数%d，移动次数%d。\n", cp, mv);

    // printf("(7)简单选择排序......\n");
    // L = LL;
    // cp = mv = 0;
    // SelectSort(L, cp, mv);
    // printf("  排序结果：");
    // OutputList(L);
    // printf("  排序效率：比较次数%d，移动次数%d。\n", cp, mv);

    // printf("(8)堆排序......\n");
    // L = LL;
    // cp = mv = 0;
    // HeapSort(L, cp, mv);
    // printf("  排序结果：");
    // OutputList(L);
    // printf("  排序效率：比较次数%d，移动次数%d。\n", cp, mv);

    // printf("(9)二路归并排序......\n");
    // L = LL;
    // cp = mv = 0;
    // MergeSort(L, temp, 1, L.length, cp, mv);
    // printf("  排序结果：");
    // OutputList(L);
    // printf("  排序效率：比较次数%d，移动次数%d。\n", cp, mv);
}
