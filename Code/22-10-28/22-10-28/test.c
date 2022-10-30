#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int mySqrt(int x)
{
	if (x == 0)
	{
		return 0;
	}
	int n = 1;
	int m = 2;
	int num1 = 1;
	int num2 = 4;
	while (num1 <= x && num2 <= x)
	{
		++n;
		++m;
		num1 = n*n;
		num2 = m*m;
	}
	return n;
}

int main()
{
	int x = 0;
	scanf("%d", &x);
	int ret = mySqrt(x);
	printf("%d", ret);
	return 0;
}