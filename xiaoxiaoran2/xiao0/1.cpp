#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "hello world"
         << "xiaoxiaoran" << endl;
    int x;
    cout << "input a number--> ";
    cin >> x;
    cout << "the number is --> " << x << endl;

    string s1;
    getline(cin, s1);

    cout << s1 << endl;

    return 0;
}