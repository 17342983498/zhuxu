#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
//int main()
//{
//	string s1, s2, maxs;
//	getline(cin, s1);
//	auto it = s1.begin();
//
//	while (it != s1.end())
//	{
//		while (it != s1.end() && *it >= 48 && *it <= 57)
//		{
//			s2.push_back(*it);
//			++it;
//		}
//		if (s2.size()>maxs.size())
//		{
//			maxs = s2;
//
//		}
//
//		s2.clear();
//
//		if (it != s1.end())
//		{
//			it++;
//		}
//	}
//	//maxs += '\0';
//	cout << maxs << endl;
//	return 0;
//}



//sort(numbers.begin(), numbers.end());
//auto it = numbers.begin();
//int count = 1;
//int max = numbers[0];
//++it;
//while (it != numbers.end())
//{
//	if (*it == max)
//	{
//		count++;
//	}
//
//	++it;
//}


//int main()
//{
//	
//	int arr[7] = { 3, 3, 3, 3, 2, 2, 2 };
//	vector<int> numbers(arr,arr+7);
//	sort(numbers.begin(), numbers.end());
//	auto it = numbers.begin();
//	int count = 0;
//	int maxcount = 1;
//	int max = numbers[0];
//	++it;
//	while (it != numbers.end())
//	{
//		if (*it == max)
//		{
//			maxcount++;
//			++it;
//		}
//		else{
//			break;
//		}
//	}
//	it = numbers.begin() + maxcount;
//	if (it == numbers.end())
//	{
//		cout << max << endl;
//	}
//	else
//	{
//		int m = *it;
//		while (it != numbers.end())
//		{
//			if (*it == m)
//			{
//				count++;
//			}
//			else
//			{
//				if (count>maxcount)
//				{
//					maxcount = count;
//					max = m;
//					m = *it;
//					count = 1;
//				}
//				else{
//					m = *it;
//					count = 1;
//				}
//			}
//			++it;
//		}
//		if (it == numbers.end() && count > maxcount)
//		{
//			max = m;
//		}
//		cout << max << endl;
//	}
//}













//sort(numbers.begin(), numbers.end());
//auto it = numbers.begin();
//int count = 0;
//int maxcount = 1;
//int max = numbers[0];
//++it;
//while (it != numbers.end())
//{
//	if (*it == max)
//	{
//		maxcount++;
//		++it;
//	}
//	else{
//		break;
//	}
//}
//it + maxcount - 1;
//int m = *it;
//while (it != numbers.end())
//{
//	if (*it == m)
//	{
//		count++;
//	}
//	else
//	{
//		if (count>maxcount)
//		{
//			maxcount = count;
//			max = m;
//			m = *it;
//			count = 1;
//		}
//		else{
//			m = *it;
//			count = 1;
//		}
//	}
//	++it;
//}
//return max;




#include <string>

//int main() 
//{
//	int num = 0, x = 0;
//	cin >> num >> x;
//	string s;
//	string str = "0123456789ABCDEF";
//	if (num == 0) 
//	{
//		cout << "0" << endl;
//	}
//	else
//	{
//		if (num<0)
//		{
//			cout << "-";
//			num = -num;
//		}
//		//while (num)
//		//{
//		//	int n = num % x;
//		//	s += str[n];
//		//	//if (n > 9 && n < 16)
//		//	//{
//		//	//	n += 7;
//		//	//}
//		//	//s += (n + 48);
//		//	num /= x;
//		//}
//
//		while (num)
//		{
//			int n = num % x;
//			
//			if (n > 9 && n < 16)
//			{
//				n += 7;
//			}
//			s += (n + 48);
//			num /= x;
//		}
//		auto it = s.rbegin();
//		while (it != s.rend())
//		{
//			cout << *it;
//			it++;
//		}
//		cout << endl;
//	}
//	return 0;
//}