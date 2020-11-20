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
		cout << "我在吃饭！" << endl;
	}
	void Sleep()
	{
		cout << "我在睡觉！" << endl;
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
		cout << "我在学习！" << endl;
	}
private:
	int _StuID;
};


class Teacher :public Person
{
public:
	void Teach()
	{
		cout << "我在教书！" << endl;
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
		cout << "我在吃饭！" << endl;
	}
	void Sleep()
	{
		cout << "我在睡觉！" << endl;
	}

	//既不能在类外使用，也不能在子类中使用
private:
	string _name;

	//不能在类外使用，但可在子类中使用
protected:
	string _gender;

	//两种位置都可使用
public:
	int _age;
};

class Student:public Person
{
public:
	void Study()
	{
		//访问权限：public
		_age = 23;
		//访问权限：protected
		_gender = "男";
		//访问权限为 private ,不可访问
		_name = "zhuxu";
		cout << "我在学习！" << endl;
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
		_gender = "男";
		_name;
	}
};


int main()
{
	Student t;
	t._age = 20;
	t._name = "zhuxu";
	t._gender = "男";
	
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
		cout << "我在吃饭！" << endl;
	}
	void Sleep()
	{
		cout << "我在睡觉！" << endl;
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
		//访问权限：protected
		_age = 23;
		
		//为什么知道两者的权限是protected呢,是因为他两在类外不能使用，但可在子类中使用

		//访问权限：protected
		_gender = "男";

		//访问权限为 private ,不可访问
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
		_gender = "男";
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
		cout << "我在吃饭！" << endl;
	}
	void Sleep()
	{
		cout << "我在睡觉！" << endl;
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
		//访问权限：private
		_age = 23;

		//访问权限：private
		_gender = "男";

		//访问权限为 private ,不可访问
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
		_gender = "男";
		_age = 23;
	}
};


int main()
{
	Student t;
	t._name = "zhuxu";
	t._gender = "男";
	t._age = 24;
	return 0;
}
