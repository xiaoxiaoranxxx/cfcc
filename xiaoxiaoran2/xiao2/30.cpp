#include <iostream>
#include <cstring>
using namespace std;

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
