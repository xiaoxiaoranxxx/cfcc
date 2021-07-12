#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; 
    cin >> n;
    n += 1;
    int i, j, a[n][n];

    //使第一列和对角线元素的值为1
    for (i = 1; i < n; i++)
    {                //前两行全为1，拿出来单独处理
        a[i][i] = 1; //使最右侧边全为1
        a[i][1] = 1; //使最左侧边全为1
    }

    //从第三行开始处理
    for (i = 3; i < n; i++)                          //三行开始出现变化
        for (j = 2; j <= i - 1; j++)                 //j始终慢i一步
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j]; //每个数等于它上方两数之和，如a32=a21+a22

    //输出数组各元素的值
    for (i = 1; i < n; i++)
    {                                          //从第一行开始
        for (j = 1; j <= i; j++)               //利用j将每一行的数据全部输出
            cout << setw(1) << a[i][j] << " "; //在C++中，setw(int n)用来控制输出间隔，这里是指前元素末尾与后元素末尾之间有个5空格位
        cout << endl;
    }
    cout << endl;
    return 0;
}