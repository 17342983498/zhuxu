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
//		//��ӡ����ԭ���һ����ʽ
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


//��NULLָ��Ľ����ò���
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


//�Զ�̬���ٵ��ڴ����Խ�����
//#include <stdio.h>
//#include <stdlib.h>

//int main()
//{
//	int *p = (int *)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		printf("�����ڴ�ռ�ʧ��\n");
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
