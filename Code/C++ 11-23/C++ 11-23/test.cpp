#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
class Base
{
public:
	Base(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
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
	void Change()
	{
		_pub = 100;//public   原因：在main函数中可以直接使用
		_pro = 200;//protected     原因：在main函数中不可见，但可再继承一个类，在那个类中可以使用
		_pri = 300;//private      原因：在main函数和那个类中都不可见
	}
};

class A:public Derive
{
public:
	void Change()
	{
		_pro = 2000;
		_pri = 3000;
	}
};
int main()
{
	Base s(10, 20, 30);
	s._pub = 100;
	s._pro = 200;
	s._pri = 300;
	return 0;
}
#endif


#if 0
class Base
{
public:
	Base(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class Derive :protected Base
{
public:

	void Change(int pub, int pro, int pri)
	{
		_pub = pub;//protected   原因：在那个类中的成员函数中可以使用，但在Derive中不可在mian函数中使用
		_pro = pro;//protected     原因：在那个类中的成员函数中可以使用，但在Derive中不可在mian函数中使用
		_pri = pri;//private      原因：在main函数和类中都不可见
	}
};

class A :public Derive
{
public:

	void Change()
	{
		_pub = 1000;
		_pro = 2000;
		_pri = 3000;
	}
};
int main()
{
	Base s(10, 20, 30);1
	s._pub = 100;
	s._pro = 200;
	s._pri = 300;
	Derive d(100,200,300);
	d._pub = 11;
	d._pro = 22
	return 0;
}
#endif


//#if 0
class Base
{
public:
	Base(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class Derive :private Base
{
public:
	void Change()
	{
		_pub = 100;//private   原因：在main函数中和类中都不可见
		_pro = 200;//private     原因：在main函数中和类中都不可见
		_pri = 300;//private      原因：在main函数和类中都不可见
	}
};

class A :public Derive
{
public:

	void Change()
	{
		_pub = 1000;
		_pro = 2000;
		_pri = 3000;
	}
};
int main()
{
	Base s(10, 20, 30);
	s._pub = 100;
	s._pro = 200;
	s._pri = 300;
	return 0;
}
//#endif