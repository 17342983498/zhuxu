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
	////创建同学录
	//struct PeoInfo con[MAX];//存放MAX个人的信息
	struct Contact con;//con就是同学录，里边包含1000个元素的数和size
	//初始化同学录
	InitContcat(&con);
	do
	{ 
		menu();
		printf("请选择:>");
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
			printf("退出同学录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (n);
	return 0;

}
