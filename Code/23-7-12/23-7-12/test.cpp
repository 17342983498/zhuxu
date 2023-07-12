#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 2000, int month = 1, int day = 9)
		:_year(year), _month(month), _day(day)
	{}

	operator bool()
	{
		if (_year == 0)
		{
			return false;
		}
		return true;
	}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator << (ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日";
	return out;
}

istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}
//
//int main()
//{
//	Date d(2023, 7, 12);
//	cout << d;
//
//	//cin >> d;
//	//cout << d;
//
//	while (d)
//	{
//		cin >> d;
//		cout << d;
//	}
//	return 0;
//}

#include <fstream>

//int main()
//{
//	ofstream ofs("test.txt", ofstream::out||ofstream::binary);
//	ofs << "i am a boy!";
//	//ofs << "i am a girl!";
//
//	//ifstream ifs("test.txt", ofstream::in);
//	return 0;
//}

#include <string>

struct ServerInfo
{
	//char _address[32];
	string _address;
	int _port;
	Date _date;
};

class ConfigManager
{
public:
	ConfigManager(const char* filename)
		:_filename(filename)
	{}

	//二进制读写，不能使用string
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_filename, ofstream::out | ofstream::binary);
		ofs.write((const char*)&info, sizeof(info));
	}

	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_filename, ifstream::in | ifstream::binary);
		ifs.read((char*)&info, sizeof(info));
	}
	//文本读写
	void WriteText(const ServerInfo& info)
	{
		ofstream ofs(_filename);
		ofs << info._address << endl;
		ofs << info._port << endl;
		ofs << info._date << endl;
	}

	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_filename);
		ifs >> info._address;
		ifs >> info._port;
		ifs >> info._date;
	}
private:
	string _filename; // 配置文件
};

//int main()
//{
//	ServerInfo winfo = { "192.0.0.1sdasdsdassaddsadsadasdasdas", 100, { 2023, 7, 12 } };//	string str;//	cin >> str;//	if (str == "二进制写")//	{//		ConfigManager cm("test.txt");
//		cm.WriteBin(winfo);//	}//	else if (str == "二进制读")//	{//		ServerInfo rinfo;//		ConfigManager cm("test.txt");//		cm.ReadBin(rinfo);//		cout << rinfo._address << " " << rinfo._port << " " << rinfo._date;//	}//	else if (str == "文本写")//	{//		ConfigManager cm("test.txt");//		cm.WriteText(winfo);//	}//	else if (str == "文本读")//	{//		ServerInfo rinfo;//		ConfigManager cm("test.txt");//		cm.ReadText(rinfo);//		cout << rinfo._address << endl;
//		cout << rinfo._port << endl;
//		cout << rinfo._date << endl;//	}//	return 0;
//}


#include <sstream>
//int main()
//{
//	//int a = 1;
//	//double b = 3.14;
//	//string str = "iamagirl!";
//
//	ostringstream oss;
//	oss << 1 << " ";
//	oss << 3.14 << " ";
//	oss << "iamagirl!";
//
//	string str = oss.str();
//	cout << str << endl;
//
//	istringstream iss(str);
//	int a;
//	double b;
//	string s;
//	iss >> a >> b >> s;
//	cout << a << endl;
//	cout << b << endl;
//	cout << s << endl;
//}


// 序列化和反序列化
struct ChatInfo
{
	string _name; // 姓名
	int _id;      // ID
	Date _date;   // 时间
	string _msg;  // 描述
};

int main()
{
	ChatInfo winfo = { "张三", 135246, { 2023, 7, 12 }, "晚上一起看电影吧" };
	stringstream oss;
	oss << winfo._name << " ";
	oss << winfo._id << " ";
	oss << winfo._date << " ";
	oss << winfo._msg;
	string str = oss.str();
	cout << str << endl;

	stringstream iss(str);
	ChatInfo rinfo;
	iss >> rinfo._name;
	iss >> rinfo._id;
	iss >> rinfo._date;
	iss >> rinfo._msg;
	cout << rinfo._msg << endl;

	//cout << "-------------------------------------------------------" << endl;
	//cout << "姓名：" << rinfo._name << "(" << rinfo._id << ") ";
	//cout << rinfo._date << endl;
	//cout << rinfo._name << ":>" << rinfo._msg << endl;
	//cout << "-------------------------------------------------------" << endl;

	return 0;
}