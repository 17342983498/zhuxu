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
	out << d._year << "��" << d._month << "��" << d._day << "��";
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

	//�����ƶ�д������ʹ��string
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
	//�ı���д
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
	string _filename; // �����ļ�
};

//int main()
//{
//	ServerInfo winfo = { "192.0.0.1sdasdsdassaddsadsadasdasdas", 100, { 2023, 7, 12 } };//	string str;//	cin >> str;//	if (str == "������д")//	{//		ConfigManager cm("test.txt");
//		cm.WriteBin(winfo);//	}//	else if (str == "�����ƶ�")//	{//		ServerInfo rinfo;//		ConfigManager cm("test.txt");//		cm.ReadBin(rinfo);//		cout << rinfo._address << " " << rinfo._port << " " << rinfo._date;//	}//	else if (str == "�ı�д")//	{//		ConfigManager cm("test.txt");//		cm.WriteText(winfo);//	}//	else if (str == "�ı���")//	{//		ServerInfo rinfo;//		ConfigManager cm("test.txt");//		cm.ReadText(rinfo);//		cout << rinfo._address << endl;
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


// ���л��ͷ����л�
struct ChatInfo
{
	string _name; // ����
	int _id;      // ID
	Date _date;   // ʱ��
	string _msg;  // ����
};

int main()
{
	ChatInfo winfo = { "����", 135246, { 2023, 7, 12 }, "����һ�𿴵�Ӱ��" };
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
	//cout << "������" << rinfo._name << "(" << rinfo._id << ") ";
	//cout << rinfo._date << endl;
	//cout << rinfo._name << ":>" << rinfo._msg << endl;
	//cout << "-------------------------------------------------------" << endl;

	return 0;
}