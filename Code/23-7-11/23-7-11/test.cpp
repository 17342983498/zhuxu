#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


//int main()
//{
//	int a = 10;
//	double b = a;
//	printf("%d %f\n", a, b);
//
//	int *p = &a;
//	int addres = (int)p;
//	printf("%p %d\n", p, addres);
//	return 0;
//}

//C++ǿ������ת��
//static_cast----�൱��C�����е���ʽ����ת��������������ͣ�

//int main()
//{
//	double a = 3.14;
//	int b = static_cast<int>(a);
//	cout << b << endl;
//	return 0;
//}

//reinterpret_cast
//int main()
//{
//	int a = 10;
//	//int *p = static_cast<int*>(a);
//	int *p = reinterpret_cast<int*>(a);
//	cout << p << endl;
//	return 0;
//}


//const_cast
//int main()
//{
//	//volatile const int a = 2;
//	volatile const int a = 2;
//	int *p = (int*)&a;
//	//int *p = const_cast<int*>(&a);
//	*p = 3;
//	cout << a << " " << *p << endl;
//	return 0;
//}
//����a���޸��ˣ����Ǵ�ӡ�Ľ�������޸�֮ǰ��ֵ��������Ϊa��const���Σ�ϵͳ��Ϊ���ǲ��ܱ��޸�
//���Ǳ������ͻ�����Ż������ܽ�a��ֵ���뵽�Ĵ����ж������ڴ���ȥ��a��ֵ
//VS���Ż���ֱ���滻��
//volatile�������Ż�


//dynamic_cast
class A
{
public:

	virtual void f(){}
};

class B : public A
{};

void fun(A* pa)
{
	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
	/*B* pb1 = static_cast<B*>(pa);*/
	B* pb1 = (B*)pa;
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl << endl;
}


//void fun(B* pb)
//{
//	B* pb1 = (B*)pb;
//	B* pb2 = dynamic_cast<B*>(pb);
//	cout << "pb1:" << pb1 << endl;
//	cout << "pb2:" << pb2 << endl << endl;
//}

//int main()
//{
//	A a;
//	B b;
//	//fun(&a);
//	fun(&b);
//	return 0;
//}


int main()
{
	clog << "dfsdfds" << endl;
}