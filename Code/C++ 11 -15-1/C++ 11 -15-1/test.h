#include <iostream>
using namespace std;
#include<vector>
template<class T,class Con=vector<T>>
class priority_queue
{
public:
	template<class Iterator>
	priority_queue(Iterator first, Iterator last)
		:c(first, last)
	{
		int count = c.size();
		int root = (count - 2) / 2;
		while (root >= 0)
		{
			AdjustDown(root--);
		}
	}
	void push(const T& data)
	{
		c.push_back(data);
		AdjustUp(c.size()-1);
	}
	void pop()
	{
		if (empty())
			return;
		swap(c.front(), c.back());
		c.pop_back();
		AdjustDown(0);
	}
	size_t size()const
	{
		return c.size();
	}
	bool empty()const
	{
		return c.empty();
	}
	void AdjustUp(size_t child)
	{
		size_t parent = (child - 1) / 2;
		while (child)
		{
			if (c[parent] > c[child])
			{
				swap(c[child], c[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}
	void AdjustDown(size_t parent)
	{
		size_t child = parent * 2 + 1;
		while (child < c.size())
		{
			if (child + 1 < c.size() && c[child] > c[child + 1])
			{
				child += 1;
			}
			if (c[parent]>c[child])
			{
				swap(c[parent], c[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}
private:
	Con c;
};