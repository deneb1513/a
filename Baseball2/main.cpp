#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void GetRandomNumber(int arr[]);
void SetInputPlayerNumber(int arr[]);
bool CheckAnswer(int rndNumber[], int playerNumber[]);

int OutCount = 0;

int main()
{
	int randomBaseballNumber[3] = {};
	int playerBaseballNumber[3] = {};
	const int MAX_ATTEMP_COUNT = 10;
	int attempCount = 0;

	srand(unsigned int(time(0)));
	GetRandomNumber(randomBaseballNumber);
	printf("랜덤 숫자 3개 입력완료.\n");

	while (true)
	{
		printf("%d 번 째 시도!\n남은 도전 횟수:%d\n", ++attempCount, MAX_ATTEMP_COUNT - attempCount);
		SetInputPlayerNumber(playerBaseballNumber);
		bool result = CheckAnswer(randomBaseballNumber, playerBaseballNumber);

		if (result)
		{
			printf("승리!\n");
			break;
		}
		if (OutCount == 3)
		{
			printf("3OUT! 패배...\n");
			break;
		}
		if (attempCount == MAX_ATTEMP_COUNT)
		{
			printf("시도 횟수 초과 패배... \n");
			break;
		}
	}
	printf("정답 출력 : ");
	for (int i = 0; i < 3; i++) {
		printf("%d, ", randomBaseballNumber[i]);
	}

	return 0;

}
void GetRandomNumber(int arr[])
{
	int randomNum = 0;
	int inputArrCount = 0;
	bool isOverlap = false;
	arr[inputArrCount++] = rand() % 9 + 1;	// 랜덤 값
	while (true)
	{
		isOverlap = false;
		randomNum = rand() % 9 + 1;	// 랜덤 값
		for (int i = 0; i < inputArrCount; i++)
		{
			if (randomNum == arr[i])
				isOverlap = true;
		}
		if (isOverlap)
			continue;

		arr[inputArrCount++] = randomNum;

		if (inputArrCount == 3) break;
	}
}

void SetInputPlayerNumber(int arr[])
{
	int inputNumber = 0;
	int inputCount = 0;
	bool isOverlap = false;
	printf("3개의 숫자를 중복 없이 입력하여 주세요.\n");

	while (true)
	{
		isOverlap = false;
		printf("%d번 째 숫자 입력 : ", inputCount);
		scanf_s("%d", &inputNumber);
		if (inputCount > 0)
		{
			for (int i = 0; i < inputCount; i++)
			{
				if (arr[i] == inputNumber)
					isOverlap = true;
			}
		}
		if (isOverlap)
		{
			printf("이전에 입력한 값과 중복된 숫자입니다. \n");
			continue;
		}

		arr[inputCount++] = inputNumber;

		if (inputCount == 3)
			break;
	}
}

bool CheckAnswer(int rndNumber[], int playerNumber[])
{
	bool result = false;
	int strikeCount = 0;
	int ballCount = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (playerNumber[i] == rndNumber[j])
			{
				if (i == j)
				{
					strikeCount++;
					break;
				}
				ballCount++;
			}
		}
	}

	printf("입력하신 3개의 숫자는 %d스트라이크 %d볼 입니다. \n", strikeCount, ballCount);
	if (strikeCount == 0 && ballCount == 0)
	{
		OutCount++;
		printf("OUT !! \n현재 Out 횟수 : %d !! \n", OutCount);
	}
	if (strikeCount == 3)
		result = true;
	return result;
}