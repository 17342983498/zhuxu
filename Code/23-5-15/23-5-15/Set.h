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
		set<int> s;
		s.insert(1);
		s.insert(3);
		s.insert(2);

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

}