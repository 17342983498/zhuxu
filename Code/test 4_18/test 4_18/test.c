#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//int main()
//{
//	char arr1[20] = "hello,";
//	char arr2[] = "world!";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
//char* my_strcat(char* str1, const char* str2)
//{
//	assert(*str1);
//	assert(*str2);
//	char* ret = str1;
//	while (*str1!='\0')
//	{
//		str1++;
//	}
//	while (*str1++ = *str2++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "hello,";
//	char arr2[] = "world!";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "bcdefg";
//	int len = strcmp(arr1, arr2);
//	if (len < 0)
//		printf("arr2 > arr1");
//	else if (len > 0)
//		printf("arr1 > arr2");
//	else
//		printf("arr1 = arr2");
//	return 0;
//}
//my_strcmp(char* str1, char* str2)
//{
//	while (*str1++ == *str2++)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//	}
//	if (*str1 < *str2)
//		return -1;
//	else
//		return 1;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "bcdefg";
//	int len = my_strcmp(arr1, arr2);
//	if (len < 0)
//		printf("arr2 > arr1");
//	else if (len > 0)
//		printf("arr1 > arr2");
//	else
//		printf("arr1 = arr2");
//	return 0;
//}
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "bit";
//	strncpy(arr1, arr2, 3);//�������������� arr2 �е��ַ��������������油��\0��
//	printf("%s\n", arr1);
//	return 0;
//}
//char* my_strncpy(char* str1, const char* str2, int n)
//{
//	char* ret = str1;
//	while (n && (*str1++ = *str2++))
//	{
//		n--;
//	}
//	if (n)
//	{
//		while (n--)
//		{
//			*str1 = '\0';
//		}
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "bit";
//	my_strncpy(arr1, arr2, 2);
//	printf("%s\n", arr1);
//	return 0;
//}
//int main()
//{
//	/*char arr1[20] = "hello,";
//	char arr2[] = "world!";*/
//	char arr1[20] = "abcdef";
//	char arr2[] = "abcdef";
//	strncat(arr1, arr2, 6); //strcat���ܸ��Լ������������Լ���������Ҫ��strncat
//	printf("%s\n", arr1);
//	return 0;
//}
char* my_strncat(char* str1, char* str2, int n)
{
	char* ret = str1;
	while (*str1++)
	{
		;
	}
	str1--;
	while (n--)
	{
		if (!(*str1 = *str2))
		{
			return (ret);
		}
	}
	*str1 = '\0';
	return (ret);
}
int main()
{
	char arr1[20] = "hello,";
	char arr2[] = "world!";
	/*char arr1[20] = "abcdef";
	char arr2[] = "abcdefg";*/
	my_strncat(arr1, arr2, 6); //strcat���ܸ��Լ������������Լ���������Ҫ��strncat
	printf("%s\n", arr1);
	return 0;
}