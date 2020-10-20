#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	int arr[10] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(arr));
	char* s = "abcd";
	printf("%d\n", sizeof(s));
	printf("%d\n", strlen(s));
	char s1[] = "abcd";
	printf("%d\n", sizeof(s1));
	printf("%d\n", strlen(s1));
	printf("%d\n", strlen(arr));
	return  0;
}
