#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
//int main()
//{
//	int arr[] = { 3, 2, 5, 8, 9, 4, 1, 7, 6, 10, 1 };
//	int i = 0;
//	int j = 0;
//	int tmp = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = i + 1; j < sz; j++)
//		{
//			if (arr[i]>arr[j])
//			{
//				tmp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = tmp;
//			}
//		}
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//void swap(int *p1, int *p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//void swaparray()
//{
//	int A[5] = { 1, 3, 5, 7, 9 };
//	int B[5] = { 2, 4, 6, 8, 10 };
//	int len = sizeof(A) / sizeof(A[0]);
//	int i = 0;
//
//
//	for (i = 0; i < len; i++)
//	{
//		swap(&A[i], &B[i]);
//	}
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", B[i]);
//	}
//}
//int main()
//{
//	swaparray();
//	system("pause");
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include"game.h"
//
//void menu()
//{
//	printf("      ��ӭ����������С��Ϸ��   \n");
//	printf("*******************************\n");
//	printf("*******************************\n");
//	printf("*********  1.play  ************\n");
//	printf("*********  0.exit  ************\n");
//	printf("*******************************\n");
//}
//void game()
//{
//	char ret;
//	char board[ROW][COL] = { 0 };
//	InitBoard(board, ROW, COL);//��ʼ������
//	PrintBoard(board, ROW, COL);//��ӡ����
//
//	while (1)
//	{
//		printf("�����\n");
//		PlayerMove(board, ROW, COL);
//		PrintBoard(board, ROW, COL);
//		is_full(board, ROW, COL);
//		ret = DisplayBoard(board, ROW, COL);
//		if (ret == 'X')
//		{
//			printf("���Ӯ��\n");
//			break;
//		}
//		else if (ret == 'O')
//		{
//			printf("����Ӯ��\n");
//			break;
//		}
//		else if (ret == 'p')
//		{
//			printf("ƽ�֣�\n");
//			break;
//		}
//		printf("������\n");
//		ComputerMove(board, ROW, COL);
//		PrintBoard(board, ROW, COL);
//		//�ж�
//
//		if (ret == 'X')
//		{
//			printf("���Ӯ��\n");
//			break;
//		}
//		else if (ret == 'O')
//		{
//			printf("����Ӯ��\n");
//			break;
//		}
//		else if (ret == 'p')
//		{
//			printf("ƽ�֣�\n");
//			break;
//		}
//
//	}
//}
//void test()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("��ѡ��:>\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			//����Ϸ
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ��\n");
//			break;
//		default:
//			printf("ѡ�����������ѡ��\n");
//			break;
//		}
//	} while (input);
//}
//int main()
//{
//	test();
//	return 0;
//
//}
//#include <stdio.h>
//#include <string.h>
//void Init(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = i;
//	}
//}
//
//void Reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//void Print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
//	int sz = sizeof(arr) / sizeof(arr[10]);
//	int i = 0;
//	printf("ԭ���飺\n");
//	Print(arr, sz);
//	Init(arr, sz);
//	printf("��ʼ�����飺\n");
//	Print(arr, sz);
//	Reverse(arr, sz);
//	printf("�������飺\n");
//	Print(arr, sz);
//	return 0;
//}
