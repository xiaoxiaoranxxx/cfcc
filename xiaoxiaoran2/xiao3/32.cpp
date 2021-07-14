#include <iostream>
using namespace std;
/*输入一个四位数，将其加密后输出。方法是将该数每一位上的数字加9，然后除以10取余，做为该位上的新数字，最后将千位和十位上的数字互换，
百位和个位上的数字互换，组成加密后的新四位数。例如输入1257，经过加9取余后得到新数字0146，再经过两次换位后得到4601。*/
int xiao(char x)
{
    int num;
    num = x - '0';
    num = (num + 9) % 10;
    return num;
}
int main()
{
    char xx[4];
    int i, xi[4];

    cin >> xx;
    for (i = 0; i < 4; i++)
        xi[i] = xiao(xx[i]);
    swap(xi[0], xi[2]);
    swap(xi[1], xi[3]);
     cout << "The encrypted number is ";
    for (i = 0; i < 4; i++)
        cout << xi[i];
}
