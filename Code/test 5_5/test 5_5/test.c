#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
//int  main()
//{
//	int* p = (int*) malloc(40);//申请40个整形字节
//	if (p == NULL)//申请失败
//	{
//		printf("%s\n", strerror(errno));
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
int main()
{
	int* p = (int*)malloc(20);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		*(p + i) = i;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", *(p + i));
	}
	int* ptr = (int*)realloc(p, 40);//之前已经申请20个字节，现在再往后面申请20个字节，总共40个字节
	//如果之前p的后面没有20个字节，则需另开辟一个40个字节的空间
	//realloc自己就已经将之前的初始化掉了
	if (ptr != NULL)
	{
		p = ptr;
	}
	int j = 0;
	for (j = 5; j < 10; j++)
	{
		*(p + j) = j;
	}
	for (j = 5; j < 10; j++)
	{
		printf("%d ", *(p + j));
	}
	free(p);
	p = NULL;
	return 0;
}