#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//int main()
//{
//	char arr[] = "abcdef";
//	int len = strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}
//int my_strlen(const char* str)
//{
//	int count = 0;
//	assert(str != NULL);
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "zhuxu";
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
char* my_strcpy(char* str1, char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	//while (*str2 != '\0')
	//{
	//	*str1 = *str2;
	//	str1++;
	//	str2++;
	//}
	//*str1 = *str2;//拷贝‘\0’
	char* ret = str1;
	while (*str1++ = *str2++)
	{
		;
	}
	//返回目的空间的起始地址
	return ret;
}
int main()
{
	char arr1[] = "abcdef";//目的空间的元素个数必须大于源字符串中的元素个数
	//char* arr1="abcdef"   ERR   该字符串为常量字符串，无法被改变
	char arr2[] = "zhuxu";
	// char arr2[]={'a','b','c','d'};  ERR  源字符串必须存在‘\0’
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);//zhuxu
	return 0;
}
