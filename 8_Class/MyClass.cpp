#include"MyClass.h"
#include<stdio.h>

CMyclass2::CMyclass2(int valueA) : a(valueA), m_b(0), c(0)
{
	printf("생성자A 호출됨\n");
}

CMyclass2::CMyclass2(int valueA, int valueB) : a(valueA), m_b(valueB), c(0)
{
	printf("생성자B 호출됨\n");
}


CMyclass2::~CMyclass2()
{
	printf("파괴자 호출됨\n");
}

void CMyclass2::PrintB()
{
	printf("B=%d", m_b);
}
void CMyclass2::SetC(int num)
{
	c = num;
}