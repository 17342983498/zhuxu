#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//struct S3 { double d;    char c;    int i; }; 
//struct S4 { char c1;    struct S3 s3;    double d; };
//int main()
//{
//	printf("%d\n", sizeof(struct S4));
//	return 0;
//}


#include <stdio.h>
#pragma pack(8)//����Ĭ�϶�����Ϊ8 
struct S1 {    char c1;    int i;    char c2; }; 
#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭΪĬ��
#pragma pack(1)//����Ĭ�϶�����Ϊ8 
struct S2 {    char c1;    int i;    char c2; }; 
#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭΪĬ�� 
int main()
{
	printf("%d\n", sizeof(struct S1));
	printf("%d\n", sizeof(struct S2));
	return 0;
}
