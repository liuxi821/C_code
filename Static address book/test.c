#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
#include<stdio.h>
enum    //枚举
{
    EXIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
    SORT,
    CLEAR,
};
menu()
{
    printf("******************************\n");
    printf("****  1.add      2.del    ****\n");
    printf("****  3.search   4.modify ****\n");
    printf("****  5.show     6.sort   ****\n");//排序
    printf("****  7.clear    0.exit   ****\n");
    printf("******************************\n");
}
void test()
{
    int input = 0;
    Contact my_con;
    InitContact(&my_con);//初始化
    do
    {
        menu();
        printf("请输入您的选项:>");
        scanf("%d", &input);
        switch (input)
        {
        case ADD:
            AddContact(&my_con);
            break;
        case DEL:
            DelContact(&my_con);
            break;
        case SEARCH:
            SearchContact(&my_con);
            break;
        case MODIFY:
            ModifyContact(&my_con);
            break;
        case SHOW:
            ShowContact(&my_con);
            break;
        case SORT:
            SortContact(&my_con);
            break;
        case CLEAR:
            ClearContact(&my_con);
            break;
        case EXIT:
            break;
        default:
            printf("输入错误，请重新输入\n");
            break;
        }
    } while (input);
}
int main()
{
    test();
    return 0;
}
