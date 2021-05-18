#include <iostream>

using namespace std;

int main()
{
    int i = 0, sum = 0;
    label:
        i++;
        sum += i;
        if(i<10)
            goto label;
        cout << sum << endl;
        return 0;
}