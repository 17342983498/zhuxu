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
//	class B // B����A����Ԫ
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
//	// ������ô���������Ϊ�������޷�ʶ��������һ���������������Ƕ�����
//	//A aa1();
//	// �������ǿ�����ô����������������������ص㲻��ȡ���֣�
//	// ����������������ֻ����һ�У����ǿ��Կ�����һ�����ͻ��Զ�������������
//
//	A();
//	A aa2(2);
//	// �������������������¾ͺܺ��ã���Ȼ����һЩ����ʹ�ó�������������Ժ���������˵
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
	A a1 = 1;//����+��������--->����
	func1(a1);//��������
	func1(1);//����+��������--->����
	func1(A(1));//����+��������--->����

	func2(a1);//���Ż�  
	func2(1);//���Ż�  ����
	func2(A(1));//���Ż�  ����

	func3();//���Ż�
	A a2 = func3();//����+��������+��������--->����+��������

	func4();//����+��������--->����
	A a3 = func4();//����+��������+��������--->����+��������
}





//int main()
//{
//	func3();//���ǻ�
//	A a2 = func3();//����+��������+��������--->����+��������
//}

//int main()
//{
//
//	func4();//����+��������--->����
//	A a3 = func4();//����+��������+��������--->����+��������
//
//	return 0;
//}
