#include <queue>
#include <iostream>
using namespace std;
#include <vector>
#include <list>

namespace zx
{
	template<class T, class Container = list<T>>
	class queue
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_front();
		}

		const T& front()
		{
			return _con.front();
		}

		const T& back()
		{
			return _con.back();
		}

		bool empty()
		{
			return _con.empty();
		}

		size_t size()
		{
			return _con.size();
		}

	private:
		Container _con;
	};

	void test_queue()
	{
		queue<int,list<int>> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		q.push(5);
		cout << q.size() << endl;

		cout << q.front() << endl;
		cout << q.back() << endl;


		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
		cout << q.size() << endl;
	}
}


void adjust_down(int parent)
{
	int child = parent * 2 + 1;
	while (child<_con.size())
	{
		if (child + 1 < _con.size() && _con[child]<_con[child + 1])
		{
			child += 1;
		}
		if (_con[parent]<_con[child])
		{
			swap(_con[parent], _con[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}


}