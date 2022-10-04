#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
//int reverse_num(int num)
//{
//	int ret = 0;
//	while (num)
//	{
//		ret = num % 10 + ret * 10;
//		num /= 10;
//	}
//	return ret;
//}
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int ret = reverse_num(num);
//	printf("%d\n", ret);
//	return 0;
//}


//int reverse(int x) {
//	int flag = 0;
//	if (x < 0) {
//		x = -x;
//		flag = 1;
//	}
//	long long ret = 0;
//	while (x) {
//		ret = x % 10 + ret * 10;
//		x /= 10;
//	}
//	if (flag == 1) {
//		ret = -ret;
//	}
//	if (ret > pow(2, 31) - 1 || ret < -pow(2, 31)) {
//		return 0;
//	}
//	else {
//		return ret;
//	}
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int ret = reverse(num);
//	printf("%d\n", ret);
//	return 0;
//}




#include <string.h>
int main()
{
	char s[100];
	gets(s);
	int n, f = 0, t;
	n = strlen(s) - 1;    //统计字符串有多长，注意下标是从0开始的，值要减1
	while (s[n] == '0')  //计算第一个非’0’位置
	{
		n--;
		t = n;
	}
	if (s[0] == '-')     //符号特判
	{
		f = 1;
		printf("-");
	}
	for (int i = n; i >= 1; i--)    //从非’0’位置倒序输出
	{
		printf("%c", s[i]);
	}
	if (f == 0)               //单独输出
	{
		printf("%c", s[0]);
	}
	return 0;
}
