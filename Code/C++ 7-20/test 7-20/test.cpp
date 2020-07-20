#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
int Print(int a = 20)//此处的a就相当于一个备胎，返回值得看原函数里边存不存在参数。
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
//全缺省参数
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
//半缺省参数
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
void Test(int a = 20) //这种方法不可行，缺省参数不能同时在函数声明和定义中存在，因为编译器不知道该使用哪个缺省值。
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
void Test(int a)//缺省值必须是常量或者全局变量
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
//                                   函数重载

//int Add(int left, int right)
//{
//	return (left + right);
//}
//double Add(double left, double right)//-----------------------------函数重载：多个函数作用域相同，函数名相同，参数列表必须不相同（参数个数，类型，顺序）
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
// --------------------------------  参数个数
int Test(int a)
{

}

int Test()
{

}

// --------------------------------  参数类型
int Test(int a)
{

}

int Test(char a)
{

}

// ---------------------------------  参数顺序
int Test(int a, double b)
{

}

int Test(double a, int b)
{

}
#endif