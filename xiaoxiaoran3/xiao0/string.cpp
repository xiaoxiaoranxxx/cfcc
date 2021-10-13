#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define overflow -1
#define ok 1
#define error 0
#define maxsize 40

typedef int status;
typedef int elemtype;

typedef char String[maxsize + 1]; // 0号单元存放串的长度

status str_assign(String T, char *chars)
{
    int i;
    if (strlen(chars) > maxsize)
        return error;
    else
    {
        T[0] = strlen(chars);
        for (i = 1; i <= T[0]; i++)
            T[i] = *(chars + i - 1);
        return ok;
    }
}
status str_empty(String S)
{
    if (S[0] == 0)
        return true;
    else
        return false;
}
int str_length(String S)
{
    return S[0];
}
int str_compare(String S, String T)
{
    for (int i = 0; i <= S[0] && i <= T[0]; ++i)
        if (S[i] != T[i])
            return false;
    return true;
}
void str_print(String T)
{
    int i;
    for (i = 1; i <= T[0]; i++)
        printf("%c", T[i]);
    printf("\n");
}
status str_clear(String S)
{
    S[0] = 0; //令串长为零
    return ok;
}

status str_concat(String T, String S1, String S2)
{
    int i = 0;
    if (S1[0] + S2[0] <= maxsize)
    { //未截断
        for (i = 1; i <= S1[0]; i++)
            T[i] = S1[i];
        for (i = 1; i <= S2[0]; i++)
            T[S1[0] + i] = S2[i];
        T[0] = S1[0] + S2[0];
        return true;
    }
    else
    { //截断
        for (i = 1; i <= S1[0]; i++)
            T[i] = S1[i];
        for (i = 1; i <= maxsize - S1[0]; i++)
            T[S1[0] + i] = S2[i];
        T[0] = maxsize;
        return false;
    }
}

status str_substring(String sub, String s, int pos, int len)
{
    if (pos < 1 || pos > s[0] || len < 0 || len > s[0] - pos + 1)
        return error;
    for (int i = 1; i <= len; i++)
        sub[i] = s[pos + i - 1];
    sub[0] = len;
    return ok;
}
//返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0
status str_index1(String S, String T, int pos)
{
    int i = pos;                   /* i用于主串S中当前位置下标值，若pos不为1，则从pos位置开始匹配 */
    int j = 1;                     /* j用于子串T中当前位置下标值 */
    while (i <= S[0] && j <= T[0]) /* 若i小于S的长度并且j小于T的长度时，循环继续 */
    {
        if (S[i] == T[j]) /* 两字母相等则继续 */
        {
            ++i;
            ++j;
        }
        else /* 指针后退重新开始匹配 */
        {
            i = i - j + 2; /* i退回到上次匹配首位的下一位 */
            j = 1;         /* j退回到子串T的首位 */
        }
    }
    if (j > T[0])
        return i - T[0];
    else
        return 0;
}
//若主串S中第pos个字符之后存在与T相等的子串  则返回第一个这样的子串在S中的位置，否则返回0
status str_index2(String S, String T, int pos)
{
    int n, m, i;
    String sub;
    if (pos > 0)
    {
        n = str_length(S); /* 得到主串S的长度 */
        m = str_length(T); /* 得到子串T的长度 */
        i = pos;
        while (i <= n - m + 1)
        {
            str_substring(sub, S, i, m);  /* 取主串中第i个位置长度与T相等的子串给sub */
            if (str_compare(sub, T) != 0) /* 如果两串不相等 */
                ++i;
            else          /* 如果两串相等 */
                return i; /* 则返回i值 */
        }
    }
    return 0; /* 若无子串与T相等，返回0 */
}
//在串S的第pos个字符之前插入串T。
status str_insert(String S, int pos, String T)
{
    int i;
    if (pos < 1 || pos > S[0] + 1)
        return error;
    if (S[0] + T[0] <= maxsize)
    { /*  完全插入 */
        for (i = S[0]; i >= pos; i--)
            S[i + T[0]] = S[i];
        for (i = pos; i < pos + T[0]; i++)
            S[i] = T[i - pos + 1];
        S[0] = S[0] + T[0];
        return ok;
    }
    else
    { /*  部分插入 */
        for (i = maxsize; i <= pos; i--)
            S[i] = S[i - T[0]];
        for (i = pos; i < pos + T[0]; i++)
            S[i] = T[i - pos + 1];
        S[0] = maxsize;
        return false;
    }
}
//从串S中删除第pos个字符起长度为len的子串
status str_delete(String S, int pos, int len)
{
    int i;
    if (pos < 1 || pos > S[0] - len + 1 || len < 0)
        return error;
    for (i = pos + len; i <= S[0]; i++)
        S[i - len] = S[i];
    S[0] -= len;
    return ok;
}
// 用V替换主串S中出现的所有与T相等的不重叠的子串
status str_replace(String S, String T, String V)
{
    int i = 1;        /*  从串S的第一个字符起查找串T */
    if (str_empty(T)) /*  T是空串 */
        return error;
    do
    {
        i = str_index1(S, T, i); /*  结果i为从上一个i之后找到的子串T的位置 */
        if (i)                   /*  串S中存在串T */
        {
            str_delete(S, i, str_length(T)); /*  删除该串T */
            str_insert(S, i, V);             /*  在原串T的位置插入串V */
            i += str_length(V);              /*  在插入的串V后面继续查找串T */
        }
    } while (i);
    return ok;
}
int main()
{
    int i, j;
    status k;
    char s;
    String xiao1("xiaoxiaoran"), xiao2("6_6_6");
    String s1, s2, s3, s4;

    //assign测试
    if (!str_assign(s1, xiao1))
        exit(0); //串长超过MAXSIZE
    str_print(s1);

    //empty测试
    if (str_empty(s1))
        return 0;

    //compare测试
    if (!str_assign(s2, xiao2))
        exit(0);
    str_print(s2);
    if (str_compare(s1, s2))
        printf("same\n");

    //length测试
    printf("length-->%d\n", str_length(s1));

    //clear测试
    // str_clear(s2);
    // str_print(s2);

    //concat测试
    str_concat(s3, s1, s2);
    str_print(s3);

    //substring测试
    str_substring(s4, s3, 12, 5);
    str_print(s4);

    //index1测试
    printf("%d\n", str_index1(s3, s4, 2));

    //index2测试
    printf("%d\n", str_index2(s3, s4, 10));

    //insert测试
    str_print(s3); //xiaoxiaoran6_6_6
    str_print(s2); //6_6_6
    str_insert(s3, 1, s2);
    str_print(s3); //6_6_6xiaoxiaoran6_6_6

    //delete测试
    str_print(s3); //6_6_6xiaoxiaoran6_6_6
    str_delete(s3, 17, 5);
    str_print(s3); //6_6_6xiaoxiaoran

    //replace测试
    str_print(s3); //6_6_6xiaoxiaoran
    str_print(s2); //6_6_6
    str_print(s1); //xiaoxiaoran
    str_replace(s3, s2, s1);
    str_print(s3); //xiaoxiaoranxiaoxiaoran

    printf("-->end<--");
}