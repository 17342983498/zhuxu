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
	//为什么在C++中，每个函数都能够准确的找到自己所对应的结构体实体呢？
	//每个类“成员函数”都有一个默认的参数，该参数时刻都指向调用该成员函数的对象，将该参数成为this指针。
	//this指针是编译器在编译类的期间自动加上的
	student s1, s2, s3, s4;
	cout << &s1 << endl;
	s1.setstuInfo("喜羊羊", "公", 5, "羊村");
	//就相当于这里是  s1.setstuInfo(&s1,"喜羊羊", "公", 5, "羊村");
	cout << &s2 << endl;
	s2.setstuInfo("美羊羊", "母", 4, "羊村");
	cout << &s3 << endl;
	s3.setstuInfo("懒羊羊", "公", 4, "羊村");
	cout << &s4 << endl;
	s4.setstuInfo("灰太狼", "公", 20, "狼堡");
	s1.printstuInfo();
	//s1.printstuInfo(&s1);
	s2.printstuInfo();
	s3.printstuInfo();
	s4.printstuInfo();
	return 0;
}