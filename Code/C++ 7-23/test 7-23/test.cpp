#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//int main()
//{
//	auto a = 10;
//	auto b = "abcd";                               //autoֻ��һ��ռλ���������Ƕ�������
//	auto c = 'c';                                  //�ڱ���ʱ�����ڱ���׶Σ���������ͨ�����ݵõ�ÿ�������Ķ������ͣ��ô����滻auto
//	auto d = 10.03;                                
//	auto e = a + 10;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(e).name() << endl;
//	return 0;
//}

#if 0
int main()
{                       //��ʹ��auto�������ʱ������Ա�����ʼ������Ϊ�ڱ���׶���Ҫ�Ա����������ݵõ��ñ����Ķ�������
	auto e;
	return 0;
}
#endif

//int main()
//{
//	auto a = 10;//�ڶ���ָ�����ʱ���Ӳ���*������ν
//	auto ra = &a;        //  auto   ->   int*
//	auto *rra = &a;      //  auto   ->   int
//	cout << typeid(ra).name() << endl;
//	cout << typeid(rra).name() << endl;
//}


int main()
{
	auto a = 10;
	auto& ra = a;//�� ra ���� a
	auto rra = a;//��������� rra ���� a����ֻ�Ƕ�����һ��rra�ı������ñ���ʹ�� a �����г�ʼ������a��ͬ���͵�
	//cout << typeid(a).name() << endl;
	//cout << typeid(ra).name() << endl;
	//cout << typeid(rra).name() << endl;
	cout << &a << endl;     //006FFCE8
	
	cout << &ra << endl;    //006FFCE8
	
	cout << &rra << endl;	//006FFCD0
	//���������ַ���Կ�������ʹ��auto�����������ͱ���ʱ��auto���������� &
}