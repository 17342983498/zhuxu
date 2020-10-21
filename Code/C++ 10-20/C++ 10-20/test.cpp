#define _CRT_SECURE_NO_WARNINGS 1

#include<string>
#include<iostream>
using namespace std;



void TestString2()
{
	string s1 ("hello,world!");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	s1.clear();
	if (s1.empty())
	{
		cout << "¿Õ×Ö·û´®" << endl;
	}
	else
	{
		cout << "×Ö·û´®" << endl;
	}
	s1 = "";
}


void TestString1()
{
	string s1;
	string s2("hello,world!");
	string s3(s2);
	string s4(5, 'c');
	cin >> s1;
	cout << s1 << endl;
}

void TestString3()
{
	string s1("abcdefg");
	s1.resize(10,'!');
	s1.resize(5);
	s1 += "fg";
}


int main()
{
	//TestString1();
	//TestString2();
	TestString3();
	return 0;
}