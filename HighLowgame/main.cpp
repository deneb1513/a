#include <stdio.h>
#include <vector>
#include <string>
#include "Card.h"
#include<random>

/*
1. 52개의 카드으로 게임을 합니다.
2. 52개의 카드를 무작위로 섞습니다.
3. 게임이 시작되면 카드 하나를 오픈 합니다.
4. 플레이어는 다음카드가 오픈된 카드보다 높은 카드인지 낮은 카드인지에 대해 배팅을 합니다.
5. 다음 카드를 오픈하고 높은지 낮은지에 대한 선택이 맞으면 승리 틀리면 패배
6. 카드를 1이 가장 낮고 K가 가장 높습니다. 같은 숫자라면 높은 문양의 카드가 승리
7. 문양은 스페이드 > 다이아 > 하트 > 클로버 순으로 높습니다.
*/

void Shuffle(std::vector<CCard>& Cards)
{
	std::random_device rd;//난수생성기
	// 1234은 시드(seed)값이라고 해서 초기에 주어지는 키값
	// 같은 시드면은 랜덤 숫자가 정하게 나온다.
	// std::mt19937 mt(1234); 
	std::mt19937 mt(rd.entropy());// 시드 값도 랜덤으로 부여해서 거의 같은 결과가 나오지 않는다.
	//난수값을 생성해준다.
	std::uniform_int_distribution<int> dist(0, Cards.size() - 1);//0부터 카드사이즈-1까지의 길이가 나오는 변수를 만들었음. 랜덤값이 나오는 범위를 지정


	for (int i = 0; i < 100; i++)//int i=0, i<100보다 작을때까지만 반복, i값 증가. 100회 실시
	{
		int firstIndex = dist(mt);//dist(mt)에 무작위 변수가 들어간다. 이 각각의 값을 각각의 inidex에 대입한다.
		int secondIndex = dist(mt);

		CCard temp = Cards[firstIndex];//CCard에 temp라는 공간을 만들어서 Cards[firstIndex]값을 대입해준다.
		Cards[firstIndex] = Cards[secondIndex];//firstIndex공간에 secondIndex의 값을 대입하는것으로 값을 덮어쓴다.
		Cards[secondIndex] = temp;//secondIndex값에 temp값을 대입하여 덮어써준다.
	}
}//Shuffle을 실행하면 결과적으로 int firstIndex와 int secondIndex에 저장된 값이 temp를 거쳐 서로 교환된다.

bool CompareCard(const CCard& CardA, const CCard& CardB)//카드 비교 함수
{
	
	/*if ((int)CardA.m_number == (int)CardB.m_number)
	{
		if ((int)CardA.m_mark > (int)CardB.m_mark)
		{
			printf("승리");
		}
		else
		{
			printf("패배");
			false;
		}
	}
	else if ((int)CardA.m_number > (int)CardB.m_number)
	{
		printf("승리");
	}
	else if ((int)CardA.m_number < (int)CardB.m_number)
	{
		printf("패배");
	}*/
	int ScoreA = CardA.m_number * 10 + CardA.m_mark;//scoreA에 카드숫자값과 마크값을 더한 값을 대입해준다. 
	int ScoreB = CardB.m_number * 10 + CardB.m_mark;//scoreB도 같은 방식

	return ScoreA > ScoreB;// ScoreA가 ScoreB보다 크다 라는 값을 반환해준다.
}

int main()
{
	std::vector<CCard> Cards;

	for (int i = CardMark::Clover; i < CardMark::MaxMark; ++i)
	{
		//1,2,3,4,5,6,7,8,9,10,J(11),Q(12),K(13)
		for (int j = 1; j <= 13; ++j)
		{
			CCard card;
			card.m_mark = (CardMark)i;
			card.m_number = j;
			Cards.push_back(card);
		}
	}

	Shuffle(Cards);
	
	bool bRun = true; //bRun에  true값을 대입해준다.
	int i = 0; //int 자료형 i라는 변수의 값이 0이라고 설정 해준다.

	while (bRun)//bRun이 들어가 있으므로 참. 작동한다.
	{
		printf("첫번째 카드는 %s 입니다\n", Cards[i].GetCardStr().c_str());
		
		int input = 0;//input = 1 이면 Cards[0] 높다.
		printf("두번째 카드가 높으면 0, 낮으면 1을 입력해주세요 : ");
		scanf_s("%d", &input);
		system("cls");//전에 출력된걸 지워주는 역할

		printf("첫번째 카드는 %s 입니다.\n", Cards[i].GetCardStr().c_str());//배열 0번부터 순서대로 뽑는다.
		printf("두번째 카드는 %s 입니다.\n", Cards[i + 1].GetCardStr().c_str());//i+1을 해주어서 다음순서의 카드를 뽑도록 해준다.
		// IsFirstHigh = 1 이면 Cards[0] 높다.
		bool IsFirstHigh = CompareCard(Cards[i], Cards[i + 1]);//카드 비교 함수에 카드 정보가 들어간다.

		if (IsFirstHigh == input)//IsFirstHigh과 input값이 같을때 작동
		{
			printf("맞췄다.\n");//정답일시 출력
		}
		else//IsFirstHigh과 input값이 다를때 작동
		{
			printf("틀렸다.\n");//오답일시 출력
		} 

		i += 2;//다음 게임을 진행하기 위해 i값에 +2를 해서 다음 순서의 카드가 오게 한다.
	}

	/*for (CCard& card : Cards)
	{
		card.printCard();
	}*/
}