#pragma once

class CMyclass2
{
	
	int m_b;
public:
	

	CMyclass2(int valueA = 0);

	CMyclass2(int valueA, int valueB);

	
	~CMyclass2();

	void PrintB();

	void SetC(int num);
	
public:
	int a;
protected:
private:
	int c;

};