#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*set（集合）——包含了经过排序了的数据，这些数据的值(value)必须是唯一的。   
    也就是说输入set容器后得到数据，会去重并排序。
    s.insert()插入一个元素
    s.begin() s.end()分别返回首尾指针
    s.clear() 清空集合
   遍历需要利用迭代器set<类型>::iterator 变量名 ；*/

set<int> s;
int main()
{
    int t = 5, a;

    while (t--)
        s.insert(t);

    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
} //0 1 2 3 4
