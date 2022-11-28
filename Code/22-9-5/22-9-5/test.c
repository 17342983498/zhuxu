#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


void swap(char* buf1, char* buf2, int width)
{
	for (int i = 0; i < width; i++)
	{
		char temp = *buf1;
		*buf1 = *buf2;
		*buf2 = temp;
		buf1++;
		buf2++;
	}
}

int cmp(const void*elem1,const void*elem2)
{
	return *(int*)elem1 - *(int*)elem2;
}

void bubble_sort(void* base, int sz, int width)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width) > 0)
			{
				swap((char*)base + j*width, (char*)base + (j + 1)*width,width);
			}
		}
	}
}

int main()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]));
	for(int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

