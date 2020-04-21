#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//int main()
//{
//	const char* arr1 = "abcdef";
//	char* arr2 = "abcghrf";
//	/*int ret = strcmp(arr1, arr2);*/
//	int ret = strncmp(arr1, arr2, 3);//  3--只比较字符的前三个元素
//	printf("%d\n", ret);
//	return 0;
//}

// strstr--查找字符串
//int main()
//{
//	char arr1[] = "abccddef";
//	char arr2[] = "cde";
//	char* ret = strstr(arr1,arr2);
//	if (ret == NULL)
//	{
//		printf("子串不存在。\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}
//char* my_strstr(const char* str1,const char* str2)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	char* s1 = NULL;
//	char* s2 = NULL;
//	char* sen =(char*) str1;
//	/*if (*str2 == '\0')
//	{
//		return str1;
//	}*/
//	while (*sen)
//	{
//		s1 = sen;
//		s2 = (char*)str2;
//		while ((*s1 == *s2) && (*s1 != '\0') && (*s2 != '\0'))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return sen;//找到子串
//		}
//		if (*s1 == '\0')
//		{
//			return NULL;//找不到子串---str1比str2短
//		}
//		sen++;
//	}
//	return NULL;//找不到子串
//}
//int main()
//{
//	/*char arr1[] = "abbbcdef";
//	char arr2[] = "sfsdfgwgfgewg";*/
//	char arr1[] = "abbbcdef";
//	char arr2[] = "bbcd";
//	char* ret = my_strstr(arr1, arr2);
//	if (ret == NULL)
//	{
//		printf("子串不存在。\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}
//int main()
//{
//	//125.124.235.21---分隔符（ .）
//	//zhxu@qq.com----分隔符（@ .）
//	/*char str[] = "zhuxu@qq.com";*/
//	char str[] = "125.124.235.21";
//	char* p = "@.";
//	char arr[100] = { 0 };
//	strcpy(arr, str);
//	char* ret = NULL;
//	for (ret = strtok(str, p); (ret != NULL); ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}
#include<ctype.h>
int main()
{
	char arr[] = "I Am A Student.";
	int i = 0;
	while (arr[i])
	{
		if (toupper(arr[i]))
		{
			arr[i] = tolower(arr[i]);
		}
		i++;
	}
	printf("%s\n", arr);
	return 0;
}