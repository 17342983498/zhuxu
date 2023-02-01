#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


//int main()
//{
//	int a = 10;
//	int& aa = a;
//	cout << a << " " << aa << endl;
//	cout << &a <<" "<<&aa << endl;
//
//	aa = 20;
//	cout << a << " " << aa << endl;
//	cout << &a << " " << &aa << endl;
//
//	a = 30;
//	cout << a << " " << aa << endl;
//	cout << &a << " " << &aa << endl;
//
//	//int b = 1;
//	//int& aa = b;
//	return 0;
//}


#include <time.h>
//struct A{ int a[10000]; };
//void TestFunc1(A a){}
//void TestFunc2(A& a){}
//void TestRefAndValue()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//	TestRefAndValue();
//	return 0;
//}


struct A{ int a[10000]; };
A a;
// ֵ����
A TestFunc1() { return a; }
// ���÷���
A& TestFunc2(){ return a; }
void TestReturnByRefOrValue()
{
	// ��ֵ��Ϊ�����ķ���ֵ����
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();
	// ��������Ϊ�����ķ���ֵ����
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();
	// �������������������֮���ʱ��
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}

int main()
{
	TestReturnByRefOrValue();
	return 0;
}