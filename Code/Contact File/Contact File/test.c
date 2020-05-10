#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("***********************************\n");
	printf("******* 1. add     2. del   *******\n");
	printf("******* 3. search  4. modify*******\n");
	printf("******* 5. show    6. sort  *******\n");
	printf("******* 7.save     0. exit  *******\n");
	printf("***********************************\n");
}
int main()
{
	int n = 0;
	//int size = 0;
	//
	////创建同学录
	//struct PeoInfo con[MAX];//存放MAX个人的信息
	struct Contact con;//con就是同学录，里边包含data指针和size，capacity
	//初始化同学录
	InitContcat(&con);
	do
	{ 
		menu();
		printf("请选择:>");
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
			//销毁同学录-释放动态开辟的内存
			SaveContact(&con);
			DestroyContact(&con);
			printf("退出同学录\n");
			break;
		case SAVE:
			SaveContact(&con);
			printf("保存成功\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (n);
	return 0;

}
