#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#if 0
int main()
{
	FILE *fp = fopen("myfile", "w");
	if (!fp){
		printf("fopen error!\n");
	}
	const char *msg = "hello bit!\n";
	int count = 5;
	while (count--){
		fwrite(msg, strlen(msg), 1, fp);
	}
	fclose(fp);
	return 0;
}
#endif
#if 0
int main()
{
	FILE *fp = fopen("myfile", "r");
	if (!fp){
		printf("fopen error!\n");
	}
	char buf[1024];
	const char *msg = "hello bit!\n";
	while (1)
	{
		//注意返回值和参数，此处有坑，仔细查看man手册关于该函数的说明
		size_t s = fread(buf, 1, strlen(msg), fp);
		if (s > 0)
		{
			buf[s] = 0;
			printf("%s", buf);
		}
		if (feof(fp))
		{
			break;
		}
	}
	fclose(fp);
	return 0;
}
#endif