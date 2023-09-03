#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>


void TestVector1()
{
	vector<int> v1;  //�޲ι��죬��������Ϊ int
	vector<int> v2(5, 10);  //����v2,���5��10
	vector<int> v3(v2); //ͨ��v2��������v3
	vector<int> v4(v2.begin(),v2.end());  //ʹ�õ���������
}



void TestVector2()
{
	vector<int> v(5,10);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}


void TestVector3()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl << endl;

	v.resize(15);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl << endl;

	v.resize(5);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl << endl;

	v.resize(8, 100);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

//reserve
void TestVector4()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);

	//cout << v.size() << endl;
	//cout << v.capacity() << endl << endl;

	//v.reserve(16);
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//cout << v.size() << endl;
	//cout << v.capacity() << endl << endl;

	//v.reserve(5);
	//cout << v.size() << endl;
	//cout << v.capacity() << endl << endl;


	v.assign(100, 8);
	for (auto e : v)
	{
		cout << e << " ";
	}
}

#include <time.h>

// ����vector��Ĭ�����ݻ���
// vs������1.5����ʽ����
// linux������2����ʽ����
void TestVectorExpand()
{
	size_t begin = clock();
	size_t sz;
	vector<int> v;
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
	size_t end = clock();
	cout << end - begin << endl;
}

void TestVector5()
{
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.pop_back();
	v.pop_back();
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestVector6()
{
	// ʹ���б�ʽ��ʼ����C++11���﷨
	vector<int> v{ 1, 2, 3, 4 };

	// ��ָ��λ��ǰ����ֵΪval��Ԫ�أ����磺3֮ǰ����30,���û���򲻲���
	// 1. ��ʹ��find����3����λ��
	// ע�⣺vectorû���ṩfind���������Ҫ����ֻ��ʹ��STL�ṩ��ȫ��find
	auto pos = find(v.begin(), v.end(), 3);
	if (pos != v.end())
	{
		// 2. ��posλ��֮ǰ����30
		v.insert(pos, 30);
	}

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	pos = find(v.begin(), v.end(), 30);
	// ɾ��posλ�õ�����
	v.erase(pos);

	it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


// operator[]+index �� C++11��vector����ʽfor+auto�ı���
// vectorʹ�������ֱ�����ʽ�ǱȽϱ�ݵġ�
void TestVector7()
{
	vector<int> v{ 1, 2, 3, 4 };

	// ͨ��[]��д��0��λ�á�
	v[0] = 10;
	cout << v[0] << endl;

	// 1. ʹ��for+[]С�귽ʽ����
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	vector<int> swapv;
	swapv.swap(v);

	cout << "v data:";
	for (size_t i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	// 2. ʹ�õ���������
	cout << "swapv data:";
	auto it = swapv.begin();
	while (it != swapv.end())
	{
		cout << *it << " ";
		++it;
	}

	// 3. ʹ�÷�Χfor����
	for (auto x : v)
		cout << x << " ";
	cout << endl;
}



void TestVector8()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6 };

	auto it = v.begin();

	// ����ЧԪ�ظ������ӵ�100���������λ��ʹ��8��䣬�����ڼ�ײ������

	// v.resize(100, 8);


	// reserve�����þ��Ǹı����ݴ�С�����ı���ЧԪ�ظ����������ڼ���ܻ�����ײ������ı�

	// v.reserve(100);


	// ����Ԫ���ڼ䣬���ܻ��������ݣ�������ԭ�ռ䱻�ͷ�

	// v.insert(v.begin(), 0);

	// v.push_back(8);


	// ��vector���¸�ֵ�����ܻ�����ײ������ı�

	v.assign(100, 8);

	/*

	����ԭ�����ϲ��������п��ܻᵼ��vector���ݣ�Ҳ����˵vector�ײ�ԭ��ɿռ䱻�ͷŵ���
	���ڴ�ӡʱ��it��ʹ�õ����ͷ�֮��ľɿռ䣬�ڶ�it����������ʱ��ʵ�ʲ�������һ���Ѿ����ͷŵ�
	�ռ䣬�������������ʱ������

	�����ʽ�������ϲ������֮�������Ҫ����ͨ������������vector�е�Ԫ�أ�ֻ���it����
	��ֵ���ɡ�

	*/

	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


void TestVector9()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	// ʹ��find����3����λ�õ�iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	// ɾ��posλ�õ����ݣ�����pos������ʧЧ��
	v.erase(pos);
	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����

}


void TestVector10()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			v.erase(it);
//		else
		++it;
	}
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}



int main()
{
	TestVector10();
	//TestVectorExpand();
}