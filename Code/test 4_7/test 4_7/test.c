#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//����ָ��
//void Print(char* str)
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	void(*p)(char*) = Print;
//	(*p)("hello,world!");
//	return 0;
//}
void menu()
{
	printf("**************************\n");
	printf("***   1.Add   2.Sub    ***\n");
	printf("***   3.Mul   4.Div    ***\n");
	printf("*******   0.exit   *******\n");
	printf("**************************\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do
//	{
//		menu();
//		printf("������һ������>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("������������������>");
//			scanf("%d %d", &x, &y);
//			printf("%d\n",Add(x,y));
//			break;
//		case 2:
//			printf("������������������>");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", Sub(x, y));
//			break;
//		case 3:
//			printf("������������������>");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", Mul(x, y));
//			break;
//		case 4:
//			printf("������������������>");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", Div(x, y));
//			break;
//		case 0:
//			printf("�˳�����");
//				break;
//		default:
//			printf("����������������룡");
//				break;
//		}
//	} while (input);
//	return 0;
//}
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int input = 0;
//	int(*pfArr[5])(int, int) = { 0, Add, Sub, Mul, Div };
//	do
//	{
//		menu();
//		printf("������һ������");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("������������������");
//			scanf("%d %d", &x, &y);
//			int ret = (*pfArr[input])(x, y);//*����ʡ��
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�Ƴ�����\n");
//		}
//		else
//		{
//			printf("����������������룡\n");
//		}
//	} while (input);
//	return 0;
//}
void Calc(int(*pf)(int, int))
{
	int x = 0;
	int y = 0;
	printf("������������������>");
	scanf("%d %d", &x, &y);
	printf("%d\n", (*pf)(x, y));
}
int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	do
	{
		menu();
		printf("������һ������>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Calc(Add);
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		case 0:
			printf("�˳�����\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
	return 0;
}