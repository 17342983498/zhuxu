#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str+1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("len=%d\n", len);
//	return 0;
//}

//void reverse_string(char* str)
//{
//	if (*(++str) != '\0')
//	{
//		reverse_string(str);
//	}
//	printf("%c ", *(str - 1));
//}
//int main()
//{
//	char arr[]= "abcdef";
//	reverse_string(arr);
//	return 0;
//}
//int sum(int n)
//{
//	
//	if (n != 0)
//	{
//		return n % 10+ (sum(n / 10));
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//
//	printf("%d\n",sum(1972));
//	return 0;
//}
//int fuc(int x)
//{
//	if (x != 0)
//		return x % 10 + (fuc(x / 10));
//	return 0;
//}
//
//int main()
//{
//	printf("%d\n", fuc(2138));
//	return 0;
//}
//int Fac(int n, int k)
//{
//	if (k == 0)
//	{
//		return 1;
//	}
//	if (n == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		 return n * (Fac(n, k - 1));
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	int sum = Fac(n, k);
//	printf("%d\n", sum);
//	return 0;
//}

//int Find_num(int n, int k)
//{
//	if (k == 0)
//    {
//	    return 1;
//	 }
//	 if (k == 1)
//     {
//		 return n;
//	 }
//	 else
//     {
//		 return n*Find_num(n, k - 1);
//	  }
// }
//
//int main()
//{
//	int n, k;
//	printf("请输入底数：\n");
//	scanf("%d", &n);
//	printf("请输入指数：\n");
//	scanf("%d", &k);
//	int num = Find_num(n, k);
//	printf("%d\n", num);
//
//	return 0;
//}
//int Fib(int n)
//{
//	int i = 1;
//	int j = 1;
//	int m = 1;
//	while (n > 2)
//	{
//		m = i + j;
//		i = j;
//		j = m;
//		n--;
//	}
//	return m;
//}
//int Fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(n - 1) + Fib(n - 2);
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int num = Fib(n);
//	printf("num = %d\n", num);
//	return 0;
//}