#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//int my_strlen(char* arr)
//{
//	int num = 0;
//	while (*arr++)
//	{
//		num++;
//	}
//	return num;
//}
//
//int main()
//{
//	char arr[10] = "abcdefg";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}
#include <assert.h>
//void my_strcpy(char* dest, const char* src)
//{
//	assert(src);
//	while (*dest++ = *src++)
//	{
//		//dest++;
//		//src++;
//	}
//}
//
//int main()
//{
//	char arr1[20] = {0};
//	char arr2[] = "hello world!";
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}

//int my_strcmp(const char* arr1, const char* arr2)
//{
//	assert(arr1);
//	assert(arr2);
//	while (!(*arr1 - *arr2) && *arr1)
//	{
//		arr1++;
//		arr2++;
//	}
//	if (*arr1 > *arr2)
//	{
//		return 1;
//	}
//	else if (*arr1 < *arr2)
//	{
//		return -1;
//	}
//	return 0;
//
//}
//
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "abcdefh";
//	int ret = my_strcmp(arr1, arr2);
//	if (ret > 0)
//	{
//		printf("字符串arr1大\n");
//	}
//	else if (ret < 0)
//	{
//		printf("字符串arr2大\n");
//	}
//	else
//		printf("两字符串一样大\n");
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
//	while (*src)
//	{
//		*dest = *src;
//		dest++;
//		src++;
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


char* my_strstr(char* str1, char* str2)
{
	char* str = str1;
	char *s1, *s2;
	if (!(*str2))
	{
		return str1;
	}
	while (*str1)
	{
		s1 = str1;
		s2 = str2;
		while (!(*s1 - *s2) && *s1 && *s2)
		{
			s1++;
			s2++;
		}
		if (!(*s2))
		{
			return str1;
		}
		str1++;
	}
	return NULL;
}

int main()
{
	char arr1[] = "abcdefg";
	char arr2[] = "def";
	char* ret = my_strstr(arr1, arr2);
	printf("%s\n", ret);
	return 0;
}