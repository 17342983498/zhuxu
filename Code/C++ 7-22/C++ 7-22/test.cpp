#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include<string>
//int sum = 0;
//int Add(int a, int b)
//{
//	sum = a + b;
//	return sum;
//}
//int main()
//{
//	int sum = Add(1, 2);
//	cout << sum << endl;
//	Add(3, 4);
//	cout << sum << endl;
//	Add(5, 6);
//	cout << sum << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	cout << sizeof(a) << endl;//4
//	cout << sizeof(ra) << endl;//4 说明 int& a的类型仍然是int
//	return 0;
//}

#include<ctime>
struct stu
{
	int array[100000];
};
void test1(stu a)
{

}
void test2(stu& a)
{

}
void test3(stu* a)
{

}
void Func()
{
	stu a;
	size_t begin1 = clock();
	for (int i = 0; i < 10000; i++)
	{
		test1(a);
	}
	size_t end1 = clock();
	size_t begin2 = clock();
	for (int i = 0; i < 10000; i++)
	{
		test2(a);
	}
	size_t end2 = clock();
	size_t begin3 = clock();
	for (int i = 0; i < 10000; i++)
	{
		test3(&a);
	}
	size_t end3 = clock();
	cout << "传值性能 " << end1 - begin1 << endl;
	cout << "传引用性能 " << end2 - begin2 << endl;
	cout << "传址性能 " << end3 - begin3 << endl;
}
int main()
{
	Func();
	return 0;
}