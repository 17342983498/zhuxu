#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//int main()
//{
//	struct S s = { 0 };
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//	return 0;
//}


//union Un
//{
//	int i;
//	char c;
//};
//int main()
//{
//	union Un un;
//	printf("%d\n", &(un.i));
//	printf("%d\n", &(un.c));
//	return 0;
//}



//union Un
//{
//	int i;
//	char c;
//};
//int main()
//{
//	union Un un;
//	printf("%d\n", &(un.i));
//	printf("%d\n", &(un.c));
//	un.c = 0x55;
//	un.i = 0x11223344;
//	//un.c = 0x55;
//	printf("%x\n", un.i);
//	return 0;
//}


//union Un
//{
//	short s[6];
//	int a;
//};
//int main()
//{
//	printf("%d\n", sizeof(union Un));
//	return 0;
//}


#pragma pack(2)//设置默认对齐数为2

struct S1
{
	char c1;//1 2 1
	int i;//4 2 2
	char c2;//1 2 1
};

#pragma pack()//取消设置的默认对齐数，还原为默认

int main()
{
	printf("%d\n", sizeof(struct S1));
	return 0;
}