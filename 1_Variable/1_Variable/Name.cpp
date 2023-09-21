#include<iostream>
#include<stdlib.h>
int main()
{   //컴퓨터는 이진법을 사용 0, 1, 1개를 bit라고 한다.
	//이진법 8개 bit일때는 0~255 256개의 숫자를 표현
	//0000 0000=0
	//0000 0001=1
	//0000 0010=2
	//0000 0011=3
	//0000 0100=4
	//0000 1000=6
	//0000 1111=15
	//1000 0000: 부호 비트로 빠진다.
	
	//0111 1111 = 127
	//0000 0001 = 1
	//1000 0000 = 128(-128)
	//1111 1111 = (-1)
	//0000 0000(1) + 1111 1111(-1) = 0000 0000(0)

	char c;// -128~127 1Byte = 8bit
	unsigned char uc;//0~255
	

	short s;// 2Byte = 16bit
	//int 자료형
	//최초 16bit 아키텍쳐 일때는 16bit
	//32bit 아키텍쳐일때는 32bit
	//64bit 아키텍쳐일대도 32bit
	//int64 일때 64bit
	int A;//숫자, 음수, 양수, 정수(0, 1, 2, 3, 4)
	unsigned int uA;//숫자, 양수, 정수(0, 1, 2, 3, 4)

	char C;
	short S;

	float f;

	f = 2.0f;

		//부동소수점
		//0001 0000 = 1이라면
		//0000 1000 = 0.5
		//0000 0100 = 0.25
		//0000 0010 = 0.125
		//0000 0001 = 0.0625
		//1111 1101 = 0.5 + 0.25 + 0.0625 =0.8125
		//0(부호부) / 000 0000(지수부) / 000 0000 0000 0000(가수부)
		// 21.8215 = 21(10101)/8125(0.1101)
		// 21.8125>10101.1101(21825)>>>0.10101101 * 2^5>>> 5승을 진법으로 바꾸면 (101)명
		// 10101101(218125) >> 0.218125 * 2^5 >> 5승을 2진법으로 바꾸면(101)
		// 0(부호부) / 000 0010 1(지수부) /101 0111 0100 0000 0000 0000(기수부)
		// 명확하게 0.1을 표기하여고 한다면 0000 0001 1011 1001

	double d = 0.1; //8byte float 보다 더 정밀하다

	int i2 = 0;
    float f2 = 1.0f;
	i2 = (int)f2;
	f2 = (float)i2;
	f2 = float(i2);
	f2 = (float)(i2 + 1);
	i2 = int(f2) + 1;


	//연산자
	//+, -, *, /, %, ++, --
	//대입 연산자 (=) 오른쪽값을 왼쪽에 대입
	i2 = 1 + 1;
	i2 = i2 + 1;
	i2 += 1; // 위와 동일한 계산식

	i2 = 1 * 1;
	i2 = i2 * 1;
	i2 *= 1; 
	float divide = 10 / 2.0f; // 10*0.5f;
	//실수끼리 나머지 연산 불가능(몇번째소수점에서 연산해야하는지 알수 없음
	//즉, 둘다 저우일때만 나머지 연산 가능

	int add = 0; // 변수를 선언하면 0을 대입하여 초기화 해준다.
	int minus = 10;
	
	// add++; 후치연산은 대입연산자보다 더 뒤에 실행
	// ++add; 전치연산

	int addR = 0, addL = 0;
	addL = ++add;
	addR = add++;

	//논리연산자
	//&&(and), ||=\\(OR), !(NOT)
	// and는 둘다 참일때 참
	// or는 둘 중 하나라도 참이면 참
	// not 참이면 거짓, 거짓이면 참. 값의 반전
	// yes= 0이 아닌 값. True(1)
	// no= 0일 때. False(0)
    //bool bResult = true;
    //bool bResult = false;
	//bool bResult = 1; 은 true를 넣은 것과 같다.
	bool bResult = 0; //은 false를 넣은 것과 같다.
	bResult = 0 && 20;
	bResult = 0 || 20;
	bResult = !1;
	bResult = !0;

	//자주쓰는 단축키
	// 지정한 구문 주석: ctrl + k, c
	// 지정한 구문 주석 해제: ctrl + k, u
	// 부분 영역 지정: Alt + 드래그 
	// 디버깅 단축키
	// F5 = 디버깅 시작, 계속 진행
	// F9 = 중단점 생성 및 해제
	// F10 = 디버깅 중 다음 구문 진행
	// F11 = 디버깅 중 함수 내부 구문 진행
	// shift + F5 = 디버깅 종료

	//비교 연산자 
	//== : 같으면 t, 아니면 f
	//!=: 같으면 f, 아니면 t
	//>: 왼쪽이 오른쪽보다 크면 t, 아니면 f
	//>=: 왼쪽이 오른쪽보다 크거나 같으면 t, 아니면 f
	//<: 왼쪽이 오른쪽보다 작으면 t, 아니면 f
	//<=: 왼쪽이 오른쪽보다 작거나 같으면 t, 아니면 f
	bResult = (10 == 11);
	bResult = (10 != 11);
	bResult = (10 > 11);
	bResult = (10 < 11);

	int nResult = (10 == 11) ? 100 : 50;

	//문제 아래 time 들어있는 초 값에 분과 시간을 구하여라

	unsigned int total_sec = 987654321; //초

	unsigned int day = 0, hour = 0, min = 0, sec=0;
	/*day = 11431;
	* 나머지 =15921
	hour =4;
	나머지 = 1521
	min = 25;
	sec = 21;*/
	
	 day = total_sec/86400;
	 hour = (total_sec % 86400)/3600;
	 min = ((total_sec % 86400)%3600)/60;
	 sec = ((total_sec % 86400) % 3600) % 60;
   
	
	 printf("%d, %d, %d, %d", day, hour, min, sec);
	system("pause");

}