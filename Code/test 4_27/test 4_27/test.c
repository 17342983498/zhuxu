#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("***********************************\n");
	printf("******* 1. add     2. del   *******\n");
	printf("******* 3. search  4. modify*******\n");
	printf("******* 5. show    6. sort  *******\n");
	printf("*******        0. exit      *******\n");
	printf("***********************************\n");
}
int main()
{
	int n = 0;
	//int size = 0;
	//
	////����ͬѧ¼
	//struct PeoInfo con[MAX];//���MAX���˵���Ϣ
	struct Contact con;//con����ͬѧ¼����߰���1000��Ԫ�ص�����size
	//��ʼ��ͬѧ¼
	InitContcat(&con);
	do
	{ 
		menu();
		printf("��ѡ��:>");
		scanf("%d", &n);
		switch (n)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("�˳�ͬѧ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (n);
	return 0;

}
