#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


//// ר�Ŵ���int�ļӷ�����
//
//int Add(int left, int right)
//{
//	cout << "1" << endl;
//	return left + right;
//}
//
//
//// ͨ�üӷ�����
//
//template<class T>
//
//T Add(T left, T right)
//{
//	cout << "2" << endl;
//	return left + right;
//}
//
//
//
//int main()
//{
//	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2);
//	Add(1, 2.0);
//	int a = 0;
//	double b = 1;
//	Add<int>(a, b);
//	return 0;
//}



//int Add(int left, int right)
//{
//	cout << "0" << endl;
//	return left + right;
//}
//
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	cout << "1" << endl;
//	return left + right;
//}
//
//int main()
//{
//	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//	//Add<int,int>(1, 2.0);
//	return 0;
//}





int main()
{
	int n = 0;
	cin >> n;
	int flag = 1;
	int count = 0, maxcount = 0;
	for (int i = 0; i<32; i++)
	{
		if ((n >> i & 1) == 1)
		{
			count++;
		}
		else
		{
			if (count>maxcount)
			{
				maxcount = count;
			}
			count = 0;
		}
	}
	if (count>maxcount)
	{
		maxcount = count;
	}
	cout << maxcount << endl;
	return 0;
}