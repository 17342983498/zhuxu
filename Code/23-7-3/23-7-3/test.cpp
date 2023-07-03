#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <thread>
using namespace std;

//double Division(int left,int right)
//{
//	if (right == 0)
//		throw "Division by zero condition!";
//	else if (left == 0)
//	{
//		throw 'x';
//	}
//	else
//		return (double)left / (double)right;
//}


//void Func()
//{
//	int x, y;
//	cin >> x >> y;
//	cout << Division(x, y) << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* msg)
//	{
//		cout << msg << endl;
//	}
//	return 0;
//}


//void Func()
//{
//	int x, y;
//	cin >> x >> y;
//	try
//	{
//		cout << Division(x, y) << endl;
//	}
//	catch (char* msg)
//	/*catch (const char* msg)*/
//	{
//		cout << msg << endl;
//	}
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* msg)
//	{
//		cout << msg << endl;
//	}
//	catch (char c)
//	{
//		cout << c << endl;
//	}
//	return 0;
//}


//class Exception
//{
//public:
//	Exception(const string& errmsg, int errid)
//		:_errmsg(errmsg)
//		, _errid(errid)
//	{}
//
//	const string& _Getmsg() const
//	{
//		return _errmsg;
//	}
//
//	int _Getid() const
//	{
//		return _errid;
//	}
//
//	//const string Getmsg()const
//	//{
//	//	return _Getmsg();
//	//}
//
//	//int Getid()
//	//{
//	//	return _Getid();
//	//}
//private:
//	string _errmsg;
//	int _errid;
//};
//
//
//double Division(int left,int right)
//{
//	if (right == 0)
//	{
//		//生成一个异常对象，被catch捕获它的临时拷贝
//		Exception err("除0错误", 1);
//		throw err;
//		//throw 1;
//	}
//	else
//		return (double)left / (double)right;
//}
//
//void Func()
//{
//	int x, y;
//	cin >> x >> y;
//	cout<< Division(x, y) << endl;
//}
//
//
//int main()
//{
//	while (1)
//	{
//		try
//		{
//			Func();
//		}
//		catch (const Exception& e)
//		{
//			cout << e._Getid() << "--" << e._Getmsg() << endl;
//		}
//		catch (...)
//		{
//			cout << "未知异常" << endl;
//		}
//	}
//	return 0;
//}




//class Exception
//{
//public:
//	Exception(const string& errmsg, int errid)
//		:_errmsg(errmsg)
//		, _errid(errid)
//	{}
//
//	virtual string what() const
//	{
//		return _errmsg;
//	}
//
//	int _Getid() const
//	{
//		return _errid;
//	}
//
//protected:
//	string _errmsg;
//	int _errid;
//};
//
//class SqlException:public Exception
//{
//public:
//	SqlException(const string& errmsg, int errid, const string& sql)
//		:Exception(errmsg, errid)
//		, _sql(sql)
//	{}
//
//	virtual string what()const
//	{
//		string msg = "SqlException: ";
//		msg += _errmsg;
//		msg += "->";
//		msg += _sql;
//		return msg;
//	}
//
//protected:
//	const string _sql;
//};
//
//
//class CacheException :public Exception
//{
//public:
//	CacheException(const string& errmsg, int errid)
//		:Exception(errmsg, errid)
//	{}
//
//	virtual string what()const
//	{
//		string msg = "CacheException: ";
//		msg += _errmsg;
//		return msg;
//	}
//};
//
//class HttpException :public Exception
//{
//public:
//	HttpException(const string& errmsg, int errid, const string& type)
//		:Exception(errmsg, errid)
//		,_type(type)
//	{}
//
//	virtual string what()const
//	{
//		string msg = "HttpException: ";
//		msg += _errmsg;
//		msg += "->";
//		msg += _type;
//		return msg;
//	}
//
//protected:
//	const string _type;
//};
//
//void SQLMgr()
//{
//	srand(time(0));
//	if (rand() % 7 == 0)
//	{
//		throw SqlException("权限不足", 100, "select * from name = '张三'");
//	}
//	cout << "请求成功" << endl;
//}
//void CacheMgr()
//{
//	srand(time(0));
//	if (rand() % 5 == 0)
//	{
//		throw CacheException("权限不足", 100);
//	}
//	else if (rand() % 6 == 0)
//	{
//		throw CacheException("数据不存在", 101);
//	}
//	SQLMgr();
//}
//void HttpServer()
//{
//	// 模拟异常
//	srand(time(0));
//	if (rand() % 3 == 0)
//	{
//		throw HttpException("请求资源不存在", 100, "get");
//	}
//	else if (rand() % 4 == 0)
//	{
//		throw HttpException("权限不足", 101, "post");
//	}
//	CacheMgr();
//}
//
//int main()
//{
//	while (1)
//	{
//		this_thread::sleep_for(chrono::seconds(1));
//		try{
//			HttpServer();
//		}
//		catch (const Exception& e) // 这里捕获父类对象就可以
//		{
//			// 多态
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//	return 0;
//}


double Division(int a, int b)
{
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func()
{
	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
	// 重新抛出去。
	int* array = new int[10];
	try 
	{
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete []" << array << endl;
		delete[] array;
		throw;
	}
	cout << "delete []" << array << endl;
	delete[] array;
}

int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	return 0;
}