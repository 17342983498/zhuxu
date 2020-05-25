#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

int main()
{
	char password[7] = "secert";
	char userInput[81] = "0";
	scanf("%s", userInput);
	if (strcmp(password, userInput)==0)
	{
		printf(" Correct password!Welcome to whe system...\n" ) ;
	}
	else if (strcmp(password, userInput) < 0)
	{
		printf(" Invalid password!user input<password\n") ;
	}
	else
	{
		printf(" Invalid password!user input>password\n") ;
	}
	return 0;
}