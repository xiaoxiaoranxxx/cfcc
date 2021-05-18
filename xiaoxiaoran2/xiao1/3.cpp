#include <iostream>
#include <stdarg.h>

using namespace std;

void outputinfo(int num, ...)
{
    va_list arguments;
    va_start(arguments, num);
    while (num--)
    {
        char* pch = va_arg(arguments, char*);
        int i = va_arg(arguments, int);
        cout << pch << endl;
        cout << i << endl;
    }
    va_end(arguments);
}

int main()
{
    outputinfo(2,"2",3,"ee",3);
    return 0;
}