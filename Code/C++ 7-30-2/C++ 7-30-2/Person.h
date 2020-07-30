#define _CRT_SECURE_NO_WARNINGS 1

class student
{
public:
	void setstuInfo(const char* name, const char* sex, int age, const char* addres);
	void printstuInfo();
	char _name[20];
	char _sex[5];
	int _age;
	char _addres[20];
};
