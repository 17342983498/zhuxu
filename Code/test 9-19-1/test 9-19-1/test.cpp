#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Time
{
public:
	Time(int _hour,int _minute,int second)
	{
		cout << "Time()" << endl;
		cout << _hour << " " << _minute << " " << _second << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year=1900, int month=1, int day=1)
		:_year()
		,_month()
		, _day(1)
		,t(0,0,0)
	{
		cout << "Date()" << endl;
		cout << _year << " " << _month << " " << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	Time t;
};
int main()
{
	Date d(2020,9,19);
	return 0;
}