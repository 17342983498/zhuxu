#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 9)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << _year << " " << _month << " " << _day << endl;
	}
	Date(const Date& a)
	{
		_year = a._year;
		_month = a._month;
		_day = a._day;
		cout << this << endl;
		cout << &a << endl;
		cout << _year << " " << _month << " " << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date a1(2020, 8, 17);
	Date a2(a1);
	cout << &a1 << endl;
	cout << &a2 << endl;
	return 0;
}