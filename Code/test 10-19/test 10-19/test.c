#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	int n = 3;
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 4; j++)
		{
			printf("  ");
		}
		for (int m = 0; m < n; m++)
		{
			printf("* ");
		}
		printf("\n");
		n += 2;
	}
	return 0;
}