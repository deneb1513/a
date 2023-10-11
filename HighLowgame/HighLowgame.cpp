#include<stdio.h>
#include<vector>
#include<string>
#include"Card.h"

/*
1.52���� ī��� ������ �Ѵ�. ���� ���۽� �������� ����.
2.������ ���۵Ǹ� ī�� �ϳ��� ����
3.�÷��̾�� ���� ī�尡 ���µ� ī�庸�� ���� ī������ ���� ī�������� ���Ͽ� ������ �Ѵ�.
4.���� ī�带 �����ϰ� ������ �������� ���� ������ ������ �¸� Ʋ���� �й�
5.ī��� 1�� ���� ���� k�� ���� ����
6.������ �����̵�>���̾�>��Ʈ>Ŭ�ι� ������ ����
*/

enum CardMark
{
	None = 0,
	Clover,
	Heart,
	Dia,
	Spade,
	MaxMark
};//enum(������)�� �̿��Ͽ� ī�幮���� �����Ѵ�. ī�幮�翡 ���� ������. ���� ������ �����ָ� ���ʴ�� 1�� �����Ѵ�. ���� ���� �������� ���� �ִ�.

class CCard
{
public://�ܺο��� ����� �� �ֵ��� public���� ����
	CCard(CardMark mark = CardMark::None, int number = 0) :m_mark(mark), m_number(number)//�����ڸ� ����� �Ķ��Ÿ�� �������ְ� ������ �ʱⰪ�� �������ش�
	{

	}

	std::string GetMarkStr()//GetMarkStr�̶�� �Լ��� �������ش�.
	{
		switch (m_mark)//switch���� m_mark�� ���ؼ� ���. 
		{
		case Clover:
			return "Clover";//Ŭ�ι��϶� Ŭ�ι����� ��ȯ���ش�.
			break;
		case Heart:
			return "Heart";//��Ʈ�϶� ��Ʈ���� ��ȯ���ش�.
			break;
		case Dia:
			return "Dia";//���̾��϶� ���̾ư��� ��ȯ���ش�.
			break;
		case Spade:
			return "Spade";////�����̵��϶� �����̵尪�� ��ȯ���ش�.
			break;
		}

		return "None";//None������ ��ȯ
	}

	void printCard()//printCard��� �Լ��� ����
	{
		printf("%s[%d]\n", GetMarkStr().c_str(), m_number);
	}//ī���� ����� ���ڸ� ������ش�.

public:
	CardMark m_mark;//��� ���� ����
	int m_number;
};

int main()
{
	std::vector<CCard> Cards;//vector�� ���� ���� �������ش�

	for (int i = CardMark::Clover; i < CardMark::MaxMark; ++i)//i�� clover�� ����, i�� maxmark���� ���������� �ݺ�. i�� ����
	{
		//1,2,3,4,5,6,7,8,9,10,J(11),Q(12),K(13)
		for (int j = 1; j <= 13; ++j)//j�� 1�̰� j�� 13���� �۰ų� ���������� �ݺ�, j�� ����
		{
			CCard card;//CCard�� card��� ������ ����. ī�尪�� ������ �����ϱ� ���ؼ�
			card.m_mark = (CardMark)i;//ī�� ������ i���̰�
			card.m_number = j;//ī���� ���ڴ� j��
			Cards.push_back(card);//cards�� �ڿ� card���� �ٿ��ش�. ����[����]
		}
	}
	//���� for���� ī�忡 ����� ���ڸ� �ο����ִ� ����

	for (CCard& card : Cards)//CCard�� card�� ���۷��� ����
	{
		card.printCard();//ī�尪�� ������ش�.
	}
}