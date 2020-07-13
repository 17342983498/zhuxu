#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
struct stu
{
	int xuehao;
	char name[10];
	char sex[10];
	float chengji[3];
};
void input(struct stu s[])
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("请输入学号，姓名，性别，三门课的成绩成绩:> ");
		scanf("%d %s %s %f %f %f", &s[i].xuehao, &s[i].name, &s[i].sex,
			&s[i].chengji[0], &s[i].chengji[1], &s[i].chengji[2]);
	}
}
void search(struct stu s[])
{
	char name[10];
	printf("请输入查询的姓名:>");
	scanf("%s", name);
	int pos = FindByName(s, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("学号：%d\n姓名：%s\n性别：%s\n成绩分别是：%f %f %f\n",
			s[pos].xuehao, s[pos].name, s[pos].sex,
			s[pos].chengji[0], s[pos].chengji[pos], s[pos].chengji[2]);
	}
}
int FindByName(struct stu s[], char name[10])
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (0 == strcmp(s[i].name, name))
		{
			return i;
		}
	}
	return -1;
}
void print(struct stu s[])
{
	for (int i = 0; i < 5; i++)
	{
		printf("学号：%d\n姓名：%s\n性别：%s\n成绩分别是：%f %f %f\n",
			s[i].xuehao, s[i].name, s[i].sex,
			s[i].chengji[0], s[i].chengji[1], s[i].chengji[2]);
	}
}
int main()
{
	struct stu s[5];
	/*struct Student *p = s;*/
	input(s);
	search(s);
	/*print(s);*/
	return 0;
}
