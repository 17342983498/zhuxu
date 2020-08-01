#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
class Date
{
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void PrintDate()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}
};

int main()
{
	Date a(2020, 8, 1);
	a.PrintDate();
	Date b(2020, 8, 2);
	b.PrintDate();
	return 0;
}
#endif

class Time
{
private:
	int _hour;
	int _minute;
	int _second;
public:
	Time(int hour = 0, int minute = 0,int second = 0)
	{
		_hour = hour;
		_minute = minute;
		_second = second;
	}
	void PrintTime()
	{
		cout << _hour << " " << _minute << " " << _second << endl;
	}
};
class Date
{
private:
	int _year;
	int _month;
	int _day;
	Time _t;
public:
	void PrintDate()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}
};

int main()
{
	Date a;
	a.PrintDate();
	/*a.PrintTime();*/
	return 0;
}