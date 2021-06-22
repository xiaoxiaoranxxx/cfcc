#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pair
{
    int first, second;
};
struct pair get_min_max(int *array, int len)
{
    int i;
    struct pair res;
    res.first = array[0];
    res.second = array[0];
    for (i = 1; i < len; i++)
    {
        //printf("%d %d-->", res.first, res.second);
        if (array[i] > res.first) //a>9
            res.first = array[i];
        if (array[i] < res.second) //a<1
            res.second = array[i];
        //printf("%d %d\n", res.first, res.second);
    }
    return res;
}
int main()
{
    int array[5] = {9, 1, 3, 4}; //a[4]=0;
    struct pair min_max = get_min_max(array, 5);
    printf("min=%d,max=%d\n", min_max.first, min_max.second);
}