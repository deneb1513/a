#include<iostream>
#include<stdlib.h>
int main()
{   //��ǻ�ʹ� �������� ��� 0, 1, 1���� bit��� �Ѵ�.
	//������ 8�� bit�϶��� 0~255 256���� ���ڸ� ǥ��
	//0000 0000=0
	//0000 0001=1
	//0000 0010=2
	//0000 0011=3
	//0000 0100=4
	//0000 1000=6
	//0000 1111=15
	//1000 0000: ��ȣ ��Ʈ�� ������.
	
	//0111 1111 = 127
	//0000 0001 = 1
	//1000 0000 = 128(-128)
	//1111 1111 = (-1)
	//0000 0000(1) + 1111 1111(-1) = 0000 0000(0)

	char c;// -128~127 1Byte = 8bit
	unsigned char uc;//0~255
	

	short s;// 2Byte = 16bit
	//int �ڷ���
	//���� 16bit ��Ű���� �϶��� 16bit
	//32bit ��Ű�����϶��� 32bit
	//64bit ��Ű�����ϴ뵵 32bit
	//int64 �϶� 64bit
	int A;//����, ����, ���, ����(0, 1, 2, 3, 4)
	unsigned int uA;//����, ���, ����(0, 1, 2, 3, 4)

	char C;
	short S;

	float f;

	f = 2.0f;

		//�ε��Ҽ���
		//0001 0000 = 1�̶��
		//0000 1000 = 0.5
		//0000 0100 = 0.25
		//0000 0010 = 0.125
		//0000 0001 = 0.0625
		//1111 1101 = 0.5 + 0.25 + 0.0625 =0.8125
		//0(��ȣ��) / 000 0000(������) / 000 0000 0000 0000(������)
		// 21.8215 = 21(10101)/8125(0.1101)
		// 21.8125>10101.1101(21825)>>>0.10101101 * 2^5>>> 5���� �������� �ٲٸ� (101)��
		// 10101101(218125) >> 0.218125 * 2^5 >> 5���� 2�������� �ٲٸ�(101)
		// 0(��ȣ��) / 000 0010 1(������) /101 0111 0100 0000 0000 0000(�����)
		// ��Ȯ�ϰ� 0.1�� ǥ���Ͽ��� �Ѵٸ� 0000 0001 1011 1001

	double d = 0.1; //8byte float ���� �� �����ϴ�

	int i2 = 0;
    float f2 = 1.0f;
	i2 = (int)f2;
	f2 = (float)i2;
	f2 = float(i2);
	f2 = (float)(i2 + 1);
	i2 = int(f2) + 1;


	//������
	//+, -, *, /, %, ++, --
	//���� ������ (=) �����ʰ��� ���ʿ� ����
	i2 = 1 + 1;
	i2 = i2 + 1;
	i2 += 1; // ���� ������ ����

	i2 = 1 * 1;
	i2 = i2 * 1;
	i2 *= 1; 
	float divide = 10 / 2.0f; // 10*0.5f;
	//�Ǽ����� ������ ���� �Ұ���(���°�Ҽ������� �����ؾ��ϴ��� �˼� ����
	//��, �Ѵ� �����϶��� ������ ���� ����

	int add = 0; // ������ �����ϸ� 0�� �����Ͽ� �ʱ�ȭ ���ش�.
	int minus = 10;
	
	// add++; ��ġ������ ���Կ����ں��� �� �ڿ� ����
	// ++add; ��ġ����

	int addR = 0, addL = 0;
	addL = ++add;
	addR = add++;

	//����������
	//&&(and), ||=\\(OR), !(NOT)
	// and�� �Ѵ� ���϶� ��
	// or�� �� �� �ϳ��� ���̸� ��
	// not ���̸� ����, �����̸� ��. ���� ����
	// yes= 0�� �ƴ� ��. True(1)
	// no= 0�� ��. False(0)
    //bool bResult = true;
    //bool bResult = false;
	//bool bResult = 1; �� true�� ���� �Ͱ� ����.
	bool bResult = 0; //�� false�� ���� �Ͱ� ����.
	bResult = 0 && 20;
	bResult = 0 || 20;
	bResult = !1;
	bResult = !0;

	//���־��� ����Ű
	// ������ ���� �ּ�: ctrl + k, c
	// ������ ���� �ּ� ����: ctrl + k, u
	// �κ� ���� ����: Alt + �巡�� 
	// ����� ����Ű
	// F5 = ����� ����, ��� ����
	// F9 = �ߴ��� ���� �� ����
	// F10 = ����� �� ���� ���� ����
	// F11 = ����� �� �Լ� ���� ���� ����
	// shift + F5 = ����� ����

	//�� ������ 
	//== : ������ t, �ƴϸ� f
	//!=: ������ f, �ƴϸ� t
	//>: ������ �����ʺ��� ũ�� t, �ƴϸ� f
	//>=: ������ �����ʺ��� ũ�ų� ������ t, �ƴϸ� f
	//<: ������ �����ʺ��� ������ t, �ƴϸ� f
	//<=: ������ �����ʺ��� �۰ų� ������ t, �ƴϸ� f
	bResult = (10 == 11);
	bResult = (10 != 11);
	bResult = (10 > 11);
	bResult = (10 < 11);

	int nResult = (10 == 11) ? 100 : 50;

	//���� �Ʒ� time ����ִ� �� ���� �а� �ð��� ���Ͽ���

	unsigned int total_sec = 987654321; //��

	unsigned int day = 0, hour = 0, min = 0, sec=0;
	/*day = 11431;
	* ������ =15921
	hour =4;
	������ = 1521
	min = 25;
	sec = 21;*/
	
	 day = total_sec/86400;
	 hour = (total_sec % 86400)/3600;
	 min = ((total_sec % 86400)%3600)/60;
	 sec = ((total_sec % 86400) % 3600) % 60;


	 //����� Ǯ��
	 //sec = total%60;
	 //min = (total/60)%60;
	 //hour = ((total/60)/60)%24; 
     //day = ((total/60)/60)/24;
	
	 printf("%d, %d, %d, %d", day, hour, min, sec);
	system("pause");

}