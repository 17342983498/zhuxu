#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Info
{
public:
	char _name[20];
	char _gender[10];
	int _age;
	char _addres[20];

	void SetInfo(char* name,char* gender,int age,char* addres)
	{
		strcpy(_name,name);
		strcpy(_gender,gender);
		_age = age;
		strcpy(_addres, addres);
	}
	void PrintInfo()
	{
		cout << _name << " " << _gender << " " << _age << " " << _addres << endl;
	}
};

int main()
{
	Info s1, s2, s3, s4;
	s1.SetInfo("ÐÜ´ó", "¹«", 5, "¹·ÐÜÁë");
	s2.SetInfo("ÐÜ¶þ", "¹«", 5, "¹·ÐÜÁë");
	s3.SetInfo("´ä»¨", "Ä¸", 4, "Ç¬ÏØ");
	s4.SetInfo("¹âÍ·Ç¿", "ÄÐ", 30, "¹·ÐÜÁë");
	s1.PrintInfo();
	s2.PrintInfo();
	s3.PrintInfo();
	s4.PrintInfo();
	return 0;
}