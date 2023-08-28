#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <set>
#include <unordered_set>
#include <time.h>
#include <vector>
using namespace std;



int main()
{
	const size_t N = 100000;
	set<int> s;
	unordered_set<int> us;
	vector<int> v;
	srand(time(0));

	for (int i = 0; i < N; i++)
	{
		v.push_back(i);
		//v.push_back(rand());
		//v.push_back(rand() + i);
	}
	
	//²åÈë
	size_t begin1 = clock();
	for (auto e : v)
	{
		s.insert(e);
	}
	size_t end1 = clock();

	size_t begin2 = clock();
	for (auto e : v)
	{
		us.insert(e);
	}
	size_t end2 = clock();

	cout << "set insert: " << end1 - begin1 << endl;
	cout << "unordered_set insert: " << end1 - begin1 << endl;


	//²éÕÒ
	size_t begin3 = clock();
	for (auto e : v)
	{
		s.find(e);
	}
	size_t end3 = clock();

	size_t begin4 = clock();
	for (auto e : v)
	{
		us.find(e);
	}
	size_t end4 = clock();

	cout << "set find: " << end3 - begin3 << endl;
	cout << "unordered_set find: " << end4 - begin4 << endl;

	cout << s.size() << endl;
	cout << us.size() << endl << endl;;

	//É¾³ý
	size_t begin5 = clock();
	for (auto e : v)
	{
		s.erase(e);
	}
	size_t end5 = clock();

	size_t begin6 = clock();
	for (auto e : v)
	{
		us.erase(e);
	}
	size_t end6 = clock();

	cout << "set erase: " << end5 - begin5 << endl;
	cout << "unordered_set erase: " << end6 - begin6 << endl;

	return 0;
}