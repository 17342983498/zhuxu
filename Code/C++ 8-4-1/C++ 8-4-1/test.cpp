#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class student
{
private:
	char _name[20];
	char _gender[10];
	int _age;
	char _addres[20];
public:
	student(char* name,char* gender,int age,char* addres)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		strcpy(_addres, addres);
		_age = age;
	}
	void  PrintInfo()
	{
		cout << "���֣�"<< _name << " " << "�Ա�"<< _gender << " " << "���䣺"<< _age << " " << "סַ��"<< _addres << endl;
	}
};

int main()
{
	student s1("�ܴ�", "��", 5, "������");
	s1.PrintInfo();
	return 0;


}