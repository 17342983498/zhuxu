#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");
	fwrite(&a, 4, 1, pf);//�����Ƶ���ʽд���ļ���
	fclose(pf);
	pf = NULL;
	return 0;
}


//#include <windows.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	fputs("abcdef", pf);//��ʱֻ�ǽ����ݷŵ��˻���������
//	printf("˯��10��-�Ѿ�д�����ˣ���test.txt�ļ��������ļ�û������\n");
//	Sleep(10000);
//	printf("ˢ�»�����\n");
//	fflush(pf);//ˢ�»�����ʱ���Ž����������������д���˴��̵���
//	printf("��˯��10��-��ʱ���ٴδ�test.txt�ļ����ļ���������\n");
//	Sleep(10000);
//	//fclose�ڹر��ļ���ʱ��Ҳ��ˢ�»�����
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