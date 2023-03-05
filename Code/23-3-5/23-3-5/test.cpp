#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print()
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main()
//{
//	A a(1);
//	a.Print();
//}


//class A
//{
//public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	~A() { --_scount; }
//	static int GetACount() { return _scount; }
//
//private:
//	static int _scount;
//};
//
//int A::_scount = 0;
//
//int main()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//}




// 单参数的构造函数
class A
{
public:
	A(int a)
		:_a1(a)
	{
		cout << "A(int a)" << endl;
	}

	//explicit A(int a1, int a2)
	A(int a1, int a2)
		:_a1(a1)
		, _a2(a2)
	{}

	A(const A& aa)
		:_a1(aa._a1)
	{
		cout << "A(const A& aa)" << endl;
	}

private:
	int _a2;
	int _a1;
};

int main()
{
	// 单参数构造函数 C++98
	A aa1(1);  // 构造函数
	A aa2 = 1; // 隐式类型转换   构造+拷贝(优化)->构造
	//const A& ref = 10;


	// 多参数构造函数 C++11
	A aa3(1, 1);
	A aa4 = { 2, 2 };
	const A &ref = { 2, 2 };

	return 0;
}