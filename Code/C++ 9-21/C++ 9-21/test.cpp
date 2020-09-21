#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Time
{
public:
	Time(int hour=0, int minute=0, int second=0)
		//:_hour(hour)
		//, _minute(minute)
		//, _second(second)
		//:_hour(0)
		//, _minute(0)
		//, _second(0)
	{
		cout << "Time(int int int)" << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year , int month , int day )
		:_year(year)
		, _month(month)
		, _day(day)
		, _t(0,0,0)
	{
		cout << "Date(int,int,int)" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
int main()
{
	Date d(2020, 9, 21);
	return 0;
}