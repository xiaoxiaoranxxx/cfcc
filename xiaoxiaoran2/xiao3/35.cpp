#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <sstream>

using namespace std;
/*stack（栈）——“先进后出”的一种数据结构，和队列类比看。 
其本操作：
1、定义：stack<int> s;
2、  s.push（a） 将元素a压入栈    
        s.top（）访问栈顶元素      
        s.pop（） 删除栈顶元素 
        s.size（）返回元素个数
        s.empty（）判断栈是否为空  */
stack<int> s;

int main()
{
    int t, a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        s.push(a);
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
