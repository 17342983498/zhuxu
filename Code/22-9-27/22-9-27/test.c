#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//struct S
//{
//	int a;
//	float s;
//	int arr[];//柔性数组成员
//};
//int main()
//{
//	int sz = sizeof(struct S);
//	printf("%d\n", sz);
//	return 0;
//}



//struct S
//{
//	int arr[];//柔性数组成员
//};
//int main()
//{
//	int sz = sizeof(struct S);
//	printf("%d\n", sz);
//	return 0;
//}


//error C2229: struct“S”有非法的大小为零的数组
//struct S
//{
//	int a;
//	float s;
//	int arr[];//柔性数组成员
//	int b;
//};
//int main()
//{
//	int sz = sizeof(struct S);
//	printf("%d\n", sz);
//	return 0;
//}


#include <stdlib.h>
//struct S
//{
//	int a;
//	float s;
//	int arr[];
//};
//
//int main()
//{
//	struct S *s = (struct S*)malloc(sizeof(struct S) + 4 * sizeof(int));
//	s->a = 10;
//	s->s = 3.14f;
//	for (int i = 0; i < 4; i++)
//	{
//		s->arr[i] = i;
//	}
//	printf("%d %f\n", s->a, s->s);
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d ", s->arr[i]);
//	}
//	printf("\n");
//  free(s);
//	return 0;
//}

//struct S
//{
//	int a;
//	float s;
//	int* arr;
//};
//
//int main()
//{
//	struct S *s = (struct S*)malloc(sizeof(struct S));
//	s->a = 10;
//	s->s = 3.14f;
//	s->arr = (int*)malloc(4 * sizeof(int));
//	for (int i = 0; i < 4; i++)
//	{
//		s->arr[i] = i;
//	}
//	printf("%d %f\n", s->a, s->s);
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%d ", s->arr[i]);
//	}
//	printf("\n");
//	free(s->arr);
//	s->arr = NULL;
//	free(s);
//	s = NULL;
//	return 0;
//}





//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[1000] = { 0 };
//	int tmp = 0;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &tmp);
//		arr[tmp] = tmp;
//	}
//	for (int i = 1; i < n; i++)
//	{
//		if (arr[i] != 0)
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//	return 0;
//}



int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[10] = { 0 };
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		arr[temp] = temp;
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			printf("%d ",arr[i]);
		}
	}
	return 0;
}