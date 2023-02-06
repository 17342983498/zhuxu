#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 2000,int month = 1,int day = 9)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool operator==(const Date& d)
	{
		return d._year == _year&&d._day == _day&&d._month == _month;
	}

	bool operator<(const Date& d)
	{
		return _year < d._year ||
			(_year == d._year&&_month < d._month) ||
			(_year == d._year&&_month == d._month&&_day < d._day);
	}

	bool operator<=(const Date& d)
	{
		return *this == d || *this < d;
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	Date& operator=(const Date& d)
	{
		if (*this != d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//������
	////ǰ��++
	//Date& operator++()
	//{
	//	(*this)++;
	//	return *this;
	//}
	////����++
	//Date operator++(int)
	//{
	//	Date tmp(*this);
	//	(*this)++;
	//	return tmp;
	//}

	void DatePrint()
	{
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2023, 2, 5);
	//���Կ�����d1�����˶�Ӧ�ĺ�������d,d2������this
	Date d2(d1);
	d2.DatePrint();
	Date d3;
	Date d4(2023, 2, 6);
	Date d5;
	d5 = d4;
	d5.DatePrint();
	//��һ���βθ���this
	cout << (d1 == d2) << endl;
	cout << (d3 < d1) << endl;
	cout << (d1 <= d4) << endl;
	cout << (d1 != d4) << endl;

	d5++;
	d5.DatePrint();
	++d5;
	d5.DatePrint();
	return 0;
}