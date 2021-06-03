#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 4
int main()
{
    FILE *fp[M]; //定义文件指针数组
    char ch, filename[40], mode[4], fn[M + 1][40] = {0, 0, 0, 0};
    int i = 1, n = 0;
    while (i <= M)
    {
        printf("\nPlease input the filename and mode(%d):\n", i);
        gets(filename); //输入要打开的文件名
        fflush(stdin);  //刷新输入缓冲区
        printf("Open mode-->");
        gets(mode);     //输入使用文件方式
        //使用fopen函数打开文件，检查打开是否成功
        if ((fp[i] = fopen(filename, mode)) != NULL)
        { //若成功则输出成功的消息，并将文件保存在数组fn中
            printf("Successful open %s in mode %s.\n", filename, mode);
            strcpy(fn[i], filename);
        }
        else //若不成功则输出不成功的消息
            printf("Error open file %s in mode %s.\n", filename, mode);
        i++;
    }
    printf("Please input the filename which must close.\n ");
    gets(filename);          //输入要关闭的文件名
    for (i = 1; i <= M; i++) //从文件指针数组中找到指向要关闭的文件的指针
    {
        if (strcmp(fn[i], filename) == 0)
        {
            n = i;
            break;
        }
    }
    if (n == 0) //若n等于0则说明要关闭的文件并没有打开
        printf("Opens file named %s not to succeed!\n", filename);
    else
    {
        if (fclose(fp[n]) == 0) /* 检测是否关闭成功 */
            printf("Success close file named %s\n", fn[n]);
        else
        {
            printf("can not close file named %s!\n", filename);
            exit(1); //退出程序
        }
    }
    printf("\nclose all file...");


    // scanf("%c", &ch);
    // if (ch == 'y') //关闭所有文件
    //     printf("The success closure is left over %d files.\n", fcloseall());
}

/*
Please input the filename and mode(1):
32.txt
Open mode-->r
Successful open 32.txt in mode r.

Please input the filename and mode(2):
32.txt
Open mode-->w
Successful open 32.txt in mode w.

Please input the filename and mode(3):
32.txt
Open mode-->w
Successful open 32.txt in mode w.

Please input the filename and mode(4):
32.txt
Open mode-->r
Successful open 32.txt in mode r.
Please input the filename which must close.
 32.txt
Success close file named 32.txt

close all file...
*/