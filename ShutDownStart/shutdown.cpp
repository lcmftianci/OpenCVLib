#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int input;
	while (1)
	{
		system("cls");
		printf("ѡ��Ҫִ�еĲ���\n");
		printf("1:�ػ�\n");
		printf("2:ȡ���ػ�\n");
		scanf("%d", &input);
		if (input == 1)
		{
			system("COLOR 53");
			system("shutdown -s -t 10");
			system("COLOR 69");
		}
		else if (input == 2)
		{
			system("COLOR 53");
			system("shutdown -a");
			system("COLOR 69");
		}
	}
	return 0;
}