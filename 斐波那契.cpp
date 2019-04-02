#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int sum = 0;
int feibonaqi(int a) 
{
	if (a - 2 == 0)
	{
		return 1;
	}
	if (a - 1 == 0)
	{
		return 0;
	}
	sum = feibonaqi(a - 1) + feibonaqi(a - 2);
	return sum;
}
int main()
{
	int a = 0;
	int num = 0;
	int num1 = 1;
	int num2 = 1;
	printf("请输入您想求的项数：\n");
	scanf("%d", &a);
	if (a <= 0)
		printf("输入错误\n");
	else if (a == 1)
	{
		printf("%d\n", num);
	}
	else if (a == 2)
	{
		printf("%d\n", num1);
	}
	else if (a == 1)
	{
		printf("%d\n", num2);
	}
	else 
		for (int i = 4; i <= a; i++)
		{
			num = num1;
			num1 = num2;
			num2 = num + num1;
			if (i == a)
			{
				printf("%d\n", num2);
			}
		}
	printf("%d\n", feibonaqi(a));
	system("pause");
	return 0;
}