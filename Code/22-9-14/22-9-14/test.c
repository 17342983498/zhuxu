#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <assert.h>
//
//char* my_strncpy(char* str1, const char* str2, int num)
//{
//	char* str = str1;
//	while (num && (*str1++ = *str2++))
//	{
//		num--;
//	}
//	if (num)
//	{
//		while (num--)
//		{
//			*str1++ = '\0';
//		}
//	}
//	return str;
//}
//
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "aaaaaaaaaaaaaaaaaaaa";
//	char* ret = my_strncpy(arr2, arr1, 10);
//	printf("%s\n", ret);
//	return 0;
//}


char* my_strncat(char* str1, const char* str2, int num)
{
	char* str = str1;
	while (*str1)
	{
		str1++;
	}

	while (num--)
	{
		if (!(*str1++ = *str2++))
		{
			return str;
		}
	}
	*str1 = '\0';
	return str;
}

int main()
{
	char arr1[20] = "come de v";
	char arr2[] = " abc!";
	char* ret = my_strncat(arr1, arr2, 5);
	printf("%s\n", ret);
	return 0;
}




//int my_strncmp(const char* str1, const char* str2, int num)
//{
//	while (num--)
//	{
//		if (*str1 > *str2)
//		{
//			return 1;
//		}
//		else if (*str1 < *str2)
//		{
//			return -1;
//		}
//		else
//		{
//			str1++;
//			str2++;
//		}
//	}
//	return 0;
//}
//
//
//int main()
//{
//	char arr1[] = "abcde";
//	char arr2[] = "abcdf";
//	int ret = my_strncmp(arr1, arr2,6);
//	if (ret > 0)
//	{
//		printf("第一个字符串大\n");
//	}
//	else if (ret < 0)
//	{
//		printf("第二个字符串大\n");
//	}
//	else
//		printf("两个个字符串一样大\n");
//	return 0;
//
//}

//char* my_strstr(char* str1, char* str2)
//{
//	char* str = str1;
//	char *s1, *s2;
//	if (!(*str2))
//	{
//		return str1;
//	}
//	while (*str)
//	{
//		s1 = str;
//		s2 = str2;
//		while (*s1 && *s2 && !(*s1 - *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (!(*s2))
//		{
//			return str;
//		}
//		str++;
//	}
//	return NULL;
//}


//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "def";
//	char* ret = my_strstr(arr1, arr2);
//	printf("%s\n", ret);
//	return 0;
//}



//union n
//{
//	int a;
//	char arr[4];
//};
//
//int main()
//{
//	union  n u;
//	printf("%d\n", sizeof(u));
//	return 0;
//}