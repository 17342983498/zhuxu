#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h> 
//int fun(char *s) 
//{ 
//	char *p = s; 
//	while(*p != '\0')
//	{ 
//		p++; 
//	}
//	return(p-s); 
//}
//int main() 
//{ 
//	printf("%d\n",fun("goodbye!")); 
//}

//int main() 
//{ 
//	unsigned char a = 0xA5; 
//	unsigned char b = ~a >> 4 + 1; 
//	printf("%d\n", b); 
//	return 0; 
//}
//int main()
//{
//	const int i = 0; 
//	int *j = (int *)&i; 
//	*j = 1; 
//	printf("%d,%d", i, *j);
//	return 0;
//}

//int main() 
//{ 
//	int i = 1; 
//	printf("%d, %d\n", sizeof(i++), i); 
//	return 0; 
//}
//
//int main() 
//{ 
//	char a[1000]; 
//	int i; 
//	for (i = 0; i<1000; i++) 
//	{ 
//		a[i] = (char)(-1 - i); 
//	}
//	printf("%d\n", strlen(a)); 
//	return 0; 
//}


//int f(int x, int y) 
//{ 
//	return (x&y) + ((x^y) >> 1); 
//}
//int main() 
//{ 
//	int result = f(2, 4); 
//	printf("%d\n", result); 
//	return 0; 
//}

void fun(int x, int y, int *c, int *d) 
{ 
	*c = x + y; 
	*d = x - y; 
}
int main() 
{ 
	int a = 4, b = 3, c = 0, d = 0; 
	fun(a, b, &c, &d); 
	printf("%d %d\n", c, d); 
}