#define _CRT_SECURE_NO_WARNINGS 1


void PrintArray(int array[],int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void InsertSort(int array[], int sz)
{
	for (int i = 1; i < sz; i++)
	{
		int x = array[i];
		int j = i - 1;
		//while (j >= 0 && array[j] > x)
		//{
		//	array[j + 1] = array[j];
		//	j--;
		//}
		for (; j >= 0; j--)
		{
			if (array[j] > x)
			{
				array[j + 1] = array[j];
			}
			else
			{
				break;
			}
		}
		array[j + 1] = x;
	}
}

void SellSort(int array[], int sz)
{
	int gap = sz;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < sz; i++)
		{
			int x = array[i];
			int j = i - gap;
			while (j >= 0 && array[j] > x)
			{
				array[j + gap] = array[j];
				j-=gap;
			}
			array[j + gap] = x;
		}
	}
}

void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

void BubbleSort(int array[], int sz)
{
	for (int i = sz - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (array[j]>array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
			}
		}
	}
}

void SelectSort(int array[], int sz)
{
	for (int i = sz - 1; i > 0; i--)
	{
		int max = array[0];
		for (int j = 1; j <= i; j++)
		{
			if (array[j] > max)
			{
				max = array[j];
			}
		}
		Swap(&array[i], &max);
	}
}

int main()
{
	int array[10] = { 5, 8, 1, 0, 3, 6, 9, 7, 4, 2 };
	int sz = sizeof(array) / sizeof(array[0]);
	InsertSort(array, sz);
	PrintArray(array, sz);
	SellSort(array, sz);
	PrintArray(array, sz);
	BubbleSort(array, sz);
	PrintArray(array, sz);
	SelectSort(array, sz);
	PrintArray(array, sz);
}