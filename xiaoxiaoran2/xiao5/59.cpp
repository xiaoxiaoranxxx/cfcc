#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*给定一个整数数组 x 和一个整数目标值 k，请你在该数组中找出 和为目标值 k 的那 两个 整数，请你判断是否能够满足条件. */
int main()
{
    
    static int nums[11111111];
    int i, j, sum, num, flag = 0;
    cin >> num >> sum;
    for (i = 0; i < num; i++)
        scanf("%d", &nums[i]);

    for (i = 0; i < num; i++)
        for (j = i + 1; j < num; j++)
            if (nums[j] == sum - nums[i])
            {
                cout << "yes" << endl;
                flag = 1;
                break;
            }
    if (!flag)
        cout << "no" << endl;
}

/*

4 9
2 7 11 15
yes

3 2
1 2 3
no
*/
