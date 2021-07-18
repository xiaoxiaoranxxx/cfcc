#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

//ճ����csdnһ��ѧ���,Ĥ�ݴ���...

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
    printf("\t\t\t|          ��ӭ����ѧ���ɼ�����ϵͳ        |\n");
    printf("\t\t\t|===========================================|\n");
    printf("\t\t\t|                1.¼��ѧԱ                |\n");
    printf("\t\t\t|                2.����ѧԱ                |\n");
    printf("\t\t\t|                3.ɾ��ѧԱ                |\n");
    printf("\t\t\t|                4.�޸ĳɼ�                |\n");
    printf("\t\t\t|                5.���ļ�                |\n");
    printf("\t\t\t|                0.�˳�ϵͳ                |\n");
    printf("\t\t\t=============================================\n");

    printf("\t\t\t��ѡ��:");

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

    printf("\t\t\t|              ����¼��ѧԱ��Ϣ            |\n");

    printf("\t\t\t=============================================\n");

    STU *p = plist;

    int count = 0;

    printf("\t\t\t������Ҫ��Ӷ���ѧԱ:");

    scanf("%d", &count);

    if (count <= 0)

        return;

    for (int i = 0; i < count; i++)
    {

        STU *pnew = (STU *)malloc(sizeof(STU));

        if (pnew == NULL)
            return;

        printf("\t\t\t������ѧ��ѧ��:");

        scanf("%d", &pnew->num);

        while (1)

        {

            if (NumIsExist(plist, pnew->num))

            {

                printf("\t\t\tѧ���ظ�,����������ѧ��:");

                scanf("%d", &pnew->num);
            }

            else

                break;
        }

        printf("\t\t\t������ѧ������:");

        scanf("%s", pnew->name);

        printf("\t\t\t���������ĳɼ�:");

        scanf("%f", &pnew->chinese);

        printf("\t\t\t��������ѧ�ɼ�:");

        scanf("%f", &pnew->math);

        printf("\t\t\t������Ӣ��ɼ�:");

        scanf("%f", &pnew->english);

        pnew->total = pnew->chinese + pnew->math + pnew->english;

        pnew->next = NULL;

        //ͷ�巨? β�巨? ����λ�ò���?

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

    printf("\t\t\t|              ���ڲ���ѧԱ��Ϣ            |\n");

    printf("\t\t\t=============================================\n");

    printf("\t\t\t������ѧԱѧ��:");

    scanf("%d", &num);

    while (plist != NULL)

    {

        if (plist->num == num)

        {

            printf("\t\t\tѧ��\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");

            printf("\t\t\t%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",

                   plist->num, plist->name, plist->chinese,

                   plist->math, plist->english, plist->total);

            printf("\t\t\t");

            system("pause");

            return;
        }

        plist = plist->next;
    }
    printf("\t\t\tû���ҵ���ѧ��!!\n");
    printf("\t\t\t");
    system("pause");
}

void SerchByName(STU *plist)
{

    char name[10] = {0};

    system("cls");

    printf("\n\n");

    printf("\t\t\t=============================================\n");

    printf("\t\t\t|              ���ڲ���ѧԱ��Ϣ            |\n");

    printf("\t\t\t=============================================\n");

    printf("\t\t\t������ѧԱ����:");

    scanf("%s", &name);

    int n = 1;

    while (plist != NULL)

    {

        if (strcmp(name, plist->name) == 0)

        {

            if (n)
            {

                printf("\t\t\tѧ��\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");

                n = 0;
            }

            printf("\t\t\t%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",

                   plist->num, plist->name, plist->chinese,

                   plist->math, plist->english, plist->total);
        }

        plist = plist->next;
    }

    if (n)

        printf("\t\t\tû���ҵ���ѧ��!!\n");

    printf("\t\t\t");

    system("pause");
}

void SerchAllStu(STU *plist)
{

    plist = plist->next;

    system("cls");

    printf("\n\n");

    printf("\t\t\t=============================================\n");

    printf("\t\t\t|              ���ڲ���ѧԱ��Ϣ            |\n");

    printf("\t\t\t=============================================\n");

    if (plist == NULL)

    {

        printf("\t\t\tû��ѧԱ��Ϣ!\n");

        printf("\t\t\t");

        system("pause");

        return;
    }

    printf("\t\t\tѧ��\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");

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

        printf("\t\t\t|              ���ڲ���ѧԱ��Ϣ            |\n");

        printf("\t\t\t|===========================================|\n");

        printf("\t\t\t|                                          |\n");

        printf("\t\t\t|                1.��ѧ�Ų���              |\n");

        printf("\t\t\t|                2.����������              |\n");

        printf("\t\t\t|                3.�鿴������              |\n");

        printf("\t\t\t|                0.�������˵�              |\n");

        printf("\t\t\t|                                          |\n");

        printf("\t\t\t=============================================\n");

        printf("\t\t\t��ѡ��:");

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

    printf("\t\t\t|              ����׼��ɾ����Ϣ            |\n");

    printf("\t\t\t=============================================\n");

    printf("\t\t\t��������Ҫɾ����ѧ��:");

    scanf("%d", &num);

    while (p != NULL)

    {

        if (p->num == num)

        {

            printf("\t\t\tѧ��\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");

            printf("\t\t\t%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",

                   p->num, p->name, p->chinese,

                   p->math, p->english, p->total);

            printf("\t\t\t�Ƿ�ɾ��? [Y/N] : ");

            getchar();

            scanf("%c", &key);

            if (key == 'N' || key == 'n')

                return;

            else if (key == 'Y' || key == 'y')

            {

                pre->next = p->next;

                free(p);

                p = NULL;

                printf("\t\t\tɾ���ɹ�!!\n");

                printf("\t\t\t");

                system("pause");

                return;
            }
        }

        pre = pre->next;

        p = p->next;
    }

    printf("\t\t\tû���ҵ���ѧ��!!\n");

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

    printf("\t\t\t|              ����׼���޸���Ϣ            |\n");

    printf("\t\t\t=============================================\n");

    printf("\t\t\t��������Ҫ�޸ĵ�ѧ��:");

    scanf("%d", &num);

    while (p != NULL)

    {

        if (num == p->num)

        {

            printf("\t\t\tѧ��\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");

            printf("\t\t\t%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",

                   p->num, p->name, p->chinese,

                   p->math, p->english, p->total);

            printf("\t\t\t�Ƿ��޸�? [Y/N] : ");

            getchar();

            scanf("%c", &key);

            if (key == 'N' || key == 'n')

                return;

            else if (key == 'Y' || key == 'y')

            {

                printf("\n\t\t\t==============\n");

                printf("\t\t\t1.�޸�����\n\t\t\t2.�޸�����\n\t\t\t3.�޸���ѧ\n\t\t\t4.�޸�Ӣ��\n\t\t\t0.����\n");

                printf("\t\t\t==============\n");

                printf("\t\t\t��ѡ��:");

                getchar();

                scanf("%c", &key);

                if (key == '1')
                {

                    printf("\t\t\t�µ�����:");

                    scanf("%s", p->name);
                }

                else if (key == '2')
                {

                    printf("\t\t\t�µ����ĳɼ�:");

                    scanf("%f", &p->chinese);
                }

                else if (key == '3')
                {

                    printf("\t\t\t�µ���ѧ�ɼ�:");

                    scanf("%f", &p->math);
                }

                else if (key == '4')
                {

                    printf("\t\t\t�µ�Ӣ��ɼ�:");

                    scanf("%f", &p->english);
                }

                else if (key == '0')
                    return;

                printf("\t\t\t�޸ĺ����Ϣ����:\n");

                printf("\t\t\tѧ��\t����\t����\t��ѧ\tӢ��\t�ܷ�\n");

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

    printf("\t\t\tû���ҵ���ѧԱ!!\n");

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

        printf("\t\t\t|          ��ӭ����ѧ���ɼ�����ϵͳ        |\n");

        printf("\t\t\t|                                          |\n");

        printf("\t\t\t|            ��Ф��Ȼ���㡿          |\n");

        printf("\t\t\t=============================================\n");

        printf("\t\t\t������༶(��:3��2��):");

        scanf("%s", filename);

        fp = fopen(filename, "rb+");

        if (fp != NULL)
            break; //�򿪳ɹ�

        printf("\t\t\t�ļ�������!�Ƿ񴴽����ļ�? [Y/N] : ");

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

        //ͷ�巨? β�巨? ����λ�ò���?

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

    //ֻд��ʽ���ļ�

    if ((fp = fopen(filename, "wb+")) == NULL)

    {

        printf("���ļ�ʧ��!");
    }

    else

    {
        //��������������ļ�
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

    pList = OpenStuFile(); //��ʼ������
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