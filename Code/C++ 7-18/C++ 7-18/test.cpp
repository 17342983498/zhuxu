#define _CRT_SECURE_NO_WARNINGS 1



              //N1��һ�������ռ�
              //a��Add�������ռ��е�������Ա
namespace N1
{
	int a = 10;
	int Add(int left, int right)
	{
		return left + right;
	}
		
}
namespace N1
{
	int b = 0;
	int Div(int left, int right)
	{
		return left / right;
	}
}

            //�����ռ��Ƕ��
namespace N2
{
	namespace N3
	{
		int a = 40;
		int Sub(int left, int right)
		{
			return left - right;
		}
	}
}
//int a = 20;
//int main()
//{
//	int a = 30; 
//	printf("%d\n", a);//30
//	printf("%d\n", N1::a);//10 ������>�����������
//	printf("%d\n", ::a);//20
//	int sum = N1::Add(10, 20);
//	printf("%d\n", sum);//30
//	printf("%d\n", N2::N3::a);//40
//	int dif = N2::N3::Sub(20,10);
//	printf("%d\n", dif);//10
//	printf("%d\n", N1::b);
//	int div = N1::Div(300, 10);
//	printf("%d\n", div);//30
//	return 0;
//}

//---------------------------------------------------------------------------------

                      //ʹ��using�������ռ��г�Ա����
                      //using N1::a  --->�˷����൱�ڽ������ռ��е�a�����ȫ�ֱ���a
                      //��ʹ�ô˷���ʱ����������ͬ��ȫ�ֱ���������ͻ��ͻ
//using N1::a;
//int main()
//{
//	printf("%d\n", a);
//	return 0;
//}

//--------------------------------------------------------------------------
//int a = 10;
//int main()
//{
//	printf("%d\n", a);//10
//	return 0;
//}

//--------------------------------------------------------------------------
                
                         //ʹ��using namespace �����ռ���������
                         //�����ռ��е����г�Ա����ֱ��ʹ�ã����г�Ա���ȫ�ֱ�����
//using namespace N1;
//
//int main()
//{
//	printf("%d\n", N1::a);
//	printf("%d\n", a);
//	int sum = Add(10, 20);
//	printf("%d\n", sum);
//	return 0;
//}
//----------------------------------------



#include <iostream>
using namespace std;

#if 0
int main()
{
	//���
	cout << "hello, world!"<< endl;
	cout << "��" << "��" << "��" << endl;
	return 0;
}
#endif

//int main()
//{
//	int a;
//	char b;
//	float c;
//	cin >> a;
//	cout << a << endl;
//	cin >> b;
//	cout << b << endl;
//	cin >> c;
//	cout << c << endl;
//	return 0;
//}


//C++���������ں������������Լ�����ֵ���ͼ���Ϊ�ϸ�
void test1()
{
	cout << "�Ұ��㣡" << endl;
}
int test2(int a)
{
	return a / 2;
}
int main()
{
	int a;
	test1();
	cin >> a;
	int b = test2(a);
	cout << b << endl;
	return 0;
}