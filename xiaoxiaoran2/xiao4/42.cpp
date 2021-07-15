#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//假设要在足够多的会场里安排一批活动，并希望使用尽可能少的会场。设计一个有效的 贪心算法进行安排。（这个问题实际上是著名的图着色问题。若将每一个活动作为图的一个 顶点，不相容活动间用边相连。使相邻顶点着有不同颜色的最小着色数，相应于要找的最小 会场数。）
int main()
{
    int n;
    cin >> n;
    int start[n], end[n];
    for (int i = 0; i < n; i++)
        cin >> start[i] >> end[i];
    sort(start, start + n);
    sort(end, end + n);
    int j = 0;
    int sum = 0; //会场个数
    for (int i = 0; i < n; i++)
    {
        if (start[i] < end[j])
            sum++; //如果开始时间小于结束时间则另开辟一个会场
        else
            j++; //否则和下一个结束时间进行比较
    }
    cout << sum;
}
