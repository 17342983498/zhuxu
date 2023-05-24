#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>


//位图
template<size_t N>  //这个N表示我们要表示多少个数字
class bitset
{
public:
	bitset()
	{
		_bits.resize(N / 8 + 1, 0);
	}

	void set(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;
		_bits[i] |= (1 << j);
	}

	void reset(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;
		_bits[i] &= ~(1 << j);
	}

	bool test(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;
		return _bits[i] & (1 << j);
	}

private:
	vector<char> _bits;
};


//int main()
//{
//	bitset<100> bs;
//	bs.set(10);
//	bs.set(5);
//	bs.set(15);
//
//	cout << bs.test(5) << endl;
//	cout << bs.test(50) << endl;
//
//	bs.reset(5);
//	bs.set(50);
//	cout << bs.test(5) << endl;
//	cout << bs.test(50) << endl;
//	return 0;
//}



template<size_t N>
class twobitset
{
public:
	//void set(size_t x)
	//{
	//	//第一次出现
	//	if (_bs1.test(x) == false && _bs2.test(x) == false)
	//	{
	//		_bs1.set(x);
	//	}
	//	//第二次及以上出现
	//	else if (_bs1.test(x) == true && _bs2.test(x) == false)
	//	{
	//		_bs2.set(x);
	//	}
	//}

	void set(size_t x)
	{
		//第一次出现
		if (_bs1.test(x) == false && _bs2.test(x) == false)
		{
			_bs2.set(x);
		}
		//第二次出现
		else if (_bs1.test(x) == false && _bs2.test(x) == true)
		{
			_bs1.set(x);
			_bs2.reset(x);
		}
		else
		{
			_bs2.set(x);
		}
	}


	//void Print()
	//{
	//	for (size_t i = 0; i < N; ++i)
	//	{
	//		if (_bs1.test(i) == true && _bs2.test(i) == false)
	//		{
	//			cout << i << " ";
	//		}
	//	}
	//	cout << endl;
	//}

	void Print()
	{
		for (size_t i = 0; i < N; ++i)
		{
			if ((_bs1.test(i) == true && _bs2.test(i) == false)||
				(_bs2.test(i) == true && _bs1.test(i) == false))
			{
				cout << i << " ";
			}
		}
		cout << endl;
	}


private:
	bitset<N> _bs1;
	bitset<N> _bs2;
};


//int main()
//{
//	int a[] = { 3, 45, 53, 32, 32, 43, 3, 2, 5, 2, 32, 55, 5, 53, 43, 9, 8, 7, 8, 55 };
//	twobitset<100> bs;
//	for (auto e : a)
//	{
//		bs.set(e);
//	}
//
//	bs.Print();
//	return 0;
//}


//int main()
//{
//	int a1[] = { 3, 45, 26, 32, 25, 64, 3, 26 };
//	int a2[] = { 2, 45, 32, 65, 12, 4, 78, 3 };
//	bitset<100> bs1;
//	bitset<100> bs2;
//	for (auto e : a1)
//	{
//		bs1.set(e);
//	}
//	for (auto e : a2)
//	{
//		bs2.set(e);
//	}
//
//	for (size_t i = 0; i < 100; ++i)
//	{
//		if (bs1.test(i) && bs2.test(i))
//		{
//			cout << i << " ";
//		}
//	}
//	cout << endl;
//	return 0;
//}


int main()
{
	int a[] = { 3, 45, 63, 23, 45, 63, 78, 3, 23, 63, 45, 0 };
	twobitset<100> bs;
	for (auto e : a)
	{
		bs.set(e);
	}
	bs.Print();
	return 0;
}