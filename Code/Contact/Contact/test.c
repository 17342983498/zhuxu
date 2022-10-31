#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


void menu()
{
	printf("************************************\n");
	printf("******    ͨѶ¼����ϵͳ     *******\n");
	printf("************************************\n");
	printf("*******       1.ADD          *******\n");
	printf("*******       2.DELETE       *******\n");
	printf("*******       3.UPDATE       *******\n");
	printf("*******       4.READ         *******\n");
	printf("*******       5.SHOW         *******\n");
	printf("*******       6.SORT         *******\n");
	printf("*******       0.EXIT         *******\n");
	printf("************************************\n");
}

enum option
{
	EXIT,
	ADD,
	DELETE,
	UPDATE,
	READ,
	SHOW,
	SORT
};

int main()
{
	int input = 0;
	struct Contact stu;
	InitContact(&stu);
	do
	{
		menu();
		printf("��ѡ�������");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&stu);
			break;
		case DELETE:
			DeleteContact(&stu);
			break;
		case UPDATE:
			UpdateContact(&stu);
			break;
		case READ:
			ReadContact(&stu);
			break;
		case SHOW:
			ShowContact(&stu);
			break;
		case SORT:
			SortContact(&stu);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�����������²�����\n");
			break;
		}
	} while (input);
	return 0;
}