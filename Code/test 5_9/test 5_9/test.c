#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<errno.h>
#include<string.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt","wb");
//	fwrite(&a, 4, 1, pf);//�Զ�������ʽд���ļ���
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//�ַ��������
//int main()
//{
//	//���ļ� test.txt
//	FILE* pfWrite = fopen("test.txt", "w");
//	if (pfWrite == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	//д�ļ�
//	fputc('z', pfWrite);
//	fputc('h', pfWrite);
//	fputc('u', pfWrite);
//	fputc('x', pfWrite);
//	fputc('u', pfWrite);
//	//�ر��ļ�
//	fclose(pfWrite);
//	pfWrite = NULL;
//	return 0;
//}

//�ַ����뺯��
//int main()
//{
//	FILE* pfRead = fopen("test.txt", "r");
//	if (pfRead == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	//���ļ��л�ȡ
//	printf("%c", fgetc(pfRead));
//	printf("%c", fgetc(pfRead));
//	printf("%c", fgetc(pfRead));
//	printf("%c", fgetc(pfRead));
//	printf("%c", fgetc(pfRead));
//	fclose(pfRead);
//	pfRead = NULL;
//	return 0;
//}


//int main()
//{
//	int ch = fgetc(stdin);//�Ӽ�������
//	fputc(ch,stdout);//����Ļ���
//	return 0;
//}

//�ı����뺯��
//int main()
//{
//	char arr[1024] = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	fgets(arr, 1024, pf);
//	printf("%s\n", arr);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//�ı��������
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	fputs("abcdef\n",pf);
//	fputs("ghijklmn", pf);//���뵽�ļ���
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main()
//{
//	//�Ӽ��̶�ȡһ�к���
//	char arr[1024] = { 0 };
//	fgets(arr, 1024, stdin);
//	fputs(arr, stdout);
//	return 0;
//}
//struct s
//{
//	int n;
//	float num;
//	char arr[10];
//};
//int main()
//{
//	struct s stu = { 100, 3.14f, "zhuxu" };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//��ʽ����ʽд�ļ�
//	fprintf(pf, "%d %f %s", stu.n, stu.num, stu.arr);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//struct s
//{
//	int n;
//	float num;
//	char arr[10];
//};
//int main()
//{
//	struct s stu = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//��ʽ����ʽ��������
//	fscanf(pf, "%d %f %s", &(stu.n), &(stu.num), stu.arr);
//	printf("%d %f %s", stu.n, stu.num, stu.arr);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
struct s
{
	int n;
	float num;
	char arr[10];
};
int main()
{
	struct s stu = { 0 };
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		return 0;
	}
	fscanf(stdin, "%d %f %s", &(stu.n), &(stu.num), stu.arr);
	fprintf(stdout, "%d %f %s", stu.n, stu.num, stu.arr);
	fclose(pf);
	pf = NULL;
	return 0;
}