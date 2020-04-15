#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
//void left_move(char* arr, int k)
//{
//	assert(arr);
//	int i = 0;
//	int len = strlen(arr);
//	for (i = 0; i <k ; i++)
//	{
//		char tmp = *arr;//����Ԫ�������ȥ����ֹ������
//		int j = 0;
//		for (j = 0; j <len-1 ; j++)
//		{
//			*(arr + j) = *(arr + j + 1);//�ֱ𽫺����Ԫ����ǰŲ��һλ
//		}
//		*(arr + len-1) = tmp;//��ԭ������Ԫ�ط��������
//	}
//}
void reserve(char* left, char* right)
{
	assert(left);//assert(left!=NULL)
	assert(right);
	while (left<right)
	{
		char tmp = *right;
		*right = *left;
		*left = tmp;
		right--;
		left++;
	}
}
void left_move(char* arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	assert(k < len);
	//����K=2����abcdef�ֳ� ab  cdef
	//�Ƚ�ab�����ٽ�cdef��������ٽ�ȫ������
	//ba  fedc----cdefab
	reserve((arr),(arr+k-1));
	reserve((arr+k),(arr+len-1));
	reserve((arr),(arr+len-1));
}
int main()
{
	char arr[] = "abcdef";
	int k = 0;
	printf("������һ��С��7����������\n");
	scanf("%d", &k);
	left_move(arr, k);
	printf("%s\n", arr);
	return 0;
}
