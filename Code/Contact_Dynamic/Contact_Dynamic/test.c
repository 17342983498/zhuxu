#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//void menu()
//{
//	printf("\n\n\t\t-------------------------欢迎使用-------------------------\n");
//	printf("\t\t☆☆ 1. ADD                           ☆☆\n\n");
//	printf("\t\t☆☆ 2. DEL                           ☆☆\n\n");
//	printf("\t\t☆☆ 3. SEARCH                        ☆☆\n\n");
//	printf("\t\t☆☆ 4. MODIFY                        ☆☆\n\n");
//	printf("\t\t☆☆ 5. SHOW                          ☆☆\n\n");
//	printf("\t\t☆☆ 6. SORT                          ☆☆\n\n");
//	printf("\t\t☆☆ 0. EXIT                          ☆☆\n\n");
//	printf("\t\t----------------------------------------------------------\n");
//}
int main()
{
	int n = 0;
	system("color 3E");
	//int size = 0;
	//
	////创建同学录
	//struct PeoInfo con[MAX];//存放MAX个人的信息
	struct Contact con;//con就是同学录，里边包含data指针和size和capacity
	//初始化同学录
	/*menu();*/

	InitContcat(&con);
	do
	{ 
		printf("\n\n\t\t-------------------------欢迎使用-------------------------\n");
		printf("\t\t☆☆ 1. ADD                           ☆☆\n\n");
		printf("\t\t☆☆ 2. DEL                           ☆☆\n\n");
		printf("\t\t☆☆ 3. SEARCH                        ☆☆\n\n");
		printf("\t\t☆☆ 4. MODIFY                        ☆☆\n\n");
		printf("\t\t☆☆ 5. SHOW                          ☆☆\n\n");
		printf("\t\t☆☆ 6. SORT                          ☆☆\n\n");
		printf("\t\t☆☆ 0. EXIT                          ☆☆\n\n");
		printf("\t\t----------------------------------------------------------\n");
		printf("\t\t★★★★★★★★★★★★★★★★\n");
		printf("\t\t请选择您要运行的选项按(0-6):");
		scanf("%d", &n);
		printf("\t\t★★★★★★★★★★★★★★★★\n");
		Sleep(1000);
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
			Sleep(1000);
			//销毁同学录
			DestroyContact(&con);
			printf("退出同学录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (n);
	return 0;

}
