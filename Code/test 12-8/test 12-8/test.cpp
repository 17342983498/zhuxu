#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
class Base
{
public:
	virtual void Func1()
	{
		cout << "Base:Func1()" << endl;
	}

	virtual void Func2()
	{
		cout << "Base:Func2()" << endl;
	}

	virtual void Func3()
	{
		cout << "Base:Func3()" << endl;
	}
};

class Derived :public Base
{
public:
	virtual void Func1()
	{
		cout << "Derived:Func1()" << endl;
	}
	virtual void Func4()
	{
		cout << "Derived:Func4()" << endl;
	}
};

typedef void(*Pvf)();

void Test(Base& b)
{
	Pvf* P =(Pvf*)(*(int*)(&b));
	while (*P)
	{
		(*P)();
		++P ;
	}
	cout << endl;
}

int main()
{
	Base b;
	Derived d;
	Test(d);
	Test(b);
	return 0;
}
#endif




class B1
{
public:
	virtual void f1()
	{
		cout << "B1::f1()" << endl;
	}

	virtual void f2()
	{
		cout << "B1::f2()" << endl;
	}

	int _b1;
};

class B2
{
public:
	virtual void f3()
	{
		cout << "B2::f3()" << endl;
	}

	virtual void f4()
	{
		cout << "B2::f4()" << endl;
	}

	int _b2;
};


class D : public B1, public B2
{
public:
	virtual void f1()
	{
		cout << "D::f1()" << endl;
	}

	virtual void f3()
	{
		cout << "D::f3()" << endl;
	}

	virtual void f5()
	{
		cout << "D::f5()" << endl;
	}

	int _d;
};


typedef void(*PVF)();

void PrintVFTB1(B1& b, const string& str)
{
	//cout << str << endl;
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

void PrintVFTB2(B2& b, const string& str)
{
	//cout << str << endl;
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
	cout << sizeof(D) << endl;

	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;

	PrintVFTB1(d, "B1 vft:");
	PrintVFTB2(d, "B2 vft:");
	return 0;
}