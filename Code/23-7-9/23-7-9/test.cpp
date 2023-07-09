#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

////���һ���࣬���ܱ�����
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


//���һ���ֻ࣬���ڶ��ϴ�������
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
//	//��������ջ�����룬������˽�оͲ���ջ��������
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


//���һ���ֻ࣬����ջ�ϴ�������
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

//����ģʽ
//�ʼ��mian����֮ǰ���ʹ���
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
//	Singleton::GetInstance()->Add("����");
//	Singleton::GetInstance()->Add("����");
//	Singleton::GetInstance()->Add("����");
//	Singleton::GetInstance()->Print();
//}


//����ģʽ
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		//˫������
		if (_ins == nullptr)// ���Ч�ʣ�����Ҫÿ�λ�ȡ������Ҫ��������
		{
			_imutex.lock();
			if (_ins == nullptr)//��֤�̰߳�ȫ��ֻnewһ��
			{
				_ins = new Singleton;
			}
			_imutex.unlock();
		}
		return _ins;
	}

	// һ��ȫ�ֶ�Ҫʹ�õ����������Ե�������һ�㲻��Ҫ��ʾ�ͷ�
	// ��Щ���ⳡ��������ʾ�ͷ�һ��
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

	// �����������
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
		// �־û�
		// ����Ҫ��������ʱ��������д���ļ���������������ʱ�־û��ͱȽϺ�
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
			Singleton::GetInstance()->Add("t1�߳�:" + to_string(rand()));
		}
	});

	thread t2([n](){
		for (size_t i = 0; i < n; ++i)
		{
			Singleton::GetInstance()->Add("t2�߳�:" + to_string(rand()));
		}
	});

	t1.join();
	t2.join();

	Singleton::GetInstance()->Print();

	return 0;
}