#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//
//int solution(int n, int m, int arr1[])
//{
//	int result;
//
//	// TODO: 请在此编写代码
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j<m; j++)
//		{
//			if (i%arr1[j] == 0)
//			{
//				sum++;
//				j = m;
//			}
//		}
//	}
//	result = n-sum;
//	return result;
//}
//
//
//int main() {
//
//	int n;
//	int m;
//	scanf("%d", &n);
//	scanf("%d", &m);
//
//
//	int *arr1;
//	arr1 = (int*)malloc(m * sizeof(int));
//
//	for (int i = 0; i < m; i++)
//	{
//		scanf("%d", &arr1[i]);
//	}
//
//
//	int result = solution(n, m, arr1);
//
//	printf("%d", result);
//
//	return 0;
//}



//#include <stdio.h>
//#include <stdlib.h>
//
//int * solution(int m, int arr1[], int* return_size){
//	//return_size: result长度
//	int* result;
//
//	// TODO: 请在此编写代码;
//	int arr2[1000] = { 0 };
//	int arr3[1000] = { 0 };
//	int i = 0;
//	int x = 0;
//	int y = 0;
//	while (i<m)
//	{
//		if (arr1[i] % 2 == 1)
//			arr2[x++] = arr1[i];
//		else
//			arr3[y++] = arr1[i];
//		i++;
//	}
//	i = 0;
//	int j = 0;
//	while (arr2[i] != 0)
//	{
//		*(arr1+j) = arr2[i++];
//		j++;
//	}
//	i = 0;
//	while (arr3[i] != 0)
//	{
//		*(arr1 + j) = arr3[i++];
//		j++;
//	}
//	result = arr1;
//	*return_size = m;
//	return result;
//}
//
//
//int main() {
//
//	int n;
//	scanf("%d", &n);
//
//
//	int *arr;
//	arr = (int*)malloc(n * sizeof(int));
//
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	int return_size;
//	int* result = solution(n, arr, &return_size);
//
//	for (int i = 0; i < return_size; i++){
//		printf("%d ", result[i]);
//	}
//
//	return 0;
//}




#include <stdio.h>


int solution(int n, int m, int arr1[]){
	int result;

	// TODO: 请在此编写代码
	int num = 0;
	for (int i = 0; i<m; i++)
	{
		int sum = arr1[i];
		int j = 1;
		while (sum <= n)
		{
			sum = arr1[i];
			sum *= j;
			j++;
		}
		j -= 2;
		num += j;
	}
	for ( int i = 1; i <= n; i++)
	{
		if ((i%arr1[0] == 0) && (i%arr1[1] == 0))
		{
			num -= 1;
		}
	}
	result = n - num;
	return result;
}


int main() {

	int n;
	int m;
	scanf("%d", &n);
	scanf("%d", &m);


	int *arr1;
	arr1 = (int*)malloc(m * sizeof(int));

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &arr1[i]);
	}


	int result = solution(n, m, arr1);

	printf("%d", result);

	return 0;
}