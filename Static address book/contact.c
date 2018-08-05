#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
void InitContact(pContact pcon)
{
    pcon->sz = 0;
    memset(pcon->data, 0, sizeof(pcon->data));//sizeof(pcon->data)数组名单独放在sizeof内部，表示整个数组

}
void AddContact(pContact pcon)
{
    assert(pcon->data);
    if (pcon->sz == MAX)
    {
        printf("通讯录已满\n");
        return;
    }
    printf("请输入名字：>");
    scanf("%s", pcon->data[pcon->sz].name);
    printf("请输入年龄：>");
    scanf("%d", &(pcon->data[pcon->sz].age));
    printf("请输入性别：>");
    scanf("%s", pcon->data[pcon->sz].sex);
    printf("请输入地址：>");
    scanf("%s", pcon->data[pcon->sz].addr);
    printf("请输入电话：>");
    scanf("%s", pcon->data[pcon->sz].tele);

    printf("添加成功\n");
    pcon->sz++;
}
void DelContact(pContact pcon)
{
    char name[NAME_MAX];
    printf("请输入你要查找的姓名:>");
    scanf("%s", name);
    int p = 0;//利用p接收FindEntry返回的地址
    p = FindEntry(pcon, name);

    if (p != -1)
    {
        int j = 0;
        for (j = p; j < pcon->sz; j++)
        {
            pcon->data[j] = pcon->data[j + 1];//利用后面一个覆盖前一个，从而达到删除的效果
        }
        pcon->sz--;
        printf("删除成功\n");
    }
    else
    {
        printf("没有此人\n");
        return;
    }

}
static int FindEntry(pContact pcon, char name[])//查找函数入口
{
    int i = 0;
    for (i = 0; i < pcon->sz; i++)
    {
        if (strcmp(pcon->data[i].name, name) == 0)//
        {
            return i;//找到，返回下标
        }
    }
    return -1;//没找到返回-1
}
void SearchContact(pContact pcon)
{
    char name[NAME_MAX];
    printf("请输入你要查找的姓名:>");
    scanf("%s", name);//pcon->data[pcon->sz].name
    int p = FindEntry(pcon, name);
    if (p == -1)
    {
        printf("没有此人\n");
        return;
    }
    else
    {
        printf("%10s\t%4s\t%5s\t%20s\t%15s\t\n",
            "name", "age", "sex", "addr", "tele");
        printf("%10s\t%4d\t%5s\t%20s\t%15s\t\n",
            pcon->data[p].name,   //p为查找返回的下标
            pcon->data[p].age,
            pcon->data[p].sex,
            pcon->data[p].addr,
            pcon->data[p].tele);
    }
}
void ModifyContact(pContact pcon)
{
    char name[NAME_MAX];
    printf("请输入要修改的联系人姓名:>");
    scanf("%s", name);
    int p = 0;//利用pos接收FindEntry返回的地址
    p = FindEntry(pcon, name);
    if (p != -1)
    {
        printf("请输入修改后的姓名： ");
        scanf("%s", pcon->data[pcon->sz].name);
        printf("请输入修改后的性别： ");
        scanf("%s", pcon->data[pcon->sz].sex);
        printf("请输入修改后的年龄： ");
        scanf("%d", &pcon->data[pcon->sz].age);
        printf("请输入修改后的电话： ");
        scanf("%s", pcon->data[pcon->sz].tele);
        printf("请输入修改后的地址： ");
        scanf("%s", pcon->data[pcon->sz].addr);
        printf("修改完毕\n");
    }
    else
    {
        printf("没有此人\n");
    }
}
void ShowContact(const pContact pcon)
{
    int i = 0;
    printf("%10s\t%4s\t%5s\t%20s\t%15s\t\n",
        "name", "age", "sex", "addr", "tele");
    for (i = 0; i < pcon->sz; i++)
    {
        printf("%10s\t%4d\t%5s\t%20s\t%15s\t\n",
            pcon->data[i].name,
            pcon->data[i].age,
            pcon->data[i].sex,
            pcon->data[i].addr,
            pcon->data[i].tele);
    }
}
void SortContact(pContact pcon)
{
    int i = 0;
    for (i = 0; i < pcon->sz; i++)
    {
        if (strcmp(pcon->data[i].name, pcon->data[i + 1].name) > 0)
        {
            struct PeoInfo tem;
            tem = pcon->data[i];
            pcon->data[i] = pcon->data[i + 1];
            pcon->data[i + 1] = tem;
        }
    }
    printf("排序完成\n");
}
void ClearContact(pContact pcon)
{
    pcon->sz = 0;
}
