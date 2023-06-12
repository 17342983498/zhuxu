#pragma once
#include <iostream>
#include <assert.h>

namespace zx
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _val;

		ListNode(const T& val = T())
			:_next(nullptr), _prev(nullptr), _val(val)
		{}

	};


	template<class T,class Ref, class Ptr>
	struct list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T, Ref, Ptr> self;
		Node* _node;

		list_iterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_val;
		}

		Ptr operator->()
		{
			return &_node->_val;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const self& s)
		{
			return _node != s._node;
		}

		bool operator==(const self& s)
		{
			return _node == s._node;
		}
	};

	//很明显这样做代码冗余
	/*template<class T>
	struct const_iterator
	{
		typedef ListNode<T> Node;
		typedef const_iterator<T> self;
		Node* _node;

		const_iterator(Node* node)
			:_node(node)
		{}

		const T& operator*()
		{
			return _node->_val;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		bool operator!=(const self& s)
		{
			return _node != s._node;
		}
	};*/

	template<class T>
	struct List
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
	public:
		void List_Init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		List()
		{
			List_Init();
		}

		~List()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		template<class iterator>
		List(iterator begin, iterator end)
		{
			List_Init();
			while (begin != end)
			{
				push_back(*begin);
				++begin;
			}
		}

		//传统写法
		//List(const List<T>& lt)
		//{
		//	List_Init();
		//	auto it = lt.begin();
		//	while (it != lt.end())
		//	{
		//		lt.push_back(*it);
		//		++it;
		//	}
		//}

		//现代写法
		List(const List<T>& lt)
		{
			List_Init();
			List<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}

		List<T>& operator=(List<T> lt)
		{
			swap(lt);
			return *this;

		}

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

		//在pos之前插入
		void insert(iterator pos, const T& val)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(val);

			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			prev->_next = newnode;
		}


		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;
			prev->_next = next;
			next->_prev = prev;
			delete pos._node;
			//return iterator(next);
			return next;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		void swap(List<T>& lt)
		{
			std::swap(_head, lt._head);
		}

	private:
		Node* _head;
	};

	void ListPrint(const List<int>& lt)
	{
		List<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			//*it *= 2;
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}


	void List_test1()
	{
		List<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		auto it = lt.begin();
		while (it!=lt.end())
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		ListPrint(lt);

		auto pos = lt.begin();
		++pos;
		lt.insert(pos, 0);
		ListPrint(lt);

		--pos;
		lt.erase(pos);
		ListPrint(lt);
		//std::cout << *pos << std::endl;

		lt.clear();
		ListPrint(lt);

		//lt.push_back(9);
		//lt.push_front(0);
		//ListPrint(lt);

		//lt.pop_back();
		//lt.pop_front();
		//ListPrint(lt);
	}
}
