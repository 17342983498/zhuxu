#define _CRT_SECURE_NO_WARNINGS 1

#include<string>
#include<iostream>
using namespace std;

void TestString1()
{
	string s1("abcdefg");
	s1.resize(10,'!');
	cout << s1 << endl;
}
void TestString2()
{
	string s1("abcdefg");
	s1.reserve(10);
	s1.reserve(20);
	s1.reserve(30);
	s1.reserve(40);
	s1.reserve(30);
	s1.reserve(20);
	s1.reserve(10);
}
void TestString3()
{
	string s1("hello");
	//s1.push_back(',' );
	//s1 += "world";
	//s1.push_back('!');
	/*s1.append(s1,2,'$');*/
	s1.append(3,'$');
	//s1.append("abcd",1,3);
	s1.append(",world!");
	s1.append("abcd",2);
	s1.append("cd");
}
void TestString4()
{
	string s1("hello world !");
	s1.insert(s1.find(' '), "$$$");
	s1.insert(s1.rfind(' '),"$$$");
}
void TestString5()
{
	string s1;
	getline(cin, s1);
	cout << s1.substr(s1.rfind(' ') + 1) << endl;
	cout << s1.substr(s1.rfind(' ') + 1).size() << endl;
}
int main()
{
	//TestString1();
	//TestString2();
	//TestString3();
	//TestString4();
	TestString5();
	return 0;
}