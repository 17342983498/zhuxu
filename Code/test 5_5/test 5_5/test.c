#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
//int  main()
//{
//	int* p = (int*) malloc(40);//����40�������ֽ�
//	if (p == NULL)//����ʧ��
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
	int* ptr = (int*)realloc(p, 40);//֮ǰ�Ѿ�����20���ֽڣ�����������������20���ֽڣ��ܹ�40���ֽ�
	//���֮ǰp�ĺ���û��20���ֽڣ���������һ��40���ֽڵĿռ�
	//realloc�Լ����Ѿ���֮ǰ�ĳ�ʼ������
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