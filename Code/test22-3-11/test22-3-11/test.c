#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//int main()
//{
//	int arr[] = { 5, 4, 9, 3, 1, 8, 7, 2, 6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 1; i < sz; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			if (arr[j]>arr[i])
//			{
//				int num = arr[j];
//				arr[j] = arr[i];
//				arr[i] = num;
//			}
//		}
//	}
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	int a = 5;
//	printf("%d\n", arr[a/2]);
//	return 0; 
//}


//²åÈëÅÅÐò
//int main()
//{
//	int arr[] = { 5, 4, 9, 3, 1, 8, 7, 2, 6, 0};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 1; i < sz; i++)
//	{
//		int key = arr[i];
//		int end = i - 1;
//		while (end >= 0 && arr[end] > key)
//		{
//			arr[end + 1] = arr[end];
//			end--;
//		}
//		arr[end + 1] = key;
//	}
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//Ï£¶ûÅÅÐò
int main()
{
	int arr[] = { 5, 4, 9, 3, 1, 8, 7, 2, 6, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int gap = sz;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < sz; i++)
		{
			int key = arr[i];
			int end = i - gap;
			while (end >= 0 && key < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = key;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}