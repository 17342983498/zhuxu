#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

//定义存储概率数组最大长度
const int maxn = 11;

//定义静态全局变量
static char p[maxn][10];
static int flag1 = 0;
static int ncount;
static int ncount1;

//定义不可变误差精度
const double eps = 1e-10;

/*--------------Fano子函数---------------*/
//二元编码
void Fano(int m, int n, float y[maxn])
{
	int j, k;
	float sum = 0, s = 0, s1;
	flag1++;

	if (flag1 == 1)
		ncount1 = n;

	//当分组中仅剩一个元素则不继续分组直接return
	if (m == n) return;

	//计算分组中元素sum用于二次分组
	for (j = m; j <= n; j++)
		sum = sum + y[j];

	k = m;

	//按概率和对半分组
	do
	{
		s1 = s;
		s = s + y[k++];
	} while (s <= sum - s);
	//现在考虑第k个元素的最佳分组
	//其中k--表示第k个元素最好分在后面一组
	//理论上<= 和< 生成的码字可能不同 但编码效率应该一致
	if ((sum - 2 * s1) <= (2 * s - sum)) k--;

	//以k为中线，把m～n间的概率分为两组
	//各组所有元素分别在对应p后附上0或1
	for (j = m; j < k; j++)
		strcat(p[j], "0");

	for (j = k; j <= n; j++)
		strcat(p[j], "1");

	//分左右两组进行递归
	Fano(m, k - 1, y);
	Fano(k, n, y);

}

//计算信源信息熵
float comentropy(float a[])
{
	float sum = 0;

	for (int i = 1; i <= ncount; i++)
		sum -= a[i] * log2(a[i]);

	return sum;
}

//sort的参数 用于实现降序排序
bool cmp(int a, int b)
{
	return a > b;
}

/*-------------------主函数--------------------*/
int main()
{
	int i, flag;
	float a[maxn], s = 0.0, code_length = 0.0;

	//输入信源符号个数
	printf("输入信源符号个数:\n");
	scanf_s("%d", &ncount);

	flag = 0;

	while (!flag)
	{
		flag = 1;
		printf("输入符号的概率分别是:\n");

		for (i = 1; i <= ncount; i++)
		{
			scanf_s("%f", &a[i]);
			if ((a[i] < eps) || (a[i] - 1 > eps))
			{
				printf("请输入0到1之间的数\n");
				flag = 0;
				break;
			}

			else s = s + a[i];
		}

		if (abs(s - 1) > eps)
		{
			printf("请使输入概率为1!!\n");
			flag = 0;
			s = 0;
		}
	}
	//复杂度比较：冒泡 O(n^2) --- sort O(nlogn)

	//将概率由大到小排序
	sort(a + 1, a + ncount + 1, cmp);

	//Fano子函数
	Fano(1, ncount, a);

	//输出结果
	printf("费诺编码结果:\n\n");

	printf("概率\t\t费诺码字\t\t码长\n\n");

	for (i = 1; i <= ncount; i++)
	{
		printf("%.3f\t\t\t", a[i]);
		//顺序输出数组内存储的0-1码字
		printf("%s", p[i]);
		printf("   \t\t\t%zu\n", strlen(p[i]));
		code_length += strlen(p[i]) * a[i];
	}

	//计算平均码长
	printf("平均码长 :%.3f \n", code_length);

	//计算编码效率
	printf("编码效率 : %.3f \n", comentropy(a) / code_length);
	cout << endl;
}