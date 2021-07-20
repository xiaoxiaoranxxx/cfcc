#include <bits/stdc++.h>

using namespace std;

int main()
{
    static int a[99999999], b[99999999];
    int n, temp = 0, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    do
    {   
        for (int i = 1; i <= n; i++)
            sum += a[i] * pow(10, i - 1);
        b[temp++] = sum;
        sum = 0;
    } while (next_permutation(a + 1, a + 1 + n));
    sort(b, b + temp);
    int xiao = 0;
    cin >> xiao;

    // for (int i = 0; i < temp; i++)
    // cout <<i<< "->"<< b[i] << endl;

    cout << b[xiao - 1] << endl;
    return 0;
}

//8 444 12674853
//9 333 123689547
//9 8888 138526497
//9 34567 189235467
