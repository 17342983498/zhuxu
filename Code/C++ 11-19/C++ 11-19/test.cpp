#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
int main()
{
	int n = 123456789;
	char arr[32] = { 0 };
	//_itoa(n, arr, 10);
	//for (auto e : arr)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	sprintf(arr, "%d", n);
	sprintf(arr, "%p", n);
	return 0;
}
#endif

#include <sstream>

#if 0
int main()
{
	int n = 123456789;
	string ss;
	stringstream s;
	s << n;
	s >> ss;
	cout << ss << endl;

	double m = 12.34;
	s << m;
	s >> ss;
	cout << ss << endl;//ss��ֵ���ᷢ���ı�
	return 0;
}
#endif

#if 0
int main()
{
	int n = 123456789;
	string ss;
	stringstream s;
	s << n;
	s >> ss;
	cout << ss << endl;

	//s.str("");
	s.clear();

	double m = 12.34;
	s << m;
	s >> ss;
	cout << ss << endl;
	cout << s.str() << endl;
	return 0;
}
#endif

#if 0
int main()
{
	int a = 12345678;
	string sa;
	// ��һ�����α���ת��Ϊ�ַ������洢��string�������
	stringstream s;
	s << a;
	s >> sa;
	// ��stringstream�ײ����string�������ó�"", 
	// ������ת��ʱ���Ὣ���ȫ���ۻ��ڵײ�string������
	s.str("");
	s.clear(); // ���s, ����ջ�ת��ʧ��
	double d = 12.34;
	s << d;
	s >> sa;
	string sValue;
	sValue = s.str(); // str()����������stringsteam�й����string����
	cout << sValue << endl;
	return 0;
}
#endif


int main()
{
	stringstream _str;
	_str << "hello" << " " << "world!";
	_str << "666!!!";
	cout << _str.str() << endl;

	//_str.str("");
	_str << "hello,";
	_str << "bit!";
	cout << _str.str() << endl;
	return 0;
}