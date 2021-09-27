#include <iostream>
#include <stdlib.h>
#include <stdlib.h>
#include <stack>
#include <bits\stdc++.h>
using namespace std;
bool IsBracket(char c)
{
    if ('(' == c || ')' == c || '{' == c || '}' == c || '[' == c || ']' == c)
        return true;
    return false;
}
bool MatchBrackets(const char *str)
{
    size_t len = strlen(str);
    stack<char> s;
    for (size_t i = 0; i < len; ++i)
    {
        if (!IsBracket(str[i])) //如果不是括号，那就直接结束本次循环
            continue;
        else
        {
            //检测当前字符是否为左括号
            if ('(' == str[i] || '[' == str[i] || '{' == str[i])
                s.push(str[i]); //如果为左括号，那就压入栈中
            else
            {
                //当前字符为右括号

                //当前字符是右括号，栈里存放的是左括号，如果此时栈为空的话，所以右括号比左括号多
                if (s.empty())
                {
                    cout << "右括号比左括号多" << endl;
                    return false;
                }
                char c = s.top(); //取栈顶元素

                //如果栈顶元素与当前元素匹配的话，那就把栈顶元素弹出
                if ('(' == c && ')' == str[i] ||
                    '{' == c && '}' == str[i] ||
                    '[' == c && ']' == str[i])
                {
                    s.pop(); //将栈顶元素弹出
                }
                //栈顶元素与当前元素不匹配
                else
                {
                    cout << "左右括号次序匹配出错" << endl;
                    return false;
                }
            }
        }
    }

    //把已知字符串已经遍历完，栈中存放的是左括号，栈还没有空的话，那就是左括号比右括号多
    if (!s.empty())
    {
        cout << "左括号比右括号多" << endl;
        return false;
    }
    //把已知字符串已经遍历完，栈中也是空的，那就是刚好匹配的情况
    cout << "左右匹配正确" << endl;
    return true;
}
int main()
{
    char a[] = "(())abc{[(])}"; // 左右括号次序匹配不正确
    char b[] = "(()))abc{[]}";  // 右括号多于左括号
    char c[] = "(()()abc{[]}";  // 左括号多于右括号
    char d[] = "(())abc{[]()}"; // 左右括号匹配正确
    MatchBrackets(a);
    MatchBrackets(b);
    MatchBrackets(c);
    MatchBrackets(d);
    return 0;
}
