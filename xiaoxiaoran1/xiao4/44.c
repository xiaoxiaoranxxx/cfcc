#include <stdio.h>

#include <string.h>

struct STU
{
    char name[10];
    int num;
    float TotalScore;
};
void f(struct STU *p)
{
    struct STU s[2] = {{"SunDan", 20044, 550}, {"Penghua", 20045, 537}}, *q = s;
    ++p;
    ++q;
    *p = *q;
}
int main()
{
    struct STU s[3] =
        {{"YangSan", 20041, 703}, {"LiSiGuo", 20042, 580}};
    f(s);
    printf("%s %d %3.0f\n", s[1].name, s[1].num, s[1].TotalScore);
}