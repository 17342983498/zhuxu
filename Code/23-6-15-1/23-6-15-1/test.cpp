#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

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

//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//
//template<>
//bool Less<Date*>(Date* left,Date* right)
//{
//	return *left < *right;
//}
//
//bool Less(Date* left, Date* right)
//{
//	return *left < *right;
//}
//
//
//template<class T>
//bool Less<T*>(T* left, T* right)
//{
//	return *left < *right;
// }
//
//int main()
//{
//	int a = 10, b = 20;
//	cout << Less(a, b) << endl;
//
//	Date d1(2023, 6, 15);
//	Date d2(2023, 6, 16);
//	cout << Less(d1, d2) << endl;
//
//	//并没有按照具体的日期比较，而是根据日期对象的地址来比较
//	//Date* p1 = &d1;
//	//Date* p2 = &d2;
//	//cout << Less(p1, p2) << endl;
//
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl;
//
//	int* p3 = new int(1);
//	int* p4 = new int(2);
//	cout << Less(p3, p4) << endl;
//
//	return 0;
//}

//template<class T>
//struct Less
//{
//	bool operator()(const T& left, const T& right) const
//	{
//		return left < right;
//	}
//};
//
////template<class Date>
////struct Less
////{
////	bool operator()(const Date& left, const Date& right) const
////	{
////		return left < right;
////	}
////};
//
//template<>
//struct Less<Date*>
//{
//	bool operator()(const Date* left, const Date* right)const
//	{
//		return *left < *right;
//	}
//};
//
//template<class T>
//struct Less<T*>
//{
//	bool operator()(const T* left, const T* right) const
//	{
//		return *left < *right;
//	}
//};
//
//int main()
//{
//	Date d1(2023, 6, 15);
//	Date d2(2023, 6, 16);
//	cout << Less<Date>()(d1, d2) << endl;
//
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less<Date*>()(p1, p2) << endl;
//
//	int* p3 = new int(1);
//	int* p4 = new int(2);
//	cout << Less<int*>()(p3, p4) << endl;
//	return 0;
//}

//template<class T>
//class Data
//{
//public:
//	Data()
//	{
//		cout << "Data<T>" << endl;
//	}
//private:
//	int _d1;
//	int _d2;
//};

template<class T1, class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

//全特化
template<>
class Data<int, char>
{
public:
	Data()
	{
		cout << "Data<int,char>" << endl;
	}
private:
	int _d1;
	char _d2;
};

//偏特化
template<class T>
class Data<T,int>
{
public:
	Data()
	{
		cout << "Data<T,int>" << endl;
	}
private:
	T _d1;
	int _d2;
};

template<class T>
class Data<double,T>
{
public:
	Data()
	{
		cout << "Data<double,T>" << endl;
	}
private:
	double _d1;
	T _d2;
};

template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "Data<T1*, T2*>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

template<class T1, class T2>
class Data<T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		:_d1(d1),_d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	const T1& _d1;
	const T2& _d2;
};

int main()
{
	Data<int, char> d1;
	Data<char, char> d2;
	Data<char, int> d3;
	Data<double, char> d4;
	Data<int*,char*> d5;
	Data<int&, int&> d6(1,2);
	return 0;
}