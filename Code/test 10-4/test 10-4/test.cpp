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


	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			return 31;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			return 30;
		}
		else
		{
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			{
				return 29;
			}
			else
				return 28;
		}


	}


	//// 日期+=天数
	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this - (0 - day);
		}
		this->_day += day;
		int daysOfMonth = 0;
		while (this->_day >(daysOfMonth = this->GetMonthDay(this->_year, this->_month)))
		{
			this->_month += 1;
			if (this->_month > 12)
			{
				this->_year += 1;
				this->_month = 1;
			}
			this->_day -= daysOfMonth;
		}
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
		return *this;
	}


	////// 日期+天数
	Date operator+(int day)
	{
		if (day < 0)
		{
			return *this - (0 - day);
		}
		Date temp(*this);
		temp._day += day;
		int daysOfMonth = 0;
		while (temp._day >(daysOfMonth = temp.GetMonthDay(temp._year, temp._month)))
		{
			temp._month += 1;
			if (temp._month > 12)
			{
				temp._year += 1;
				temp._month = 1;
			}
			temp._day -= daysOfMonth;
		}
		cout << temp._year << "-" << temp._month << "-" << temp._day << endl;
		return temp;
	}


	////// 日期-天数
	Date operator-(int day)
	{
		if (day < 0)
		{
			return *this + (0 - day);
		}
		Date temp(*this);
		temp._day -= day;
		while (temp._day <= 0)
		{
			temp._month -= 1;
			if (temp._month == 0)
			{
				temp._year -= 1;
				temp._month = 12;
			}
			temp._day += temp.GetMonthDay(temp._year, temp._month);
		}
		cout << temp._year << "-" << temp._month << "-" << temp._day << endl;
		return temp;
	}


	////// 日期-=天数
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this + (0 - day);
		}
		this->_day -= day;
		while (this->_day <= 0)
		{
			this->_month -= 1;
			if (this->_month <= 0)
			{
				this->_year -= 1;
				this->_month = 12;
			}
			this->_day += this->GetMonthDay(this->_year, this->_month);
		}
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
		return *this;
	}

	//friend ostream& operator<<(ostream& _cout, const Date& d);
private:

	int _year;
	int _month;
	int _day;

};

//ostream& operator<<(ostream& _cout,const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
int main()
{
	Date d1(2020, 9, 20);
	Date d2;
	d1 += 100;

	d1 -= 100;

	d2 = d1 + 100;

	d2 = d1 - 100;

	return 0;
}