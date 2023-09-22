

#include <iostream>
#include <stdio.h>

int main()
{

 {
	{
		// cin 입력, cout 출력
		//int a = 0;
		//std::cin >> a;
		//std::cout << a << "를 입력하셨습니다.";
	}

	{   //%d: 부호 있는 10진수 정수
		// %|64d : 부호 있는 10진수 정수(8byte)
		// %u : 부호 없는 10진수 정수
		// $|64u : 부호 없는 10진수 정수 (8byte)
		// %f : 부호 있는 실수 (12.3456789)
		// %e, %E : 부호 있는 실수 (1.23456789e + 001)
		// %i : 부호 있는 10진수 정수 (10진수 / 8진수 / 16진수 입력가능)
		// %x : 부호 없는 16진수 정수 (0123456879abcdef)
		// %X : 부호 없는 16진수 정수 (0123456879ABCDEF)
		// %o : 부호 없는 8진수
		// %p : 포인터 값을 16진수로 표기
		// %c : 단일 문자 출력
		// 
		/*int a = 0, b = 0;
		scanf_s("%d %d", &a, &b);
		printf("a 더하기 b는? %d", a+b);*/

		//ctrl + space bar 자동완성(인텔리센스) 다시 키기

		/*bool bReulst = false;
		if (true)
		{
			printf("참이다.");
		}
		else
		{
			printf("거짓이다.");
		}*/

		/*	int Score = 0;
			printf("Score를 입력해주세요 : ");
			scanf_s("%d", &Score);

			printf("Score = %d", Score);

			if (Score >= 90)
			{
				printf("A학점");
			}
			else if (Score >= 80)
			{
				printf("B학점");
			}
			else if (Score >= 70)
			{
				printf("C학점");
			}
			else if (Score >= 60)
			{
				printf("D학점");
			}
			else if (Score >= 50)
			{
				printf("E학점");
			}
			else
			{
				printf("F학점");
			}

		}*/
		//	int backnumber = 0;
		//	scanf_s("%d", &backnumber);

		//	switch (backnumber) //에러처리 할때 제일 많이 사용 
		//	{
		//	case 10:
		//	case 11:
		//	{
		//		//11 일때 실행
		//		printf("포수");
		//	}
		//	break;

		//	case 9:
		//	{
		//		printf("투수");
		//	}
		//	break;

		//	default:
		//	{
		//		//위에 case가 모두 아닐때 실행
		//		printf("후보");
		//	}

		//	break;
		//	}
		//}
		//int light = 0;
		//{   //scanf_s light 값을 입력
		//	// light가 true면 "파랑" 출력
		//    // light가 false면 "빨강" 출력
		//	scanf_s("%d", &light);
		//	if (light (== true 제외해도 작동함 light에 값이 들어가면 true로 처리하기 때문))
		//	{
		//		printf("파랑");
		//	}
		//	else
		//	{
		//		printf("빨강");
		//	}
		//	
		//}

		// ninput 값이 100보다 크면 "100보다 크다" 출력(printf)
		// ninput 값이 100보다 작으면 "100보다 작다" 출력(printf)
		/*int nlnput = 0;
		{
			scanf_s("%d", &nlnput);

			if (nlnput >= 100)
			{
				printf("100보다 크다");
			}
			else
			{
				printf("100보다 작다");
			}
		}*/



		// scanf_s로 myScore, otherScore 값으 입력
		//myScore가 otherScore 크면 "3점" 출력(printf);
		//myScore가 otherScore 같으면 "1점" 출력(printf);
		//myScore가 otherScore 작으면 0점" 출력(printf);
		/*int  myScore = 0, otherScore = 0;
		{scanf_s("%d %d", &myScore, &otherScore);
		if (myScore > otherScore)
		{
			printf("3점");
		}
		else if (myScore == otherScore)
		{
			printf("1점");
		}
		else 
		{
			printf("0점");
		}*/
		
		// scanf_s로 nCode 값을 입력
		// nCode 가1이나 3이면 "남자" 출력(printf)
		// nCode 가2이나 4이면 "du자" 출력(printf)
		/*int nCode = 0;
		{scanf_s("%d", &nCode);
		switch (nCode)
		{   case 1:
			case 2:
			{
				printf("남자"); 
			}
			break;

			case 3:
			case 4: 
			{
				printf("여자");
			}
			break;

		}*/
		
		// scanf_s로 nCode2 값을 입력
		// nCode가 1이나 2이면 "2000년 미만 출생" 출력(printf)
		//nCode가 3이나 4이면 "2000년 이후 출생" 출력(printf)
		int nCode2 = 0;
		{
			scanf_s("%d", &nCode2);
		}
		 switch(nCode2)
		 {
		     case 1:
		     case 2:
			 {
				 printf("2000년 미만 출생");
			 }
			 break;

			 case 3:
			 case 4:
			 {
				 printf("2000년 이후 출생");
			 }
			 break;
		 }
		 

		}
	}
	
	return 0;
}