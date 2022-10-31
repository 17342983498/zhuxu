#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


void menu()
{
	printf("************************************\n");
	printf("******    通讯录管理系统     *******\n");
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
		printf("请选择操作：");
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
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误，请从新操作：\n");
			break;
		}
	} while (input);
	return 0;
}