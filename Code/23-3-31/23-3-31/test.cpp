#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


//// 专门处理int的加法函数
//
//int Add(int left, int right)
//{
//	cout << "1" << endl;
//	return left + right;
//}
//
//
//// 通用加法函数
//
//template<class T>
//
//T Add(T left, T right)
//{
//	cout << "2" << endl;
//	return left + right;
//}
//
//
//
//int main()
//{
//	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2);
//	Add(1, 2.0);
//	int a = 0;
//	double b = 1;
//	Add<int>(a, b);
//	return 0;
//}



//int Add(int left, int right)
//{
//	cout << "0" << endl;
//	return left + right;
//}
//
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	cout << "1" << endl;
//	return left + right;
//}
//
//int main()
//{
//	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//	//Add<int,int>(1, 2.0);
//	return 0;
//}





int main()
{
	int n = 0;
	cin >> n;
	int flag = 1;
	int count = 0, maxcount = 0;
	for (int i = 0; i<32; i++)
	{
		if ((n >> i & 1) == 1)
		{
			count++;
		}
		else
		{
			if (count>maxcount)
			{
				maxcount = count;
			}
			count = 0;
		}
	}
	if (count>maxcount)
	{
		maxcount = count;
	}
	cout << maxcount << endl;
	return 0;
}