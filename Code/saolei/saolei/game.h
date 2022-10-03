#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9
#define easy_count 80


void Init_board(char board[ROWS][ROWS], int rows, int cols, char s);

void Display_board(char board[ROWS][COLS], int row, int col);

void Set_mine(char mine[ROWS][COLS], int row, int col);

void Find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);