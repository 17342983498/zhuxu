#include <stack>
#include <iostream>
using namespace std;
#include <vector>
#include <list>

namespace zx
{
	//template<class T>
	template<class T,class Container = vector<T>>
	class stack
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_back();
		}

		const T& top()
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
		//vector<T> _v;
		Container _con;
	};

	void test_stack()
	{
		//stack<int,vector<int>> st;
		stack<int, list<int>> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);
		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
		cout << st.size() << endl;
	}
}