#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");
	fwrite(&a, 4, 1, pf);//二进制的形式写到文件中
	fclose(pf);
	pf = NULL;
	return 0;
}


//#include <windows.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	fputs("abcdef", pf);//此时只是将数据放到了缓冲区当中
//	printf("睡眠10秒-已经写数据了，打开test.txt文件，发现文件没有内容\n");
//	Sleep(10000);
//	printf("刷新缓冲区\n");
//	fflush(pf);//刷新缓冲区时，才将输出缓冲区的数据写到了磁盘当中
//	printf("再睡眠10秒-此时，再次打开test.txt文件，文件有内容了\n");
//	Sleep(10000);
//	//fclose在关闭文件的时候也会刷新缓冲区
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	char buffer[] = { 'x', 'y', 'z' };
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	fwrite(buffer,1,3,pf);
//	fclose(pf);
//	return 0;
//}


//int main()
//{
//	char buffer[5] = { 0 };
//	FILE* pf = fopen("test.txt", "rb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	fread(buffer, 1, 3, pf);
//	printf("%c ", buffer[0]);
//	printf("%c ", buffer[1]);
//	printf("%c ", buffer[2]);
//	return 0;
//}


//int main()
//{
//	FILE * pFile;
//	pFile = fopen("test.txt", "r");
//	fputs("This is an apple.", pFile);
//	int ch = fgetc(pFile);
//	printf("%c\n", ch);
//	fseek(pFile, 2, SEEK_CUR);
//	int c = fgetc(pFile);
//	printf("%c\n", c);
//	fclose(pFile);
//	return 0;
//}



//int main()
//{
//	FILE * pFile;
//	pFile = fopen("test.txt", "wb");
//	fputs("This is an apple.", pFile);
//	fseek(pFile, -8, SEEK_END);
//	fputs(" sam", pFile);
//	fclose(pFile);
//	return 0;
//}

//
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	int ch = getc(pf);
//	printf("%c\n", ch);
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test.txt", "wb");
//	fputs("This is an apple.", pf);
//	fseek(pf, 1, SEEK_SET);
//	fseek(pf, 8, SEEK_CUR);
//	fputs(" sam", pf);
//	fclose(pf);
//	return 0;
//}