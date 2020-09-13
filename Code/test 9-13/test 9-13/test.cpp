#define _CRT_SECURE_NO_WARNINGS 1

//#include <time.h>
#include<iostream>
using namespace std;
#if 0
struct A
{ 
	int a[10000];
};

// 值返回
void TestFunc1(A a) 
{}
// 引用返回
void TestFunc2(A& a)
{}
void TestFunc3(A* a)
{}
void TestReturnByRefOrValue()
{
	A a;
	// 以值作为函数的返回值类型
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1(a);
	size_t end1 = clock();
	// 以引用作为函数的返回值类型
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2(a);
	size_t end2 = clock();
	size_t begin3 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc3(&a);
	size_t end3 = clock();
	// 计算两个函数运算完成之后的时间
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
	cout << "TestFunc3 time:" << end3 - begin3 << endl;
}
int main()
{
	int a = 10;
	int& ra = a;
	//cout << "&a = " << &a << endl;
	//cout << "&ra = " << &ra << endl;
	TestReturnByRefOrValue();
	return 0;
}
#endif
#if 0
int main()
{
	int a = 10;
	int& ra = a;

	cout << "&a = " << &a << endl;
	cout << "&ra = " << &ra << endl;
	return 0;
}
#endif

//int main()
//{
//	const double a = 10.21;
//	const int& ra = a;
//	ra = 20.30;
//	cout << a << " "<<ra << endl;
//	return 0;
//}

int main()
{
	int a = 10;

	int& ra = a;
	ra = 20;

	int* pa = &a;
	*pa = 20;

	return 0;
}