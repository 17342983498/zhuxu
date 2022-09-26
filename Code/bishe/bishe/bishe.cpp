#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

//����洢����������󳤶�
const int maxn = 11;

//���徲̬ȫ�ֱ���
static char p[maxn][10];
static int flag1 = 0;
static int ncount;
static int ncount1;

//���岻�ɱ�����
const double eps = 1e-10;

/*--------------Fano�Ӻ���---------------*/
//��Ԫ����
void Fano(int m, int n, float y[maxn])
{
	int j, k;
	float sum = 0, s = 0, s1;
	flag1++;

	if (flag1 == 1)
		ncount1 = n;

	//�������н�ʣһ��Ԫ���򲻼�������ֱ��return
	if (m == n) return;

	//���������Ԫ��sum���ڶ��η���
	for (j = m; j <= n; j++)
		sum = sum + y[j];

	k = m;

	//�����ʺͶ԰����
	do
	{
		s1 = s;
		s = s + y[k++];
	} while (s <= sum - s);
	//���ڿ��ǵ�k��Ԫ�ص���ѷ���
	//����k--��ʾ��k��Ԫ����÷��ں���һ��
	//������<= ��< ���ɵ����ֿ��ܲ�ͬ ������Ч��Ӧ��һ��
	if ((sum - 2 * s1) <= (2 * s - sum)) k--;

	//��kΪ���ߣ���m��n��ĸ��ʷ�Ϊ����
	//��������Ԫ�طֱ��ڶ�Ӧp����0��1
	for (j = m; j < k; j++)
		strcat(p[j], "0");

	for (j = k; j <= n; j++)
		strcat(p[j], "1");

	//������������еݹ�
	Fano(m, k - 1, y);
	Fano(k, n, y);

}

//������Դ��Ϣ��
float comentropy(float a[])
{
	float sum = 0;

	for (int i = 1; i <= ncount; i++)
		sum -= a[i] * log2(a[i]);

	return sum;
}

//sort�Ĳ��� ����ʵ�ֽ�������
bool cmp(int a, int b)
{
	return a > b;
}

/*-------------------������--------------------*/
int main()
{
	int i, flag;
	float a[maxn], s = 0.0, code_length = 0.0;

	//������Դ���Ÿ���
	printf("������Դ���Ÿ���:\n");
	scanf_s("%d", &ncount);

	flag = 0;

	while (!flag)
	{
		flag = 1;
		printf("������ŵĸ��ʷֱ���:\n");

		for (i = 1; i <= ncount; i++)
		{
			scanf_s("%f", &a[i]);
			if ((a[i] < eps) || (a[i] - 1 > eps))
			{
				printf("������0��1֮�����\n");
				flag = 0;
				break;
			}

			else s = s + a[i];
		}

		if (abs(s - 1) > eps)
		{
			printf("��ʹ�������Ϊ1!!\n");
			flag = 0;
			s = 0;
		}
	}
	//���ӶȱȽϣ�ð�� O(n^2) --- sort O(nlogn)

	//�������ɴ�С����
	sort(a + 1, a + ncount + 1, cmp);

	//Fano�Ӻ���
	Fano(1, ncount, a);

	//������
	printf("��ŵ������:\n\n");

	printf("����\t\t��ŵ����\t\t�볤\n\n");

	for (i = 1; i <= ncount; i++)
	{
		printf("%.3f\t\t\t", a[i]);
		//˳����������ڴ洢��0-1����
		printf("%s", p[i]);
		printf("   \t\t\t%zu\n", strlen(p[i]));
		code_length += strlen(p[i]) * a[i];
	}

	//����ƽ���볤
	printf("ƽ���볤 :%.3f \n", code_length);

	//�������Ч��
	printf("����Ч�� : %.3f \n", comentropy(a) / code_length);
	cout << endl;
}