#include<stdio.h>
#include<vector>
#include<string>
#include"Card.h"

/*
1.52개의 카드로 게임을 한다. 게임 시작시 무작위로 섞음.
2.게임이 시작되면 카드 하나를 오픈
3.플레이어는 다음 카드가 오픈된 카드보다 높은 카드인지 낮은 카드인지에 대하여 베팅을 한다.
4.다음 카드를 오픈하고 높은지 낮은지에 대한 선택이 맞으면 승리 틀리면 패배
5.카드는 1이 가장 낮고 k가 가장 높음
6.문양은 스페이드>다이아>하트>클로버 순으로 높음
*/

enum CardMark
{
	None = 0,
	Clover,
	Heart,
	Dia,
	Spade,
	MaxMark
};//enum(열거형)을 이용하여 카드문양을 열거한다. 카드문양에 값을 정의함. 따로 설정을 안해주면 차례대로 1씩 증가한다. 따로 값을 설정해줄 수도 있다.

class CCard
{
public://외부에서 사용할 수 있도록 public으로 설정
	CCard(CardMark mark = CardMark::None, int number = 0) :m_mark(mark), m_number(number)//생성자를 만들고 파라메타를 설정해주고 각각의 초기값을 설정해준다
	{

	}

	std::string GetMarkStr()//GetMarkStr이라는 함수를 정의해준다.
	{
		switch (m_mark)//switch문을 m_mark에 대해서 사용. 
		{
		case Clover:
			return "Clover";//클로버일때 클로버값을 반환해준다.
			break;
		case Heart:
			return "Heart";//하트일때 하트값을 반환해준다.
			break;
		case Dia:
			return "Dia";//다이아일때 다이아값을 반환해준다.
			break;
		case Spade:
			return "Spade";////스페이드일때 스페이드값을 반환해준다.
			break;
		}

		return "None";//None값으로 반환
	}

	void printCard()//printCard라는 함수를 정의
	{
		printf("%s[%d]\n", GetMarkStr().c_str(), m_number);
	}//카드의 문양과 숫자를 출력해준다.

public:
	CardMark m_mark;//멤버 변수 설정
	int m_number;
};

int main()
{
	std::vector<CCard> Cards;//vector로 만들어서 값을 저장해준다

	for (int i = CardMark::Clover; i < CardMark::MaxMark; ++i)//i에 clover값 대입, i는 maxmark보다 작을때까지 반복. i값 증가
	{
		//1,2,3,4,5,6,7,8,9,10,J(11),Q(12),K(13)
		for (int j = 1; j <= 13; ++j)//j는 1이고 j는 13보다 작거나 같을때까지 반복, j값 증가
		{
			CCard card;//CCard의 card라는 변수를 설정. 카드값의 정보를 저장하기 위해서
			card.m_mark = (CardMark)i;//카드 문양은 i값이고
			card.m_number = j;//카드의 숫자는 j값
			Cards.push_back(card);//cards의 뒤에 card값을 붙여준다. 문양[숫자]
		}
	}
	//위의 for문은 카드에 문양과 숫자를 부여해주는 역할

	for (CCard& card : Cards)//CCard가 card를 레퍼런스 참조
	{
		card.printCard();//카드값을 출력해준다.
	}
}