#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>


void TestVector1()
{
	vector<int> v1;  //无参构造，参数类型为 int
	vector<int> v2(5, 10);  //构造v2,存放5个10
	vector<int> v3(v2); //通过v2拷贝构造v3
	vector<int> v4(v2.begin(),v2.end());  //使用迭代器构造
}



void TestVector2()
{
	vector<int> v(5,10);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


void TestVector3()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl << endl;

	v.resize(15);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl << endl;

	v.resize(5);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl << endl;

	v.resize(8, 100);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

//reserve
void TestVector4()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);

	//cout << v.size() << endl;
	//cout << v.capacity() << endl << endl;

	//v.reserve(16);
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//cout << v.size() << endl;
	//cout << v.capacity() << endl << endl;

	//v.reserve(5);
	//cout << v.size() << endl;
	//cout << v.capacity() << endl << endl;


	v.assign(100, 8);
	for (auto e : v)
	{
		cout << e << " ";
	}
}

#include <time.h>

// 测试vector的默认扩容机制
// vs：按照1.5倍方式扩容
// linux：按照2倍方式扩容
void TestVectorExpand()
{
	size_t begin = clock();
	size_t sz;
	vector<int> v;
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
	size_t end = clock();
	cout << end - begin << endl;
}

void TestVector5()
{
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.pop_back();
	v.pop_back();
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestVector6()
{
	// 使用列表方式初始化，C++11新语法
	vector<int> v{ 1, 2, 3, 4 };

	// 在指定位置前插入值为val的元素，比如：3之前插入30,如果没有则不插入
	// 1. 先使用find查找3所在位置
	// 注意：vector没有提供find方法，如果要查找只能使用STL提供的全局find
	auto pos = find(v.begin(), v.end(), 3);
	if (pos != v.end())
	{
		// 2. 在pos位置之前插入30
		v.insert(pos, 30);
	}

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	pos = find(v.begin(), v.end(), 30);
	// 删除pos位置的数据
	v.erase(pos);

	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


// operator[]+index 和 C++11中vector的新式for+auto的遍历
// vector使用这两种遍历方式是比较便捷的。
void TestVector7()
{
	vector<int> v{ 1, 2, 3, 4 };

	// 通过[]读写第0个位置。
	v[0] = 10;
	cout << v[0] << endl;

	// 1. 使用for+[]小标方式遍历
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	vector<int> swapv;
	swapv.swap(v);

	cout << "v data:";
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	// 2. 使用迭代器遍历
	cout << "swapv data:";
	auto it = swapv.begin();
	while (it != swapv.end())
	{
		cout << *it << " ";
		++it;
	}

	// 3. 使用范围for遍历
	for (auto x : v)
		cout << x << " ";
	cout << endl;
}



void TestVector8()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6 };

	auto it = v.begin();

	// 将有效元素个数增加到100个，多出的位置使用8填充，操作期间底层会扩容

	// v.resize(100, 8);


	// reserve的作用就是改变扩容大小但不改变有效元素个数，操作期间可能会引起底层容量改变

	// v.reserve(100);


	// 插入元素期间，可能会引起扩容，而导致原空间被释放

	// v.insert(v.begin(), 0);

	// v.push_back(8);


	// 给vector重新赋值，可能会引起底层容量改变

	v.assign(100, 8);

	/*

	出错原因：以上操作，都有可能会导致vector扩容，也就是说vector底层原理旧空间被释放掉，
	而在打印时，it还使用的是释放之间的旧空间，在对it迭代器操作时，实际操作的是一块已经被释放的
	空间，而引起代码运行时崩溃。

	解决方式：在以上操作完成之后，如果想要继续通过迭代器操作vector中的元素，只需给it重新
	赋值即可。

	*/

	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


void TestVector9()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	// 使用find查找3所在位置的iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	// 删除pos位置的数据，导致pos迭代器失效。
	v.erase(pos);
	cout << *pos << endl; // 此处会导致非法访问

}


void TestVector10()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			v.erase(it);
//		else
		++it;
	}
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}



int main()
{
	TestVector10();
	//TestVectorExpand();
}