#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
int main()
{
	int* p1 = new int;
	delete p1;
	int* p2 = new int(10);
	delete p2;
	int* p3 = new int[10];
	delete p3;
	int* p4 = new int[10]{0};
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int a;
};
int main()
{
	Test* p1 = new Test;
	delete p1;
	Test* p2 = new Test[10];
	delete[] p2;
	return 0;
}
#endif

class Test
{
public:
	Test(int a,int b)
	{
		cout << "Test():" << this << endl;;
	}
	//Test(int a = 10)
	//{

	//}
	Test()
	{

	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int a;
	int b;
};
int main()
{
	Test* p1 = new Test(10,20);
	delete p1;
	Test* p2 = new Test[10];//自定义类型为连续空间，初始化就得调用无参或者全缺省参数的构造函数
	delete[] p2;
	return 0;
}