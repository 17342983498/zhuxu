#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


#define Com(a,b) ((a) > (b)) ? (a) : (b)   // 7
                                           //�ɴ˿ɿ�����ʹ�ú꺯�����ܻ����������
//int Com(int a, int b)                    // 6
//{
//	if (a > b)
//		return a;
//	else
//		return b;
//}
int main()
{
	int a = 5;
	int b = 5;
	int max = Com(++a, b);
	cout << max << endl;
	return 0;
}