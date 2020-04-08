#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0; 
	int a[10][10];
	for (i = 1; i < 10; i++)                     
	{
		a[i][i] = 1;  //斜对角一直为 1                       
		a[i][1] = 1;  //第一列一直为 1                          
	}
	for (i = 3; i < 10; i++)//从第三行开始加
	{
		for (j = 2; j <= i - 1; j++)//从第二列
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];//相加存储在数组中
	} 
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j <= i; j++)
			printf("%4d", a[i][j]);              
		printf("\n");                           
	}
	return 0;
}
