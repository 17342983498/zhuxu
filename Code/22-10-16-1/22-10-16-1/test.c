#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//
//#define WAPE_BIT(a) a = (((a&0Xaaaaaaaa)>>1)+((a&0X55555555)<<1))
//
//int main()
//{
//	int a = 13;
//	int ret = WAPE_BIT(a);
//	printf("%d\n", ret);
//	return 0;
//}


//struct S
//{
//	char a;
//	int b;
//	char c;
//};
//
//#define OFFSETOF(s_type,m_name) (int)&(((s_type*)0)->m_name)
//
//int main()
//{
//	printf("%d ", OFFSETOF(struct S, a));
//	printf("%d ", OFFSETOF(struct S, b));
//	printf("%d ", OFFSETOF(struct S, c));
//}




int main() {
	int a;
	while (scanf("%d", &a) != EOF) { // 注意 while 处理多个 case
		// 64 位输出请用 printf("%lld")
		int arr[100000] = { 0 };
		for (int i = 0; i<a; i++)
		{
			scanf("%d", &arr[i]);
		}
		int num = 0;
		for (int i = 0; i<a; i++)
		{
			num ^= arr[i];
		}
		int pos = 0;
		for (int i = 0; i<32; i++)
		{
			if ((num >> i & 1) == 1)
			{
				pos = i;
				break;
			}
		}
		int x = 0, y = 0;
		for (int i = 0; i<a; i++)
		{
			if ((arr[i] >> pos & 1) == 1)
			{
				x ^= arr[i];
			}
			else{
				y ^= arr[i];
			}
		}
		if (x>y)
		{
			int m = x;
			x = y;
			y = m;
		}
		printf("%d %d", x, y);
	}
	return 0;
}