#pragma once

#include <mutex>
#include <thread>
#include <memory>

namespace zx
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmutex(new mutex)
		{} 

		~shared_ptr()
		{
			Release();
		}

		void Release()
		{
			_pmutex->lock();
			bool flag = false;
			if (--(*_pcount) == 0)
			{
				cout << "delete: " << _ptr << endl;
				delete _ptr;
				delete _pcount;
				flag = true;
			}
			_pmutex->unlock();
			if (flag == true)
			{
				delete _pmutex;
			}
		}

		void AddCount()
		{
			_pmutex->lock();
			++(*_pcount);
			_pmutex->unlock();
		}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmutex(sp._pmutex)
		{
			AddCount();
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				Release();
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmutex = sp._pmutex;
				AddCount();
			}
			return *this; 
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()const
		{
			return _ptr;
		}

		int use_count()
		{
			return *_pcount;
		}
	private:
		T* _ptr;
		int* _pcount;
		mutex* _pmutex;
	};


	void test_shared()
	{
		shared_ptr<int> sp1(new int(10));
		shared_ptr<int> sp2(sp1);

		shared_ptr<int> sp3(new int(20));

		sp1 = sp3;
	}


	struct Date
	{
		int _year = 0;
		int _month = 0;
		int _day = 0;
	};

	void SharePtrFunc(zx::shared_ptr<Date>& sp, size_t n, mutex& mtx)
	{
		cout << sp.get() << endl;
		for (size_t i = 0; i < n; ++i)
		{
			// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
			zx::shared_ptr<Date> copy(sp);
			mtx.lock();
			sp->_year++;
			sp->_month++;
			sp->_day++;
			mtx.unlock();
		}
	}

	void test_shared_safe()
	{
		zx::shared_ptr<Date> p(new Date);
		cout << p.get() << endl;
		const size_t n = 10000;
		mutex mtx;
		thread t1(SharePtrFunc, ref(p), n, ref(mtx));
		thread t2(SharePtrFunc, ref(p), n, ref(mtx));
		t1.join();
		t2.join();		cout << p.use_count() << endl;

		cout << p->_year << endl;
		cout << p->_month << endl;
		cout << p->_day << endl;
	}


	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()const
		{
			return _ptr;
		}

		int use_count()
		{
			return *_pcount;
		}
	private:
		T* _ptr;
	};

	struct ListNode
	{
		weak_ptr<ListNode> next;
		weak_ptr<ListNode> prev;
		int val;

		~ListNode()
		{
			cout << "~ListNode()" << endl;
		}
	};

	//循环引用
	void test_shared_cycle()
	{
		shared_ptr<ListNode> n1(new ListNode);
		shared_ptr<ListNode> n2(new ListNode);

		n1->next = n2;
		n2->prev = n1;
	}

	template<class T>
	struct DeleteArray
	{
		void operator()(T* ptr)
		{
			cout << "void operator()(T* ptr)" << endl;
			delete[] ptr;
		}
	};

	void test_shared_deletor()
	{
		std::shared_ptr<Date> spa1(new Date[10], DeleteArray<Date>());
	}


	/*template<class T>
	struct DeleteArray
	{
		void operator()(T* ptr)
		{
			cout << "void operator()(T* ptr)" << endl;
			delete[] ptr;
		}
	};

	void test_shared_deletor()
	{
		std::shared_ptr<Date> spa1(new Date[10], DeleteArray<Date>());
		std::shared_ptr<Date> spa2(new Date[10], [](Date* ptr){
			cout << "lambda delete[]" << ptr << endl;
			delete[] ptr;
		});
	}*/
}