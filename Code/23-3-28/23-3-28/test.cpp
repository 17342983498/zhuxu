#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


//int fib(int n)
//{
//	int first = 0, second = 1;
//	while (n>second)
//	{
//		int sum = first + second;
//		first = second;
//		second = sum;
//	}
//	int min1 = n - first;
//	int min2 = second - n;
//	return min1<min2 ? min1 : min2;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	int ret = fib(n);
//	cout << ret << endl;
//}


//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间,还会调用构造函数和析构函数
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1);
//	free(p1);
//	delete p2;
//	cout << "_____________________" << endl;
//
//	// 内置类型是几乎是一样的
//	int* p3 = (int*)malloc(sizeof(int)); // C
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//	cout << "_____________________" << endl;
//
//	A* p5 = (A*)malloc(sizeof(A)* 10);
//	A* p6 = new A[10];
//	free(p5);
//	delete[] p6;
//	return 0;
//}


#include <string>
#include <vector>

int main()
{
	int n = 0;
	cin >> n;
	string s1, s2;
	int flag1 = 1, flag2 = 1;
	//s1 = "";
	for (int i = 0; i<=n; ++i)
	{
		getline(cin, s2);
		if (s1>s2)
		{
			flag1 = 0;
		}
		if (s1.size()>s2.size())
		{
			flag2 = 0;
		}
		s1 = s2;
	}

	if (flag1 == 1 && flag2 == 1)
	{
		cout << "both" << endl;
	}
	else if (flag1 == 1 && flag2 == 0)
	{
		cout << "lexicographically" << endl;
	}
	else if (flag2 == 1 && flag1 == 0)
	{
		cout << "length" << endl;
	}
	else
	{
		cout << "none" << endl;
	}
	return 0;
}




//int main()
//{
//	int n = 0, m = 0;
//	cin >> n >> m;
//	for (int i = m; i <= n*m; ++i)
//	{
//		if (i%n == 0 && i%m == 0)
//		{
//			cout << i << endl;
//			break;
//		}
//	}
//	return 0;
//}