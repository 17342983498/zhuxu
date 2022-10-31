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
		printf("ͨѶ¼�������޷������Ϣ!\n");
	}
	else
	{
		printf("�����������");
		scanf("%s", (stu->data)[stu->size].name);
		printf("��������䣺");
		scanf("%d", &((stu->data)[stu->size].age));
		printf("����ӵ绰��");
		scanf("%s", (stu->data)[stu->size].tele);
		printf("������Ա�");
		scanf("%s", (stu->data)[stu->size].sex);
		printf("����ӵ�ַ��");
		scanf("%s", (stu->data)[stu->size].addres);
		stu->size++;
		printf("��ӳɹ�\n");
	}
}


void ShowContact(const struct Contact* stu)
{
	if (stu->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-10s\t%-5s\t%-10s\t%-5s\t%-10s\n", "����", "����", "�绰", "�Ա�", "��ַ");
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
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
	}
	char name[nlen];
	printf("������Ҫɾ����Ϣ�˵����֣�");
	scanf("%s", name);	
	int ret = FindByName(stu, name);
	if (ret == -1)
	{
		printf("��Ҫɾ������Ϣ�����ڣ�\n");
	}
	else
	{
		for (int j = ret; j < stu->size - 1; j++)
		{
			stu->data[j] = stu->data[j + 1];
		}
		stu->size--;
		printf("ɾ���ɹ�\n");
	}
}


void ReadContact(const struct Contact* stu)
{
	printf("������Ҫ������Ϣ�˵����֣�");
	char name[nlen];
	scanf("%s", name);
	int ret = FindByName(stu, name);
	if (ret == -1)
	{
		printf("��Ҫ���ҵ���Ϣ������\n");
	}
	else
	{
		printf("%-10s\t%-5s\t%-10s\t%-5s\t%-10s\n", "����", "����", "�绰", "�Ա�", "��ַ");
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
	printf("������Ҫ����Ϣ�˵����֣�");
	char name[nlen];
	scanf("%s", name);
	int ret = FindByName(stu, name);
	if (ret == -1)
	{
		printf("��Ҫ�޸ĵ���Ϣ������\n");
	}
	else
	{
		printf("�����������");
		scanf("%s", (stu->data)[ret].name);
		printf("��������䣺");
		scanf("%d", &((stu->data)[ret].age));
		printf("����ӵ绰��");
		scanf("%s", (stu->data)[ret].tele);
		printf("������Ա�");
		scanf("%s", (stu->data)[ret].sex);
		printf("����ӵ�ַ��");
		scanf("%s", (stu->data)[ret].addres);
		printf("�޸ĳɹ�\n");
	}
}


int cmp_s(const void* elem1, const void* elem2)
{
	return strcmp((char*)elem1, (char*)elem2);
}

void SortContact(struct Contact* stu)
{
	qsort(stu, stu->size, sizeof(stu->data[0]), cmp_s);
	printf("%-10s\t%-5s\t%-10s\t%-5s\t%-10s\n", "����", "����", "�绰", "�Ա�", "��ַ");
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