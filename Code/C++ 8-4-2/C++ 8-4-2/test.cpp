#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<malloc.h>
class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 4);
		strcpy(_str, str);
		strcpy(_str+1, str+1);
		strcpy(_str+2, str+2);
		strcpy(_str+3, str+3);
		cout << *_str << *(_str + 1) << *(_str + 2) << *(_str + 3) << *(_str + 4) << endl;
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};
class Person
{
private:
	String _name;
	int _age;
};
int main()
{
	Person p;
	return 0;
}