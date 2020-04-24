#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>


//void* my_memmove(void* dest,const void* src, size_t count)
//{
//	void* ret = dest;
//	assert(dest);
//	assert(src);
//	while (count--)
//	{
//		if (dest < src)
//		{
//			*((char*)dest)++ = *((char*)src)++;
//		}
//		else
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//	return ret;
//}

//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	char arr2[] = "abcdefghijk";
//	my_memmove(arr1, arr1+3, 20);
//    char* ret = my_memmove(arr2, arr2 + 3, 5);
//	int i = 0;
//	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	printf("%s\n", ret);
//	return 0;
//}


//int my_memcmp(const void* str1,const void* str2, size_t count)
//{
//	assert(str1);
//	assert(str2);
//	while (count--)
//	{
//		if (*(char*)str1 == *(char*)str2)
//		{
//			((char*)str1)++;
//			((char*)str2)++;
//		}
//		else if (*(char*)str1 < *(char*)str2)
//		{
//			return -1;
//		}
//		else
//			return 1;
//	}
//	return 0;
//}


//int my_memcmp(void*buf1, void*buf2, size_t count)
//{
//	assert(buf1);
//	assert(buf2);
//	while (count--)
//	{
//		if (*(char*)buf1  == *(char*)buf2)
//		{
//			buf1  = (char*)buf1  + 1;
//			buf2  = (char*)buf2  + 1;
//		}
//        else
//        {
//	         if (*(char*)buf1 > *(char*)buf2)
//	         {
//		         return 1;
//	         }
//             else
//             {
//	             return -1;
//             }
//         }
//	}
//	return 0;
//}

//int main()
//{
//	/*char arr1[] = "abcdefg";
//	char arr2[] = "abcderg";*/
//	int arr1[] = { 1, 2, 3, 4, 5, 6 };
//	int arr2[] = { 1, 2, 3, 4, 7, 8 };
//	int len = my_memcmp(arr1, arr2, 17);
//	printf("%d\n", len);
//	return 0;
//}
