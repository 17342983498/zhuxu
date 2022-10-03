#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("\n\n\t\t\t-------------欢迎使用------------\n\n");
	printf("\t\t\t☆☆           扫雷          ☆☆\n\n");
	printf("\t\t\t☆☆          1.play         ☆☆\n\n");
	printf("\t\t\t☆☆          0.exit         ☆☆\n\n");
	printf("\t\t\t---------------------------------\n\n");
}

void game()
{
	//初始化棋盘
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	Init_board(mine, ROWS, COLS, '0');
	Init_board(show, ROWS, COLS, '*');
	printf("\n\n\t\t\t2秒后进入游戏界面！\n");
	Sleep(2000);
	system("cls");
	//打印棋盘
	//Display_board(mine, ROW, COL);
	//Display_board(show, ROW, COL);
	//布置雷
	Set_mine(mine, ROW, COL);
	//Display_board(mine, ROW, COL);
	//排查雷
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
		printf("\t\t\t请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("\n\n\t\t\t退出成功！\n");
			break;
		default:
			printf("\n\n\t\t\t选择错误，请重新输入！\n");
			Sleep(2000);
			system("cls");
		}

	} while (input);
}