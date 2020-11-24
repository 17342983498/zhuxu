#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
class Base
{
public:

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class Derive :public Base
{
public:

private:
	int _Der;
};

int main()
{
	Derive d;
	Base b;

	//子类可以给基类赋值，但基类不能给子类赋值
	//原因：子类中有自己独有的成员变量，基类无法满足给子类的全部赋值，但是子类可以
	//b = d;
	//d = b;//报错

	//基类的指针可以指向子类，但是子类的指针不可指向基类
	Base* bb = &d;
	Base& bbb = d;

	Derive* dd = &b;
	Derive& ddd = b;

	Derive* dd = (Derive*)&b;//虽然我们可以强转，但是可能会有越界访问的风险
	return 0;
}
#endif

class Base
{
public:

	void Test()
	{
		cout << _pub << _pro << _pri << endl;
	}
public:
	int _pub;
	int _pro;
	int _pri;
};

class Derive :public Base
{
public:

	void Test()
	{
		cout << _pub << _pro << _pri << endl;
	}
private:
	int _Der;
};

int main()
{
	Derive d;
	d.Test();
	d.Base::Test();
	return 0;
}