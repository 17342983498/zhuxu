#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


#if 0
//´íÎó
template<class T>
bool IsEqual(T& left, T& Right)
{
	return left == right;
}

void Test1()
{
	char* str1 = "hello";
	char* str2 = "world";
	if (IsEqual(str1, str2))
		cout << str1 << endl;
	else
		cout << str2 << endl;
}

int main()
{
	Test1();
	return 0;
}
#endif


#if 0
template<>
bool IsEqual<char*>(char*& left, char*& Right)
{
	if (strcmp(left, right) > 0)
		return true;
	return false;
}

void Test1()
{
	char* str1 = "hello";
	char* str2 = "world";
	if (IsEqual(str1, str2))
		cout << str1 << endl;
	else
		cout << str2 << endl;
}

int main()
{
	Test1();
	return 0;
}
#endif


#if 0
bool IsEqual(char* left, char* right)
{
	if (strcmp(left, right) > 0)
		return true;
	return false;
}

void Test1()
{
	char* str1 = "hello";
	char* str2 = "world";
	if (IsEqual(str1, str2))
		cout << str1 << endl;
	else
		cout << str2 << endl;
}

int main()
{
	Test1();
	return 0;
}
#endif


#if 0
template<class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<int,int>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};


int main()
{
	Data<int, int> d;
	return 0;
}
#endif


#if 0
template<class T1, class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<int,int>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

//È«ÌØ»¯
template<>
class Data<int, char>
{
public:
	Data()
	{
		cout << "Data<int,char>" << endl;
	}
private:
	int _d1;
	char _d2;
};


int main()
{
	Data<int, int> d1;
	Data<int, char> d2;
	return 0;
}
#endif


#if 0
template<class T1, class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<int,int>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

template<class T>
class Data<T, char>
{
public:
	Data()
	{
		cout << "Data<T,char>" << endl;
	}
private:
	T _d1;
	char _d2;
};

int main()
{
	Data<int, char> d;
	return 0;
}
#endif

#if 0
template<class T1, class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

template<typename T1, typename T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "Data<T1*,T2*>" << endl;
	}
private:
	T1* _d1;
	T2* _d2;
};

template<typename T1,typename T2>
class Data<T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		:_d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&,T2&>" << endl;
	}
private:
	const T1& _d1;
	const T2& _d2;
};

int main()
{
	Data<int, char> d0;
	Data<int*, char*> d1;
	Data<int&, int&>d2 (1, 2);
	return 0;
}
#endif


#if 0
template<class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Date<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};	

template<>
class Data<int,char>
{
public:
	Data()
	{
		cout << "Data<int,char>" << endl;
	}
private:
	int _d1;
	char _d2;
};

int main()
{
	Data<int, int> d1;
	Data<int, char> d2;
	Data<char, char> d3;
	return 0;
}
#endif


template<class T1, class T2>
class Data
{
public:
	Data()
	{
		cout << "Date<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

template<class T>
class Data<T, char>
{
public:
	Data()
	{
		cout << "Data<T,char>" << endl;
	}
private:
	T _d1;
	char _d2;
};

int main()
{
	Data<int, int> d1;
	Data<int, char> d2;
	Data<char, char> d3;
	return 0;
}