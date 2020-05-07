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
			printf("\t\t���ݳɹ�\n");
		}
	}
}
void AddContact(struct Contact* ps)
{
	system("cls");
	printf("\t\t----------------------------------\n");
	CheckCapacity(ps);//��⵱ǰͨѶ¼�������������ˣ���������������û�������ֱ��������Ϣ
	//��������
	printf("\t\t����������:>");
	scanf("%s", ps->data[ps->size].name);
	printf("\t\t����������:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("\t\t�������Ա�:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("\t\t������绰:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("\t\t������סַ:>");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("\t\t��ӳɹ�\n");
	printf("\t\t----------------------------------\n");
	printf("\t\t3����Զ��˳�����ҳ��\n");
	Sleep(3000);
	system("cls");
}
void ShowContact(const struct Contact* ps)
{
	system("cls");
	printf("\t\t--------------------------------------------------------------\n");
	if (ps->size == 0)
	{
		printf("\t\tͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("\t\t%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����","����","�Ա�","�绰","סַ");
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
	printf("\t\t3����Զ��˳�����ҳ��\n");
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
	printf("\t\t3����Զ��˳�����ҳ��\n");
	Sleep(3000);
	system("cls");
}
void DelContact(struct Contact* ps)
{
	system("cls");
	printf("\t\t----------------------------------\n");
	char name[MAX_NAME];
	printf("\t\t������ɾ���˵�����:>");
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
		printf("\t\t��Ҫɾ�����˲����ڣ�\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("\t\tɾ���ɹ�\n");
	}
	printf("\t\t----------------------------------\n");
	printf("\t\t3����Զ��˳�����ҳ��\n");
	Sleep(3000);
	system("cls");
}
void SearchContact(struct Contact* ps)
{
	system("cls");
	printf("\t\t----------------------------------------------------------------------\n");
	char name[MAX_NAME];
	printf("\t\t��������Ҫ���Ҷ��������:>");
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
		printf("\t\t�Բ���û���ҵ���Ҫ���ҵ��ˣ�\n");
	}
	else
	{
		printf("\t\t%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("\t\t%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
	printf("\t\t-----------------------------------------------------------------------\n");
	printf("\t\t3����Զ��˳�����ҳ��\n");
	Sleep(3000);
	system("cls");
}
void ModifyContact(struct Contact* ps)
{
	system("cls");
	printf("\t\t---------------------------------------------------------------------------\n");
	char name[MAX_NAME];
	printf("\t\t��������Ҫ�޸Ķ��������:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("\t\t�Բ���û���ҵ���Ҫ���ҵ��ˣ�\n");
	}
	else
	{
		printf("\t\t%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("\t\t����������:>");
		scanf("%s", ps->data[pos].name);
		printf("\t\t����������:>");
		scanf("%d", &(ps->data[pos].age));
		printf("\t\t�������Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("\t\t������绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("\t\t������סַ:>");
		scanf("%s", ps->data[pos].addr);
		printf("\t\t�޸ĳɹ�\n");
	}
	printf("\t\t----------------------------------------------------------------------------\n");
	printf("\t\t3����Զ��˳�����ҳ��\n");
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
	printf("\t\t%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
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
	printf("\t\t3����Զ��˳�����ҳ��\n");
	Sleep(3000);
	system("cls");
}

void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}