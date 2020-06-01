#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int main()
{
	int i = 1;
	double sum = 0;
	while (i <= 100)
	{
		if (i % 2 == 0)
		{
			sum -= 1.0 / i;
		}
		else
		{
			sum += 1.0 / i;
		}
		i++;
	}
	printf("%lf\n", sum);
	return 0;
}

