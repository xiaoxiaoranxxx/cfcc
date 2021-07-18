#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

//粘贴的csdn一起学编程,膜拜大佬...

char filename[20] = {0};

typedef struct Student
{

    int num;

    char name[10];

    float chinese;

    float math;

    float english;

    float total;

    struct Student *next;

} STU;

int MainInterface()
{

    int key;

    system("cls");

    printf("\n\n");

    printf("\t\t\t=============================================\n");
    printf("\t\t\t|          欢迎来到学生成绩管理系统        |\n");
    printf("\t\t\t|===========================================|\n");
    printf("\t\t\t|                1.录入学员                |\n");
    printf("\t\t\t|                2.查找学员                |\n");
    printf("\t\t\t|                3.删除学员                |\n");
    printf("\t\t\t|                4.修改成绩                |\n");
    printf("\t\t\t|                5.打开文件                |\n");
    printf("\t\t\t|                0.退出系统                |\n");
    printf("\t\t\t=============================================\n");

    printf("\t\t\t请选择:");

    scanf("%d", &key);

    return key;
}

STU *CreateList()
{

    STU *p = (STU *)malloc(sizeof(STU));

    if (p != NULL)

        p->next = NULL;

    return p;
}

int NumIsExist(STU *plist, int num)
{

    plist = plist->next;

    while (plist != NULL)

    {

        if (plist->num == num)

            return 1;

        plist = plist->next;
    }

    return 0;
}

void InsertStu(STU *plist)
{

    system("cls");

    printf("\n\n");

    printf("\t\t\t=============================================\n");

    printf("\t\t\t|              正在录入学员信息            |\n");

    printf("\t\t\t=============================================\n");

    STU *p = plist;

    int count = 0;

    printf("\t\t\t请问需要添加多少学员:");

    scanf("%d", &count);

    if (count <= 0)

        return;

    for (int i = 0; i < count; i++)
    {

        STU *pnew = (STU *)malloc(sizeof(STU));

        if (pnew == NULL)
            return;

        printf("\t\t\t请输入学生学号:");

        scanf("%d", &pnew->num);

        while (1)

        {

            if (NumIsExist(plist, pnew->num))

            {

                printf("\t\t\t学号重复,请重新输入学号:");

                scanf("%d", &pnew->num);
            }

            else

                break;
        }

        printf("\t\t\t请输入学生姓名:");

        scanf("%s", pnew->name);

        printf("\t\t\t请输入语文成绩:");

        scanf("%f", &pnew->chinese);

        printf("\t\t\t请输入数学成绩:");

        scanf("%f", &pnew->math);

        printf("\t\t\t请输入英语成绩:");

        scanf("%f", &pnew->english);

        pnew->total = pnew->chinese + pnew->math + pnew->english;

        pnew->next = NULL;

        //头插法? 尾插法? 任意位置插入?

        p = plist;

        while (p->next != NULL)

        {
            if (pnew->num < p->next->num)
            {
                pnew->next = p->next;
                p->next = pnew;

                break;
            }

            p = p->next;
        }

        p->next = pnew;
    }
}

void SerchByNum(STU *plist)
{

    int num = 0;

    system("cls");

    printf("\n\n");

    printf("\t\t\t=============================================\n");

    printf("\t\t\t|              正在查找学员信息            |\n");

    printf("\t\t\t=============================================\n");

    printf("\t\t\t请输入学员学号:");

    scanf("%d", &num);

    while (plist != NULL)

    {

        if (plist->num == num)

        {

            printf("\t\t\t学号\t姓名\t语文\t数学\t英语\t总分\n");

            printf("\t\t\t%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",

                   plist->num, plist->name, plist->chinese,

                   plist->math, plist->english, plist->total);

            printf("\t\t\t");

            system("pause");

            return;
        }

        plist = plist->next;
    }
    printf("\t\t\t没有找到该学生!!\n");
    printf("\t\t\t");
    system("pause");
}

void SerchByName(STU *plist)
{

    char name[10] = {0};

    system("cls");

    printf("\n\n");

    printf("\t\t\t=============================================\n");

    printf("\t\t\t|              正在查找学员信息            |\n");

    printf("\t\t\t=============================================\n");

    printf("\t\t\t请输入学员姓名:");

    scanf("%s", &name);

    int n = 1;

    while (plist != NULL)

    {

        if (strcmp(name, plist->name) == 0)

        {

            if (n)
            {

                printf("\t\t\t学号\t姓名\t语文\t数学\t英语\t总分\n");

                n = 0;
            }

            printf("\t\t\t%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",

                   plist->num, plist->name, plist->chinese,

                   plist->math, plist->english, plist->total);
        }

        plist = plist->next;
    }

    if (n)

        printf("\t\t\t没有找到该学生!!\n");

    printf("\t\t\t");

    system("pause");
}

void SerchAllStu(STU *plist)
{

    plist = plist->next;

    system("cls");

    printf("\n\n");

    printf("\t\t\t=============================================\n");

    printf("\t\t\t|              正在查找学员信息            |\n");

    printf("\t\t\t=============================================\n");

    if (plist == NULL)

    {

        printf("\t\t\t没有学员信息!\n");

        printf("\t\t\t");

        system("pause");

        return;
    }

    printf("\t\t\t学号\t姓名\t语文\t数学\t英语\t总分\n");

    while (plist != NULL)

    {

        printf("\t\t\t%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",

               plist->num, plist->name, plist->chinese,

               plist->math, plist->english, plist->total);

        plist = plist->next;
    }

    printf("\t\t\t");

    system("pause");
}

void SerchMain(STU *plist)
{

    int key;

    do
    {

        system("cls");

        printf("\n\n");

        printf("\t\t\t=============================================\n");

        printf("\t\t\t|              正在查找学员信息            |\n");

        printf("\t\t\t|===========================================|\n");

        printf("\t\t\t|                                          |\n");

        printf("\t\t\t|                1.按学号查找              |\n");

        printf("\t\t\t|                2.按姓名查找              |\n");

        printf("\t\t\t|                3.查看所有项              |\n");

        printf("\t\t\t|                0.返回主菜单              |\n");

        printf("\t\t\t|                                          |\n");

        printf("\t\t\t=============================================\n");

        printf("\t\t\t请选择:");

        scanf("%d", &key);

        switch (key)
        {

        case 1:
            SerchByNum(plist);
            break;

        case 2:
            SerchByName(plist);
            break;

        case 3:
            SerchAllStu(plist);
            break;
        }

    } while (key != 0);
}

void DeleteStu(STU *plist)
{

    int num = 0;

    char key = '\0';

    STU *pre = plist;

    STU *p = plist->next;

    system("cls");

    printf("\n\n");

    printf("\t\t\t=============================================\n");

    printf("\t\t\t|              正在准备删除信息            |\n");

    printf("\t\t\t=============================================\n");

    printf("\t\t\t请输入需要删除的学号:");

    scanf("%d", &num);

    while (p != NULL)

    {

        if (p->num == num)

        {

            printf("\t\t\t学号\t姓名\t语文\t数学\t英语\t总分\n");

            printf("\t\t\t%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",

                   p->num, p->name, p->chinese,

                   p->math, p->english, p->total);

            printf("\t\t\t是否删除? [Y/N] : ");

            getchar();

            scanf("%c", &key);

            if (key == 'N' || key == 'n')

                return;

            else if (key == 'Y' || key == 'y')

            {

                pre->next = p->next;

                free(p);

                p = NULL;

                printf("\t\t\t删除成功!!\n");

                printf("\t\t\t");

                system("pause");

                return;
            }
        }

        pre = pre->next;

        p = p->next;
    }

    printf("\t\t\t没有找到该学生!!\n");

    printf("\t\t\t");

    system("pause");
}

void ModifyStu(STU *plist)
{

    int num = 0;

    STU *p = plist->next;

    char key = '\0';

    system("cls");

    printf("\n\n");

    printf("\t\t\t=============================================\n");

    printf("\t\t\t|              正在准备修改信息            |\n");

    printf("\t\t\t=============================================\n");

    printf("\t\t\t请输入需要修改的学号:");

    scanf("%d", &num);

    while (p != NULL)

    {

        if (num == p->num)

        {

            printf("\t\t\t学号\t姓名\t语文\t数学\t英语\t总分\n");

            printf("\t\t\t%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",

                   p->num, p->name, p->chinese,

                   p->math, p->english, p->total);

            printf("\t\t\t是否修改? [Y/N] : ");

            getchar();

            scanf("%c", &key);

            if (key == 'N' || key == 'n')

                return;

            else if (key == 'Y' || key == 'y')

            {

                printf("\n\t\t\t==============\n");

                printf("\t\t\t1.修改姓名\n\t\t\t2.修改语文\n\t\t\t3.修改数学\n\t\t\t4.修改英语\n\t\t\t0.返回\n");

                printf("\t\t\t==============\n");

                printf("\t\t\t请选择:");

                getchar();

                scanf("%c", &key);

                if (key == '1')
                {

                    printf("\t\t\t新的姓名:");

                    scanf("%s", p->name);
                }

                else if (key == '2')
                {

                    printf("\t\t\t新的语文成绩:");

                    scanf("%f", &p->chinese);
                }

                else if (key == '3')
                {

                    printf("\t\t\t新的数学成绩:");

                    scanf("%f", &p->math);
                }

                else if (key == '4')
                {

                    printf("\t\t\t新的英语成绩:");

                    scanf("%f", &p->english);
                }

                else if (key == '0')
                    return;

                printf("\t\t\t修改后的信息如下:\n");

                printf("\t\t\t学号\t姓名\t语文\t数学\t英语\t总分\n");

                printf("\t\t\t%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",

                       p->num, p->name, p->chinese,

                       p->math, p->english, p->total);
                printf("\t\t\t");
                system("pause");
                return;
            }
        }
        p = p->next;
    }

    printf("\t\t\t没有找到该学员!!\n");

    printf("\t\t\t");

    system("pause");
}

STU *OpenStuFile()
{

    char c;

    STU *pstu = NULL;

    STU *ptem = NULL;

    FILE *fp = NULL;

    while (1)
    {

        system("cls");

        printf("\n\n");

        printf("\n\n");

        printf("\t\t\t=============================================\n");

        printf("\t\t\t|          欢迎来到学生成绩管理系统        |\n");

        printf("\t\t\t|                                          |\n");

        printf("\t\t\t|            【肖萧然最秀】          |\n");

        printf("\t\t\t=============================================\n");

        printf("\t\t\t请输入班级(如:3年2班):");

        scanf("%s", filename);

        fp = fopen(filename, "rb+");

        if (fp != NULL)
            break; //打开成功

        printf("\t\t\t文件不存在!是否创建该文件? [Y/N] : ");

        getchar();

        scanf("%c", &c);

        if (c == 'Y' || c == 'y')

        {

            fp = fopen(filename, "wb+");

            if (fp != NULL)

                break;

            else

                continue;
        }

        else

            continue;
    }

    pstu = CreateList();

    while (1)

    {

        STU *pnew = (STU *)malloc(sizeof(STU));

        pnew->next = NULL;

        if (fscanf(fp, "%d\t%s\t%f\t%f\t%f\t%f\n",

                   &pnew->num, pnew->name, &pnew->chinese,

                   &pnew->math, &pnew->english, &pnew->total) == EOF)

        {

            free(pnew);

            pnew = NULL;

            break;
        }

        //头插法? 尾插法? 任意位置插入?

        ptem = pstu;

        while (ptem->next != NULL)

        {

            if (pnew->num < ptem->next->num)

            {

                pnew->next = ptem->next;

                ptem->next = pnew;

                break;
            }

            ptem = ptem->next;
        }

        ptem->next = pnew;
    }

    fclose(fp);

    return pstu;
}

void CloseStuFile(STU *plist)
{

    FILE *fp = NULL;

    plist = plist->next;

    //只写方式打开文件

    if ((fp = fopen(filename, "wb+")) == NULL)

    {

        printf("打开文件失败!");
    }

    else

    {
        //遍历链表输出到文件
        while (plist != NULL)
        {
            fprintf(fp, "%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",

                    plist->num, plist->name, plist->chinese,

                    plist->math, plist->english, plist->total);

            plist = plist->next;
        }
    }

    fclose(fp);
}

int main()
{
    int key = -1;

    STU *pList = NULL;

    pList = OpenStuFile(); //初始化链表
    while (key != 0)
    {
        key = MainInterface();
        switch (key)
        {
        case 1:
            InsertStu(pList);
            break;
        case 2:
            SerchMain(pList);
            break;
        case 3:
            DeleteStu(pList);
            break;
        case 4:
            ModifyStu(pList);
            break;
        case 0:
            CloseStuFile(pList);
            break;
        }
    }

    return 0;
}