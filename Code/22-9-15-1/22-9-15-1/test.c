#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int main()
{
	int  n = 0;
	int num = 0;
	scanf("%d", &n);
	int arr[9] = { 0 };
	for (int i = 8; i >= 0; i--)
	{
		num = n % 10;
		n /= 10;
		if (num % 2 == 0)
		{
			arr[i] = 0;
		}
		else
		{
			arr[i] = 1;
		}
	}
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		sum = arr[i] + sum * 10;
	}
	printf("%d\n", sum);
	return 0;
}



//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d", &n);
//	int sum = 0;
//	int i = 0;
//	while (n)
//	{
//		int num = n % 10;
//		if (num % 2 == 0)
//		{
//			m = 0;
//		}
//		else
//			m = 1;
//		sum += m * pow(10, i++);
//		n /= 10;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//
//#include <stdlib.h>
//
//int cmp(const int* num1, const int* num2)
//{
//	return *num1 - *num2;
//}
//
//int main()
//{
//	int n = 0;
//	int arr[50] = { 0 };
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, n, sizeof(int), cmp);
//	for (int i = n-1; i > n - 6 ; i--)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		int j = i;
//		int num = 1;
//		while (j--)
//		{
//			printf("%d ", num);
//			num++;
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int n = 0; 
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n - i - 1; j++)
//		{
//			printf(" ");
//		}
//		printf("*\n");
//	}
//	return 0;
//}

