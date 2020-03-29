#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("*************************\n");
	printf("***** 1.play 0.exit *****\n");
	printf("*************************\n");
}
void game()
{
	int ret = 0;
	ret = rand()%100+1;//生成1-100之间的随机数
	int guess = 0;
	while (1)
	{
		printf("请猜数字\n");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("猜小了\n");//继续循环
		}
		else if (guess>ret)
		{
			printf("猜大了\n");//继续循环
		}
		else
		{
			printf("恭喜你猜对了\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	//那时间戳设置随机数的生成
	//time_t time(time_t *timer)
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择>;");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//去game函数猜数字
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;

		}
	} while (input);//如果为1，继续do；如果为0，则退游，循环终止；如果为其他数字，选择错误，但是input仍为真，继续执行do.

	return 0;

}
