#pragma once

#include "RBTree.h"


namespace zx
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& Key)
			{
				return Key;
			}
		};
	public:
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		bool insert(const K& Key)
		{
			return _t.insert(Key);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};

	void set_test()
	{
		int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		set<int> s;
		//s.insert(1);
		//s.insert(3);
		//s.insert(2);
		for (auto e : a)
		{
			s.insert(e);
		}
		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;



	}

}