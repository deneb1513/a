#include<stdio.h>
//함수형
// int : 반환 자료형
// CalculatorSum : 함수이름
// (int x, int y) : 매개 변수 (파라메타)
unsigned int CalculatorSum(int x, int y)
{//->함수 시작
	printf("함수시작.\n");

	return x + y; // <-반환 및 종료 처리

	printf("함수종료.\n");
}//->함수 끝

// 빼기 함수 만들기
unsigned int CalculatorMinus(int x, int y)
{
	return x - y;
}
// 곱하기 함수 만들기
unsigned int CalculatorMultiply(int x, int y)
{
	return x * y;
}
// 나누기 함수 만들기
 float CalculatorDivide(float x, float y)
{
	return x / y;
}
// 나머지 함수 만들기
 unsigned int CalculatorRemain(int x, int y)
 {
	 return x % y; 
 }
	 
 //Factorial 함수
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
 //재귀함수를 이용한 팩토리얼 구현
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
{// return <<- 을 만나면 종료되고 반환처리 된다.
	printf("함수 호출");
}

int main()
{
	/*unsigned int nResult = 0;
	float fResult = 0.0f;
	nResult = CalculatorSum(1, 1);
	printf("함수 실행 결과 = %d\n", nResult);
	CallFunction();

	nResult = CalculatorMinus(1, 1);
	printf("함수 실행 결과 = %d\n", nResult);

	nResult = CalculatorMultiply(2, 2);
	printf("함수 실행 결과 = %d\n", nResult);

	fResult = CalculatorDivide(6.0, 2.0);
	printf("함수 실행 결과 = %f\n", fResult);

	nResult = CalculatorRemain(7, 2);
	printf("함수 실행 결과 = %d\n", nResult);*/


	// 반복문
	// for문
 //   for (/*초기설정*/ int i = 0; /* 반복조건체크*/ i < 10; /*반복 후 처리 */++i)
	//{
	// //반복처리할 코드 시작
	//		printf("hello\n");
	//}// <-반복 처리할 코드 끝

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
	//	printf("1실행결과 = %d\n", FacResult);
	//}

	//printf("2실행결과 = %d\n", Factorial(5));
	//
	//printf("3실행결과 = %d\n", FactorialA(5));
	//printf("빼기=%d\n", CalculatorMinus(1, 1));
	//printf("4실행결과 =%d\n", ReFactorial(5));

	////1~n까지 합 구하는 함수
	////int SumToN (int Num)
	//printf("5실행결과 = %d\n", SumToN(8));
    
	
	
	//int i = 1;
	//nResult = 1;
	//while (true/*조건식*/)
	//	// (i <= 10) <- 이 조건식이 true면 중괄호 안의 코드 실행
	//	// (i <= 10) <- 이 조건식이 false면 while문을 종료하고 다음 코드 실행
	//{// 반복 처리할 시작 코드
	//	printf("i=%d\n", i);
	//	i++;
	//	printf("break 실행전\n");
	//	break;// 이 명령어를 만나면 종료
	//	printf("break 실행 후\n");
	//}// 반복 처리 코드 종료
	/*
	while (i <= 10)
	{
		nResult *= i;
		i++;
	}
	printf("6실행결과 = %d\n", nResult);*/

	//0~Num 짝수만 더하기

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
	//		continue;// 다음 코드를 실행하지 않고 while문을 반복한다
	//	ZResult += Z;
	//}
	//printf("0~Num EvenSum=%d\n", ZResult);

	// 위의 코드를 for 문으로 만드시오
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