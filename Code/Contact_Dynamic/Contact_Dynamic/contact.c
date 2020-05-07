#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void InitContcat(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = 3;
}
void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2)*sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("\t\t增容成功\n");
		}
	}
}
void AddContact(struct Contact* ps)
{
	system("cls");
	printf("\t\t----------------------------------\n");
	CheckCapacity(ps);//检测当前通讯录的容量，若满了，则增加容量，若没满，则就直接增加信息
	//增加数据
	printf("\t\t请输入名字:>");
	scanf("%s", ps->data[ps->size].name);
	printf("\t\t请输入年龄:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("\t\t请输入性别:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("\t\t请输入电话:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("\t\t请输入住址:>");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("\t\t添加成功\n");
	printf("\t\t----------------------------------\n");
	printf("\t\t3秒后自动退出至主页面\n");
	Sleep(3000);
	system("cls");
}
void ShowContact(const struct Contact* ps)
{
	system("cls");
	printf("\t\t--------------------------------------------------------------\n");
	if (ps->size == 0)
	{
		printf("\t\t通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("\t\t%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字","年龄","性别","电话","住址");
		for (i = 0; i < ps->size; i++)
		{
			printf("\t\t%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
	printf("\t\t---------------------------------------------------------------\n");
	printf("\t\t3秒后自动退出至主页面\n");
	Sleep(3000);
	system("cls");
}
int FindByName(struct Contact* ps, char name[MAX_NAME])
{
	system("cls");
	printf("\t\t----------------------------------\n");
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
	printf("\t\t----------------------------------\n");
	printf("\t\t3秒后自动退出至主页面\n");
	Sleep(3000);
	system("cls");
}
void DelContact(struct Contact* ps)
{
	system("cls");
	printf("\t\t----------------------------------\n");
	char name[MAX_NAME];
	printf("\t\t请输入删除人的名字:>");
	scanf("%s", name);
	/*int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			break;
		}
	}*/
	int pos = FindByName(ps, name);

	if (pos==-1)
	{
		printf("\t\t您要删除的人不存在！\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("\t\t删除成功\n");
	}
	printf("\t\t----------------------------------\n");
	printf("\t\t3秒后自动退出至主页面\n");
	Sleep(3000);
	system("cls");
}
void SearchContact(struct Contact* ps)
{
	system("cls");
	printf("\t\t----------------------------------------------------------------------\n");
	char name[MAX_NAME];
	printf("\t\t请输入您要查找对象的名字:>");
	scanf("%s", name);
	/*int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			break;
		}
	}*/
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("\t\t对不起，没有找到您要查找的人！\n");
	}
	else
	{
		printf("\t\t%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
		printf("\t\t%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
	printf("\t\t-----------------------------------------------------------------------\n");
	printf("\t\t3秒后自动退出至主页面\n");
	Sleep(3000);
	system("cls");
}
void ModifyContact(struct Contact* ps)
{
	system("cls");
	printf("\t\t---------------------------------------------------------------------------\n");
	char name[MAX_NAME];
	printf("\t\t请输入您要修改对象的名字:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("\t\t对不起，没有找到您要查找的人！\n");
	}
	else
	{
		printf("\t\t%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
		printf("\t\t请输入名字:>");
		scanf("%s", ps->data[pos].name);
		printf("\t\t请输入年龄:>");
		scanf("%d", &(ps->data[pos].age));
		printf("\t\t请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("\t\t请输入电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("\t\t请输入住址:>");
		scanf("%s", ps->data[pos].addr);
		printf("\t\t修改成功\n");
	}
	printf("\t\t----------------------------------------------------------------------------\n");
	printf("\t\t3秒后自动退出至主页面\n");
	Sleep(3000);
	system("cls");
}
void SortContact(struct Contact* ps)
{
	system("cls");
	printf("\t\t-----------------------------------------------------------------------\n");
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		int j = 0;
		for (j = 0; j < ps->size-i-1; j++)
		{
			if (strcmp(ps->data[j].name ,ps->data[j+1].name)>0)
			{
				struct PeoInfo ret ;
				ret = ps->data[j];
				ps->data[j] = ps->data[j+1];
				ps->data[j+1] = ret;
			}
		}
	}
	printf("\t\t%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
	for (i = 0; i < ps->size; i++)
	{
		printf("\t\t%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].tele,
			ps->data[i].addr);
	}
	printf("\t\t-----------------------------------------------------------------------\n");
	printf("\t\t3秒后自动退出至主页面\n");
	Sleep(3000);
	system("cls");
}

void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}