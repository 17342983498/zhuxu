#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//
//int check_sys()
//{
//	int a = 1;
//	return *(char*)&a;
//}
//
//int main()
//{
//	int a = 1;
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}


//int main()
//{
//	int a = 1;
//	return 0;
//}

//union Un
//{
//	int a;
//	char b;
//};

int check_sys()
{
	union 
	{
		int a;
		char b;
	}un;
	un.a = 1;
	return un.b;
}


int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}