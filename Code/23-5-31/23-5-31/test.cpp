#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <assert.h>

namespace zx
{
	class string
	{
	public:
		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
		{
			cout << "string(const char* str)" << endl;
			_str = new char[_size + 1];
			strcpy(_str, str);
			_capacity = _size;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s)" << "-----深拷贝" << endl;
			string tmp(s._str);
			swap(tmp);

		}

		string(string&& s)
			:_str(nullptr)
		{
			cout << "string(string&& s)" << "-----移动拷贝" << endl;
			swap(s);
		}


		string& operator=(const string& s)
		{
			cout << "string(const string& s)" << "-----深拷贝" << endl;
			string tmp(s);
			swap(tmp);
			return *this;
		}

		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s)" << "-----移动赋值" << endl;
			swap(s);
			return *this;
		}


		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}

		void resize(size_t newsize, char c = '\0')
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

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
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
			if (_size + len > _capacity)
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

		string operator+(char ch)
		{
			string tmp(*this);
			tmp += ch;
			return tmp;
		}

		string& insert(size_t pos, char c)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
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

		size_t size()
		{
			return _size;
		}

		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};


	zx::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}

		zx::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;

			str += ('0' + x);
		}

		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());
		return str;
	}
}

class Person
{
public:
	Person(const char* name = "", int age = 0)
		:_name(name)
		, _age(age)
	{}

	/*Person(const Person& p)
		:_name(p._name)
		,_age(p._age)
	{}*/

	/*Person& operator=(const Person& p)
	{
		if(this != &p)
		{
			_name = p._name;
			_age = p._age;
		}
		return *this;
	}*/

	/*~Person()

	{}*/

private:
	zx::string _name;
	int _age;
};

int main()
{
	Person s1("张三", 18);
	Person s2 = s1;
	Person s3 = std::move(s1);
	//Person s4;
	//s4 = std::move(s2);
	return 0;
}

