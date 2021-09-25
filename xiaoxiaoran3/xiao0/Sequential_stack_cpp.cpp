#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

void convesion(int num, int Y)
{
    int result;
    char x, e;
    cout << num << "的";
    while (num)
    {
        result = num % Y;
        if (result <= 9)
            x = result + '0';
        else
            x = result - 10 + 'A';
        s.push(x);
        num = num / Y;
    }

    cout << Y << "进制是-->";

    while (!s.empty())
    {
        printf("%c", s.top());
        s.pop();
    }
    cout << endl;
}

int main()
{
    int number = 10;
    convesion(number, 16);
    convesion(number, 2);
    convesion(number, 8);
    number = 66;
    convesion(number, 16);
    convesion(number, 2);
    convesion(number, 8);
    return 0;
}