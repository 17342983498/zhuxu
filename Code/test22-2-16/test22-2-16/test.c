#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = a + b;
//	printf("%d\n",c);
//	return 0;
//}

//extern int Add(int, int);
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = Add(a, b);
//	printf("sum = %d\n", sum);
//	return 0;
//}


//int main()
//{
//	int first = 1;
//	int second = 1;
//	int num = 0;
//	int n = 0;
//	scanf("%d", &n);
//	if (n == 1 || n == 2)
//	{
//		printf("%d\n", first);
//	}
//	for (int i = 3; i <= n; i++)
//	{
//		num = first + second;
//		first = second;
//		second = num;
//	}
//	printf("%d\n", num);
//	return 0;
//}

//int FIB(int n)
//{
//	if (n == 0)
//	{
//		return 0;
//	}
//	else if (n == 1 || n == 2)
//		return 1;
//	else
//		return FIB(n - 1) + FIB(n - 2);
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int num = FIB(n);
//	printf("%d\n", num);
//	return 0;
//}




//int main()
//{
	//int a = 10;
	//printf("%p\n", &a);
	//int* p = &a;
	//printf("%d\n", *p);
	//printf("%p\n", p);
	//*p = 20;
	//printf("%d\n", a);

	//double a = 2.201;
	//double* p = &a;
	//*p = 2.533;
	//printf("%.2lf\n", a);
	//printf("%d\n", sizeof(a));
	//printf("%d\n", sizeof(p));


	//printf("%d\n", sizeof(int*));
	//printf("%d\n", sizeof(double*));
	//printf("%d\n", sizeof(char*));
	//printf("%d\n", sizeof(short*));

	//printf("%d\n", sizeof(char));
	//printf("%d\n", sizeof(short));
	//printf("%d\n", sizeof(int));
	//printf("%d\n", sizeof(long));
	//printf("%d\n", sizeof(long long));
	//printf("%d\n", sizeof(float));
	//printf("%d\n", sizeof(double));
	//printf("%d\n", sizeof(long double));


	//for (int i = 1; i <= 100; i++)
	//{
	//	if (i % 2 == 1)
	//	{
	//		printf("%d ", i);
	//	}
	//}
	//printf("\n");
	//return 0;
//}

int main()
{
	int i = 1;
	while (i < 10)
	{
		if (i == 5)
			continue;
		printf("%d ", i);
		i++;
	}
	return 0;
}