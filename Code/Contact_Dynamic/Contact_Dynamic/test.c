#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//void menu()
//{
//	printf("\n\n\t\t-------------------------��ӭʹ��-------------------------\n");
//	printf("\t\t��� 1. ADD                           ���\n\n");
//	printf("\t\t��� 2. DEL                           ���\n\n");
//	printf("\t\t��� 3. SEARCH                        ���\n\n");
//	printf("\t\t��� 4. MODIFY                        ���\n\n");
//	printf("\t\t��� 5. SHOW                          ���\n\n");
//	printf("\t\t��� 6. SORT                          ���\n\n");
//	printf("\t\t��� 0. EXIT                          ���\n\n");
//	printf("\t\t----------------------------------------------------------\n");
//}
int main()
{
	int n = 0;
	system("color 3E");
	//int size = 0;
	//
	////����ͬѧ¼
	//struct PeoInfo con[MAX];//���MAX���˵���Ϣ
	struct Contact con;//con����ͬѧ¼����߰���dataָ���size��capacity
	//��ʼ��ͬѧ¼
	/*menu();*/

	InitContcat(&con);
	do
	{ 
		printf("\n\n\t\t-------------------------��ӭʹ��-------------------------\n");
		printf("\t\t��� 1. ADD                           ���\n\n");
		printf("\t\t��� 2. DEL                           ���\n\n");
		printf("\t\t��� 3. SEARCH                        ���\n\n");
		printf("\t\t��� 4. MODIFY                        ���\n\n");
		printf("\t\t��� 5. SHOW                          ���\n\n");
		printf("\t\t��� 6. SORT                          ���\n\n");
		printf("\t\t��� 0. EXIT                          ���\n\n");
		printf("\t\t----------------------------------------------------------\n");
		printf("\t\t�����������������\n");
		printf("\t\t��ѡ����Ҫ���е�ѡ�(0-6):");
		scanf("%d", &n);
		printf("\t\t�����������������\n");
		Sleep(1000);
		switch (n)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			Sleep(1000);
			//����ͬѧ¼
			DestroyContact(&con);
			printf("�˳�ͬѧ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (n);
	return 0;

}
