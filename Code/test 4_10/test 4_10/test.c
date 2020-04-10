#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
struct Stu 
{
	char name[20];
	int age;
};
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return (((struct Stu*)e1)->age - ((struct Stu*)e2)->age);
}

int cmp_int(const void* e1,const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void swap(char* len1, char* len2,int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp;
		tmp= *len1;
		*len1 = *len2;
		*len2 = tmp;
		len1++;
		len2++;
	}
}
void bubble_sort(void* base, int sz, int width, int (cmp)(void* e1, void* e2))
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int j = 0;
		for (j = 0; j < sz - i - 1; j++)
		{
			if (cmp((char*)base + j*width, (char*)base + (j + 1) * width)>0)
			{
				swap((char*)base + j*width, (char*)base + (j + 1) * width,width);
			}
		}
	}

}

void test1()
{
	int i = 0;
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test2()
{
	int i = 0;
	struct Stu s[6] = { { "wuwenshuai", 19 }, { "guoxingxing", 20 }, { "zhxuu", 21 }, { "wangjiangtao", 22 }, { "wensulei", 23 }, { "zhangzichen", 35 } };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	for (i = 0; i < sz; i++)
	{
		printf("%s ", s[i].name);
	}
	printf("\n");
}
void test3()
{
	int i = 0;
	struct Stu s[6] = { { "wuwenshuai", 19 }, { "guoxingxing", 20 }, { "zhxuu", 21 }, { "wangjiangtao", 22 }, { "wensulei", 23 }, { "zhangzichen", 35 } };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", s[i].age);
	}
	printf("\n");
}
int main()
{
	test1();
	test2();
	test3();
	return 0;
}
