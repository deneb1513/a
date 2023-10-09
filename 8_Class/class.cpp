#include<stdio.h>
#include"MyClass.h"
struct stMyStruct //������
{
	int a;
};

/*Class(����, �ڷ���)
Class�� ����� ���� Type�̶�� �Ѵ�.
C�� struct�� Ȯ��� ����
C++�� Ŭ������ �� ���� �׼���(����) ������(private, protected, public)�� ����
�׼����� ����Ǵ� ����� ������ �� �Լ��� �ִ� ����� ���� ���� �Ǵ� ������ ������ �����.
�׼��� �����ڸ� ����Ͽ� ������ �� �Լ��� ����°� ĸ��ȭ ��� �Ѵ�.
Class�� �ѱ۷� �����ϸ� ��Ʋ�̶�� ��, ��밡���� ��ü�� �ƴ�
��ü�� �����ϱ� ���� ����� ��Ÿ����.*/

//��ü(object)
//Class�� ����ؼ� �����Ȱ� ��ü�ϰ� �Ѵ�.
//Class�� ������ �������� �����ǰ� �޸𸮿��� ������ ������.

//��ü ���� ���α׷���
//��ü ���� ���α׷����� ��ǻ�� ���α׷��� ��ɾ��� ������� ���� �ð����� ��� ���� ���� ������ ����
//��. "��ü"���� �������� ������ ����� �ϴ� �з�����
//������ ��ü�� �޽����� �ְ�ް�, �����͸� ���������� ó�� �� �� �ִ�.

class CMyclass // ������
{
	/*����������
	private: �ܺο��� ���� �Ұ�
	protected: ��Ӱ����� �� ������ ����, �̿ܿ��� ���� �Ұ�
	public: ��𼭵� ���� ����
	���� ���� �����ڰ� ������ �⺻������ private*/
	int m_b;//Ŭ���� �ȿ� ����� ������ ��� ������� �Ѵ�.(�����ڵ��� ���������� ���������°� ǥ���ϱ� ���� m_�� ���̱⵵ �Ѵ�.)
public: 
	//�����ڴ� �ݵ�� public�� �־�� ��
	/*������: Ŭ������ �����ɶ� ȣ��Ǵ� �Լ�
    ���� ���� �ʾƵ� �⺻ �����ڰ� ����
	�����ڵ� private�� �ܺο� ȣ�� �Ұ�, �ݵ�� public���� ����
	�����ڵ� �Ķ��Ÿ�� ������ Ÿ�Կ� ���� Overload(Ÿ�Ժ� �������� �Լ��� ����)�� �� �ִ�.
	(int valueA=0)�̷� ������� ������ �Ķ��Ÿ�� �־��ټ� �ִ�.
	:a(valueA), m_b(valueB), c(0) �̷� ������� ������ ��������� �ʱⰪ�� ���ð���
	�Ķ��Ÿ ������ ���°� �Է¹�Ŀ� ���� ������ �Ұ����ϸ� ������ �߻�*/

	CMyclass(int valueA=0): a(valueA), m_b(0), c(0)
	{
		printf("������A ȣ���\n");
	}

	CMyclass(int valueA, int valueB) : a(valueA), m_b(valueB), c(0)
	{
		printf("������B ȣ���\n");
	}

	CMyclass(int valueA, int valueB, int valueC) : a(valueA), m_b(valueB), c(valueC)
	{
		printf("������C ȣ���\n");
	}

	//�ı���: Ŭ������ �ı��ɶ� ȣ��Ǵ� �Լ�
	//�������� �ʾƵ� �⺻�ı��� ����
	//�ı��ڵ� public�� �ƴϸ� ȣ�� �Ұ���. �ݵ�� public���� ����
	~CMyclass()
	{
		printf("�ı��� ȣ���\n");
	}

	void PrintB()
	{
		printf("1��_B=%d", m_b);
	}

	void PrintAllValue()
	{
		printf("2��_A=%d, B=%d, C=%d\n", a, m_b, c);
	}

	void SetC(int num)
	{
		c = num;
	}

	//������ �����ε�(Operator Overloading)
	//���Կ�����(�⺻������ ������)
	//const CMyClass& : �������� ��ȯ�� ������
	//operator = �����ε� �� ������
	//(const CMyClass& other):�����ʿ� �Էµ� ����
	const CMyclass& operator=(const CMyclass& other)
	{
		a = other.a;
		m_b = other.m_b;
		c = other.c;

		//�Ϲ������� this Ű����� �����Ǿ� ����.
		//this : Ŭ���� �ȿ��� �Լ��� ȣ���� ��� ��ü�� �ǹ���
		return*this;
	}

	const CMyclass& operator+(const CMyclass& other)
	{
		return CMyclass(a + other.a, m_b + other.m_b, c + other.c);
	}

public:
	int a;
protected:
private:
	int c;

};


int main()
{
	{
		//���۷��� ����
		//�޸� ������ ���� �ʰ� ������ �����Ͽ� �޸𸮸� ȿ�������� ����ϱ� ���� ������
		int num = 100;
		stMyStruct stTest;
		//������ ������ ������ ������ �ּ� ���� �����Ѵ�.
		//������ ������ �ּҰ��� �����Ͱ� ����Ű�� �մ� �ּ� ���� �ٸ���
		int* pNum = &num;//pNum ������ �������� num�� �ּ� ���� ����. ��, pNum�� num������ ����Ű�� �ִ�.
		stMyStruct* pTest = &stTest;
		printf("3��_&pNum != &num ? %d\n", (int(&pNum) !=int(&num)));

		//���۷��� ������ ���� ����� �ּҰ��� ����
		int& refNum = num;
		stMyStruct& refTest = stTest;
		refTest.a = 0;
		printf("4��_&refNum == &num? %d\n", (int(&refNum) == int(&num)));

	}
	int a;

	stMyStruct stMy;
	stMy.a = 0;

	CMyclass cMy(100);//������A�� ȣ����
	CMyclass cMy2(100, 200);//������B�� ȣ����
	printf("5��_cMy.a=%d\n", cMy.a);
	cMy.a = 0;
	cMy.SetC(0);// Ư�� ������ �����ϱ� ���� �Լ��� �����ؼ� �����ϴ°� �⺻��Ģ.
	//cMy.c=100; ���� ������ private���� �Ǿ��ִٸ� �����ڰ� ���� �������� ����� �ǵ��� �ִٴ� ��.
	
	CMyclass2 aa;

	CMyclass cMy3;
	cMy.a = 1000;
	cMy.PrintAllValue();
	cMy2.PrintAllValue();
	cMy3 = cMy + cMy2;
	cMy3.PrintAllValue();

}