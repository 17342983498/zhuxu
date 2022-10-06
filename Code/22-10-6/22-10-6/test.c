#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int Fib(int n)
//{
//	if (n == 1 || n == 2)
//	{
//		return 1;
//	}
//	int first = 1;
//	int second = 1;
//	int temp = 0;
//	for (int i = 0; i < n - 2; i++)
//	{
//		temp = first + second;
//		first = second;
//		second = temp;
//	}
//	return temp;
//}


//int Fib(int n)
//{
//	if (n == 1 || n == 2)
//	{
//		return 1;
//	}
//	return Fib(n - 1) + Fib(n - 2);
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d\n", ret);
//	return 0;
//}



//int main() {
//	int a;
//	while (scanf("%d", &a) != EOF) { // 注意 while 处理多个 case
//		// 64 位输出请用 printf("%lld")
//		for (int i = 1; i <= a; i++)
//		{
//			for (int j = 1; j <= i; j++)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}



//int main() {
//	int a;
//	while (scanf("%d", &a) != EOF) { // 注意 while 处理多个 case
//		// 64 位输出请用 printf("%lld")
//		for (int i = a; i>0; i--)
//		{
//			for (int j = 1; j <= i; j++)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = n, j = 1; i > 0; i--,j++)
//	{
//		int x = i;
//		int y = j;
//		while (--x)
//		{
//			printf(" ");
//		}
//		while (y--)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//}




//int main() {
//	int a;
//	while (scanf("%d", &a) != EOF) { // 注意 while 处理多个 case
//		// 64 位输出请用 printf("%lld")
//		for (int i = a, j = 1; i > 0; i--, j++) {
//			int x = i;
//			int y = j;
//			while (--x) {
//				printf(" ");
//			}
//			while (y--) {
//				printf("* ");
//			}
//			printf("\n");
//		}
//	}
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = n; i > 0; i--)
//	{
//		int num = n - i;
//		while (num--)
//		{
//			printf(" ");
//		}
//		for (int j = 0; j < i; j++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = n+1; i > 0; i--)
//	{
//		for (int j = i; j > 1; j--)
//		{
//			printf(" ");
//		}
//		int num = i;
//		while ( num++ <= n + 1)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//	for (int i = 0; i < n ; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		int num = n - i;
//		while (num--)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//	return 0;
//}


int main()
{
	int a = 0;
	scanf("%d", &a);
	for (int i = a+1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	for (int i = 2; i <= a + 1; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}