#include<stdio.h>
#include<iostream>

//x64�� ��� Ŭ���� ũ�⸦ 8, 16, 24, 32������ 8byte �������� �Ҵ�
//RTTI���� 8byte+4byte =12byte
//12byte�� ���� �� �ִ� �ּ����� ������ 16byte
class CBase
{
public:
	//�����Լ�
	//virtual Ű���带 �Լ� �տ� ���δ�.
	//�ڽ� Ŭ�������� �Լ��� override�� �ؼ� �籸�� ����
	//���� �Լ��� �Ǹ� RTTI������ ����Ű�� ������ ���� ����8byte(x64 ����) �Ҵ�
	//RTTI �����ʹ� �ش� Ŭ������ ������ ����Ű�� ��
	//��Ÿ���� �������� �Ҵ�
	//dynamic_cast�� Ŭ������ ũ�⸦ �����ϴ°� �ƴ϶� �߰��� �Ҵ�� RTTI�������� Ŭ���� ���� ����
	virtual void printx()
	{
		printf("X=%d", m_X);
	}

	int m_X = 10;
};

//RTTI���� �Ҵ� 8byte +8byte =16byte
// 16byte�� ���� �� �ִ� �ּ����� ������ 24byte
class CChild1 : public CBase
{
public:
	void printY()
	{
		printf("Y=%d", m_Y);
	}
	int m_Y = 20;
};

class CChild2 : public CBase
{
public:
	void printZ()
	{
		printf("Z=%d", m_Z);
	}
	int m_Z = 20;
};



int main()
{
	int64_t i64 = sizeof(CBase);
	printf("CBase Size=%I64d\n", i64); //sizeof : ��ü�� ũ�� ��ȯ ���
	printf("CChild1 Size=%I64d\n", sizeof(CChild1)); 

	int64_t* pB = (int64_t*)new CBase;
	int64_t* pC = (int64_t*)new CChild1;
	printf("pB[0]=%I64d, pB[1]=%d\n", pB[0], (int)pB[1]);
	printf("pC[0]=%I64d, pC[1]=%d,  pC[2]=%d\n", pC[0], (int)pC[1], (int)pC[2]);

	delete pB;
	delete pC;

	CBase* pBase[] = { new CChild1, new CChild2 };

	for (CBase* pTemp : pBase)
	{
		pTemp->printx();

		//dynamic_cast
		//<CChild*>
		//(pTemp)
		//CChild1
		CChild1* pChild = dynamic_cast<CChild1*>(pTemp);
		if (pChild == nullptr)
			continue;

		pChild->printY();
	}

	for (CBase* pTemp : pBase)
	{
		delete pTemp;
	}

}