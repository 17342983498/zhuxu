#pragma once
#include <mutex>
#include <thread>

//C++98 管理权转移
//不熟悉这种特性的可能会导致空字符串的解引用
namespace zx
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}


		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
		//C++11
		unique_ptr(unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(unique_ptr<T>& up) = delete;
		//C++98 -- 只声明，不实现，还得私有，防止类外实现
	private:
		//unique_ptr(unique_ptr<T>& up);

	private:
		T* _ptr;
	};


	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
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
			if (--(*_pcount) == 0)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				delete _pcount;
			}
			_pmutex->unlock();
		}

		void AddCount()
		{
			_pmutex->lock();
			++(*_pcount);
			_pmutex->unlock();
		}

		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmutex(sp._pmutex)
		{
			AddCount();
		}

		shared_ptr<T>& operator=(shared_ptr<T>& sp)
		{
			//不能通过this和sp进行比较，因为可能会有同一个资源的不同对象赋值
			if (_ptr != sp._ptr)
			{
				//被赋值的资源只有一个指针指向
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

		}
	}

	void test_shared_safe()
	{
		zx::shared_ptr<Date> p(new Date);
		cout << p.get() << endl;
		const size_t n = 10000;
		mutex mtx;
		thread t1(SharePtrFunc, std::ref(p), n, std::ref(mtx));
		thread t2(SharePtrFunc, std::ref(p), n, std::ref(mtx));
		t1.join();
		t2.join();		cout << p.use_count() << endl;
	}

	void test_shared()
	{
		shared_ptr<int> sp1(new int(1));
		shared_ptr<int> sp2(sp1);

		shared_ptr<int> sp3(new int(1));

		sp1 = sp3;
	}
}