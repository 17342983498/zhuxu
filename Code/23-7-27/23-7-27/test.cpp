#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <thread>

struct Goods
{
	string _name;
	double _price; 
	int _evaluate; 
	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};


//struct ComparePriceLess
//{
//	bool operator()(const Goods& g1, const Goods& g2)
//	{
//		return g1._price < g2._price;
//	}
//};
//
//
//struct ComparePriceGreater
//{
//	bool operator()(const Goods& g1, const Goods& g2)
//	{
//		return g1._price > g2._price;
//	}
//};
//
//
//int main()
//{
//	vector<Goods> v = {{ "苹果", 2.1, 5},{ "香蕉", 3, 4},{ "橙子", 2.2, 3},{"菠萝", 1.5, 4}};
//	sort(v.begin(), v.end(), ComparePriceLess());
//	for (auto& e: v)
//	{
//		cout << e._name << " ";
//	}
//	cout << endl;
//
//	sort(v.begin(), v.end(), ComparePriceGreater());
//	for (auto& e : v)
//	{
//		cout << e._name << " ";
//	}
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	auto add = [](int x, int y)->int{return x + y; };
//	cout << add(1, 2) << endl;
//	cout << [](int x, int y)->int{return x + y; }(2, 3) << endl;
//	return 0;
//}




//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
//
//	auto PriceGreater = [](const Goods& g1, const Goods& g2)->bool{return g1._price > g2._price; };
//	sort(v.begin(), v.end(), PriceGreater);
//	for (auto& e : v)
//	{
//		cout << e._name << " ";
//	}
//	cout << endl;
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)->bool{return g1._price < g2._price; });
//	for (auto& e : v)
//	{
//		cout << e._name << " ";
//	}
//	cout << endl;
//
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)->bool{return g1._evaluate > g2._evaluate; });
//	for (auto& e : v)
//	{
//		cout << e._name << " ";
//	}
//	cout << endl;
//	return 0;
//}



//int main()
//{
//	int a = 1, b = 2;
//	//auto swap = [](int& a, int& b)
//	//{
//	//	int x = a;
//	//	a = b;
//	//	b = x;
//	//};
//
//	//swap(a, b);
//	//cout << "a: " << a << " " << "b:" << b << endl;
//
//	//传值捕捉
//	//auto swap = [a, b]()mutable
//	//{
//	//	int x = a;
//	//	a = b;
//	//	b = x;
//	//};
//
//	//swap();
//	//cout << "a: " << a << " " << "b:" << b << endl;
//
//	//传引用捕捉
//	auto swap = [&a, &b]()mutable
//	{
//		int x = a;
//		a = b;
//		b = x;
//	};
//
//	swap();
//	cout << "a: " << a << " " << "b:" << b << endl;
//}


//int main()
//{
//	int a = 1, b = 2;
//	auto fun1 = [=,&b](int c){b = a + c; };
//	fun1(10);
//	cout << a << " " << b << endl;
//
//	//除了b都是传值
//	auto fun2 = [=, &b](int c)->int{return b += a + c; };
//	cout << fun2(10) << endl;
//	return 0;
//}


//void Func(int num, int n)
//{
//	while (n <= num)
//	{
//		cout << n++ << " ";
//	}
//	cout << endl;
//}
//
//
//int main()
//{
//	int a = 10, b = 20;
//	thread t1(Func, a, 1);
//	thread t2(Func, b, 1);
//	
//	t1.join();
//	t2.join();
//	return 0;
//}


//int main()
//{
//	int n1 = 10 , n2 = 20;
//
//	thread t1([n1](int num)
//		{
//			for (int i = 0; i < n1; i++)
//			{
//				cout <<num<<":" << i << endl;
//			}
//			cout << endl;
//		}, 1);
//
//	thread t2([n2](int num)
//		{
//			for (int i = 0; i < n2; i++)
//			{
//				cout << num << ":" << i << endl;
//			}
//			cout << endl;
//		}, 2);
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}


//int main()
//{
//	size_t m;
//	cin >> m;
//	vector<thread> vthds(m);
//	for (size_t i = 0; i < m; ++i)
//	{
//		size_t n;
//		cin >> n;
//		vthds[i] = thread([i, n, m](){
//			for (int j = 0; j < n; j++)
//			{
//				cout << i << " " << j << endl;
//			}
//			cout << endl;
//		});
//	}
//	for (auto& vt : vthds)
//	{
//		vt.join();
//	}
//	return 0;
//}



class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}

	double operator()(double money, int year)
	{
		return money * _rate * year;
	}

private:
	double _rate;
};



int main()
{
	double rate = 0.01999;
	Rate r1(rate);
	cout << r1(10000, 5) << endl;;
	return 0;

	auto r2 = [=](double money, int year)->double{return money * rate * year; };
	r2(10000, 5);
}