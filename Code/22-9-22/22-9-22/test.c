#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <errno.h>
#include <string.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	fputc('z',pf);
//	fputc('h',pf);
//	fputc('u',pf);
//	return 0;
//}



//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	printf("%c\n",fgetc(pf));
//	printf("%c\n", fgetc(pf));
//	printf("%c\n", fgetc(pf));
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	fputs("hello world!",pf);
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	char arr[20] = { 0 };
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	fgets(arr,20,pf);
//	printf("%s\n", arr);
//	return 0;
//}


struct S
{
	int a;
	char b;
	float f;
};

//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	struct S s = { 12, 'v', 3.14f };
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	fprintf(pf, "%d,%c,%lf",s.a, s.b, s.f);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	struct S s = { 0 };
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	fscanf(pf, "%d,%c,%f",&(s.a), &(s.b), &(s.f));
//	printf("%d %c %.2lf\n", s.a, s.b, s.f);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//int main()
//{
//	struct S s = { 12, 'v', 3.14f };
//	char buf[20] = { 0 };
//	struct S s1 = { 0 };
//	sprintf(buf, "%d %c %f", s.a, s.b, s.f);
//	printf("%s\n", buf);
//	sscanf(buf, "%d %c %f", &(s.a), &(s.b), &(s.f));
//	printf("%d %c %.2lf\n", s.a, s.b, s.f);
//	return 0;
//}

//#include <stdlib.h>
//
//int main()
//{
//	char arr[5] = { 'a', 'b', 'c', 'd', 'e' };
//	FILE* pf = fopen("test.txt", "w");
//	char c = 0;
//	size_t ret_code = 0;
//	if (pf == NULL)
//	{
//		perror("File opening failed");
//		return EXIT_FAILURE;
//	}
//	fwrite(arr, sizeof(arr[0]), 5, pf);
//	fclose(pf);
//	pf = fopen("test.txt", "r");
//	while (ret_code = fread(&c, sizeof(char), 1, pf) >= 1)
//	{
//		printf("%c\n", c);
//	}
//	if (feof(pf))
//		printf("Error reading test.bin: unexpected end of file\n");
//	else if (ferror(pf)) {
//		perror("Error reading test.bin");
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//int main()
//{
//	union
//	{
//		short k;
//		char i[2];
//	}*s, a;
//	s = &a;
//	s->i[0] = 0x39;
//	s->i[1] = 0x38;
//	printf("%x\n", a.k);
//	return 0;
//}



int main()
{
	int arr1[20] = { 1, 2, 3, 2, 4, 3, 5, 6, 5, 6, 4, 7, 8, 7 };
	int arr2[20] = { 0 };
	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		arr2[arr1[i]]++;
	}
	for (int i = 0; i < 20; i++)
	{
		if (arr2[arr1[i]] == 1)
		{
			printf("%d ", arr1[i]);
		}
	}
	return 0;
}