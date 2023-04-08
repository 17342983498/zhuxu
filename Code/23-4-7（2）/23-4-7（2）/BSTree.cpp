#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include "BSTree.h"

int main()
{
	int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> t;
	for (auto e : arr)
	{
		t.Insert(e);
	}

	t.Inorder();
	
	t.Erase(5);
	t.Inorder();
	return 0;
}