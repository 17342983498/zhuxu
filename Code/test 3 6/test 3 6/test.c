#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int n = 0;
	int m = 0;
	int p = 0;
	scanf("%d %d %d", &a, &b, &c);
	if (a < b)
	{
		n = a;
		a = b;
		b = n;
	}
	if (a < c)
	{
		m = a;
		a = c;
		c = m;
	}
	if (b < c)
	{
		p = b;
		b = c;
		c = p;
	}
	printf("%d %d %d", a, b, c);
	return 0;
} 