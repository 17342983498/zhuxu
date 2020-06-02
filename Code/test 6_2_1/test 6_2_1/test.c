#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void print(int* arr,int k)
{
	int *str = arr;
	int i = 0;
	for (i = 0; i < k; i++)
	{
		printf("%d ", *str++); 
	}
	printf("\n");
}
int main()
{
	int i = 0;
	int arr[10] = {0};
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	print(arr,10);
	return 0;
}