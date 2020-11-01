#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;




//传统版
#if 0

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
	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* temp = new char[strlen(s._str) + 1];
			strcpy(temp, s._str);
			delete _str;
			_str = temp;
		}
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
#endif


//现代版
class String
{
public:
	String(const char* str)
	{
		if (nullptr == str)
		{
			_str = nullptr;
		}
		_str = new char[strlen(_str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(nullptr)
	{
		String strtemp(s._str);//调用个构造函数
		/*swap(strtemp, (String)_str);*/
		swap(_str, strtemp._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			String strtemp(s);
			swap(strtemp, (String)_str);
		}
		return *this;
	}

	//String& operator=(String s)
	//{
	//	swap(_str, s._str);
	//	return *this;
	//}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
int main()
{
	String s1("hello");
	String s2(s1);
	return 0;
}