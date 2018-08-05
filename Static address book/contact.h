#ifndef __CONTACT_H__//防止头文件的重复引用
#define __CONTACT_H__
#include <string.h>
#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 25
#define ADDR_MAX 30
#define TELE_MAX 12
#include<stdio.h>
#include<assert.h>
#include<string.h>

typedef struct PeoInfo
{
    char name[NAME_MAX];
    int age;
    char sex[SEX_MAX];
    char addr[ADDR_MAX];
    char tele[TELE_MAX];
}PeoInfo;

typedef struct Contact
{
    PeoInfo data[MAX];
    int sz ;              //将*之前的结构体重命名为pContact
}Contact, *pContact;      //Contact;
void InitContact(pContact pcon);//Contact* pcon
void AddContact(pContact pcon);
void DelContact(pContact pcon);
void SearchContact(pContact pcon);
void ModifyContact(pContact pcon);
void ShowContact(const pContact pcon);
void SortContact(pContact pcon);
void ClearContact(pContact pcon);
static int FindEntry(pContact pcon, char name[]);
#endif 
