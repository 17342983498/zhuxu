#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//class Date
//{
//public:
//	//Date(int year = 2023, int month = 2, int day = 9)
//	//	:_year(year),
//	//	_month(month),
//	//	_day(day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	Date(int year = 2023, int month = 2, int day = 9)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year = 2000;
//	int _month = 1;
//	int _day = 9;
//};
//
//
//int main()
//{
//	Date d1;
//	d1.Print();
//	return 0;
//}




//class Date
//{
//public:
//	//explicit Date(int year = 2023)
//	//{
//	//	cout << "Date()" << endl;
//	//}
//
//	Date(int year = 2023)
//	{
//		cout << "Date()" << endl;
//	}
//
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//
//private:
//	int _year = 2000;
//};
//
//int main()
//{
//	Date d1(2000);
//	Date d2 = 2001;  //构造+拷贝构造--->构造
//
//	const Date& d3 = 2000;
//	return 0;
//}



//class Date
//{
//public:
//
//	Date(int year = 2023, int month = 2, int day = 9)
//		:_year(year),
//		_month(month),
//		_day(day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1;
//	Date d2 = { 2000, 1, 9 };
//	return 0;
//}