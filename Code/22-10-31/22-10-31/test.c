#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

//int removeDuplicates(int* arr, int arrSize)
//{
//	int index1 = 0;
//	int index2 = 1;
//	while (index2<arrSize)
//	{
//		if (arr[index2] != arr[index1])
//		{
//			arr[++index1] = arr[index2];
//		}
//		index2++;
//	}
//	return index1+1;
//}
//
//
//int main()
//{
//	int arr[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
//	int arrSize = sizeof(arr) / sizeof(arr[0]);
//	int num = removeDuplicates(arr, arrSize);
//	for (int i = 0; i < num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}


int merge(int* arr1, int arr1Size, int m, int* arr2, int arr2Size, int n)
{
	int index1 = 0, index2 = 0;
	int num1 = 0,num2 = 0,num = m;
	while (num1 < m && num2 < n)
	{
		if (arr1[index1] < arr2[index2])
		{
			index1++;
			num--;
			num1++;

		}
		else
		{
			for (int i = index1 + num - 1; i >= index1; i--)
			{
				arr1[i + 1] = arr1[i];
			}
			arr1[index1] = arr2[index2];
			index1++;
			index2++;
			num2++;
		}
	}
	if (num2 < n)
	{
		for (int i = index1, j = index2; i < m + n; i++,j++)
		{
			arr1[i] = arr2[j];
			num2++;
		}
	}
	else
	{
		num1++;
	}
	return num1 + num2;
}


int main()
{
	int arr1[] = { 2, 4, 6, 0, 0, 0 };
	int arr2[] = { 1, 3, 5 };
	int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
	int arr2Size = sizeof(arr2) / sizeof(arr2[0]);
	int ret = merge(arr1, arr1Size, 3, arr2, arr2Size, 3);
	for (int i = 0; i < ret; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	return 0;
}