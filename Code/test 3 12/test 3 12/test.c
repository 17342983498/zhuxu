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
	ret = rand()%100+1;//����1-100֮��������
	int guess = 0;
	while (1)
	{
		printf("�������\n");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("��С��\n");//����ѭ��
		}
		else if (guess>ret)
		{
			printf("�´���\n");//����ѭ��
		}
		else
		{
			printf("��ϲ��¶���\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	//��ʱ������������������
	//time_t time(time_t *timer)
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>;");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//ȥgame����������
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;

		}
	} while (input);//���Ϊ1������do�����Ϊ0�������Σ�ѭ����ֹ�����Ϊ�������֣�ѡ����󣬵���input��Ϊ�棬����ִ��do.

	return 0;

}
