#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//int main()
//{
//	int n = 10;
//	char *pc = (char*)&n;
//	int *pi = &n;
//	printf("%p\n", &n);
//	printf("%p\n", pc);
//	printf("%p\n", pc + 1);
//	printf("%p\n", pi);
//	printf("%p\n", pi + 1);
//	return  0;
//}


//int main()
//{
//	int arr[5] = { 0 };
//	for (int i = 0; i < 5; i++)
//	{
//		*(arr + i) = i;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//int my_strlen(char *s)
//{
//	char *p = s;
//	while (*p != '\0')
//		p++;
//	return p - s;
//}
//
//int main()
//{
//	char str[] = "abcdef";
//	int ret = my_strlen(str);
//	printf("%d\n", ret);
//	return 0;
//}
//#include <malloc.h>
//int main()
//{
//	int *p = (int*)malloc(sizeof(int));
//	free(p);
//	p = NULL;
//	*p = 10;
//	printf("%d\n", *p);
//	return 0;
//}




//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr);
//	return 0;
//}




//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 0 };
//	printf("arr = %p\n", arr);
//	printf("&arr= %p\n", &arr);
//	printf("arr+1 = %p\n", arr + 1);
//	printf("&arr+1= %p\n", &arr + 1);
//	return 0;
//}



void test()
{
	printf("hehe\n");
}

int main()
{
	printf("%p\n", test);
	printf("%p\n", &test);
	return 0;
}