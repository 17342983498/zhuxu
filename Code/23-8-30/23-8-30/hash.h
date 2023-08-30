#pragma once


#include <iostream>
using namespace std;
#include <vector>


namespace Closed_Hash
{
	enum Statue
	{
		EMPTY,
		EXIST,
		DELETE
	};


	template<class K,class V>
	class HashNode
	{
	public:
		pair<K, V> _kv;
		Statue _statue;
	};

	template<class K, class V>
	class HashTable
	{
	public:
		//插入
		bool Insert(const pair<K,V>& kv)
		{
			//检查是否需要扩容
			if (_tables.size() == 0 || _num * 10 / _tables.size() >= 7)
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V> newht;
				newht._tables.resize(newsize);
				for (auto& data : _tables)
				{
					if (data._statue == EXIST)
					{
						newht.Insert(data._kv);
					}
				}
				_tables.swap(newht._tables);
			}

			size_t hashi = kv.first % _tables.size();
			size_t i = 1;
			size_t index = hashi;
			while (_tables[index]._statue == EXIST)
			{
				index = hashi + i;
				index = index % _tables.size();
				i++;
			}
			_tables[index]._kv = kv;
			_tables[index]._statue = EXIST;
			_num++;

			return true;
		}

		HashNode<K, V>* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}
			size_t hashi = key % _tables.size();
			size_t i = 1;
			size_t index = hashi;
			while (_tables[index]._statue != EMPTY)
			{
				if (_tables[index]._statue != DELETE && key == _tables[index]._kv.first)
				{
					return &_tables[index];
				}
				index = hashi + i;
				index %= _tables.size();
				++i;
				
				//没找到
				if (index == hashi)
				{
					return nullptr;
				}
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashNode<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_statue = DELETE;
				--_num;
				return true;
			}
			else
			{
				return false;
			}
		}


	private:
		vector<HashNode<K, V>> _tables;
		size_t _num;
	};


	void TestHashTable()
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
}



namespace Open_Hash
{
	template<class K,class V>
	class HashNode
	{
	public:
		HashNode<K, V>* _next;
		pair<K, V> _kv;
		HashNode(const pair<K, V>& kv)
			:_next(nullptr)
			, _kv(kv)
		{}
	};

	template<class K, class V>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		~HashTable()
		{
			for (auto& cur : _tables)
			{
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}

				cur = nullptr;
			}
		}

		bool Insert(const pair<K,V> kv)
		{
			if (_num == _tables.size())
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newht(newsize, nullptr);
				//将原来的数据添加到新哈希表中
				for (auto& cur : _tables)
				{
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = cur->_kv.first % newht.size();
						cur->_next = newht[hashi];
						newht[hashi] = cur;
						cur = next;
					}
				}
				_tables.swap(newht);
			}
			//真正的插入(头插)
			size_t hashi = kv.first % _tables.size();
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_num;
			return true;
		}

		Node* Find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;
			size_t hashi = key% _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first != key)
				{
					cur = cur->_next;
				}
				return cur;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			size_t hashi = key% _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first != key)
				{
					prev = cur;
					cur = cur->_next;
				}
				else
				{
					//删除第一个元素
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					_num--;
					return true;
				}
			}
			return false;
		}

	private:
		vector<Node*> _tables;
		size_t _num;
	};


	void TestHashTable()
	{
		int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Insert(make_pair(15, 15));
		ht.Insert(make_pair(25, 25));
		ht.Insert(make_pair(35, 35));
		ht.Insert(make_pair(45, 45));
	}
	void TestHashTable2()
	{
		int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Erase(12);
		ht.Erase(3);
		ht.Erase(33);
	}
}

