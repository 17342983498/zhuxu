#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stu
{
	char name[20];
	int age;
};
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
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
int cmp_float(const void* e1, const void* e2)
{
	//return (int)(*(float*)e1 - *(float*)e2);
	if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 < *(float*)e2)
		return -1;
	else
		return 1;
}
void test2()
{
	float d[] = { 9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0, 0.0 };
	int sz = sizeof(d) / sizeof(d[0]);
	qsort(d, sz, sizeof(d[0]), cmp_float);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", d[i]);
	}
	printf("\n");
}
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
void test3()
{
	struct Stu p[6] = { { "zhuxu", 21 }, { "wensulei", 23 }, { "zhanzgzichen", 35 }, { "wuwenshuai", 19 }, { "guoxingxing", 20 }, { "wangjiangtao", 22 } };
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
	struct Stu p[6] = { { "zhuxu", 21 }, { "wensulei", 23 }, { "zhanzgzichen", 35 }, { "wuwenshuai", 19 }, { "guoxingxing", 20 }, { "wangjiangtao", 22 } };
	int sz = sizeof(p) / sizeof(p[0]);
	qsort(p, sz, sizeof(p[0]), cmp_stu_by_age);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", p[i].age);
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
