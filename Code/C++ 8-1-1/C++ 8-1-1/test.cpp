#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class SeqList
{
public:
	void SeqList(const size_t capacity = 10)
	{
		_array = (int*)malloc(sizeof(int)*capacity);
		_capacity = 10;
		_size = 0;
	}
	void pushback(int data)
	{
		if (_capacity == _size)
		{
			int* arr = (int*)realloc((int*)(SeqList::_array), sizeof(int)*_capacity * 2);
			if (arr == NULL)
			{
				return;
			}
			(SeqList::_array) = arr;

		}
	}
private:
	int _array;
	size_t _capacity;
	size_t _size;
};