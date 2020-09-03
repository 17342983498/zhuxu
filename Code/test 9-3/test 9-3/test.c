#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main() 
//{
//	unsigned int a = 0xFFFFFFF7; 
//	unsigned char i = (unsigned char)a; 
//	char *b = (char *)&a;
//	printf("%08x,%08x", i, *b); 
//	return 0; 
//}

//int main()
//{
//	int j = 4;
//	int i = j;
//	for (; i <= 2 * j; i++) 
//	{
//		switch (i / j) 
//		{
//		case 0: 
//		case 1: 
//			printf("*"); 
//			break; 
//		case 2: 
//			printf("#");
//			
//		}
//	}
//	return 0;
//}

//int main() 
//{ 
//	int x = 1, y = 012; 
//	printf("%d", y*x++); 
//	return 0;
//}


//int main() 
//{ 
//	int arr[] = { 1, 2, 3, 4, 5 }; 
//	int *ptr = (int *)(&arr + 1); 
//	printf("%d %d\n", *(arr + 1), *(ptr - 1)); 
//	return 0;
//}

//int main() 
//{ 
//	unsigned short sht = 0; 
//	sht--; 
//	printf("%d", sht);
//	return 0; 
//}

//int main()
//{
//	unsigned long pulArray[] = { 6, 7, 8, 9, 10 }; 
//	unsigned long *pulPtr; 
//	pulPtr = pulArray; 
//	*(pulPtr + 2) += 2; 
//	printf("%d,%d\n", *pulPtr, *(pulPtr + 2));
//	return 0;
//}

//void main() 
//{ 
//	char *szStr = "abcdef";
//	szStr += 2; 
//	printf("%lu\n", szStr); 
//	return; 
//}

//int main() 
//{ 
//	int i;
//	char acNew[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; 
//	for (i = 0; i < 10; i++)
//	{ 
//		acNew[i] = '0';
//	}
//	printf("%d\n", strlen(acNew)); 
//	return;
//}
//
//void foo(int b[][3]) 
//{ 
//	++b;
//	b[1][1] = 9; 
//}
//void main() 
//{ 
//	int a[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } }; 
//	foo(a); 
//	printf("%d", a[2][1]);
//}

int main()
{
	//int x = 0, y = 0, z = 0;
	//z = (x == 1) && (y = 2); 
	//printf("%d ", y);
	int i = 10; 
	int j = sizeof(i++);
	printf("%d", i);
}