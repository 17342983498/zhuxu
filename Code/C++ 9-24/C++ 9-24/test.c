#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//void exchange(char* arr1, char* arr2)
//{
//	while (*arr1)
//	{
//		if (*arr1 != ' ')
//		{
//			*arr2 = *arr1;
//			arr2++;
//		}
//		else
//		{
//			strcpy(arr2, "20%" );
//			arr2 += 3;
//		}
//		arr1++;
//	}
//	*arr2 = '\0';
//}
//int main()
//{
//	char arr1[40];
//	gets(arr1);
//	char arr2[40];
//	exchange(arr1, arr2);
//	printf("%s\n", arr2);
//	return 0;
//}

//void exchange(char* arr1, char* arr2)
//{
//	while (*arr1)
//	{
//		if (*arr1 != ' ')
//		{
//			*arr2 = *arr1;
//			arr2++;
//		}
//		else
//		{
//			strcpy(arr2, "20%");
//			arr2 += 3;
//		}
//		arr1++;
//	}
//	*arr2 = '\0';
//}
//int main()
//{
//	char arr1[40];
//	gets(arr1);
//	char arr2[40];
//	exchange(arr1, arr2);
//	printf("%s\n", arr2);
//	return 0;
//}

//int main()
//{
//	char a= -1;
//	signed char b=-1;
//	unsigned char c=-1;
//	printf("a=%d,b=%d,c=%d",a,b,c);
//	return 0; 
//} 

//int main() 
//{ 
//	unsigned char a = -128;     
//	printf("%d\n", a);     
//	return 0; 
//	//int i = -20; 
//	//unsigned  int  j = 10; 
//	//printf("%d\n", i + j);
//	//return 0;
//}

int main()
{
	int n = 9;
	float *pFloat = (float *)&n;
	printf("n的值为：%d\n", n);
	printf("*pFloat的值为：%f\n", *pFloat);

	*pFloat = 9.0;
	printf("n的值为：%d\n", n);
	printf("*pFloat的值为：%f\n", *pFloat);
	return 0;
}
