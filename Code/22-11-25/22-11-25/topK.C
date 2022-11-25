#define _CRT_SECURE_NO_WARNINGS 1
#include "TOPk.H"

void Swap(HPDataType* left, HPDataType* right)
{
	HPDataType temp = *left;
	*left = *right;
	*right = temp;
}


void AdjustDown(Heap* hp, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n&&hp->array[child] > hp->array[child + 1])
		{
			child += 1;
		}
		if (hp->array[child] < hp->array[parent])
		{
			Swap(&hp->array[child], &hp->array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	hp->array = (HPDataType*)malloc(sizeof(HPDataType)*n);
	if (hp->array == NULL)
	{
		return;
	}
	memcpy(hp->array, a, sizeof(HPDataType)*n);
	hp->size = hp->capacity = n;
	for (int root = (n - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp, n, root);
	}
	for (int i = n; i < 10; i++)
	{
		if (a[i]>hp->array[0])
		{
			Swap(&a[i], &hp->array[0]);
			AdjustDown(hp, 3, 0);
		}
	}
}

void Test()
{
	int arr[10] = { 5, 8, 1, 6, 3, 0, 2, 7, 4, 9 };
	Heap hp;
	HeapCreate(&hp, arr, 3);
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", hp.array[i]);
	}
	printf("\n");

}