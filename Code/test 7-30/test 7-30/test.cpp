#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class num
{
private:
	int _a;//�ó�Ա�����ȿ���stenum������ʹ�ã�Ҳ����printnum������ʹ��
	       //�ó�Ա�����Ϳ��Կ������ȫ�ֱ���
public:
	void setnum(int a)
	{
		_a = a;
		cout << &_a << endl;
	}
	void printnum()
	{
		cout << _a << endl;
		cout << &_a << endl;
	}
};
#if 0
void func()//����������ȫ�ֱ�����ֵ����ô�������������ȫ�ֱ����ĺ���
{
	cout << b << endl;
}
#endif
int b = 20;//ȫ�ֱ���

void func()
{
	cout << b << endl;
}
int main()
{
	num a;
	a.setnum(10);
	a.printnum();
	func();
	cout << b << endl;
	return 0;
}