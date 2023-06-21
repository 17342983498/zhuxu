#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	bool operator<(const Date& d)const
//	{
//		return (_year < d._year) ||
//			(_year == d._year && _month < d._month) ||
//			(_year == d._year && _month == d._month && _day < d._day);
//	}
//
//	bool operator>(const Date& d)const
//	{
//		return (_year > d._year) ||
//			(_year == d._year && _month > d._month) ||
//			(_year == d._year && _month == d._month && _day > d._day);
//	}
//
//	friend ostream& operator<<(ostream& _cout, const Date& d)
//	{
//		_cout << d._year << "-" << d._month << "-" << d._day;
//		return _cout;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};


//基础的模板
//template<class T1, class T2>
//class Data
//{
//public:
//	Data()
//	{
//		cout << "Data(T1, T2)" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};


//全特化
//将模板参数列表中所有的参数都确定化
//template<>
//class Data<int, char>
//{
//public:
//	Data()
//	{
//		cout << "Data(int, char)" << endl;
//	}
//private:
//	int _d1;
//	char _d2;
//};
//
//
//int main()
//{
//	Data<int, int> d1;
//	Data<int, char> d2;
//	Data<int, double> d3;
//	return 0;
//}


//template<class T>
//class Data<T, int>
//{
//public:
//	Data()
//	{
//		cout << "Data<T,int>" << endl;
//	}
//private:
//	T _d1;
//	int _d2;
//};
//
//template<class T>
//class Data<double, T>
//{
//public:
//	Data()
//	{
//		cout << "Data<double,T>" << endl;
//	}
//private:
//	double _d1;
//	T _d2;
//};
//
//template<class T1, class T2>
//class Data<T1*, T2*>
//{
//public:
//	Data()
//	{
//		cout << "Data<T1*, T2*>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//template<class T1, class T2>
//class Data<T1&, T2&>
//{
//public:
//	Data(const T1& d1, const T2& d2)
//		:_d1(d1), _d2(d2)
//	{
//		cout << "Data<T1&, T2&>" << endl;
//	}
//private:
//	const T1& _d1;
//	const T2& _d2;
//};
//
//int main()
//{
//	Data<int, char> d1;
//	Data<char, char> d2;
//	Data<char, int> d3;
//	Data<double, char> d4;
//	Data<int*, char*> d5;
//	Data<int&, int&> d6(1, 2);
//	return 0;
//}

//template <class T1>
//class Data<T1, int>
//{
//public:
//	Data() { cout << "Data<T1, int>" << endl; }
//
//private:
//	T1 _d1;
//	int _d2;
//};

//template<class T1, class T2>
//class Data<T1*, T2*>
//{
//public:
//	Data()
//	{
//		cout << "Data<T1*, T2*>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//template<class T1, class T2>
//class Data<T1&, T2&>
//{
//public:
//	Data(const T1& d1, const T2& d2)
//		:_d1(d1), _d2(d2)
//	{
//		cout << "Data<T1&, T2&>" << endl;
//	}
//private:
//	const T1& _d1;
//	const T2& _d2;
//};
//
//int main()
//{
//	Data<int, double> d1;
//	//Data<char, char> d2;
//	//Data<char, int> d3;
//	Data<double, int> d4;
//	Data<int*, char*> d5;
//	Data<int&, int&> d6(1, 2);
//	return 0;
//}





//template<class T>
//struct Less
//{
//	bool operator()(const T& x,const T& y)const
//	{
//		return x < y;
//	}
//};
//
//
//template<>
//struct Less<Date*>
//{
//	bool operator()(Date* x, Date* y)const
//	{
//		return *x < *y;
//	}
//};
//
//int main()
//{
//	Date d1(2023, 6, 21);
//	Date d2(2023, 6, 22);
//	Date d3(2023, 6, 23);
//
//	vector<Date> v;
//	v.push_back(d3);
//	v.push_back(d1);
//	v.push_back(d2);
//
//	sort(v.begin(), v.end(), Less<Date>());
//
//	vector<Date*> v1;
//	v1.push_back(&d3);
//	v1.push_back(&d1);
//	v1.push_back(&d2);
//
//	sort(v1.begin(), v1.end(), Less<Date*>());
//	return 0;
//}



#include "Func.h"


int main()
{
	int x = 1,y = 2;
	add(x, y);
	return 0;
}