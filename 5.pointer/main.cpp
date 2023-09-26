#include<stdio.h>
#include<iostream>

void BuyItem(int* Money, int price)
{
	//int*Money는 메모리 복제가 일어나지 않는다.
	//메모리의 효율적인 관리, 데이터 참조가 편리하다.
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
		pPs->iPhoneCnt--;//포인트로 참조하는 구조체에 변수는 "->"키워드로 참조한다.
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

//void SelectionSort(int*ap_buf)
//{
//	int min, index, temp;
//
//	for (int i = 0; i < 10; i++)
//	{
//		min = ap_buf[i];
//		
//		for (int j = i + 1; j < 10; j++)
//		{
//			if (ap_buf[j] < min)
//			{
//				min = ap_buf[j];
//				index = j;
//			}
//		}
//		temp = ap_buf[i];
//		ap_buf[i] = min;
//		ap_buf[index] = temp;
//	}
//}

int main()
{
	int a = 0; //4Byte
	int b = 0;
	//포인터를 사용하는 이유
	// 메모리에 효율적인 관리, 데이터 참조가 편리하다.
	// int*pA: 포인터 변수의 선언(pA에 들어가있는 주소에 int형의 크기만큼 참조한다.)
	// nullptr : 포인터 변수의 초기화 값(주소값이 비어있음)
	//이전에는 NULL을 사용했는데 Null=0을 의미 그래서 0이랑 의미가 동일해서 문제 발생
	//주소값이 비어있음이라는 명확한 의미를 가진 Nullptr사용
	//포인터의 크기(x32에는 4Byte, x64에는 8Byte)
	int* pA = nullptr;
	pA = &a;//a주소값을 pA에 넣는다.
	// *:레퍼런스를 참조한다. (주소가 가르키고 있는 값을 참조함.)
	b = *pA;//b에 pA가 가르키고 있는 주소레 값을 넣는다.
	*pA = 10; //pA가 가르키고 있는 주소에 값을 10으로 변경한다.

	int num1 = 0;
	int num2 = 0;
	int* pNum = nullptr;
	pNum = &num1; //pNum에 num1의 주소값을 넣는다.(pNum은 num1을 가르키고 있는 상태)
	printf("pNum=%d\n", *pNum); //num1값 0
	*pNum = 20;   //pNum이 가르키고 있는 num1에 20을 넣는다.
	printf("pNum=%d\n", *pNum); //num1값 20
	pNum = &num2; //pNum에 num2의 주소값을 넣는다.(pNum은 num2을 가르키고 있는 상태)
	printf("pNum=%d\n", *pNum); //num2값 0
	*pNum = 30;	  //pNum이 가르키고 있는 num2에 30을 넣는다.
	printf("pNum=%d\n", *pNum); //num2값 30
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
	//배열과 포인터

	int arrint[10] = { 0,10,20,30,40,50,60,70,80,90 };
	int* pint = nullptr;
	pint = arrint;
	printf("pint=%d\n", *pint);
	pint += 1;
	printf("pint=%d\n", *pint);

	short arrS[10] = { 0,10,20,30,40,50,60,70,80,90 };
	pint = (int*)arrS; //(int*)를 사용해서 int*로 강제 형변환(Cast)한다.
	pint += 1; //pint가 int*이므로 int(4Byte)만큼 다음 주소값을 참조한다.
	short* pS = (short*)pint;//int(4BYte)만큼 이동한 주소값은 Short(2Byte) 2번 이동한 값 >>>내 디코서버 참조
	printf("pS=%d\n", *pS);

	//x32 아키텍쳐 = x86 아키텍쳐
	//int32(4Byte) = 0~ 4,294,967,295(Byte) >>4G이상을 참조하지 못하는 에러 발생

	//아래 배열을 낮은 숫자 순서대로 출력
	int arr[10] = { 10,2,78,53,6,33,27,99,7,31 };


	printf("정렬 전:");
	for (int i = 0; i < 10; i++)
	{
		if (i > 0) printf(",");
		printf("%d", arr[i]);
	}
	printf("\n");
	
	for (int i = 0; i < 10; i++)
	{
		int lowestindex = i;//가장 낮은 index저장

		for (int j = i + 1; j < 10; j++)
		{
			if (arr[lowestindex] > arr[j])
			{
				// lowestindex와 j를 순서대로 비교
				// j index에 값이 낮으면 j는 새로운  lowestindex
				lowestindex = j;
			}
		}
		//j for문이 종료되면 lowestindex에는 가장 낮은 수의 index 값이 저장
		//i 는 순차적으로 돌면서 가장 낮은 수가 들어가야됨
		// lowestindex 값과 i index에 값을 교체한다.
		int temp = arr[i];
		arr[i] = arr[lowestindex];
		arr[lowestindex] = temp;
	}

	printf("정렬 후:");
	for (int i = 0; i < 10; i++)
	{
		if (i > 0) printf(",");
		printf("%d", arr[i]);
	}
	printf("\n");

	return 0; 

}
