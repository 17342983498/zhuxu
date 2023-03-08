
#include <iostream>
using namespace std;
#include <assert.h>

namespace zx
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin()const
		{
			return _start;
		}

		const_iterator end()const
		{
			return _finish;
		}

		size_t capacity()const
		{
			return _end_of_storage - _start;
		}

		size_t size()const
		{
			return _finish - _start;
		}

		void reserve(size_t num)
		{
			if (num > capacity())
			{
				size_t oldsize = size();
				T* tmp = new T[num];
				if (_start)
				{
					for (size_t i = 0; i < oldsize; ++i)
					{
						tmp[i] = _start[i];
					}
				}
				_start = tmp;
				_finish = _start + oldsize;
				_end_of_storage = _start + num;
			}
		}

		void resize(size_t num, T val = T())
		{
			if (num < size())
			{
				_finish = _start + num;
			}
			else
			{
				if (num>capacity())
				{
					reserve(num);
				}
				while (_finish != _start + num)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);

			}
			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			assert(!empty());
			--_finish;
		}


		iterator insert(iterator pos, const T& val)
		{
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				//扩容之后得更新pos位置
				pos = _start + len;
			}
			iterator it = _finish - 1;
			while (it >= pos)
			{
				*(it + 1) = *it;
				--it;
			}
			*pos = val;
			++_finish;
			return _start;
		}

		void erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;
		}

		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return _start[pos];
		}

		bool empty()
		{
			return _finish == _start;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	void VectorPrint(const vector<int>& v)
	{
		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;


		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void VectorTest1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		VectorPrint(v);

		v.pop_back();
		
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

	}

	void VectorTest2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		VectorPrint(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		v.resize(10,0);
		VectorPrint(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		v.resize(3);
		VectorPrint(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl;
	}

	void VectorTest3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);


		//v.insert(v.begin(), 100);
		//v.insert(v.begin(), 100);
		//v.insert(v.begin(), 100);
		//v.insert(v.begin(), 100);
		//v.insert(v.begin(), 100);
		//v.insert(v.begin(), 100);
		//v.insert(v.begin(), 100);
		//VectorPrint(v);
		//v.erase(v.begin());
		//VectorPrint(v);


		auto pos = find(v.begin(),v.end(), 2);
		v.insert(pos,0);
		//cout << *pos << endl;
		//VectorPrint(v);
		//cout << v.size() << endl;
		//cout << v.capacity() << endl;

		pos = find(v.begin(), v.end(), 5);
		v.erase(pos);
		cout << *pos << endl;
		VectorPrint(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl;

	}


	void VectorTest4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		VectorPrint(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		auto pos = find(v.begin(), v.end(), 2);
		v.insert(pos, 0);

		VectorPrint(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		++(*pos);
		VectorPrint(v);

		pos = find(v.begin(), v.end(), 4);
		v.erase(pos);
		VectorPrint(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		cout << (*pos) << endl;
	}

}