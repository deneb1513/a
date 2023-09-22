#include <iostream>
#include <stdio.h>
#include <bitset>
#define LEVEL1_REWARD_10 0b00000001; //1
#define LEVEL1_REWARD_20 0b00000010; //2
#define LEVEL1_REWARD_30 0b00000100; //4
#define LEVEL1_REWARD_40 0b00001000; //8
#define LEVEL1_REWARD_50 0b00010000; //16
#define LEVEL1_REWARD_60 0b00100000; //32


//C++의 컴파일
//C++에서 사람이 작성한 소스코드를 컴퓨터가 읽을수 있는 코드로 변환하여 실행할 수 있는 파일로 변환하는 과정
// 1. 전처리(Preprocessing)단계 : #include 와 #define 과 같은 전처리기 매크로들을 처리하는 단계
// 2. 컴파일(Compile) 단계 : 각각의 소스 파일들을 어셈블리 명령어로 변환
// 3. 어셈블(Assemble) 단계 : 어셈블리 코드들을 실제 기계어로 이루어진 목적 코드(Object file)로 변환하는 단계
// 4. 링킹(Linking)단계 : 각각의 목적 코드들을 한데 모아서 하나의 실행 파일을 생성하는 단계

// 메모리 영역
// code 영역 : 실행할 코드가 저장되어있는 영역(기계어로 존재)
// Data 영역 : 전역변수, Static 변수들이 저장, 프로세스가 종료될때 까지 메모리에 저장됨
// Stack 영역: 지역변수, 매개변수들이 저장, 함수가 호출되면 생성되고 함수가 종료되면 시스템에 반환
// Heap 영역 : malloc 또는 new 함수에 의해서 동적으로 할당되는 영역, malloc()또는 new연산자로 할당, free() 또는 delete 연산자로 해제

int main()
 {
	 //비트 연산자
	 //C++ 11버전 부터 숫자 앞에 0b를 붙이면 2진법 표기 가능
	 //2진법 표기 : 앞에 0b를 붙인다(0b01011101)
	 //8진법 표기 : 앞에 0을 붙인다(0123)
	 //16진법 표기 : 앞에 0x를 붙인다(0xFF) (A:10, B:11, C:12, D:13, E:14, F:15)
	 int A = 0b01011101;
	 int B = 0123;
	 int C = 0xFF;
	 printf("2진법(0b01011101 : %d\n", A);
	 printf("8진법(0123) : %d\n", B);
	 printf("16진법(0xFF : %d\n", C);

	 //비트 연산 기호
	 //곱(&) : 둘 다 1이면 1, 아니면 0
	 //합(|) : 둘 중에 하나라도 1이면 1, 아니면 0
	 //XOR(^) : 둘이 같으면 0, 아니면 1
	 //반전(~) : 0이면 1, 1이면 0

	 char bitNum = 0b01001010;
	 char bitResult = 0;
	 bitResult = bitNum & 0b11010100;
	 std::cout << std::bitset<8>(bitResult) << std::endl;//std::endㅣ은 개행(printf에 \n과 같다.
	 //답 01000000

	 bitResult = bitNum | 0b11010100;
	 std::cout << std::bitset<8>(bitResult) << std::endl;
	 //답11011110

	 bitResult = bitNum ^ 0b11010100;
	 std::cout << std::bitset<8>(bitResult) << std::endl;
	 //답10011110

	 bitResult = ~0b11010100;
	 std::cout << std::bitset<8>(bitResult) << std::endl;
	 //답 00101011

	 //10레벨 달성 보상 
	 bool isGetLevel10Reward = false;

	 //20레벨 달성 보상
	 bool isGetLevel20Reward = false;

	 //30레벨 달성 보상
	 bool isGetLevel30Reward = false;

	 //40레벨 달성 보상
	 bool isGetLevel40Reward = false;

	 //50레벨 달성 보상
	 bool isGetLevel50Reward = false;

	 //60레벨 달성 보상
	 bool isGetLevel60Reward = false;
	 
	 //비트 1로 설정 
	 char MyReward = 0b00000000;
	 MyReward = MyReward | LEVEL1_REWARD_10; //LEVEL1_REWARD_10;
	 //0b01011000
	 //0b00000001
	 //0b01011001

	 std::cout << "MYReward Enable=" << std::bitset<8>(MyReward) << std::endl;

	 //비트 활성화 되어있는지 체크
	 bool isEnable = false;
	 //0b01011001
	 //0b00000001
	 //0b00000001
	 isEnable = MyReward & LEVEL1_REWARD_10;
	 std::cout << "MYReward Check=" << isEnable << std::endl;

	 //비트 0으로 설정
	 MyReward = MyReward & ~LEVEL1_REWARD_10;
	 //0b10110011
	 //0b11111101
	 //0b10110001
	 std::cout << "MYReward Set = " << std::bitset<8>(MyReward) << std::endl;



	 return 0;
 }