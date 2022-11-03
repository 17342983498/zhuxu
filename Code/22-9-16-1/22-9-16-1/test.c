#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//int cmp(const int* s1, const int* s2)
//{
//	return *s1 - *s2;
//}
//int main()
//{
//	int arr[7] = { 0 };
//	for (int i = 0; i < 7; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, 7, sizeof(int), cmp);
//	int sum = 0;
//	for (int i = 1; i < 6; i++)
//	{
//		sum += arr[i];
//	}
//	printf("%.2lf", sum / 5.0);
//	return 0;
//}


//int cmp(const int* s1, const int* s2)
//{
//	return *s1 - *s2;
//}
//int main() {
//	int a = 0;
//	while (scanf("%d", &a)!=EOF)
//	{
//		int arr[7];
//		arr[0] = a;
//		int i = 1;
//		int num = 0;
//		while (num < 6)
//		{
//			scanf("%d", &arr[i++]);
//			num++;
//		}
//		qsort(arr, 7, sizeof(int), cmp);
//		float sum = 0;
//		for (int i = 1; i < 6; i++)
//		{
//			sum += arr[i];
//		}
//		printf("%.2lf\n", sum / 5.0);
//	}
//	return 0;
//}



//#include <string.h>
//int main() {
//	char arr[100] = { 0 };;
//	scanf("%s", arr);
//	int sum1 = 0, sum2 = 0;
//	int num = strlen(arr);
//	for (int i = 0; i<num; i++)
//	{
//		if (arr[i] == 'A')
//		{
//			sum1++;
//		}
//		else
//			sum2++;
//	}
//	if (sum1>sum2)
//	{
//		printf("A");
//	}
//	else if (sum1<sum2)
//	{
//		printf("B");
//	}
//	else
//		printf("E");
//	return 0;
//}



int main() {
	int a;
	while (scanf("%d", &a) != EOF) {

		switch (a)
		{
		case 200:
			printf("OK\n");
			break;
		case 202:
			printf("Accepted\n");
			break;
		case 400:
			printf("Bad Request\n");
			break;
		case 403:
			printf("Forbidden\n");
			break;
		case 404:
			printf("Not Found\n");
			break;
		case 500:
			printf("Internal Server Error\n");
			break;
		case 502:
			printf("Bad Gateway\n");
			break;
		}
	}
	return 0;
}