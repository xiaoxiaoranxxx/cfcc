#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <sstream>

using namespace std;
/*queue（队列）——“先进先出”的一种数据结构，感觉这些容器就是把数组改造，添加一些成员函数，使它用起来更方便些，理解的时候可以对照如果用数组实现这样的功能有多麻烦。
其本操作：
1、定义：queue<int> q;
2、  q.push（a） 将元素a加入队列    
        q.front（）访问首元素      
        q.back（） 访问尾元素 
        q.pop（） 删除首元素 
        q.size（）返回元素个数
       q.empty（）判断队列是否为空 */
queue<int> q;

int main()
{
    int t, a;
    cin >> t;
    while(t--){
        cin >> a;
        q.push(a);
    }
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}
