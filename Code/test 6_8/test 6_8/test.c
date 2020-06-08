#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int Fib(x)
{
	int first = 1;
	int second = 1;
	int num = 0;
	for (int i = 2; i < x; i++)
	{
		num = first + second;
		first = second;
		second = num;
	}
	return num;
}
int main()
{
	int x = 0;
	scanf("%d", &x);
	int num = Fib(x);
	printf("%d\n", num);
	return 0;
}