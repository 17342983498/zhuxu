#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//void left_move(char* arr, int k)
//{
//	assert(arr);
//	int i = 0;
//	int len = strlen(arr);
//	for (i = 0; i <k ; i++)
//	{
//		char tmp = *arr;//将首元素先提出去，防止被覆盖
//		int j = 0;
//		for (j = 0; j <len-1 ; j++)
//		{
//			*(arr + j) = *(arr + j + 1);//分别将后面的元素向前挪动一位
//		}
//		*(arr + len-1) = tmp;//将原来的首元素放在最后面
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
	//假设K=2，则将abcdef分成 ab  cdef
	//先将ab逆序，再将cdef逆序，最后再将全部逆序
	//ba  fedc----cdefab
	reserve((arr),(arr+k-1));
	reserve((arr+k),(arr+len-1));
	reserve((arr),(arr+len-1));
}
int main()
{
	char arr[] = "abcdef";
	int k = 0;
	printf("请输入一个小于7的正整数！\n");
	scanf("%d", &k);
	left_move(arr, k);
	printf("%s\n", arr);
	return 0;
}
