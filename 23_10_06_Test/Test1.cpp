#include<stdio.h>
#include<iostream>

void ScanfinputNum(int& a, int& b)
{
    printf("\n숫자 하나를 입력하세요:");
    scanf_s("%d", &a);
    printf("\n숫자 하나 더 입력하세요:");
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
    printf("\n%d와 %d 사이의 숫자를 모두 더하면 %d입니다.\n", a, b, nResult);
}