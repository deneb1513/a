#include"money.h"
#include<stdio.h>

static int s_money = 0;

extern int g_money;// extern 변수가 나올거라고 미리 알려주는 역할

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
