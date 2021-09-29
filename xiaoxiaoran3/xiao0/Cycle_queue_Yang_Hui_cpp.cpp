#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

void out_YangHui_number(int n)
{

    int s1 = 0, s2 = 1, i, j;
    printf("1\n");
    q.push(s1 + s2);
    for (i = 2; i <= n; i++)
    {
        s1 = 0;
        for (j = 1; j <= i - 1; j++)
        {
            s2 = q.front();
            q.pop();
            printf("%d ", s2);
            q.push( s1 + s2);
            s1 = s2;
        }
        printf("1");
        q.push(1 + s2);
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    out_YangHui_number(8);
    return 0;
}
