#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> aa;

int main()
{
    int len, eyemax, temp, i, num = 0;
    cin >> len >> eyemax;
    int bb[1000];
    for (i = 0; i < len; i++)
    {
        cin >> temp;
        aa.push_back(temp);
    }
    vector<int>::iterator it;
    vector<int> s;
    int xiao = len - eyemax + 1;
    for (it = aa.begin(); it < aa.begin() + xiao; it++)
    {
        for (i = 0; i < eyemax; i++)
            s.push_back(*(it + i));
        sort(s.begin(), s.end());
        bb[num++] = s.back();
        s.clear();
    }
    cout << xiao << endl;
    for (i = 0; i < xiao; i++)
        if (i == xiao - 1)
            cout << bb[i];
        else
            cout << bb[i] << " ";
}

/*

超哥正坐在一辆火车上, 这一列火车途中经过了n颗树 ,这n颗树高矮不一 , 超哥视力非常远 , 每一次可以看见前方k颗树, 超哥想知道每次视野内看见的最大的树所组成的序列是多少?
(注:当超哥是视野内没有k颗树时超哥不用统计树,并且超哥只会向前看 不会去回首往事 )
聪明的你能帮帮超哥吗?

输入格式:
第一行输入n和视力k
第二行是n个数a
​
​​ 
​​ 

输出格式:
第一行输出序列的长度
第二行输出超哥每次看见的最高的树的大小 每一行行尾不要有多余的空格

样例
case 1

输入

5 3
1 2 1 2 1
输出

3
2 2 2
case 2

输入

10 2
1 2 3 4 5 6 7 8 9 10
输出

9
2 3 4 5 6 7 8 9 10
case 3

输入

8 3
2 3 4 2 5 2 6 1
输出

6
4 4 5 5 6 6
case 4

输入

8 3
1 3 -1 -3 5 3 6 7
输出

6
3 3 5 5 6 7
提示
如果当前的树的序列是 1 2 1 2 1 2 3 超哥的视力为3
那么这个序列就是 2 2 2 2 3
第一次看见的是 1 2 1 所以 为 2
第二次看见的是 2 1 2 所以 为 2
第三次看见的是 1 2 1 所以 为 2
第四次看见的是 2 1 2 所以 为 2
第五次看见的是 1 2 3 所以 为 3

*/
