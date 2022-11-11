#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main() 
{
	int a = 0;
	scanf("%d", &a);
	for (int i = 0; i < a ; i++)
	{
		if (i == 0 || i == a - 1)
		{
			for (int j = 0; j < a; j++)
			{
				printf("* ");
			}
			printf("\n");
		}
		else
		{
			printf("* ");
			for (int m = 0; m < a - 2; m++)
			{
				printf("  ");
			}
			printf("*\n");
		}
	}
	return 0;
}