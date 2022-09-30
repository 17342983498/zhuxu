#define _CRT_SECURE_NO_WARNINGS 1


int amin()
{
	int a[] = { 1, 2, 3, 4 };

	printf("%d\n", sizeof(a));//16

	printf("%d\n", sizeof(a + 0));//4

	printf("%d\n", sizeof(*a));//4

	printf("%d\n", sizeof(a + 1));//4

	printf("%d\n", sizeof(a[1]));//4

	printf("%d\n", sizeof(&a));//4

	printf("%d\n", sizeof(*&a));//16

	printf("%d\n", sizeof(&a + 1));//4

	printf("%d\n", sizeof(&a[0]));//4

	printf("%d\n", sizeof(&a[0] + 1));//4;

	//字符数组

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };

	printf("%d\n", sizeof(arr));//6

	printf("%d\n", sizeof(arr + 0));//4

	printf("%d\n", sizeof(*arr));//1

	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4

	printf("%d\n", sizeof(&arr + 1));//4

	printf("%d\n", sizeof(&arr[0] + 1));//4

	printf("%d\n", strlen(arr));//随机

	printf("%d\n", strlen(arr + 0));//随机

	printf("%d\n", strlen(*arr));//err  *arr —— a —— 97

	printf("%d\n", strlen(arr[1]));//err 98

	printf("%d\n", strlen(&arr));//随机

	printf("%d\n", strlen(&arr + 1));//随机

	printf("%d\n", strlen(&arr[0] + 1));//随机

	char arr[] = "abcdef";

	printf("%d\n", sizeof(arr));//7

	printf("%d\n", sizeof(arr + 0));//4

	printf("%d\n", sizeof(*arr));//1

	printf("%d\n", sizeof(arr[1]));//1

	printf("%d\n", sizeof(&arr));//4

	printf("%d\n", sizeof(&arr + 1));//4

	printf("%d\n", sizeof(&arr[0] + 1));//4

	printf("%d\n", strlen(arr));//6

	printf("%d\n", strlen(arr + 0));//6

	printf("%d\n", strlen(*arr));//err

	printf("%d\n", strlen(arr[1]));//err

	printf("%d\n", strlen(&arr));//6

	printf("%d\n", strlen(&arr + 1));//随机

	printf("%d\n", strlen(&arr[0] + 1));//5

	char *p = "abcdef";

	printf("%d\n", sizeof(p));//4

	printf("%d\n", sizeof(p + 1));//4

	printf("%d\n", sizeof(*p));//1

	printf("%d\n", sizeof(p[0]));//1

	printf("%d\n", sizeof(&p));//4

	printf("%d\n", sizeof(&p + 1));//4

	printf("%d\n", sizeof(&p[0] + 1));//4

	printf("%d\n", strlen(p));//6

	printf("%d\n", strlen(p + 1));//5

	printf("%d\n", strlen(*p));//err

	printf("%d\n", strlen(p[0]));//err

	printf("%d\n", strlen(&p));//随机 p是字符串首地址，&p首地址的地址，从这个地址数根本不知道是什么

	printf("%d\n", strlen(&p + 1));//随机

	printf("%d\n", strlen(&p[0] + 1));//5

	//二维数组

	int a[3][4] = { 0 };

	printf("%d\n", sizeof(a));//48

	printf("%d\n", sizeof(a[0][0]));//4

	printf("%d\n", sizeof(a[0]));//16

	printf("%d\n", sizeof(a[0] + 1));//a[0]是第一行的数组名，但是没有单独放在sizeof内，所以表示第一行的首地址（第一行的首元素地址），  4

	printf("%d\n", sizeof(*(a[0] + 1)));//a[0][1]  4

	printf("%d\n", sizeof(a + 1));//a是二维数组的数组名，但是（），所以表示二维数组的首地址（第一行的地址）4

	printf("%d\n", sizeof(*(a + 1)));//第二行大小，16

	printf("%d\n", sizeof(&a[0] + 1));//&a[0]对第一行取地址，+1表示第二行  4

	printf("%d\n", sizeof(*(&a[0] + 1)));//16

	printf("%d\n", sizeof(*a));//a没有与sizeof单独使用，表示第一行地址，解引用表示第一行  16

	printf("%d\n", sizeof(a[3]));//16  sizeof(int [4])

	return 0;
}