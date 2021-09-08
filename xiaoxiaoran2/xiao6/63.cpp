#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

int a[N], q[N]; //a原数组 q单调队列

int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    int hh = 0, tt = -1; //队头0 队尾 -1
    for(int i = 0; i < n; i++)
    {
        if(hh <= tt && q[hh] < i - k + 1) hh ++; //当前队头不在窗口里面 往后移动
        while(hh <= tt && a[q[tt]] >= a[i]) tt--; //队尾元素比当前元素大，删掉
        q[++ tt] = i; //把当前数加入单调队列
        
        if(i >= k - 1) printf("%d ", a[q[hh]]); //最小值 把单调队列 队头 输出
    }
    puts("");
    
    //下面输出最大值
    hh = 0, tt = -1;
    for(int i = 0; i < n; i++)
    {
        if(hh <= tt && q[hh] < i - k + 1) hh ++; //当前队头不在窗口里面 往后移动
        while(hh <= tt && a[q[tt]] <= a[i]) tt--; //队尾元素比当前元素小，删掉
        q[++ tt] = i; //把当前数加入单调队列
        
        if(i >= k - 1) printf("%d ", a[q[hh]]); //最大值 把单调队列 队头 输出
    }
    puts("");
    
    return 0;
} 
