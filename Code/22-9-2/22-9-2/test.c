#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h.>
#include <stdlib.h>
#include <string.h>
//int main()
//{
//	char s = 'a';
//	const char* p = &s;
//	//*p = 'b';
//	s = 'b';
//	printf("%c\n", s);
//
//
//	return 0;
//}

//void Print(int x, int y)
//{
//	printf("%d\n", x + y);
//}
//int main()
//{
//	int x = 10;
//	int y = 20;
//	void (*p)(int,int) = Print;
//	(*p)(x, y);
//	(p)(x, y);
//	(**p)(x, y);
//	return 0;
//}


//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int input = 0;
//	int ret = 0;
//	int x, y = 0;
//	int(*p[5])(int , int ) = { 0, Add, Sub, Mul, Div };
//	printf("***********************\n");
//	printf("******1.Add 2.Sub******\n");
//	printf("******3.Mul 4.Div******\n");
//	printf("***********************\n");
//	printf("请输入算法数：");
//	scanf("%d", &input);
//	printf("请输入操作数：");
//	scanf("%d %d", &x,&y);
//	ret = (*p[input])(x, y);
//	printf("%d\n", ret);
//	return 0;
//}


//int calculate(int a, int b, int c)
//{
//	return a*b*c;
//}
//
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	int ret = calculate(a, b, c);
//	printf("%d\n", ret);
//	return 0;
//}


//void bubble_sort(int arr[],int sz)
//{
//	for (int i = 0; i < sz - 1; i++)
//	{
//		for (int j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}



//int cmp_int(const void* elem1, const void* elem2)
//{
//	return *(int*)elem1 - *(int*)elem2;
//}
//
//
//int main()
//{
//	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}


//int cmp_char(const void* elem1, const void* elem2)
//{
//	return *(char*)elem1 - *(char*)elem2;
//}
//
//
//int main()
//{
//	char arr[] = { 'g', 'f', 'e', 'd', 'c', 'b', 'a' };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_char);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}


//int cmp_double(const void* elem1, const void* elem2)
//{
//	return *(double*)elem1 > *(double*)elem2 ? 1 : -1;
//}
//
//
//int main()
//{
//	double arr[10] = { 5.32, 9.34, 1.27, 0.28, 0.98, 8.98, 5.69, 4.33, 7.01, 9.90 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_double);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%f ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}


//typedef struct Stu
//{
//	char subject[10];
//	int grade;
//}Stu;

//int cmp_s_subject(const void* elem1, const void* elem2)
//{
//	return strcmp(((struct Stu*)elem1)->subject, ((struct Stu*)elem2)->subject);
//}

//int cmp_s_subject(const void* elem1, const void* elem2)
//{
//	return strlen(((Stu*)elem1)->subject)-strlen(((Stu*)elem2)->subject);
//}

//int cmp_s_grade(const void* elem1, const void* elem2)
//{
//	return ((Stu*)elem1)->grade-((Stu*)elem2)->grade;
//}

//int main()
//{
//	Stu s[] = { { "yuwen", 89 }, { "shuxue", 100 }, { "yingyu", 101 }, { "lizong", 236 } };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_s_subject);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%s ", s[i].subject);
//	}
//	qsort(s, sz, sizeof(s[0]), cmp_s_grade);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", s[i].grade);
//	}
//	printf("\n");
//	return 0;
//}



//int cmp_string(const void* elem1, const void* elem2)
//{
//	return strcmp((char*)elem1,(char*)elem2);
//}
//
//
//int main()
//{
//	char arr[6][10] = { "grrfdg","adew","gderfe","abrfggfe","lerf","lmnp" };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_string);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%s ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}


//int cmp_string(const void* elem1, const void* elem2)
//{
//	return strlen((char*)elem1)-strlen((char*)elem2);
//}
//
//
//

//int cmp_string(const void* elem1, const void* elem2)
//{
//	return strlen((char *)elem1) > strlen((char *)elem2) ? 1 : -1;
//}
//int main()
//{
//	char arr[6][10] = { "aaa", "aaaaa", "aaaaaaa", "aaaaaa", "aa", "aaaa" };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_string);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%s ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

//int cmp_string(const void* elem1, const void* elem2)
//{
//	return *(char*)elem1 - *(char*)elem2; 
//}
//int main()
//{
//	char arr[6][10] = { "grape", "face", "dog", "cat", "black", "apple" };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_string);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%s ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}



typedef struct Stu
{
	char name[10];
	int grade;
}Stu;

int cmp_s(const void* elem1, const void* elem2)
{
	if ((strcmp(((Stu*)elem1)->name, ((Stu*)elem2)->name))!=0)
		return strcmp(((Stu*)elem1)->name, ((Stu*)elem2)->name);
	else
		return ((Stu*)elem1)->grade - ((Stu*)elem2)->grade;
}


int main()
{
	Stu s[] = { { "zhaoda", 89 }, { "qianer", 100 }, { "sunsan", 101 }, { "lisi", 121 }, { "sunsan", 95 }, {"zhaoda",78} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_s);
	for (int i = 0; i < sz; i++)
	{
		printf("%s %d\n", s[i].name,s[i].grade);
	}
	printf("\n");
	return 0;
}
