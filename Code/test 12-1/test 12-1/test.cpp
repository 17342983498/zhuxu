#define _CRT_SECURE_NO_WARNINGS 1

//��Ӿ���

//ţţ�ٰ���һ�α�̱���,�μӱ�������3*n��ѡ��,ÿ��ѡ�ֶ���һ��ˮƽֵa_i.
//����Ҫ����Щѡ�ֽ������,һ�����n������,��ÿ������3��.ţţ���ֶ����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ��

//����:
//һ������������Ա��ˮƽֵ�ֱ���3, 3, 3.��ô�����ˮƽֵ��3
//һ������������Ա��ˮƽֵ�ֱ���3, 2, 3.��ô�����ˮƽֵ��3
//һ������������Ա��ˮƽֵ�ֱ���1, 5, 2.��ô�����ˮƽֵ��2
//Ϊ���ñ������п���, ţţ�밲�Ŷ���ʹ���ж����ˮƽֵ�ܺ����

//��������ʾ :
//���ţţ��6����Ա���ֵ���������
//�������Ϊ :
//team1 : {1, 2, 5}, team2 : {5, 5, 8}, ��ʱ��ˮƽֵ�ܺ�Ϊ7.
//���������Ϊ :
//   team1 : {2, 5, 8}, team2 : {1, 5, 5}, ��ʱ��ˮƽֵ�ܺ�Ϊ10.
//		   û�б��ܺ�Ϊ10����ķ���, �������10.


#if 0
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main()
{
	size_t n;
	while (cin >> n)
	{
		vector<int> v(3 * n);
		for (size_t i = 0; i<3 * n; i++)
		{
			cin >> v[i];
		}

		sort(v.begin(), v.end());
		size_t sum = 0;
		for (size_t i = 0; i<n; i++)
		{
			sum += v[2 * i + n];
		}
		cout << sum << endl;
	}
	return 0;
}
#endif


//ɾ�������ַ�

//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
//���磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��


#if 0
#include <iostream>
using namespace std;

#include <string>

int main()
{
	string  s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int arr[256] = { 0 };
	string str;

	for (int i = 0; i<s2.size(); i++)
	{
		arr[s2[i]] = 1;
	}

	for (int i = 0; i<s1.size(); i++)
	{
		if (arr[s1[i]] != 1)
		{
			str += s1[i];
		}
	}
	cout << str << endl;
	return 0;
}
#endif


//����������
//ţţ��������������Ϊһ��������һ��������������, ��������������Ƿǵ������߷ǵݼ�����ġ�
//ţţ��һ������Ϊn����������A, ��������һ�������ǰ�����A��Ϊ���ɶ�����������, ţţ��֪�������ٿ��԰���������Ϊ��������������.
//��������ʾ, ţţ���԰�����A����Ϊ[1, 2, 3]��[2, 2, 1]��������������, ������Ҫ����Ϊ2������������, �������2


#if 0
#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i<n; i++)
	{
		cin >> v[i];
	}
	int count = 0;
	int i = 0;
	while (i<n)
	{
		if (v[i]<v[i + 1])
		{
			while (i<n&&v[i] <= v[i + 1])
			{
				i++;
			}
			count++;
			i++;
		}
		else if (v[i] == v[i + 1])
		{
			i++;
		}
		else
		{
			while (i<n&&v[i] >= v[i + 1])
			{
				i++;
			}
			count++;
			i++;
		}
	}
	cout << count << endl;
	return 0;
}
#endif



//�����ַ���

//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing.�����������Ϊ��beijing.like I


#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
int main()
{
	string s;
	getline(cin, s);
	reverse(s.begin(), s.end());
	auto start = s.begin();
	int i = 0;
	while (start != s.end())
	{
		auto end = start;
		while (*end != ' ' && end != s.end())
		{
			end++;
		}
		reverse(start, end);
		if (end != s.end())
		{
			start = end + 1;
		}
		else
		{
			start = end;
		}
	}
	cout << s << endl;
	return 0;
}