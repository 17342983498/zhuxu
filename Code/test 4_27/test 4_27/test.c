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
		case 1:
			AddContact(&con);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			break;
		case 0:
			printf("�˳�ͬѧ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (n);
	return 0;

}
