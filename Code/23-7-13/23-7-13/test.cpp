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
//	//���p1�����쳣����ô�ͻ�ֱ���˳�
//	int *p1 = new int;
//	int *p2 = nullptr;
//	try
//	{
//		//���p1�����쳣����ô����ֱ���˳���Ӧ�ý�p1�ͷŵ�
//		p2 = new int;
//	}
//	catch (...)//���������쳣
//	{
//		delete p1;
//		//�ͷŵ�֮��ֱ��throw��main�������catch��������
//		throw;
//	}
//
//	try
//	{
//		//Div���쳣�͵ý�p1��p2�ͷŵ����ٲ����쳣
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
//	//�Զ������ͻ���->
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
//		throw invalid_argument("��0����");
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
//		//������ζ�Ҫ��һ��
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
