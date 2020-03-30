#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//strlen实现
//int my_strlen(const char *str)
//{
//	int count = 0;
//	assert(str != NULL );
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	int len=my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//strcpy实现
//char* my_strcpy(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest++ = *src++);
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "520";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
int num(int b)
{
    b = 20;
	int sum = 20;
	while (b>1)
	{
		sum += b / 2;
		b /= 2;
	}
	return sum;
}
int main()
{
	int a = 0;
	int sum = num(a);
	printf("%d\n", sum);
	return 0;
}
