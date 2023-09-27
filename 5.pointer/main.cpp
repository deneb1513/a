#include<stdio.h>
#include<iostream>

void BuyItem(int* Money, int price)
{
	//int*Money�� �޸� ������ �Ͼ�� �ʴ´�.
	//�޸𸮿� ȿ������ ����, ������ ������ ���ϴ�.
	*Money -= price;
}

enum ePhoneType
{
	iPhone = 0,
	Galaxys23,
    GalaxyFold,
    GalaxyZ
};

struct stPhoneShop
{
	int iPhoneCnt;
	int Galaxys23;
	int GalaxyFold;
	int GalaxyZ;

	void printfPhoneCnt()
	{
		printf("iPhone=%d, Galaxys23=%d, GalaxyFold=%d, GalaxyZ=%d\n", iPhoneCnt, Galaxys23, GalaxyFold, GalaxyZ);
	}
};

void BuyPhone(ePhoneType phoneType,stPhoneShop* pPs)
{
	switch (phoneType)
	{
	case ePhoneType::iPhone:
		pPs->iPhoneCnt--;//����Ʈ�� �����ϴ� ����ü�� ������ "->"Ű����� �����Ѵ�.
		break;
	case ePhoneType::Galaxys23:
		pPs->Galaxys23--;
		break;
	case ePhoneType::GalaxyFold:
		pPs->GalaxyFold--;
		break;
	case ePhoneType::GalaxyZ:
		pPs->GalaxyZ--;
		break;
	default:
		break;
	}
}
//number�� �޾Ƽ� ȭ�鿡 ����Ѵ�.
void printNumber(const int* number)
{   // number = nullptr;// ������ �ּ� ���� ������ �� �ִ�.
	// *number =2;
	printf("pinrt number=%d\n", *number);
}

void printNumber2(const int& number)
{
	// number = nullptr;
	// *number =4;
	printf("pinrt number=%d\n", number);
} //���� printNumber��� ���� ����. ���� ���۷��� ������� ��.

void printPhoneShop(const stPhoneShop* ps)
{
	printf("pinrt iPhoneCnt=%d\n", ps -> iPhoneCnt);
}

void printPhoneShop(const stPhoneShop& ps)
{
	printf("pinrt iPhoneCnt=%d\n", ps.iPhoneCnt);
}

int main()
{
	int a = 0; //4Byte
	int b = 0;
	//�����͸� ����ϴ� ����
	// �޸𸮿� ȿ������ ����, ������ ������ ���ϴ�.
	// int*pA: ������ ������ ����(pA�� ���ִ� �ּҿ� int���� ũ�⸸ŭ �����Ѵ�.)
	// nullptr : ������ ������ �ʱ�ȭ ��(�ּҰ��� �������)
	//�������� NULL�� ����ߴµ� Null=0�� �ǹ� �׷��� 0�̶� �ǹ̰� �����ؼ� ���� �߻�
	//�ּҰ��� ��������̶�� ��Ȯ�� �ǹ̸� ���� Nullptr���
	//�������� ũ��(x32���� 4Byte, x64���� 8Byte)
	int* pA = nullptr;
	pA = &a;//a�ּҰ��� pA�� �ִ´�.
	// *:���۷����� �����Ѵ�. (�ּҰ� ����Ű�� �ִ� ���� ������.)
	b = *pA;//b�� pA�� ����Ű�� �ִ� �ּҷ� ���� �ִ´�.
	*pA = 10; //pA�� ����Ű�� �ִ� �ּҿ� ���� 10���� �����Ѵ�.

	int num1 = 0;
	int num2 = 0;
	int* pNum = nullptr;
	pNum = &num1; //pNum�� num1�� �ּҰ��� �ִ´�.(pNum�� num1�� ����Ű�� �ִ� ����)
	printf("pNum=%d\n", *pNum); //num1�� 0
	*pNum = 20;   //pNum�� ����Ű�� �ִ� num1�� 20�� �ִ´�.
	printf("pNum=%d\n", *pNum); //num1�� 20
	pNum = &num2; //pNum�� num2�� �ּҰ��� �ִ´�.(pNum�� num2�� ����Ű�� �ִ� ����)
	printf("pNum=%d\n", *pNum); //num2�� 0
	*pNum = 30;	  //pNum�� ����Ű�� �ִ� num2�� 30�� �ִ´�.
	printf("pNum=%d\n", *pNum); //num2�� 30
	printf("%d, %d\n", num1, num2);

	//-----------------------------------------------------------------------------------//
	int Money = 10000;
	
	BuyItem(&Money, 1000);
	printf("MyMoney=%d\n", Money);

	stPhoneShop stPs;
	stPs.iPhoneCnt = 100;
	stPs.Galaxys23 = 100;
	stPs.GalaxyFold = 100;
	stPs.GalaxyZ = 100;

	BuyPhone(ePhoneType::Galaxys23, & stPs);
	stPs.printfPhoneCnt();

	//-----------------------------------------------------------------------------------//
	//�迭�� ������

	int arrint[10] = { 0,10,20,30,40,50,60,70,80,90 };
	int* pint = nullptr;
	pint = arrint;
	printf("pint=%d\n", *pint);
	pint += 1;
	printf("pint=%d\n", *pint);

	short arrS[10] = { 0,10,20,30,40,50,60,70,80,90 };
	pint = (int*)arrS; //(int*)�� ����ؼ� int*�� ���� ����ȯ(Cast)�Ѵ�.
	pint += 1; //pint�� int*�̹Ƿ� int(4Byte)��ŭ ���� �ּҰ��� �����Ѵ�.
	short* pS = (short*)pint;//int(4BYte)��ŭ �̵��� �ּҰ��� Short(2Byte) 2�� �̵��� �� >>>�� ���ڼ��� ����
	printf("pS=%d\n", *pS);

	//x32 ��Ű���� = x86 ��Ű����
	//int32(4Byte) = 0~ 4,294,967,295(Byte) >>4G�̻��� �������� ���ϴ� ���� �߻�

	//�Ʒ� �迭�� ���� ���� ������� ���
	int arr[10] = { 10,2,78,53,6,33,27,99,7,31 };


	printf("���� ��:");
	for (int i = 0; i < 10; i++)
	{
		if (i > 0) printf(",");
		printf("%d", arr[i]);
	}
	printf("\n");
	
	for (int i = 0; i < 10; i++)
	{
		int lowestindex = i;//���� ���� index����

		for (int j = i + 1; j < 10; j++)
		{
			if (arr[lowestindex] > arr[j])
			{
				// lowestindex�� j�� ������� ��
				// j index�� ���� ������ j�� ���ο�  lowestindex
				lowestindex = j;
			}
		}
		//j for���� ����Ǹ� lowestindex���� ���� ���� ���� index ���� ����
		//i �� ���������� ���鼭 ���� ���� ���� ���ߵ�
		// lowestindex ���� i index�� ���� ��ü�Ѵ�.
		int temp = arr[i];
		arr[i] = arr[lowestindex];
		arr[lowestindex] = temp;
	}

	printf("���� ��:");
	for (int i = 0; i < 10; i++)
	{
		if (i > 0) printf(",");
		printf("%d", arr[i]);
	}
	printf("\n");

	// const ���ȭ
	// �Ǽ��� ���ϼ� �־ ����� Ƚ���� ���ϼ� �ִ�. �����: ���׸� ã�ų� �����ϴ� ��� ����
	const int cint = 100;//���

	int value = 0;
	int value2 = 0;
	int* pValue = &value;
	// const int* pValue = &value; // �����Ͱ� ����Ű�� ���� ���� �Ұ���, ������ �� ��������, ���� ����
	// int const* pValue = &value; // �����Ͱ� ����Ű�� ���� ���� �Ұ���, ������ �� ��������, ���� ����
	// int *const pValue = &value; // �����Ͱ� ����Ű�� ���� ���� ����, ������ �� ���� �Ұ���, ���� ����
	// const int *const pValue = &value; // �����Ͱ� ����Ű�� ���� ���� �Ұ���, ������ �� ���� �Ұ���, ���� ����
	// int const *const pValue = &value; // �����Ͱ� ����Ű�� ���� ���� �Ұ���, ������ �� ���� �Ұ���, ���� ����

	*pValue = 2;
	pValue = &value2;
	printf("pValue=%d\n", *pValue);
	
	printNumber(&value);

	printNumber2(value);




	return 0; 

}