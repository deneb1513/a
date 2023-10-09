#include<stdio.h>
#include"sum.h"
#include"Minus.h"
#include"Multi.h"
#include"Divide.h"
#include"Average.h"
//�Լ��̸� : sum
//�Ű�����(�Ķ��Ÿ) : int a, int b
//��ȯ ��: int
//a�� b�� ���� ����� ��ȯ�Ͻÿ�.

//�Լ��̸� : Minus
//�Ű�����(�Ķ��Ÿ) : int a, int b
//��ȯ ��: int
//a�� b�� �� ����� ��ȯ�Ͻÿ�.

//�Լ��̸� : Multi
//�Ű�����(�Ķ��Ÿ) : int a, int b
//��ȯ ��: int
//a�� b�� ���� ����� ��ȯ�Ͻÿ�.


//�Լ��̸� : Divid
//�Ű�����(�Ķ��Ÿ) : int a, int b
//��ȯ ��: int
//a�� b�� ���� ����� ��ȯ�Ͻÿ�.

//�Լ��̸� : Average
//�Ű�����(�Ķ��Ÿ) : int & sum, int a, int b, int c
//��ȯ ��: ����
//���۷��� ���� Sum���� a, b, c�� ��� ���� ��ȯ.

void Average (int&sum, int a, int b, int c)
{
	sum=(a + b + c) / 3;
}
	

//�Լ��̸� : ArraySum
//�Ű�����(�Ķ��Ÿ) : int* arr, int length
//��ȯ ��: int
//�迭 "arr"�� �迭�� ���� "length"�� �Ķ��Ÿ�� �޾Ƽ� ��� �迭�� ���� ��ȯ

int ArraySum(int* arr, int length)
{
	int a = length;
	int b = 0;
	for (int i = 0; i < a; ++i)
	{
		b += arr[i];
	}
	return b;
}

// Ŭ���� �̸� : CShop
// �ɹ� ���� : m_value(�⺻��:0)
// �ɹ� �Լ� �߰� : printValue
// printValue �Լ� ��� : "Value=%d"�� m_value ���
class CShop
{

public:
	int m_value;

	void printValue()
	{
		printf("Value=%d\n", m_value);
	}
};


// Ŭ���� �̸� : CPhoneShop
// �θ� Ŭ���� : CShop
// ������ �Ķ��Ÿ : int PhoneCnt ( m_PhoneCnt�� �� ���� )
// ������ �Ķ��Ÿ : int PhonePrice ( m_PhonePrice�� �� ���� )
// �ɹ� ���� : m_PhoneCnt
// �ɹ� ���� : m_PhonePrice
// printValue �Լ� ��� : "Value=%d"�� m_PhoneCnt * m_PhonePrice���
class CPhoneShop : public CShop
{
public:
	CPhoneShop(int PhoneCnt, int PhonePrice):m_PhoneCnt(PhoneCnt), m_PhonePrice(PhonePrice)
	{

	}
	void printValue()
	{
		printf("Value=%d\n", m_PhoneCnt * m_PhonePrice);
	}
	int m_PhoneCnt;
	int	m_PhonePrice;
};

	//CPhoneShop(10, 100) ���� �� ��ü�� printValue ���

		// Ŭ���� �̸� : CFruitShop
		// ������ �Ķ��Ÿ : int FruitCnt ( m_FruitCnt�� �� ���� )
		// ������ �Ķ��Ÿ : int FruitPrice ( m_FruitPrice�� �� ���� )
		// �θ� Ŭ���� : CShop
		// �ɹ� ���� : m_FruitCnt
		// �ɹ� ���� : m_FruitPrice
		// printValue �Լ� ��� : "Value=%d"�� m_FruitCnt * m_FruitPrice���

		//CFruitShop(10, 100) ���� �� ��ü�� printValue ���
class CFruitShop : public CShop
{
public:
	CFruitShop(int FruitCnt, int FruitPrice):m_FruitCnt(FruitCnt), m_FruitPrice(FruitPrice)
	{

	}
	void printValue()
	{
		printf("Value=%d\n", m_FruitCnt * m_FruitPrice);
	}
};

int main()
{
	int iResult = 0;
	float fResult = 0;
	int rResult = 0;
	//printf�� "sum=%d\n"�� sum �Լ� ��� ���
	iResult = sum(4, 3);
	printf("sum=%d\n", iResult);
	//printf�� "minus=%d\n"�� minus �Լ� ��� ���
    iResult = Minus(4, 3);
	printf("minus=%d\n", iResult);
	//printf�� "multi=%d\n"�� multi �Լ� ��� ���
	iResult = Multi(4, 3);
	printf("Multi=%d\n", iResult);
	//printf�� "Divid=%d\n"�� Divid �Լ� ��� ���
	fResult = Divid(4, 2);
	printf("Divid=%f\n", fResult);
	int aa; 
	Average(aa, 1, 2, 3);
	printf("Average=%d\n", aa);
	
	int arr[5] = {1, 3, 5, 7, 9};
	rResult = ArraySum(arr, 5);
	printf("ArraySum=%d\n", rResult);


}