/* 根据Huffman编码的原理，编写一个程序，在用户输入节点权重的基础上建立他的Huffman编码 */

//解题思路：先构造一棵Huffman树，由此得到的二进制前缀便为Huffman
//由于Huffman树没有度为1的节点，则一棵有着n个节点的Huffman树共有2n-1个节点，设计一个结构数组，存储2n-1个节点的值
//包括权重，父节点、左节点、右节点等

#include <iostream>
using namespace std;
#define MAX 21
typedef struct
{
    char data;  //节点值
    int weight; //权重
    int parent; //父节点下标位置
    int left;   //左节点
    int right;  //右节点
} huffnode;

typedef struct
{
    char cd[MAX];
    int start; //叶节点的Huffman code的起始位置
} huffcode;

int main()
{
    huffnode ht[2 * MAX];
    huffcode hcd[MAX], d;
    int i, k, f, l, r, n, c, m1, m2;
    cout << "元素个数：";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cout << "第" << i << "个元素=>\t节点值：";
        cin >> ht[i].data;
        cout << "\t\t权重：";
        cin >> ht[i].weight;
    }

    //初始化Huffman叶节点和分支节点
    //数组为静态存储空间，其最大的特征为 - 预先分配所需空间
    for (i = 1; i <= 2 * n - 1; i++)
    {
        ht[i].parent = ht[i].left = ht[i].right = 0;
    }

    //构造哈夫曼树
    for (i = n + 1; i <= 2 * n - 1; i++)
    {
        m1 = m2 = 32767; //m1 - 最小权值，m2 - 次小权值
        l = r = 0;       //l - 最小权值节点的位置，r - 次小权值节点的位置

        for (k = 1; k <= i - 1; k++)
        {
            if (ht[k].parent == 0)
            {
                if (ht[k].weight < m1)
                {
                    m2 = m1; //更新最小、次小权值并记录其所在位置
                    r = l;
                    m1 = ht[k].weight;
                    l = k;
                }
                else if (ht[k].weight < m2)
                {
                    m2 = ht[k].weight;
                    r = k;
                }
            }
        }
        //设置找到的2个子节点的父节点信息
        ht[l].parent = i;
        ht[r].parent = i;
        ht[i].weight = ht[l].weight + ht[r].weight;
        ht[i].left = l;
        ht[i].right = r;
    }

    //根据Huffman树求Huffman编码
    //注意：由于HuffmanCode的生成过程为自底向上，所以我们这里采用-倒着存方式
    for (i = 1; i <= n; i++)
    {
        d.start = n + 1;  //start - 记录HuffmanCode的起始位置
        c = i;            //当前叶节点在结构数组中的下标
        f = ht[i].parent; //当前叶节点的父节点
        while (f != 0)    //到达根节点则HuffmanCode建立完毕，循环退出
        {
            if (ht[f].left == c) //若当前叶节点的父节点的左指针指向了当前叶节点，则记录0 - 左儿子
                d.cd[--d.start] = '0';
            else //若当前叶节点的父节点的右指针指向了当前叶节点，则记录1 - 右儿子
                d.cd[--d.start] = '1';
            c = f;            //更新儿子节点(分支节点) - 自叶节点到根节点建立HuffmanCode
            f = ht[f].parent; //更新当前儿子节点的父节点 直到根节点为止
        }
        hcd[i] = d;
    }

    //输出HuffmanCode
    cout << "输出HuffmanCode：\n";
    for (i = 1; i <= n; i++)
    {
        cout << "  " << ht[i].data << ": ";
        for (k = hcd[i].start; k <= n; k++)
            cout << hcd[i].cd[k];
        cout << endl;
    }

    return 0;
}

// a 7 b 9 c 12 d 22 e 23 f 27 