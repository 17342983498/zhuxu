#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//int main()
//{
//	//int a;
//	//char a;
//	double a;
//	cin >> a;
//	cout << a << endl;
//	return 0;
//}


//void Test(int a,int b,int c = 3)
//{
//	cout << a <<" "<< b <<" "<<c << endl;
//}
//
//
//
//int main()
//{
//	//两个函数之间的参数对应一定要吻合，不能出现某个参数没有值，当然某个参数值重合了也可以，但是会用被调用函数的参数。
//	//Test();
//	Test(10,20);
//	Test(10,20,30);
//	return 0;
//}


void add(int a,int b)
{
	cout << a + b << endl;
}

void add(double a, double b)
{
	cout << a + b << endl;
}

void add(int a, double b)
{
	cout << a + b << endl;
}

int main()
{
	add(1, 2.0);
	add(1, (int)2.0);
	return 0;
}