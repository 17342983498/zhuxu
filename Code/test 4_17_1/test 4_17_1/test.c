#define _CRT_SECURE_NO_WARNINGS 1


//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������YES.
//����s1 = abcd��s2 = ACBD������NO.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC
#include<stdio.h>
#include<string.h>
int is_left_move(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
		return 0;//���һ���ַ���Ϊabcdef,��һ��Ϊcdefa,��������YES,�����ԣ����������ǰһ���ַ�����ת�õ���
	//���Լ����ⲽ�ж������ַ����ĳ����Ƿ�����������ж�
	//strcat(str1,str1)  ERR  ��������Լ����Լ�׷��
	strncat(str1, str1,6);
	char* ret = strstr(str1, str2);
	//strstr--���Ӵ��ģ����û���ҵ����ؿ�ָ�룬����ҵ�������c�ĵ�ַ��cdefab��
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