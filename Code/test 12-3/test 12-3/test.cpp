#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#include <string>


class Base
{
public:
	void f0()
	{
		cout << "Base::f0()" << endl;
	}

	virtual void f1()
	{
		cout << "Base::f1()" << endl;
	}

	virtual void f2()
	{
		cout << "Base::f2()" << endl;
	}

	/*
	b1.f3();--->call Base::f3(&b1);
	b2.f3();--->call Base::f3(&b2);
	b3.f3();--->call Base::f3(&b3);
	virtual void f3(Base* const this)
	{
	this->_b = 10;
	cout << "Base::f3()" << endl;
	}
	*/
	virtual void f3()
	{
		_b = 10;
		cout << "Base::f3()" << endl;
	}
	int _b;
};

class Derived : public Base
{
public:
	void f0()
	{
		cout << "Base::f0()" << endl;
	}

	virtual void f4()
	{
		cout << "Derived::f4()" << endl;
	}

	virtual void f1()
	{
		cout << "Derived::f1()" << endl;
	}

	virtual void f3()
	{
		cout << "Derived::f3()" << endl;
	}

	virtual void f5()
	{
		cout << "Derived::f5()" << endl;
	}

	int _d;
};

typedef void(*PVF)();

void PrintVFT(Base& b, const string& str)
{
	cout << str << endl;
	// 取到对象前4个字节的内容--->(*(int*)&b)--->int类型的值
	// 必须将(*(int*)&b) 整形数值--->变成虚表地址
	// 虚表中--->放的虚函数的入口地址--->虚表中每个元素的类型其实就是每个虚函数的类型
	PVF* pVF = (PVF*)(*(int*)&b);   // &b--->Base*

	while (*pVF)
	{
		(*pVF)();
		++pVF;
	}
	cout << endl;
}

int main()
{

	Base bb;
	Derived dd;

	PrintVFT(bb, "Base vft:");
	PrintVFT(dd, "Derived vft: ");

	return 0;
}