#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//student将其看成一个学生群体类型
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
//		cout << "姓名:" << _name << " " << "性别:" << _sex << " " << "年龄:" << _age << " " << "住址:" << _addres << endl;
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
		cout << "姓名:" << _name << " " << "性别:" << _sex << " " << "年龄:" << _age << " " << "住址:" << _addres << endl;
	}
};

int main()
{
	student s1,s2,s3,s4;
	s1.setstuInfo("喜羊羊", "公", 5, "羊村");
	s2.setstuInfo("美羊羊", "母", 4, "羊村");
	s3.setstuInfo("懒羊羊", "公", 4, "羊村");
	s4.setstuInfo("灰太狼", "公", 20, "狼堡");
	s1.printstuInfo();
	s2.printstuInfo();
	s3.printstuInfo();
	s4.printstuInfo();
	//s1._age = 10;在这里不能对类的元素进行修改，因为这个类的元素它是私有的，在外面是不可修改的，"privata" 也可改成 "protectd"
	return 0;
}