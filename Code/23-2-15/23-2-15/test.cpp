#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//class Date
//{
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	int GetMonthDay(int year,int month)
//	{
//		int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//		{
//			days[2] = 29;
//		}
//		return days[month];
//	}
//
//	Date(int year = 2000,int month = 1,int day = 9)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	bool operator==(const Date& d)
//	{
//		return d._year == _year&&d._day == _day&&d._month == _month;
//	}
//
//	bool operator<(const Date& d)
//	{
//		return _year < d._year ||
//			(_year == d._year&&_month < d._month) ||
//			(_year == d._year&&_month == d._month&&_day < d._day);
//	}
//
//	bool operator<=(const Date& d)
//	{
//		return *this == d || *this < d;
//	}
//
//	bool operator!=(const Date& d)
//	{
//		return !(*this == d);
//	}
//
//	Date& operator=(const Date& d)
//	{
//		if (*this != d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//
//	//前置++
//	Date operator++()
//	{
//		*this += 1;
//		return *this;
//	}
//
//	//后置++
//	Date operator++(int)
//	{
//		Date tmp(*this);
//		*this += 1;
//		return tmp;
//	}
//
//	//前置--
//	Date operator--()
//	{
//		*this -= 1;
//		return *this;
//	}
//
//	//后置--
//	Date operator--(int)
//	{
//		Date tmp(*this);
//		*this -= 1;
//		return tmp;
//	}
//
//	Date& operator+=(int days)
//	{
//		if (days < 0)
//		{
//			*this -= -days;
//			return *this;
//		}
//		_day += days;
//		while (_day > GetMonthDay(_year, _month))
//		{
//			_day -= GetMonthDay(_year, _month);
//			++_month;
//			if (_month > 12)
//			{
//				_year++;
//				_month = 1;
//			}
//		}
//		return *this;
//	}
//
//	Date operator+(int days)
//	{
//		Date tmp(*this);
//		tmp += days;
//		return tmp;
//	}
//
//	Date& operator-=(int days)
//	{
//		if (days < 0)
//		{
//			*this += -days;
//			return *this;
//		}
//		_day -= days;
//		while (_day <= 0)
//		{
//			--_month;
//			if (_month == 0)
//			{
//				_month = 12;
//				--_year;
//			}
//			_day += GetMonthDay(_year, _month);
//		}
//		return *this;
//	}
//
//	Date operator-(int days)
//	{
//		Date tmp(*this);
//		tmp -= days;
//		return tmp;
//	}
//
//	int operator-(const Date& d)
//	{
//		Date max = *this;
//		Date min = d;
//		int flag = 1;
//		if (*this < d)
//		{
//			max = d;
//			min = *this;
//			flag = -1;
//		}
//		int count = 0;
//		while (min != max)
//		{
//			++min;
//			++count;
//		}
//		return count*flag;
//	}
//
//	void DatePrint()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
//	return out;
//}
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//
//void DateTest1()
//{
//	Date d1(2023, 2, 5);
//	//可以看出，d1给到了对应的函数参数d,d2给到了this
//	Date d2(d1);
//	d2.DatePrint();
//	Date d3;
//	Date d4(2023, 2, 6);
//	Date d5;
//	d5 = d4;
//	d5.DatePrint();
//	//第一个形参给到this
//	cout << (d1 == d2) << endl;
//	cout << (d3 < d1) << endl;
//	cout << (d1 <= d4) << endl;
//	cout << (d1 != d4) << endl;
//}
//
//void DateTest2()
//{
//	Date d4(2023, 2, 8);
//	d4 += 100;
//	d4.DatePrint();
//	Date d5;
//	d5 = d4 + 1000;
//	d5.DatePrint();
//}
//
//void DateTest3()
//{
//	Date d4(2023, 2, 8);
//	d4 -= 100;
//	d4.DatePrint();
//	Date d5;
//	d5 = d4 - 1000;
//	d5.DatePrint();
//}
//
//void DateTest4()
//{
//	Date d1(2023, 2, 8);
//	d1 -= -100;
//	d1.DatePrint();
//}
//
//void DateTest5()
//{
//	Date d1(2023, 2, 8);
//	Date d2(1974, 9, 2);
//	cout << d1 - d2 <<endl;
//}
//
//void DateTest6()
//{
//	Date d1(2023, 2, 8);
//	cout << d1;
//}
//
//void DateTest7()
//{
//	Date d1;
//	cin >> d1;
//	cout << d1;
//}
//
//int main()
//{
//	//DateTest1();
//
//	//DateTest2();
//
//	//DateTest3();
//
//	//DateTest4();
//
//	//DateTest6();
//
//	DateTest7();
//	return 0;
//}

//class Test
//{
//public:
//	void Display()
//	{
//		cout << "Display()" << endl;
//		Print();
//	}
//	void Display()const
//	{
//		cout << "Display()const" << endl;
//		Print();
//	}
//	//void Print()
//	//{
//	//	cout << "Print()" << endl;
//	//}
//	void Print()const
//	{
//		cout << "Print()const" << endl;
//	}
//};
//
//int main()
//{
//	Test t1;
//	t1.Display();
//	const Test t2;
//	t2.Display();
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 2000,int month = 1,int day = 9)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Display()const
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//		//_year = 2023;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	const Date d;
//	d.Display();
//	return 0;
//}


class Date
{
public:
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d;
	cout << &d << endl;
	const Date d1;
	cout << &d1 << endl;
	return 0;
}