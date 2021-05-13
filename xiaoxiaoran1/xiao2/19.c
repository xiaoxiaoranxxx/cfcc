#include <stdio.h>
#include <stdlib.h>

//#include "18.c"  //文件包含

#define A 0
#define B 0

#define xiao(x1, x2) (x1 > x2) ? x1 : x2
#define xiu(x) x *x * 3
#define a 3
#define b a * 4

int main()
{
    printf("%d ", xiao(1, 2));

    printf("%d ", xiu(1));

    printf("%d ", b);

#undef b //取消定义

#if 1 && 1
    printf("test logic operation \n"); /* 如果上面的逻辑判断成立，那么将打印出一句话；如果不成立，那么就不会打印这句话 */
#endif
    system("pause");
    return EXIT_SUCCESS;
}
