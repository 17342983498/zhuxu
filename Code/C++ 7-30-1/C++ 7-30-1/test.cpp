#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//student���俴��һ��ѧ��Ⱥ������
//struct student
//{
//	char _name[20];
//	char _sex[5];
//	int _age;
//	char _addres[20];
//	void setstuInfo(const char* name,const char* sex,int age,const char* addres)
//	{
//		strcpy(_name, name);
//		strcpy(_sex, sex);
//		_age = age;
//		strcpy(_addres, addres);
//	}
//	void printstuInfo()
//	{
//		cout << "����:" << _name << " " << "�Ա�:" << _sex << " " << "����:" << _age << " " << "סַ:" << _addres << endl;
//	}
//};


class student
{
private:
	char _name[20];
	char _sex[5];
	int _age;
	char _addres[20];
public:
	void setstuInfo(const char* name, const char* sex, int age, const char* addres)
	{
		strcpy(_name, name);
		strcpy(_sex, sex);
		_age = age;
		strcpy(_addres, addres);
	}
	void printstuInfo()
	{
		cout << "����:" << _name << " " << "�Ա�:" << _sex << " " << "����:" << _age << " " << "סַ:" << _addres << endl;
	}
};

int main()
{
	student s1,s2,s3,s4;
	s1.setstuInfo("ϲ����", "��", 5, "���");
	s2.setstuInfo("������", "ĸ", 4, "���");
	s3.setstuInfo("������", "��", 4, "���");
	s4.setstuInfo("��̫��", "��", 20, "�Ǳ�");
	s1.printstuInfo();
	s2.printstuInfo();
	s3.printstuInfo();
	s4.printstuInfo();
	//s1._age = 10;�����ﲻ�ܶ����Ԫ�ؽ����޸ģ���Ϊ������Ԫ������˽�еģ��������ǲ����޸ĵģ�"privata" Ҳ�ɸĳ� "protectd"
	return 0;
}