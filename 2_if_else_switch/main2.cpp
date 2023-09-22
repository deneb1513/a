#include <iostream>
#include <stdio.h>
#include <bitset>
#define LEVEL1_REWARD_10 0b00000001; //1
#define LEVEL1_REWARD_20 0b00000010; //2
#define LEVEL1_REWARD_30 0b00000100; //4
#define LEVEL1_REWARD_40 0b00001000; //8
#define LEVEL1_REWARD_50 0b00010000; //16
#define LEVEL1_REWARD_60 0b00100000; //32


//C++�� ������
//C++���� ����� �ۼ��� �ҽ��ڵ带 ��ǻ�Ͱ� ������ �ִ� �ڵ�� ��ȯ�Ͽ� ������ �� �ִ� ���Ϸ� ��ȯ�ϴ� ����
// 1. ��ó��(Preprocessing)�ܰ� : #include �� #define �� ���� ��ó���� ��ũ�ε��� ó���ϴ� �ܰ�
// 2. ������(Compile) �ܰ� : ������ �ҽ� ���ϵ��� ����� ��ɾ�� ��ȯ
// 3. �����(Assemble) �ܰ� : ����� �ڵ���� ���� ����� �̷���� ���� �ڵ�(Object file)�� ��ȯ�ϴ� �ܰ�
// 4. ��ŷ(Linking)�ܰ� : ������ ���� �ڵ���� �ѵ� ��Ƽ� �ϳ��� ���� ������ �����ϴ� �ܰ�

// �޸� ����
// code ���� : ������ �ڵ尡 ����Ǿ��ִ� ����(����� ����)
// Data ���� : ��������, Static �������� ����, ���μ����� ����ɶ� ���� �޸𸮿� �����
// Stack ����: ��������, �Ű��������� ����, �Լ��� ȣ��Ǹ� �����ǰ� �Լ��� ����Ǹ� �ý��ۿ� ��ȯ
// Heap ���� : malloc �Ǵ� new �Լ��� ���ؼ� �������� �Ҵ�Ǵ� ����, malloc()�Ǵ� new�����ڷ� �Ҵ�, free() �Ǵ� delete �����ڷ� ����

int main()
 {
	 //��Ʈ ������
	 //C++ 11���� ���� ���� �տ� 0b�� ���̸� 2���� ǥ�� ����
	 //2���� ǥ�� : �տ� 0b�� ���δ�(0b01011101)
	 //8���� ǥ�� : �տ� 0�� ���δ�(0123)
	 //16���� ǥ�� : �տ� 0x�� ���δ�(0xFF) (A:10, B:11, C:12, D:13, E:14, F:15)
	 int A = 0b01011101;
	 int B = 0123;
	 int C = 0xFF;
	 printf("2����(0b01011101 : %d\n", A);
	 printf("8����(0123) : %d\n", B);
	 printf("16����(0xFF : %d\n", C);

	 //��Ʈ ���� ��ȣ
	 //��(&) : �� �� 1�̸� 1, �ƴϸ� 0
	 //��(|) : �� �߿� �ϳ��� 1�̸� 1, �ƴϸ� 0
	 //XOR(^) : ���� ������ 0, �ƴϸ� 1
	 //����(~) : 0�̸� 1, 1�̸� 0

	 char bitNum = 0b01001010;
	 char bitResult = 0;
	 bitResult = bitNum & 0b11010100;
	 std::cout << std::bitset<8>(bitResult) << std::endl;//std::end���� ����(printf�� \n�� ����.
	 //�� 01000000

	 bitResult = bitNum | 0b11010100;
	 std::cout << std::bitset<8>(bitResult) << std::endl;
	 //��11011110

	 bitResult = bitNum ^ 0b11010100;
	 std::cout << std::bitset<8>(bitResult) << std::endl;
	 //��10011110

	 bitResult = ~0b11010100;
	 std::cout << std::bitset<8>(bitResult) << std::endl;
	 //�� 00101011

	 //10���� �޼� ���� 
	 bool isGetLevel10Reward = false;

	 //20���� �޼� ����
	 bool isGetLevel20Reward = false;

	 //30���� �޼� ����
	 bool isGetLevel30Reward = false;

	 //40���� �޼� ����
	 bool isGetLevel40Reward = false;

	 //50���� �޼� ����
	 bool isGetLevel50Reward = false;

	 //60���� �޼� ����
	 bool isGetLevel60Reward = false;
	 
	 //��Ʈ 1�� ���� 
	 char MyReward = 0b00000000;
	 MyReward = MyReward | LEVEL1_REWARD_10; //LEVEL1_REWARD_10;
	 //0b01011000
	 //0b00000001
	 //0b01011001

	 std::cout << "MYReward Enable=" << std::bitset<8>(MyReward) << std::endl;

	 //��Ʈ Ȱ��ȭ �Ǿ��ִ��� üũ
	 bool isEnable = false;
	 //0b01011001
	 //0b00000001
	 //0b00000001
	 isEnable = MyReward & LEVEL1_REWARD_10;
	 std::cout << "MYReward Check=" << isEnable << std::endl;

	 //��Ʈ 0���� ����
	 MyReward = MyReward & ~LEVEL1_REWARD_10;
	 //0b10110011
	 //0b11111101
	 //0b10110001
	 std::cout << "MYReward Set = " << std::bitset<8>(MyReward) << std::endl;



	 return 0;
 }