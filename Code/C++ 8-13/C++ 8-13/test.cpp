#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 2000 , int month = 1 , int day = 9)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << _year << " " << _month << " " << _day << endl;
	}
	Date(const Date& s)
	{
		_year = s._year;
		_month = s._month;
		_day = s._month;
		cout << &s << endl;
		cout << this << endl;
		cout << s._year << " " << s._month << " " << s._day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date s1(2020, 8, 13);
	Date s2(s1);
	cout << &s1 << endl;
	cout << &s2 << endl;
	return 0;
}