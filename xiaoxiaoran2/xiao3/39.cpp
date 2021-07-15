#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //lower_bound()返回值是一个迭代器,返回指向大于等于key的第一个值的位置
    //upper_bound() 用法跟lower_bound() 一样，只不过它返回的是第一个大于x的值的地址， 而lower_bound() 是返回第一个大于等于x的值的地址， > 和 >= 是二者的区别 
    
    int a[] = {1, 2, 3, 4, 5, 7, 8, 9};
    cout << lower_bound(a, a + 8, 1) - a << endl;

    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    A.push_back(7);
    A.push_back(8);
    A.push_back(9);

    int pos = lower_bound(A.begin(), A.end(), 6) - A.begin();
    cout << pos << endl;
}
