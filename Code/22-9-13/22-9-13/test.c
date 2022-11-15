#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//struct stu
//{
//	char name[20];
//	int id[10];
//	int tele[11];
//};
//
//int main()
//{
//	struct stu s = { "zhuxu", "03187021", "13891487029" };
//	return 0;
//}



//struct s
//{
//	char a;
//	double c;
//	int b;
//};
//
//int main()
//{
//	struct s s1 = { 'a', 10, 'c' };
//	printf("%d\n", sizeof(struct s));
//	return 0;
//}



//int my_strlen(char* arr)
//{
//	char* str = arr;
//	while (*arr)
//	{
//		arr++;
//	}
//	return arr - str;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}


#include <assert.h>

//char* my_strcpy(char* dest, const char* src)
//{
//	assert(src);
//	char* str = dest;
//	while (*dest = *src)
//	{
//		src++;
//		dest++;
//	}
//	return str;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[10] = { 0 };
//	char* str = my_strcpy(arr2,arr1);
//	printf("%s\n", str);
//	return 0;
//}

//char* my_strcat(char* dest, const char* src)
//{
//	assert(src);
//	char* str = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//	while (*dest = *src)
//	{
//		src++;
//		dest++;
//	}
//	return str;
//}
//
//int main()
//{
//	char arr1[15] = "hello";
//	char arr2[] = " world";
//	char* str = my_strcat(arr1,arr2);
//	printf("%s\n", str);
//	return 0;
//}

//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1);
//	assert(str2);
//	while (!(*str1 - *str2) && *str1)
//	{
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//	{
//		return 1;
//	}
//	else if (*str1 < *str2)
//	{
//		return -1;
//	}
//	return 0;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	int ret = my_strcmp(arr1, arr2);
//	if (ret > 0)
//	{
//		printf("arr1字符串长\n");
//	}
//	else if (ret < 0)
//	{
//		printf("arr2字符串长\n");
//	}
//	else
//		printf("两个字符串一样长\n");
//	return 0;
//
//}