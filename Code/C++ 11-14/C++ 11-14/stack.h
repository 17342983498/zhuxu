#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>

template<class T>
class stack
{
public:
	stack()
	{

	}
	void push(const T& data)
	{
		_S.push_back(data);
	}
	void pop()
	{
		_S.pop_back();
	}
	int top()
	{
		return _S.back();
	}
	const int top()const
	{
		return _S.back();
	}
	size_t size()
	{
		return _S.size();
	}
	bool empty()
	{
		return _S.empty();
	}
private:
	vector<T> _S;
};