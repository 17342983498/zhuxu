#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;
}
int main()
{
	int a = 10;
	int b = 20;
	swap(&a, &b);
	cout << a << " " << b << endl;
	return 0;
}

//void swap(int& a, int& b)
//{
//	int c = 0;
//	c = a;
//	a = b;
//	b = c;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	swap(a, b);
//	printf("%d %d\n", a, b);
//	return 0;
//}

