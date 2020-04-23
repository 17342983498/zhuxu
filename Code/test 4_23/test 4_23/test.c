#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
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
//#include<string.h>
//int main()
//{
//	char arr1[] = "zhuxu@qq.com";
//	char* p = "@.";
//	char arr2[100] = { 0 };
//	char* ret = NULL;
//	strcpy(arr2, arr1);
//	for (ret = strtok(arr2, p); (ret != NULL); ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}
#include<ctype.h>
int main()
{
	/*char arr1[20] = "I Am A Student.";*/
	char arr1[20] = "ABCDEFG HIJKLMN";
	int i = 0;
	while (arr1[i])
	{
		char a = arr1[i];
		if (isupper(a))
		{
			a=tolower(a);
		}
		printf("%c", a);
		i++;
	}
	printf("\n");
	return 0;
}