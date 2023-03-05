#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>

////vector<vector<int>>& generate(vector<vector<int>>& vv,int numrows)
////{
////	vv.resize(numrows);
////	for (int i = 1; i <= numrows; ++i)
////	{
////		vv[i - 1].resize(i, 1);
////	}
////
////	for (int i = 2; i < numrows; ++i)
////	{
////		for (int j = 1; j < i; ++j)
////		{
////			vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
////		}
////	}
////	return vv;
////}
//
//
//int main()
//{
//	vector<vector<int>> vv;
//	vv.resize(6);
//	for (int i = 1; i <= 6; ++i)
//	{
//		vv[i - 1].resize(i, 1);
//	}
//
//	for (int i = 2; i < 6; ++i)
//	{
//		for (int j = 1; j < i; ++j)
//		{
//			vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//		}
//	}
//	for (int i = 0; i < 6; ++i)
//	{
//		for (int j = 0; j <= i; ++j)
//		{
//			cout << vv[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}




//vector<vector<int>>& generate(vector<vector<int>>& vv,int numrows)
//{
//	vv.resize(numrows);
//	for (int i = 1; i <= numrows; ++i)
//	{
//		vv[i - 1].resize(i, 1);
//	}
//
//	for (int i = 2; i < numrows; ++i)
//	{
//		for (int j = 1; j < i; ++j)
//		{
//			vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//		}
//	}
//	return vv;
//}
//
//int main()
//{
//	vector<vector<int>> vv;
//	
//	generate(vv, 6);
//	for (int i = 0; i < 6; ++i)
//	{
//		for (int j = 0; j <= i; ++j)
//		{
//			cout << vv[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}



