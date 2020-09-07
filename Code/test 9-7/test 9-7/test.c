#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int Fib(int n)
{
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		n1 = 1;
		n2 = 1;
		for (int m = 3; m <= n; m++)
		{
			n3 = n2 + n1;
			n1 = n2;
			n2 = n3;
		}
		return n3;
	}
}
int main()
{
	int n = 0;
	int m = 0;
	scanf("%d", &n);
	m = Fib(n);
	printf("%d\n", m);
	return 0;
}