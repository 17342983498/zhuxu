#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//int main()
//{
//	FILE* pf = (FILE*)fopen("test.txt", "w");
//	if (pf==NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	for (int i = 0; i < 26; i++)
//	{
//		fputc('a'+i, pf);
//	}
//  fclose(pf);
//  pf=NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = (FILE*)fopen("test.txt", "r");
//	if (pf==NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	char c = 0;
//	while ((c = fgetc(pf)) != EOF)
//	{
//		printf("%c", c);
//	}
//	fclose(pf);
//  pf=NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = (FILE*)fopen("test.txt", "w");
//	if (pf==NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	fputs("hello ", pf);
//	fputs("world!", pf);
//  fclose(pf);
//  pf=NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf = (FILE*)fopen("test.txt", "r");
//	if (pf==NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	char arr[10] = { 0 };
//	fgets(arr, 7, pf);
//	printf("%s", arr);
//	fclose(pf);
//	pf=NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf = (FILE*)fopen("test.txt", "w");
//	if (pf==NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	fprintf(pf, "%s %d", "zhuxu", 115);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


int main()
{
	FILE* pf = (FILE*)fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return -1;
	}
	char str[10] = { 0 };
	int n = 0;
	fscanf(pf, "%s", str);
	fscanf(pf, "%d", &n);
	printf("%d", n);
	fclose(pf);
	pf = NULL;
	return 0;
}


//struct S
//{
//	int a;
//	char str[10];
//	float f;
//};

//int main()
//{
//	struct S s = { 10, "zhuxu", 3.14f };
//	FILE* pf = (FILE*)fopen("test.txt", "w+");
//	if (pf==NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	fwrite(&s,sizeof(s),1,pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	struct S s = { 10, "zhuxu", 3.14f };
//	FILE* pf = (FILE*)fopen("test.txt", "w+");
//	if (pf==NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	fread(&s,sizeof(s),1,pf);
//	printf("%d %s %.2lf", s.a, s.str, s.f);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}