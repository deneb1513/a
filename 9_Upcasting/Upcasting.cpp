#include<stdio.h>

/*���
���� Ŭ������ ����� �߰��ϰų� �������Ͽ� ���ο� Ŭ������ �����ϴ� ���
����-�⺻ �ֻ��� Ŭ���� ��� ����
���� : ����+�����δ� ����� �߰�
������ ������ ����� ��� ����
������: ���� + �����̸� �Ѵ� ����� �߰�
�������� ���� ����� ��� ����
���: ������ + ���� �ɷ� ����� �߰�
����� �������� ����� ��� ����
*/


class CBase
{
public:
	CBase(int x=1, int y=2) :m_X(x), m_Y(y)
	{
		printf("�θ� Ŭ����(CBase) ����\n");
	}
	~CBase()
	{
		printf("�θ�Ŭ����(CBase) �ı�\n");
	}
	
	//���� �Լ�(virtual function)
	//�ڽ� Ŭ�������� ������ �� ������ ����ϴ� ��� �Լ�
	//�Լ� �տ� virtual Ű���带 ����
	/*virtual void printValue()
	{
		printf("m_X=%d\n", m_X);
	}*/

public:
	int m_X;
	int m_Y;
};

//��� ���: ":public CBase"�� ���� Ŭ���� �ڿ� ����� �θ� Ŭ������ ����
class CChild : public CBase
{
public:
 //":"�� �ڿ� �θ�Ŭ����(CBase(x))�� �־ �θ�Ŭ������ ������ ȣ��
	//�θ� Ŭ������ �����ڰ� ���� ȣ�� �� �ڽ� �����ڰ� ȣ���
 CChild(int x=1, int y=2, int z=3) :m_Z(z),CBase(x, y)
 {
	 printf("�ڽ� Ŭ����(CChild) ����\n");
 }
 //�ڽ� �ı��� ���� ȣ�� �� �θ� �ı��� ȣ���
 ~CChild()
 {
	 printf("�ڽ�Ŭ����(CChild) �ı�\n");
 }
 /*
 virtual void printValue()override
 {
	 printf("m_X=%d, m_Z=%d\n", m_X, m_Z);
	
	 CBase::printValue();//�θ𿡼��� ó�� ȣ��-�θ��� Ŭ�������� ������ �������� �Լ� ȣ��
 }
 */
public:
	int m_Z;
};
//upcasting 
// �ڽ�Ŭ�������� �θ�Ŭ������ ���ٸ� �����ھ��� �ڵ����� ĳ����(�о�����) �Ǵ� ���
void printObjer(CBase** pBase, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("xpos=%d, ypos=%d\n", pBase[i]->m_X, pBase[i]->m_Y);
	}
}




int main()
{
	//CBase base(10);
	//base.m_X = 100;
	//base.printValue();



	//CChild child(10, 20);
	//child.m_X = 200;//��ӹ��� �θ��� ����� �״�� ��� ����
	//base.printValue();



	/*CChild* pArrChild = new CChild[10];
	printObjer(pArrChild, 10);
	delete[] pArrChild;*/

	CBase** pArrBase = new CBase * [10];//���� ������: �ּҰ��� �迭�� ����
	for (int i = 0; i < 10; i++)
	{
		pArrBase[i] = new CChild;
	}
	printObjer(pArrBase, 10);
	for (int i = 0; i < 10; i++)
	{
		delete pArrBase[i];
	}
	delete[] pArrBase;

}