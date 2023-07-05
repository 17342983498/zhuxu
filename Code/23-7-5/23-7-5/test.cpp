#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include "SmartPtr.h"


int main()
{
//	//zx::test_shared();
//	//zx::test_shared_safe();
//	zx::test_shared_cycle();
	zx::test_shared_deletor();
	return 0;
}
