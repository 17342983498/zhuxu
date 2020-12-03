#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
class A{};
class B :public A{};

class Base
{
public:

	virtual void Test1()
	{
		cout << "Test1" << endl;
	}

	virtual Base* Test2()
	{
		cout << "Test2" << endl;
		return this;
	}

	virtual A* Test3()
	{
		cout << "Test3" << endl;
	}

	virtual void Test4()
	{
		cout << "Test4" << endl;
	}

	//virtual int Test5()
	//{
	//	cout << "Test5" << endl;
	//}
};

class Derived :public Base
{
public:

	virtual void Test1()
	{
		cout << "Test1" << endl;
	}

	virtual Derived* Test2()
	{
		cout << "Test2" << endl;
		return this;
	}

	virtual B* Test3()
	{
		cout << "Test3" << endl;
	}

	void Test4()
	{
		cout << "Test4" << endl;
	}

	//virtual char Test5()
	//{
	//	cout << "Test5" << endl;
	//}

};

int main()
{
	return 0;
}
#endif


#if 0
#include <windows.h>


class WashRoom
{
public:
	void ManWC()
	{
		cout << "go to left" << endl;
	}

	void WomanWC()
	{
		cout << "go to right" << endl;
	}
};

class Person
{
public:
	// 纯虚函数
	virtual void GotoWC(WashRoom& wc) = 0;
};


// 抽象类是一定要被继承的
// 子类继承一个抽象类之后，如果没有重写基类的纯虚函数，则子类也是抽象类
class Man : public Person
{
public:
	virtual void GotoWC(WashRoom& wc)
	{
		wc.ManWC();
	}
};

class Woman : public Person
{
public:
	virtual void GotoWC(WashRoom& wc)
	{
		wc.WomanWC();
	}
};


void TestWC()
{
	Person* p = nullptr;
	WashRoom wr;
	for (size_t i = 0; i < 10; ++i)
	{
		if (rand() % 2 == 0)
		{
			p = new Man;
		}
		else
		{
			p = new Woman;
		}

		p->GotoWC(wr);
		delete p;

		Sleep(1000);
	}

}

int main()
{
	// Person p;  编译失败：抽象类不能实例化对象
	// Man m;
	TestWC();
	return 0;
}
#endif


#if 0
class Base
{
public:
	virtual void Test1()
	{}

	virtual void Test2()
	{}

	virtual void Test0()
	{}

	virtual void Test3()
	{}

	int _b;
};

int main()
{
	cout << sizeof(Base) << endl;
	Base b;
	b._b = 0;
	return 0;
}
#endif


#if 0
class Base
{
public:
	virtual void Test1()
	{}

	virtual void Test2()
	{}

	virtual void Test3()
	{}

	int _b;
};

class Derived :public Base
{
public:
	virtual void Test4()
	{}

	int _d;
};

int main()
{
	cout << sizeof(Base) << endl;
	Base b;
	b._b = 0;
	Derived d;
	d._b = 1;
	d._d = 2;
	return 0;
}
#endif


class Base
{
public:
	virtual void Test1()
	{}

	virtual void Test2()
	{}

	virtual void Test3()
	{}

	int _b;
};

class Derived :public Base
{
public:
	virtual void Test2()
	{}

	int _d;
};

int main()
{
	cout << sizeof(Base) << endl;
	Base b;
	b._b = 0;
	Derived d;
	d._b = 1;
	d._d = 2;
	return 0;
}