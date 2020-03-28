#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int cal_diff(int m, int n)
{
	int count = 0;
	int i = 0;
	for (i = 0; i<32; i++)
	{
		if (((m >> i) & 1) != ((n >> i) & 1))
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int x = 2299;
	int y = 1999;
	int count = 0;
	int ret = 0;
	count = cal_diff(x, y);
	printf("%d\n", count);
}
//int sum(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//
//	return count;
//}
//int main()
//{
//	int m = 0;
//	scanf("%d", &m);
//	int num = sum(m);
//	printf("%d\n", num);
//	return 0;
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d%d", &m, &n);
//	m = m^n;
//	n = m^n;
//	m = m^n;
//	printf("m = %d n = %d", m, n);
//	return 0;
//}
//int num(int arr[], int count)
//{
//	int n = 0;
//	if (n < count)
//	{
//		printf("%d ", arr[n++]);
//	}
//}
//int main()
//{
//	int m = 0;
//	int count = 0;
//	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	count = sizeof(arr) / sizeof(arr[0]);
//	int num(arr, count);
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* p = arr;  
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", *p);   
//		p++;              
//	}
//
//	return 0;
//}


//void Print(int num)
//{
//	printf("奇数位");
//	for (int i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	printf("偶数位");
//	for (int i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	Print(n);
//	return 0;
