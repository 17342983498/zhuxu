#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n=0;
	int i = 0;
	for (n = 1; n <= 100; n++)
	{
		if (n % 2 == 1)
		{
			printf("%d ", n);
			i++;
			if (i % 10 == 0)
				printf("\n");
		}
	}
	return 0;
}
