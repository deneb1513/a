#include"MyClass.h"
#include<stdio.h>

CMyclass2::CMyclass2(int valueA) : a(valueA), m_b(0), c(0)
{
	printf("������A ȣ���\n");
}

CMyclass2::CMyclass2(int valueA, int valueB) : a(valueA), m_b(valueB), c(0)
{
	printf("������B ȣ���\n");
}


CMyclass2::~CMyclass2()
{
	printf("�ı��� ȣ���\n");
}

void CMyclass2::PrintB()
{
	printf("B=%d", m_b);
}
void CMyclass2::SetC(int num)
{
	c = num;
}