#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


#if 0
class Base
{
public:
	void f0()
	{
		cout << "Base:f0()" << endl;
	}

	virtual void f1()
	{
		cout << "Base:f1()" << endl;
	}

	virtual void f2()
	{
		cout << "Base:f2()" << endl;
	}

	virtual void f3()
	{
		cout << "Base:f3()" << endl;
	}

	int _b;
};

class Derived :public Base
{
public:
	virtual void f4()
	{
		cout << "Derived:f4()" << endl;
	}

	virtual void f1()
	{
		cout << "Derived:f1()" << endl;
	}

	virtual void f3()
	{
		cout << "Derived:f3()" << endl;
	}

	virtual void f5()
	{
		cout << "Derived:f5()" << endl;
	}

	int _b;
};

typedef void(*Vfptr)();


//先找到该对象的地址，前四个字节存放着一个指针（虚表指针），指向一个虚表，该虚表中存放的就是虚函数的地址。
void TestFunc(Base& b)
{
	Vfptr* Vft=(Vfptr*)(*(int*)&b);
	while (*Vft)
	{
		(*Vft)();
		Vft++;
	}
}

int main()
{
	Base b;
	Derived d;

	TestFunc(b);
	TestFunc(d);
	return 0;
}
#endif


#if 0
class Base
{
public:

	virtual void f1()
	{
		cout << "Base:f1()" << endl;
	}

};

class Derived :public Base
{
public:

	virtual void f1()
	{
		cout << "Derived:f1()" << endl;
	}

	virtual void f2()
	{
		cout << "Derived:f2()" << endl;
	}
};

int main()
{
	Base b;
	Derived d;

	Base* pb = (Base*)&d;
	//这里的(Base*)其实没有任何作用，它就是相当于把子类的大小格式切割成与基类同种类型的一个类
	//调用也只能是调用子类的方法，当然该方法也必须是子类父类共有的
	pb->f1();

	pb = &(Base)d;
	//这种就是把d对象重新生成一个临时对象，而他的类型是Base类的。
	pb->f1();
	return 0;
}
#endif


