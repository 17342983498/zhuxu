#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>

#if 0
class Person
{
public:
	void Eat()
	{
		cout << "���ڳԷ���" << endl;
	}
	void Sleep()
	{
		cout << "����˯����" << endl;
	}
private:
	string _name;
	string _gender;
	int _age;
};

class Student:public Person
{
	void Study()
	{
		cout << "����ѧϰ��" << endl;
	}
private:
	int _StuID;
};


class Teacher :public Person
{
public:
	void Teach()
	{
		cout << "���ڽ��飡" << endl;
	}
private:
	int TeaID;
};

int main()
{
	Teacher t;
	t.Teach();
	t.Eat();
	t.Sleep();
	return 0;
}
#endif


#if 0
class Person
{
public:
	void Eat()
	{
		cout << "���ڳԷ���" << endl;
	}
	void Sleep()
	{
		cout << "����˯����" << endl;
	}

	//�Ȳ���������ʹ�ã�Ҳ������������ʹ��
private:
	string _name;

	//����������ʹ�ã�������������ʹ��
protected:
	string _gender;

	//����λ�ö���ʹ��
public:
	int _age;
};

class Student:public Person
{
public:
	void Study()
	{
		//����Ȩ�ޣ�public
		_age = 23;
		//����Ȩ�ޣ�protected
		_gender = "��";
		//����Ȩ��Ϊ private ,���ɷ���
		_name = "zhuxu";
		cout << "����ѧϰ��" << endl;
	}
private:
	int _StuID;
};
class A :public Student
{
public:
	void test()
	{
		_age = 23;
		_gender = "��";
		_name;
	}
};


int main()
{
	Student t;
	t._age = 20;
	t._name = "zhuxu";
	t._gender = "��";
	
	A a;
	a._age = 23;
	a._gender;
	return 0;
}
#endif


#if 0
class Person
{
public:
	void Eat()
	{
		cout << "���ڳԷ���" << endl;
	}
	void Sleep()
	{
		cout << "����˯����" << endl;
	}

private:
	string _name;

protected:
	string _gender;

public:
	int _age;
};

class Student :protected Person
{
public:
	void Study()
	{
		//����Ȩ�ޣ�protected
		_age = 23;
		
		//Ϊʲô֪�����ߵ�Ȩ����protected��,����Ϊ���������ⲻ��ʹ�ã�������������ʹ��

		//����Ȩ�ޣ�protected
		_gender = "��";

		//����Ȩ��Ϊ private ,���ɷ���
		_name = "zhuxu";

	}
private:
	int _StuID;
};

class A :public Student
{
public:
	void test()
	{
		_age = 24;
		_gender = "��";
	}
};


int main()
{
	Student t;
	t._age;
	t._gender;
	t._name;

	A a;
	a._age;
	a._gender;
	return 0;
}
#endif





class Person
{
public:
	void Eat()
	{
		cout << "���ڳԷ���" << endl;
	}
	void Sleep()
	{
		cout << "����˯����" << endl;
	}

private:
	string _name;

protected:
	string _gender;

public:
	int _age;
};

class Student :private Person
{
public:
	void Study()
	{
		//����Ȩ�ޣ�private
		_age = 23;

		//����Ȩ�ޣ�private
		_gender = "��";

		//����Ȩ��Ϊ private ,���ɷ���
		_name = "zhuxu";

	}
private:
	int _StuID;
};
class A :public Student
{
public:
	void test()
	{
		_gender = "��";
		_age = 23;
	}
};


int main()
{
	Student t;
	t._name = "zhuxu";
	t._gender = "��";
	t._age = 24;
	return 0;
}
