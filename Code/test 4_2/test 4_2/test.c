#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int flag = 0;
//	int killer;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)
//		{
//			flag = 1;
//			printf("killer is %c\n", killer);
//			break;
//		}
//	}
//	if (flag == 0)
//	{
//		printf("Can not find\n");
//	}
//	return 0;
//}


int main() 
{
	int arr[5] = { 0 };   
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0; 
	int e = 0;
	int count=0;
	for (a = 1; a <= 5; a++) 
	{
		for (b = 1; b <= 5; b++) 
		{
			for (c = 1; c <= 5; c++) 
			{
				for (d = 1; d <= 5; d++) 
				{
					for (e = 1; e <= 5; e++)
					{
						//分别将abcde所说的分为两种情况,其中一种必为真
						if ((b == 2 && a != 3) || (b != 2 && a == 3))
						if ((b == 2 && e != 4) || (b != 2 && e == 4))
						if ((c == 1 && d != 2) || (c != 1 && d == 2))
						if ((c == 5 && d != 3) || (c != 5 && d == 3))
						if ((e == 4 && a != 1) || (e != 4 && a == 1)) 
						{
							count = 0;
							arr[0] = a;
							arr[1] = b;
							arr[2] = c;
							arr[3] = d;
							arr[4] = e;
							//判断abcde是否都不相等,若都不相等则可输出结果,count为
							//比较次数,若全部不相等则count=4+3+2+1=10.
							for (int i = 0; i < 5; i++)
							{
								for (int j = i + 1; j < 5; j++)
								{
									if (arr[i] != arr[j])
									{
										count++;
									}
								}
							}
							//count==10则可输出正确名次
							if (count == 10)
							{
								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

