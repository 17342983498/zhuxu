#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
int* combin(int str1[], int str2[],int m,int n)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int* arr =(int*)malloc((sizeof(str1[0]))*(m+n));
	if (arr == NULL)
		return 0;
	while (i<m && j<n)
	{
		if (str1[i] <= str2[j])
		{
			arr[k++] = str1[i++];
		}
		else
		{
			arr[k++] = str2[j++];
		}
	}
	while (i<m)
	{
		arr[k++] = str1[i++];
	}
	while (j<n)
	{
		arr[k++] = str2[j++];
	}
	return arr;
}
int main()
{
	int arr1[] = { 1, 5, 6, 8 };
	int arr2[] = { 2, 3, 5, 6, 8, 9 };
	int m = sizeof(arr1)/sizeof(arr1[0]);
	int n = sizeof(arr2)/sizeof(arr2[0]);
	int i = 0;
	int x = m + n;
	int* arr = combin(arr1, arr2, m,n);
	for ( i = 0; i < x; i++)
	{
		printf("%d ", arr[i]);
	}
	free(arr);
	arr = NULL;
	return 0;
}
