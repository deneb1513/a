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
	printf("���� ���� 3�� �Է¿Ϸ�.\n");

	while (true)
	{
		printf("%d �� ° �õ�!\n���� ���� Ƚ��:%d\n", ++attempCount, MAX_ATTEMP_COUNT - attempCount);
		SetInputPlayerNumber(playerBaseballNumber);
		bool result = CheckAnswer(randomBaseballNumber, playerBaseballNumber);

		if (result)
		{
			printf("�¸�!\n");
			break;
		}
		if (OutCount == 3)
		{
			printf("3OUT! �й�...\n");
			break;
		}
		if (attempCount == MAX_ATTEMP_COUNT)
		{
			printf("�õ� Ƚ�� �ʰ� �й�... \n");
			break;
		}
	}
	printf("���� ��� : ");
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
	arr[inputArrCount++] = rand() % 9 + 1;	// ���� ��
	while (true)
	{
		isOverlap = false;
		randomNum = rand() % 9 + 1;	// ���� ��
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
	printf("3���� ���ڸ� �ߺ� ���� �Է��Ͽ� �ּ���.\n");

	while (true)
	{
		isOverlap = false;
		printf("%d�� ° ���� �Է� : ", inputCount);
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
			printf("������ �Է��� ���� �ߺ��� �����Դϴ�. \n");
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

	printf("�Է��Ͻ� 3���� ���ڴ� %d��Ʈ����ũ %d�� �Դϴ�. \n", strikeCount, ballCount);
	if (strikeCount == 0 && ballCount == 0)
	{
		OutCount++;
		printf("OUT !! \n���� Out Ƚ�� : %d !! \n", OutCount);
	}
	if (strikeCount == 3)
		result = true;
	return result;
}