#include<stdio.h>
//�Լ���
// int : ��ȯ �ڷ���
// CalculatorSum : �Լ��̸�
// (int x, int y) : �Ű� ���� (�Ķ��Ÿ)
unsigned int CalculatorSum(int x, int y)
{//->�Լ� ����
	printf("�Լ�����.\n");

	return x + y; // <-��ȯ �� ���� ó��

	printf("�Լ�����.\n");
}//->�Լ� ��

// ���� �Լ� �����
unsigned int CalculatorMinus(int x, int y)
{
	return x - y;
}
// ���ϱ� �Լ� �����
unsigned int CalculatorMultiply(int x, int y)
{
	return x * y;
}
// ������ �Լ� �����
 float CalculatorDivide(float x, float y)
{
	return x / y;
}
// ������ �Լ� �����
 unsigned int CalculatorRemain(int x, int y)
 {
	 return x % y; 
 }
	 
 //Factorial �Լ�
 int Factorial(int Num)
 {
	 int FacResult = 1;

	 for (int i = Num; i > 0; --i)
	 {
		 FacResult *= i; 
	 }

	 return FacResult;
 }

 int FactorialA(int Num)
 {
	 int FacResult = 1;

	 for (int i = FacResult; i <=Num; ++i)
	 {
		 FacResult *= i;
	 }
	 return FacResult; 
 }
 //����Լ��� �̿��� ���丮�� ����
 int ReFactorial(int Num)
 {
	 if (Num == 1)
	 {
		 return 1; 
	 }

	 return Num * ReFactorial(Num - 1);
 }

 int SumToN(int Num)
 {
	 int SumResult = 0;
	 
	 for (int i = SumResult; i <= Num; ++i)
	 {
		 SumResult += i;
	 }
	 return SumResult;
 }

 int AAA()
 {
	 while (1)
	 {
		 printf("1st While Start\n");
		 break;
		 printf("1st While End\n");
	 }

	 while (1)
	 {
		 printf("2nd While Start\n");
		 return 0;
		 printf("2nd While End\n");
	 }

	 while (1)
	 {
		 printf("3rd While Start\n");
		 break;
		 printf("3rd While End\n");
	 }
	 return 0;
 }


 void CallFunction()
{// return <<- �� ������ ����ǰ� ��ȯó�� �ȴ�.
	printf("�Լ� ȣ��");
}

int main()
{
	/*unsigned int nResult = 0;
	float fResult = 0.0f;
	nResult = CalculatorSum(1, 1);
	printf("�Լ� ���� ��� = %d\n", nResult);
	CallFunction();

	nResult = CalculatorMinus(1, 1);
	printf("�Լ� ���� ��� = %d\n", nResult);

	nResult = CalculatorMultiply(2, 2);
	printf("�Լ� ���� ��� = %d\n", nResult);

	fResult = CalculatorDivide(6.0, 2.0);
	printf("�Լ� ���� ��� = %f\n", fResult);

	nResult = CalculatorRemain(7, 2);
	printf("�Լ� ���� ��� = %d\n", nResult);*/


	// �ݺ���
	// for��
 //   for (/*�ʱ⼳��*/ int i = 0; /* �ݺ�����üũ*/ i < 10; /*�ݺ� �� ó�� */++i)
	//{
	// //�ݺ�ó���� �ڵ� ����
	//		printf("hello\n");
	//}// <-�ݺ� ó���� �ڵ� ��

	//for (int i = 0; i < 10; ++i)
	//{
	//	printf("%d Hello\n", i);
	//}
	//
	//int a = 0;
	//for (; a < 5; ++a)
	//{
	//	printf("HelloA\n");
	//}

	//for (int b = 0; b < 10; b += 2)
	//{
	//	printf("HelloB\n");
	//}

	//int FacResult = 1;
	//
	//for (int i = 1; i <= 4; ++i)
	//{
	//	FacResult *= i;
	//	printf("1������ = %d\n", FacResult);
	//}

	//printf("2������ = %d\n", Factorial(5));
	//
	//printf("3������ = %d\n", FactorialA(5));
	//printf("����=%d\n", CalculatorMinus(1, 1));
	//printf("4������ =%d\n", ReFactorial(5));

	////1~n���� �� ���ϴ� �Լ�
	////int SumToN (int Num)
	//printf("5������ = %d\n", SumToN(8));
    
	
	
	//int i = 1;
	//nResult = 1;
	//while (true/*���ǽ�*/)
	//	// (i <= 10) <- �� ���ǽ��� true�� �߰�ȣ ���� �ڵ� ����
	//	// (i <= 10) <- �� ���ǽ��� false�� while���� �����ϰ� ���� �ڵ� ����
	//{// �ݺ� ó���� ���� �ڵ�
	//	printf("i=%d\n", i);
	//	i++;
	//	printf("break ������\n");
	//	break;// �� ��ɾ ������ ����
	//	printf("break ���� ��\n");
	//}// �ݺ� ó�� �ڵ� ����
	/*
	while (i <= 10)
	{
		nResult *= i;
		i++;
	}
	printf("6������ = %d\n", nResult);*/

	//0~Num ¦���� ���ϱ�

	/*int Z = 0, Num=10;
	int ZResult = 0;*/
	/*while(Z <= Num)
	{
		Z++;
		if (Z % 2 == 0)
		{
			ZResult += Z;
		}
	}
	printf("0~Num EvenSum=%d\n", ZResult);*/
	
	//while (Z <= Num)
	//{
	//	Z++;
	//	if (Z % 2 != 0)
	//		continue;// ���� �ڵ带 �������� �ʰ� while���� �ݺ��Ѵ�
	//	ZResult += Z;
	//}
	//printf("0~Num EvenSum=%d\n", ZResult);

	// ���� �ڵ带 for ������ ����ÿ�
	int Num = 10;
	int nResult = 0;
	for (int i = 0; i <= Num; ++i)
	{
		if (i % 2 != 0)
			continue;

		nResult += i;	
	}
	printf("%d\n", nResult);

	AAA();
}