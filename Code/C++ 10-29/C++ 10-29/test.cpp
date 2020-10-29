#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
		{
			_str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		} 
	}
	String(const String& s)
		:_str(new char(strlen(s._str)+1))
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			//delete[] _str;
			//_str = new char[sizeof(s._str)+1];
			//strcpy(_str,s._str);

			char* temp = new char[sizeof(s._str) + 1];
			strcpy(temp, s._str);
			delete[] _str;
			_str = temp;
		}
		return *this;
	}
private:
	char* _str;
};

void TestFunc1()
{
	String s1("hello");
	String s2(s1);
}

void TestFunc2()
{
	String s1("hello");
	String s2;
	s2 = s1;
}
int main()
{
	TestFunc1();
	//TestFunc2();
	return 0;
}