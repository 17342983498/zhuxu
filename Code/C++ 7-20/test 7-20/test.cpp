#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
int Print(int a = 20)//�˴���a���൱��һ����̥������ֵ�ÿ�ԭ������ߴ治���ڲ�����
{
	return a;
}
int main()
{
	//int sum = Print(10);   
	//cout << sum << endl;    
	int sum = Print();
	cout << sum << endl;
	return 0;
}
#endif

#if 0
//ȫȱʡ����
void Test(int a = 10, int b = 20, int c = 30)
{
	cout << a <<' '<< b <<' '<< c << endl;

}
int main()
{
	Test();//10 20 30
	Test(1);// 1 20 30
	Test(1, 2);//1 2 30
	return 0;
}
#endif

#if 0
//��ȱʡ����
void Test(int a, int b = 20, int c = 30)
{
	cout <<" a = "<< a << endl;
	cout <<" b = "<< b << endl;
	cout <<" c = "<< c << endl;
}
int main()
{
	Test(1);
	return 0;
}
#endif

#if 0
void Test(int a = 10);
void Test(int a = 20) //���ַ��������У�ȱʡ��������ͬʱ�ں��������Ͷ����д��ڣ���Ϊ��������֪����ʹ���ĸ�ȱʡֵ��
{
	cout << a << endl;
}
int main()
{
	Test();
	return 0;
}
#endif

#if 0
int a = 10;
void Test(int a)//ȱʡֵ�����ǳ�������ȫ�ֱ���
{
	cout << a << endl;
}
int main()
{
	Test(a);
	return 0;
}
#endif
//------------------------------------------------------------------------------------------
//                                   ��������

//int Add(int left, int right)
//{
//	return (left + right);
//}
//double Add(double left, double right)//-----------------------------�������أ����������������ͬ����������ͬ�������б���벻��ͬ���������������ͣ�˳��
//{
//	return (left + right);
//}
//char Add(char left, char right)
//{
//	return (left + right);
//}
//float Add(float left, float right)
//{
//	return (left + right);
//}
//int main()
//{
//	int sum1 = Add(1, 2);
//	cout << sum1 << endl;
//	double sum2 = Add(10.0, 20.0);
//	cout << sum2 << endl;
//	char sum3 = Add('1', '2');
//	cout << sum3 << endl;
//	float sum4 = Add(1.0, 2.0);
//	cout << sum4 << endl;
//    return 0;
//}

#if 0
// --------------------------------  ��������
int Test(int a)
{

}

int Test()
{

}

// --------------------------------  ��������
int Test(int a)
{

}

int Test(char a)
{

}

// ---------------------------------  ����˳��
int Test(int a, double b)
{

}

int Test(double a, int b)
{

}
#endif