#include<stdio.h>
#include<iostream>

void ScanfinputNum(int& a, int& b)
{
    printf("\n���� �ϳ��� �Է��ϼ���:");
    scanf_s("%d", &a);
    printf("\n���� �ϳ� �� �Է��ϼ���:");
    scanf_s("%d", &b);
}

int main()
{
    int a = 0, b=0;
    int nResult = 0;
    ScanfinputNum(a, b);
    for (int i = a+1; i< b; ++i)
    {
        printf("%d\n", i);
        nResult += i;
    }
    printf("%d", nResult);
    printf("\n%d�� %d ������ ���ڸ� ��� ���ϸ� %d�Դϴ�.\n", a, b, nResult);
}