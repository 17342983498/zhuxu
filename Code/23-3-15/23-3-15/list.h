#pragma once
#include <iostream>
using namespace std;

namespace zx
{
	template<class T>
	struct list_node
	{
		list_node(const T& val = T())
		:_next(nullptr)
		, _prev(nullptr)
		, _val(val)
		{}
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;
	};

	template<class T,class Ref,class Ptr>
	class list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T, Ref, Ptr> Self;

	public:
		typedef Ref Ref;
		typedef Ptr Ptr;

		list_iterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_val;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		Self operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			Node* tmp = _node;
			_node = _node->_next;
			return tmp;
		}

		Self operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Node* tmp = _node;
			_node = _node->_prev;
			return tmp;
		}

		bool operator==(const Self& l)const
		{
			return _node == l._node;
		}

		bool operator!=(const Self& l)const
		{
			return _node != l._node;
		}

		Node* _node;
	};

	template<class Iterator>
	class ReverseIterator
	{
	public:
		typedef typename Iterator::Ref Ref;
		typedef typename Iterator::Ptr Ptr;
		typedef ReverseIterator<Iterator> Self;
	public:
		ReverseIterator(Iterator it)
			: _it(it)
		{}

		Ref operator*()
		{
			Iterator tmp(_it);
			--tmp;
			return *tmp;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		Self& operator++()
		{
			--_it;
			return *this;
		}

		Self& operator--()
		{
			++_it;
			return *this;
		}

		Self& operator++(int)
		{
			Self tmp(*this);
			--_it;
			return tmp;
		}

		Self& operator--(int)
		{
			Self tmp(*this);
			++_it;
			return tmp;
		}

		bool operator==(const Self& lt)const
		{
			return _it == lt._it;
		}

		bool operator!=(const Self& lt)const
		{
			return _it != lt._it;
		}


		Iterator _it;
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		//正向迭代器
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;

		//反向迭代器
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef ReverseIterator<const_iterator> const_reverse_iterator;
	public:

        ///////////////////////////////////////////////////////////
		list()
		{
			CreateHead();
		}

		list(int n, const T& val = T())
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//拷贝构造
		list(const list<T>& lt)
		{
			CreateHead();
			list<T> tmp(lt.begin(), lt.end());
			this->swap(tmp);
		}

		list<T>& operator=(list<T> lt)
		{
			this->swap(lt);
			return *this;
		}


		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
 
		///////////////////////////////////////////////////////////
		//插入删除
		void push_back(const T& val)
		{
			insert(end(), val);
		}

		void pop_back()
		{
			erase(--end());
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		void pop_front()
		{
			erase(begin());
		}

		iterator insert(iterator pos, const T& val)
		{
			Node* newnode = new Node(val);
			Node* cur = pos._node;

			newnode->_prev = cur->_prev;
			newnode->_next = cur;
			newnode->_prev->_next = newnode;
			cur->_prev = newnode;
			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			Node* pcur = pos._node;
			Node* pnext = pcur->_next;

			pcur->_prev->_next = pnext;
			pnext->_prev = pcur->_prev;
			delete(pcur);
			return iterator(pnext);
		}

		///////////////////////////////////////////////////////////
		//迭代器
		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rbegin()const
		{
			return const_reverse_iterator(end());
		}


		const_reverse_iterator rend()const
		{
			return const_reverse_iterator(begin());
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}

		///////////////////////////////////////////////////////////
		//链表的容量相关
		size_t size()const
		{
			Node* cur = _head->_next;
			size_t count = 0;
			while (cur != _head)
			{
				count++;
				cur = cur->_next;
			}
			return count;
		}

		bool empty()
		{
			return _head->_next == _head;
		}

		void resize(size_t newsize,const T& val = T())
		{
			size_t oldsize = size();
			if (newsize <= oldsize)
			{
				while (newsize < oldsize)
				{
					pop_back();
					oldsize--;
				}
			}
			else
			{
				int count = newsize - oldsize;
				while (count--)
				{
					push_back(val);
				}
			}
		}

		///////////////////////////////////////////////////////////


		void clear()
		{
			while (_head->_next != _head)
			{
				erase(begin());
			}
			_head->_next = _head->_prev = _head;
		}

		void CreateHead()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

	private:
		Node* _head;
	};

	template<class T>
	void PrintList(const list<T>& lt)
	{
		auto it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	//链表的拷贝、拷贝构造、赋值运算符重载
	void ListTest1()
	{
		list<int> lt1;
		list<int> lt2(5, 10);
		PrintList(lt2);

		list<int> lt3(lt2);
		PrintList(lt3);

		int arr[] = { 1, 2, 3, 4, 5, 6 };
		list<int> lt4(arr, arr + sizeof(arr) / sizeof(int));
		PrintList(lt4);

		list<int> lt5;
		lt5 = lt4;
		PrintList(lt5);
	}


	//链表的尾插、尾删、头插、头删
	void ListTest2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		//list<int>::iterator it = lt.begin();
		//while (it != lt.end())
		//{
		//	(*it) *= 2;
		//	cout << *it << " ";
		//	++it;
		//}
		//cout << endl;

		PrintList(lt);

		lt.pop_back();
		PrintList(lt);

		lt.push_front(0);
		PrintList(lt);

		lt.pop_front();
		PrintList(lt);

		lt.insert(lt.begin(), 0);
		PrintList(lt); 
		lt.erase(lt.begin());
		PrintList(lt);

	}


	void ListTest3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		cout << lt.size() << endl;
		cout << lt.empty() << endl;

		//lt.clear();
		//cout << lt.empty() << endl;

		lt.resize(10, 0);
		PrintList(lt);
		cout << lt.size() << endl;
	}

	void ListTest4()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		auto pos = lt.begin();
		//在插入一个元素之后，pos的位置会向后移动一个位置
		lt.insert(lt.begin(), 0);
		PrintList(lt);

		++pos;
		lt.insert(pos, 100);
		PrintList(lt);

		lt.erase(pos);
		PrintList(lt);

		//迭代器失效
		//cout << *pos << endl;


		auto it = lt.begin();
		while (it != lt.end())
		{
			it = lt.erase(it);
		}
		cout << lt.size() << endl;
	}

	void ListTest5()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		auto rit = lt.rbegin();
		while (rit != lt.rend())
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;

		const list<int> cl(lt);
		auto crit = lt.rbegin();

		while (crit != lt.rend())
		{
			cout << *crit << " ";
			++crit;
		}
		cout << endl;
	}

}