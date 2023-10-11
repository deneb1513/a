#include <stdio.h>
#include <vector>
#include <string>
#include "Card.h"
#include<random>

/*
1. 52���� ī������ ������ �մϴ�.
2. 52���� ī�带 �������� �����ϴ�.
3. ������ ���۵Ǹ� ī�� �ϳ��� ���� �մϴ�.
4. �÷��̾�� ����ī�尡 ���µ� ī�庸�� ���� ī������ ���� ī�������� ���� ������ �մϴ�.
5. ���� ī�带 �����ϰ� ������ �������� ���� ������ ������ �¸� Ʋ���� �й�
6. ī�带 1�� ���� ���� K�� ���� �����ϴ�. ���� ���ڶ�� ���� ������ ī�尡 �¸�
7. ������ �����̵� > ���̾� > ��Ʈ > Ŭ�ι� ������ �����ϴ�.
*/

void Shuffle(std::vector<CCard>& Cards)
{
	std::random_device rd;//����������
	// 1234�� �õ�(seed)���̶�� �ؼ� �ʱ⿡ �־����� Ű��
	// ���� �õ���� ���� ���ڰ� ���ϰ� ���´�.
	// std::mt19937 mt(1234); 
	std::mt19937 mt(rd.entropy());// �õ� ���� �������� �ο��ؼ� ���� ���� ����� ������ �ʴ´�.
	//�������� �������ش�.
	std::uniform_int_distribution<int> dist(0, Cards.size() - 1);//0���� ī�������-1������ ���̰� ������ ������ �������. �������� ������ ������ ����


	for (int i = 0; i < 100; i++)//int i=0, i<100���� ������������ �ݺ�, i�� ����. 100ȸ �ǽ�
	{
		int firstIndex = dist(mt);//dist(mt)�� ������ ������ ����. �� ������ ���� ������ inidex�� �����Ѵ�.
		int secondIndex = dist(mt);

		CCard temp = Cards[firstIndex];//CCard�� temp��� ������ ���� Cards[firstIndex]���� �������ش�.
		Cards[firstIndex] = Cards[secondIndex];//firstIndex������ secondIndex�� ���� �����ϴ°����� ���� �����.
		Cards[secondIndex] = temp;//secondIndex���� temp���� �����Ͽ� ������ش�.
	}
}//Shuffle�� �����ϸ� ��������� int firstIndex�� int secondIndex�� ����� ���� temp�� ���� ���� ��ȯ�ȴ�.

bool CompareCard(const CCard& CardA, const CCard& CardB)//ī�� �� �Լ�
{
	
	/*if ((int)CardA.m_number == (int)CardB.m_number)
	{
		if ((int)CardA.m_mark > (int)CardB.m_mark)
		{
			printf("�¸�");
		}
		else
		{
			printf("�й�");
			false;
		}
	}
	else if ((int)CardA.m_number > (int)CardB.m_number)
	{
		printf("�¸�");
	}
	else if ((int)CardA.m_number < (int)CardB.m_number)
	{
		printf("�й�");
	}*/
	int ScoreA = CardA.m_number * 10 + CardA.m_mark;//scoreA�� ī����ڰ��� ��ũ���� ���� ���� �������ش�. 
	int ScoreB = CardB.m_number * 10 + CardB.m_mark;//scoreB�� ���� ���

	return ScoreA > ScoreB;// ScoreA�� ScoreB���� ũ�� ��� ���� ��ȯ���ش�.
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
	
	bool bRun = true; //bRun��  true���� �������ش�.
	int i = 0; //int �ڷ��� i��� ������ ���� 0�̶�� ���� ���ش�.

	while (bRun)//bRun�� �� �����Ƿ� ��. �۵��Ѵ�.
	{
		printf("ù��° ī��� %s �Դϴ�\n", Cards[i].GetCardStr().c_str());
		
		int input = 0;//input = 1 �̸� Cards[0] ����.
		printf("�ι�° ī�尡 ������ 0, ������ 1�� �Է����ּ��� : ");
		scanf_s("%d", &input);
		system("cls");//���� ��µȰ� �����ִ� ����

		printf("ù��° ī��� %s �Դϴ�.\n", Cards[i].GetCardStr().c_str());//�迭 0������ ������� �̴´�.
		printf("�ι�° ī��� %s �Դϴ�.\n", Cards[i + 1].GetCardStr().c_str());//i+1�� ���־ ���������� ī�带 �̵��� ���ش�.
		// IsFirstHigh = 1 �̸� Cards[0] ����.
		bool IsFirstHigh = CompareCard(Cards[i], Cards[i + 1]);//ī�� �� �Լ��� ī�� ������ ����.

		if (IsFirstHigh == input)//IsFirstHigh�� input���� ������ �۵�
		{
			printf("�����.\n");//�����Ͻ� ���
		}
		else//IsFirstHigh�� input���� �ٸ��� �۵�
		{
			printf("Ʋ�ȴ�.\n");//�����Ͻ� ���
		} 

		i += 2;//���� ������ �����ϱ� ���� i���� +2�� �ؼ� ���� ������ ī�尡 ���� �Ѵ�.
	}

	/*for (CCard& card : Cards)
	{
		card.printCard();
	}*/
}