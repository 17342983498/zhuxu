#include <iostream>
using namespace std;
#include <assert.h>

namespace zx
{
	template<class T>
	class vector
	{
	public:
		// Vector的迭代器是一个原生指针
		typedef T* iterator;
		typedef const T* const_iterator;


		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}

		vector(size_t n, const T& value = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}


		vector(int n, const T& value = T())
			: _start(new T[n])
			, _finish(_start + n)
			, _endOfStorage(_finish)
		{
			for (int i = 0; i < n; ++i)
			{
				_start[i] = value;
			}
		}


		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reserve(v.capacity());
			iterator it = begin();
			const_iterator vit = v.cbegin();
			while (vit != v.cend())
			{
				*it++ = *vit++;
			}
			_finish = it;
		}

		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endOfStorage = nullptr;
			}
		}


		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator cbegin() const
		{
			return _start;
		}

		const_iterator cend() const
		{
			return _finish;
		}


		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endOfStorage - _start;
		}

		bool empty() const
		{
			return _start == _finish;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldSize = size();
				// 1. 开辟新空间
				T* tmp = new T[n];

				// 2. 拷贝元素
				// 这里直接使用memcpy会有问题吗？同学们思考下
				//if (_start)
				//	memcpy(tmp, _start, sizeof(T)*size);

				if (_start)
				{
					for (size_t i = 0; i < oldSize; ++i)
						tmp[i] = _start[i];

					// 3. 释放旧空间
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + oldSize;
				_endOfStorage = _start + n;
			}
		}

		void resize(size_t n, const T& value = T())
		{
			// 1.如果n小于当前的size，则数据个数缩小到n
			if (n <= size())
			{
				_finish = _start + n;
				return;
			}

			// 2.空间不够则增容
			if (n > capacity())
				reserve(n);

			// 3.将size扩大到n
			iterator it = _finish;
			_finish = _start + n;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}


		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return _start[pos];
		}

		T& front()
		{
			return *_start;
		}

		const T& front()const
		{
			return *_start;
		}

		T& back()
		{
			return *(_finish - 1);
		}

		const T& back()const
		{
			return *(_finish - 1);
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void pop_back()
		{
			erase(end() - 1);
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endOfStorage, v._endOfStorage);
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);

			// 空间不够先进行增容
			if (_finish == _endOfStorage)
			{
				//size_t size = size();
				size_t newCapacity = (0 == capacity()) ? 1 : capacity() * 2;
				reserve(newCapacity);

				// 如果发生了增容，需要重置pos
				pos = _start + size();
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finish;
			return pos;
		}

		// 返回删除数据的下一个数据
		// 方便解决:一边遍历一边删除的迭代器失效问题
		iterator erase(iterator pos)
		{
			// 挪动数据进行删除
			iterator begin = pos + 1;
			while (begin != _finish) {
				*(begin - 1) = *begin;
				++begin;
			}

			--_finish;
			return pos;
		}
	private:
		iterator _start;		// 指向数据块的开始
		iterator _finish;		// 指向有效数据的尾
		iterator _endOfStorage;  // 指向存储容量的尾
	};
}

/// /////////////////////////////////
/// 对模拟实现的vector进行严格测试
void TestBitVector1()
{
	zx::vector<int> v1;
	zx::vector<int> v2(10, 5);

	int array[] = { 1, 2, 3, 4, 5 };
	zx::vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));

	zx::vector<int> v4(v3);

	for (size_t i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	auto it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestBitVector2()
{
	zx::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;
	cout << v[0] << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.pop_back();
	v.pop_back();
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.insert(v.begin(), 0);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin() + 1);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}