#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//int main()
//{
//	int i = 0;
//	int n = 0;
//	scanf("%d", &n);
//	int arr[6] = { 0 };
//	int flag = 0;
//	for (int i = 0; i < 6; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for ( i = 0; i < 5; i++)
//	{
//		for (int j = i + 1; j < 6; j++)
//		{
//			if (arr[i] + arr[j] == n)
//			{
//				printf("%d %d\n", arr[i], arr[j]);
//				flag = 1;
//			}
//		}
//	}
//	if (flag == 0)
//	{
//		printf("没有\n");
//	}
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[6] = { 0 };
//	int flag = 0;
//	for (int i = 0; i < 6; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (arr[i] == n - arr[j])
//			{
//				printf("%d %d\n", arr[i], arr[j]);
//				flag = 1;
//			}
//		}
//	}
//	if (flag == 0)
//	{
//		printf("没有\n");
//	}
//	return 0;
//}



//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[6] = { 0 };
//	int flag = 0;
//	for (int i = 0; i < 6; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (arr[i] == n - arr[j])
//			{
//				printf("%d %d\n", arr[i], arr[j]);
//				flag = 1;
//			}
//		}
//	}
//	if (flag == 0)
//	{
//		printf("没有\n");
//	}
//	return 0;
//}

//void search(int arr[], int left, int right, int n)
//{
//	int flag = 0;
//	while (left <= right)
//	{
//		int middle = (left + right) / 2;
//		if (arr[middle] == n)
//		{
//			printf("找到了\n");
//			flag = 1;
//			break;
//		}
//		else if (arr[middle] > n)
//		{
//			right = middle - 1;
//		}
//		else
//			left = middle + 1;
//	}
//	if (flag == 0)
//	{
//		printf("没找到\n");
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int n = 0;
//	scanf("%d", &n);
//	search(arr, 0, 9, n);
//	return 0;
//}
#include <string.h>

int main()
{
	char arr1[20] = { '\0' };
	char arr2[20] = { '\0' };
	strcpy(arr1, "heelo");
	gets(arr2);
	strcat(arr1,arr2);
	puts(arr1);
	return 0;
}