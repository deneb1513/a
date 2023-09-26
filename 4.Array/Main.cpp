#include<stdio.h>
#include "money.h"
#include"clacfunc.h"
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

int g_money = 0;//전역변수

static int s_money = 0;

int aResult = 0;
int num1, num2;
float fnum1, fnum2;

//오버로드
int Add(int a, int b) //정수를 적으면 int. Add(1, 1)
{
    return a + b;
}

float Add(float a, float b) // 실수에 f를 붙이면 작동. Add(1.5f, 1.2f)
{
    return a + b;
}

double Add(double a, double b)//실수를 적으면 작동. Add(1.5, 1.2)
{
    return a + b;
}

struct fruitShop
{
    //구조체 내부에 선언한 변수는 구조체가 사라지지 않는 이상 안사라짐.
    int appleA;
    int mangoA;
    int strawberryA;

    //구조체  생성자 ":"이 구문 오른쪽에 변수에 초기값을 세팅한다.
    fruitShop() : appleA(1000), mangoA(1000), strawberryA(1000)
    {

    }

    //구조체에 함수 생성
    void SetFruitValue(int apple, int mango, int strawberry)
    {
        int appleB = apple; //SetFrutvalue 함수가 종료되면 사라짐.
        appleA = apple;
        mangoA = mango;
        strawberryA = strawberry;
    }

    void printShopValue()
    {
        printf("과일가게 가격 사과:%d, 망고:%d, 딸기:%d\n", appleA, mangoA, strawberryA);
    }

};
       // Struct PhoneShop
       // int iPhone;
       // int zFlip;
       // int GalaxyS23;
       // int GalaxyFold;
       // PhoneShop[0], iPhone=100, zFlip=90, GalaxyS23= 80, GalaxyFold=150
       // PhoneShop[1], iPhone = 110, zFlip = 100, GalaxyS23 = 90, GalaxyFold = 160
       // PhoneShop[2], iPhone = 90, zFlip = 80, GalaxyS23 = 70, GalaxyFold = 140
       // PhoneShop[0], PhoneShop[1],  PhoneShop[2]에 가격을 출력

struct PhoneShop
{    
    int index;
    int iPhoneA;
    int zFlipA;
    int GalaxyS23A;
    int GalaxyFoldA;

    PhoneShop():index(0), iPhoneA(100), zFlipA(90), GalaxyS23A(80), GalaxyFoldA(150)
    {}

    void SetPhoneValue(int iPhone, int zFlip, int GalaxyS23, int GalaxyFold)
    {
        iPhoneA = iPhone;
        zFlipA = zFlip;
        GalaxyS23A = GalaxyS23;
        GalaxyFoldA = GalaxyFold;
    }

    void printPhoneValue()
    {
        printf("%d 대리점 핸드폰가격 iPhoneA:%d, zFlipA:%d, GalaxyS23A:%d, GalaxyFoldA:%d\n", index, iPhoneA, zFlipA, GalaxyS23A, GalaxyFoldA);
    }


};


int main()
{
	//int t_money = 0;//지역변수
	//addmoney(100);
	//addmoney(100);
	//addmoney(100);
	//addmoney(100);
	//addmoney(100);

 //   printf("main t_money=%d\n", t_money);
 //   printf("main g_money=%d\n", g_money);
 // 
 //   bool bRun = true;
 //   while (bRun)
 //   {
 //       int nlnput = 0;
 //       int num1, num2;

 //       printf("어떤 연산을 하시겠습니까?(0:더하기, 1: 빼기, 2:곱하기, 3:나누기, 4:나머지)");
 //       scanf_s("%d", &aResult);

 //       switch (aResult)
 //       {
 //       case 0:
 //       {
 //           printf("숫자 2개를 입력하시오(num1 num2):");
 //           scanf_s("%d %d", &num1, &num2);
 //           printf("두 수의 합은 %d입니다.\n", AddNum(num1, num2));
 //       }
 //       break;

 //       case 1:
 //       {
 //           printf("숫자 2개를 입력하시오(num1 num2):");
 //           scanf_s("%d %d", &num1, &num2);
 //           printf("두 수의 뺄셈은 %d입니다.\n", MinusNum(num1, num2));
 //       }
 //       break;

 //       case 2:
 //       {
 //           printf("숫자 2개를 입력하시오(num1 num2):");
 //           scanf_s("%d %d", &num1, &num2);
 //           printf("두 수의 곱셈은 %d입니다.\n", MultiplyNum(num1, num2));
 //       }
 //       break;

 //       case 3:
 //       {
 //           printf("숫자 2개를 입력하시오(num1 num2):");
 //           scanf_s("%f %f", &fnum1, &fnum2);
 //           printf("두 수의 나눗셈은 %f입니다.\n", DivideNum(fnum1, fnum2));
 //       }
 //       break;

 //       case 4:
 //       {
 //           printf("숫자 2개를 입력하시오(num1 num2):");
 //           scanf_s("%d %d", &num1, &num2);
 //           printf("두 수의 나머지는 %d입니다.\n", RemainNum(num1, num2));
 //       }
 //       break;

 //       default:
 //           break;
 //       }


 //       printf("계산기를 종료하시겠습니까?(0:No, 1:Yes)");
 //       scanf_s("%d", &nlnput);

 //       switch (nlnput)
 //       {
 //       case 1:
 //           bRun = false;
 //           break;
 //       }
 //   }

    //배열
        /*int arrint[10] = { 0 } 전부 0으로 초기화
        int arrint[10] = { 0, } 전부 0으로 초기화*/
        int arrint[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; //각각에 배열에 초기값 넣는 방법
        arrint[0] = 10; //0번 배열에 값넣기
        arrint[4] = 40; //4번 배열에 값넣기
        arrint[9] = 90; //9번 배열에 값넣기

        for (int i = 0; i < 10; i++)
        {
            printf("%d번째 배열 값은 %d 입니다.\n", i, arrint[i]); //2개 이상의 파라메타 출력 방법
        }

        int number = 0;
        for (int value : arrint)
        {
            printf("for each %d번째 배열 값은 %d입니다.\n", number, value);
            number++;
        }
        //Struct에 사용
        //fruitShop : 변수형
        //shop : 변수의 이름
        fruitShop shop[3];

        //Struct 함수 사용법
        shop[0].SetFruitValue(1000, 2000, 3000);
        shop[1].SetFruitValue(1100, 2100, 3100);
        shop[2].SetFruitValue(900, 1900, 2900);

        for (fruitShop stValue : shop)
        {
            stValue. printShopValue();
        }

        PhoneShop Shop[3];
        Shop[0].index = 0;
        Shop[0].SetPhoneValue(100, 90, 80, 150);
        Shop[1].index = 1;
        Shop[1].SetPhoneValue(110, 100, 90, 160);
        Shop[2].index = 2;
        Shop[2].SetPhoneValue(90, 80, 70, 140);
            
        for (PhoneShop PValue : Shop)
        {
            PValue.printPhoneValue();
        }
            

    return 0;
}
