#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main()
//{
//	int arr[4][4];
//	int i = 0;
//	int j = 0;
//	int sum1 = 0;
//	int sum2 = 0;
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	for (i = 0; i < 4; i++)
//	{
//		int sum = 0;
//		for (j = 0; j < 4; j++)
//		{
//			sum += arr[i][j];
//		}
//		int n = i + 1;
//		printf("第%d行和为：%d\n", n, sum);
//	}
//	for (j = 0; j < 4; j++)
//	{
//		int sum = 0;
//		for (i = 0; i < 4; i++)
//		{
//			sum += arr[i][j];
//		}
//		int n = j + 1;
//		printf("第%d列和为：%d\n", n, sum);
//	}
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			if (i == j)
//			{
//				sum1 += arr[i][j];
//			}
//			if (i + j == 3)
//			{
//				sum2 += arr[i][j];
//			}
//		}
//	}
//	printf("主对角线和为%d\n", sum1);
//	printf("主对角线和为%d\n", sum2);
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	char acX[] = "abcdefg"; 
//	char acY[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' ,'h'};
//	printf("%d\n", sizeof(acX));
//	printf("%d\n", sizeof(acY));
//	printf("%d\n", strlen(acX));
//	printf("%d\n", strlen(acY));
//	return 0;
//}

//int main() 
//{ 
//	int s = 0, n; 
//	for (n = 0; n<4; n++) 
//	{ 
//		switch (n) 
//		{ 
//		default:s += 4; 
//		case 1:s += 1; 
//		case 2:s += 2; 
//		case 3:s += 3; 
//		} 
//	}
//	printf("%d\n", s); 
//	return 0; 
//}

//int main()
//{
//	char *pc = "blue1"; 
//	char ac[] = "blue1";
//	printf("%d\n", strlen(pc));
//	printf("%d\n", strlen(ac));
//	printf("%d\n", sizeof(ac));
//	printf("%d\n", sizeof(pc));
//}

//int main() 
//{ 
//	unsigned long ulA = 0x11000000; 
//	printf("%x\n", *(unsigned char *)&ulA); 
//	return 0; 
//}

//void Func(char str_arg[2]) 
//{ 
//	int m = sizeof(str_arg); 
//	int n = strlen(str_arg); 
//	printf("%d\n", m); 
//	printf("%d\n", n); 
//}
//int main(void) 
//{ 
//	char str[] = "Hello"; 
//	Func(str); 
//}

//int main() 
//{ 
//	int a, x; 
//	for (a = 0, x = 0; a <= 1 && !x++; a++) 
//	{ 
//		a++; 
//	}
//	printf("%d %d", a, x); 
//	return 0; 
//}

int main() 
{ 
	int a[5] = { 1, 2, 3, 4, 5 }; 
	int* p1 = (int*)(&a + 1); 
	int* p2 = (int*)((int)a + 1); 
	int* p3 = (int*)(a + 1); 
	printf("%d, %x, %d\n", p1[-1], p2[0], p3[1]); 
	return 0; 
}