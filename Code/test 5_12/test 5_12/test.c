#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
char* Include(const char* str1, const char* str2)
{
	char* ret = (char*)str1;
	assert(str1);
	assert(str2);
	char* s1;
	char* s2;
	while (ret)
	{
		s1 = ret;
		s2 = (char*)str2;
		while(*s1 == *s2 && *s1!='\0' && *s2!='\0')
		{
			s1++;
			s2++;
		}
		if (*s2=='\0')
		{
			return ret;
		}
		if (*s1=='\0')
		{
			return NULL;
		}
		ret++;
	}
	return NULL;
}
int main()
{
	char arr1[] = "jfabbcdef";
	char arr2[] = "abbcd";
	char* str = Include(arr1, arr2);
	if (str == NULL)
	{
		printf("FALSE\n");
	}
	else
	{
		printf("%s\n", str);
	}
	return 0;
}



//char* my_strstr(const char* str1, const char* str2)
//{
//	char* ret = (char*)str1;
//	assert(str1);
//	assert(str2);
//	char* s1;
//	char* s2;
//	while (ret)
//	{
//		s1 = ret;
//		s2 = (char*)str2;
//		while (*s1 != '\0'&& *s2 != '\0'&& *s1 == *s2)
//		{
//			*s1++;
//			*s2++;
//		}
//		if (*s1 == '\0')
//		{
//			return NULL;
//		}
//		if (*s2 == '\0')
//		{
//			return ret;
//		}
//		ret++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[] = "abbbcdef";
//	char arr2[] = "abbcd";
//	char* arr3 = my_strstr(arr1, arr2);
//	if (arr3 == NULL)
//	{
//		printf("ÕÒ²»µ½×Ó´®¡£\n");
//	}
//	else
//	{
//		printf("%s\n", arr3);
//	}
//
//	return 0;
//}