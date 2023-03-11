#pragma once


namespace zx
{
	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;

		list_node(const T& x = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(x)
		{

		}
	};

	template<class T, class Ref>
	struct __list_iterator
	{
		typedef list_node<T> node;
		typedef __list_iterator<T, Ref> self;
		node* _node;

		__list_iterator(node* n)
			:_node(n)
		{}

		Ref& operator*()
		{
			return _node->_data;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self& operator++(int)
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

		self& operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}


		bool operator==(const self& s)
		{
			return s._node == _node;
		}

		bool operator!=(const self& s)
		{
			return s._node != _node;
		}
	};



	template<class T>
	class list
	{
		typedef list_node<T> node;
		
	public:
		typedef __list_iterator<T, T&> iterator;
		typedef __list_iterator<T, const T&> const_iterator;
		iterator begin()
		{
			return iterator(_Head->_next);
		}

		iterator end()
		{
			return iterator(_Head);
		}

		const_iterator begin()const
		{
			return const_iterator(_Head->_next);
		}

		const_iterator end()const
		{
			return const_iterator(_Head);
		}
		list()
		{
			_Head = new node;//加上了模板参数才是类型
			_Head->_next = _Head;
			_Head->_prev = _Head;
		}

		void push_back(const T& x)
		{
			node* tail = _Head->_prev;
			node* newnode = new node(x);
			newnode->_next = _Head;
			tail->_next = newnode;
			_Head->_prev = newnode;
			newnode->_prev = tail;
		}
	private:
		node* _Head;
	};

	void ListPrint(const list<int>& l)
	{
		list<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			//(*it) *= 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;

	}

	void list_test1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;


		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
		ListPrint(lt);
	}

}


