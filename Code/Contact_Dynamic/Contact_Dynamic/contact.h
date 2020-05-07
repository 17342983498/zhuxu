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
//ͨѶ¼����
struct Contact
{
	struct PeoInfo *data;//���һ����Ϣ
	int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ���
	int capacity;//��ǰͨѶ¼�������
};

//��������

void InitContcat(struct Contact* ps);//��ʼ��ͬѧ¼

void AddContact(struct Contact* ps);//����

void ShowContact(const struct Contact* ps);//չʾ

void DelContact(struct Contact* ps);//ɾ��

void SearchContact(struct Contact* ps);//����

void ModifyContact(struct Contact* ps);//�޸�

void SortContact(struct Contact* ps);//����

void DestroyContact(struct Contact* ps);//����