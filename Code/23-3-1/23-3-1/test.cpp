#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		cout << "Date(int,int,int):" << this << endl;
//	}
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d):" << this << endl;
//	}
//	~Date()
//	{
//		cout << "~Date():" << this << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//Date Test(Date d)
//{
//	Date tmp(d);
//	return tmp;
//}
//
//int main()
//{
//	Date d1(2000, 1, 9);
//	Test(d1);
//	return 0;
//}
//
//
//class Time
//
//{
//
//public:
//	Time()
//	{
//		_hour = 1;
//		_minute = 1;
//		_second = 1;
//	}
//	Time& operator=(const Time& t)
//	{
//		if (this != &t)
//		{
//			_hour = t._hour;
//			_minute = t._minute;
//			_second = t._second;
//		}
//		return *this;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//
//{
//
//private:
//	// 基本类型(内置类型)
//
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//
//	Time _t;
//};
//
//int main()
//{
//	Date d1;
//	Date d2;
//	d1 = d2;
//	return 0;
//}



class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Display()
	{
		cout << "Print()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
	void Display() const
	{
		cout << "Display()const" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日

};

int main()
{
	Date d1(2023, 3, 1);
	d1.Display();
	const Date d2(2023, 3, 1);
	d2.Display();
	return 0;
}

