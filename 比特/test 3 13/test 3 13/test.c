#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void menu()
//{
//	printf("*******************************\n");
//	printf("******  1.play  0.exit   ******\n");
//	printf("*******************************\n");
//
//}
//void game()
//{
//	int ret = 0;
//	ret = rand()%100+1;
//	int guess =0;
//	while (1)
//	{
//		printf("请输入你猜的数字\n");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("猜大了\n");
//		}
//		else if (guess < ret)
//		{
//			printf("猜小了\n");
//		}
//		else
//		{
//			printf("恭喜你，猜对了\n");
//			break;
//		}
//	}
//
//
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//
//
//#include<stdio.h>
//int main()
//{
//	int n ;
//	int i;
//	int j;
//	
//	int sum = 0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		int s = 1;
//		for (j = 1; j <= i; j++)
//		{
//			s *= j;
//		}
//		sum += s;
//	}
//	printf("%d", sum);
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//#include<windows.h>
//#include<stdlib.h>
//int main()
//{
//	char arr1[] = "welcome to bit";
//	char arr2[] = "**************";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	printf("%s\n", arr2);
//	while (left <= right)
//	{
//		Sleep(1000);
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		system("cls");清空屏幕
//		
//		printf("%s\n", arr2);
//		left++;
//		right--;
//	}
//	return 0;
//}
//
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//
//again:
//	printf("请注意，你已启动关机程序，你的电脑会在一分钟后关机，如果你输入我是猪，则取消关机\n");
//	scanf("%s", &input);
//	if (strcmp(input, "我是猪") == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}
#include<stdio.h>
#include<math.h>
int is_prime(int n)
{
	int j = 0;
	for (j = 2; j < n / 2; j++)
	{
		if (n%j == 0)
		{
			return 0;
		}
		
	}
	if (j == n / 2)
	{
		return 1;
	}
}
int main()
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		if (is_prime(i) == 1)
		{
			printf("%d ", i);
		}
	}
	return 0;
}