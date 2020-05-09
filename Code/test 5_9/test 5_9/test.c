#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<errno.h>
#include<string.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt","wb");
//	fwrite(&a, 4, 1, pf);//以二进制形式写到文件中
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//字符输出函数
//int main()
//{
//	//打开文件 test.txt
//	FILE* pfWrite = fopen("test.txt", "w");
//	if (pfWrite == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	//写文件
//	fputc('z', pfWrite);
//	fputc('h', pfWrite);
//	fputc('u', pfWrite);
//	fputc('x', pfWrite);
//	fputc('u', pfWrite);
//	//关闭文件
//	fclose(pfWrite);
//	pfWrite = NULL;
//	return 0;
//}

//字符输入函数
//int main()
//{
//	FILE* pfRead = fopen("test.txt", "r");
//	if (pfRead == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	//从文件中获取
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
//	int ch = fgetc(stdin);//从键盘输入
//	fputc(ch,stdout);//从屏幕输出
//	return 0;
//}

//文本输入函数
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

//文本输出函数
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	fputs("abcdef\n",pf);
//	fputs("ghijklmn", pf);//输入到文件中
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main()
//{
//	//从键盘读取一行函数
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
//	//格式化形式写文件
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
//	//格式化形式输入数据
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