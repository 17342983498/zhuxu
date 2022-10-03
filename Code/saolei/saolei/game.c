#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void Init_board(char board[ROWS][ROWS], int rows, int cols, char s)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = s;
		}
	}
}


void Display_board(char board[ROWS][COLS], int row, int col)
{
	printf("\t\t-------------------------------------\n\n\t\t\t");
	//printf("\n\n\t\t\t");
	for (int i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("\t\t\t");
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n\t\t-------------------------------------\n\n");
}


void Set_mine(char mine[ROWS][COLS], int row, int col)
{
	int count = easy_count;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1; 
		if (mine[x][y] != '1')
		{
			mine[x][y] = '1';
			count --;
		}
		
	}
}

int get_mine_num(char mine[ROWS][COLS],int x,int y)
{
	return mine[x - 1][y - 1]
		+ mine[x - 1][y]
		+ mine[x - 1][y + 1]
		+ mine[x][y - 1]
		+ mine[x][y + 1]
		+ mine[x + 1][y - 1]
		+ mine[x + 1][y]
		+ mine[x + 1][y + 1] - 8 * '0';
}
void Find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	Display_board(show, ROW, COL);
	int x, y = 0;
	int win = 0;
	while (win < (row*col-easy_count))
	{
		printf("\n\t\t\t������ѡ���λ�ã�");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] != '1')
				{
					int num = get_mine_num(mine, x, y);
					show[x][y] = num + '0';
					//Display_board(show, ROW, COL);
					win++;
				}
				else
				{
					system("cls");
					printf("\n\n\t\t\t--- Game Over! ---\n");
					Sleep(1000);
					Display_board(mine, ROW, COL);
					break;
				}
			}
			else
			{
				printf("\n\n\t\t\t�������ѱ��Ų��,������ѡ��\n");
				Sleep(1000);
			}
		}
		else
		{
			printf("\n\n\t\t\t�������������ѡ��\n");
			Sleep(1000);
		}
		system("cls");
		Display_board(show, ROW, COL);
	}
	if (win == (row*col - easy_count))
	{
		printf("\t\t\t��ϲ�������׳ɹ���\n");
	}
	printf("\t\t\t3����Զ��˳�����ҳ��\n");
	Sleep(3000);
	system("cls");
}