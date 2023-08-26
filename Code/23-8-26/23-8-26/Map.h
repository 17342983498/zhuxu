#pragma once

#include "RBTree.h"


namespace zx
{
	template<class K,class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		bool insert(const pair<const K, V>& kv)
		{
			return _t.insert(kv);
		}

		bool insert(const pair<K,V>& kv)
		{
			return _t.insert(kv);
		}
	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};

	void map_test()
	{
		map<int,int> m;
		m.insert(make_pair(1, 1));
		m.insert(make_pair(3, 3));
		m.insert(make_pair(2, 2));

		map<int,int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << (*it).first << " ";
			++it;
		}
		cout << endl;
	}

}