#define _CRT_SECURE_NO_WARNINGS 1



              //N1是一个命名空间
              //a和Add是命名空间中的两个成员
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

            //命名空间的嵌套
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
//	printf("%d\n", N1::a);//10 ：：—>作用域运算符
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

                      //使用using将命名空间中成员引入
                      //using N1::a  --->此方法相当于将命名空间中的a变成了全局变量a
                      //在使用此方法时，不能有相同的全局变量，否则就会冲突
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
                
                         //使用using namespace 命名空间名称引入
                         //命名空间中的所有成员都可直接使用（所有成员变成全局变量）
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
	//输出
	cout << "hello, world!"<< endl;
	cout << "我" << "爱" << "你" << endl;
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


//C++编译器对于函数参数类型以及返回值类型检测更为严格
void test1()
{
	cout << "我爱你！" << endl;
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