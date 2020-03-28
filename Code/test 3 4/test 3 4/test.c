#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int Add(int a, int b)
{
	int z = a + b;
	return z;
}
int main()
{
	int n = 10;
	int m = 20;
	int sum = Add(n, m);
	printf("%d", sum);
	return 0;

}
