#define _CRT_SECURE_NO_WARNINGS 1


//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回YES.
//给定s1 = abcd和s2 = ACBD，返回NO.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
#include<stdio.h>
#include<string.h>
int is_left_move(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
		return 0;//如果一个字符串为abcdef,另一个为cdefa,结果会输出YES,很明显，这个并不是前一个字符串旋转得到的
	//所以加上这步判断两个字符串的长度是否相等来进行判断
	//strcat(str1,str1)  ERR  这个不能自己给自己追加
	strncat(str1, str1,6);
	char* ret = strstr(str1, str2);
	//strstr--找子串的，如果没有找到返回空指针，如果找到，返回c的地址（cdefab）
	if (ret == NULL)
	{
		return 0;
	}
	else
		return 1;
}
int main()
{
	char arr1[30] = "abcdef";
	char arr2[] = "cdefab";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("YES!\n");
	else if (ret == 0)
		printf("NO!\n");
	return 0;
}