#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

void TestFunc(int a)
{
	cout << "TestFunc(int a)" << endl;
}
void TestFunc(int *a)
{
	cout << "TestFunc(int *a)" << endl;
}
int main()
{
	TestFunc(0);//�����ϻ�������ε�TestFunc����
	TestFunc(NULL);//�����ϻ����ָ�����͵�TestFunc����������ʵ���ϻ�������ε�TestFunc����
	               //ԭ�����������ط��������NULL����һ���궨�壬��#define NULL 0��
	TestFunc(nullptr);//��ʹ�ÿ�ָ��ʱ���Ϳ���ʹ��nullptr.
	return 0;
}