#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date()
//	{
//		cout << "Date()" << endl;
//	}
//	//Date(int year, int month, int day)
//	//{
//	//	cout << "Date(int year, int month, int day)" << endl;
//	//}
//	//Date(int year = 1, int month = 1, int day = 1)
//	//{
//	//	cout << "Date(int year, int month, int day)" << endl;
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1;//只能调无参构造函数
//	//Date d2(2023, 2, 10);//2、3都可以
//	//Date d3(2023);只能3
//	return 0;
//}


void Func(int a, int b = 2, int c = 3)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}


int main()
{
	Func(1);
	return 0;
}