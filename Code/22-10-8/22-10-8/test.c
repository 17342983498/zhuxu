#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = n; i > 0; i--)
//	{
//		int num = n - i;
//		while (num--)
//		{
//			printf(" ");
//		}
//		for (int j = i; j > 0; j--)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//	return 0;
//}


int main()
{
	int arr1[5] = { 1, 2,3,4,5 };
	int arr2[5] = { 6,7,8,9,10 };
	int arr[10] = { 0 };
	int i = 0;
	int j = 0; 
	int x = 0;
	while (i < 5 && j < 5)
	{
		if (arr1[i] <= arr2[j])
		{
			arr[x++] = arr1[i++];
		}
		else
		{
			arr[x++] = arr2[j++];
		}
	}
	while (j < 5)
	{
		arr[x++] = arr2[j++];
	}
	while (i < 5)
	{
		arr[x++] = arr1[i++];
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}