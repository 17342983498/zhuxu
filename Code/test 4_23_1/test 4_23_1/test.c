#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//void* my_memcpy(void* str1, const void* str2, size_t count)
//{
//	void* ret = str1;
//	assert(str1);
//	assert(str2);
//	while (count--)
//	{
//		*(char*)str1 = *(char*)str2;
//		((char*)str1)++;
//		((char*)str2)++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "zhuxu";
//	void* ret = my_memcpy(arr1, arr2, 5);
//	printf("%s\n", (char*)ret);
//	return 0;
//}
void* my_memcpy(void* str1, const void* str2, size_t count)
{
	void* ret = str1;
	assert(str1);
	assert(str2);
	while (count--)
	{
		*(char*)str1 = *(char*)str2;
		((char*)str1)++;
		((char*)str2)++;
	}
	return ret;
}
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr2[] = { 6, 6, 6 };
	void* ret = my_memcpy(arr1, arr2, 12);
	int i = 0;
	for (i = 0; i < (sizeof(arr1) / sizeof(arr1[0])); i++)
	{
		printf("%d ", arr1[i]);
	
	}
	printf("\n");
	return 0;
}