#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class student
{
public:
	char _name[20];
	char _sex[10];
	int _age;
	char _addres[20];
	void setstuInfo(/*student* this,*/char name[], char sex[], int age, char addres[])
	{
		cout << this << endl;
		strcpy(this->_name, name);
		strcpy(this->_sex, sex);
		this->_age = age;
		strcpy(this->_addres, addres);

	}
	void printstuInfo()
	{
		cout << this->_name << " " << this->_sex << " " << this->_age << " " << this->_addres << endl;
	}
};

int main()
{
	//Ϊʲô��C++�У�ÿ���������ܹ�׼ȷ���ҵ��Լ�����Ӧ�Ľṹ��ʵ���أ�
	//ÿ���ࡰ��Ա����������һ��Ĭ�ϵĲ������ò���ʱ�̶�ָ����øó�Ա�����Ķ��󣬽��ò�����Ϊthisָ�롣
	//thisָ���Ǳ������ڱ�������ڼ��Զ����ϵ�
	student s1, s2, s3, s4;
	cout << &s1 << endl;
	s1.setstuInfo("ϲ����", "��", 5, "���");
	//���൱��������  s1.setstuInfo(&s1,"ϲ����", "��", 5, "���");
	cout << &s2 << endl;
	s2.setstuInfo("������", "ĸ", 4, "���");
	cout << &s3 << endl;
	s3.setstuInfo("������", "��", 4, "���");
	cout << &s4 << endl;
	s4.setstuInfo("��̫��", "��", 20, "�Ǳ�");
	s1.printstuInfo();
	//s1.printstuInfo(&s1);
	s2.printstuInfo();
	s3.printstuInfo();
	s4.printstuInfo();
	return 0;
}