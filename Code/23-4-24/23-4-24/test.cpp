#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

// set  -- key
// map  -- key/value

void test_set1()
{
	set<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(2);

	set<int>::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		// 搜索树不允许修改key，可能会破坏搜索的规则
		//*it1 += 1;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	// 范围for
	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set2()
{
	// 排序 + 去重
	set<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(2);

	int x;
	while (cin >> x)
	{
	/*	auto ret = s1.find(x);
		if (ret != s1.end())
		{
			cout << "在" << endl;
		}
		else
		{
			cout << "不在" << endl;
		}*/

		
		if (s1.count(x))
		{
			cout << "在" << endl;
		}
		else
		{
			cout << "不在" << endl;
		}
	}
}
//
//template <class T1, class T2>
//struct pair
//{
//	typedef T1 first_type;
//	typedef T2 second_type;
//
//	T1 first;
//	T2 second;
//	pair() : first(T1()), second(T2())
//	{}
//
//	pair(const T1& a, const T2& b) : first(a), second(b)
//	{}
//};

void test_set3()
{
	// 排序
	multiset<int> s1;
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(1);
	s1.insert(1);
	s1.insert(1);
	s1.insert(2);

	multiset<int>::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		// 搜索树不允许修改key，可能会破坏搜索的规则
		//*it1 += 1;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	// 多个key，find中序的第一个key
	auto ret = s1.find(1);
	while (ret != s1.end() && *ret == 1)
	{
		cout << *ret << " ";
		++ret;
	}
	cout << endl;

	cout << s1.count(1) << endl;
	cout << s1.count(2) << endl;
}

void test_map1()
{
	map<string, string> dict;
	//dict.insert(pair<string, string>("sort", "排序"));
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("string", "字符串"));
	dict.insert(make_pair("count", "计数"));

	//map<string, string>::iterator dit = dict.begin();
	auto dit = dict.begin();
	while (dit != dict.end())
	{
		cout << (*dit).first << ":" << (*dit).second << endl;
		++dit;
	}
	cout << endl;
}

void test_map2()
{
	// 21:00继续
	map<string, string> dict;
	//dict.insert(pair<string, string>("sort", "排序"));
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("string", "字符串"));
	dict.insert(make_pair("count", "计数"));
	dict.insert(make_pair("string", "(字符串)")); // 插入失败

	dict["left"];			// 插入
	dict["right"] = "右边"; // 插入+修改
	dict["string"] = "(字符串)"; // 修改
	cout << dict["string"] << endl; // 查找
	cout << dict["string"] << endl; // 查找


	//map<string, string>::iterator dit = dict.begin();
	auto dit = dict.begin();
	while (dit != dict.end())
	{
		//cout << (*dit).first << ":" << (*dit).second << endl;
		cout << dit->first << ":" << dit->second << endl;

		++dit;
	}
	cout << endl;
}

void test_map3()
{
	string arr[] = { "西瓜", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉", "梨" };
	map<string, int> countMap;
	//for (auto& e : arr)
	//{
	//	auto ret = countMap.find(e);
	//	if (ret == countMap.end())
	//	{
	//		countMap.insert(make_pair(e, 1));
	//	}
	//	else
	//	{
	//		ret->second++;
	//	}
	//}

	for (auto& e : arr)
	{
		countMap[e]++;
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}

//V& operator[](const K& key)
//{
//	pair<iterator, bool> ret = insert(make_pair(key, V()));
//	return ret.first->second;
//}

//int main()
//{
//	//test_set3();
//	test_map2();
//
//	return 0;
//}

int main()
{
	map<string, string> dict;
	//dict.insert(pair<string, string>("sort", "排序"));
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("string", "字符串"));
	dict.insert(make_pair("count", "计数"));
	dict.insert(make_pair("string", "(字符串)")); // 插入失败

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	multimap<string, string> mdict;
	//dict.insert(pair<string, string>("sort", "排序"));
	mdict.insert(make_pair("sort", "排序"));
	mdict.insert(make_pair("string", "字符串"));
	mdict.insert(make_pair("count", "计数"));
	mdict.insert(make_pair("string", "(字符串)")); // 插入失败
	mdict.insert(make_pair("string", "字符串"));

	for (auto& kv : mdict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}

	return 0;
}