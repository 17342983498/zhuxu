#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//int main()
//{
//	//int a;
//	//char a;
//	double a;
//	cin >> a;
//	cout << a << endl;
//	return 0;
//}


//void Test(int a,int b,int c = 3)
//{
//	cout << a <<" "<< b <<" "<<c << endl;
//}
//
//
//
//int main()
//{
//	//��������֮��Ĳ�����Ӧһ��Ҫ�Ǻϣ����ܳ���ĳ������û��ֵ����Ȼĳ������ֵ�غ���Ҳ���ԣ����ǻ��ñ����ú����Ĳ�����
//	//Test();
//	Test(10,20);
//	Test(10,20,30);
//	return 0;
//}


void add(int a,int b)
{
	cout << a + b << endl;
}

void add(double a, double b)
{
	cout << a + b << endl;
}

void add(int a, double b)
{
	cout << a + b << endl;
}

int main()
{
	add(1, 2.0);
	add(1, (int)2.0);
	return 0;
}