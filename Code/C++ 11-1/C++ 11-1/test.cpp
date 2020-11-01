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
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		_count = new int(1);
	}

	String(const String& s)
		:_str(s._str)
		, _count(s._count)
	{
		++*_count;
	}

	String operator=(const String& s)
	{
		if (this != &s)
		{
			if (--*_count == 0 && _str)
			{
				delete[] _str;
				delete _count;
			}
			_str = s._str;
			_count = s._count;
			++*_count;
		}
		return *this;
	}

	~String()
	{
		if (--*_count == 0 && _str)
		{
			delete[] _str;
			_str = nullptr;
			delete _count;
			_count = nullptr;
		}
	}

private:
	char* _str;
	int* _count;
};
int main()
{
	String s1("hello");
	String s2(s1);
	String s3("world");
	String s4(s3);
	s1 = s3;
	s2 = s4;
	return 0;
}