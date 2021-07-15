#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*给定一堆巧克力,还有每一块的巧克力吃的时间
有两个人 一个小明一个小红 小明是个男生 小红是个女生
小明从右往左吃 小红从左往右吃
小明是个绅士 所有如果他和小红准备吃同一块巧克力
小明将会让出这一块巧克力*/

struct xx
{
    int time = 0;
    int count = 0;
} ss[2];

int main()
{
    int num;
    cin >> num;
    int ll[num];
    for (int i = 0; i < num; i++)
        cin >> ll[i];

    int i = 0, j = num - 1;
    while (1)
    {
        if (ss[0].time <= ss[1].time)
        {
            ss[0].time += ll[i];
            if (ll[i] != 0)
            {
                ss[0].count++;
                ll[i] = 0;
            }
            i++;
        }
        if (ss[0].time >ss[1].time)
        {
            ss[1].time += ll[j];
            if (ll[j] != 0)
            {
                ss[1].count++;
                ll[j] = 0;
            }
            j--;
        }
        if (ss[0].count + ss[1].count >= num)
            break;

        // cout << i << " " << j << endl;
    }
   

    cout << ss[0].count << " " << ss[1].count << endl;
}
/*

10
1 6 1 2 3 4 2 3 4 5 
6 4

8
1 2 3 4 5 6 7 8
6 2

4
1 2 3 3
3 1

*/
