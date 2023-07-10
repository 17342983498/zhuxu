#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//int count = 0;

//class A
//{
//public:
//	A()
//	{
//		_count++;
//	}
//	A(const A& t)
//	{
//		_count++;
//	}
//
//	static int Getcount()
//	{
//		return _count;
//	}
//private:
//
//	static int _count;
//	int _a;
//};
//
//int A::_count = 0;
//
//int main()
//{
//	A a1;
//	A a2(a1);
//	A a3 = a2;
//	cout << A::Getcount() << endl;
//	cout << a1.Getcount() << endl;
//	cout << a2.Getcount() << endl;
//	cout << a3.Getcount() << endl;
//	return 0;
//
//}


//class A
//{
//private:
//	static int k;
//	int h = 0;
//
//public:
//	class B // B就是A的友元
//	{
//	public:
//		void func(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a.h << endl;//OK
//		}
//	};
//};
//int A::k = 1;
//int main()
//{
//	A::B b;
//	b.func(A());
//	return 0;
//}


//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//private:
//	int _a;
//};
//class Solution
//{
//public:
//	int Sum_Solution(int n)
//	{
//		//...
//		cout << "Sum_Solution(int n)" << endl;
//		return n;
//	}
//};
//
//int main()
//{
//	A aa1;
//	// 不能这么定义对象，因为编译器无法识别下面是一个函数声明，还是对象定义
//	//A aa1();
//	// 但是我们可以这么定义匿名对象，匿名对象的特点不用取名字，
//	// 但是他的生命周期只有这一行，我们可以看到下一行他就会自动调用析构函数
//
//	A();
//	A aa2(2);
//	// 匿名对象在这样场景下就很好用，当然还有一些其他使用场景，这个我们以后遇到了再说
//
//	Solution().Sum_Solution(10);
//	return 0;
//}








class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

void func1(A aa)
{}


void func2(const A& aa)
{}

A func3()
{
	A aa;
	return aa;
}

A func4()
{
	return A();
}
int main()
{
	A a1 = 1;//构造+拷贝构造--->构造
	func1(a1);//拷贝构造
	func1(1);//构造+拷贝构造--->构造
	func1(A(1));//构造+拷贝构造--->构造

	func2(a1);//无优化  
	func2(1);//无优化  构造
	func2(A(1));//无优化  构造

	func3();//无优化
	A a2 = func3();//构造+拷贝构造+拷贝构造--->构造+拷贝构造

	func4();//构造+拷贝构造--->构造
	A a3 = func4();//构造+拷贝构造+拷贝构造--->构造+拷贝构造
}





//int main()
//{
//	func3();//无忧化
//	A a2 = func3();//构造+拷贝构造+拷贝构造--->构造+拷贝构造
//}

//int main()
//{
//
//	func4();//构造+拷贝构造--->构造
//	A a3 = func4();//构造+拷贝构造+拷贝构造--->构造+拷贝构造
//
//	return 0;
//}
