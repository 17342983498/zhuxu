#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int partition(string &str, int lo, int hi)
//{
//
//	int key = str[hi]; //以最后一个元素，data[hi]为主元
//	int i = lo - 1;
//	for (int j = lo; j < hi; j++) ///注，j 从 p 指向的是 r-1，不是 r。
//
//	{
//
//		if (str[j] <= key)
//		{
//			i++;
//			swap(str[i], str[j]);
//		}
//	}
//	swap(str[i + 1], str[hi]); //不能改为 swap(&data[i+1],&key)
//
//	return i + 1;
//}
//
//
//void quicksort(string &str, int lo, int hi)
//{
//
//	if (lo < hi)
//	{
//		int k = partition(str, lo, hi);
//		quicksort(str, lo, k - 1);
//		quicksort(str, k + 1, hi);
//	}
//}
//
//void compare(string str1, string str2)
//{
//	size_t posOne = 0;
//	size_t posTwo = 0;
//	while (posTwo < str2.length() && posOne < str1.length())
//	{
//		while (str1[posOne] < str2[posTwo] && posOne < str1.length() - 1)
//			posOne++;
//
//		if (str1[posOne] != str2[posTwo])
//			break;
//		posTwo++;
//	}
//
//	if (posTwo == str2.length())
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//}
//
//int main()
//{
//	string str1 = "abcdef";
//	string str2 = "cdf";
//	quicksort(str1, 0, str1.length() - 1);
//	quicksort(str2, 0, str2.length() - 1); //先排序
//	compare(str1, str2); //后线性扫描
//	return 0;
//}


#include <stdio.h>


//int main()
//{
//	char str1[] = "LKJHGFDSA";
//	char str2[] = "SGKLA";
//
//	int num = 0;
//	int arr[26] = { 0 };
//	for (int i = 0; i < sizeof(str2) / sizeof(str2[0]); i++)
//	{
//		int dex = str2[i] - 'A';
//		if (arr[dex] == 0)
//		{
//			arr[dex] = 1;
//			num++;
//		}
//	}
//	for (int i = 0; i < sizeof(str1) / sizeof(str1[0]); i++)
//	{
//		int dex = str1[i] - 'A';
//		if (arr[dex] == 1)
//		{
//			num--;
//			arr[dex] = 0;
//			if (num == 0)
//				break;
//		}
//	}
//	if (num == 0)
//	{
//		printf("true\n");
//	}
//	else
//		printf("false\n");
//	return 0;
//}



//int main()
//{
//	char str1[] = "LKJHGFDSA";
//	char str2[] = "SGKLAA";
//
//	int num = 0;
//	int arr[26] = { 0 };
//	for (int i = 0; i < sizeof(str2) - 1; i++)
//	{
//		int dex = str2[i] - 'A';
//		arr[dex]++;
//		num++;
//	}
//	for (int i = 0; i < sizeof(str1) - 1; i++)
//	{
//		int dex = str1[i] - 'A';
//		if (arr[dex] != 0)
//		{
//			num--;
//			arr[dex]--;
//			if (num == 0)
//				break;
//		}
//	}
//	if (num == 0)
//	{
//		printf("true\n");
//	}
//	else
//		printf("false\n");
//	return 0;
//}


//int main()
//{
//	char str1[] = "LKJHGFDSA";
//	char str2[] = "SGKLA";
//	int arr[58];
//	memset(arr, 0, 58);
//	for (int i = 0; i < strlen(str2); i++)
//	{
//		int dex = arr[i] - 'A';
//		arr[dex] = 1;
//	}
//	for (int i = 0; i < strlen(str1); i++)
//	{
//		int dex = arr[i] - 'A';
//		if (arr[dex] == 1)
//		{
//			arr[dex] = 0;
//		}
//	}
//	for (int i = 0; i < 58; i++)
//	{
//		if (arr[i] == 1)
//		{
//			printf("false\n");
//			break;
//		}
//		if (i == 57)
//		{
//			printf("true\n");
//		}
//	}
//	return 0;
//}



int main()
{
	char str1[] = "LKJHGFDSAasc";
	char str2[] = "SGKLAsc";

	int num = 0;
	int arr[1024] = { 0 };
	for (int i = 0; i < sizeof(str2)-1; i++)
	{
		arr[str2[i]]++;
		num++;
	}
	for (int i = 0; i < sizeof(str1)-1; i++)
	{
		if (arr[str1[i]] != 0)
		{
			num--;
			arr[str1[i]]--;
			if (num == 0)
				break;
		}
	}
	if (num == 0)
	{
		printf("true\n");
	}
	else
		printf("false\n");
	return 0;
}