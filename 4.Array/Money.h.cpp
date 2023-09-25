#include<stdio.h>

int g_money = 0;//전역변수
int addmoney(int money)
{
	int t_money = 0;
	t_money += money;
	g_money += money;

	printf("t_money=%d\n", t_money);
	printf("g_money=%d\n", g_money);
	return 0;
}

int usemoney(int money)
{
	return 0;
}
