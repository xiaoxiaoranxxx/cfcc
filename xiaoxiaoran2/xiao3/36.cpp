#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

bool complare(int a, int b)
{
    return a > b;
}

int main()
{
    int a[10] = {9, 6, 3, 8, 5, 2, 7, 4, 1, 0};
    sort(a, a + 10, complare);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
    sort(a, a + 10);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";

    vector<int> v{1, 2, 2, 3, 4, 5, 6, 6, 7, 8, 9, 0};
    

    vector<int> b{3, 3, 3, 4, 4, 5, 6, 9};
    vector<int> s(v.size() + b.size());

    // 合并有序
    merge(v.begin(), v.end(), b.begin(), b.end(), s.begin());

    // 逆序
    reverse(v.begin(), v.end());

    // 随机排序
    random_shuffle(v.begin(), v.end());
}
