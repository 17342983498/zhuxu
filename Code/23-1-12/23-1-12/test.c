#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int *ptr = (int *) (&a + 1);
//	printf("%d , %d", *(a + 1), *(ptr - 1));//2 5
//	return 0;
//}


//struct Test
//{
//	int Num;
//	char *pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
//
////假设p 的值为0x100000。 如下表表达式的值分别为多少？
//
//int main()
//{
//	printf("%p\n ", p + 0x1);//0x1不是地址，是十六进制的1，在这里加一代表向后挪动一个结构体  0x00100014
//	printf("%p\n ", (unsigned long) p + 0x1);//加数字一   0x00100001
//	printf("%p\n ", (unsigned int*) p + 0x1);//0x00100004
//	return 0;
//}

//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int *ptr1 = (int *) (&a + 1);
//	int *ptr2 = (int *) ((int) a + 1);//地址转为整形
//	printf("%x , %x", ptr1[-1], *ptr2);
//	return 0;
//}



//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//	int *p;
//	p = a[0];
//	printf("%d", p[0]);
//	return 0;
//}


//int main()
//{
//	int a[3] = { 0,0,0 };
//	int *p = a + 1;
//	printf("%d\n", sizeof(a + 1));
//	printf("%d\n", p - a);
//	printf("%p ", a);
//	printf("%p ", p);
//	return 0;      
//}


//int main()
//{
//	char *a[] = { "work", "at", "alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n ", *pa);
//	return 0;
//}
//#include <string.h>
//void reverse(char* s)
//{
//	char* left = s;
//	char* right = s + strlen(s) - 1;
//	while (left < right)
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//}
// 
//int main()
//{
//	char s[10] = { 0 };
//	/*scanf("%s", s);*/
//	//gets(s);
//	reverse(s);
//	printf("%s\n", s);
//	return 0;
//
//}

//#include <math.h>
//int main()
//{
//	for (int i = 0; i <= 10000; i++)
//	{
//		int temp = i;
//		int num = 0;
//		while (temp)
//		{
//			num++;
//			temp /= 10;
//		}
//		int sum = 0;
//		temp = i;
//		while (temp)
//		{
//			sum += pow(temp % 10,num);
//			temp /= 10;
//		}
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
#include <string.h>
//void reverse(char* left,char* right)
//{
//	while (left < right)
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//}
//
//void move(char* arr, int k)
//{
//    int len = strlen(arr);
//	reverse(arr, arr + k - 1);
//	reverse(arr + k, arr + len - 1);
//	reverse(arr, arr + len - 1);
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int k = 0;
//	scanf("%d", &k);
//	move(arr, k);
//	printf("%s\n", arr);
//	return 0;
//}


//int left_move(char* arr1,char* arr2)
//{
//	int len = strlen(arr1);
//	for (int i = 1; i <= len; i++)
//	{
//		move(arr1, i);
//		int x = strcmp(arr1, arr2);
//		if (x == 0)
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "defabc";
//	int m = left_move(arr1,arr2);
//	if (m == 1)
//		printf("YES\n");
//	else
//		printf("NO\n");
//	return 0;
//}


//int left_move(char arr1[], char* arr2)
//{
//	int len = strlen(arr1);
//	strncat(arr1, arr1, len);
//	char* s = strstr(arr1, arr2);
//	if (s == NULL)
//	{
//		return 0;
//	}
//	else
//		return 1;
//}
//
//int main()
//{
//	char arr1[13] = "abcdef";
//	char arr2[] = "defabc";
//	int m = left_move(arr1,arr2);
//	if (m == 1)
//		printf("YES\n");
//	else
//		printf("NO\n");
//	return 0;
//}

//int find_num(int arr[][3], int k,int x, int y)
//{
//	int row = 0;
//	int col = y - 1;
//	while (row >= 0 && col <= y - 1)
//	{
//		if (arr[row][col] < k)
//		{
//			row++;
//		}
//		else if (arr[row][col] > k)
//		{
//			col--;
//		}
//		else
//			return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
//	int k = 0;
//	scanf("%d", &k);
//	int ret = find_num(arr,k,3,3);
//	if (ret == 1)
//	{
//		printf("找到了\n");
//	}
//	else
//		printf("没找到\n");
//	return 0;
//}




int find_num(int arr[][3], int k, int* x, int* y)
{
	int row = 0;
	int col = *y - 1;
	while (row >= 0 && col <= *y - 1)
	{
		if (arr[row][col] < k)
		{
			row++;
		}
		else if (arr[row][col] > k)
		{
			col--;
		}
		else
		{
			*x = row+1;
			*y = col+1;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int arr[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int k = 0;
	scanf("%d", &k);
	int x = 3;
	int y = 3;
	int ret = find_num(arr, k, &x, &y);
	if (ret == 1)
	{
		printf("找到了\n");
		printf("所在位置为第%d行第%d例\n", x, y);
	}
	else
		printf("没找到\n");
	return 0;
}