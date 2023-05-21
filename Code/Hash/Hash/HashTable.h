#pragma once


#include <iostream>
using namespace std;
#include <vector>
enum State
{
	EMPTY,
	EXIST,
	DELETE
};


template<class K,class V>
struct HashData
{
	pair<K, V> _kv;
	State _state;
};

template<class K, class V>
struct HashTable
{
public:
	bool Insert(const pair<K,V> kv)
	{
		//先检查是否需要扩容
		if (_tables.size() == 0 || _num * 10 / _tables.size() >= 7)
		{
			size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
			HashTable<K, V> newht;
			newht._tables.resize(newsize);
			for (auto& data : _tables)
			{
				if (data._state == EXIST)
				{
					newht.Insert(data._kv);
				}
			}

			_tables.swap(newht._tables);
		}


		size_t hashi = kv.first % _tables.size();
		size_t i = 1;
		size_t index = hashi;
		while (_tables[index]._state == EXIST)
		{
			index = hashi + i;
			index %= _tables.size();
			i++;
		}
		_tables[index]._kv = kv;
		_tables[index]._state = EXIST;
		_num++;

		return true;
	}

	HashData<K, V>* Find(const K& key)
	{
		if (_tables.size() == 0)
		{
			return nullptr;
		}
		size_t hashi = key % _tables.size();
		size_t i = 1;
		size_t index = hashi;
		while (_tables[index]._state != EMPTY)
		{
			if (_tables[index]._state == EXIST && _tables[index]._kv.first == key)
			{
				return &_tables[index];
			}
			index = hashi + i;
			index %= _tables.size();
			++i;
			if (index == hashi)
			{
				break;
			}
		}
		return nullptr;
	}
	bool Erase(const K& key)
	{
		HashData<K, V>* ret = Find(key);
		if (ret)
		{
			ret->_state = DELETE;
			--_num;
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	vector<HashData<K,V>> _tables;
	size_t _num;
};


void TestHashTable1()
{
	int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
	HashTable<int, int> ht;
	for (auto e : a)
	{
		ht.Insert(make_pair(e, e));
	}

	ht.Insert(make_pair(15, 15));

	if (ht.Find(13))
	{
		cout << "13在" << endl;
	}
	else
	{
		cout << "13不在" << endl;
	}
	ht.Erase(13);
	if (ht.Find(13))
	{
		cout << "13在" << endl;
	}
	else
	{
		cout << "13不在" << endl;
	}
}