#include <iostream>
#include <algorithm>
using namespace std;

/*先输入N,表示数的个数，然后输入N个数，求这N个数的最大值和最小值。N<=10000，输入的数的绝对值不大于10^6
样例输入 
4  
2 0 1 2
样例输出 
2 0*/

int main()
{
    int a[10000];
    int N;
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 0; i < N; i++)
            cin >> a[i];
        sort(a, a + N);
        printf("%d %d\n", a[N - 1], a[0]);
    }
    system("pause");
    return 0;
}
