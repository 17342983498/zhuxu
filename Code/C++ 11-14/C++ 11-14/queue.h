#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <list>

template<class T>
class queue
{
public:
	queue()
	{

	}
	void push(const T& data)
	{
		L.push_back(data);
	}
	void pop()
	{
		L.pop_front();
	}
	T& front()
	{
		return L.front();
	}
	const T& front()const
	{
		return L.front();
	}
	T& back()
	{
		return L.back();
	}
	const T& back()const
	{
		return L.back();
	}
	size_t size()
	{
		return L.size();
	}
	bool empty()
	{
		return L.empty();
	}
private:
	list<int> L;
};