#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str++)
//	{
//		count++;
//	}
//	return count;
//}

//int my_strlen(char* str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	else
//		return my_strlen(str+1) + 1;
//}

//int my_strlen(char* str)
//{
//	char* s = str;
//	while (*s)
//	{
//		s++;
//	}
//	return s - str;
//}
//
//int main()
//{
//	char str[] = "abcdefg";
//	int ret = my_strlen(str);
//	printf("%d\n", ret);
//	return 0;
//}



//char* my_strcpy(char* dest, char* src)
//{
//	char* str = dest;
//	while (*src)
//	{
//		*dest++ = *src++;
//	}
//	return str;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[10] = { 0 };
//	char* str = my_strcpy(arr2, arr1);
//	printf("%s\n", str);
//	return 0;
//}


char* my_strcat(char* dest, char* src)
{
	char* str = dest;
	while (*dest)
	{
		dest++;
	}
	while ((*dest++ = *src++))
	{
	}
	return str;
}

int main()
{
	char arr1[10] = "abc";
	char arr2[10] = "def";
	char* str = my_strcat(arr1, arr2);
	printf("%s\n", str);
	return 0;
}



//int my_strcmp(const char* arr1, const char* arr2)
//{
//	int ret = 0;
//	while (!(ret = *arr1 - *arr2) && *arr2)
//	{
//		arr1++;
//		arr2++;
//	}
//	if (ret > 0){
//		ret = 1;
//	}
//	else if (ret < 0)
//	{
//		ret =  -1;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	int ret = my_strcmp(arr1, arr2);
//	if (ret > 0)
//	{
//		printf("第一个字符串大\n");
//	}
//	else if (ret == 0)
//	{
//		printf("两个字符串一样大\n");
//	}
//	else
//		printf("第二个字符串大\n");
//	return 0;
//}



#include <string.h>
//int main()
//{
//	char arr[10] = "abcd";
//	char* ret = strncat(arr, arr,4);
//	printf("%s\n", ret);
//	return 0;
//}


//char* my_strncpy(char* dest, char* src, int k)
//{
//	char* ret = dest;
//	while (k && (*dest++ = *src++))
//	{
//		k--;
//	}
//	while (k--)
//	{
//		*dest++ = '\0';
//	}
//	return ret;
//}

//char * my_strncpy(
//	char * dest,
//	const char * source,
//	size_t count
//	)
//{
//	char *start = dest;
//
//	while (count && (*dest++ = *source++))    /* copy string */
//		count--;
//
//	if (count)                              /* pad out with zeroes */
//	while (--count)
//		*dest++ = '\0';
//
//	return(start);
//}
//
//int main()
//{
//	char arr1[10] = {0};
//	char arr2[] = "woaini";
//	char* ret = my_strncpy(arr1, arr2,5);
//	printf("%s\n", ret);
//	return 0;
//}

//char* my_strncat(char* dest, char* src, int k)
//{
//	char* ret = dest;
//	//while (*dest++)
//	//{
//	//}
//	//dest--;
//	while (*dest)
//	{
//		dest++;
//	}
//	while (k--)
//	{
//		if (!(*dest++ = *src++))
//			return ret;
//	}
//	*dest = '\0';
//	return ret;
//}
//
//int main()
//{
//	char arr1[10] = "abc";
//	char arr2[] = "def";
//	char* ret = my_strncat(arr1, arr2, 5);
//	printf("%s\n", ret);
//	return 0;
//}



//int main()
//{
//	const char*str1 = "abcdef";
//	const char*str2 = "bbb";
//	if (strlen(str2) - strlen(str1)>0)
//	{
//		printf("str2>str1\n");
//	}
//	else
//	{
//		printf("srt1>str2\n");
//	}
//	return 0;
//}

//int main()
//{
//	char arr[] = "abcdefg";
//	int num = strlen(arr);
//	printf("%d\n", num);
//	return 0;
//}


//int main()
//{
//	char arr1[5] = "abc";
//	char arr2[] = "defghijklmn";
//	char* ret = strcpy(arr1, arr2);
//	printf("%s\n", ret);
//	return 0;
//}


//int main()
//{
//	char arr[] = "abcd";
//	char* str = strcat(arr, arr);
//	printf("%s\n", str);
//	return 0;
//}


//
//char* my_strncat(char* dest, char* src, int k)
//{
//	char* ret = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//	while (k--)
//	{
//		if (!(*dest++ = *src++))
//			return ret;
//	}
//	*dest = '\0';
//	return ret;
//}
//
//int main()
//{
//	char arr1[10] = "abc";
//	char* ret = my_strncat(arr1, arr1, 3);
//	printf("%s\n", ret);
//	return 0;
//}