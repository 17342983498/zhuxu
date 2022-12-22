#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//void Print(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Print(arr,sz);
//	return 0;
//}


//void Print(int (*p)[10], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		/*printf("%d ", (*p)[i]);*/
//		printf("%d ", *((*p)+i));
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Print(&arr, sz);
//	return 0;
//}


//void Print(int *arr, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr+i));
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Print(arr,sz);
//	return 0;
//}


//void print_arr(int(*p)[5], int x, int y)
//{
//	for (int i = 0; i < x; i++)
//	{
//		for (int j = 0; j < y; j++)
//		{
//			printf("%d ", *(*(p + i) + j));
//		}
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	print_arr(arr, 3, 5);//arr数组名，代表第一个元素地址，所以那指针接收，第一个元素表示第一行，第一行又是一个数组，所以拿数组指针接收。
//	return 0;
//}

//void menu()
//{
//	printf("****************************\n");
//	printf("*****  1.Add    2.Sub  *****\n");
//	printf("*****  3.Mul    4.Div  *****\n");
//	printf("*****  0.EXIT          *****\n");
//	printf("****************************\n");
//}
//
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int Sub(int a, int b)
//{
//	return a - b;
//}
//
//int Mul(int a, int b)
//{
//	return a * b;
//}
//
//int Div(int a, int b)
//{
//	return a / b;
//}
//
//
//int main()
//{
//	int a, b = 0;
//	int input = 0;
//	int ret = 0;
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数：");
//			scanf("%d %d", &a, &b);
//			ret = Add(a, b);
//			printf("%d\n", ret);
//			break;
//		case 2:
//			printf("请输入两个操作数：");
//			scanf("%d %d", &a, &b);
//			ret = Sub(a, b);
//			printf("%d\n", ret);
//			break;
//		case 3:
//			printf("请输入两个操作数：");
//			scanf("%d %d", &a, &b);
//			ret = Mul(a, b);
//			printf("%d\n", ret);
//			break;
//		case 4:
//			printf("请输入两个操作数：");
//			scanf("%d %d", &a, &b);
//			ret = Div(a, b);
//			printf("%d\n", ret);
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("输入错误，请重新输入：\n");
//		}
//	} while (input);
//	return 0;
//}

#include <windows.h>

void menu()
{
	printf("****************************\n");
	printf("*****  1.Add    2.Sub  *****\n");
	printf("*****  3.Mul    4.Div  *****\n");
	printf("*****  0.EXIT          *****\n");
	printf("****************************\n");
}


int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

int Mul(int a, int b)
{
	return a * b;
}

int Div(int a, int b)
{
	return a / b;
}


int main()
{
	int a, b = 0;
	int input = 0;
	int ret = 0;

	do
	{
		menu();
		printf("请选择：");
		int(*p[5])(int a,int b) = { 0, Add, Sub, Mul, Div };
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输入操作数：");
			scanf("%d %d", &a, &b);
			ret = p[input]( a, b);
			printf("%d\n", ret);
			Sleep(1000);
			system("cls");
		}
		else if (input == 0)
		{
			printf("退出\n");
			Sleep(1000);
			break;
		}
		else
		{
			printf("请重新输入！\n");
			Sleep(1000);
			system("cls");
		}

	} while (input);
	return 0;
}