#include<stdio.h>
#include"sum.h"
#include"Minus.h"
#include"Multi.h"
#include"Divide.h"
#include"Average.h"
//함수이름 : sum
//매개변수(파라메타) : int a, int b
//반환 값: int
//a와 b를 합한 결과를 반환하시오.

//함수이름 : Minus
//매개변수(파라메타) : int a, int b
//반환 값: int
//a와 b를 뺀 결과를 반환하시오.

//함수이름 : Multi
//매개변수(파라메타) : int a, int b
//반환 값: int
//a와 b를 곱한 결과를 반환하시오.


//함수이름 : Divid
//매개변수(파라메타) : int a, int b
//반환 값: int
//a와 b를 나눈 결과를 반환하시오.

//함수이름 : Average
//매개변수(파라메타) : int & sum, int a, int b, int c
//반환 값: 없음
//레퍼런스 변수 Sum으로 a, b, c의 평균 값을 반환.

void Average (int&sum, int a, int b, int c)
{
	sum=(a + b + c) / 3;
}
	

//함수이름 : ArraySum
//매개변수(파라메타) : int* arr, int length
//반환 값: int
//배열 "arr"와 배열의 길이 "length"를 파라메타로 받아서 모든 배열의 합을 반환

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

// 클래스 이름 : CShop
// 맴버 변수 : m_value(기본값:0)
// 맴버 함수 추가 : printValue
// printValue 함수 결과 : "Value=%d"로 m_value 출력
class CShop
{

public:
	int m_value;

	void printValue()
	{
		printf("Value=%d\n", m_value);
	}
};


// 클래스 이름 : CPhoneShop
// 부모 클래스 : CShop
// 생성자 파라메타 : int PhoneCnt ( m_PhoneCnt에 값 적용 )
// 생성자 파라메타 : int PhonePrice ( m_PhonePrice에 값 적용 )
// 맴버 변수 : m_PhoneCnt
// 맴버 변수 : m_PhonePrice
// printValue 함수 결과 : "Value=%d"로 m_PhoneCnt * m_PhonePrice출력
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

	//CPhoneShop(10, 100) 생성 후 객체에 printValue 출력

		// 클래스 이름 : CFruitShop
		// 생성자 파라메타 : int FruitCnt ( m_FruitCnt에 값 적용 )
		// 생성자 파라메타 : int FruitPrice ( m_FruitPrice에 값 적용 )
		// 부모 클래스 : CShop
		// 맴버 변수 : m_FruitCnt
		// 맴버 변수 : m_FruitPrice
		// printValue 함수 결과 : "Value=%d"로 m_FruitCnt * m_FruitPrice출력

		//CFruitShop(10, 100) 생성 후 객체에 printValue 출력
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
	//printf로 "sum=%d\n"로 sum 함수 결과 출력
	iResult = sum(4, 3);
	printf("sum=%d\n", iResult);
	//printf로 "minus=%d\n"로 minus 함수 결과 출력
    iResult = Minus(4, 3);
	printf("minus=%d\n", iResult);
	//printf로 "multi=%d\n"로 multi 함수 결과 출력
	iResult = Multi(4, 3);
	printf("Multi=%d\n", iResult);
	//printf로 "Divid=%d\n"로 Divid 함수 결과 출력
	fResult = Divid(4, 2);
	printf("Divid=%f\n", fResult);
	int aa; 
	Average(aa, 1, 2, 3);
	printf("Average=%d\n", aa);
	
	int arr[5] = {1, 3, 5, 7, 9};
	rResult = ArraySum(arr, 5);
	printf("ArraySum=%d\n", rResult);


}