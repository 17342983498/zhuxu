#pragma once

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


		const iterator begin()const
		{
			return _str;
		}

		const iterator end()const
		{
			return _str + _size;
		}


		string(const char* str = "")
			:_size(strlen(str))
		{
			_str = new char[_size + 1];
			strcpy(_str, str);
			_capacity = _size;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		string(const string& s)
			:_size(s._size)
		{
			_str = new char[_size + 1];
			strcpy(_str, s._str);
			_capacity = _size;
		}

		string& operator=(const string& s)
		{
			char* tmp = new char[s._size + 1];
			strcpy(tmp, s._str);
			delete[] _str;
			_str = tmp;
			_capacity = _size = s._size;
			return *this;
		}

		bool operator==(const string& s)
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator>(const string& s)
		{
			return strcmp(_str, s._str) > 0;
		}

		bool operator>=(const string& s)
		{
			return *this > s || *this == s;
		}

		bool operator<(const string& s)
		{
			return !(*this >= s);
		}

		bool operator<=(const string& s)
		{
			return *this < s && *this == s;
		}

		bool operator!=(const string& s)
		{
			return !(*this == s);
		}

		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}

		void resize(size_t newsize,char c = '\0')
		{
			if (newsize > _size)
			{
				if (newsize > _capacity)
				{
					reserve(newsize);
				}
				memset(_str + _size, c, newsize - _size);
			}
			_size = newsize;
			_str[newsize] = '\0';
		}

		void reserve(size_t cap)
		{
			if (cap > _capacity)
			{
				char* tmp = new char[cap + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = cap;
			}
		}

		void push_back(char c)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			_str[_size++] = c;
			_str[_size] = '\0';
		}

		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}

		void append(const char* str)
		{
			int len = strlen(str);
			if (_size +len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		string& insert(size_t pos, char c)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			//size_t end = _size;
			//while (end >= pos)
			//{
			//	_str[end + 1] = _str[end];
			//	--end;
			//}
			//_str[pos] = c;
			//++_size;
			//return *this;

			//size_t num = _size + 1 - pos;
			//size_t end = _size;
			//while (num--)
			//{
			//	_str[end + 1] = _str[end];
			//	--end;
			//}
			//_str[pos] = c;
			//++_size;
			//return *this;


			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = c;
			++_size;
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end + len - 1] = _str[end - 1];
				--end;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}

		string& erase(size_t pos, size_t len = npos)
		{
			if (pos + len >= _size || len == npos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}

		const char* c_str()const
		{
			return _str;
		}

		size_t size()
		{
			return _size;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		friend ostream& operator<<(ostream& out, const string& s);
		friend istream& operator>>(istream& in, string& s);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos;
	};
	const size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}


	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch = in.get();
		char buf[128];
		size_t i = 0;
		while (ch != ' '&& ch != '\n')
		{
			buf[i++] = ch;
			if (i == 127)
			{
				buf[127] = '\0';
				s += buf;
				i = 0;
			}
			ch = in.get();
		}
		if (i != 0)
		{
			buf[i] = '\0';
			s += buf;
		}
		return in;
	}
	void Print(const string& s)
	{
		string::iterator it = s.begin();
		while (it != s.end())
		{
			(*it)++;
			++it;
		}
		it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			it++;
		}
	}

	void StringTest()
	{
		string s1("abcd");
		cout << s1.c_str() << endl;

		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			(*it)++;
			++it;
		}
		it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		Print(s1);
	}

	void StringTest1()
	{
		string s1("abcdf");
		string s2("abcde");
		cout << (s1 == s2) << endl;
		cout << (s1 != s2) << endl;
		cout << (s1 >= s2) << endl;
		cout << (s1 > s2) << endl;
		cout << (s1 <= s2) << endl;
		cout << (s1 < s2) << endl;
	}

	void StringTest2()
	{
		string s("zhuxu");
		for (size_t i = 0; i < s.size(); ++i)
		{
			cout << s[i] << " ";
		}
		cout << endl;

		s.push_back(',');
		s.append("happy!");
		cout << s.c_str() << endl;
		cout << s.size() << endl;
		s += 'c';
		cout << s.size() << endl;
		s += "sdfsd";
		cout << s.c_str() << endl;
		cout << s.size() << endl;
		s.clear();
		cout << s.c_str() << endl;

	}

	void StringTest3()
	{
		string s("abcd");
		s.insert(0, 'e');
		cout << s.c_str() << endl;
		cout << s.size() << endl;

		s.insert(0, "xyz");
		cout << s.c_str() << endl;
		cout << s.size() << endl;

		cout << s << endl;

	}

	void StringTest4()
	{
		string s;
		cin >> s;
		cout << s << endl;
	}

}