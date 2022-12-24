#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

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
//void calc(int(*p)(int, int))
//{
//	int a, b = 0;
//	printf("请输入操作数：");
//	scanf("%d %d", &a, &b);
//	int ret = p(a, b);
//	printf("%d\n", ret);
//}
//
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calc(Add);
//			break;
//		case 2:
//			calc(Sub);
//			break;
//		case 3:
//			calc(Mul);
//			break;
//		case 4:
//			calc(Div);
//			break;
//		case 0:
//			printf("退出成功\n");
//			break;
//		default:
//			printf("输出错误请重新输入：");
//		}
//	} while (input);
//	return 0;
//}

//int cmp_int(const void* elem1, const void* elem2)
//{
//	return *(int*)elem1 - *(int*)elem2;
//}
//
//void swap(char* p1, char* p2, int width)
//{
//	for (int i = 0; i < width; i++)
//	{
//		char temp = *p1;
//		*p1 = *p2;
//		*p2 = temp;
//		p1++;
//		p2++;
//	}
//}
//
//
//void bubble_sort(const void* base, int sz, int width, int(*cmp)(void* elem1, void* elem2))
//{
//	for (int i = 0; i < sz - 1; i++)
//	{
//		for (int j = 0; j < sz -1 - i; j++)
//		{
//			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
//			{
//				swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 5, 9, 6, 3, 1, 4, 7, 8, 2, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}
//#include <string.h>
//struct S
//{
//	char name[20];
//	int age;
//};
//
//int cmp_by_name(const void* elem1, const void* elem2)
//{
//	return  strcmp(((struct S*)elem1)->name, ((struct S*)elem2)->name);
//}
//
//int cmp_by_age(const void* elem1, const void* elem2)
//{
//	return  ((struct S*)elem1)->age - ((struct S*)elem2)->age;
//}
//
//void swap(char* p1, char* p2, int width)
//{
//	for (int i = 0; i < width; i++)
//	{
//		char temp = *p1;
//		*p1 = *p2;
//		*p2 = temp;
//		p1++;
//		p2++;
//	}
//}
//
//
//void bubble_sort(const void* base, int sz, int width, int(*cmp)(void* elem1, void* elem2))
//{
//	for (int i = 0; i < sz - 1; i++)
//	{
//		for (int j = 0; j < sz -1 - i; j++)
//		{
//			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
//			{
//				swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
//			}
//		}
//	}
//}
//
//int main()
//{
//	struct S s[] = { {"zhuxu",22}, {"wanger",56}, {"auansi",24} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	bubble_sort(s, sz, sizeof(s[0]), cmp_by_name);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%s ", s[i].name);
//	}
//	printf("\n");
//	bubble_sort(s, sz, sizeof(s[0]), cmp_by_age);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%s ", s[i].name);
//	}
//	printf("\n");
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", s[i].age);
//	}
//	printf("\n");
//	return 0;
//}




int cmp_float(const void* elem1, const void* elem2)
{
	return *(float*)elem1 > *(float*)elem2 ? 1: -1;
}

void swap(char* p1, char* p2, int width)
{
	for (int i = 0; i < width; i++)
	{
		char temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		p1++;
		p2++;
	}
}


void bubble_sort(const void* base, int sz, int width, int(*cmp)(void* elem1, void* elem2))
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz -1 - i; j++)
		{
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
			{
				swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}

int main()
{
	float arr[] = { 5.65f, 9.21f, 23.1f, 2.31f, 4.32f };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_float);
	for (int i = 0; i < sz; i++)
	{
		printf("%.2lf ", arr[i]);
	}
	printf("\n");
	return 0;
}