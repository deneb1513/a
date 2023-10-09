#include<stdio.h>
#include<iostream>
#include<string>
unsigned int GetStringLength(const wchar_t* _pString)
{
	int i = 0;

	while (1)
	{
		wchar_t c = *(_pString + i);//순차적인 주소값에 문자를 저장
		//if(c==0)
		if (c == '\0')
		{
			break;
		}
		++i;
	}
	return i;
}
using namespace std;

int main()
{
	_wsetlocale(LC_ALL, L"Korean");

	//2의 배수 출력하기(0~100)

	//int num = 100;
	/*for (int a = 0; a <= num; a+=2)
	{
		printf("%d\n", a);
	}*/

	//n은 숫자 하나를 입력 받기
	//n에 배수 출력하기

	/*int a, b, c;
	printf("원하는 배수를 입력해주세요");
	scanf_s("%d", &a);
	printf("몇번반복할것인지");
	scanf_s("%d", &b);
	for (c=1; c<b+1; c++)
	{
		printf("%d\n", c*a);
	}*/

	//(0~100) 2의 배수에 개수 출력
	//int sum2 = 0;// int형 sum2변수라고 생성하고 초기값을 0으로 설정한다.
	//sum2 = 1;// sum2에 1을 대입한다.
	//sum2 = sum2+1;// sum2에 1을 더한값을 대입한다.

	/*for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
		{
			sum2 += 1;
		}
	}
	printf("2의 배수의 개수의 합은 %d입니다.\n", sum2);*/

	//abcdef를 역으로 출력하기 ->fedcba
	//wchar_t szWChar[20] = L"abcdef";

	//int a = wcslen(szWChar);
	//for (int b = 0; b < a; b++)
	//{
	//	wprintf(L"역순 출력%c\n", szWChar[a-1-b]);
	//}
	//강사님 풀이
	//int size = wcslen(szWChar);
	///*printf("size=%d\n", size);
	//printf("%c", szWChar[size - 1]);
	//printf("%c", szWChar[size - 2]);
	//printf("%c", szWChar[size - 3]);
	//printf("%c", szWChar[size - 4]);
	//printf("%c", szWChar[size - 5]);
	//printf("%c", szWChar[size - 6]);*/
 //   //위를 for문으로 작성
	//for (int i = 1; i <= size; ++i)
	//{
	//	printf("%c", szWChar[size - i]);
	//}




	//wchar_t형으로 문자 입력 받기
	//"szWCharInput"이름을 가진 wchar_t변수형을 생성하고
	// [20]의 크기로 생성하고 L""값을 초기값으로 넣는다. 
	wchar_t szWCharInput[20] = L"";
	//wscanf_s는 입력을 받는 기능을 사용하겠다.
	//L"%Is" 변수형태로 입력을 받겠다.
	//"szWCharInput"변수에 입력한 값을 넣어주겠다.
	//"(unsigned)_countof(szWCharInput)"는 값을 넣을 변수의 크기
	wscanf_s(L"%Is", szWCharInput, (unsigned)_countof(szWCharInput));
	//wprintf는 출력을 하는 기능을 사용하겠다.
	//L"szWCharInput=%s"문자 형태로 출력하겠다.
	//%s 위치에 szWCharInput값을 출력하겠다.
	wprintf(L"szWCharInput=%s", szWCharInput);



	//입력 받은 문자열에서 'a'문자 갯수 출력
	/*int size = wcslen(szWCharInput);
	int cnt = 0;
	for (int i = 0; i < size; ++i)
	{
		if (szWCharInput[i]=='a')
		{
			cnt++;
		}
	}
	printf("cnt=%d\n", cnt);*/

	int size = wcslen(szWCharInput);
	int cnt = 0;
	for (int i = 0; i < size; ++i)
	{
		if (szWCharInput[i] == 'a')
		{
			cnt++;
		}
	}
	printf("cnt=%d\n", cnt);








}

