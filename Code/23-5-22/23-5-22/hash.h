#pragma once


#include <iostream>
using namespace std;
#include <vector>
#include <time.h>

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


	template<class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};

	//字符串型特化
	template<>
	struct HashFunc<string>
	{
		size_t operator()(const string& s)
		{
			size_t hash = 0;
			for (auto& e : s)
			{
				hash += e;
				hash *= 131;
			}
			return hash;
		}
	};

	template<class K, class V, class Hash = HashFunc<K>>
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
			Hash hash;
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
						size_t hashi = hash(cur->_kv.first) % newht.size();
						cur->_next = newht[hashi];
						newht[hashi] = cur;
						cur = next;
					}
				}
				_tables.swap(newht);
			}
			//真正的插入(头插)
			size_t hashi = hash(kv.first) % _tables.size();
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_num;
			return true;
		}

		Node* Find(const K& key)
		{
			Hash hash;
			if (_tables.size() == 0)
				return nullptr;
			size_t hashi = hash(key)% _tables.size();
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
			Hash hash;
			size_t hashi = hash(key)% _tables.size();
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

		size_t MaxBucketSize()
		{
			size_t max = 0;
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				auto cur = _tables[i];
				size_t size = 0;
				while (cur)
				{
					++size;
					cur = cur->_next;
				}

				printf("[%d]->%d\n", i, size);
				if (size > max)
				{
					max = size;
				}
			}
			return max;
		}


		void Print()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				auto cur = _tables[i];
				while (cur)
				{
					printf("%s ",cur->_kv.first);
					cur = cur->_next;
				}
				cout << endl;
			}
		}

	private:
		vector<Node*> _tables;
		size_t _num;
	};


	struct HashStr
	{
		size_t operator()(const string& s)
		{
			size_t hash = 0;
			for (auto& e : s)
			{
				hash += e;
				hash *= 131;
			}
			return hash;
		}
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

	void TestHashTable3()
	{
		//HashTable<string, string, HashStr> ht;
		//ht.Insert(make_pair("sort", "排序"));
		//ht.Insert(make_pair("string", "字符串"));
		//ht.Insert(make_pair("left", "左边"));
		//ht.Insert(make_pair("right", "右边"));
		//ht.Insert(make_pair("", "右边"));

		//HashStr hashstr;
		//cout << hashstr("abcd") << endl;
		//cout << hashstr("bcda") << endl;
		//cout << hashstr("aadd") << endl;
		//cout << hashstr("eat") << endl;
		//cout << hashstr("ate") << endl;

		HashTable<string, string> ht;
		ht.Insert(make_pair("sort", "排序"));
		ht.Insert(make_pair("string", "字符串"));
		ht.Insert(make_pair("left", "左边"));
		ht.Insert(make_pair("right", "右边"));
		ht.Insert(make_pair("", "右边"));

		ht.Print();
	}

	void TestHashTable4()
	{
		size_t N = 10000;
		HashTable<int, int> ht;
		srand(time(0));
		for (size_t i = 0; i < N; ++i)
		{
			size_t x = rand() + i;
			ht.Insert(make_pair(x, x));
		}

		cout << ht.MaxBucketSize() << endl;
	}
}