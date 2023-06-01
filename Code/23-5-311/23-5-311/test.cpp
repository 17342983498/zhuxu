#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
//class Person
//{
//public:
//	Person(const char* name = "",int age = 0)
//		:_name(name)
//		, _age(age)
//	{}
//
//	//Person(const Person& p) = delete;
//	Person(const Person& p)
//		:_name(p._name)
//		, _age(p._age)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person(Person&& p) = default;
//
//private:
//	string _name;
//	int _age;
//};
//
//
//int main()
//{
//	Person p1;
//	Person p2 = p1;
//	Person p3 = move(p1);
//}

//void ShowList()
//{
//	cout << endl;
//}
//
//template<class T, class ...Args>
//void ShowList(const T& val, Args... args)
//{
//	//cout << sizeof...(args) << endl;
//	cout << val << " ";
//	ShowList(args...);
//}
//
//int main()
//{
//	ShowList();
//	ShowList(1);
//	ShowList(1, '2');
//	ShowList(1,"dsfs");
//	ShowList(1, '2', "dsfs");
//	return 0;
//}

void _ShowList()
{
	cout << endl;
}

template<class T,class ...Args>
void _ShowList(const T& val,Args... args)
{
	cout << __FUNCTION__ << "(" << sizeof...(args) << ")" << endl;
	_ShowList(args...);
}

template<class ...Args>
void ShowList(Args... args)
{
	_ShowList(args...);
}


int main()
{
	ShowList(1, 'a', string("abc"));
	return 0;
}