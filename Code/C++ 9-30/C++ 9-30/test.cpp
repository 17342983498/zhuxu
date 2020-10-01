#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//// >运算符重载
	bool operator>(const Date& d)
	{
		if (this->_year > d._year ||
			this->_year == d._year&&this->_month > d._month ||
			this->_year == d._year&&this->_month == d._month&&this->_day > d._day)
		{
			return true;
		}
		return false;
	}

	//// ==运算符重载
	bool operator==(const Date& d)
	{
		if (d._year == this->_year&&d._month == this->_month&&d._day == this->_day)
		{
			return true;
		}
		return false;
	}

	//// <运算符重载
	bool operator < (const Date& d)
	{
		if (this->_year < d._year ||
			this->_year == d._year&&this->_month < d._month ||
			this->_year == d._year&&this->_month == d._month&&this->_day < d._day)
		{
			return true;
		}
		return false;
	}

	//// !=运算符重载
	bool operator != (const Date& d)
	{

		return !(&d == this);
	}

private:

	int _year;
	int _month;
	int _day;

};

int main()
{
	Date d1(2020, 10, 9);

	Date d2(2020, 9, 20);

	if (d1 > d2)
	{
		cout << "d1 > d2" << endl;
	}

	if (d1 == d2)
	{
		cout << "d1 == d2" << endl;
	}

	if (d1 < d2)
	{
		cout << "d1 < d2" << endl;
	}


	if (d1 != d2)
	{
		cout << "d1 != d2" << endl;
	}
	return 0;
}