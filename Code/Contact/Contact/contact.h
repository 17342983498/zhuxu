#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
#define nlen 20
#define tlen 11
#define slen 10
#define alen 10


struct Infor
{
	char name[nlen];
	int age;
	char tele[tlen];
	char sex[slen];
	char addres[alen];
};


struct Contact
{
	struct Infor data[MAX];
	int size;
};


void InitContact(struct Contact* stu);

//void AddContact(struct Contact* stu);

void ShowContact(const struct Contact* stu);

void DeleteContact(struct Contact* stu);

void ReadContact(const struct Contact* stu);

//int FindByName(const struct Contact* stu, char name[nlen]);

void UpdateContact(struct Contact* stu);

void SortContact(struct Contact* stu);