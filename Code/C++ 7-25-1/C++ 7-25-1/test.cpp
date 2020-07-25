#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//int main()
//{
//	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	for (auto e : array)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	for (auto& e : array)
//	{
//		e *= 2;
//	}
//	cout << endl;
//	for (auto& e : array)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	for (auto e : array)
//	{
//		e *= 2;
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}


void Test(int array[10])
{
	for (auto e : array)//在使用此方法时，我们必须知道这个for循环的循环迭代的范围
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Test(array);
	return 0;
}