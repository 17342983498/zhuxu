#define _CRT_SECURE_NO_WARNINGS 1
#include"Person.h"
#include<iostream>
using namespace std;

void student::setstuInfo(const char* name, const char* sex, int age, const char* addres)
{
	strcpy(_name, name);
	strcpy(_sex, sex);
	_age = age;
	strcpy(_addres, addres);
}
void student::printstuInfo()
{
	cout << "����:" << _name << " " << "�Ա�:" << _sex << " " << "����:" << _age << " " << "סַ:" << _addres << endl;
}


int main()
{
	student s1, s2, s3, s4;
	s1.setstuInfo("ϲ����", "��", 5, "���");
	s1.printstuInfo();
	s2.setstuInfo("������", "ĸ", 4, "���");
	s2.printstuInfo();
	s3.setstuInfo("������", "��", 4, "���");
	s3.printstuInfo();
	s4.setstuInfo("��̫��", "��", 20, "�Ǳ�");
	s4.printstuInfo();
	return 0;
}