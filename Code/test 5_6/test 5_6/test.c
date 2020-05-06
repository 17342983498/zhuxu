#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#define  INT_MAX 100000
#define  INT_MIN -100000
int my_atoi(char* str)
{
	int ret = 0;            //用于返回
	int flag = 1;           //刚开始为合法
	assert(str);
	while (*str == ' ')     //处理空格情况
	{
		str++;
	}
	if (*str == '+')        // 处理加号情况
	{
		str++;
	}

	if (*str == '-')        //处理减号情况；
	{
		str++;
		flag = -1;
	}

	while (*str)
	{
		if (isdigit(*str))  //数字
		{
			ret = ret * 10 + (*str - '0')*flag;
			if (ret>INT_MAX || ret < INT_MIN)
			{
				ret = 0;
				break;
			}
			str++;
		}
		else                //其他字符
		{
			ret = 0;
			break;
		}
	}
	return ret;
}

int main()
{
	char p[] = "  -123";
	int ret = my_atoi(p);
	printf("%d", ret);
	return 0;
}


