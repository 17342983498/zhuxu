#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("\n\n\t\t\t-------------��ӭʹ��------------\n\n");
	printf("\t\t\t���           ɨ��          ���\n\n");
	printf("\t\t\t���          1.play         ���\n\n");
	printf("\t\t\t���          0.exit         ���\n\n");
	printf("\t\t\t---------------------------------\n\n");
}

void game()
{
	//��ʼ������
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	Init_board(mine, ROWS, COLS, '0');
	Init_board(show, ROWS, COLS, '*');
	printf("\n\n\t\t\t2��������Ϸ���棡\n");
	Sleep(2000);
	system("cls");
	//��ӡ����
	//Display_board(mine, ROW, COL);
	//Display_board(show, ROW, COL);
	//������
	Set_mine(mine, ROW, COL);
	//Display_board(mine, ROW, COL);
	//�Ų���
	Find_mine(mine, show, ROW, COL);
}



int main()
{
	system("color 5E");
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("\t\t\t��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("\n\n\t\t\t�˳��ɹ���\n");
			break;
		default:
			printf("\n\n\t\t\tѡ��������������룡\n");
			Sleep(2000);
			system("cls");
		}

	} while (input);
}