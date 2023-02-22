#include <iostream>
using namespace std;
#include <string.h>
#include <assert.h>

namespace zx
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin()const
		{
			return _str;
		}

		const_iterator end()const
		{
			return _str + _size;
		}

		//string()
		//	:_str(new char[1]),
		//	_size(0),
		//	_capacity(0)
		//{
		//	_str[0] = '\0';
		//}
		//string(const char* str)
		//	:_size(strlen(str))
		//{
		//	_capacity = _size;
		//	_str = new char[_size + 1];
		//	strcpy(_str, str);
		//}

		//构造
		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_size + 1];
			strcpy(_str, str);
		}

		//析构
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		//拷贝构造
		string(const string& s)
			:_size(s._size)
			, _capacity(s._capacity)
		{
			_str = new char(_size + 1);
			strcpy(_str, s._str);
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._size + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
			}
			_size = s._size;
			_capacity = s._capacity;
			return *this;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}

		bool operator==(const string& s)const
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator!=(const string& s)const
		{
			return !(*this == s);
		}

		bool operator>(const string& s)const
		{
			return strcmp(_str, s._str) > 0;
		}

		bool operator>=(const string& s)const
		{
			return (*this == s)||(*this > s);
		}

		bool operator<(const string& s)const
		{
			return !(*this >= s);
		}

		bool operator<=(const string& s)const
		{
			return !(*this > s);
		}

		const char* c_str()const
		{
			return _str;
		}

		size_t size()const
		{
			return _size;
		}

		void reserve(size_t cap)
		{
			char* tmp = new char[cap + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = cap;
		}

		void push_back(char c)
		{
			if (_size == _capacity)
			{
				_capacity == 0 ? 3 : _capacity * 2;
				reserve(_capacity);
			}
			_str[_size++] = c;
			_str[_size] = '\0';
		}

		void append(const char* s)
		{
			size_t len = strlen(s);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, s);
			_size += len;
		}

		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}

		string& operator+=(const char* s)
		{
			append(s);
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			int len = strlen(str);
			if (len + _size > _capacity)
			{
				reserve(_size+len);
			}
			memmove(_str + pos + len, _str + pos, sizeof(size_t)*(_size - pos));

			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}



		//string& insert(size_t pos, const char* str)
		//{
		//	assert(pos <= _size);
		//	int len = strlen(str);
		//	if (len + _size >= _capacity)
		//	{
		//		reserve(_size + len);
		//	}
		//	size_t end = _size + len;
		//	while (end >= pos + len)
		//	{
		//		_str[end] = _str[end - len];
		//		end--;
		//	}

		//	strncpy(_str + pos, str, len);
		//	_size += len;
		//	return *this;
		//}


		//string& insert(size_t pos, const char* str)
		//{
		//	assert(pos <= _size);
		//	int len = strlen(str);
		//	if (len + _size >= _capacity)
		//	{
		//		reserve(_size + len);
		//	}
		//	size_t end = _size + len;
		//	while (end > pos + len - 1)
		//	{
		//		_str[end] = _str[end - len];
		//		--end;
		//	}

		//	strncpy(_str + pos, str, len);
		//	_size += len;
		//	return *this;
		//}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	void StringTest1()
	{
		string s1;
		string s2("hello!");
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		string s3(s2);
		cout << s3.c_str() << endl;

		s1 = s2;
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
	}
	void Print(const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			//这里被const修饰
			cout << s[i] << " ";
		}
		cout << endl;

		string::const_iterator it = s.begin();

		//错误的
		//while (it != s.end())
		//{
		//	(*it)++;//不能更改，被const修饰了
		//	it++;
		//}
		//cout << endl;

		while (it != s.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

	void StringTest2()
	{
		string s1("hello world!");
		for (size_t i = 0; i < s1.size(); i++)
		{
			s1[i]++;
		}
		cout << endl;

		for (size_t i = 0; i < s1.size(); ++i)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

		Print(s1);

		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			(*it)++;
			it++;
		}
		cout << endl;

		it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	void StringTest3()
	{
		string s1("good morning!");
		string s2("good evening!");
		cout << (s1 > s2) << endl;
		cout << (s1 == s2) << endl;
		cout << (s1 >= s2) << endl;
		cout << (s1 < s2) << endl;
		cout << (s1 <= s2) << endl;
		cout << (s1 != s2) << endl;
	}

	void StringTest4()
	{
		string s1("hello");

		s1.append(" world");
		s1.push_back('!');
		cout << s1.c_str() << endl;


		string s2("hello");
		s2 += " world";
		s2 += '!';
		cout << s2.c_str() << endl;
	}
	void StringTest5()
	{
		string s("xxxxx");
		s.insert(1, "aaa");
		cout << s.c_str() << endl;

		//s.insert(2, "bbbb");
		//cout << s.c_str() << endl;
	}
}