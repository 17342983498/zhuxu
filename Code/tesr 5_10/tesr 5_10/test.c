#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<errno.h>
#include<string.h>

//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	fputc('z', pf);
//	fputc('h', pf);
//	fputc('u', pf);
//	fputc('x', pf);
//	fputc('u', pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	printf("%c",fgetc(pf));
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	int ch = fgetc(stdin);
//	fputc(ch,stdout);
//	return 0;
//}
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	fputs("HELLO ", pf);
//	fputs("WORLD!", pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//int main()
//{
//	char arr[1024] = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	fgets(arr,1024,pf);
//	printf("%s", arr);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	char arr[1024] = { 0 };
//	fgets(arr, 1024, stdin);
//	fputs(arr, stdout);
//	return 0;
//}

//struct S 
//{
//	int n;
//	float num;
//	char arr[10] ;
//};
//int main()
//{
//	struct S s = { 100, 3.14f, "zhuxu" };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	fprintf(pf, "%d %f %s", s.n, s.num, s.arr);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct S
//{
//	int n;
//	float num;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	fscanf(pf, "%d %f %s", &(s.n), &(s.num), s.arr);
//	printf("%d %f %s", s.n, s.num, s.arr);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct S
//{
//	int n;
//	float num;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 0 };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.num), s.arr);
//	fprintf(stdout,"%d %f %s", s.n, s.num, s.arr);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct S
//{
//	int n;
//	float num;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 110, 3.14f, "zhuxu" };
//	char str[1024] = { 0 };
//	sprintf(str, "%d %f %s", s.n, s.num, s.arr);//将结构体里的变量转换成字符串
//	printf("%s\n", str);
//	return 0;
//}

//struct S
//{
//	int n;
//	float num;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 110, 3.14f, "zhuxu" };
//	struct S tmp = { 0 };
//	char str[1024] = { 0 };
//	//把格式化的数据转换成字符串存储到str中
//	sprintf(str, "%d %f %s", s.n, s.num, s.arr);
//	//从str中读取格式化的数据到tmp中
//	sscanf(str, "%d %f %s", &(tmp.n), &(tmp.num), tmp.arr);
//	printf("%d %f %s\n", tmp.n, tmp.num, tmp.arr);
//	return 0;
//}

//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main()
//{
//	struct S s = { "zhuxu", 20, 59 };
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//二进制写文件
//	fwrite(&s,sizeof(struct S),1,pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

struct S
{
	char name[20];
	int age;
	double score;
};
int main()
{
	struct S tmp = { 0 };
	FILE* pf = fopen("test.txt", "rb");
	if (pf == NULL)
	{
		return 0;
	}
	//以二进制形式读文件
	fread(&tmp,sizeof(struct S),1,pf);
	printf("%s %d %lf", tmp.name, tmp.age, tmp.score);
	fclose(pf);
	pf = NULL;
	return 0;
}