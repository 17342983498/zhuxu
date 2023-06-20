#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//template<class T,size_t N = 10>
//class Array
//{
//public:
//private:
//	T _arr[N];
//};

//template<class T, double N = 10.1>
//class Array
//{
//public:
//private:
//	T _arr[N];
//};
//
//
//int main()
//{
//	return 0;
//}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}

	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}

	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}

private:
	int _year;
	int _month;
	int _day;
};



template<class T>
bool Less(T left, T right)
{
	return left < right;
}

template<>
bool Less<Date*>(Date* left, Date* right)
{
	return *left < *right;
}

template<class T>
bool Less(T* left, T* right)
{
	return *left < *right;
}



int main()
{
	int a = 10, b = 20;
	cout << Less(a, b) << endl;

	Date d1(2023, 6, 15);
	Date d2(2023, 6, 16);
	cout << Less(d1, d2) << endl;



	Date* p1 = &d1;
	Date* p2 = &d2;
	cout << Less(p1, p2) << endl;

	int* p3 = new int(1);
	int* p4 = new int(2);
	cout << Less(p3, p4) << endl;

	return 0;
}