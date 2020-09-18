#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


class Date
{
public:

	// 获取某年某月的天数
	//int GetMonthDay(int year, int month)
	//{
	//	cout << _year << _month << endl;
	//}
	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << _year << " " << _month << " " << _day << endl;
	}

	//// 拷贝构造函数
	//// d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << _year << " " << _month << " " << _day << endl;
	}

	//// 赋值运算符重载
	//// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
			cout << _year << " " << _month << " " << _day << endl;
		}
		return *this;
	}

	//// 析构函数
	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
		cout << "~Date" << endl;
	}

	//// 日期+=天数
	Date& operator+=(int day)
	{
		_day += day;
		cout << _year << " " << _month << " " << _day << endl;
		return *this;
	}

	////// 日期+天数
	Date operator+(int day)
	{
		_day += day;
		cout << _year << " " << _month << " " << _day << endl;
		return *this;
	}

	////// 日期-天数
	Date operator-(int day)
	{
		_day -= day;
		cout << _year << " " << _month << " " << _day << endl;
		return *this;
	}

	////// 日期-=天数
	Date& operator-=(int day)
	{
		_day -= day;
		cout << _year << " " << _month << " " << _day << endl;
		return *this;
	}

	//// 前置++
	Date& operator++()
	{
		_day += 1;
		cout << _year << " " << _month << " " << _day << endl;
		return *this;
	}

	//// 后置++
	Date operator++(int)
	{
		Date temp(*this);
		_day += 1;
		cout << _year << " " << _month << " " << _day << endl;
		return temp;
	}

	//// 后置--
	Date operator--(int)
	{
		Date temp(*this);
		_day -= 1;
		cout << _year << " " << _month << " " << _day << endl;
		return temp;
	}

	//// 前置--
	Date& operator--()
	{
		_day -= 1;
		cout << _year << " " << _month << " " << _day << endl;
		return *this;
	}

	//// >运算符重载
	bool operator>(const Date& d)
	{
		cout << this << endl;
		cout << &d << endl;
		if (this->_year > d._year ||
			this->_year == d._year&&this->_month > d._month ||
			this->_year == d._year&&this->_month == d._month&&this->_day > d._day)
		{
			return 1;
		}
		return 0;
	}

	//// ==运算符重载
	bool operator==(const Date& d)
	{
		if (d._year == this->_year&&d._month == this->_month&&d._day == this->_day)
		{
			return 1;
		}
		return 0;
	}

	//// >=运算符重载
	inline bool operator >= (const Date& d)
	{
		if (this->_year >= d._year ||
			this->_year == d._year&&this->_month >= d._month ||
			this->_year == d._year&&this->_month == d._month&&this->_day >= d._day)
		{
			return 1;
		}
		return 0;
	}

	//// <运算符重载
	bool operator < (const Date& d)
	{
		if (this->_year < d._year ||
			this->_year == d._year&&this->_month < d._month ||
			this->_year == d._year&&this->_month == d._month&&this->_day < d._day)
		{
			return 1;
		}
		return 0;
	}

	//// <=运算符重载
	bool operator <= (const Date& d)
	{
		if (this->_year <= d._year ||
			this->_year == d._year&&this->_month <= d._month ||
			this->_year == d._year&&this->_month == d._month&&this->_day <= d._day)
		{
			return 1;
		}
		return 0;
	}

	//// !=运算符重载
	bool operator != (const Date& d)
	{
		if (this->_year != d._year ||
			this->_month != d._month ||
			this->_day != d._day)
		{
			return 1;
		}
		return 0;
	}

	//// 日期-日期 返回天数
	int operator-(const Date& d)
	{
		int count = 0;
		int month1 = this->_month;
		int month2 = d._month;
		month1--;
		month2++;
		if (month1 == month2)
		{
			count = this->_day - d._day;
			return count;
		}
		else
		{
			for (int i = month2; i <= month1; i++)
			{
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				{
					count += 31;
				}
				else
					count += 30;
			}
			if (d._month == 1 || d._month == 3 || d._month == 5 || d._month == 7 || d._month == 8 || d._month == 10 || d._month == 12)
			{
				count += (31 - d._day);
			}
			else
				count += (30 - d._day);
			count += this->_day;
			return count;
		}
	}

private:

	int _year;
	int _month;
	int _day;

};

int main()
{
	Date d1(2020, 8, 9);
	/*Date GetMonthDay(2020, 9);*/
	//Date d2(d1);
	/*Date d2;*/
	//d2 = d1;
	/*d1 += 3;
	d1 + 3;
	d1 - 3;
	d1 -= 3;*/
	//d2 = ++d1;
	//d2 = d1++;
	/*d2 = d1--;*/
	//d2 = --d1;
	Date d3(2020, 9, 20);
	//cout << &d1 << endl;
	//cout << &d3 << endl;
	//if (d1 > d3)
	//{
	//	cout << "d1 > d3" << endl;
	//}
	//if (d1 == d3)
	//{
	//	cout << "d1 == d3" << endl;
	//}
	//if (d1 >= d3)
	//{
	//	cout << "d1 >= d3" << endl;
	//}
	//if (d1 < d3)
	//{
	//	cout << "d1 < d3" << endl;
	//}
	//if (d1 <= d3)
	//{
	//	cout << "d1 <= d3" << endl;
	//}
	//if (d1 != d3)
	//{
	//	cout << "d1 != d3" << endl;
	//}
	int daynum = d3 - d1;
	cout << daynum << endl;
	return 0;
}