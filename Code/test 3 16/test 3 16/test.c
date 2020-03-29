#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int is_leap_year(int n)
//{
//	if (((n % 4) == 0 &&( n % 100)!= 0)|| ((n % 400) == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if (is_leap_year(year) == 1)
//	{
//	    printf("%d 是闰年\n ", year);
//	}
//	else
//	{
//		printf("%d 不是闰年\n", year);
//	}
//	return 0;
//}
//
//void mul(int n)
//{
//	int i = 0;
//	int j = 0;
//	int m = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			m = i*j;
//			printf("%d*%d=%-2d ", i, j, m);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	mul(n);
//	return 0;
//}
//void swap(int* pa, int* pb)
//{
//	int ret = 0;
//	ret = *pa;
//	*pa = *pb;
//	*pb = ret;
//}
//
//int main()
//{
//	int n = 10;
//	int m = 20;
//	swap(&n, &m);
//	printf("n = %d,m = %d\n", n, m);
//	return 0;
//}
//void print(int n)
//{
//	if (n > 9)
//	{
//		print(n/10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	unsigned int n = 0;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//
//}
//int Fac(int n)
//{
//	if (n <=1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n*Fac(n - 1);
//	}
//}
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d", &n);
//	m = Fac(n);
//	printf("%d\n", m);
//	return 0;
//
//}