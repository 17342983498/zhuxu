#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

//class Person
//{
//public:
//	void InfoPrint()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "zhuxu";
//public:
//	int _age = 23;
//};
//
////�����е�public����������λ��ʹ�ã�protectedֻ���ڻ������������ʹ�ã�privateֻ���ڻ�����ʹ��
//class Student :public Person
//{
//public:
//	void InfoPrint()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//		cout << "stuid:" << _stuid << endl;
//	}
//
//private:
//	string _stuid = "03187021";
//};
//
//int main()
//{
//	//Student s;
//	//s.InfoPrint();
//	//s._age = 0;
//	////s._name = "sad";
//
//	Student s;
//	Person p = s;//���������ֵ���������
//	Person *pp = &s;//ָ��
//	Person& rp = s;//����
//
//	//���಻�ܸ�ֵ��������
//	//�����޷�����������
//	//s = r;
//
//	pp = &s;
//	Student* ps=(Student*)pp;
//	ps->_age = 0;
//	return 0;
//}


class Person
{
protected:
	string _name = "zxzxz";
	int _age = 13;
};

class Student:public Person
{
public:
	void InfoPrint()
	{
		cout << "name:" << _name << endl;
		//��������
		cout << "age:" << Person::_age << endl;
		cout << "age:" << _age << endl;
	}
protected:
	int _age = 23;
};


int main()
{
	Student s;
	s.InfoPrint();
	return 0;
}

