#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"
#include <vector>

int main()
{
	vector<int> v{ 1, 5, 8, 6, 3, 2, 7, 4, 9, 0 };
	priority_queue<int> q{ v.begin(), v.end() };
	return 0;
}