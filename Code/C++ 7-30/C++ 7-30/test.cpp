#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

void TestFunc(int a)
{
	cout << "TestFunc(int a)" << endl;
}
void TestFunc(int *a)
{
	cout << "TestFunc(int *a)" << endl;
}
int main()
{
	TestFunc(0);//理论上会调用整形的TestFunc函数
	TestFunc(NULL);//理论上会调用指针类型的TestFunc函数，但是实际上会调用整形的TestFunc函数
	               //原因就是在这个地方，它会把NULL当成一个宏定义，“#define NULL 0”
	TestFunc(nullptr);//想使用空指针时，就可以使用nullptr.
	return 0;
}