#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>

using namespace std;

/*vector(不定长数组）——不需要定义初始长度的数组
    v.push_back()向尾部插入一个元素
    v.size()返回数组大小
    v.pop_back()删除最后一个元素
    v.insert(v[0]+i,a)在第i+1个元素后插入元素a
 基本操作

(1)头文件#include<vector>.

(2)创建vector对象，vector<int> vec;

(3)尾部插入数字：vec.push_back(a);

(4)使用下标访问元素，cout<<vec[0]<<endl;记住下标是从0开始的。

(5)使用迭代器访问元素.

vector<int>::iterator it;for(it=vec.begin();it!=vec.end();it++) cout<<*it<<endl;
(6)插入元素：    vec.insert(vec.begin()+i,a);在第i+1个元素前面插入a;

(7)删除元素：    vec.erase(vec.begin()+2);删除第3个元素

vec.erase(vec.begin()+i,vec.end()+j);删除区间[i,j-1];区间从0开始

(8)向量大小:vec.size();

(9)清空:vec.clear();*/

vector<string> v;

int main()
{
    string a;
    char s[100];
    while (gets(s))
    {
        stringstream ss(s);
        while (ss >> a)
            v.push_back(a);
        for (int i = 0; i < v.size();i++)
            cout << v[i] << "-";
    }

    return 0;
}

//how are you ? ...
//how-are-you-?-...-

