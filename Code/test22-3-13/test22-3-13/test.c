#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//		{
//			count++;
//		}
//		n /= 2;
//	}
//	printf("%d\n",count);
//	return 0;
//}



//int main()
//{
//	int n = -1;
//	int count = 0;
//	while (n)
//	{
//		count++;
//		n = n&(n - 1);
//	}
//	printf("%d\n",count);
//	return 0;
//}



//int main()
//{
//	int n = 1;
//	char* p = (char*)&n;
//	if (*p == 1)
//	{
//		printf("小端\n");
//	}
//	else
//		printf("大端\n");
//	return 0;
//}

//int check_sys()
//{
//	int a = 1;
//	//char* p = (char*) &a;
//	//return *p;
//	return (*(char*)&a);
//
//}
//
//int main()
//{
//	int n = check_sys();
//	if (n == 1)
//	{
//		printf("小端\n");
//	}
//	else
//		printf("大端\n");
//	return 0;
//}





void Print_Factorial(const int N);
double fac(int x);

int main()
{
	int N;

	scanf("%d", &N);
	Print_Factorial(N);
	return 0;
}


void Print_Factorial(const int N)
{
	int x = N;
	if (x<0)
	{
		printf("Invalid input");
	}
	else
	{
		double ret = fac(x);
		printf("%lf\n", ret);
	}
}

double fac(int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	return n*fac(n - 1);
}

