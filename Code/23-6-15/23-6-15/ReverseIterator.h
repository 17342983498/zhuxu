#pragma once


namespace zx
{	
	template<class Iterator, class Ref, class Ptr>
	class ReverseIterator
	{
	public:
		typedef ReverseIterator<Iterator, Ref, Ptr> self;
		Iterator _cur;

		ReverseIterator(Iterator cur)
			:_cur(cur)
		{}

		Ref operator*()
		{
			Iterator tmp = _cur;
			--tmp;
			return *tmp;	
		}

		Ptr operator->()
		{
			Iterator tmp = _cur;
			--tmp;
			return tmp;
		}

		self& operator++()
		{
			--_cur;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			--_cur;
			return tmp;
		}

		self& operator--()
		{
			++_cur;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			++_cur;
			return tmp;
		}

		bool operator!=(const self& s)
		{
			return _cur != s._cur;
		}

		bool operator==(const self& s)
		{
			return _cur == s._cur;
		}
	};
}