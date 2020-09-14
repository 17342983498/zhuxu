#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	//char *arr = "abcdef";
	//arr++;
	//printf("%c\n", *arr);
	int arr[5] = {8,1,2,3,4};
	(*arr)++;
	printf("%d\n", *arr);
	return 0;
}