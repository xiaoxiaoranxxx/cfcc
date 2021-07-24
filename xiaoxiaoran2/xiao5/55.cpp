/*题目描述
    给出2个字符串，3485djDkxh4hhGE  2934akdfkhkkggEdsb
    两字符串中出现的第 1 对相同的数字或者大写英文字母代表小时（一天的 0 点到 23 点由数字 0 到 9、以及大写字母A到N表示），第1对相同的小写字母的位置代表分钟，现在给出2个字符串，输出其中隐藏的时间。
    如例子中第 1 对相同的小写英文字母是h，出现在第 9 个位置（从 0 开始计数）上，代表第 9 分钟。
    第1对相同的大写英文字母是E， E是第 5 个英文字母，代表一天里的第 14 个钟头；
    所以，时间是14:09
输入
    第一行n表示测试用例个数，接下来2n行表示每组测试用例的字符串
    在每组测试用例的 2 行中分别给出 2个非空、不包含空格、且长度不超过 60 的字符串。
输出
    在每行测试中输出时间，格式为HH:MM， 如果分或小时不存在，则输出字符串NO
样例输入 
    2
    3485djDkxh4hhGE
    2934akdfkhkkggEdsb
    uopiuuoiuuoi
    8979798qwzafas
样例输出
    14:09
    NO
*/

#include <stdio.h>

int xiao(char x)
{
    if (x >= 'A' && x <= 'N')
        return 1;
    else if (x >= '0' && x <= '9')
        return 1;
    else
        return 0;
}

void xiu(char a[], char b[])
{
    int i = 0, hh = 0, mm = 0;

    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == b[i])
            if (xiao(a[i]))
                hh = i;
            else
                mm = i;
    }
    if (mm < 10 && mm > 0)
        printf("%d:0%d", hh, mm);
    else if (!(mm && hh))
        printf("NO");
    else
        printf("%d:%d", hh, mm);
}

int main()
{
    int num, i;
    char x[60], y[60];
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%s", x);
        scanf("%s", y);
        xiu(x, y);
        printf("\n");
    }
}