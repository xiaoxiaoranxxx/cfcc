#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct student
{
    //string name;
    char name[21];
    int score;
} s[21];

bool cmp(student a, student b)
{
    if (a.score == b.score)
        //if(a.name.compare(b.name) <= 0)
        if (strcmp(a.name, b.name) <= 0)
            return true;
    return a.score > b.score;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i].name >> s[i].score;

    // for (int i = 0; i < n - 1; i++)
    //     for (int j = 0; j < n - i - 1; j++)
    //     {
    //         if (s[j].score < s[j + 1].score)
    //             swap(s[j + 1], s[j]);
    //         if (s[j].score == s[j + 1].score && strcmp(s[j].name, s[j + 1].name) > 0)
    //             swap(s[j + 1], s[j]);
    //     }

    sort(s, s + n, cmp);
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

