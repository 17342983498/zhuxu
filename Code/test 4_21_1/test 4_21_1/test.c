#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
//void* my_memcpy(void* dest,const void* src, size_t num)
//{
//	void* str = dest;
//	assert(dest);
//	assert(src);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		((char*)dest)++;
//		((char*)src)++;
//	}
//	return str;
//}
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5, 6 };
//	int arr2[9] = { 0 };
//	int i = 0;
//	my_memcpy(arr2, arr1,sizeof(arr1));
//	for (i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//void* my_memcpy(void *dest, const void *src, size_t count)
//{
//	void *ret = dest;
//	assert(dest);
//	assert(src);
//	while (count--)
//	{
//		*(char*)dest = *(char*)src;
//	    ((char*)dest)++;
//		((char*)src)++;
//			
//	}
//	return ret;
//}
//
//int main() 
//{
//	char arr1[] = "dssdgsgdsgrerg";
//	char arr2[] = "hello world";
//	void *ret = my_memcpy(arr1, arr2, 12);
//	printf("%s\n", (char*)ret);
//	return 0;
//}
//void* my_memmove(void *dest, void *src, size_t count)
//{
//	assert(dest);
//	assert(src);
//	char *s1 = (char *)dest;
//	char *s2 = (char *)src;
//	dest = s1 + 16;
//	src = s2 + 8;
//	if ((s2 < s1) && (s1 < s2 + count))
//	{
//		while (count--)
//		{
//			*(s1 + count) = *(s2 + count);
//		}
//	}
//	else
//	{
//		while (count--)
//		{
//			*s1 = *s2;
//			s1++;
//			s2++;
//		}
//	}
//	return src;
//}
//
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int i = 0;
//	int len = sizeof(arr1) / sizeof(arr1[0]);
//	int* ret = my_memmove(arr1, arr1, 16);
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", *(ret + i));
//	}
//	return 0;
//}


void *my_memmove(void *p1, void *p2, size_t count)
{
	assert(p1);
	assert(p2);
	char *dest = (char *)p1;
	char *src = (char *)p2;
	dest = dest + 16;
	src = src + 8;
	if ((src < dest) && (dest < src + count))
	{
		while (count--)
		{
			*(dest + count) = *(src + count);
		}
	}
	else
	{
		while (count--)
		{
			*dest = *src;
			src++;
			dest++;
		}
	}
	return p2;
}

int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i = 0;
	int len = sizeof(arr1) / sizeof(arr1[0]);
	my_memmove(arr1, arr1, 16);
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}