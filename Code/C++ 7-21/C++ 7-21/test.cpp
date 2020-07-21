#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
 
//void swap(int *a, int *b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int& ra = a;
//	int& rb = b;
//	swap(a,b);
//	cout << a << " " << b << endl;
//	swap(ra, rb);
//	cout << ra << " " << rb << endl;
//	return 0;
//}

#if 0
int Add(int left, int right);//int __cdecl Add(int,int)" (?Add@@YAHHH@Z)
int main()
{
	Add(1, 2);
	return 0;
}
#endif
#if 0
extern "C" int Add(int left, int right);// _Add
int main()
{
	Add(1, 2);
	return 0;
}
#endif

//全缺省参数与无参的只能存在一个
//void TestFunc(int a ) 
//{
//	cout << "void TestFunc(int)" << endl;
//}
//void TestFunc() 
//{
//	cout << "void TestFunc(int)" << endl;
//}
//int main()
//{
//	TestFunc();
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	cout << a << endl;
//	int& ra = a;
//	ra = 20;
//	cout << "a="<< a << ' ' << "ra=" << ra << endl;
//	a = 30;
//	cout << "a=" << a << ' ' << "ra=" << ra << endl;
//	return 0;
//}


void SetNullPtr1(int** p)
{
	//*p就是实参本身
	*p = NULL;
}
void SetNullPtr2(int*& p)//通过“引用”，我们用一级指针就可实现
{
	p = NULL;
}

//通过SetNullPtr函数将pa指针指向空 ，需要在SetNullPtr函数中改变pa指针的指向
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	SetNullPtr1(&pa);//需要一个二级指针
//	SetNullPtr2(pa);
//	return 0;
//}
//
//int main()
//{
//	double a = 12.34;
//	const int& ra = a;
//	cout << &a <<" "<< &ra << endl;//地址不一样
//	return 0;
//}