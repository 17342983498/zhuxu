#define _CRT_SECURE_NO_WARNINGS 1


#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
};
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
//通讯录类型
struct Contact
{
	struct PeoInfo *data;//存放一个信息
	int size;//记录当前已经有的元素个数
	int capacity;//当前通讯录最大容量
};

//声明函数

void InitContcat(struct Contact* ps);//初始化同学录

void AddContact(struct Contact* ps);//增加

void ShowContact(const struct Contact* ps);//展示

void DelContact(struct Contact* ps);//删除

void SearchContact(struct Contact* ps);//查找

void ModifyContact(struct Contact* ps);//修改

void SortContact(struct Contact* ps);//排序

void DestroyContact(struct Contact* ps);//销毁