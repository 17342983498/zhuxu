#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
#include <assert.h>
#include <list>

//void func(int& x)
//{
//	cout << "void func(int& x)" << endl;
//}
//
//void func(int&& x)
//{
//	cout << "void func(int&& x)" << endl;
//}
//
//int main()
//{
//	int a = 1;
//	int b = 0;
//	func(a);
//	func(a + b);
//	return 0;
//}


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
			string tmp(s);
			swap(tmp);
			cout << "string(const string& s)" << "-----深拷贝" << endl;
		}

		string(string&& s)
			:_str(nullptr)
		{
			swap(s);
			cout << "string(string&& s)" << "-----移动拷贝" << endl;
		}


		string& operator=(const string& s)
		{
			string tmp(s);
			swap(tmp);
			cout << "string(const string& s)" << "-----深拷贝" << endl;
			return *this;
		}

		string& operator=(string&& s)
		{
			swap(s);
			cout << "string& operator=(string&& s)" << "-----移动拷贝" << endl;
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


//int main()
//{
//	//string s1("hello ");
//	//string s2("world!");
//	// 
//	//string ret1 = s1;
//	//string ret2 = s1 + s2;
//
//	zx::string s1("hello world");
//	zx::string ret1 = s1;
//	zx::string ret2 = (s1 + '!');
//
//	return 0;
//}

//
//int main()
//{
//	zx::string valStr = zx::to_string(1234);
//	return 0;
//}


//int main()
//{
//	string s1 = "abc";
//	string s2 = s1;
//	//string s3 = move(s1);
//	move(s1);
//	string s3 = s1;
//	return 0;
//}


//int main()
//{
//	list<zx::string> lt;
//	zx::string s = "zbcd";
//	lt.push_back(s);
//	lt.push_back(move(s));
//	lt.push_back("asdf");
//	return 0;
//}



//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//
//void Fun(int&& x) { cout << "右值引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//
//// 万能引用(引用折叠)：既可以引用左值，也可以引用右值
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(t);
//	//Fun(forward<T>(t));
//}
//
//int main()
//{
//	PerfectForward(10);           // 右值
//
//	int a;
//	PerfectForward(a);            // 左值
//	PerfectForward(std::move(a)); // 右值
//
//	const int b = 8;
//	PerfectForward(b);		      // const 左值
//	PerfectForward(std::move(b)); // const 右值
//
//	/*int&& rr1 = 10;
//	cout << &rr1 << endl;
//	rr1++;*/
//
//	/*string s1("hello world");
//	string s2("hello world");
//	string s3 = s1 + s2;*/
//
//	return 0;
//}


int main()
{
	zx::string s;
	s = zx::to_string(1324);
	return 0;
}