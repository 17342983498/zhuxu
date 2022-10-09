#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	fputs("abcdef", pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//int main()
//{
//	char arr[10] = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	fgets(arr, 7, pf);
//	printf("%s\n", arr);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//int main()
//{
//	FILE* pf = fopen("test.txt", "a");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	fputs("ghi", pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test.txt", "a+");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	fputs("ghik", pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//
//int main()
//{
//	char arr[10] = { 0 };
//	FILE* pf = fopen("test.txt", "a+");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	fgets(arr, 10, pf);
//	printf("%s\n", arr);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}