#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

#include "test.h"

//class A
//{
//public:
//	virtual A()
//	{}
//
//	virtual A(const A& aa)
//	{}
//
//	virtual A& operator=(const A& aa)
//	{
//		return *this;
//	}
//
//	inline virtual void func1()
//	{
//
//	}
//
//	// ±¨´í
//	/*static virtual void func2()
//	{}*/
//};
//
//int main()
//{
//	A aa;
//	aa.func1();
//
//	return 0;
//}

//class A
//{
//public:
//	virtual void func1()
//	{
//		cout << "A::func1" << endl;
//	}
//
//	void func2()
//	{
//		cout << "func2" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	virtual void func1()
//	{
//		cout << "B::func1" << endl;
//	}
//
//	void func2()
//	{
//		cout << "func2" << endl;
//	}
//};
//
//int main()
//{
//	A aa;
//	aa.func1();
//	aa.func2();
//
//	// ¶àÌ¬µ÷ÓÃ  -- È¥Ðé±íÖÐÕÒÐéº¯ÊýµØÖ·
//	A* ptr = &aa;
//	ptr->func1();
//
//	ptr = new B;
//	ptr->func1();
//
//	return 0;
//}

void TestBSTree1()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	key::BSTree<int> t1;

	for (auto e : a)
	{
		t1.Insert(e);
	}

	//t1.InOrder(t1.GetRoot());
	t1.InOrder();

	/*t1.Erase(4);
	t1.InOrder();

	t1.Erase(14);
	t1.InOrder();

	t1.Erase(3);
	t1.InOrder();*/

	t1.Erase(8);
	t1.InOrder();


	for (auto e : a)
	{
		t1.Erase(e);
		t1.InOrder();
	}

	t1.InOrder();
}

void TestBSTree2()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	key::BSTree<int> t1;

	for (auto e : a)
	{
		t1.InsertR(e);
	}
	t1.InOrder();

	t1.EraseR(10);
	t1.EraseR(14);
	t1.EraseR(13);
	t1.InOrder();


	for (auto e : a)
	{
		t1.EraseR(e);
		t1.InOrder();
	}

	t1.InOrder();
}

void TestBSTree3()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	key::BSTree<int> t1;
	for (auto e : a)
	{
		t1.InsertR(e);
	}

	t1.InOrder();

	key::BSTree<int> t2(t1);
	t2.InOrder();
}

void TestBSTree4()
{
	key_value::BSTree<string, string> dict;
	dict.Insert("sort", "ÅÅÐò");
	dict.Insert("left", "×ó±ß");
	dict.Insert("right", "ÓÒ±ß");
	dict.Insert("string", "×Ö·û´®");
	dict.Insert("insert", "²åÈë");
	dict.Insert("erase", "É¾³ý");

	string str;
	while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << ":" << ret->_value << endl;
		}
		else
		{
			cout << "ÎÞ´Ëµ¥´Ê" << endl;
		}
	}
}

void TestBSTree5()
{
	string arr[] = { "Î÷¹Ï", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ïã½¶", "Æ»¹û", "Ïã½¶", "Àæ" };

	key_value::BSTree<string, int> countTree;
	for (auto str : arr)
	{
		//key_value::BSTreeNode<string, int>* ret = countTree.Find(str);
		auto ret = countTree.Find(str);
		if (ret == nullptr)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}

	countTree.InOrder();
}

int main()
{
	TestBSTree5();

	return 0;
}