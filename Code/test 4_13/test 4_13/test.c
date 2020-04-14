#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<assert.h>
//char* my_strncat(char* dest, char* src, int size)
//{
//	assert(dest);
//	assert(src);
//	char* tmp = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//
//	while (size)
//	{
//		*dest++ = *src++;
//		size--;
//	}
//	*dest = '\0';
//	return tmp;
//}
//int main()
//{
//	char arr1[15] = "AABCD";
//	char arr2[] = "BCDAA";
//	int len = strlen(arr1);
//	char* ret1 = my_strncat(arr1, arr1, len);//ret1是arr1自己连接自己后的字符串
//
//	char* ret2 = strstr(ret1, arr2);
//	if (*ret2 == NULL)
//	{
//		printf("0\n");
//	}
//	else
//	{
//		printf("1\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<windows.h>
//void Find(int arr[4][4], int rows, int cols, int num)
//{
//	int result = 0;
//	int row = 0;
//	int col = cols - 1;
//	while (row < rows && col >= 0)
//	{
//		if (arr[row][col] == num)
//		{
//			result = 1;
//			break;
//		}
//		else if (arr[row][col] > num)
//		{
//			--col;
//		}
//		else
//		{
//			++row;
//		}
//	}
//	if (result == 1)
//	{
//		printf("找到了!\n");
//	}
//	else
//		printf("没有找到!\n");
//}
//int main()
//{
//	int arr[4][4] = { { 1, 3, 5, 8 }, { 2, 4, 6, 9 }, { 4, 5, 8, 10 }, { 5, 7, 9, 11 } };
//	Find(arr, 4, 4, 15);
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void reverse(char arr[], int n, int len)
{
	int i = 0;
	while (n)//将字符串左旋
	{
		char tmp = arr[0];//保存首字符，不然覆盖后就不存在了
		for (i = 0; i<len - 1; i++)//将第一个字符后的所有字符向前移动
		{
			arr[i] = arr[i + 1];
		}
		arr[len - 1] = tmp;//将第一个字符放到字符串的末尾
		n--;//进行下一次左旋
	}
}
int main()
{
	char arr[] = "abcde";
	int n = 0;
	scanf("%d", &n);
	reverse(arr, n, strlen(arr));
	printf("%s\n", arr);
	return 0;
}
