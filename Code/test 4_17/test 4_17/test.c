#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Stu
{
	char name[20];
	int num;
};
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
int cmp_float(const void* e1, const void* e2)
{
	return (int)(*(float*)e1 - *(float*)e2);
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
int cmp_stu_by_num(const void* e1, const void* e2)
{
	return (struct Stu*)e1 - (struct Stu*)e2;
}
void test1()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test2()
{
	float arr[] = { 9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0, 0.0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_float);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", arr[i]);
	}
	printf("\n");
}
void test3()
{
	struct Stu p[6] = { { "wuwenshuai", 19 }, { "guoxingxing", 20 }, { "zhuxu", 21 }, { "wangjiangtao", 22 }, { "wensulei", 23 }, { "zhangzichen", 35 } };
	int sz = sizeof(p) / sizeof(p[0]);
	qsort(p, sz, sizeof(p[0]), cmp_stu_by_name);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s ", p[i].name);
	}
	printf("\n");
}
void test4()
{
	struct Stu p[6] = { { "wuwenshuai", 19 }, { "guoxingxing", 20 }, { "zhuxu", 21 }, { "wangjiangtao", 22 }, { "wensulei", 23 }, { "zhangzichen", 35 } };
	int sz = sizeof(p) / sizeof(p[0]);
	qsort(p, sz, sizeof(p[0]), cmp_stu_by_num);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", p[i].num);
	}
	printf("\n");
}
int main()
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}
