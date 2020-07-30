#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class num
{
private:
	int _a;//该成员变量既可在stenum函数中使用，也可在printnum函数中使用
	       //该成员变量就可以看成类的全局变量
public:
	void setnum(int a)
	{
		_a = a;
		cout << &_a << endl;
	}
	void printnum()
	{
		cout << _a << endl;
		cout << &_a << endl;
	}
};
#if 0
void func()//如果你想输出全局变量的值，那么这个函数必须在全局变量的后面
{
	cout << b << endl;
}
#endif
int b = 20;//全局变量

void func()
{
	cout << b << endl;
}
int main()
{
	num a;
	a.setnum(10);
	a.printnum();
	func();
	cout << b << endl;
	return 0;
}