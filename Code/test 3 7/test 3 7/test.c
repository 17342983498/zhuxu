#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int left = 0;
	int right = 9;
	int m ;
	scanf("%d", &m);
	while (left<=right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] > m)
		{
			right = mid - 1;
		}
		else if (arr[mid] < m)
		{
			left = mid + 1;
		}
		else
		{
			printf("其下标为%d\n", mid);
			break;
		}
	}
	if (left>right)
	{
		printf("找不到\n");
	}
	return 0;
}