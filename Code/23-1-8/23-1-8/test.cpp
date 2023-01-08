#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


//namespace n1
//{
//	int a = 10;
//	int add(int x, int y)
//	{
//		return x + y;
//	}
//}
//
//namespace n2
//{
//	int a = 20;
//	int b = 12;
//}
//
//namespace n3
//{
//	int b = 23;
//}
//
//using n2::a;
//
//using namespace n3;
//int main()
//{
//	cout << n1::a << endl;
//	cout << a << endl;
//	cout << n1::add(1, 2) << endl;
//	cout << b << endl;
//	return 0;
//}

//void func(int a = 10)
//{
//	cout << a << endl;
//}
//
//
//int main()
//{
//	func();
//	func(20);
//	return 0;
//}

//void add(int a = 20, int b = 30);

//void add(int a ,int b)
//{
//	cout << a + b << endl;
//}
//
////void add(int a = 10, int b = 20)
////{
////	cout << a + b << endl;
////}
//
//int main()
//{
//	add();
//	add(1);
//	add(2, 3);
//	return 0;
//}

void add(int x, int y)
{
	cout << x + y << endl;
}

//int add(int x, int y)
//{
//	cout << x + y << endl;
//	return 0;
//}

void add(double x, double y)
{
	cout << x + y << endl;
}

int main()
{
	add(1, 2);
	add(1.2, 1.3);
	return 0;
}