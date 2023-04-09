#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
//int main()
//{
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	int flag = 1;
//	int count1 = 0, count2 = 0;
//	auto it1 = s1.begin();
//	auto it2 = s2.begin();
//	while (it1 != s1.end() || it2 != s2.end())
//	{	
//		if ((*it1 == *it2) || (*it1 - *it2 == 32) || (*it2 - *it1 == 32) || (*it1 == '?'))
//		{
//			it1++;
//			it2++;
//		}
//		else if (*it1 == '*')
//		{
//			it1++;
//			if (*it1 == '?' || *it1 == '*')
//			{
//				if (*it1 == '?')
//				{
//					count1++;
//				}
//				it1++;
//			}
//			while ((*it1 != *it2) || (*it1 - *it2 != 32) || (*it2 - *it1 != 32))
//			{
//				if (!((*it2>'0'&&*it2<'9') || (*it2>'a'&&*it2<'z') || (*it2>'A'&&*it2<'Z')))
//				{
//					flag = 0;
//					break;
//				}
//				it2++;
//				count2++;
//			}
//			if (count2<count1)
//			{
//				flag = 0;
//				break;
//			}
//		}
//	
//	}
//	if (flag == 1)
//	{
//		cout << "true" << endl;
//	}
//	else
//	{
//		cout << "false" << endl;
//	}
//	return 0;
//}


//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	for (int x = 0; x <= 12; x++)
//	{
//		for (int y = 4; y <= 25; y++)
//		{
//			for (int z = 75; z <= 84; z += 3)
//			{
//				if (((x * 5 + y * 3 + (z / 3)) == 100) && (x + y + z == 100))
//				{
//					cout << x << y << z << endl;
//				}
//			}
//		}
//	}
//}





class person
{
public:
	person()
	{
		cout << "person()" << endl;
	}
	~person()
	{
		cout << "~person()" << endl;
	}
};

class student:public person
{
public:
	student()
	{
		cout << "student()" << endl;
	}
	~student()
	{
		cout << "~student()" << endl;
	}
};


int main()
{
	person s;
	student p;


	//person* s1 = new person;
	//student* p1 = new student;

	//delete s1;
	//delete p1;

	//person* s2 = new student;
	//delete s2;
}