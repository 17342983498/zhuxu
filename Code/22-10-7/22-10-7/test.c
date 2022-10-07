#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = n,j = 1; i >= 0,j <= (n+1); i--,j++)
//	{
//		int num = 2 * i;
//		while (num--)
//		{
//			printf(" ");
//		}
//		num = j;
//		while (num--)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (int i = 1, j = n; i <= n,j > 0; i++,j--)
//	{
//		int num = 2 * i;
//		while (num--)
//		{
//			printf(" ");
//		}
//		num = j;
//		while (num--)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		int num = i;
//		while (num--)
//		{
//			printf(" ");
//		}
//		printf("*\n");
//	}
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		if (i < (n + 1) / 2)
//		{
//			int num = i;
//			while (num--)
//			{
//				printf(" ");
//			}
//			printf("*");
//			num = n - (2 * (i + 1));
//			for (int i = num; i > 0; i--)
//			{
//				printf(" ");
//			}
//			if (num >= 0)
//			{
//				printf("*");
//			}
//			printf("\n");
//		}
//		else
//		{
//			int j = i + 1;
//			int num = n - j;
//			while (num--)
//			{
//				printf(" ");
//			}
//			printf("*");
//			num = n - 2 * (n - i);
//			while (num--)
//			{
//				printf(" ");
//			}
//			printf("*\n");
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	printf("*\n");
//	printf("* *\n");
//	for (int i = a - 1; i > 2 ; i--)
//	{
//		printf("* ");
//		int num = a - i;
//		while (num--)
//		{
//			printf("  ");
//		}
//		printf("*\n");
//	}
//	while (a--)
//	{
//		printf("* ");
//	}
//	printf("\n");
//	return 0;
//}



int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j || (i + j + 1) == n)
			{
				printf("*");
			}
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}