#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"



void InitContact(struct Contact* stu)
{
	memset(stu->data, 0, sizeof(stu->data));
	stu->size = 0;
}


void AddContact(struct Contact* stu)
{
	if (stu->size == MAX)
	{
		printf("通讯录已满，无法添加信息!\n");
	}
	else
	{
		printf("请添加姓名：");
		scanf("%s", (stu->data)[stu->size].name);
		printf("请添加年龄：");
		scanf("%d", &((stu->data)[stu->size].age));
		printf("请添加电话：");
		scanf("%s", (stu->data)[stu->size].tele);
		printf("请添加性别：");
		scanf("%s", (stu->data)[stu->size].sex);
		printf("请添加地址：");
		scanf("%s", (stu->data)[stu->size].addres);
		stu->size++;
		printf("添加成功\n");
	}
}


void ShowContact(const struct Contact* stu)
{
	if (stu->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-10s\t%-5s\t%-10s\t%-5s\t%-10s\n", "姓名", "年龄", "电话", "性别", "地址");
		for (int i = 0; i < stu->size; i++)
		{
			printf("%-10s\t%-5d\t%-10s\t%-5s\t%-10s\n",
				stu->data[i].name,
				stu->data[i].age,
				stu->data[i].tele,
				stu->data[i].sex,
				stu->data[i].addres);
		}
	}
}


static int FindByName(const struct Contact* stu,char name[nlen] )
{
	int i = 0;
	for (i = 0; i < stu->size; i++)
	{
		if (0 == strcmp(stu->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

void DeleteContact(struct Contact* stu)
{
	if (stu->size == 0)
	{
		printf("通讯录为空，无法删除\n");
	}
	char name[nlen];
	printf("请输入要删除信息人的名字：");
	scanf("%s", name);	
	int ret = FindByName(stu, name);
	if (ret == -1)
	{
		printf("您要删除的信息不存在！\n");
	}
	else
	{
		for (int j = ret; j < stu->size - 1; j++)
		{
			stu->data[j] = stu->data[j + 1];
		}
		stu->size--;
		printf("删除成功\n");
	}
}


void ReadContact(const struct Contact* stu)
{
	printf("请输入要查找信息人的名字：");
	char name[nlen];
	scanf("%s", name);
	int ret = FindByName(stu, name);
	if (ret == -1)
	{
		printf("您要查找的信息不存在\n");
	}
	else
	{
		printf("%-10s\t%-5s\t%-10s\t%-5s\t%-10s\n", "姓名", "年龄", "电话", "性别", "地址");
		printf("%-10s\t%-5d\t%-10s\t%-5s\t%-10s\n",
			stu->data[ret].name,
			stu->data[ret].age,
			stu->data[ret].tele,
			stu->data[ret].sex,
			stu->data[ret].addres);
	}
}


void UpdateContact(struct Contact* stu)
{
	printf("请输入要该信息人的名字：");
	char name[nlen];
	scanf("%s", name);
	int ret = FindByName(stu, name);
	if (ret == -1)
	{
		printf("您要修改的信息不存在\n");
	}
	else
	{
		printf("请添加姓名：");
		scanf("%s", (stu->data)[ret].name);
		printf("请添加年龄：");
		scanf("%d", &((stu->data)[ret].age));
		printf("请添加电话：");
		scanf("%s", (stu->data)[ret].tele);
		printf("请添加性别：");
		scanf("%s", (stu->data)[ret].sex);
		printf("请添加地址：");
		scanf("%s", (stu->data)[ret].addres);
		printf("修改成功\n");
	}
}


int cmp_s(const void* elem1, const void* elem2)
{
	return strcmp((char*)elem1, (char*)elem2);
}

void SortContact(struct Contact* stu)
{
	qsort(stu, stu->size, sizeof(stu->data[0]), cmp_s);
	printf("%-10s\t%-5s\t%-10s\t%-5s\t%-10s\n", "姓名", "年龄", "电话", "性别", "地址");
	for (int i = 0; i < stu->size; i++)
	{
		printf("%-10s\t%-5d\t%-10s\t%-5s\t%-10s\n",
			stu->data[i].name,
			stu->data[i].age,
			stu->data[i].tele,
			stu->data[i].sex,
			stu->data[i].addres);
	}
}