#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	FILE * pFile;
//	pFile = fopen("myfile.txt", "w");
//	if (pFile != NULL)
//	{
//		fputs("fopen example", pFile);
//		fclose(pFile);
//	}
//	return 0;
//}
#include <errno.h>
#include <string.h>


//int main()
//{
//	FILE* pfWrite = fopen("test.txt", "w");
//	if (pfWrite == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	fputc('a', pfWrite);
//	fputc('b', pfWrite);
//	return 0;
//}


//int  main()
//{
//	FILE* pfRead = fopen("test.txt", "r");
//	if (pfRead == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	printf("%c ", fgetc(pfRead));
//	printf("%c ", fgetc(pfRead));
//	printf("%c ", fgetc(pfRead));
//	fclose(pfRead);
//	pfRead = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pfwrite = fopen("test.txt", "w");
//	if (pfwrite == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	fputs("helloworld!", pfwrite);
//	return 0;
//}


int main()
{
	char str[20] = { 0 };
	FILE* pfread = fopen("test.txt", "r");
	if (pfread == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	fgets(str, 20, pfread);
	printf("%s\n", str);
	return 0;
}