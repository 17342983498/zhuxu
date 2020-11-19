#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



void Insertsort(int arr[], int k)
{
	for (int i = 1; i < k; i++)
	{
		int key = arr[i];
		int end = i - 1;
		while ( end >= 0 && key < arr[end])
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = key;
	}
}

void Print(int arr[],int k)
{
	for (int i = 0; i < k; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 2, 4, 8, 1, 0, 3, 6, 9, 7, 5 };
	Insertsort(arr, sizeof(arr) / sizeof(arr[0]));
	Print(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}