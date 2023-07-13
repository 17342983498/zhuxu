#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//int Division()
//{
//	int x, y;
//	cin >> x >> y;
//	if (y == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return x / y;
//}
//
//
//void Func()
//{
//	//如果p1申请异常，那么就会直接退出
//	int *p1 = new int;
//	int *p2 = nullptr;
//	try
//	{
//		//如果p1申请异常，那么不能直接退出，应该将p1释放掉
//		p2 = new int;
//	}
//	catch (...)//捕获任意异常
//	{
//		delete p1;
//		//释放掉之后直接throw被main函数里的catch函数捕获
//		throw;
//	}
//
//	try
//	{
//		//Div抛异常就得将p1、p2释放掉，再捕获异常
//		cout << Division() << endl;
//	}
//	catch (...)
//	{
//		delete p1;
//		delete p2;
//		throw;
//	}
//
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}




//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	~SmartPtr()
//	{
//		cout << "delete:" << _ptr << endl;
//		delete _ptr;
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	//自定义类型会用->
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};


//int Division()
//{
//	int x, y;
//	cin >> x >> y;
//	if (y == 0)
//	{
//		throw invalid_argument("除0错误");
//	}
//	return x / y;
//}
//
//void Func()
//{
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(new int);
//	cout << Division() << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}
//
//
//int main()
//{
//	SmartPtr<int> ap1(new int(1));
//	SmartPtr<int> ap2(ap1);
//}


#include "Smart.h"

#include <memory>


void test_auto()
{
	std::auto_ptr<int> ap1(new int(1));
	std::auto_ptr<int> ap2(ap1);
}

//void test_unique()
//{
//	std::unique_ptr<int> ap1(new int(1));
//	std::unique_ptr<int> ap2(ap1);
//}

int main()
{
	//zx::test_auto();
	//test_unique();
	//test_auto();
	//zx::test_shared();
	zx::test_shared_safe();
	return 0;
}





























//shared_ptr<T>& operator=(const share_ptr<T>& sp)
//{
//	if (_ptr != sp._ptr)
//	{
//		//无论如何都要减一次
//		if (--(*_pcount) == 0)
//		{
//			delete _ptr;
//			delete _pcount;
//		}
//
//		_ptr = sp._ptr;
//		_pcount = ++sp._pcount;
//
//	}
//	return *this;
//}
