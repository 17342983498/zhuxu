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
	cout << "ÐÕÃû:" << _name << " " << "ÐÔ±ð:" << _sex << " " << "ÄêÁä:" << _age << " " << "×¡Ö·:" << _addres << endl;
}


int main()
{
	student s1, s2, s3, s4;
	s1.setstuInfo("Ï²ÑòÑò", "¹«", 5, "Ñò´å");
	s1.printstuInfo();
	s2.setstuInfo("ÃÀÑòÑò", "Ä¸", 4, "Ñò´å");
	s2.printstuInfo();
	s3.setstuInfo("ÀÁÑòÑò", "¹«", 4, "Ñò´å");
	s3.printstuInfo();
	s4.setstuInfo("»ÒÌ«ÀÇ", "¹«", 20, "ÀÇ±¤");
	s4.printstuInfo();
	return 0;
}