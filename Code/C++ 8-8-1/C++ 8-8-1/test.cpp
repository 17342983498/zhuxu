#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string.h>

class String
{
public:
	String(const char* str = " haha ")
	{
		str = (char*)malloc(sizeof(_str)+1);
		strcpy(_str, str);
	}
	size_t Size()
	{
		return strlen(_str);
	}
	~String()
	{
		if (_str)
		{
			free(_str);
		}
	}
	void Print()
	{
		cout << *_str << endl;
	}
private:
	char* _str;
};

int main()
{
	String s1("hello");
	int a = s1.Size();
	cout << a << endl;
	s1.Print();
	String s2(s1);
	s2.Print();
	return 0;
}