#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = 0;
//	int pos = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	for (int i = 0; i < 32; i++)
//	{
//		if (((ret >> i) & 1) == 1)
//		{
//			pos = i;
//			break;
//		}
//	}
//	int num1 = 0, num2 = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)
//		{
//			num1 ^= arr[i];
//		}
//		else
//			num2 ^= arr[i];
//	}
//	printf("%d %d\n", num1, num2);
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int arr1[1024] = { 0 };
//	for (int i = 0; i < sz; i++)
//	{
//		arr1[arr[i]]++;
//	}
//	for (int i = 0; i < 1024; i++)
//	{
//		if (arr1[arr[i]] == 1)
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//	printf("\n");
//	return 0;
//}

#include <limits.h>
#include <ctype.h>
enum Status
{
	VALID,
	INVALID
};

enum Status status = INVALID;



int my_atoi(const char* str)
{
	if (str == NULL)
	{
		return 0;
	}
	if (*str == '\0')
	{
		return 0;
	}
	while (isspace(*str))
	{
		str++;
	}
	int flag = 0;
	if (*str == '+')
	{
		flag = 1;
		str++;
	}
	else if (*str == '-')
	{
		flag = -1;
		str++;
	}
	long long ret = 0;
	while (isdigit(*str))
	{
		ret = ret * 10 + flag*(*str - '0');
		if (ret<INT_MIN || ret>INT_MAX)
		{
			return 0;
		}
		str++;
	}
	if (*str == '\0')
	{
		status = VALID;
		return (int)ret;
	}
	else
	{
		return (int)ret;
	}
}

int main()
{
	//int ret = my_atoi("-123");
	int ret = my_atoi("  -1234275427527527527522527");
	if (status == VALID)
	{
		printf("合法的转换：%d\n", ret);
	}
	else
		printf("转换不合法！返回值为：%d\n", ret);
	return 0;
}


//#include <stdlib.h>
//
//
//int main()
//{
//	int ret = atoi("2222222222");
//	printf("%d\n", ret);
//	return 0;
//}