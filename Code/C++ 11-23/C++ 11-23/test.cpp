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
		_pub = 100;//public   ԭ����main�����п���ֱ��ʹ��
		_pro = 200;//protected     ԭ����main�����в��ɼ��������ټ̳�һ���࣬���Ǹ����п���ʹ��
		_pri = 300;//private      ԭ����main�������Ǹ����ж����ɼ�
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
		_pub = pub;//protected   ԭ�����Ǹ����еĳ�Ա�����п���ʹ�ã�����Derive�в�����mian������ʹ��
		_pro = pro;//protected     ԭ�����Ǹ����еĳ�Ա�����п���ʹ�ã�����Derive�в�����mian������ʹ��
		_pri = pri;//private      ԭ����main���������ж����ɼ�
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
		_pub = 100;//private   ԭ����main�����к����ж����ɼ�
		_pro = 200;//private     ԭ����main�����к����ж����ɼ�
		_pri = 300;//private      ԭ����main���������ж����ɼ�
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