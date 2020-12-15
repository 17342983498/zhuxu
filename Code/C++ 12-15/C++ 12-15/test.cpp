#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}

	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
private:
	int _d;
};

class Derived :public Base
{
public:
	virtual void Func1()
	{
		cout << "Derived::Func1()" << endl;
	}

	virtual void Func3()
	{
		cout << "Derived::Func3()" << endl;
	}

	virtual void Func4()
	{
		cout << "Derived::Func4()" << endl;
	}
private:
	int _b;
};

typedef void(*VFPTR) ();
void TestFunc(Base& b)
{
	VFPTR* vFPtr = (VFPTR*)*((int*)(&b));
	while (*vFPtr)
	{
		(*vFPtr)();
		++vFPtr;
	}
	cout << endl;
}


//void TestVirtual(Base& b)
//{
//	b.Func1();
//	b.Func2();
//	b.Func3();
//	b.Func4();
//}

int main()
{
	Base b;
	TestFunc(b);
	Derived d;
	TestFunc(d);
	//TestVirtual(b);
	TestVirtual(d);
	return 0;
}
#endif


#if 0
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

	virtual void f6()
	{
		cout << "D::f6()" << endl;
	}

	int _d;
};


typedef void(*PVF)();

void PrintVFTB1(B1& b)
{

	PVF* pVF = (PVF*)(*(int*)&b);   

	while (*pVF)
	{
		(*pVF)();
		++pVF;
	}
	cout << endl;
}

void PrintVFTB2(B2& b)
{
	PVF* pVF = (PVF*)(*(int*)&b);  

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

	PrintVFTB1(d);
	PrintVFTB2(d);
	return 0;
}
#endif


class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}

	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
private:
	int _d;
};

class Derived :public Base
{
public:
	virtual void Func1()
	{
		cout << "Derived::Func1()" << endl;
	}

	virtual void Func3()
	{
		cout << "Derived::Func3()" << endl;
	}

	virtual void Func4()
	{
		cout << "Derived::Func4()" << endl;
	}
private:
	int _b;
};


int main()
{
	Base b;
	Derived d;
	return 0;
}