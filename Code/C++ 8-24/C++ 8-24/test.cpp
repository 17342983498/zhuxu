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
	}
	Date& operator += (int day)
	{
		
		if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
		{
			if (day + _day > 31)
			{
				_day = (day + _day) - 31;
				_month += 1;
			}
			else
			{
				_day += day;
			}
		}
		else if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
		{
			if (day + _day > 30)
			{
				_day = (day + _day) - 30;
				_month += 1;
			}
			else
			{
				_day += day;
			}
		}
		else if (_month == 2)
		{
			if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0)
			{
				if (day + _day > 29)
				{
					_day = (day + _day) - 29;
					_month += 1;
				}
				else
				{
					_day += day;
				}
			}
			else
			{
				if (day + _day > 28)
				{
					_day = (day + _day) - 28;
					_month += 1;
				}
				else
				{
					_day += day;
				}
			}
		}
		cout << _year << " " << _month << " " << _day << endl;
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date a1(2000, 8, 24);
	a1+=15;
	return 0;
}