#include <iostream>
#include <cstring>
using namespace std;
/*给出班里某门课程的成绩单，请你按成绩从高到低对成绩单排序输出，如果有相同分数则名字字典序小的在前。*/
struct student
{
    char name[21];
    int score;
};
int main()
{
    struct student s[21];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i].name >> s[i].score;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].score < s[j + 1].score)
                swap(s[j + 1], s[j]);
            if (s[j].score == s[j + 1].score && strcmp(s[j].name, s[j + 1].name) > 0)
                swap(s[j + 1], s[j]);
        }
    for (int i = 0; i < n; i++)
        cout << s[i].name << " " << s[i].score << endl;
    return 0;
}
/*
4
Kitty 80
Hanmeimei 90
Joey 92
Tim 28
*/
