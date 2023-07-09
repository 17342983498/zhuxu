#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

////设计一个类，不能被拷贝
////C++98
//class CopyBan
//{
//public:
//	CopyBan()
//	{}
//private:
//	CopyBan(const CopyBan& cb);
//	CopyBan& operator=(const CopyBan& cb);
//};
//
////C++11
//class CopyBan
//{
//public:
//	CopyBan()
//	{}
//	CopyBan(const CopyBan& cb) = delete;
//	CopyBan& operator=(const CopyBan& cb) = delete;
//};
//
//
//int main()
//{
//	CopyBan cp1;
//	CopyBan cp2(cp1);
//	CopyBan cp3 = cp1;
//}


//设计一个类，只能在堆上创建对象
//class HeapOnly
//{
//public:
//	void Destroy()
//	{
//		delete this;
//	}
//private:
//	~HeapOnly()
//	{}
//};
//
//int main()
//{
//	//这种是在栈上申请，将析构私有就不能栈上申请了
//	/*HeapOnly ho1;
//	static HeapOnly ho2;*/
//
//	HeapOnly* hp3 = new HeapOnly;
//	hp3->Destroy();
//}


//class HeapOnly
//{
//public:
//	static HeapOnly* CreateObject()
//	{
//		return new HeapOnly;
//	}
//private:
//	HeapOnly()
//	{}
//
//	HeapOnly(const HeapOnly& ho) = delete;
//	HeapOnly& operator=(const HeapOnly& cb) = delete;
//};
//
//int main()
//{
//	HeapOnly* ho1 = HeapOnly::CreateObject();
//	//HeapOnly ho2(*ho1);
//	HeapOnly* ho3 = HeapOnly::CreateObject();
//	ho3 = ho1;
//}


//设计一个类，只能在栈上创建对象
//class StackOnly
//{
//public:
//	static StackOnly CreateObj()
//	{
//		return StackOnly();
//	}
//
//	StackOnly(StackOnly&& st)
//	{}
//private:
//	StackOnly()
//	{}
//	StackOnly(const StackOnly& st) = delete;
//	StackOnly& operator=(const StackOnly& so) = delete;
//};
//
//int main()
//{
//	StackOnly so1 = StackOnly::CreateObj();
//	static StackOnly so2 = so1;
//}


#include <vector>
#include <string>
#include <mutex>
#include <thread>
#include <time.h>

//饿汉模式
//最开始（mian函数之前）就创建
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return _ins;
//	}
//
//	void Add(const string& str)
//	{
//		_mutex.lock();
//		_v.push_back(str);
//		_mutex.unlock();
//	}
//
//	void Print()
//	{
//		_mutex.lock();
//		for (auto& e : _v)
//		{
//			cout << e << endl;
//		}
//		cout << endl;
//		_mutex.unlock();
//	}
//private:
//	Singleton()
//	{}
//
//	vector<string> _v;
//	static Singleton* _ins;
//	mutex _mutex;
//};
//
//Singleton* Singleton::_ins = new Singleton;

//int main()
//{
//	Singleton::GetInstance()->Add("张三");
//	Singleton::GetInstance()->Add("李四");
//	Singleton::GetInstance()->Add("王五");
//	Singleton::GetInstance()->Print();
//}


//懒汉模式
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		//双检查加锁
		if (_ins == nullptr)// 提高效率，不需要每次获取单例都要加锁解锁
		{
			_imutex.lock();
			if (_ins == nullptr)//保证线程安全和只new一次
			{
				_ins = new Singleton;
			}
			_imutex.unlock();
		}
		return _ins;
	}

	// 一般全局都要使用单例对象，所以单例对象一般不需要显示释放
	// 有些特殊场景，想显示释放一下
	static void DelInstance()
	{
		_imutex.lock();
		if (_ins)
		{
			delete _ins;
			_ins = nullptr;
		}
		_imutex.unlock();
	}

	// 单例对象回收
	class GC
	{
	public:
		~GC()
		{
			DelInstance();
		}
	};

	static GC _gc;

	void Add(const string& str)
	{
		_vmutex.lock();
		_v.push_back(str);
		_vmutex.unlock();
	}

	void Print()
	{
		_vmutex.lock();
		for (auto& e : _v)
		{
			cout << e << endl;
		}
		cout << endl;
		_vmutex.unlock();
	}

	~Singleton()
	{
		// 持久化
		// 比如要求程序结束时，将数据写到文件，单例对象析构时持久化就比较好
	}
private:
	Singleton()
	{}

	vector<string> _v;
	static Singleton* _ins;
	mutex _vmutex;
	static mutex _imutex;
};

Singleton* Singleton::_ins = new Singleton;
mutex Singleton::_imutex;

Singleton::GC Singleton::_gc;

int main()
{
	srand(time(0));

	int n = 100;
	thread t1([n](){
		for (size_t i = 0; i < n; ++i)
		{
			Singleton::GetInstance()->Add("t1线程:" + to_string(rand()));
		}
	});

	thread t2([n](){
		for (size_t i = 0; i < n; ++i)
		{
			Singleton::GetInstance()->Add("t2线程:" + to_string(rand()));
		}
	});

	t1.join();
	t2.join();

	Singleton::GetInstance()->Print();

	return 0;
}