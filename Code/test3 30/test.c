#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//void my_strcpy(char *dest, char *src)
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest=*src;// '\0'
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "520";
//	my_strcpy(arr1, arr2);
//	printf("%s\n",arr1 );
//	return 0;
//}
//void my_strcpy(char *dest, char *src)
//{
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "520";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//void my_strcpy(char *dest, char *src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "520";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
//void my_strcpy(char *dest, const char *src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "520";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
char* my_strcpy(char *dest, const char *src)
{
	char* ret = dest;
	assert(dest != NULL);//╤оят
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "520";

	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}