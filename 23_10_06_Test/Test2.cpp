#include<stdio.h>
#include<iostream>

int main()
{
	int nInput = 0;
	int value = 0;
	int per = 0;
	printf("소득세를 계산하시겠습니까? 0)No 1)Yes");
	scanf_s("%d", &nInput);
	bool bRun = true;
	while (bRun)
	{
		switch (nInput)
		{
		 case 0:
		 {bRun = false; }
		 break;

		 case 1:
		 {
			 printf("연간 총 소득을 입력하세요(만단위)\n");
			 scanf_s("%d", &value);
			 if (100000 < value)
			 {
				 per = 45;
			 }
			 else if (100000 >= value && value > 50000)
			 {
				 per = 42;
			 }
			 else if (50000 >= value && value > 30000)
			 {
				 per = 40;
			 }
			 else if (30000 >= value && value > 15000)
			 {
				 per = 38;
			 }
			 else if (15000 >= value && value > 8800)
			 {
				 per = 35;
			 }
			 else if (8800 >= value && value > 4600)
			 {
				 per = 24;
			 }
			 else if (4600 >= value && value > 1200)
			 {
				 per = 15;
			 }
			 else if (1200 >= value)
			 {
				 per = 6;
			 }
			 printf("당신의 소득세는 %d퍼센트 입니다.\n", per);
		 }
		 break;

		 default:
			 break;
		}
		printf("계산기를 종료하시겠습니까?(0:Yes, 1:no)\n");
		scanf_s("%d", &nInput);

		
	}
	return 0;
}
