#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//int a = 30;
//namespace n1
//{
//	int a = 10;
//}
//using namespace n1;
//
//void func()
//{
//	int a = 20;
//	cout << a << endl;
//}
//
//int main()
//{
//	func();
//	return 0;
//}

void func(int a=10,int b=20,int c=30)
{
	cout << a + b + c << endl;
}
void func1(int a, int b = 20, int c = 30)
{
	cout << a + b + c << endl;
}

int main()
{
	int a = 1, b = 2, c = 3;
	func(a, b, c);
	func1(1,2);
	func();
	return 0;
}