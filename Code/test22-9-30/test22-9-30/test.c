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

	//�ַ�����

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };

	printf("%d\n", sizeof(arr));//6

	printf("%d\n", sizeof(arr + 0));//4

	printf("%d\n", sizeof(*arr));//1

	printf("%d\n", sizeof(arr[1]));//1
	printf("%d\n", sizeof(&arr));//4

	printf("%d\n", sizeof(&arr + 1));//4

	printf("%d\n", sizeof(&arr[0] + 1));//4

	printf("%d\n", strlen(arr));//���

	printf("%d\n", strlen(arr + 0));//���

	printf("%d\n", strlen(*arr));//err  *arr ���� a ���� 97

	printf("%d\n", strlen(arr[1]));//err 98

	printf("%d\n", strlen(&arr));//���

	printf("%d\n", strlen(&arr + 1));//���

	printf("%d\n", strlen(&arr[0] + 1));//���

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

	printf("%d\n", strlen(&arr + 1));//���

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

	printf("%d\n", strlen(&p));//��� p���ַ����׵�ַ��&p�׵�ַ�ĵ�ַ���������ַ��������֪����ʲô

	printf("%d\n", strlen(&p + 1));//���

	printf("%d\n", strlen(&p[0] + 1));//5

	//��ά����

	int a[3][4] = { 0 };

	printf("%d\n", sizeof(a));//48

	printf("%d\n", sizeof(a[0][0]));//4

	printf("%d\n", sizeof(a[0]));//16

	printf("%d\n", sizeof(a[0] + 1));//a[0]�ǵ�һ�е�������������û�е�������sizeof�ڣ����Ա�ʾ��һ�е��׵�ַ����һ�е���Ԫ�ص�ַ����  4

	printf("%d\n", sizeof(*(a[0] + 1)));//a[0][1]  4

	printf("%d\n", sizeof(a + 1));//a�Ƕ�ά����������������ǣ��������Ա�ʾ��ά������׵�ַ����һ�еĵ�ַ��4

	printf("%d\n", sizeof(*(a + 1)));//�ڶ��д�С��16

	printf("%d\n", sizeof(&a[0] + 1));//&a[0]�Ե�һ��ȡ��ַ��+1��ʾ�ڶ���  4

	printf("%d\n", sizeof(*(&a[0] + 1)));//16

	printf("%d\n", sizeof(*a));//aû����sizeof����ʹ�ã���ʾ��һ�е�ַ�������ñ�ʾ��һ��  16

	printf("%d\n", sizeof(a[3]));//16  sizeof(int [4])

	return 0;
}