#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
using namespace std;

//void TestString1()
//{
//	string s1("hello world!");
//	cout << s1.capacity() << endl;
//	cout << s1.size() << endl;
//	cout << s1 << endl;
//
//	string s2;
//	cout << s2.capacity() << endl;
//	cout << s2.size() << endl;
//
//	string s3(s1);
//	cout << s3.capacity() << endl;
//	cout << s3.size() << endl;
//	cout << s3 << endl;
//
//	string s4(5, 'b');
//	cout << s4 << endl;
//}


//void TestString2()
//{
//	string s1("hello world!");
//
//	string s2(s1, 6, 4);//从第六个字符开始往后四个字符
//	cout << s2 << endl;
//
//	string s3(s1, 6, 14);//从第六个字符开始往后十四个字符，字符数不足的话仅剩余的即可
//	cout << s3 << endl;
//
//	string s4(s1, 6);//与上面同
//	cout << s4 << endl;
//}


//void TestString3()
//{
//	string s1("hello world!");
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.capacity() << endl;
//
//	//s1.clear();
//	//cout << s1.size() << endl;
//	//cout << s1.length() << endl;
//	//cout << s1.capacity() << endl;
//
//	//cout << s1.empty() << endl;
//
//
//	s1.resize(5, 'z');
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.capacity() << endl;
//	cout << s1 << endl;
//
//	s1.resize(10, 'a');
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.capacity() << endl;
//	cout << s1 << endl;
//
//	string s2("abcd");
//	s2.resize(5);
//	cout << s2.size() << endl;
//	cout << s2.length() << endl;
//	cout << s2.capacity() << endl;
//	cout << s2 << endl;
//	cout << sizeof(s2) << endl;//28\
//
//
//	s2.resize(58);
//	cout << s2.size() << endl;
//	cout << s2.length() << endl;
//	cout << s2.capacity() << endl;
//	
//}

//void TestString4()
//{
//	string s1("aaaa");
//
//	s1.reserve(200);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//
//	s1.reserve(20);
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//}


void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << "capacity is " << sz << endl;
	for (int i = 0; i < 100; i++)
	{
		s.push_back('a');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity has changed:" << sz << endl;
		}
	}
}

void TestPushBack2()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "capacity is " << sz << endl;
	for (int i = 0; i < 100; i++)
	{
		s.push_back('a');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity has changed:" << sz << endl;
		}
	}
	cout << s << endl;
}


int main()
{
	//TestString4();
	TestPushBack2();
	return 0;
}