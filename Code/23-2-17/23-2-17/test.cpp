#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

namespace zx
{
	class string
	{
	public:
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		string(const string& s)
			:_size(s._size)
			, _capacity(_size)
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
			}
			return *this;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}


