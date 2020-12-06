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


//���ҵ��ö���ĵ�ַ��ǰ�ĸ��ֽڴ����һ��ָ�루���ָ�룩��ָ��һ�����������д�ŵľ����麯���ĵ�ַ��
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
	//�����(Base*)��ʵû���κ����ã��������൱�ڰ�����Ĵ�С��ʽ�и�������ͬ�����͵�һ����
	//����Ҳֻ���ǵ�������ķ�������Ȼ�÷���Ҳ���������ุ�๲�е�
	pb->f1();

	pb = &(Base)d;
	//���־��ǰ�d������������һ����ʱ���󣬶�����������Base��ġ�
	pb->f1();
	return 0;
}
#endif


