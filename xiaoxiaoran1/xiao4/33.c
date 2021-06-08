#include <stdio.h>
#include <stdlib.h>
char *write()
{
    FILE *fp;
    char *p;
    char filename[10];
    printf("input a filename-->");
    scanf("%s", filename);
    getchar();  //不写会导致生成文件有换行
    if ((fp = fopen(filename, "a")) == NULL)
        return 0;
    p = filename;
    char ch;
    printf("please this file content-->");
    ch=getchar();
    while (ch != '#')
    {
        fputc(ch, fp);
        ch = getchar();
    }
    fclose(fp);
    return p;
}
int read(char name[])
{
    FILE *fp;
    int i=0;
    char str[20][20];
    if ((fp = fopen(name, "r")) == NULL)
        return 1;
    printf("\nThe content of this file is:\n");
    while(fgets(str[i],20,fp)!=NULL){
        printf("%s", str[i]);
        i++;
    }
    fclose(fp);
    return 0;
}
int main()
{
    char *file_name_p;
    if ((file_name_p = write()) != NULL)
        printf("\nThe file was successfully written -->%s\n", file_name_p);
    else
    {
        printf("File creation failed...\n");
        exit(0);
    }
    char xiao[10] = {"33.txt"};
    if(read(xiao))
        printf("false");
    return 0;
}
