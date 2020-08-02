#define _CRT_SECURE_NO_WARNINGS 1

void TestSort();
void PrintSort(int array[], int size);
void InsertSort(int array[], int size);
void swap(int* left, int*right);
int Partion(int array[], int left, int right);
void QuickSort(int array[], int left, int right);
void HeapSort(int array[], int size);
void HeapAdjust(int array[], int size, int parent);
void BubbleSort(int array[], int size);
void ShellSort(int array[], int size);
void SelectSort1(int array[], int size);
void SelectSort2(int array[], int size);
void SelectSortOP(int array[], int size);