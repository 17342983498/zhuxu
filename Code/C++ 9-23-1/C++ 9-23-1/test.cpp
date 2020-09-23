#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
class Date
{
public:
	Date(int year , int month , int day )
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	ostream& operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day << endl;
		return _cout;
	}
private:

	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d(2020, 9, 23);
	d << cout;
	return 0;
}
#endif

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//public:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout,const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day << endl;
//	return _cout;
//}
//int main()
//{
//	Date d1(2020, 9, 23);
//	Date d2(2020, 9, 22);
//	cout << d1 << d2 ;
//	operator<<(operator<<(cout, d1), d2);
//	return 0;
//}

//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day << endl;
//	return _cout;
//}
//
//int main()
//{
//	Date d1(2020, 9, 23);
//	Date d2(2020, 9, 22);
//	cout << d1 << d2;
//	/*operator<<(operator<<(cout, d1), d2);*/
//	return 0;
//}


class Time
{
	friend class Date;
public:
	//Time(int hour=0, int minute=0, int second=0)
	Time(int hour , int minute , int second )
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
		, _t(12,15,13)
	{}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << "-" << _t._hour << "-" << _t._minute << "-" << _t._second << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d1(2020, 9, 23);
	d1.Print();
	return 0;
}
