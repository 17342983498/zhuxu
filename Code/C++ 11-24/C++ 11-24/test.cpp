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

	//������Ը����ำֵ�������಻�ܸ����ำֵ
	//ԭ�����������Լ����еĳ�Ա�����������޷�����������ȫ����ֵ�������������
	//b = d;
	//d = b;//����

	//�����ָ�����ָ�����࣬���������ָ�벻��ָ�����
	Base* bb = &d;
	Base& bbb = d;

	Derive* dd = &b;
	Derive& ddd = b;

	Derive* dd = (Derive*)&b;//��Ȼ���ǿ���ǿת�����ǿ��ܻ���Խ����ʵķ���
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