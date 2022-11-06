#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int main()
//{
//	int* ptr = NULL;
//	ptr = (int*)malloc(10 * sizeof(int));
//	if (NULL == ptr)
//	{
//		//打印错误原因的一个方式
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(ptr + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(ptr + i));
//		}
//	}
//	free(ptr);
//	ptr = NULL;
//	return 0;
//}



//int main()
//{
//	int *p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d  ", *(p+i));
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//对NULL指针的解引用操作
//int main()
//{
//
//	int *p = (int*)malloc(40);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//对动态开辟的内存进行越界访问
//#include <stdio.h>
//#include <stdlib.h>

//int main()
//{
//	int *p = (int *)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		printf("开辟内存空间失败\n");
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i<20; i++)
//		{
//			p[i] = i;
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//int main()
//{
//	int *p = (int*)malloc(40);
//	p++;
//	free(p);
//	p = NULL;
//}


int main()
{
	int *p = (int *)malloc(100);
	if (NULL != p)
	{
		*p = 1;
	}
	while (1);
	return 0;
}
