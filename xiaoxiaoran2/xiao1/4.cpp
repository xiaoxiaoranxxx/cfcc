#include <iostream>

using namespace std;

int Add(int a, int b)
{
    cout << "the is int-->" << a + b << endl;
    return a + b;
}
double Add(double a, double b)
{
    cout << "the is doble-->" << a + b << endl;
    return a + b;
}

int main()
{
    int xiao1 = Add(1, 2);
    double xiao2 = Add(11.1, 21.22);
    cout << xiao1 << " " << xiao2 << endl;
    return 0;
}