#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
class Test
{
public:
	Test(int t=10)
		:_t(t)
	{
		cout << "Test:" << this << endl;
	}
	~Test()
	{
		cout << "~Test:" << this << endl;
	}
private:
	int _t;
};
int main()
{
	Test* p1 = new Test;
	Test* p2 = new Test();
	Test* p3 = new Test(20);

	delete p1;
	delete p2;
	delete p3;
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int t = 10)
		:_t(t)
	{
		cout << "Test:" << this << endl;
	}
	~Test()
	{
		cout << "~Test:" << this << endl;
	}
private:
	int _t;
};

void* operator new(size_t size,const char* filename,const char* funcname,int lineno)
{
	cout << filename << "-" << funcname << "-" << lineno << "-" << size << endl;
	return malloc(size);
}
int main()
{
	Test* p1 = new(__FILE__,__FUNCDNAME__,__LINE__) Test;
	int* p2 = new(__FILE__, __FUNCDNAME__, __LINE__) int;
	delete p1;
	delete p2;
	return 0;
}
#endif

class Test
{
public:
	Test(int t = 10)
		:_t(t)
	{
		cout << "Test:" << this << endl;
	}
	~Test()
	{
		cout << "~Test:" << this << endl;
	}
private:
	int _t;
};

int main()
{
	Test* p = (Test*)malloc(sizeof(Test));
	new(p) Test;
	p->~Test();
	free(p);
	return 0;
}